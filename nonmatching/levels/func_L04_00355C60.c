/* PAL near miss (nm/b9-t3): 3 words differ, with `@ps2as` added to the file's text_parts line, a
 * divs_nops line `func_L04_00355C60 2 2` and this block's prototype change in the file
 * (`func_L04_00355C60(u8 *o)`, and `void (*a0)(u8 *)` in func_L01_00404A10_00355BF8's extern).
 * Differs: in the second arm (h0 - 0x2D) the two `mov.s $f15/$f16, $f14` come before `move $a2, $zero`
 * in retail; here the move is earlier (the first arm matches). Tried: int/float zero arguments, a local
 * for the fraction or the result, &o[0x10], other spellings of the constant.
 */
#include "common.h"
/* localdecomp:start func_L04_00355C60 */
typedef struct {
    s16 h0, h2, h4;
    u8 pad6[2];
    f32 f8;
    f32 fC;
    u8 pad10[8];
    s32 w18;
    s32 w1C;
} S;
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_L04_00355DE0(void *, s32, s32, f32, f32, f32, f32, f32);
extern s16 D_001CFEC0[];
void func_L04_00355C60(u8 *o) {
    S *s = *(S **)(o + 0x68);
    if (s->h2 - s->h0 < 2 && s->h4 != 0 && s->w1C != 0) {
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
    }
    if (s->w18 != 0) {
        if (s->h2 - s->h0 < 10) {
            func_L04_00355DE0(o + 0x10, 0x3B, 0, s->f8 + (s->fC - s->f8) * ((f32)(s->h2 - s->h0) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((u16)(s->h0 - 0x2E) < 4) {
            func_L04_00355DE0(o + 0x10, 0x3B, 0, s->f8 + (s->fC - s->f8) * ((f32)(s->h0 - 0x2D) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_L04_00355C60 */
