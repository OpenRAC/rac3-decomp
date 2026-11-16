/* NTSC-U draft (Claude wave K): C of func_L04_00353C08, the NTSC-U twin of func_L04_00354AE8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 150 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L04_00353C08", whose code is not the PAL one).
 * Worker's note: 150 diff words in about 10 hunks with the extras the PAL line lacks (vec_* needs -mvu0-use-vf0-vf2, float immediates need @ps2as); whole body reconstructed (two 6-iteration particle loops, 5 tail calls to func_L01_0046D570 with 12-arg prototype ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00353C08 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) and @ps2as (float immediates) beyond the PAL file's flags. */
extern vu0_v4 D_L04_001E2840;
extern u8 D_L04_001D66B0[];
extern u8 *D_L04_0021FC98[];
extern u8 *D_L04_0021FE04;
extern u8 *D_L04_0021FE08;
extern u8 *D_L04_0021FE1C;

extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0046CF70(void *, void *, s32, f32);
extern u8 *func_L01_0046D570(void *, s32, s32, s32, s32, void *, s32, s32, s32, s32, f32, f32);

void func_L04_00353C08(void *self, s32 a1, s32 a2, s32 a3, f32 ang, s32 p5, s32 p6) {
    u8 *o = self;
    vu0_v4 d;
    vu0_v4 e;
    f32 base;
    f32 sa;
    f32 sb;
    f32 th;
    s32 life;
    s32 life2;
    s32 n;
    s32 i1;
    s32 i2;
    u8 *p;

    vec_sub_ab(&d, &D_L04_001E2840, o);
    base = func_00388A28(d.x, d.y);
    for (n = 5; n >= 0; n--) {
        life = (s32)func_L01_00440918(2.0f, 5.0f);
        sa = func_0037E250(0.6f, 1.0f) * 0.3f;
        sb = func_0037E250(9.0f, 12.0f) * 0.3f;
        th = func_00389380(base, func_L01_00440918(0.0f, 1.3962634f));
        sb = sb * 0.016666668f;
        e.x = func_00388960(th) * sb;
        e.y = func_00388978(th) * sb;
        e.z = 0.0f;
        e.z = func_0037E250(0.0f, 12.0f) * 0.3f * 0.016666668f;
        i1 = func_0037E208(30, 50);
        func_L01_0046DCB8(o, &e, i1, a2, life, 0x7F, 0x7F, 1, sa * 210000.0f, 630.0f, 0.0040555559f);
        life2 = -(life << 1);
        i2 = func_0037E208(30, 50);
        sa = sa * 6.0f;
        p = func_L01_0046DCB8(o, &e, i2, a2, life2, 0x30, 0x30, 0, sa * 210000.0f, 1260.0f, 0.0040555559f);
        if (p != 0) {
            p[2] = *D_L04_0021FC98[0xD4 / 4];
        }
    }
    vec_sub_ba(&e, &D_L04_001E2840, o);
    func_00388830(&e, &e, func_0037E250(0.05f, 0.1f));
    for (n = 5; n >= 0; n--) {
        e.x += func_0037E250(-0.03f, 0.03f);
        e.y += func_0037E250(-0.03f, 0.03f);
        e.z += func_0037E250(0.0f, 0.03f);
        func_L01_0046CF70(o, &e, func_0037E208(25, 40), 0.0040555559f);
    }
    func_L01_0046D570(o, 0x28, a3, 2, 4, D_L04_001D66B0, 0, 1, 6, 1, 0.1f, 0.85f);
    p = func_L01_0046D570(o, 0x1E, p5, 2, 0, D_L04_001D66B0, 0, 0, 6, 1, 0.4f, 1.75f);
    if (p != 0) {
        p[2] = D_L04_0021FE1C[2];
    }
    func_L01_0046D570(o, 0x28, p6, 0, 2, D_L04_001D66B0, 0, 4, 6, 1, 0.15f, 1.35f);
    p = func_L01_0046D570(o, 0x1B, a1, 2, 0, D_L04_001D66B0, 3, 0, 6, 1, 0.5f, ang);
    if (p != 0) {
        p[2] = D_L04_0021FE04[2];
    }
    p = func_L01_0046D570(o, 0x1B, a1, 1, -2, D_L04_001D66B0, 3, 4, 6, 1, 0.3f, ang - 0.5f);
    if (p != 0) {
        p[2] = D_L04_0021FE08[4];
    }
}
/* localdecomp:end func_L04_00353C08 */
