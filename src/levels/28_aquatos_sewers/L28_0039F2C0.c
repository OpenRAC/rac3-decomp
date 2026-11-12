#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L28_0039F2C0);

/* localdecomp:start func_L28_003A0708 */
extern s32 func_L28_003A0930(void *);
extern void func_003C2880(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L28_003A0EC0(u8 *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L28_003A0B60(u8 *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_003A0708(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 t;
    if (a0[0x20] == 0) {
        if (func_L28_003A0930(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x2D8) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, st + 0x160, 0, 0, 0) != 0) func_L28_003A0EC0(a0);
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_003A0B60(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_003A0708 */

/* localdecomp:start func_L28_003A0930 */
typedef int u128_003A0930 __attribute__((mode(TI)));
extern f32 D_L28_001DE040;
extern f32 D_L28_001DE044;
extern u8 D_L28_001DE070;
__asm__(".extern D_L28_001DE040, 4");
__asm__(".extern D_L28_001DE044, 4");
__asm__(".extern D_L28_001DE070, 1");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C7DD8(void *);
s32 func_L28_003A0930(void *self) {
    u8 *a0 = self;
    f32 fa, fb;
    u8 *st = *(u8 **)(a0 + 0x68);
    *(u128_003A0930 *)(st + 0x2D0) = *(u128_003A0930 *)(a0 + 0x10);
    if (*(s16 *)(a0 + 0xB2) == 0) {
        *(s32 *)(st + 0x2F0) = -1;
        *(s32 *)(st + 0x2F8) = -1;
    }
    a0[0x23] = 0x70;
    *(u16 *)(a0 + 0x34) |= 0x2100;
    *(s32 *)(a0 + 0xB8) = 0;
    st[0x170] = 8;
    st[0x1DB] = 0xFF;
    st[0x1A8] = 1;
    st[0x1D7] = 1;
    st[0x1D8] = 0;
    st[0x1D9] = 0;
    st[0x1DA] = 0;
    fa = D_L28_001DE044 * 0.00040000002f;
    fb = D_L28_001DE040 * 0.020000001f;
    *(s32 *)(st + 0xA8) |= 5;
    *(f32 *)(st + 0x190) = 0.5f;
    *(f32 *)(st + 0x19C) = 0.15000001f;
    *(f32 *)(st + 0x78) = 2.0f;
    *(f32 *)(st + 0x194) = 0.5f;
    *(f32 *)(st + 0x70) = 1.0f;
    *(f32 *)(st + 0x74) = 0.15000001f;
    *(f32 *)(st + 0x7C) = 2.0f;
    *(f32 *)(st + 0x80) = 12.566371f;
    *(f32 *)(st + 0xA0) = 0.34906584f;
    *(f32 *)(st + 0x9C) = 0.00392f;
    func_L01_0045BD78(a0, fa, fb, 0.010053097f, 0.25132743f);
    st[0x58] = 0x14;
    st[0x5A] = 0xE;
    if (*(s16 *)(st + 0x34) == 0) {
        *(s16 *)(st + 0x34) = 10;
        *(f32 *)(st + 0x30) = 10.0f;
    }
    *(f32 *)(st + 0x40) = 0.25f;
    st[0x39] = D_L28_001DE070;
    st[0x3E] = 1;
    st[0x3F] = 0;
    func_L01_004450F0(a0, 3, -1);
    if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 0);
    if (*(s32 *)(st + 0x2F0) != -1 || *(unsigned long *)(st + 0x2F8) != 0xFFFFFFFFUL) {
        func_L01_004450F0(a0, 1, -1);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
    }
    func_003C7DD8(a0);
    return 0;
}
/* localdecomp:end func_L28_003A0930 */

/* localdecomp:start func_L28_003A0B60 */
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L28_0039EBC8(void *);
extern void func_L01_004443E8(u8 *, s32, s32);
typedef int q_003A0B60 __attribute__((mode(TI)));
static __inline__ void spawn_003A0B60(u8 *self, u8 *st, f32 side, f32 up) {
    vu0_v4 a, b;
    u8 *m;
    u8 *d;
    m = func_003C24B0(0x1B5E, 0x200);
    if (m != 0) {
        func_L01_00456160(m, self);
        *(u16 *)(m + 0x34) |= 0x20;
        func_L01_0044A7D0(m);
        d = *(u8 **)(m + 0x68);
        *(s32 *)(d + 0x190) = *(s32 *)(st + 0x2C0);
        *(s32 *)(d + 0x198) = *(s32 *)(st + 0x2C8);
        *(f32 *)(d + 0x19C) = *(f32 *)(st + 0x2CC);
        *(f32 *)(d + 0x194) = *(f32 *)(st + 0x2C4);
        *(u8 **)(d + 0x1C) = d + 0x70;
        *(u8 **)(d + 0xC) = d + 0x160;
        *(u8 **)(d + 0x0) = d + 0x30;
        *(s16 *)(d + 0x36) = 0x1E;
        *(s32 *)(d + 0x1CC) = 2;
        func_0038CF68(&a, self + 0xD0, side);
        vec_add_ab(m + 0x10, &a, self + 0x10);
        func_0038CF68(&b, self + 0xE0, up);
        vec_add_ab(m + 0x10, &b, m + 0x10);
        *(q_003A0B60 *)(m + 0xC0) = *(q_003A0B60 *)(self + 0xC0);
        *(q_003A0B60 *)(m + 0xD0) = *(q_003A0B60 *)(self + 0xD0);
        *(q_003A0B60 *)(m + 0xE0) = *(q_003A0B60 *)(self + 0xE0);
        *(s16 *)(m + 0xB6) = 0xA;
        func_L28_0039EBC8(m);
    }
}
void func_L28_003A0B60(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    func_003A52A0(0, 0, self);
    func_003A52A0(1, 0, self);
    spawn_003A0B60(self, st, 0.7f, 0.4f);
    spawn_003A0B60(self, st, -0.7f, 0.3f);
    func_L01_004443E8(self, 0, 3);
    *(u16 *)(self + 0x34) &= 0xFFDF;
}
/* localdecomp:end func_L28_003A0B60 */

/* localdecomp:start func_L28_003A0DC0 */
extern u8 D_L28_001E1540[];
extern void func_L01_00404808(void *, void *);
extern void func_L08_003A16C8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_003A0DC0(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00404808(func_L08_003A16C8, a0);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L28_001E1540, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    t = func_0038DAB8(*(f32 *)(d + 0x30C), 0.15358898f);
    *(f32 *)(d + 0x30C) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_003A0DC0 */

/* localdecomp:start func_L28_003A0EC0 */
extern u16 *D_L28_0021B6A0[];
extern u8 *D_L28_001DEC9C;
__asm__(".extern D_L28_001DEC9C, 16");
extern s32 D_L28_001DECD8;

void func_L28_003A0EC0(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L28_0021B6A0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L28_001DECD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L28_0021B6A0[a0[0x21]])) {
        e = D_L28_001DEC9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x300) = 1;
        }
    }
}
/* localdecomp:end func_L28_003A0EC0 */
