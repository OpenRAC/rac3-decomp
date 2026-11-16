/* PAL near miss (Codex wave 6): near miss: 89 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as").
 * Worker's note: 88 instruction differences; w302/func_L07_003A61E8.03.log. Correct 0x100 frame and local layout; fixed default assembler pools 0.35f instead of inline lui/ori/mtc1; VU0 sequence scheduling and call argument residuals
 */
#include "common.h"
/* localdecomp:start func_L07_003A61E8 */
#include "vu0.h"
static __inline__ void sub_ba_003A61E8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
}
static __inline__ void add_ab_003A61E8(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
void func_L07_003A61E8(void *arg) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_L01_0044C280(void *, void *, void *, s32, f32);
    extern void func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
    extern void func_L07_003A63E8(void *, void *, void *);
    struct { vu0_q pos, endpoint, matrix[4], delta, interp, point, tangent; } v;
    u8 *p = *(u8 **)((u8 *)arg + 0x68);
    s32 index;
    f32 t;
    func_003C2EC0(arg, 0, v.matrix);
    v.pos = v.matrix[3];
    func_0038CF68(&v.endpoint, v.matrix, 1.5f);
    add_ab_003A61E8(&v.endpoint, &v.pos, &v.endpoint);
    if (p[0x491] != 0) {
        sub_ba_003A61E8(&v.delta, &v.endpoint, &v.pos);
        index = (p[0x490] + p[0x491] - 1) % 10;
        sub_ba_003A61E8(&v.tangent, p + 0x3F0 + index * 16, p + 0x350 + index * 16);
        for (t = 0.25f; t < 1.0f; t += 0.35f) {
            func_L01_0044C280(&v.interp, &v.delta, &v.tangent, 0, t);
            add_ab_003A61E8(&v.point, &v.pos, &v.interp);
            func_L03_00433C70(arg, &v.pos, &v.point, 0x10001, 0, 1, 0, (f32)p[0x44], 1.0f);
        }
    }
    func_L03_00433C70(arg, &v.pos, &v.endpoint, 0x10001, 0, 1, 0, (f32)p[0x44], 1.0f);
    func_L07_003A63E8(arg, &v.pos, &v.endpoint);
}
/* localdecomp:end func_L07_003A61E8 */
