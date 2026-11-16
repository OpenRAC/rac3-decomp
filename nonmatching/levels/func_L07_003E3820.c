/* NTSC-U draft (Claude wave C3): C of func_L07_003E1A30, the NTSC-U twin of func_L07_003E3820, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 3 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_003E1A30", whose code is not the PAL one).
 * Worker's note: about 100 words differ (control flow and calls are right, 163 vs 166 words): look-at turn update (p->0 entity index -> target pos t, func_L01_004B6C68 flag, dist < p->4^2 via func_L01_0040C040(t, hero+0x80), angle func_003893C8(func_00388A28(...), p->10) ...
 */
#include "common.h"

/* localdecomp:start func_L07_003E1A30 */
extern u8 *D_001DF500_sda;
__asm__(".extern D_001DF500_sda, 4");
extern u8 D_001A4BE0[];
extern u8 D_L07_003E1D40[];
extern void func_L07_003E1CC0(void *);
extern s32 func_L01_004B6C68(void);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern s32 func_003883C8(void *);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_00389410(f32);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_00388960(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00402498(void *, void *);

void func_L07_003E1A30(u8 *a0) {
    u8 *p;
    u8 *t;
    f32 f2;
    f32 hi;
    f32 lo;
    f32 x;

    if (a0[0x20] == 0) {
        func_L07_003E1CC0(a0);
    }
    p = *(u8 **)(a0 + 0x68);
    if (*(s32 *)p == -1) {
        t = a0 + 0x10;
    } else {
        t = D_001DF500_sda + (*(s32 *)p << 7) + 0x30;
    }
    if (func_L01_004B6C68() != 0) {
        f2 = 0.0f;
        x = *(f32 *)(p + 0x10);
    } else {
        if (func_L01_0040C040(t, D_001A4BE0 + 0x80) < *(f32 *)(p + 4) * *(f32 *)(p + 4)) {
            f2 = func_003893C8(func_00388A28(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(a0 + 0x10), *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(a0 + 0x14)), *(f32 *)(p + 0x10));
            hi = *(f32 *)(p + 8) * 0.017453292f;
            lo = -(*(f32 *)(p + 0xC) * 0.017453292f);
            if (hi < f2) {
                f2 = hi;
            } else if (f2 < lo) {
                f2 = lo;
            }
            *(f32 *)(p + 0x20) = *(f32 *)(p + 0x20) + 0.03f;
            if (*(f32 *)(p + 0x20) >= 2.0f) {
                *(f32 *)(p + 0x20) = *(f32 *)(p + 0x20) - 2.0f;
            }
        } else {
            if (func_003883C8(p + 0x1C) != 0) {
                *(f32 *)(p + 0x18) = func_0037E250(-*(f32 *)(p + 0xC), *(f32 *)(p + 8)) * 0.017453292f * 0.75f;
                *(s16 *)(p + 0x1C) = func_0037E1D8(0x3C) + 0x78;
            }
            *(f32 *)(p + 0x20) = *(f32 *)(p + 0x20) * 0.99f;
            f2 = *(f32 *)(p + 0x18);
        }
        x = *(f32 *)(p + 0x10);
    }
    func_L01_00445758(a0 + 0xF8, p + 0x14, 0, func_00389410(x + f2 + 3.1415927f), 0.00021816617f, 0.00021816617f, 0.013089971f);
    x = *(f32 *)(p + 0x20);
    if (x > 1.0f) {
        x = 2.0f - x;
    }
    *(s32 *)(a0 + 0x78) = func_003894A0(0x202020, 0xFF0000FF, (1.0f - func_00388960(x)) * 0.5f);
    if (a0[0x31] != 0) {
        func_L01_00402498(D_L07_003E1D40, a0);
    }
}
/* localdecomp:end func_L07_003E1A30 */
