/* NTSC-U draft (Claude wave K): C of func_L05_0036A788, the NTSC-U twin of func_L05_0036BC98, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 55 words differ on NTSC-U with "@ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L05_0036A788", whose code is not the PAL one).
 * Worker's note: 55 aligned diff (162 vs 164 words); float const pairs: retail f20/21=pi f22/23=0.001/0.005 f24/25=+-0.1 f26/27=3.25/4.75, ours swaps the last two pairs; per-group locals / 24 declaration orders all worse; base pointer local helps (63 -> 55)
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_0036B268 (src/levels/shared/L05_0036B268.c) */

/* localdecomp:start func_L05_0036A788 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q0;
    u128_t q10;
    f32 x20, y24, z28, p2C;
    u128_t q30;
    u128_t q40;
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    s32 w98;
    s32 w9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s32 pAC;
} P_0036A788;

extern P_0036A788 D_L05_0028DE80[];
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);

void func_L05_0036A788(u8 *owner, u8 *pos, s32 arg) {
    s32 i;
    P_0036A788 *p;
    P_0036A788 *base = D_L05_0028DE80;

    for (i = 0; i < 16; i++) {
        p = &base[i];
        if (p->w9C == 0) {
            p->w9C = (s32)owner;
            *(u128_t *)&p->x20 = *(u128_t *)(owner + 0x10);
            p->q40 = *(u128_t *)pos;
            p->x20 += func_0037E250(-0.1f, 0.1f);
            p->y24 += func_0037E250(-0.1f, 0.1f);
            p->z28 += func_0037E250(-0.1f, 0.1f);
            p->f50 = func_0037E250(-3.1415927f, 3.1415927f);
            p->f54 = func_0037E250(-3.1415927f, 3.1415927f);
            p->f58 = func_0037E250(-3.1415927f, 3.1415927f);
            p->f74 = func_0037E250(-3.1415927f, 3.1415927f);
            p->f78 = func_0037E250(-3.1415927f, 3.1415927f);
            p->f7C = func_L01_00440918(0.001f, 0.005f);
            p->f5C = func_L01_00440918(0.001f, 0.005f);
            p->f60 = func_L01_00440918(0.001f, 0.005f);
            p->f64 = func_L01_00440918(0.001f, 0.005f);
            p->f80 = func_L01_00440918(0.001f, 0.005f);
            p->f84 = func_L01_00440918(0.001f, 0.005f);
            p->f88 = func_0037E250(3.25f, 4.75f);
            p->f68 = func_0037E250(3.25f, 4.75f);
            p->f6C = func_0037E250(3.25f, 4.75f);
            p->f70 = func_0037E250(3.25f, 4.75f);
            p->f8C = p->f90 = func_0037E250(3.25f, 4.75f);
            p->f94 = func_0037E250(3.25f, 4.75f);
            p->w98 = 20;
            p->q0 = 0;
            p->wA4 = arg;
            p->q10 = 0;
            p->wA8 = 0;
            p->wA0 = arg;
            return;
        }
    }
}
/* localdecomp:end func_L05_0036A788 */
