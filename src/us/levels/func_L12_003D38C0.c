#include "common.h"

/* NTSC-U counterpart of func_L12_003D5570 (src/levels/shared/L12_003D5210.c): the retarget timer threshold and its random range (0x29, 0x14..0x28 against 0x22, 0x11..0x21) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L12_003D38C0 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4CB0;
extern vu0_v4 D_001A4D00;
__asm__(".extern D_L12_001DEFB4, 4");
extern f32 D_L12_001DEFB4;
__asm__(".extern D_L12_001DEFB8, 4");
extern f32 D_L12_001DEFB8;
__asm__(".extern D_L12_001DEFBC, 4");
extern f32 D_L12_001DEFBC;
__asm__(".extern D_L12_001DEFC0, 4");
extern f32 D_L12_001DEFC0;
__asm__(".extern D_L12_001DEFC8, 4");
extern f32 D_L12_001DEFC8;
__asm__(".extern D_L12_001DEFCC, 4");
extern f32 D_L12_001DEFCC;
__asm__(".extern D_L12_001DEFD4, 4");
extern f32 D_L12_001DEFD4;
__asm__(".extern D_L12_001DEFD8, 4");
extern f32 D_L12_001DEFD8;
__asm__(".extern D_L12_001DEFDC, 4");
extern f32 D_L12_001DEFDC;
__asm__(".extern D_L12_001DEFE0, 4");
extern f32 D_L12_001DEFE0;
extern void func_003886E8(void *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern u8 *func_0037E0B8(void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_003887A0(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L12_003D3768(void *, void *, void *, f32);

void func_L12_003D38C0(u8 *o, u8 *p) {
    vu0_v4 dir;
    vu0_v4 delta;
    vu0_v4 goal;
    vu0_v4 point;
    u8 *e;
    u8 *ride;
    u8 *info;
    u8 *tgt;
    s32 riding1A17;
    s32 riding;
    f32 d;
    f32 len;
    f32 k;

    riding1A17 = 0;
    riding = 0;
    e = *(u8 **)(p + 0x28);
    if (e == 0) {
        if ((u32)(o[0x20] - 2) >= 2) {
            return;
        }
        *(u128_t *)&goal = *(u128_t *)(p + 0x10);
    } else {
        u8 *h = D_001A4BE0;

        if (e == *(u8 **)(h + 0x25C0)) {
            if (*(s32 *)(h + 0x2850) <= 0) {
                *(s32 *)(p + 0x28) = 0;
                return;
            }
            ride = *(u8 **)(h + 0x19E0);
            if (ride != 0) {
                *(u128_t *)&goal = *(u128_t *)(h + 0xD0);
                if (*(s16 *)(ride + 0xAA) == 0x1A17) {
                    riding1A17 = 1;
                } else {
                    riding = 1;
                }
            }
            if (riding1A17 == 0 && (riding != 0 || o[0x20] == 3 || o[0x20] == 2)) {
                *(u128_t *)&goal = *(u128_t *)&D_001A4CB0;
            } else {
                if (riding1A17 != 0) {
                    u8 *hero = D_001A4BE0;

                    func_003886E8(&dir, *(u8 **)(*(u8 **)(*(u8 **)(hero + 0x19E0) + 0x68) + 0x6D0) + 0xC0, 0.5f);
                } else {
                    *(u128_t *)&dir = *(u128_t *)&D_001A4D00;
                }
                d = func_003887C8(&D_001A4CB0, o + 0x10);
                func_003886E8(&delta, &dir, d / *(f32 *)(p + 0x38));
                delta.z = 0.0f;
                vec_add_ab(&goal, &D_001A4CB0, &delta);
                vec_sub_ab(&delta, &goal, o + 0x10);
                vec_sub_ab(&dir, &D_001A4CB0, o + 0x10);
                if (func_00388730(&delta, &dir) < 0.3f) {
                    *(u128_t *)&goal = *(u128_t *)&D_001A4CB0;
                }
            }
        } else {
            info = func_0037E0B8(e);
            if (info != 0 && *(f32 *)info <= 0.0f) {
                *(s32 *)(p + 0x28) = 0;
                return;
            }
            tgt = *(u8 **)(p + 0x28);
            if (tgt == 0 || tgt[0x20] == 0xFE || tgt[0x20] == 0xFD) {
                *(s32 *)(p + 0x28) = 0;
                return;
            }
            *(u128_t *)&goal = *(u128_t *)(tgt + 0x10);
            if (info != 0) {
                goal.z = goal.z + *(f32 *)(info + 0x10);
            }
        }
        *(u128_t *)(p + 0x10) = *(u128_t *)&goal;
    }
    vec_sub_ab(&delta, &goal, o + 0x10);
    if (riding1A17 == 0 && o[0x20] == 1) {
        if (func_00388730(&delta, o + 0xC0) < 0.0f) {
            *(s32 *)(p + 0x28) = 0;
            if (*(s32 *)(p + 0x24) >= 0x29) {
                *(s32 *)(p + 0x24) = func_0037E208(0x14, 0x28);
            }
            return;
        }
    }
    if (riding1A17 != 0) {
        if (func_003887A0(&delta) < D_L12_001DEFDC) {
            *(u128_t *)&point = *(u128_t *)&goal;
        } else {
            func_00388830(&point, &delta, D_L12_001DEFE0);
            vec_add_ab(&point, &point, o + 0x10);
            point.z = goal.z + D_L12_001DEFE0;
        }
        k = D_L12_001DEFD8;
    } else if (riding != 0) {
        *(u128_t *)&point = *(u128_t *)&goal;
        k = D_L12_001DEFD4;
    } else {
        len = func_003887A0(&delta);
        if (len < D_L12_001DEFCC) {
            if (o[0x20] != 3) {
                func_L01_00441FB8(o, 3, -1);
            }
            *(u128_t *)&point = *(u128_t *)&goal;
            k = D_L12_001DEFC8;
        } else if (len < D_L12_001DEFBC) {
            if (o[0x20] == 1) {
                *(s32 *)(o + 0x98) = 0;
                func_L01_00441FB8(o, 2, -1);
            }
            func_00388830(&point, &delta, D_L12_001DEFB8);
            vec_add_ab(&point, &point, o + 0x10);
            point.z = goal.z + D_L12_001DEFC0;
            k = D_L12_001DEFC8;
        } else {
            if (D_L12_001DEFBC + 0.25f < len) {
                if (o[0x20] == 2) {
                    func_L01_00441FB8(o, 1, -1);
                }
            }
            func_00388830(&point, &delta, D_L12_001DEFB8);
            vec_add_ab(&point, &point, o + 0x10);
            point.z = goal.z + D_L12_001DEFB8;
            k = D_L12_001DEFB4;
        }
    }
    func_L12_003D3768(o, p, &point, k);
}
/* localdecomp:end func_L12_003D38C0 */
