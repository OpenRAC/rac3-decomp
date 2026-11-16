#include "common.h"

/* NTSC-U counterpart of func_L03_003D0A28 (src/levels/03_starship_phoenix/L03_003D0A28.c) */
/* localdecomp:start func_L03_003CE9F8 */
#include "vu0.h"
typedef int u128_003D0A28 __attribute__((mode(TI)));
extern u8 D_00142CBE[];
extern s32 D_L03_001D6694_003CE9F8;
extern s32 D_001A71A4[];
extern s32 D_00142C10[];
extern u8 D_001D5470[8];
extern f32 D_001DF000_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DF000_sda, 4");
extern f32 D_001DF010_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DF010_sda, 4");
extern void func_003BD360(void *);
extern s32 func_L01_004B6C68(void);
extern void func_L03_003CEE58(u8 *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_0037E250(f32, f32);
extern void func_003886C0(f32 *, f32 *, f32 *, f32);
extern s32 func_L02_003E4788(f32, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_L01_00457708(void *, f32);
extern s32 func_L02_0042DDE0(void *, void *, f32, s32, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_004576E8(void *);
extern s32 func_00388398(void *);
extern void func_L03_00446540(void *, s32, s32, s32);
extern s32 func_L01_00458AE0(void *, s32);
extern void func_L01_00458A08(void *, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
void func_L03_003CE9F8(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 d[4];
    f32 ang;
    if (D_00142CBE[0] != 0) {
        func_003BD360(a0);
        return;
    }
    if (func_L01_004B6C68() != 0 || D_001A71A4[0] == 0x65) {
        if (D_L03_001D6694_003CE9F8 == 2) {
            a0[0x31] = 0;
            *(u16 *)(a0 + 0x34) |= 1;
        }
        return;
    }
    a0[0x31] = 1;
    *(u16 *)(a0 + 0x34) &= ~1;
    switch (a0[0x20]) {
    case 0:
        func_L03_003CEE58(a0);
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 1);
        }
        func_L01_00441FB8(a0, 4, -1);
        break;
    case 1:
        if (func_L01_00452EC8(a0) != 0) {
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 1);
            }
        }
        if (D_00142C10[0] & 0x10000) {
            *(u128_003D0A28 *)(a0 + 0x10) = *(u128_003D0A28 *)D_001DF000_sda;
            *(f32 *)(a0 + 0xF8) = 1.5707964f;
            *(s32 *)(q + 0x68) &= ~0x10;
            func_L01_00441FB8(a0, 3, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(a0) != 0) {
            func_003886C0((f32 *)(q + 0x120), D_001DF000_sda, D_001DF010_sda, func_0037E250(0.0f, 1.0f));
            if (func_L02_003E4788(0.5f, q + 0x120, a0 + 0x10) != 0) {
                func_L01_00441FB8(a0, 3, -1);
                break;
            }
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, 15);
            }
            vec_sub_ab(d, q + 0x120, a0 + 0x10);
            *(f32 *)(q + 0x138) = func_00388A28(d[0], d[1]);
        }
        if (func_00389468(*(f32 *)(a0 + 0xF8), *(f32 *)(q + 0x138)) > 0.017453292f) {
            func_L01_00457708(a0, *(f32 *)(q + 0x138));
        } else {
            func_L02_0042DDE0(a0, q + 0x120, *(f32 *)(q + 0x138), *(s32 *)(q + 0x68), 0.033333335f, 0.0011111111f, 0.0022222223f);
        }
        if (func_L02_003E4788(0.2f, a0 + 0x10, q + 0x120) != 0) {
            func_L01_00441FB8(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0) != 0) {
            *(s32 *)(q + 0x134) = func_0037E208(0x28, 0x78);
        }
        ang = 1.5707964f;
        if (func_00389468(*(f32 *)(a0 + 0xF8), ang) > 0.08726646f) {
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, 15);
            }
            func_L01_00457708(a0, ang);
        } else {
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 15);
            }
            func_L01_004576E8(a0);
        }
        if (func_00388398(q + 0x134) != 0) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0) != 0) {
            func_L03_00446540(a0, *(s32 *)(q + 0x130), -1, 0);
        }
        if (func_L01_00458AE0(a0, *(s32 *)(q + 0x130)) == 0 && !(D_00142C10[0] & 0x10000)) {
            func_L01_00458A08(a0, func_00388A28(*(f32 *)(q + 0xD0), *(f32 *)(q + 0xD4)));
        } else {
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
    if (D_001D5470[1] != 0) {
        *(f32 *)(q + 0x1E0) = 2.75f;
    }
    func_L01_0044B5C8(a0, q + 0x170, 6, 0.03f, 0.3f);
}
/* localdecomp:end func_L03_003CE9F8 */
