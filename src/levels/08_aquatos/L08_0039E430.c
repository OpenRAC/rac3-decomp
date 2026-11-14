#include "common.h"

/* localdecomp:start func_L08_0039E430 */
typedef int q_0039E430 __attribute__((mode(TI)));
extern s32 func_L08_0039E658(u8 *);
extern void func_L08_0039E8C8(u8 *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern u8 func_L01_0044CE88(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L08_0039E430(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;

    if (a0[0x20] == 0) {
        if (func_L08_0039E658(a0) != 0) return 1;
    }
    if (st[0x3E] == 2) {
        func_L08_0039E8C8(a0);
        return 1;
    }
    p = func_L01_00447490(a0, 0x10000, 0);
    if (func_0038CB00(st + 0x36) == 0) p = 0;
    if (p != 0) {
        *(q_0039E430 *)(st + 0x1E0) = *(q_0039E430 *)(p + 0x10);
        st[0x47] = func_L01_0044CE88(*(u8 **)(p + 0x20));
        *(f32 *)(st + 0x30) -= *(f32 *)(p + 0x2C);
        func_L01_004450F0(a0, 0xC, 3);
        func_L02_0034FD58(a0);
    }
    a0[0xA8] = 0xFF;
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L08_0039E8C8(a0);
        return 1;
    }
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x184), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x188), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x18C), 10.0f, 1.0f);
        }
    } else {
        if (a0[0x95] == 2) func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x184), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x188), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x18C), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L08_0039E430 */

/* localdecomp:start func_L08_0039E658 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_0039CB58.c */
#include "vu0.h"

extern void func_0038D308(void *, void *);
extern f32 func_00382538(void);
extern f32 func_003C3D30(void *, f32, s32, s32);

s32 func_L08_0039E658(u8 *self) {
    u8 *t;
    f32 f;
    f32 g;
    f32 h;
    u8 *pos;

    t = *(u8 **)(self + 0x68);
    pos = self + 0x10;
    *(u128_0039CB58 *)(t + 0x1A0) = *(u128_0039CB58 *)pos;
    if (*(s16 *)(self + 0xB2) == 0) {
        *(s32 *)(t + 0x1C0) = -1;
        *(s32 *)(t + 0x1C8) = -1;
    }
    *(s32 *)(self + 0xF0) = 0;
    *(s32 *)(self + 0xF4) = 0;
    func_0038D308(self + 0xC0, self + 0xF0);
    f = func_00382538();
    *(f32 *)(t + 0x70) = 0.5f;
    *(f32 *)(t + 0x1D0) = f;
    *(f32 *)(t + 0x74) = 0.25f;
    *(f32 *)(t + 0x78) = 1.25f;
    *(f32 *)(t + 0x7C) = 1.5f;
    *(f32 *)(t + 0x80) = 1.57079637f;
    *(f32 *)(t + 0xA0) = 0.34906584f;
    *(f32 *)(t + 0x9C) = 0.00392f;
    func_L01_0045BD78(0.0064000003f, 0.080000006f, 0.010053097f, 0.25132743f, self);
    t[0x58] = 0x14;
    t[0x5A] = 0xE;
    if (*(s16 *)(t + 0x34) == 0) {
        *(s16 *)(t + 0x34) = 1;
        *(f32 *)(t + 0x30) = 1.0f;
    }
    if (t[0x44] == 0) {
        t[0x44] = 5;
        t[0x45] = 5;
        t[0x46] = 5;
    }
    *(f32 *)(t + 0x40) = 0.5f;
    t[0x3F] = 0;
    t[0x39] = 1;
    t[0x64] = 1;
    t[0x3E] = 1;
    func_L01_004450F0(self, 3, 0);
    if (self[0x43] != 1) {
        func_003C3A10(self, 1, 0, 0);
    }
    if (*(s32 *)(t + 0x1C0) != -1 || *(s32 *)(t + 0x1C8) != -1) {
        func_L01_004450F0(self, 0xA, 4);
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004AA7E8(self, 1);
    } else if (*(s32 *)(t + 0x1C4) == 1) {
        g = func_003C3D30(pos, 0.5f, 0, 0);
        h = *(f32 *)(self + 0x18);
        if (3.0f < h - g) {
            g = h;
        }
        *(f32 *)(self + 0x18) = g - 1.0f;
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(self, 1);
    }
    return 0;
}
/* localdecomp:end func_L08_0039E658 */
