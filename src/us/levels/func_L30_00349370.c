#include "common.h"

/* NTSC-U counterpart of func_L30_0034A108 (src/levels/30_vidcomic_unnamed/L30_00349390.c) */
#include "vu0.h"
extern u8 *D_L30_001DF71C_00349370;
extern u8 *D_L30_001DF71C_00349370;
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern u8 *D_L30_001DF71C_00349370;

/* localdecomp:start func_L30_00349370 */
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[0x34 - 0x28]; u16 h34; u8 pad36[0x98 - 0x36]; s32 w98; u8 pad9C[0x100 - 0x9C]; } E_0034A108;
typedef struct {
    s32 w0;
    s32 w4;
    u8 pad8[0x10 - 0x8];
    s32 w10;
    f32 f14;
    f32 f18;
    s32 w1C;
    u8 pad20[0x24 - 0x20];
    s32 w24;
    s32 w28;
    f32 f2C;
    s32 w30;
    s32 w34;
} S_0034A108;

__asm__(".extern D_L30_001DF71C_00349370, 16");
extern u8 *D_L30_001DF71C_00349370;
extern u8 D_001A4C60[];
__asm__(".extern D_L30_001DD400_00349370, 4");
extern f32 D_L30_001DD400_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD404_00349370, 4");
extern f32 D_L30_001DD404_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD408_00349370, 4");
extern f32 D_L30_001DD408_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD40C_00349370, 4");
extern f32 D_L30_001DD40C_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD410_00349370, 4");
extern f32 D_L30_001DD410_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD414_00349370, 4");
extern f32 D_L30_001DD414_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD418_00349370, 4");
extern s32 D_L30_001DD418_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD424_00349370, 4");
extern f32 D_L30_001DD424_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD428_00349370, 4");
extern f32 D_L30_001DD428_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD42C_00349370, 4");
extern f32 D_L30_001DD42C_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD440_00349370, 4");
extern s32 D_L30_001DD440_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD444_00349370, 4");
extern s32 D_L30_001DD444_00349370 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD448_00349370, 4");
extern s32 D_L30_001DD448_00349370 __attribute__((section(".sdata")));
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern s32 func_00388398(void *);
extern f32 func_L01_00436500(void *);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_003BD360(void *);
extern void func_L30_00349F30(s32, s32);
extern void func_L30_00349C88(void *);
extern void func_L30_00349BD0(void *);
extern void func_L30_00349E60(u8 *);

