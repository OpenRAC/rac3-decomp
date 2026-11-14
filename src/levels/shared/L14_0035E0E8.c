#include "common.h"

/* localdecomp:start func_L14_0035E0E8 */
extern u16 *D_L14_0021CCE0[];
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern s32 D_L14_001DF758;

void func_L14_0035E0E8(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L14_0021CCE0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L14_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L14_0021CCE0[a0[0x21]])) {
        e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            u8 *q = *(u8 **)(e + 0x68);
            if (*(s32 *)(q + 0x328) != 0) {
                *(u8 **)(q + 0x32C) = a0;
                *(s32 *)(q + 0x328) = 0;
                *(u16 *)(e + 0x34) &= 0xFFFD;
                return;
            }
        }
    }
}
/* localdecomp:end func_L14_0035E0E8 */

INCLUDE_ASM("asm/levels", func_L14_0035E1C0);

/* localdecomp:start func_L14_0035F2F8 */
extern s32 func_L14_0035F538(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L02_003516A8(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 D_001D545C;
extern s32 D_001D67C4;

s32 func_L14_0035F2F8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0 && func_L14_0035F538(a0) != 0) {
        return 1;
    }
    if (v[0x3E] == 2) {
        goto die;
    }
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 0) != 0) {
        func_L01_003A6BB0(a0);
    }
    if (v[0x5E] != 0) {
die:
        func_L02_003516A8(a0);
        return 1;
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5F] != 0) {
        if (D_001D545C == 0x16 && *(s32 *)(v + 0x330) == 0) {
            s32 n = D_001D67C4;
            *(s32 *)(v + 0x330) = 1;
            n++;
            D_001D67C4 = n;
            if (n >= 15) {
                func_L01_00459C50(0x17);
            }
        }
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else if (*(s32 *)(v + 0x324) != 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 4, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L14_0035F2F8 */

INCLUDE_ASM("asm/levels", func_L14_0035F538);
