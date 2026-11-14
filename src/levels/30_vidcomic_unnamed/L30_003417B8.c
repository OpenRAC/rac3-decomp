#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L30_003417B8);

INCLUDE_ASM("asm/levels", func_L30_00341BA0);

/* localdecomp:start func_L30_00341D88 */
extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L24_0043C3B0(u8 *, s32, s32, s32, f32, f32);
extern f32 D_001A4C60[];

void func_L30_00341D88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) {
        if (a0[0x20] != 3 && a0[0x20] != 0x42) {
            func_L01_004450F0(a0, 3, -1);
        }
    }
    if (a0[0x20] != 3 && a0[0x20] != 0x42) {
        func_L24_0043C3B0(a0, *(s32 *)(p + 0x290), 0, 0, 16.0f, 8.0f);
    }
    *(f32 *)(a0 + 0x14) = D_001A4C60[1];
}
/* localdecomp:end func_L30_00341D88 */

/* localdecomp:start func_L30_00341E38 */
extern void func_003C2F58(u8 *, s32, u8 *);
extern s32 func_L30_00340E18(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L30_00341E38(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    f32 k = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);

    v[0x170] = 3;
    v[0x1A8] = o[0x95];
    v[0x38] = 3;
    *(f32 *)(v + 0xA4) = k * 0.05f;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.4f;
    *(f32 *)(v + 0x74) = k * 0.25f;
    *(f32 *)(v + 0x70) = k * 0.5f;
    *(f32 *)(v + 0x78) = 0.4f;
    *(f32 *)(v + 0x7C) = 0.4f;
    *(f32 *)(v + 0x80) = 0.7853982f;
    *(f32 *)(v + 0x84) = 0.25132743f;
    *(f32 *)(v + 0x88) = 0.25132743f;
    *(f32 *)(v + 0xA0) = 0.5235988f;
    *(u128_t *)(v + 0x240) = *(u128_t *)(o + 0x10);
    *(f32 *)(v + 0x90) = k * 0.0012f;
    *(f32 *)(v + 0x94) = k * 0.0012f;
    *(f32 *)(v + 0x98) = k * 0.24000001f;
    *(f32 *)(v + 0x84) = 0.010053097f;
    *(f32 *)(v + 0x88) = 0.010053097f;
    *(f32 *)(v + 0x8C) = 0.50265485f;
    *(s32 *)(v + 0xA8) |= 0x10;
    func_003C2F58(o, 2, v + 0x2B0);
    func_003C2F58(o, 3, v + 0x2C0);
    *(s32 *)(v + 0x2A0) = func_L30_00340E18(v + 0x2B0, o, v + 0x2C0, 0x32, 0x32, 0x14, 5, 0xFF0808,
                                            0.2f, 0.22f, 0.1f, 1.3f, 0xFF0808, 1, -1, 1);
    *(s32 *)(v + 0x298) = 0;
}
/* localdecomp:end func_L30_00341E38 */

/* localdecomp:start func_L30_00342030 */
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L30_00342030(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0x68);

    if (state[0x251] == 0) {
        func_L01_0043A430(arg0, 0, state + 0x250);
    }
    func_0038D750(state + 0x260, 2, *(f32 *)(state + 0x29C));
    *(f32 *)(state + 0x29C) = func_0038DB00(*(f32 *)(state + 0x29C), 0.17453293f);
}
/* localdecomp:end func_L30_00342030 */

/* localdecomp:start func_L30_00342090 */
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);

void func_L30_00342090(u8 *a0, s32 a1, u8 *a2) {
    u8 *p = *(u8 **)(a0 + 0x68);
    func_L01_00446780(a0, a2, 0x10001, 0, 1, 0, 1.0f, (f32)p[0x44], 0.0f);
}
/* localdecomp:end func_L30_00342090 */

