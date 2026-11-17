#include "common.h"

/* localdecomp:start func_L14_003AD768 */
typedef struct {
    f32 f0;
    u8 *p4;
    f32 *p8;
    s32 pC;
    f32 *p10;
    f32 *p14;
    s32 f18;
    s32 f1C;
    s32 f20;
} S_3AD768;
extern s32 func_L01_00470150(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L14_003AD850(u8 *);
void func_L14_003AD768(u8 *a0) {
    S_3AD768 *s = *(S_3AD768 **)(a0 + 0x68);
    s32 i;
    if (*(u16 *)(a0 + 0x34) != 0) {
        if (a0[0x31] != 0) {
            for (i = 0; i < s->pC; i++) {
                func_L01_00470150(s->p4 + i * 16, (s32)a0, s->f20, -1, 0, 2, s->p8[i] * 210000.0f, 0.2f, 0, -1, 1.0f, 0, 0);
            }
            func_L01_00404A10(func_L14_003AD850, a0);
        }
    }
}
/* localdecomp:end func_L14_003AD768 */

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
