#include "common.h"

/* localdecomp:start func_L11_0033C080 */
extern s32 D_L11_001DCFD0;
extern s32 D_L11_001DCFD4;
extern u8 *func_L01_00444358(u8 *, s32, s32);
extern void func_L01_00442AA8(s32, s32);
extern void func_L03_0042FC00(s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_003BE418(u8 *, s32, s32);
extern s32 func_00388398(void *);

/* Steps a moby with three states: it notifies an alert group when a target of class 0xD0 or 0x825
 * is found, cuts or blends its animations as they end, and toggles flag 0xBC and a timer swapping a
 * value at +0x78. */
void func_L11_0033C080(u8 *a0)
{
    u8 *s1;
    u8 *p;

    s1 = *(u8 **)(a0 + 0x68);
    p = func_L01_00444358(a0, 0x10000, 0);
    if (p != 0 && *(u8 **)(p + 0x20) != 0) {
        s32 h = *(s16 *)(*(u8 **)(p + 0x20) + 0xAA);
        if (h == 0xD0 || h == 0x825) {
            if (a0[0x21] != 0xFF) {
                if (*(s32 *)(s1 + 0x88) == 0) {
                    func_L01_00442AA8(a0[0x21], 2);
                } else {
                    func_L01_00442AA8(a0[0x21], 2);
                    func_L03_0042FC00(a0[0x21], 1);
                }
            }
        }
    }
    a0[0xA8] = 0xFF;

    switch (a0[0x20]) {
    case 0:
        *(f32 *)(s1 + 0x78) = *(f32 *)(a0 + 0xF0);
        a0[0x20] = 1;
        if (a0[0x43] != 0)
            func_003BE4F0(a0, 0, 0, 0xC);
        *(s32 *)(s1 + 0x40) = 0;
        *(u16 *)(a0 + 0x34) |= 0x1000;
        break;
    case 1:
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x43] != 0)
                func_003BE418(a0, 0, 0);
        }
        if (a0[0xBC] == 0)
            break;
        *(u16 *)(a0 + 0x34) &= 0xEFFF;
        func_003BE418(a0, 1, 0);
        if (*(s32 *)(s1 + 0x70) != 0) {
            *(s32 *)(s1 + 0x74) = 10;
            a0[0x20] = 2;
            *(s32 *)(s1 + 0x84) = *(s32 *)(s1 + 0x80);
        } else {
            *(s32 *)(a0 + 0x78) = D_L11_001DCFD4;
            a0[0x20] = 2;
        }
        break;
    case 2:
        if (*(s32 *)(s1 + 0x70) != 0) {
            if (func_00388398(s1 + 0x74) != 0) {
                if (*(s32 *)(a0 + 0x78) == D_L11_001DCFD0)
                    *(s32 *)(a0 + 0x78) = D_L11_001DCFD4;
                else
                    *(s32 *)(a0 + 0x78) = D_L11_001DCFD0;
                *(s32 *)(s1 + 0x74) = 10;
            }
            if (func_00388398(s1 + 0x84) != 0)
                a0[0xBC] = 0;
        }
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x43] == 1)
                func_003BE418(a0, 2, 0);
        }
        if (a0[0xBC] != 0)
            break;
        if ((a0[0x60] & 2) != 0) {
            *(u16 *)(a0 + 0x34) |= 0x1000;
            func_003BE418(a0, 3, 0);
            *(s32 *)(a0 + 0x78) = D_L11_001DCFD0;
            a0[0x20] = 1;
            if (*(s32 *)(s1 + 0x88) != 0) {
                if (a0[0x21] != 0xFF)
                    func_L03_0042FC00(a0[0x21], 0);
            }
        }
        break;
    }
}
/* localdecomp:end func_L11_0033C080 */
