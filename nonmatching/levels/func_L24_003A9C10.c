/* func_L24_003A9C10 (524 B, 4 places): PAL near miss, k6 agent 4 (2026-11-26), written from the asm in the
 * style of the matched vidcomic particle updaters (func_L32_003B43F8, func_L30_003502D0). check.py at level 24:
 * 6 positional diffs, 131 = 131 words. Lever: `on = b->f4` read into a local before the `c && on` test (reorg
 * then fills the first beqz's delay slot with that load, as retail). Left: one scheduling run before the first
 * func_L03_0034B148 call: retail issues `mul.s $f20,$f20,$f0` (D474 * life) before `andi $v0,$v0,0xff` and
 * `lh $a0,0xa($s1)` after the lo conversion; here the andi goes first and the lh right after the mul.
 * Tried: lo/hi statement orders, hw temps, the product order, the call result in a local. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L24_003A9C10 */
extern f32 D_L24_001DE464;
extern f32 D_L24_001DE468;
extern f32 D_L24_001DE46C;
extern f32 D_L24_001DE470;
extern f32 D_L24_001DE474;
extern s32 D_L24_001DE478;
extern f32 D_L24_001DE47C;
extern f32 D_L24_001DE480;
__asm__(".extern D_L24_001DE464, 4");
__asm__(".extern D_L24_001DE468, 4");
__asm__(".extern D_L24_001DE46C, 4");
__asm__(".extern D_L24_001DE470, 4");
__asm__(".extern D_L24_001DE474, 4");
__asm__(".extern D_L24_001DE478, 4");
__asm__(".extern D_L24_001DE47C, 4");
__asm__(".extern D_L24_001DE480, 4");
typedef struct { s32 f0, f4; s8 f8; u8 pad9; s16 fA; f32 fC, f10, f14, f18, f1C; } Output_3A9C10;
typedef struct { u8 *f0; s32 f4; s16 f8; u16 fA; u16 fC; u16 fE; } Input_3A9C10;
void func_L24_003A9C10(Output_3A9C10 *a, Input_3A9C10 *b) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L03_0034B148(s32, s32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    u8 *c;
    u16 hw;
    f32 s, e, k, h, x;
    s32 col;

    if (b == 0) {
        return;
    }
    c = b->f0;
    {
    s32 on = b->f4;
    if (c != 0 && on != 0) {
        s = *(f32 *)(c + 0xC) * 0.0009765625f;
        if (b->fA & 1) {
            *(vu0_q *)&a->f10 = *(vu0_q *)(c + 0x10);
            a->f10 += func_003824E0(-D_L24_001DE464 * s, D_L24_001DE464 * s);
            a->f18 += func_003824E0(0.0f, D_L24_001DE468 * s);
        }
        hw = b->fC;
        if (hw & 1) {
            a->f10 = a->f10 + (D_L24_001DE46C + D_L24_001DE470 * (f32)(hw & 0xFF) * 0.00390625f);
        } else {
            a->f10 = a->f10 - (D_L24_001DE46C + D_L24_001DE470 * (f32)(hw & 0xFF) * 0.00390625f);
        }
        e = (f32)(b->fE & 0xFF);
        h = e + (e + D_L24_001DE474 * (f32)b->f8 * (f32)(b->fE >> 8) * 0.00390625f);
        a->f8 = func_003C4088(e, h, func_L03_0034B148(a->fA, b->f8, 0.0f));
        col = D_L24_001DE478 & 0xFFFFFF;
        x = func_L03_0034B148(a->fA, b->f8, 0.0f);
        a->f4 = func_0038DBD8(D_L24_001DE478, col, x);
        if (b->fA & 1) {
            a->fC = func_003824E0(D_L24_001DE480, D_L24_001DE47C);
        }
    }
    }
}
/* localdecomp:end func_L24_003A9C10 */
