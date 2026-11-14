#include "common.h"

/* NTSC-U counterpart of func_L04_00363520 (src/levels/shared/L04_00362CE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EF0(void *);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern u8 *D_L04_001DFACC;
extern s32 func_L01_00452EF0(void *);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_001D545C;
extern u8 *D_L04_001DFACC;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern u8 *D_L04_001DFACC;

/* localdecomp:start func_L04_003624D0 */
extern s32 func_L01_00452EF0(void *);
extern void func_L01_00442AA8(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 D_001D545C;
extern u8 *D_L04_001DFACC;

s32 func_L04_003624D0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    u8 *row;
    if (*(s16 *)(pv + 0x234) != 1 && func_L01_00452EF0(a0) == 0) {
        if (a0[0x21] != 0xFF) {
            func_L01_00442AA8(a0[0x21], 0);
        }
        if (*(s32 *)(pv + 0x30C) == -1) {
            if (a0[0x43] != 2) {
                func_003BE4F0(a0, 2, 0, 10);
            }
            func_L01_00441FB8(a0, 4, 2);
            if (*(s32 *)(pv + 0x318) != 0) {
                func_L01_00441FB8(a0, 7, -1);
            }
            if (*(s32 *)(pv + 0x4E4) != 0) {
                if (a0[0x43] != 1) {
                    func_003BE4F0(a0, 1, 0, 10);
                }
                func_L01_00441FB8(a0, 4, 2);
            }
        } else {
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 10);
            }
            func_L01_00441FB8(a0, 6, 2);
        }
        *(s32 *)(pv + 0x2F0) = func_0037E208(0x244, 0x258);
        return 1;
    }
    if (D_001D545C == 0x1D && *(s32 *)(pv + 0x4D8) != 0 && *(s32 *)(pv + 0x4D4) != -1
        && (row = D_L04_001DFACC + *(s32 *)(pv + 0x4D4) * 0x30, *(s16 *)(row + 0x32) != 0)) {
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, 10);
        }
        func_L01_00441FB8(a0, 10, 4);
    }
    return 0;
}
/* localdecomp:end func_L04_003624D0 */
