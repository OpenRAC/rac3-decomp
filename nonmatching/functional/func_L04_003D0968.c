/* functional: medium. State machine on obj[0x20] (0..3); gp-relative colour constants named D_L04_001DEAxx (gp+0x2230..0x2250), semantics of each guessed from use as blend colours/periods. 180 diffs, same calls in order. */
#include "common.h"
extern s32 func_L04_003D0C40(u8 *, u8 *);
extern void func_L04_003D1420(u8 *);
extern s32 func_L01_004561B8();
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *func_L01_0043B548(s32, s32);
extern void func_L03_003B1DD0(void *);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00404A10(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 D_L04_001DF940;
extern s32 D_L04_001DEAE0;
__asm__(".extern D_L04_001DEAE0, 4");
extern s32 D_L04_001DEAE4;
__asm__(".extern D_L04_001DEAE4, 4");
extern s32 D_L04_001DEAE8;
__asm__(".extern D_L04_001DEAE8, 4");
extern s32 D_L04_001DEAEC;
__asm__(".extern D_L04_001DEAEC, 4");
extern s32 D_L04_001DEAF0;
__asm__(".extern D_L04_001DEAF0, 4");
extern s32 D_L04_001DEAF4;
__asm__(".extern D_L04_001DEAF4, 4");
extern s32 D_L04_001DEAF8;
__asm__(".extern D_L04_001DEAF8, 4");
extern s32 D_L04_001DEAFC;
__asm__(".extern D_L04_001DEAFC, 4");
extern s32 D_L04_001DEB00;
__asm__(".extern D_L04_001DEB00, 4");

void func_L04_003D0968(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *child;
    u8 *cv;
    u8 *obj;
    s32 st;

    if (a0[0x20] == 0) {
        if (func_L04_003D0C40(a0, pv) == 0) return;
    }
    st = a0[0x20];
    if (st == 1) {
        if (func_L01_004561B8(a0) == 0) return;
        *(s32 *)(a0 + 0x78) = D_L04_001DEAE0;
        if (*(s32 *)(pv + 0x90) != -1) return;
        func_L01_004450F0(a0, 3, -1);
    } else if (st == 2) {
        if (func_L01_004561B8(a0) != 0) {
            if (*(s32 *)(pv + 0x90) == -2) {
                func_L01_004450F0(a0, 3, -1);
            }
            child = *(u8 **)(pv + 0x9C);
            if (child != 0) child[0x20] = 7;
        }
        if (D_L04_001DF940 % D_L04_001DEAEC != 0) return;
        child = *(u8 **)(pv + 0x9C);
        if (child == 0) return;
        *(s32 *)(a0 + 0x78) = func_0038DBD8(D_L04_001DEAE4, D_L04_001DEAE8, func_003824E0(0.0f, 1.0f));
        cv = *(u8 **)(child + 0x68);
        if (0.0f < *(f32 *)(cv + 0x40)) {
            s32 col = func_0038DBD8(D_L04_001DEAF0, D_L04_001DEAF4, func_003824E0(0.0f, 1.0f));
            *(s32 *)(a0 + 0x78) = func_0038DBD8(*(s32 *)(a0 + 0x78), col, *(f32 *)(cv + 0x40));
            if (*(f32 *)(cv + 0x40) == 1.0f) {
                func_L01_004450F0(a0, 3, -1);
            }
        }
    } else if (st == 3) {
        if (func_L01_004561B8(a0) != 0) {
            if (*(s32 *)(pv + 0x70) != 0) {
                u8 *c = func_L01_0043B548(0x19E1, 0x6C);
                (*(void (**)(u8 *, s32))(c + 8))(a0, 1);
            } else {
                func_L01_00456230(a0, 1);
            }
            if (*(s32 *)(pv + 0xA0) != 0) {
                func_L03_003B1DD0(*(u8 **)(pv + 0xA0));
            }
            obj = *(u8 **)(pv + 0x94);
            if (obj != 0) {
                if (*(s32 *)(obj + 0x90) == -2) {
                    func_L01_004450F0(obj, 3, -1);
                } else {
                    func_L01_004450F0(obj, 2, -1);
                }
            }
        }
        if (func_L01_004AA710(a0, *(s32 *)(pv + 0xA4)) == 0) {
            *(s32 *)(pv + 0xA4) = func_003A52A0(0, 4, a0);
        }
        if (D_L04_001DF940 % D_L04_001DEB00 == 0) {
            *(s32 *)(a0 + 0x78) = func_0038DBD8(D_L04_001DEAF8, D_L04_001DEAFC, func_003824E0(0.0f, 1.0f));
        }
        if (*(s32 *)(pv + 0x94) != 0) {
            func_L01_00404A10(func_L04_003D1420, a0);
        }
    }
}
