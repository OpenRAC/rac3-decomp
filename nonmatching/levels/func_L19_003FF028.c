/* NTSC-U draft (Claude wave C4): C of func_L19_003FC550, the NTSC-U twin of func_L19_003FF028, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L19_003FC550", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (vec_add_ab + 7 lui/ori/mtc1 constants; the PAL file's STD flag line has neither), so it cannot land even if exact. With them 264/264 words and frame 0xC0 match, 2 aligned ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L19_003FF028 (shared). Needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as': the PAL file's flag line has neither (vec_add_ab, 7 lui/ori/mtc1 constants). 2 aligned words differ (46DCB8 call: 'srl t1' and 'daddu a2' swapped). */

/* localdecomp:start func_L19_003FC550 */
extern f32 func_0037E250(f32, f32);
extern void func_003888C8(f32 *, f32 *, void *);
extern void func_L02_00424E20(void *, f32 *, f32, f32, f32);
extern u32 func_003894A0(u32, u32, f32);
extern s32 D_L19_001D677C_003FC550;
__asm__(".extern D_L19_001D677C_003FC550, 16");
extern void func_L01_0045FEC8(void *, void *, void *, u32, u32, s32, s32, s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);

void func_L19_003FC550(u8 *o, f32 *p1, f32 *p2, f32 *p3, f32 *p4, s32 cnt, u8 mode) {
    f32 v10[4];
    f32 v20[4];
    f32 v30[4];
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    u32 c1;
    u32 c2;
    f32 r;
    f32 k = 0.0013888889f;
    s32 fl = 0x1003C;

    for (i = 0; i < cnt; i++) {
        v10[0] = func_0037E250(p3[0], p4[0]) * 0.016666668f;
        v10[1] = func_0037E250(p3[1], p4[1]) * 0.016666668f;
        v10[2] = func_0037E250(p3[2], p4[2]) * 0.016666668f;
        v30[0] = func_0037E250(p1[0], p2[0]);
        v30[1] = func_0037E250(p1[1], p2[1]);
        v30[2] = func_0037E250(p1[2], p2[2]);
        func_003888C8(v10, v10, o + 0xC0);
        func_L02_00424E20(o, v30, v30[0], v30[1], v30[2]);
        r = func_0037E250(0.5f, 1.5f);
        a = (s32)(r * 10.0f);
        b = (s32)(r * 35.0f);
        c = (s32)(r * 7.0f);
        v10[3] = func_0037E250(0.1f, 0.4f);
        qzero(v20);
        v20[2] = -k * (f32)(a + b + c);
        vec_add_ab(v20, v20, v10);
        v20[3] = 0.01f;
        switch (mode) {
        case 1:
            c1 = func_003894A0(0x80102040, 0x801010A0, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(0x00102040, 0x001010A0, func_0037E250(0.0f, 1.0f));
            break;
        case 3:
            c1 = func_003894A0(0x80201608, 0x80402510, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(0x00201608, 0x00402510, func_0037E250(0.0f, 1.0f));
            break;
        case 2:
            c1 = func_003894A0(0x80104010, 0x8020A020, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(0x00104010, 0x0020A020, func_0037E250(0.0f, 1.0f));
            break;
        case 0:
        default:
            c1 = func_003894A0(0x80004080, 0x80408080, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(0x00004080, 0x00408080, func_0037E250(0.0f, 1.0f));
            break;
        }
        if (D_L19_001D677C_003FC550 == 0) {
            func_L01_0045FEC8(v30, v10, v20, c1, c2, a, b, c, fl);
        } else {
            func_L01_0046DCB8(v30, v10, a, c1 & 0xFFFFFF, 0, c1 >> 24, c2 >> 24, 0x1003C, 210000.0f, 0.0f, 0.0013888889f);
        }
    }
}
/* localdecomp:end func_L19_003FC550 */
