/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_0039F590, the NTSC-U twin of func_L08_003A1188, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/08_aquatos/L08_003A0F48.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of the L08_003A0F48.c function at the same place (PAL file src/levels/08_aquatos/L08_003A0F48.c).
 * Byte-exact only with -mvu0-use-vf0-vf2 and @ps2as added to the PAL line (-O2 -G8 -fopt-stack -mno-check-zero-division):
 * the vu0.h helpers need the first, retail builds float literals with lui/ori/mtc1. Every float intermediate is its own
 * local (no variable shared between the two loops) so the global allocator ranks them like retail; func_L01_0045FEC8 returns s32. */
#include "vu0.h"

/* localdecomp:start func_L08_0039F590 */
extern f32 D_001DE20C_sda;
__asm__(".extern D_001DE20C_sda, 4");
extern f32 D_001DE210_sda;
__asm__(".extern D_001DE210_sda, 4");
extern f32 D_001DE220_sda;
__asm__(".extern D_001DE220_sda, 4");
extern f32 D_001DE200_sda;
__asm__(".extern D_001DE200_sda, 4");
extern f32 D_001DE21C_sda;
__asm__(".extern D_001DE21C_sda, 4");
extern f32 D_001DE214_sda;
__asm__(".extern D_001DE214_sda, 4");
extern f32 D_001DE218_sda;
__asm__(".extern D_001DE218_sda, 4");
extern f32 D_001DE1CC_sda;
__asm__(".extern D_001DE1CC_sda, 4");
extern f32 D_001DE1DC_sda;
__asm__(".extern D_001DE1DC_sda, 4");
extern f32 D_001DE1C0_sda;
__asm__(".extern D_001DE1C0_sda, 4");
extern f32 D_001DE1C4_sda;
__asm__(".extern D_001DE1C4_sda, 4");
extern f32 D_001DE1C8_sda;
__asm__(".extern D_001DE1C8_sda, 4");
extern f32 D_001DE1BC_sda;
__asm__(".extern D_001DE1BC_sda, 4");
extern f32 D_001DE1E0_sda;
__asm__(".extern D_001DE1E0_sda, 4");
extern f32 D_001DE1E4_sda;
__asm__(".extern D_001DE1E4_sda, 4");
extern f32 D_001DE1D4_sda;
__asm__(".extern D_001DE1D4_sda, 4");
extern f32 D_001DE1D8_sda;
__asm__(".extern D_001DE1D8_sda, 4");
extern s32 D_001DE1FC_sda;
__asm__(".extern D_001DE1FC_sda, 4");
extern s32 D_001DE1B0_sda;
__asm__(".extern D_001DE1B0_sda, 4");
extern s32 D_001DE1D0_sda;
__asm__(".extern D_001DE1D0_sda, 4");
extern s32 D_001DE204_sda;
__asm__(".extern D_001DE204_sda, 4");
extern s32 D_001DE208_sda;
__asm__(".extern D_001DE208_sda, 4");
extern s32 D_001DE1E8_sda;
__asm__(".extern D_001DE1E8_sda, 4");
extern s32 D_001DE1F0_sda;
__asm__(".extern D_001DE1F0_sda, 4");
extern s32 D_001DE1EC_sda;
__asm__(".extern D_001DE1EC_sda, 4");
extern s32 D_001DE1F4_sda;
__asm__(".extern D_001DE1F4_sda, 4");
extern s32 D_001DE1F8_sda;
__asm__(".extern D_001DE1F8_sda, 4");
extern s32 D_001DE1B4_sda;
__asm__(".extern D_001DE1B4_sda, 4");
extern s32 D_001DE1B8_sda;
__asm__(".extern D_001DE1B8_sda, 4");

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00470258(void *, void *, s32, s32, s16, s32, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039F590(u8 *self) {
    vu0_v4 v10;
    vu0_v4 va;
    vu0_v4 vc;
    vu0_v4 vd;
    s32 i, j, k;
    f32 r1, p1;
    f32 ang, scale, rnd2, r2, r3, x;
    s32 c1, c2;

    *(vu0_q *)&v10 = *(vu0_q *)(self + 0xE0);
    for (k = 0; k < D_001DE1FC_sda; k++) {
        r1 = func_0037E250(D_001DE20C_sda, D_001DE210_sda) * 0.016666668f;
        func_00388830(&va, &v10, r1);
        func_003BF6A8(&va, D_001DE220_sda * 0.016666668f);
        func_00388830(&vc, &v10, D_001DE200_sda);
        vec_add_ab(&vc, &vc, self + 0x10);
        func_003BF6A8(&vc, D_001DE21C_sda);
        p1 = func_0037E250(D_001DE214_sda, D_001DE218_sda) * 210000.0f;
        func_L01_00470258(&vc, &va, D_001DE204_sda, D_001DE208_sda, func_0037E208(0x78, 0xF0), 0, p1);
    }
    for (i = 0; i < D_001DE1B0_sda; i++) {
        *(vu0_q *)&va = *(vu0_q *)(self + 0x10);
        func_003BF6A8(&va, D_001DE1CC_sda);
        va.z = va.z + 0.5f;
        ang = func_0037E2A8();
        scale = func_0037E250(D_001DE1DC_sda, D_001DE1C0_sda);
        rnd2 = func_0037E250(D_001DE1C4_sda, D_001DE1C8_sda);
        scale = scale * 0.016666668f;
        qzero(&vc);
        vc.x = vc.x + func_00388960(ang) * scale;
        vc.y = vc.y + func_00388978(ang) * scale;
        vc.z = vc.z + rnd2 * 0.016666668f;
        *(vu0_q *)&vd = *(vu0_q *)&vc;
        r2 = func_0037E250(D_001DE1BC_sda * 0.7f, D_001DE1BC_sda * 1.3f);
        vd.z = vd.z - r2 * 0.00027777778f * (f32)D_001DE1B4_sda;
        for (j = 0; j < D_001DE1D0_sda; j++) {
            r3 = func_0037E250(0.5f, 1.5f);
            vc.w = r3 * D_001DE1E0_sda;
            vd.w = r3 * D_001DE1E4_sda;
            func_003BF6A8(&va, D_001DE1D4_sda);
            func_003BF6A8(&vd, D_001DE1D8_sda * 0.016666668f);
            c1 = func_003894A0(D_001DE1E8_sda, D_001DE1F0_sda, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(D_001DE1EC_sda, D_001DE1F4_sda, func_0037E250(0.0f, 1.0f));
            x = (f32)D_001DE1B8_sda;
            func_L01_0045FEC8(&va, &vc, &vd, c1, c2, D_001DE1F8_sda, D_001DE1B4_sda, (s32)func_0037E250(x * 0.5f, x * 2.5f), -1);
        }
    }
}
/* localdecomp:end func_L08_0039F590 */
