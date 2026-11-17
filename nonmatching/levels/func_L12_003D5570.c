/* NTSC-U draft (Claude wave C4): C of func_L12_003D38C0, the NTSC-U twin of func_L12_003D5570, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 43 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L12_003D38C0", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (vec_add_ab/vec_sub_ab/vec_copy; 0.3f is lui/ori/mtc1); the PAL file L12_003D4B18.c has plain STD, so it cannot land as is. With them 303/300 words and 43 aligned diff words ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_003D38C0 */
/* func_L12_003D38C0: camera/helper follow update (state p, target object at p+0x28, hero special cases):
   picks the goal vector local20, steers the point local30 (func_00388830 scaled by the D_001DEF*_sda gp
   floats, vec_add with the object position) and hands it to func_L12_003D3768. Written from the retail
   assembly (C4 w02 fork F4).
   Build needs "-mvu0-use-vf0-vf2 ... @ps2as" (vec_* helpers; 0.3f is lui/ori/mtc1).
   Not matched: the vector block after 'local10.z = 0.0f' (retail 0x144..0x1A8: five lqc2/sqc2 copies into
   t40/t50/t60/t70 around one vadd and two vsub, the second vsub result stored twice from the same register).
   With vec_copy for all five copies cc1 spills three vf values (3 more stack slots); the best mix keeps the
   t40/t50 copies as plain 128-bit copies (lq/sq): everything outside that block is identical to retail. */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;