void func_L30_00349370(u8 *a0) {
    S_0034A108 *st = *(S_0034A108 **)(a0 + 0x68);
    s32 base;
    f32 t;
    f32 k;

    switch (a0[0x20]) {
    case 0:
        st->w1C = 0;
        st->w28 = 0;
        st->w34 = 0;
        st->w24 = 1;
        ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].h34 |= 0x41;
        ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].h34 &= 0xEFFF;
        ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].w98 = 0;
        func_L01_004A6DF8(&((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0], 1);
        ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].h34 |= 0x41;
        ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].h34 &= 0xEFFF;
        ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].w98 = 0;
        func_L01_004A6DF8(&((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4], 1);
        st->f2C = func_003BE7F0(a0 + 0x10, 0, 0, 0.5f);
        if (a0[0x43] != 1) {
            func_003BE4F0(a0, 1, 0, 0);
        }
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_0037E0F0(D_001A4C60, st->w10, 0) != 0) {
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].h34 &= 0xFFBE;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].h34 |= *(u16 *)(((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].p24 + 0x44) & 0x1000;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].w98 = *(s32 *)(((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].p24 + 0x10);
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].h34 &= 0xFFBE;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].h34 |= *(u16 *)(((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].p24 + 0x44) & 0x1000;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].w98 = *(s32 *)(((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].p24 + 0x10);
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(a0)) {
            st->w34 = D_L30_001DD440_00349370;
        }
        func_L30_00349F30((s32)a0, 0);
        if (func_00388398(&st->w34)) {
            func_L01_00441FB8(a0, 4, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0)) {
            st->w30 = 0;
            st->w34 = D_L30_001DD448_00349370;
            st->w24 = 0;
            *(f32 *)(a0 + 0x48) = D_L30_001DD414_00349370;
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 10);
            }
        }
        if (st->w30 != 0) {
            if (st->w1C == 1) {
                *(f32 *)(a0 + 0xF8) = (1.0f - (f32)st->w34 / (f32)D_L30_001DD444_00349370) * 3.1415927f;
            } else {
                *(f32 *)(a0 + 0xF8) = (f32)st->w34 / (f32)D_L30_001DD444_00349370 * 3.1415927f;
            }
        }
        if (func_00388398(&st->w34)) {
            if (st->w30 == 0) {
                st->w24 = 1;
                st->w34 = D_L30_001DD444_00349370;
                st->w30 = 1;
                if (a0[0x43] != 6) {
                    func_003BE4F0(a0, 6, 0, 10);
                }
            } else {
                st->w30 = 0;
                st->w1C = st->w1C == 0;
                func_L01_00441FB8(a0, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0)) {
            st->w24 = 1;
            *(f32 *)(a0 + 0x48) = D_L30_001DD410_00349370;
            if (a0[0x43] != (st->w1C == 1 ? 3 : 2)) {
                func_003BE4F0(a0, st->w1C == 1 ? 3 : 2, 0, 10);
            }
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 5, -1);
        }
        break;
    case 5:
        base = st->w1C == 1 ? 4 : 0;
        if (func_L01_00452EC8(a0)) {
            if (a0[0x43] != base + 8) {
                func_003BE4F0(a0, base + 8, 0, 10);
            }
            a0[0xBC] = 0;
            *(f32 *)(a0 + 0x48) = D_L30_001DD404_00349370;
            st->w28 = 0;
        }
        if (a0[0x60] & 2) {
            if (a0[0xBC] == 0) {
                if (a0[0x43] != base + 10) {
                    func_003BE4F0(a0, base + 10, 0, 3);
                }
                a0[0xBC] = 1;
                *(f32 *)(a0 + 0x48) = D_L30_001DD400_00349370;
                func_L30_00349C88(a0);
            }
            if (a0[0xBC] == 1) {
                st->w28++;
                func_L30_00349C88(a0);
                if (st->w28 >= D_L30_001DD418_00349370) {
                    if (a0[0x43] != base + 11) {
                        func_003BE4F0(a0, base + 11, 0, 3);
                    }
                    a0[0xBC] = 2;
                    *(f32 *)(a0 + 0x48) = D_L30_001DD404_00349370;
                }
            }
            if (a0[0xBC] == 2) {
                func_L01_00441FB8(a0, 6, -1);
            }
        }
        break;
    case 6:
        if (func_L01_00452EC8(a0)) {
            *(s32 *)(a0 + 0x98) = 0;
            if (a0[0x43] != 5) {
                func_003BE4F0(a0, 5, 0, 5);
            }
            *(f32 *)(a0 + 0x48) = D_L30_001DD408_00349370;
        }
        t = func_L01_00436500(a0);
        if (D_L30_001DD424_00349370 <= t && t <= D_L30_001DD428_00349370) {
            k = (t - D_L30_001DD424_00349370) / (D_L30_001DD428_00349370 - D_L30_001DD424_00349370);
            if (st->w1C == 1) {
                *(f32 *)(a0 + 0x10) = func_003BEB48(st->f14, st->f18, k);
            } else {
                *(f32 *)(a0 + 0x10) = func_003BEB48(st->f18, st->f14, k);
            }
            *(f32 *)(a0 + 0x18) = st->f2C + D_L30_001DD42C_00349370 * 4.0f * k * (1.0f - k);
        }
        if (D_L30_001DD428_00349370 < t) {
            st->w24 = 0;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            *(f32 *)(a0 + 0x18) = st->f2C;
            *(f32 *)(a0 + 0x10) = st->w1C == 1 ? st->f18 : st->f14;
        }
        if (a0[0x60] & 2) {
            func_L01_00441FB8(a0, 3, -1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(a0)) {
            if (a0[0x43] != 0x10) {
                func_003BE4F0(a0, 0x10, 0, 10);
            }
            *(f32 *)(a0 + 0x48) = D_L30_001DD40C_00349370;
            st->w24 = 1;
        }
        if (a0[0x60] & 2) {
            if (st->w30 == 0) {
                st->w34 = 0;
            }
            if (a0[0x43] != 6) {
                func_003BE4F0(a0, 6, 0, 10);
            }
            a0[0x20] = 3;
        }
        break;
    case 8:
        if (func_L01_00452EC8(a0)) {
            if (a0[0x43] != 0x11) {
                func_003BE4F0(a0, 0x11, 0, 10);
            }
        }
        func_L30_00349F30((s32)a0, 1);
        if (a0[0x60] & 2) {
            func_L30_00349F30((s32)a0, 1);
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].h34 |= 0x41;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].h34 &= 0xEFFF;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0].w98 = 0;
            func_L01_004A6DF8(&((E_0034A108 *)D_L30_001DF71C_00349370)[st->w0], 1);
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].h34 |= 0x41;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].h34 &= 0xEFFF;
            ((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4].w98 = 0;
            func_L01_004A6DF8(&((E_0034A108 *)D_L30_001DF71C_00349370)[st->w4], 1);
            func_003BD360(a0);
            return;
        }
        break;
    }
    if (a0[0x20] != 6) {
        func_L30_00349BD0(a0);
    }
    func_L30_00349E60(a0);
}
/* localdecomp:end func_L30_00349370 */
