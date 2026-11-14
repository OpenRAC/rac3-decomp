#include "common.h"

/* NTSC-U counterpart of func_L03_003AF450 (src/levels/03_starship_phoenix/L03_003AF410.c) */
extern u8 D_00142CBE[];
__asm__(".extern D_00142CBE, 16");
extern u8 D_00142700[];
__asm__(".extern D_00142700, 16");
extern s32 func_L01_004B6C68();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);
extern s32 func_00388398(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0037E208(s32, s32);
extern void func_L03_003AE398(void *);
extern void func_L03_003AE8E0(void *);
extern void func_L03_003ADEE8(void *);
extern void func_L03_003ADE90(void *);
extern s32 func_L03_003ADAD8(void *);

/* localdecomp:start func_L03_003ADB18 */
void func_L03_003ADB18(u8 *a) {
    u8 *s = *(u8 **)(a + 0x68);
    s32 t;

    if (func_L01_004B6C68() != 0) {
        a[0x31] = 0;
        *(u16 *)(a + 0x34) |= 1;
        return;
    }
    if (D_00142700[0] == 0) {
        a[0x31] = 1;
        *(u16 *)(a + 0x34) &= 0xFFFE;
    }
    switch (a[0x20]) {
    case 0:
        if (D_00142CBE[0] != 0) {
            if (a[0x43] != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            func_L01_00441FB8(a, 1, -1);
        } else {
            func_003BD360(a);
            return;
        }
        func_L03_003AE398(a);
        break;
    case 1:
        if (func_L01_00452EC8(a) != 0) {
            *(s32 *)(s + 0x140) = 0;
            if (a[0x43] != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            *(s32 *)(s + 0x30C) = func_0037E208(0x226, 0x352);
        }
        if (func_00388398(s + 0x30C) != 0) {
            *(s32 *)(s + 0x30C) = func_0037E208(0x226, 0x352);
            if (a[0x43] != 1) {
                func_003BE4F0(a, 1, 0, 20);
            }
        }
        if ((a[0x60] & 2) != 0 && a[0x43] != 0) {
            func_003BE4F0(a, 0, 0, 20);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a) != 0) {
            *(s32 *)(s + 0x140) = 0;
            if (a[0x43] != 2) {
                func_003BE4F0(a, 2, 0, 10);
            }
        } else if ((a[0x60] & 2) != 0) {
            *(s32 *)(s + 0x140) = 1;
            func_L01_00441FB8(a, *(s32 *)(s + 0x13C), -1);
            t = a[0x43];
            if (t != func_L03_003ADAD8(a)) {
                func_003BE4F0(a, func_L03_003ADAD8(a), 0, 10);
            }
        }
        break;
    case 6:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 3) {
                func_003BE4F0(a, 3, 0, 10);
            }
        }
        break;
    case 4:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 4) {
                func_003BE4F0(a, 4, 0, 10);
            }
        }
        if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 7) {
                func_003BE4F0(a, 7, 0, 10);
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 5) {
                func_003BE4F0(a, 5, 0, 10);
            }
        }
        if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 7) {
                func_003BE4F0(a, 7, 0, 10);
            }
        }
        break;
    case 7:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 7) {
                func_003BE4F0(a, 7, 0, 10);
            }
        }
        break;
    case 8:
        if (func_L01_00452EC8(a) != 0) {
            if (a[0x43] != 8) {
                func_003BE4F0(a, 8, 0, 10);
            }
            *(s32 *)(s + 0x140) = 0;
        } else if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 0) {
                func_003BE4F0(a, 0, 0, 10);
            }
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 2:
    default:
        break;
    }
    func_L03_003AE8E0(a);
    func_L03_003ADEE8(a);
    func_L03_003ADE90(a);
}
/* localdecomp:end func_L03_003ADB18 */