/* localdecomp:start func_L30_003420E0 */
#include "vu0.h"
extern f32 D_001A4C60[];
__asm__(".extern D_L30_001DCE24, 4");
extern s32 D_L30_001DCE24;
__asm__(".extern D_L30_001DCE30, 2");
extern s16 D_L30_001DCE30;
__asm__(".extern D_L30_001DCE38, 4");
extern f32 D_L30_001DCE38;
extern u8 D_L30_001D66B0[8];
extern u8 D_001A4BE0[];
extern s32 func_L01_004561B8(u8 *);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L30_003427F8(u8 *);
extern s32 func_L30_00342980(u8 *);
extern void func_L30_00342A08(u8 *);
extern f32 func_0038CF00(void *, void *);
extern void func_L30_0034CB68(u8 *, s32, s32, s32, u128_t *, s32, f32, f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L30_00342600(u8 *);


void func_L30_003420E0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 flags;

    switch (o[0x20]) {
    case 0x42:
        if (func_L01_004561B8(o)) {
            *(u128_t *)(o + 0x10) = *(u128_t *)(v + 0x50);
            func_003A52A0(2, 0, o);
            flags = *(s32 *)(v + 0x84);
            *(s32 *)(v + 0x84) = flags & ~4;
            if ((flags & 2) || ((v[0x84] ^ 1) & 1)) {
                func_003C2880(o);
                return;
            }
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
        }
        if (func_L30_0034D8D8(o + 0x10, 1.5f) != 0) {
            flags = *(s32 *)(v + 0x84);
            if (flags & 1) {
                if (flags & 4) {
                u8 *c;
                *(u16 *)(o + 0x34) &= 0xFFBE;
                c = *(u8 **)(o + 0x24);
                *(u16 *)(o + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
                *(s32 *)(o + 0x98) = *(s32 *)(c + 0x10);
                func_L01_004450F0(o, 0, -1);
                }
            }
        } else {
            *(s32 *)(v + 0x84) |= 4;
        }
        break;
    case 1:
        if (func_L01_004561B8(o) && o[0x43] != 1) {
            func_003C3A10(o, 1, 0, (D_L30_001DCE24 * 5 + 2) / 6);
        }
        func_L30_003427F8(o);
        if (func_L30_00342980(o)) {
            func_L30_00342A08(o);
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o) && o[0x43] != 5) {
            func_003C3A10(o, 5, 0, (D_L30_001DCE24 * 5 + 2) / 6);
        }
        if (__builtin_fabsf(D_001A4C60[0] - *(f32 *)(o + 0x10)) <= *(f32 *)(v + 0x78)) {
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 0:
        if (*(s16 *)(v + 4) <= 0) {
            *(s16 *)(v + 4) = D_L30_001DCE30;
        }
        *(s16 *)(v + 0x4C) = 4;
        *(s16 *)(v + 0x4E) = 0xF;
        *(f32 *)v = (f32)*(s16 *)(v + 4);
        *(u128_t *)(v + 0x50) = *(u128_t *)(o + 0x10);
        *(f32 *)(v + 0x70) = *(f32 *)(o + 0x2C) * 1.6f / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        *(f32 *)(v + 0x74) = *(f32 *)(o + 0x2C) * 1.6f / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        *(s32 *)(v + 0x80) = 0;
        if (*(s32 *)(v + 0x84) & 2) {
            func_L01_004450F0(o, 5, -1);
        } else {
            qzero(v + 0x60);
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(o) && o[0x43] != 2) {
            func_003C3A10(o, 2, 0, (D_L30_001DCE24 * 5 + 2) / 6);
        }
        if (o[0x60] & 2) {
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(o) && o[0x43] != 4) {
            func_003C3A10(o, 4, 0, (D_L30_001DCE24 * 5 + 2) / 6);
        }
        {
            f32 t = *(f32 *)(v + 0x60);
            *(f32 *)(v + 0x60) = D_001A4C60[0] < *(f32 *)(o + 0x10) ? t - D_L30_001DCE38 : t + D_L30_001DCE38;
        }
        func_L30_003427F8(o);
        if (func_0038CF00(D_001A4BE0 + 0x80, o + 0x10) < *(f32 *)(v + 0x7C)) {
            func_L30_0034CB68(o, (s32)D_L30_001D66B0, 1, -1, 0, 0, (f32)v[0x14], *(f32 *)(v + 0x7C) * 1.5f);
            func_L01_003303B8(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, *(f32 *)(v + 0x7C) / 3.0f, 1.0f, 0.0f, 0.0f,
                              1, 1, 0, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_004450F0(o, 0x42, -1);
        }
        break;
    case 5:
        func_L01_004561B8(o);
        func_L01_004450F0(o, 1, -1);
        break;
    }
    func_L30_00342600(o);
}
/* localdecomp:end func_L30_003420E0 */

/* localdecomp:start func_L30_00342600 */
extern f32 D_001A4C64[];
__asm__(".extern D_L30_001DCE34, 4");
extern s32 D_L30_001DCE34;
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L30_0034D8D8(void *, f32);

void func_L30_00342600(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    u8 *r;
    f32 dmg;

    func_0038CAD0(v + 0x80);
    func_L01_0044ABD0(o, v + 0x40);
    r = (u8 *)func_L01_00447490(o, 0x10000, 0);
    if (r != 0) {
        o[0xA8] = 0xFF;
        dmg = *(f32 *)(r + 0x2C);
        if (dmg > 0.0f && o[0x20] != 0x42 && *(s32 *)(v + 0x80) == 0) {
            v[0x47] = 0xFF;
            *(f32 *)v -= dmg;
            func_003C4A40(o, v + 0x40);
            *(s32 *)(v + 0x80) = D_L30_001DCE34;
            if (*(f32 *)v <= 0.0f) {
                func_L01_003303B8(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, *(f32 *)(v + 0x7C) / 3.0f, 1.0f, 0.0f, 0.0f,
                                  1, 1, 0, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                                  0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_L01_004450F0(o, 0x42, -1);
            }
        }
    }
    *(f32 *)(o + 0x14) = D_001A4C64[0];
    if (o[0x20] != 0x42 && (*(s32 *)(v + 0x84) & 1) && !func_L30_0034D8D8(o + 0x10, 1.5f)) {
        func_L01_004450F0(o, 0x42, -1);
    }
}
/* localdecomp:end func_L30_00342600 */

INCLUDE_ASM("asm/levels", func_L30_003427F8);

/* localdecomp:start func_L30_00342980 */
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 D_L30_001DCE2C;
__asm__(".extern D_L30_001DCE2C, 4");
extern u8 D_L30_001E9028[];

s32 func_L30_00342980(u8 *a0) {
    u128_t t = *(u128_t *)(a0 + 0x10);
    u8 *p = *(u8 **)(a0 + 0x68);
    *(f32 *)((u8 *)&t + 8) += *(f32 *)(p + 0x74);
    if (func_L01_003FB640(&t, 2, a0, *(f32 *)(p + 0x70) + D_L30_001DCE2C) != 0) {
        if (*(f32 *)D_L30_001E9028 <= *(f32 *)((u8 *)&t + 8)) {
            *(f32 *)(a0 + 0x18) = *(f32 *)D_L30_001E9028;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L30_00342980 */

INCLUDE_ASM("asm/levels", func_L30_00342A08);

/* localdecomp:start func_L30_00342C80 */
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

u8 *func_L30_00342C80(void *pos, void *vel, f32 f12, f32 f13) {
    u8 *s0 = func_003C24B0(0x1398, 0x80);
    u8 *vars;

    if (s0 == 0) {
        return 0;
    }
    *(u128_t *)(s0 + 0x10) = *(u128_t *)pos;
    s0[0x30] = 0xFF;
    *(u16 *)(s0 + 0x32) = 0x40;
    vars = *(u8 **)(s0 + 0x68);
    *(f32 *)(s0 + 0x2C) = f12 * *(f32 *)(*(u8 **)(s0 + 0x24) + 0x24);
    *(u128_t *)(vars + 0x60) = *(u128_t *)vel;
    *(f32 *)(vars + 0x7C) = f13;
    *(s32 *)(vars + 0x84) = 3;
    func_L01_004450F0(s0, 0, -1);
    return s0;
}
/* localdecomp:end func_L30_00342C80 */
