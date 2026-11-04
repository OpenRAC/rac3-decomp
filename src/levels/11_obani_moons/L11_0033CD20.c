#include "common.h"

/* localdecomp:start func_L11_0033CD20 */
extern s32 D_L11_001DCFA0;
extern s32 D_L11_001DCFA4;
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern void func_L03_004330B8(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C3938(u8 *, s32, s32);
extern s32 func_0038CAD0(void *);

void func_L11_0033CD20(u8 *a0)
{
    u8 *s1;
    u8 *p;

    s1 = *(u8 **)(a0 + 0x68);
    p = func_L01_00447490(a0, 0x10000, 0);
    if (p != 0 && *(u8 **)(p + 0x20) != 0) {
        s32 h = *(s16 *)(*(u8 **)(p + 0x20) + 0xAA);
        if (h == 0xD0 || h == 0x825) {
            if (a0[0x21] != 0xFF) {
                if (*(s32 *)(s1 + 0x88) == 0) {
                    func_L01_00445BE0(a0[0x21], 2);
                } else {
                    func_L01_00445BE0(a0[0x21], 2);
                    func_L03_004330B8(a0[0x21], 1);
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
            func_003C3A10(a0, 0, 0, 0xA);
        *(s32 *)(s1 + 0x40) = 0;
        *(u16 *)(a0 + 0x34) |= 0x1000;
        break;
    case 1:
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x43] != 0)
                func_003C3938(a0, 0, 0);
        }
        if (a0[0xBC] == 0)
            break;
        *(u16 *)(a0 + 0x34) &= 0xEFFF;
        func_003C3938(a0, 1, 0);
        if (*(s32 *)(s1 + 0x70) != 0) {
            *(s32 *)(s1 + 0x74) = 8;
            a0[0x20] = 2;
            *(s32 *)(s1 + 0x84) = (*(s32 *)(s1 + 0x80) * 5 + 2) / 6;
        } else {
            *(s32 *)(a0 + 0x78) = D_L11_001DCFA4;
            a0[0x20] = 2;
        }
        break;
    case 2:
        if (*(s32 *)(s1 + 0x70) != 0) {
            if (func_0038CAD0(s1 + 0x74) != 0) {
                if (*(s32 *)(a0 + 0x78) == D_L11_001DCFA0)
                    *(s32 *)(a0 + 0x78) = D_L11_001DCFA4;
                else
                    *(s32 *)(a0 + 0x78) = D_L11_001DCFA0;
                *(s32 *)(s1 + 0x74) = 8;
            }
            if (func_0038CAD0(s1 + 0x84) != 0)
                a0[0xBC] = 0;
        }
        if ((a0[0x60] & 2) != 0) {
            if (a0[0x43] == 1)
                func_003C3938(a0, 2, 0);
        }
        if (a0[0xBC] != 0)
            break;
        if ((a0[0x60] & 2) != 0) {
            *(u16 *)(a0 + 0x34) |= 0x1000;
            func_003C3938(a0, 3, 0);
            *(s32 *)(a0 + 0x78) = D_L11_001DCFA0;
            a0[0x20] = 1;
            if (*(s32 *)(s1 + 0x88) != 0) {
                if (a0[0x21] != 0xFF)
                    func_L03_004330B8(a0[0x21], 0);
            }
        }
        break;
    }
}
/* localdecomp:end func_L11_0033CD20 */
