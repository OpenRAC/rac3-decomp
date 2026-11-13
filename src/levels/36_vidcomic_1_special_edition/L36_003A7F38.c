#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L36_003A7F38);

/* localdecomp:start func_L36_003A85A8 */
extern u8 D_001A4BE0[];
extern u8 *D_L36_001DFC00;
extern void func_0038CF68(void *, void *, f32);
extern void func_L32_00347FE8(u8 *, void *, f32, f32, s32, s32, s32, s32, s32);
extern s32 func_00382380(u8 *, s32, s32);
__asm__(".extern D_L36_001DEA98, 4");
extern f32 D_L36_001DEA98;
void func_L36_003A85A8(u8 *a0) {
    u8 *g = D_001A4BE0;
    u8 *s;
    u8 st;
    vu0_v4 v;
    *(f32 *)(a0 + 0x14) = *(f32 *)(g + 0x84);
    s = *(u8 **)(a0 + 0x68);
    *(f32 *)(a0 + 0xF4) = *(f32 *)(s + 0x70);
    *(f32 *)(a0 + 0xF0) = *(f32 *)(s + 0x74);
    *(u16 *)(a0 + 0x96) += 1;
    st = *(u8 *)(a0 + 0x20);
    if (st != 0x42 && st != 4 && st != 0 && st != 5) {
        vec_sub_ba(&v, g + 0x80, a0 + 0x10);
        func_0038CF68(&v, &v, 1.0f);
        func_L32_00347FE8(a0, &v, (f32)*(u8 *)(s + 0x14), D_L36_001DEA98, 0, 1, 0, 0, 0);
    }
    if (func_00382380(a0 + 0x10, *(s32 *)(s + 0x8C), 0) == 0) {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(D_L36_001DFC00 + *(s32 *)(s + 0x8C) * 0x80 + 0x30);
    }
}
/* localdecomp:end func_L36_003A85A8 */

/* localdecomp:start func_L36_003A86B8 */
extern s32 D_L36_001DEAD4;
extern s32 func_L01_00456250(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L36_003A87C0(u8 *);
extern s32 func_0038CAD0(u8 *);
void func_L36_003A86B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(s32 *)(s + 0x10) = D_L36_001DEAD4;
        *(s32 *)(s + 0xC) = 0;
        *(u8 *)(a0 + 0x31) = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(a0) != 0) {
            *(s32 *)(a0 + 0x98) = 0;
            func_L01_004450F0(a0, 2, -1);
        }
        func_L36_003A87C0(a0);
        break;
    case 2:
        if (func_L01_00456250(a0) == 0) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            func_L01_004450F0(a0, 1, -1);
        }
        if (func_0038CAD0(s + 0x10) == 0) {
            func_L36_003A87C0(a0);
        }
        break;
    }
}
/* localdecomp:end func_L36_003A86B8 */

/* localdecomp:start func_L36_003A87C0 */
__asm__(".extern D_L36_001DEAC8, 4");
__asm__(".extern D_L36_001DEAD4, 4");
__asm__(".extern D_L36_001DEAB8, 4");
__asm__(".extern D_L36_001DEAC0, 4");
__asm__(".extern D_L36_001DEAD0, 4");
__asm__(".extern D_L36_001DEAC4, 4");
__asm__(".extern D_L36_001DEAB4, 4");
__asm__(".extern D_L36_001DEABC, 4");
__asm__(".extern D_L36_001DEACC, 4");
extern f32 D_L36_001DEAC8;
extern s32 D_L36_001DEAD4;
extern f32 D_L36_001DEAB8;
extern f32 D_L36_001DEAC0;
extern f32 D_L36_001DEAD0;
extern f32 D_L36_001DEAC4;
extern f32 D_L36_001DEAB4;
extern s32 D_L36_001DEABC;
extern s32 D_L36_001DEACC;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, f32, f32, f32, s32, s32, s32);
void func_L36_003A87C0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 v0, v1;
    s32 col;
    f32 r;
    *(f32 *)(s + 0xC) = *(f32 *)(s + 0xC) + D_L36_001DEAC8 * (f32)*(s32 *)(s + 0x10) / (f32)D_L36_001DEAD4;
    if (1.0f < *(f32 *)(s + 0xC)) {
        do {
            f32 e = D_L36_001DEAB8;
            *(f32 *)(s + 0xC) = *(f32 *)(s + 0xC) - 1.0f;
            *(u128_t *)&v1 = *(u128_t *)(a0 + 0x10);
            v1.x = v1.x + func_003824E0(-e, e);
            v1.z = v1.z + func_003824E0(-D_L36_001DEAB8, D_L36_001DEAB8);
            qzero(&v0);
            v0.z = D_L36_001DEAD0;
            col = (*(s32 *)(s + 8) << 16) | (*(s32 *)(s + 4) << 8) | *(s32 *)s;
            r = func_003824E0(D_L36_001DEAC0, D_L36_001DEAC4);
            func_L01_004713C8(&v1, &v0, D_L36_001DEABC, col, func_00382498(-4, 4), r, 0.0f, D_L36_001DEAB4,
                              0x80, 0, D_L36_001DEACC);
        } while (1.0f < *(f32 *)(s + 0xC));
    }
}
/* localdecomp:end func_L36_003A87C0 */

