#include "common.h"

/* NTSC-U counterpart of func_L01_003C7000 (src/levels/shared/L01_003C7000.c): 0.02 -> 0.0166667; 0.0004 -> 0.000277778 */
#include "vu0.h"

/* localdecomp:start func_L01_003C5780 */
extern s32 D_L01_001F3FC0[];
typedef struct { u8 p0[0x18]; u8 *p18; } G_EAA00;
extern G_EAA00 D_L01_001EAA80;
extern f32 D_L01_001DEC54_003C5780;
extern f32 D_L01_001DEC58_003C5780;
extern f32 D_L01_001DEC5C_003C5780;
extern f32 D_L01_001DEC60_003C5780;
extern f32 D_L01_001DEC64_003C5780;
extern f32 D_L01_001DEC68_003C5780;
extern f32 D_L01_001DEC6C_003C5780;
extern f32 D_L01_001DEC70;
extern f32 D_L01_001DEC78;
extern f32 D_L01_001DEC7C;
extern f32 D_L01_001DEC80;
extern f32 D_L01_001DEC84;
extern f32 D_L01_001DEC88;
__asm__(".extern D_L01_001DEC54_003C5780, 4");
__asm__(".extern D_L01_001DEC58_003C5780, 4");
__asm__(".extern D_L01_001DEC5C_003C5780, 4");
__asm__(".extern D_L01_001DEC60_003C5780, 4");
__asm__(".extern D_L01_001DEC64_003C5780, 4");
__asm__(".extern D_L01_001DEC68_003C5780, 4");
__asm__(".extern D_L01_001DEC6C_003C5780, 4");
__asm__(".extern D_L01_001DEC70, 4");
__asm__(".extern D_L01_001DEC78, 4");
__asm__(".extern D_L01_001DEC7C, 4");
__asm__(".extern D_L01_001DEC80, 4");
__asm__(".extern D_L01_001DEC84, 4");
__asm__(".extern D_L01_001DEC88, 4");
extern void func_00388830(void *, void *, f32);
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern f32 func_00388990(f32);
extern f32 func_00389410(f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, s32, f32, f32, f32);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_00388550(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003C26C8(void *);

s32 func_L01_003C5780(u8 *a0, u8 *s2) {
    u8 *s3;
    u8 *s4;
    f32 f20;
    f32 f21;
    s32 flag;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;

    if (D_L01_001F3FC0[0] == *(s32 *)(s2 + 0xE0)) {
        s3 = *(u8 **)(s2 + 0xD8);
        s4 = *(u8 **)(s2 + 0xDC);
    } else {
        s3 = *(u8 **)(s2 + 0x4C);
        s4 = *(u8 **)(s2 + 0x50);
    }
    if (*(f32 *)(s2 + 0x674) < D_L01_001DEC60_003C5780 * 0.017453292f) {
        f20 = D_L01_001DEC5C_003C5780 * 0.017453292f;
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
        f21 = *(f32 *)(s2 + 0x6A8) + D_L01_001DEC54_003C5780;
        func_00388830(&v2, s3 + 0xC0, D_L01_001DEC58_003C5780);
        func_00388830(&v1, s3 + 0xE0, f21);
        vec_add_ba(&v1, &v1, s3 + 0x10);
        vec_add_ba(&v1, &v1, &v2);
        vec_add_ab(&v0, s3 + 0x10, &v2);
        t = v0.z - func_003BE7F0(&v1, 0, s4, 10.0f);
        if (D_L01_001EAA80.p18 == s3 || f21 < t) {
            f20 = D_L01_001DEC5C_003C5780 * 0.017453292f;
        } else {
            f20 = func_00389410(func_00388990(t / f21) + 1.5707964f);
            if (D_L01_001F3FC0[0] != *(s32 *)(s2 + 0xE0)) {
                f20 = func_003893C8(f20, *(f32 *)(a0 + 0xF4));
                if (f20 < 0.0f) {
                    f20 += 6.2831855f;
                }
            }
            if (D_L01_001DEC5C_003C5780 * 0.017453292f < f20) {
                f20 = D_L01_001DEC5C_003C5780 * 0.017453292f;
            }
        }
        func_00388830(&v1, s3 + 0xE0, f21);
        vec_add_ba(&v1, &v1, s3 + 0x10);
        vec_sub_ba(&v1, &v1, &v2);
        vec_sub_ab(&v0, s3 + 0x10, &v2);
        t = v0.z - func_003BE7F0(&v1, 0, s4, 10.0f);
        {
            f32 g;

            if (D_L01_001EAA80.p18 == s3 || f21 < t) {
                g = D_L01_001DEC5C_003C5780 * 0.017453292f;
            } else {
                g = func_00389410(func_00388990(t / f21) + 1.5707964f);
                if (D_L01_001F3FC0[0] != *(s32 *)(s2 + 0xE0)) {
                    g = func_003893C8(g, *(f32 *)(a0 + 0xF4));
                    if (g < 0.0f) {
                        g += 6.2831855f;
                    }
                }
                if (D_L01_001DEC5C_003C5780 * 0.017453292f < g) {
                    g = D_L01_001DEC5C_003C5780 * 0.017453292f;
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
        f32 acc = D_L01_001DEC70 * 0.017453292f * 0.0166666675f;

        if (*(f32 *)(s2 + 0x98) < acc) {
            *(f32 *)(s2 + 0x98) = acc;
        }
        func_L01_00445758(s2 + 0x674, f20, s2 + 0x98, 0, D_L01_001DEC68_003C5780 * 0.017453292f * 0.000277777785f,
                          D_L01_001DEC6C_003C5780 * 0.017453292f * 0.000277777785f, D_L01_001DEC64_003C5780 * 0.017453292f * 0.0166666675f);
    }
    *(f32 *)(s2 + 0x694) = *(f32 *)(s2 + 0x674);
    if (*(s32 *)(s2 + 0xB0) != 3) {
        if (D_L01_001DEC78 * 0.017453292f < *(f32 *)(s2 + 0x674)) {
            func_003BEC60((f32 *)(s2 + 0x6A8), s2 + 0x9C, D_L01_001DEC7C,
                          D_L01_001DEC84 * 0.017453292f * 0.000277777785f,
                          D_L01_001DEC88 * 0.017453292f * 0.000277777785f,
                          D_L01_001DEC80 * 0.017453292f * 0.0166666675f);
        }
    }
    if (D_L01_001F3FC0[0] == *(s32 *)(s2 + 0xE0)) {
        *(f32 *)(s3 + 0xF0) = func_00389410(*(f32 *)(s2 + 0x674));
        func_00388BD0(s3 + 0xC0, s3 + 0xF0);
        *(vu0_q *)(s4 + 0xF0) = *(vu0_q *)(s3 + 0xF0);
        func_00388550(s4 + 0xC0, s3 + 0xC0, 0x30);
        func_003886E8(s4 + 0x10, s3 + 0xE0, *(f32 *)(s2 + 0x6A8));
        vec_add_ab(s4 + 0x10, s4 + 0x10, s3 + 0x10);
        if (D_L01_001F3FC0[0] == *(s32 *)(s2 + 0xE0)) {
            func_003C26C8(s3);
            func_003C26C8(s4);
        }
    }
    return *(f32 *)(s2 + 0x674) == f20;
}
/* localdecomp:end func_L01_003C5780 */
