#include "common.h"

/* localdecomp:start func_L03_003B11C8 */
typedef struct {
    u8 p0[0x11C];
    s32 f11C;
    u8 p120[8];
    s32 f128;
} S_L03_003B11C8;

extern s32 D_L03_001D6694;
__asm__(".extern D_L03_001D6694, 16");
extern s32 D_00142C40[];
__asm__(".extern D_00142C40, 16");
extern u8 D_00142CBE[];
__asm__(".extern D_00142CBE, 16");
extern s32 func_L01_004BA800();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern void func_L03_003B1520(void *);
extern void func_L03_003B18E0(void *);

void func_L03_003B11C8(u8 *a) {
    S_L03_003B11C8 *s = *(S_L03_003B11C8 **)(a + 0x68);
    s32 v;
    unsigned long t;

    if (D_L03_001D6694 == 2) {
        a[0x31] = 0;
        *(u16 *)(a + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        t = D_00142C40[0];
        if (((t >> 1) & 1) == 0) {
            a[0x31] = 1;
            *(u16 *)(a + 0x34) &= 0xFFFE;
        }
    }
    switch (a[0x20]) {
    case 0:
        if (D_00142CBE[0] != 0) {
            *(f32 *)(a + 0x2C) = *(f32 *)(*(u8 **)(a + 0x24) + 0x24) * 1.25f;
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 1, -1);
        } else {
            func_003C2880(a);
            return;
        }
    case 1:
        if (func_0038CAD0(&s->f11C) != 0) {
            s->f11C = (func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f;
            v = func_00382468(3) == 0;
            if (a[0x43] != v) {
                func_003C3A10(a, v, 0, 8);
            }
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 2:
        if ((a[0x60] & 2) != 0) {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a) != 0) {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            s->f128 = (func_00382498(600, 800) * 5 + 2) / 6;
        }
        if (func_0038CAD0(&s->f128) != 0) {
            s->f128 = (func_00382498(600, 800) * 5 + 2) / 6;
            if (a[0x43] != 1) {
                func_003C3A10(a, 1, 0, 0x11);
            }
        }
        if ((a[0x60] & 2) != 0) {
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
    func_L03_003B1520(a);
    func_L03_003B18E0(a);
}
/* localdecomp:end func_L03_003B11C8 */

INCLUDE_ASM("asm/levels", func_L03_003B1520);
