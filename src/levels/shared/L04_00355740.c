#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
} S_34A460b;
typedef struct {
    u8 pad0[0x68];
    S_34A460b *p68;
} S_34A460;

INCLUDE_ASM("asm/levels", func_L04_00355740);

/* localdecomp:start func_L04_00355BF8 */


extern s32 func_0038CB00(s32 *a0);
extern void func_L01_00404A10_00355BF8(void (*a0)(u8 *), S_34A460 *a1);
extern void func_L04_00355C60(u8 *o);
extern void func_003C2880(S_34A460 *a0);

void func_L04_00355BF8(S_34A460 *a0) {
    S_34A460b *t = a0->p68;
    if (func_0038CB00(&t->w0) == 0) {
        func_0038CB00(&t->w4);
        func_L01_00404A10_00355BF8(func_L04_00355C60, a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L04_00355BF8 */

/* localdecomp:start func_L04_00355C60 */
typedef struct {
    s16 h0, h2, h4;
    u8 pad6[2];
    f32 f8;
    f32 fC;
    u8 pad10[8];
    s32 w18;
    s32 w1C;
} S_355C60;
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_L04_00355DE0(void *, s32, f32, f32, f32, f32, f32, s32);
extern s16 D_L04_001CFEC0[];

void func_L04_00355C60(u8 *o) {
    S_355C60 *s = *(S_355C60 **)(o + 0x68);
    if (s->h2 - s->h0 < 2 && s->h4 != 0 && s->w1C != 0) {
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_L04_001CFEC0[0xA9], 0, D_L04_001CFEC0[0xA8], (s32)0x80808080);
    }
    if (s->w18 != 0) {
        if (s->h2 - s->h0 < 10) {
            func_L04_00355DE0(o + 0x10, 0x3B, s->f8 + (s->fC - s->f8) * ((f32)(s->h2 - s->h0) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f, 0);
        } else if ((u16)(s->h0 - 0x2E) < 4) {
            func_L04_00355DE0(o + 0x10, 0x3B, s->f8 + (s->fC - s->f8) * ((f32)(s->h0 - 0x2D) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f, 0);
        }
    }
}
/* localdecomp:end func_L04_00355C60 */

INCLUDE_ASM("asm/levels", func_L04_00355DE0);
