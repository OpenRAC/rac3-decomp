#include "common.h"

/* localdecomp:start func_L03_003B19E0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001426EB[];
extern u8 D_00142CBE[];
extern f32 D_L03_001DE940;
__asm__(".extern D_L03_001DE940, 4");
extern u8 D_L03_001DE950[8];
__asm__(".extern D_L03_001DE950, 8");
extern s32 D_001D6694;
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004BA800(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L03_003B1D38(u8 *a0);

void func_L03_003B19E0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    switch (m[0x20]) {
    case 0:
        if (D_001426EB[0] != 0 && D_00142CBE[0] == 0) {
            *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * D_L03_001DE940;
            *(u128_t *)(m + 0x10) = *(u128_t *)D_L03_001DE950;
            *(f32 *)(m + 0xF8) = 2.5132742f;
            if (m[0x43] != 6) {
                func_003C3A10(m, 6, 0, 8);
            }
            func_L01_004450F0(m, 6, -1);
        } else {
            *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * D_L03_001DE940;
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
            *(s32 *)(v + 0x298) = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
        }
        if (func_0038CAD0(v + 0x298) != 0) {
            *(s32 *)(v + 0x298) = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
            if (m[0x43] != 2) {
                func_003C3A10(m, 2, 0, 0x11);
            }
        } else if ((m[0x60] & 2) != 0) {
            if (m[0x43] != 1) {
                func_003C3A10(m, 1, 0, 0x11);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 3) {
                func_003C3A10(m, 3, 0, 8);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 4) {
                func_003C3A10(m, 4, 0, 8);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            if (m[0x43] != 5) {
                func_003C3A10(m, 5, 0, 8);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(v + 0x298) = func_00382498(0xA7, 0x14D);
        }
        if (func_0038CAD0(v + 0x298) != 0) {
            if (m[0x43] != 7) {
                func_003C3A10(m, 7, 0, 8);
            }
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7:
        if ((m[0x60] & 2) != 0) {
            if (m[0x43] != 6) {
                func_003C3A10(m, 6, 0, 8);
            }
            func_L01_004450F0(m, 6, -1);
        }
        break;
    }
    if (D_001D6694 == 2) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
    } else {
        if (func_L01_004BA800() == 0) {
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= ~1;
        }
        if ((u8)(m[0x20] - 6) >= 2) {
            func_L03_003B1D38(m);
        }
    }
}
/* localdecomp:end func_L03_003B19E0 */
