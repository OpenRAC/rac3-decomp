/* PAL near miss (k6 agent 2, 2026-11-26), from its functional C (nonmatching/functional/). 137 = 137 instructions, 18 aligned rows
 * with tools/check.py at levels 31-36 and the file's line plus -mvu0-use-vf0-vf2 (the vec_sub_ba helper's "j" operands): that flag
 * line keeps func_L31_003AC410, the file's other C function, matching at all six places. What it took: .extern size hints for the
 * D_L31_001DEAxx/EBxx scalars ($gp), the emitter word e+4 read before the a == 0 test (retail fills that branch's slot with it),
 * the colour stored straight from the call (`*(s32 *)(p + 4) = func_L30_0034DBA0(...)`, then e+0x18 from it), and
 * func_L03_0034B148(s32, s32, f32) called with 0.0f (src/levels/shared/L30_00345380.c's prototype). Left: retail loads the two
 * func_003824E0 arguments (D_L31_001DEB1C/20) before the p+4 and e+0x18 stores and the lqc2s, and D_L31_001DEB08 into $f20 right after
 * the div.s, before the position updates; the e+8 halfword is in $v1 / the colour word in $a1 there (here $a1 / $v1).
 */
#include "common.h"
/* functional: high. Read against asm; remaining diff is scheduling/gp addressing; needs vu0 flag line for vec_sub_ba. */
#include "vu0.h"
extern f32 D_L31_001DEAF0;
extern s32 D_L31_001DEAF4;
extern s32 D_L31_001DEAF8;
extern f32 D_L31_001DEAFC;
extern f32 D_L31_001DEB08;
extern f32 D_L31_001DEB0C;
extern f32 D_L31_001DEB10;
extern f32 D_L31_001DEB1C;
extern f32 D_L31_001DEB20;
__asm__(".extern D_L31_001DEAF0, 4");
__asm__(".extern D_L31_001DEAF4, 4");
__asm__(".extern D_L31_001DEAF8, 4");
__asm__(".extern D_L31_001DEAFC, 4");
__asm__(".extern D_L31_001DEB08, 4");
__asm__(".extern D_L31_001DEB0C, 4");
__asm__(".extern D_L31_001DEB10, 4");
__asm__(".extern D_L31_001DEB1C, 4");
__asm__(".extern D_L31_001DEB20, 4");
extern void func_L30_0034C958(void *, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);

/* Per-particle update callback of the vid-comic 1 emitter (p = particle, e = emitter state):
 * on a particle's first frame places it around the emitter's anchor with a random outward velocity
 * and colour; every frame fades its alpha with age/lifetime, moves it and sets its size. */
/* localdecomp:start func_L31_003AC578 */
void func_L31_003AC578(u8 *p, u8 *e) {
    u8 *a;
    s32 c;
    s32 n;
    vu0_v4 d;
    f32 f20, f21;

    if (e == 0) return;
    a = *(u8 **)e;
    n = *(s32 *)(e + 4);
    if (a == 0) return;
    if (n == 0) return;
    if (*(u16 *)(e + 0xA) & 1) {
        *(vu0_q *)(p + 0x10) = *(vu0_q *)(a + 0x10);
        func_L30_0034C958(p + 0x10, D_L31_001DEAFC);
        *(s32 *)(p + 4) = func_L30_0034DBA0(D_L31_001DEAF4, D_L31_001DEAF8);
        *(f32 *)(e + 0x18) = (f32)(*(s32 *)(p + 4) >> 24);
        vec_sub_ba(&d, p + 0x10, a + 0x10);
        func_0038CF68(&d, &d, func_003824E0(D_L31_001DEB20, D_L31_001DEB1C));
        *(f32 *)(e + 0x10) = d.x;
        *(f32 *)(e + 0x14) = d.z;
        if (func_0038CEA8(&d) < D_L31_001DEAF0 * (D_L31_001DEB20 + D_L31_001DEB1C)) {
            p[3] = 0x44;
        } else {
            p[3] = 0x48;
        }
        *(f32 *)(p + 0xC) = func_003C4088(D_L31_001DEB10, D_L31_001DEB0C,
                                          (func_0038CEA8(&d) - D_L31_001DEB20) / (D_L31_001DEB1C - D_L31_001DEB20));
    }
    c = (s32)(*(f32 *)(e + 0x18) * (f32)*(s16 *)(p + 0xA) / (f32)*(s16 *)(e + 8));
    *(s32 *)(p + 4) = (*(s32 *)(p + 4) & 0xFFFFFF) | (c << 24);
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + *(f32 *)(e + 0x10);
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + *(f32 *)(e + 0x14);
    f21 = (f32)(*(u16 *)(e + 0xE) & 0xFF);
    f20 = f21 + D_L31_001DEB08 * (f32)*(s16 *)(e + 8) * (f32)(*(u16 *)(e + 0xE) >> 8) * 0.00390625f;
    p[8] = (s32)func_003C4088(f21, f20, func_L03_0034B148(*(s16 *)(p + 0xA), *(s16 *)(e + 8), 0.0f));
}
/* localdecomp:end func_L31_003AC578 */
