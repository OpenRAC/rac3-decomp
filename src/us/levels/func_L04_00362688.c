#include "common.h"

/* NTSC-U counterpart of func_L04_003636F0 (src/levels/shared/L04_00362CE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern u8 *D_L04_001DFACC;
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 *D_L04_001DFACC;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern u8 *D_L04_001DFACC;
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern u8 *D_L04_001DFACC;

/* localdecomp:start func_L04_00362688 */
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L04_00360D18(u8 *, u8 *);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00451078(void *, void *);
extern void func_L04_00361560(u8 *);
extern void func_L01_003154D8(void *, s32, void *);
extern void func_L01_003559E0_00362688(void *);
extern u8 *D_L04_001DFACC;

s32 func_L04_00362688(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    s32 hit;
    if (*(f32 *)(pv + 0x30) <= 0.0f) {
        *(f32 *)(pv + 0x194) = *(f32 *)(pv + 0x190) = 1.25f;
    }
    *(f32 *)(pv + 0x80) = 0.785398185f;
    hit = func_L01_00451078(a0, pv + 0x160);
    *(f32 *)(pv + 0x80) = 1.48352981f;
    if ((hit & 1) || (a0[0x42] == 0x15 && func_L01_0044AF40(a0, 23.0f) != 0)
        || (*(f32 *)(pv + 0x30) <= 0.0f && *(u16 *)(a0 + 0x96) > 120)) {
        func_L04_00361560(a0);
        func_L01_003154D8(a0, 0, func_L01_003559E0_00362688);
        return 5;
    }
    if (hit & 2) {
        if (*(s16 *)(pv + 0x234) == 1) {
            if (*(s32 *)(pv + 0x304) != -1) {
                func_L01_00441FB8(a0, 0xA, 3);
            } else if (*(s32 *)(pv + 0x308) != 0 && pv[0x5F] == 0) {
                if (0.5f < func_00388800(a0 + 0x10, pv + 0x320)) {
                    func_L01_00441FB8(a0, 0xA, 3);
                } else if (func_L04_00360D18(a0, pv) != 0) {
                    func_L01_00441FB8(a0, 0x12, 3);
                } else {
                    func_L01_00441FB8(a0, 0xD, 3);
                }
            } else if (*(s32 *)(pv + 0x38C) != -1
                && (row = D_L04_001DFACC + *(s32 *)(pv + 0x38C) * 0x30, *(s16 *)(row + 0x32) != 0)) {
                func_L01_00441FB8(a0, 0xA, 3);
            } else {
                func_L01_00441FB8(a0, 0xB, 3);
            }
        } else {
            func_L01_00441FB8(a0, 6, 2);
            *(s32 *)(pv + 0x2F0) = func_0037E208(0x244, 0x258);
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 0);
            }
            if (*(long *)(pv + 0x310) != -1) {
                func_L01_00441FB8(a0, 5, 6);
            }
            if (*(s32 *)(pv + 0x300) != -1) {
                func_L01_00441FB8(a0, 2, -1);
            } else if (*(s32 *)(pv + 0x318) == 0) {
                func_L01_00441FB8(a0, 4, -1);
            } else if (*(s32 *)(pv + 0x4E4) != 0) {
                func_L01_00441FB8(a0, 3, -1);
            }
        }
        pv[0x61] = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00362688 */
