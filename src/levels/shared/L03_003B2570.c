#include "common.h"

/* localdecomp:start func_L03_003B2570 */
typedef struct {
    u8 p0[0x128];
    s32 f128;
} S_003B2570;

extern s32 D_L03_001D6694;
extern u8 D_00142CBE[];
__asm__(".extern D_00142CBE, 16");
extern u8 D_00142CC2[];
__asm__(".extern D_00142CC2, 16");
extern s32 func_L01_004BA800();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern void func_L03_003B27D0_003B2570(void *);

void func_L03_003B2570(u8 *a) {
    S_003B2570 *s = *(S_003B2570 **)(a + 0x68);

    switch (a[0x20]) {
    case 0:
        if (D_00142CBE[0] != 0) {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 3, -1);
        } else {
            func_003C2880(a);
            return;
        }
    case 3:
        if (func_L01_004561B8(a) != 0) {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            s->f128 = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
        }
        if (func_0038CAD0(&s->f128) != 0) {
            s->f128 = (func_00382498(0x226, 0x352) * 5 + 2) / 6;
            if (a[0x43] != 1) {
                func_003C3A10(a, 1, 0, 0x11);
            }
        } else if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 0x11);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(a) != 0) {
            if (a[0x43] != 2) {
                func_003C3A10(a, 2, 0, 8);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(a) != 0) {
            if (a[0x43] != 3) {
                func_003C3A10(a, 3, 0, 8);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(a) != 0) {
            if (a[0x43] != 4) {
                func_003C3A10(a, 4, 0, 8);
            }
        }
        break;
    }
    if (D_L03_001D6694 == 2) {
        a[0x31] = 0;
        *(u16 *)(a + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0 && D_00142CC2[0] == 0) {
        a[0x31] = 1;
        *(u16 *)(a + 0x34) &= 0xFFFE;
    }
    func_L03_003B27D0_003B2570(a);
}
/* localdecomp:end func_L03_003B2570 */
