#include "common.h"

/* declared by functions of L40_00420998.c, which this file was cut from */
extern s32 func_L40_00422540(u8 *a0);

/* localdecomp:start func_L40_00422678 */
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L40_00422570(u8 *);
extern s32 func_L40_00422550(u8 *);
extern void func_L40_00423CB0(u8 *);

void func_L40_00422678(u8 *self) {
    u8 *v;

    if (self == 0) {
        return;
    }
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    v = *(u8 **)(self + 104);
    func_L01_004450F0(self, 1, -1);
    *(u16 *)(self + 52) &= 0xFFBE;
    *(u16 *)(self + 52) |= *(u16 *)(*(u8 **)(self + 36) + 68) & 0x1000;
    *(s32 *)(self + 152) = *(s32 *)(*(u8 **)(self + 36) + 16);
    self[168] = 255;
    func_L40_00422570(self);
    *(f32 *)(v + 48) = 1.0f;
    *(u16 *)(self + 52) |= 0x1000;
    if (func_L40_00422550(self) != 0) {
        func_L40_00423CB0(self);
    }
}
/* localdecomp:end func_L40_00422678 */

/* localdecomp:start func_L40_00422730 */
extern void func_L40_00422678(u8 *);
extern s32 func_L40_00422608(u8 *);

void func_L40_00422730(u8 *self, s32 a1, s32 a2) {
    u8 *v;

    if (self == 0) {
        return;
    }
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    v = *(u8 **)(self + 104);
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    if (func_L40_00422608(self) == 0) {
        return;
    }
    *(s32 *)(v + 0x84) = 1;
    if (func_L40_00422550(self) != 0) {
        func_L40_00423CB0(self);
    }
    if (self[32] != 0) {
        *(s32 *)(v + 0x70) = 30000;
        ((void (*)(u8 *, s32, s32))func_L40_00422678)(self, a1, a2);
    } else {
        *(s32 *)(v + 0x70) = 30;
    }
}
/* localdecomp:end func_L40_00422730 */

/* localdecomp:start func_L40_004227F8 */
extern s32 D_L40_00247718[2] __attribute__((section(".sdata")));
extern s32 D_L40_00247720[2] __attribute__((section(".sdata")));
s32 *func_L40_004227F8(u8 *a0, s32 a1, s32 *a2) {
    s32 *r = 0;
    switch (a1) {
    case 0x4027571:
        r = D_L40_00247718;
        *a2 = 4;
        break;
    case 0x4027572:
        r = D_L40_00247720;
        *a2 = 4;
        break;
    }
    return r;
}
/* localdecomp:end func_L40_004227F8 */

/* localdecomp:start func_L40_00422848 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00422848(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00422848 */

/* localdecomp:start func_L40_00422870 */
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L40_00422540(u8 *a0);
extern s32 func_L40_00545BF0(void);
extern s32 func_L39_00672208(s32);
extern s32 func_0019D510(void);
extern s32 func_L39_00672118(u32);
extern s32 func_L39_00672190(s32);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern u8 *D_L40_00241640;

void func_L40_00422870(u8 *self, u8 *other) {
    s32 r = 0;
    s32 i;
    s32 j;
    u8 *p;
    s32 h;
    u8 bits;
    s32 k;
    s32 n;
    s32 me;
    u8 buf[1];

    if (other == 0 || !(func_L01_0040E548(other + 0xA0, self + 0x10) < 4.0f)) {
        r = 250;
    } else {
        for (i = 0; i < 8; i++) {
            p = D_L40_00249330[i];
            if (p != 0 && p != other && func_L01_0040E548(other + 0xA0, p + 0xA0) < 20.0f) {
                r = 250;
                break;
            }
        }
    }
    h = func_L39_0066DCC8((s32)self, 0, 0, r);
    if (func_L40_00422540(self) != 0) {
        bits = D_L40_00241640[0x199];
        k = 0;
        n = func_L40_00545BF0();
        if (func_L39_00672208(1) != 0) {
            n--;
        }
        if (n >= 2) {
            k = func_0019D510() % n;
        }
        me = func_L39_00672118(1);
        for (j = 0; j < 8; j++) {
            if (j != me && ((bits >> j) & 1)) {
                if (k == 0) {
                    break;
                }
                k--;
            }
        }
        buf[0] = func_L39_00672190(j);
        func_L39_00662AA0(h, buf, 1);
    }
}
/* localdecomp:end func_L40_00422870 */
