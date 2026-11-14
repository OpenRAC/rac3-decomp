#include "common.h"

/* NTSC-U counterpart of func_L04_00362F18 (src/levels/shared/L04_00362CE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L04_00361F10 */
extern s32 func_L01_00452EF0(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_003883C8(void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452F60(void *);
extern void func_0039FE80(s32, s32, void *);
extern u8 *D_L04_001DFACC;
extern u8 *D_L04_001DFE1C;

s32 func_L04_00361F10(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    u8 *nav;
    s32 ok;
    if (func_L01_00452EF0(a0) != 0 && *(s32 *)(pv + 0x374) == 0 && *(s16 *)(pv + 0x2F6) == 0) {
        *(s16 *)(pv + 0x2F6) = func_0037E208(0, 40);
    }
    ok = 1;
    if (*(s32 *)(pv + 0x4F4) != -1 && func_L01_00452F60(D_L04_001DFE1C + (*(s32 *)(pv + 0x4F4) << 8)) == 0) {
        ok = 0;
    }
    if (*(s16 *)(pv + 0x234) == 1 && ok != 0 && func_003883C8(pv + 0x2F6) != 0) {
        if (*(s32 *)(pv + 0x504) != 0) {
            func_0039FE80(2, 0, a0);
        }
        func_L01_00441FB8(a0, 0xB, 3);
        if (*(s32 *)(pv + 0x30C) != -1) {
            func_L01_00441FB8(a0, 9, -1);
        } else if (*(s32 *)(pv + 0x304) != -1) {
            func_L01_00441FB8(a0, 10, -1);
        } else if (*(s32 *)(pv + 0x38C) != -1 && (row = D_L04_001DFACC + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
            func_L01_00441FB8(a0, 10, -1);
        } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
            if (0.5f < func_00388800(a0 + 0x10, pv + 0x320)) {
                func_L01_00441FB8(a0, 10, -1);
            } else if (func_L04_00360D18(a0, pv) != 0) {
                func_L01_00441FB8(a0, 0x12, -1);
            } else {
                func_L01_00441FB8(a0, 0xD, -1);
            }
        }
        if (*(s32 *)(pv + 0x4E8) != 0) {
            func_L01_00441FB8(a0, 0xC, -1);
        }
        return 1;
    }
    if (*(s32 *)(pv + 0x4D8) != 0) {
        if (*(s32 *)(pv + 0x4D4) != -1 && (nav = D_L04_001DFACC + *(s32 *)(pv + 0x4D4) * 0x30, *(s16 *)(nav + 0x32) != 0)) {
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
            func_L01_00441FB8(a0, 10, 4);
        }
        return 0;
    }
    if (*(s32 *)(pv + 0x2F8) != 0 && func_003883C8(pv + 0x2F6) != 0) {
        func_L01_00441FB8(a0, 6, 2);
        *(s32 *)(pv + 0x2F8) = 0;
        if (*(s32 *)(pv + 0x2F0) < 0x12C) {
            *(s32 *)(pv + 0x2F0) = func_0037E208(0x1E0, 0x258);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00361F10 */
