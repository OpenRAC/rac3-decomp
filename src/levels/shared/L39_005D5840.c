#include "common.h"

/* localdecomp:start func_L39_005D5840 */
#include "vu0.h"

typedef struct V_005D5840 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_005D5840;

extern s32 func_0038CB00(void *);
extern void func_003CD250(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L39_005FFB48(void *, void *);
extern void func_L39_005FF198(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");

void func_L39_005D5840(u8 *a0) {
    V_005D5840 v;
    u8 *p;
    u8 *q;

    if (func_0038CB00(a0 + 0xA)) {
        func_003CD250(a0);
        return;
    }
    p = a0 + 0x20;
    q = a0 + 0x10;
    *(s32 *)(a0 + 4) = func_0038DBD8(*(s32 *)(p + 0x1C), *(s32 *)(p + 0x18), (f32)*(s16 *)(a0 + 0xA) * *(f32 *)(p + 0xC));
    vec_add_ab(a0 + 0x10, a0 + 0x10, a0 + 0x20);
    func_L39_005FFB48(q, q);
    if (D_L39_002429BC == 0) {
        *(f32 *)(p + 8) -= (f32)*(s16 *)(p + 0x16) * 0.0078125f * 0.00040000002f;
    } else {
        func_L39_005FF198(0, q, &v);
        func_0038CF68(&v, &v, -((f32)*(s16 *)(p + 0x16) * 0.0078125f * 0.00040000002f));
        vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
    }
    a0[8] += p[0x14];
    *(f32 *)(a0 + 0xC) += *(f32 *)(p + 0x10);
}
/* localdecomp:end func_L39_005D5840 */