extern Hero D_001A4BE0;
extern u8 D_001A4CB0[];
extern u8 D_001A4D00[];
extern f32 D_001DEFB4_sda;
__asm__(".extern D_001DEFB4_sda, 4");
extern f32 D_001DEFB8_sda;
__asm__(".extern D_001DEFB8_sda, 4");
extern f32 D_001DEFBC_sda;
__asm__(".extern D_001DEFBC_sda, 4");
extern f32 D_001DEFC0_sda;
__asm__(".extern D_001DEFC0_sda, 4");
extern f32 D_001DEFC8_sda;
__asm__(".extern D_001DEFC8_sda, 4");
extern f32 D_001DEFCC_sda;
__asm__(".extern D_001DEFCC_sda, 4");
extern f32 D_001DEFD4_sda;
__asm__(".extern D_001DEFD4_sda, 4");
extern f32 D_001DEFD8_sda;
__asm__(".extern D_001DEFD8_sda, 4");
extern f32 D_001DEFDC_sda;
__asm__(".extern D_001DEFDC_sda, 4");
extern f32 D_001DEFE0_sda;
__asm__(".extern D_001DEFE0_sda, 4");
extern void func_003886E8(void *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern void func_00388830(void *, void *, f32);
extern u8 *func_0037E0B8(u8 *);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L12_003D3768(void *, void *, void *, f32);

void func_L12_003D38C0(u8 *o, u8 *p) {
    vu0_v4 local0;
    vu0_v4 local10;
    vu0_v4 local20;
    vu0_v4 local30;
    vu0_v4 t40;
    vu0_v4 t50;
    vu0_v4 t60;
    vu0_v4 t70;
    u8 *e;
    u8 *a1;
    u8 *e2;
    s32 s5;
    s32 s6;
    s32 b;
    f32 d;
    f32 len;
    f32 k;
    u8 *hv;
    u8 *s1;

    s5 = 0;
    s6 = 0;
    e = *(u8 **)(p + 0x28);
    if (e == 0) {
        if ((u32)(o[0x20] - 2) >= 2) {
            return;
        }
        *(u128_t *)&local20 = *(u128_t *)(p + 0x10);
        goto l254;
    }
    if (e == D_001A4BE0.ptr[0x25C0 / 4]) {
        if (D_001A4BE0.i[0x2850 / 4] <= 0) {
            *(s32 *)(p + 0x28) = 0;
            return;
        }
        a1 = D_001A4BE0.ptr[0x19E0 / 4];
        if (a1 != 0) {
            *(u128_t *)&local20 = D_001A4BE0.q[0xD0 / 16];
            if (*(s16 *)(a1 + 0xAA) == 0x1A17) {
                s5 = 1;
            } else {
                s6 = 1;
            }
        }
        if (s5 == 0) {
            if (s6 == 0) {
                b = o[0x20];
                if (b == 3) {
                    goto l0cc;
                }
                if (b != 2) {
                    goto l108;
                }
            }
        l0cc:
            *(u128_t *)&local20 = *(u128_t *)D_001A4CB0;
            goto l24c;
        }
        func_003886E8(&local0, *(u8 **)(*(u8 **)(D_001A4BE0.ptr[0x19E0 / 4] + 0x68) + 0x6D0) + 0xC0, 0.5f);
        goto l118;
    l108:
        *(u128_t *)&local0 = *(u128_t *)D_001A4D00;
    l118:
        d = func_003887C8(D_001A4CB0, o + 0x10);
        func_003886E8(&local10, &local0, d / *(f32 *)(p + 0x38));
        local10.z = 0.0f;
        vec_copy(&t60, &local10);
        *(u128_t *)&t50 = *(u128_t *)D_001A4CB0;
        *(u128_t *)&t40 = *(u128_t *)(o + 0x10);
        vec_add_ab(&local20, D_001A4CB0, &t60);
        vec_copy(&t70, &local20);
        vec_sub_ab(&t60, &t50, o + 0x10);
        vec_sub_ab(&t70, &t70, &t40);
        vec_copy(&local10, &t70);
        vec_copy(&local0, &t60);
        d = func_00388730(&local10, &local0);
        if (d < 0.3f) {
            *(u128_t *)&local20 = *(u128_t *)D_001A4CB0;
            goto l24c;
        }
        goto l250;
    }
    a1 = func_0037E0B8(e);
    if (a1 != 0 && *(f32 *)a1 <= 0.0f) {
        *(s32 *)(p + 0x28) = 0;
        return;
    }
    e2 = *(u8 **)(p + 0x28);
    if (e2 == 0 || e2[0x20] == 0xFE || e2[0x20] == 0xFD) {
        *(s32 *)(p + 0x28) = 0;
        return;
    }
    *(u128_t *)&local20 = *(u128_t *)(e2 + 0x10);
    if (a1 != 0) {
        local20.z = local20.z + *(f32 *)(a1 + 0x10);
    }
l24c:
l250:
    *(u128_t *)(p + 0x10) = *(u128_t *)&local20;
l254:
    vec_sub_ab(&local10, &local20, o + 0x10);
    if (s5 == 0 && o[0x20] == 1) {
        if (func_00388730(&local10, o + 0xC0) < 0.0f) {
            *(s32 *)(p + 0x28) = 0;
            if (*(s32 *)(p + 0x24) >= 0x29) {
                *(s32 *)(p + 0x24) = func_0037E208(0x14, 0x28);
            }
            return;
        }
    }
    if (s5 != 0) {
        d = func_003887A0(&local10);
        if (d < D_001DEFDC_sda) {
            *(u128_t *)&local30 = *(u128_t *)&local20;
        } else {
            func_00388830(&local30, &local10, D_001DEFE0_sda);
            vec_add_ab(&local30, &local30, o + 0x10);
            local30.z = local20.z + D_001DEFE0_sda;
        }
        k = D_001DEFD8_sda;
    } else if (s6 != 0) {
        *(u128_t *)&local30 = *(u128_t *)&local20;
        k = D_001DEFD4_sda;
    } else {
        len = func_003887A0(&local10);
        if (len < D_001DEFCC_sda) {
            if (o[0x20] != 3) {
                func_L01_00441FB8(o, 3, -1);
            }
            *(u128_t *)&local30 = *(u128_t *)&local20;
            k = D_001DEFC8_sda;
        } else if (len < D_001DEFBC_sda) {
            if (o[0x20] == 1) {
                *(s32 *)(o + 0x98) = 0;
                func_L01_00441FB8(o, 2, -1);
            }
            func_00388830(&local30, &local10, D_001DEFB8_sda);
            vec_add_ab(&local30, &local30, o + 0x10);
            local30.z = local20.z + D_001DEFC0_sda;
            k = D_001DEFC8_sda;
        } else {
            if (D_001DEFBC_sda + 0.25f < len) {
                if (o[0x20] == 2) {
                    func_L01_00441FB8(o, 1, -1);
                }
            }
            func_00388830(&local30, &local10, D_001DEFB8_sda);
            vec_add_ab(&local30, &local30, o + 0x10);
            local30.z = local20.z + D_001DEFB8_sda;
            k = D_001DEFB4_sda;
        }
    }
    func_L12_003D3768(o, p, &local30, k);
}
/* localdecomp:end func_L12_003D38C0 */
