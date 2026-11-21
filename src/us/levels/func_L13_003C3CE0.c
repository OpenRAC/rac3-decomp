#include "common.h"

/* NTSC-U counterpart of func_L13_003C5EA8 (src/levels/shared/L13_003C5EA8.c) */
extern void func_003BDA38(u8 *a0, s32 a1, u8 *a2);

/* localdecomp:start func_L13_003C3CE0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C5EA8;

extern u8 D_L13_001D66B0_003C3CE0[8] __attribute__((section(".sdata")));
extern u8 *D_L13_0021EFF4[];
extern u8 *D_L13_001E8F00[];
extern void func_003BDA38(u8 *, s32, u8 *);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003BEB58(void *, void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_L01_0032FE90_003C3CE0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_004026A0_003C3CE0(void *, void *);
extern void func_L13_003C3C58(u8 *);

static __inline__ void steer_003C5EA8(u8 *s) {
    V4_003C5EA8 a;
    V4_003C5EA8 b;
    *(vu0_q *)&a = *(vu0_q *)s;
    *(vu0_q *)&b = *(vu0_q *)(s + 0x10);
    func_003BEB58(s, &a, &b, 0.005f);
    if (0.5f < func_00388770(s)) {
        func_00388830(s, s, 0.5f);
    }
    if (*(s32 *)(s + 0x20) == 1) {
        func_00388830(s, s, 0.5f);
    }
}

void func_L13_003C3CE0(u8 *o) {
    V4_003C5EA8 v90;
    u8 *s;
    u8 *r;
    s32 n;
    s32 hit;
    s32 owner;
    f32 rnd;
    s32 i;
    u8 *p;

    s = *(u8 **)(o + 0x68);
    if (*(u16 *)(o + 0x96) >= 0x79) {
        func_L01_0032FE90_003C3CE0(o + 0x10, 0, 6, 6, 6, 6, 10, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(o);
        return;
    }
    func_003BDA38(o, 0, (u8 *)&v90);
    n = func_0037E1D8(0x28);
    rnd = func_0037E250(500.0f, 1500.0f);
    r = func_L01_00466F98(&v90, D_L13_001D66B0_003C3CE0, 0x14, 0x60, 0x101010, n, 252000.016f, rnd, 1.0f, 0.0f, 0.0f);
    if (r != 0) {
        r[2] = *D_L13_0021EFF4[0];
        r[3] = 0x44;
    }
    if (*(u16 *)(o + 0x96) >= 0x3D) {
        if (*(s32 *)(s + 0x20) != 0) {
            steer_003C5EA8(s);
        }
    }
    {
        V4_003C5EA8 a;
        u8 *pos;
        *(vu0_q *)&a = *(vu0_q *)(o + 0x10);
        pos = o + 0x10;
        func_00389158(s, s, s + 0x10, 0.11635529f);
        *(f32 *)(o + 0xF4) = -func_00388A28(func_003887A0(s), *(f32 *)(s + 8));
        *(f32 *)(o + 0xF8) = func_00388A28(*(f32 *)s, *(f32 *)(s + 4));
        *(f32 *)(o + 0xF0) = func_00389380(*(f32 *)(o + 0xF0), 0.11635529f);
        vec_add_ba(o + 0x10, o + 0x10, s);
        owner = *(s32 *)(o + 0xB8);
        func_L01_004C76B8();
        hit = func_003CE740(&a, pos, 0, owner, 0);
    }
    if (hit != 0) {
        u8 *g = D_L13_001E8F00[0x18 / 4];
        if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
            g[0x20] = 4;
        }
    }
    func_L01_004C76F0();
    if (hit != 0) {
        u8 *g = D_L13_001E8F00[0x18 / 4];
        if (g == 0 || (u32)(*(u16 *)(g + 0xAA) - 0x199A) >= 3) {
            func_L01_0032FE90_003C3CE0(&D_L13_001E8F00[0x20 / 4], 0, 6, 6, 6, 6, 10, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(o);
            return;
        }
    }
    {
        V4_003C5EA8 b;
        *(vu0_q *)&b = *(vu0_q *)&v90;
        i = 3;
        p = s + 0x50;
        for (; i > 0; i--) {
            *(vu0_q *)(p + 0x10) = *(vu0_q *)p;
            p -= 0x10;
        }
        *(vu0_q *)(s + 0x30) = *(vu0_q *)&b;
    }
    *(s32 *)(s + 0x24) = *(s32 *)(s + 0x24) + 1;
    if (*(s32 *)(s + 0x24) >= 4) {
        func_L01_004026A0_003C3CE0(func_L13_003C3C58, o);
    }
    *(u16 *)(o + 0x96) = *(u16 *)(o + 0x96) + 1;
}
/* localdecomp:end func_L13_003C3CE0 */
