#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_003AD768);

/* localdecomp:start func_L14_003AD850 */
typedef struct {
    f32 f0;
    u8 *p4;
    u8 *p8;
    s32 pC;
    f32 *p10;
    f32 *p14;
    s32 f18;
    s32 f1C;
} S_3AD850;
extern void func_L01_0040A4A0(void *, void *, s32, s32, s32, s32, f32, f32, f32);
void func_L14_003AD850(u8 *a0) {
    S_3AD850 *s = *(S_3AD850 **)(a0 + 0x68);
    s32 i;
    f32 t = s->f0 - 0.1f;
    s->f0 = t;
    if (t <= -8.0f) {
        s->f0 = t + 8.0f;
    }
    for (i = 0; i < s->pC; i++) {
        func_L01_0040A4A0(a0, s->p4 + i * 16, 1, s->f18, s->f1C, 0x17, s->p14[i], s->p10[i], s->f0);
    }
}
/* localdecomp:end func_L14_003AD850 */
