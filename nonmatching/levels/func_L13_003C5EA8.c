/* NTSC-U draft (Claude wave C4): C of func_L13_003C3CE0, the NTSC-U twin of func_L13_003C5EA8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L13_003C3CE0", whose code is not the PAL one).
 * Worker's note: flags: MATCH with '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -fno-gcse @ps2as' (check_native, 256/256 words, no jump table, no divs row); the PAL file L13_003C5E20.c has the plain STD line, so it cannot land as is. Needs @ps2as (4 ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_003C3CE0 */
/* func_L13_003C3CE0: update of a homing projectile (state at +0x68): trail particle, steering
   (func_003BEB58), move + collision, the two explosion calls (shared tail after cross-jumping),
   position history. Written from the retail assembly (C4 w02 fork F4).
   Build needs "-mvu0-use-vf0-vf2 ... -fno-gcse @ps2as": vec_add_ba (VU0), four inline float constants
   (lui/ori/mtc1), and no gcse: with it PRE hoists the 2nd '&a' (sp+0xA0) into an extra $s4 before the
   first branch (retail computes it twice). No divs row. */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern u8 D_L13_001D66B0[8];
extern u8 *D_L13_0021EFF4[];
extern u8 *D_L13_001E8F00[];
extern void func_L13_003C3C58(void);
extern void func_003BDA38(void *, s32, void *);
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
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_004026A0(void *, void *);

void func_L13_003C3CE0(u8 *o) {
    V4 v90;
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
        func_L01_0032FE90(o + 0x10, 0, 6, 6, 6, 6, 10, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(o);
        return;
    }
    func_003BDA38(o, 0, &v90);
    n = func_0037E1D8(0x28);
    rnd = func_0037E250(500.0f, 1500.0f);
    r = func_L01_00466F98(&v90, D_L13_001D66B0, 0x14, 0x60, 0x101010, n, 252000.016f, rnd, 1.0f, 0.0f, 0.0f);
    if (r != 0) {
        r[2] = *D_L13_0021EFF4[0];
        r[3] = 0x44;
    }
    if (*(u16 *)(o + 0x96) >= 0x3D) {
        if (*(s32 *)(s + 0x20) != 0) {
            V4 a;
            V4 b;
            *(u128_t *)&a = *(u128_t *)s;
            *(u128_t *)&b = *(u128_t *)(s + 0x10);
            func_003BEB58(s, &a, &b, 0.005f);
            if (0.5f < func_00388770(s)) {
                func_00388830(s, s, 0.5f);
            }
            if (*(s32 *)(s + 0x20) == 1) {
                func_00388830(s, s, 0.5f);
            }
        }
    }
    {
        V4 a;
        *(u128_t *)&a = *(u128_t *)(o + 0x10);
        func_00389158(s, s, s + 0x10, 0.116355292f);
        *(f32 *)(o + 0xF4) = -func_00388A28(func_003887A0(s), *(f32 *)(s + 8));
        *(f32 *)(o + 0xF8) = func_00388A28(*(f32 *)s, *(f32 *)(s + 4));
        *(f32 *)(o + 0xF0) = func_00389380(*(f32 *)(o + 0xF0), 0.116355292f);
        vec_add_ba(o + 0x10, o + 0x10, s);
        owner = *(s32 *)(o + 0xB8);
        func_L01_004C76B8();
        hit = func_003CE740(&a, o + 0x10, 0, owner, 0);
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
            func_L01_0032FE90(&D_L13_001E8F00[0x20 / 4], 0, 6, 6, 6, 6, 10, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(o);
            return;
        }
    }
    {
        V4 b;
        *(u128_t *)&b = *(u128_t *)&v90;
        i = 3;
        p = s + 0x50;
        for (; i > 0; i--) {
            *(u128_t *)(p + 0x10) = *(u128_t *)p;
            p -= 0x10;
        }
        *(u128_t *)(s + 0x30) = *(u128_t *)&b;
    }
    *(s32 *)(s + 0x24) = *(s32 *)(s + 0x24) + 1;
    if (*(s32 *)(s + 0x24) >= 4) {
        func_L01_004026A0(func_L13_003C3C58, o);
    }
    *(u16 *)(o + 0x96) = *(u16 *)(o + 0x96) + 1;
}
/* localdecomp:end func_L13_003C3CE0 */
