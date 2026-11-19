#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_003C7000 (src/levels/shared/L01_003C64E0.c). Byte-exact only with
   -mvu0-use-vf0-vf2 and @ps2as added to that file's flags; needs the divs_nops row 'func_L01_003C7000 2 2'. */

/* localdecomp:start func_L01_003C7000 */
extern s32 D_L01_001F3F40[];
typedef struct { u8 p0[0x18]; u8 *p18; } G_EAA00;
extern G_EAA00 D_L01_001EAA00;
extern f32 D_L01_001DEC14;
extern f32 D_L01_001DEC18;
extern f32 D_L01_001DEC1C;
extern f32 D_L01_001DEC20;
extern f32 D_L01_001DEC24;
extern f32 D_L01_001DEC28;
extern f32 D_L01_001DEC2C;
extern f32 D_L01_001DEC30;
extern f32 D_L01_001DEC38;
extern f32 D_L01_001DEC3C;
extern f32 D_L01_001DEC40;
extern f32 D_L01_001DEC44;
extern f32 D_L01_001DEC48;
__asm__(".extern D_L01_001DEC14, 4");
__asm__(".extern D_L01_001DEC18, 4");
__asm__(".extern D_L01_001DEC1C, 4");
__asm__(".extern D_L01_001DEC20, 4");
__asm__(".extern D_L01_001DEC24, 4");
__asm__(".extern D_L01_001DEC28, 4");
__asm__(".extern D_L01_001DEC2C, 4");
__asm__(".extern D_L01_001DEC30, 4");
__asm__(".extern D_L01_001DEC38, 4");
__asm__(".extern D_L01_001DEC3C, 4");
__asm__(".extern D_L01_001DEC40, 4");
__asm__(".extern D_L01_001DEC44, 4");
__asm__(".extern D_L01_001DEC48, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);

s32 func_L01_003C7000(u8 *a0, u8 *s2) {
    u8 *s3;
    u8 *s4;
    f32 f20;
    f32 f21;
    s32 flag;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;

    if (D_L01_001F3F40[0] == *(s32 *)(s2 + 0xE0)) {
        s3 = *(u8 **)(s2 + 0xD8);
        s4 = *(u8 **)(s2 + 0xDC);
    } else {
        s3 = *(u8 **)(s2 + 0x4C);
        s4 = *(u8 **)(s2 + 0x50);
    }
    if (*(f32 *)(s2 + 0x674) < D_L01_001DEC20 * 0.017453292f) {
        f20 = D_L01_001DEC1C * 0.017453292f;
    } else {
        u8 *p54;
        f32 t;

        flag = 0;
        p54 = *(u8 **)(s2 + 0x54);
        if (p54 != 0) {
            if (*(s32 *)(p54 + 0x98) != 0) {
                *(s32 *)(p54 + 0x98) = 0;
                flag = 1;
            }
        }
        f21 = *(f32 *)(s2 + 0x6A8) + D_L01_001DEC14;
        func_0038CF68(&v2, s3 + 0xC0, D_L01_001DEC18);
        func_0038CF68(&v1, s3 + 0xE0, f21);
        vec_add_ba(&v1, &v1, s3 + 0x10);
        vec_add_ba(&v1, &v1, &v2);
        vec_add_ab(&v0, s3 + 0x10, &v2);
        t = v0.z - func_003C3D30(&v1, 0, s4, 10.0f);
        if (D_L01_001EAA00.p18 == s3 || f21 < t) {
            f20 = D_L01_001DEC1C * 0.017453292f;
        } else {
            f20 = func_0038DB48(func_0038D0C8(t / f21) + 1.5707964f);
            if (D_L01_001F3F40[0] != *(s32 *)(s2 + 0xE0)) {
                f20 = func_0038DB00(f20, *(f32 *)(a0 + 0xF4));
                if (f20 < 0.0f) {
                    f20 += 6.2831855f;
                }
            }
            if (D_L01_001DEC1C * 0.017453292f < f20) {
                f20 = D_L01_001DEC1C * 0.017453292f;
            }
        }
        func_0038CF68(&v1, s3 + 0xE0, f21);
        vec_add_ba(&v1, &v1, s3 + 0x10);
        vec_sub_ba(&v1, &v1, &v2);
        vec_sub_ab(&v0, s3 + 0x10, &v2);
        t = v0.z - func_003C3D30(&v1, 0, s4, 10.0f);
        {
            f32 g;

            if (D_L01_001EAA00.p18 == s3 || f21 < t) {
                g = D_L01_001DEC1C * 0.017453292f;
            } else {
                g = func_0038DB48(func_0038D0C8(t / f21) + 1.5707964f);
                if (D_L01_001F3F40[0] != *(s32 *)(s2 + 0xE0)) {
                    g = func_0038DB00(g, *(f32 *)(a0 + 0xF4));
                    if (g < 0.0f) {
                        g += 6.2831855f;
                    }
                }
                if (D_L01_001DEC1C * 0.017453292f < g) {
                    g = D_L01_001DEC1C * 0.017453292f;
                }
            }
            if (g < f20) {
                f20 = g;
            }
        }
        if (flag != 0) {
            *(s32 *)(*(u8 **)(s2 + 0x54) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(s2 + 0x54) + 0x24) + 0x10);
        }
    }
    if (f20 < *(f32 *)(s2 + 0x674)) {
        *(f32 *)(s2 + 0x674) = f20;
        *(s32 *)(s2 + 0x98) = 0;
    } else {
        f32 acc = D_L01_001DEC30 * 0.017453292f * 0.0200000014f;

        if (*(f32 *)(s2 + 0x98) < acc) {
            *(f32 *)(s2 + 0x98) = acc;
        }
        func_L01_00448890(s2 + 0x674, f20, s2 + 0x98, 0, D_L01_001DEC28 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC2C * 0.017453292f * 0.000400000019f, D_L01_001DEC24 * 0.017453292f * 0.0200000014f);
    }
    *(f32 *)(s2 + 0x694) = *(f32 *)(s2 + 0x674);
    if (*(s32 *)(s2 + 0xB0) != 3) {
        if (D_L01_001DEC38 * 0.017453292f < *(f32 *)(s2 + 0x674)) {
            func_003C41A0((f32 *)(s2 + 0x6A8), s2 + 0x9C, D_L01_001DEC3C,
                          D_L01_001DEC44 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC48 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC40 * 0.017453292f * 0.0200000014f);
        }
    }
    if (D_L01_001F3F40[0] == *(s32 *)(s2 + 0xE0)) {
        *(f32 *)(s3 + 0xF0) = func_0038DB48(*(f32 *)(s2 + 0x674));
        func_0038D308(s3 + 0xC0, s3 + 0xF0);
        *(vu0_q *)(s4 + 0xF0) = *(vu0_q *)(s3 + 0xF0);
        func_0038CC88(s4 + 0xC0, s3 + 0xC0, 0x30);
        func_0038CE20(s4 + 0x10, s3 + 0xE0, *(f32 *)(s2 + 0x6A8));
        vec_add_ab(s4 + 0x10, s4 + 0x10, s3 + 0x10);
        if (D_L01_001F3F40[0] == *(s32 *)(s2 + 0xE0)) {
            func_003C7C38(s3);
            func_003C7C38(s4);
        }
    }
    return *(f32 *)(s2 + 0x674) == f20;
}
/* localdecomp:end func_L01_003C7000 */
