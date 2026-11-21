#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

/* declared by functions of L07_003CC2B0.c, which this file was cut from */
void func_L07_003CD2E8(void *, s32);

/* localdecomp:start func_L07_003CD2E8 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L07_003CE320(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003CD2E8(void *arg0, s32 state) {
    u8 *a0 = arg0;
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (state) {
    case 1:
    case 2:
    case 4:
        break;
    case 3:
        if (a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 0);
        }
        break;
    case 5:
    case 6:
        if (a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 4);
        }
        break;
    case 7:
        *(f32 *)(p + 0x170) = 0.00320000015f;
        *(f32 *)(p + 0x178) = 0.0500000045f;
        *(f32 *)(p + 0x174) = 0.00320000015f;
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 2);
        }
        break;
    case 8:
        *(f32 *)(p + 0x170) = 0.00800000038f;
        *(f32 *)(p + 0x178) = 0.100000009f;
        *(f32 *)(p + 0x174) = 0.00800000038f;
        if (a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, 2);
        }
        break;
    case 9:
        *(f32 *)(p + 0x170) = 0.00720000034f;
        *(f32 *)(p + 0x178) = 0.160000011f;
        *(f32 *)(p + 0x174) = 0.00720000034f;
        if (a0[0x43] != 4) {
            func_003C3A10(a0, 4, 0, 2);
        }
        break;
    case 10:
        if (a0[0x43] != 5) {
            func_003C3A10(a0, 5, 0, 2);
        }
        break;
    case 11:
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, 0, 7);
        }
        break;
    case 12:
        if (a0[0x43] != 0xA) {
            func_003C3A10(a0, 0xA, 0, 2);
        }
        break;
    case 13:
        if (a0[0x43] != 0xB) {
            func_003C3A10(a0, 0xB, 0, 2);
        }
        break;
    case 14:
        func_L07_003CE320(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xC) {
            func_003C3A10(a0, 0xC, 0, 2);
        }
        break;
    case 15:
        func_L07_003CE320(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xD) {
            func_003C3A10(a0, 0xD, 0, 2);
        }
        break;
    case 16:
        func_L07_003CE320(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xD) {
            func_003C3A10(a0, 0xD, 0, 2);
        }
        break;
    case 17:
        if (a0[0x43] != 0xE) {
            func_003C3A10(a0, 0xE, 0, 2);
        }
        break;
    case 18:
        if (a0[0x43] != 8) {
            func_003C3A10(a0, 8, 0, 2);
        }
        break;
    case 19:
        if (a0[0x43] != 7) {
            func_003C3A10(a0, 7, 0, 2);
        }
        break;
    case 20:
        if (a0[0x43] != 9) {
            func_003C3A10(a0, 9, 0, 2);
        }
        break;
    case 21:
        func_L07_003CE320(a0);
        p[0x407] = 1;
        if (a0[0x43] != 0xF) {
            func_003C3A10(a0, 0xF, 0, 2);
        }
        break;
    case 22:
        if (a0[0x43] != 0x10) {
            func_003C3A10(a0, 0x10, 0, 2);
        }
        break;
    case 23:
        if (a0[0x43] != 0x11) {
            func_003C3A10(a0, 0x11, 0, 2);
        }
        break;
    }
    func_L01_004450F0(a0, state, -1);
}
/* localdecomp:end func_L07_003CD2E8 */

INCLUDE_ASM("asm/levels", func_L07_003CD610);