/* localdecomp:start func_L36_003A8920 */
__asm__(".extern D_L36_001DEADC, 4");
__asm__(".extern D_L36_001DEAE0, 4");
__asm__(".extern D_L36_001DEAE4, 4");
__asm__(".extern D_L36_001DEAE8, 4");
__asm__(".extern D_L36_001DEAD8, 4");
extern s32 D_L36_001DEADC;
extern f32 D_L36_001DEAE0;
extern f32 D_L36_001DEAE4;
extern s32 D_L36_001DEAE8;
extern f32 D_L36_001DEAD8;
__asm__(".extern D_L36_001E1FB0, 16");
extern u8 D_L36_001E1FB0;
extern f32 D_L36_001E1FB4;
extern void func_L03_0034B218(f32, u8 *, s32, s32, s32, void *);
extern void func_L36_003A8AB0(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);
extern s32 func_0038CAD0(u8 *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C8A8(u8 *, u8 *);
extern void func_L01_0044E820(u8 *, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L36_003A8CF8(u8 *);
void func_L36_003A8920(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 t;
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        t = D_L36_001DEADC;
        *(s32 *)(s + 0x50) = 0;
        if (t == 0) {
            D_L36_001DEADC = 1;
            func_L03_0034B218(D_L36_001DEAE0, &D_L36_001E1FB0, 0x11, 8, D_L36_001DEAE8, (void *)func_L36_003A8AB0);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 0x42:
        if (func_L01_004561B8(a0) != 0) {
            func_003A52A0(1, 0, a0);
            *(s32 *)(s + 0x54) = 0x43;
        }
        if (func_0038CAD0(s + 0x54) == 0) {
            if (*(s32 *)(s + 0x54) == 0x32) {
                func_003A52A0(0, 0, a0);
            }
            *(u8 *)(a0 + 0x23) = (s32)((f32)*(s32 *)(s + 0x54) * 128.0f / 80.0f);
            D_L36_001E1FB4 = func_003C4088(D_L36_001DEAE4, D_L36_001DEAE0, (f32)*(s32 *)(s + 0x54) / 80.0f);
            func_L30_0034C8A8(&D_L36_001E1FB0, a0);
        }
        break;
    case 1:
        if (*(s32 *)(s + 0x58) != 0) {
            func_L01_0044E820(a0, 0x80000080);
        }
        *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), D_L36_001DEAD8);
        break;
    }
    func_L36_003A8CF8(a0);
}
/* localdecomp:end func_L36_003A8920 */

/* localdecomp:start func_L36_003A8AB0 */
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
void func_L36_003A8AB0(u8 *a0, u8 *a1) {
    u8 *o;
    u8 *s;
    f32 ang;
    f32 rad;
    vu0_v4 v;
    s32 n;
    if (a1 == 0) {
        return;
    }
    o = *(u8 **)a1;
    n = *(s32 *)(a1 + 4);
    s = *(u8 **)(o + 0x68);
    if (o == 0 || n == 0) {
        return;
    }
    if (*(u16 *)(a1 + 0xA) & 1) {
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        rad = func_003824E0(0.0f, 1.5f);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(o + 0x10);
        *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 2.0f;
        v.x = func_0038D098(ang) * rad;
        v.z = func_0038D0B0(ang) * rad;
        v.y = 0.0f;
        vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
    }
    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 0.015f;
    if (*(u16 *)(a1 + 0xA) & 1) {
        if (*(s32 *)(s + 0x58) != 0) {
            s32 r1, r2, r3;
            r1 = func_00382498(0, 0x40);
            r2 = func_00382498(0, 0x40);
            r3 = func_00382498(0x40, 0x80);
            *(s32 *)(a0 + 4) = ((s32)((f32)*(s16 *)(a0 + 0xA) * 128.0f / (f32)*(s16 *)(a1 + 8)) << 24) | (r1 << 16) | (r2 << 8) | r3;
        } else {
            s32 r1, r2, r3;
            r1 = func_00382498(0, 0x40);
            r2 = func_00382498(0x60, 0x80);
            r3 = func_00382498(0, 0x40);
            *(s32 *)(a0 + 4) = ((s32)((f32)*(s16 *)(a0 + 0xA) * 128.0f / (f32)*(s16 *)(a1 + 8)) << 24) | (r1 << 16) | (r2 << 8) | r3;
        }
    }
    *(u8 *)(a0 + 8) = (s32)(f32)*(u8 *)(a1 + 0xE);
    *(f32 *)(a0 + 0xC) = func_003C4088(315000.0f, 42000.0f, (f32)*(s16 *)(a0 + 0xA) / (f32)*(s16 *)(a1 + 8));
}
/* localdecomp:end func_L36_003A8AB0 */

/* localdecomp:start func_L36_003A8CF8 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_L36_001DEAEC, 4");
extern f32 D_L36_001DEAEC;
extern u8 D_001A4C60[];
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_003C4A40(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_0038CF00(u8 *, u8 *);
void func_L36_003A8CF8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *r = func_L01_00447490(a0, 0x10000, 0);
    f32 f;
    if (r != 0) {
        *(u8 *)(a0 + 0xA8) = 0xFF;
        f = *(f32 *)(r + 0x2C);
        if (0.0f < f) {
            if (*(u8 *)(a0 + 0x20) != 0x42) {
                if (*(s32 *)(s + 0x50) <= 0) {
                    *(s32 *)(s + 0x50) = 0xC;
                    *(u8 *)(s + 0x47) = 0xFF;
                    *(f32 *)s = *(f32 *)s - f;
                    func_003C4A40(a0, s + 0x40);
                    if (*(f32 *)s <= 0.0f) {
                        func_L01_004450F0(a0, 0x42, -1);
                    }
                }
            }
        }
    }
    if (func_0038CF00(D_001A4C60, a0 + 0x10) < D_L36_001DEAEC) {
        if (*(u8 *)(a0 + 0x20) != 0x42) {
            func_L01_004450F0(a0, 0x42, -1);
        }
    }
}
/* localdecomp:end func_L36_003A8CF8 */
