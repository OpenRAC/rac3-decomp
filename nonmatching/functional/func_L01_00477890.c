/* functional: high. Read against the PAL asm; differs only in scheduling and a leading div.s nop pair. The w lane of the result (unwritten by vsub.xyz/vadd.xyz) is whatever the VU register held; not read by callers presumably. */
#include "common.h"
#include "vu0.h"
typedef struct {
    s32 count;
    s32 pad[3];
    vu0_q points[1];
} Path_00477890;
static __inline__ vu0_q sub_00477890(void *a, void *b) {
    vu0_q v;
    __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(v) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
    return v;
}
static __inline__ vu0_q add_00477890(void *a, void *b) {
    vu0_q v;
    __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
        : "=m"(v) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
    return v;
}
void func_L01_00477890(Path_00477890 *p, s32 *index, f32 *remainder, vu0_q *out, f32 time, f32 step) {
    extern void func_0038CF68(void *, void *, f32);
    vu0_q v;
    *index = (s32)(time / step);
    if (*index >= p->count - 1) {
        *index = p->count - 1;
    } else if (*index < 0) {
        *index = 0;
    } else {
        *remainder = time - (f32)*index * step;
        v = sub_00477890(&p->points[*index + 1], &p->points[*index]);
        *out = v;
        func_0038CF68(out, out, *remainder);
        v = add_00477890(out, &p->points[*index]);
        *out = v;
        return;
    }
    *remainder = 0.0f;
    *out = p->points[*index];
}
