/* functional: high. rewritten as a loop over 8 rows (retail unrolled, each row identical except X column slot and y step multiple); gp float slots named from level 39 gp 0x247FC0; col is unsigned long as retail builds it with dsll; not byte exact */
#include "common.h"

extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern f32 D_L39_00246658;
__asm__(".extern D_L39_00246658, 4");
extern f32 D_L39_0024665C;
__asm__(".extern D_L39_0024665C, 4");
extern f32 D_L39_00246650;
__asm__(".extern D_L39_00246650, 4");
extern f32 D_L39_00246654;
__asm__(".extern D_L39_00246654, 4");
extern f32 D_L39_00246648;
__asm__(".extern D_L39_00246648, 4");
extern f32 D_L39_0024664C;
__asm__(".extern D_L39_0024664C, 4");
extern s32 D_L39_00246660;
__asm__(".extern D_L39_00246660, 4");
extern u8 D_L39_00352CE0[];
extern s32 func_L39_00589890(s32 id);
extern void func_L39_0058B9F8(s32 a0, s32 a1, s32 a2, s32 a3, f32 x, f32 y, f32 w, f32 h, unsigned long col, s32 spr);

void func_L39_00678A50(void) {
    u8 *t = D_L39_00352CE0;
    s32 k;

    for (k = 0; k < 8; k++) {
        f32 W = (f32)D_L39_00240300;
        f32 H = (f32)D_L39_00240304;
        f32 xs = (k < 4) ? D_L39_00246658 : D_L39_0024665C;
        f32 ys = D_L39_00246650 + D_L39_00246654 * (f32)(k & 3);
        f32 ws = D_L39_00246648;
        f32 hs = D_L39_0024664C;
        unsigned long col = (t[0x6AC + k] != 0) ? 0x8066CCFF : 0x80808080;
        s32 spr = func_L39_00589890(0x24 + k);
        func_L39_0058B9F8(0, 0, D_L39_00246660, D_L39_00246660, xs * W, ys * H, ws * W, hs * H, col, spr);
    }
}
