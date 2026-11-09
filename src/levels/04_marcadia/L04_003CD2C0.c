#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003CD2C0);

/* localdecomp:start func_L04_003CE120 */
extern s32 func_L04_003CE348(u8 *a0);
extern s32 func_L04_003CE7C8(u8 *a0, u8 *a1, s32 a2);
extern void func_L02_0034FD58(void *a0);
extern void func_L02_003516A8(void *a0);
extern void func_L01_0044FD88(void *a0, void *a1, s32 a2, s32 a3);
extern f32 func_L01_0040E548(void *a0, void *a1);
extern void func_L01_004472C0(void *a0);
extern s32 func_00382380(void *a0, s32 a1, s32 a2);
extern void func_L01_00456BD0(void *a0, s32 a1);
extern void func_L01_00456C98(void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, f32 f1, f32 f2, f32 f3);
extern u8 D_L04_001E2840[];
__asm__(".extern D_L04_001E2840, 16");
extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");

s32 func_L04_003CE120(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *w;
    f32 f;

    if (a0[0x20] == 0) {
        if (func_L04_003CE348(a0) != 0) {
            return 1;
        }
    }
    if (func_L04_003CE7C8(a0, s + 0x160, 0) != 0) {
        func_L02_0034FD58(a0);
    }
    if (s[0x5E] != 0) {
        func_L02_003516A8(a0);
        return 1;
    }
    if (*(u8 **)(s + 0x300) != 0) {
        w = *(u8 **)(s + 0x300);
        *(long *)(w + 0x38) = *(long *)(a0 + 0x38);
        func_L01_0044FD88(a0, *(u8 **)(s + 0x300), 0, 0);
        w = *(u8 **)(s + 0x300);
        if (w[0x31] != 0) {
            f = func_L01_0040E548(D_L04_001E2840, w + 0x10);
            if (f < 576.0f) {
                func_L01_004472C0(*(u8 **)(s + 0x300));
                (*(u8 **)(s + 0x300))[0x6F] = 0x16;
            }
        }
    }
    if (a0[0x31] != 0) {
        f = func_L01_0040E548(D_L04_001E2840, a0 + 0x10);
        if (f < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    *(s16 *)(s + 0x30C) = (*(s32 *)(s + 0x304) != -1) && (func_00382380(D_001A4C60, *(s32 *)(s + 0x304), 0) != 0);
    *(s16 *)(s + 0x30E) = (*(s32 *)(s + 0x308) != -1) && (func_00382380(D_001A4C60, *(s32 *)(s + 0x308), 0) != 0);
    func_L01_00456BD0(a0, 1);
    if (a0[0x20] == 0) {
        func_L01_00456C98(a0, *(s32 *)(s + 0x2E8), 0, 0, 1, 1, 3, 0, 0, 0, *(f32 *)(s + 0x2EC), 10.0f, 1.0f);
    } else {
        func_L01_00456C98(a0, *(s32 *)(s + 0x2E0), 0, 0, 1, 1, 3, 0, 0, 0, *(f32 *)(s + 0x2E4), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L04_003CE120 */

INCLUDE_ASM("asm/levels", func_L04_003CE348);

/* localdecomp:start func_L04_003CE5A8 */
extern void func_003C2880(u8 *a0);
extern void (**func_L01_0043B548(s32 a0, s32 a1))(u8 *);

void func_L04_003CE5A8(u8 *arg0, s32 arg1) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    void (**t)(u8 *);

    if (*(u32 *)(s2 + 0x300) != 0) {
        func_003C2880(*(u8 **)(s2 + 0x300));
        *(u32 *)(s2 + 0x300) = 0;
    }
    if (*(u32 *)(s2 + 0x240) != 0) {
        t = func_L01_0043B548(6625, 108);
        (*t)(arg0);
        if (arg1 != 0) {
            t[1](arg0);
        }
    } else {
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L04_003CE5A8 */
