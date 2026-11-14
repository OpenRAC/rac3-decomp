#include "common.h"

/* NTSC-U counterpart of func_L04_00363F80 (src/levels/shared/L04_00362CE0.c): 0.0064 -> 0.00444444; 0.12 -> 0.1; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944; 8 -> 10 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern u8 *D_L04_001DFACC;
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern u8 *D_L04_001DFACC;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern u8 *D_L04_001DFACC;
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern u8 *D_L04_001DFACC;
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern f32 func_00388800(void *, void *);
extern u8 *D_L04_001DFACC;
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458AE0(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 *D_L04_0021E2C0[];
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern f32 func_00388800(void *, void *);

/* localdecomp:start func_L04_00362ED8 */
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L04_00469998(u8 *, s32 *);
extern s32 func_L01_00458AE0(void *, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern void func_003BF360(void *, void *);
extern s32 *D_L04_0021E2C0[];
extern u8 *D_L04_001DFACC;
extern s32 D_001D545C;

s32 func_L04_00362ED8(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    u8 *nav;
    if (func_L01_00452EC8(a0) != 0) {
        func_L01_00458A70(a0, 0.00444444455f, 0.100000009f, 0.00698131742f, 0.209439531f);
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, 10);
        }
    }
    if (*(s32 *)(pv + 0x4E4) != 0) {
        if (func_L04_00469998(a0, D_L04_0021E2C0[*(s32 *)(pv + 0x30C)]) == 0
            && (!(func_00388800(a0 + 0x10, pv + 0x220) < 6.0f) || *(s32 *)(pv + 0x4A4) != 0)) {
            return 0;
        }
        if (*(s32 *)(pv + 0x508) != 0) {
            *(u16 *)(a0 + 0x34) &= ~0x100;
            func_003BF360(a0 + 0xC0, a0 + 0xF0);
            *(s32 *)(pv + 0x4E4) = 0;
        }
        *(s32 *)(pv + 0x30C) = -1;
        if (*(s32 *)(pv + 0x304) != -1) {
            func_L01_00441FB8(a0, 0xA, -1);
        } else if (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFACC + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_00441FB8(a0, 0xA, -1);
        } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
            if (0.5f < func_00388800(a0 + 0x10, pv + 0x320)) {
                func_L01_00441FB8(a0, 0xA, -1);
            } else if (func_L04_00360D18(a0, pv) != 0) {
                func_L01_00441FB8(a0, 0x12, -1);
            } else {
                func_L01_00441FB8(a0, 0xD, -1);
            }
        } else {
            func_L01_00441FB8(a0, 0xB, -1);
        }
        if (D_001D545C == 0x10 && *(s32 *)(pv + 0x4E4) != 0) {
            func_L01_00441FB8(a0, 0xD, -1);
        }
        return 1;
    }
    if (func_L01_00458AE0(a0, *(s32 *)(pv + 0x30C)) == 0
        && (!(func_00388800(a0 + 0x10, pv + 0x220) < 6.0f) || *(s32 *)(pv + 0x4A4) != 0)) {
        return 0;
    }
    if (*(s32 *)(pv + 0x508) != 0) {
        *(s32 *)(pv + 0x4E4) = 0;
    }
    *(s32 *)(pv + 0x30C) = -1;
    if (*(s32 *)(pv + 0x304) != -1) {
        func_L01_00441FB8(a0, 0xA, -1);
    } else if (*(s32 *)(pv + 0x38C) != -1 && (nav = D_L04_001DFACC + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(nav + 0x32) != 0)) {
        func_L01_00441FB8(a0, 0xA, -1);
    } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
        if (0.5f < func_00388800(a0 + 0x10, pv + 0x320)) {
            func_L01_00441FB8(a0, 0xA, -1);
        } else if (func_L04_00360D18(a0, pv) != 0) {
            func_L01_00441FB8(a0, 0x12, -1);
        } else {
            func_L01_00441FB8(a0, 0xD, -1);
        }
    } else {
        func_L01_00441FB8(a0, 0xB, -1);
    }
    return 1;
}
/* localdecomp:end func_L04_00362ED8 */
