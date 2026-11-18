/* PAL port of the NTSC-U draft (Sonnet worker b15-z4, 2026-11-18): -fno-gcse needed on the file line; PAL names and constants done. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_003C5EA8 */
/* func_L13_003C5EA8: update of a homing projectile (state at +0x68): trail particle, steering
   (func_003C4098), move + collision, the two explosion calls (shared tail after cross-jumping),
   position history. Written from the retail assembly (C4 w02 fork F4).
   Build needs "-mvu0-use-vf0-vf2 ... -fno-gcse @ps2as": vec_add_ba (VU0), four inline float constants
   (lui/ori/mtc1), and no gcse: with it PRE hoists the 2nd '&a' (sp+0xA0) into an extra $s4 before the
   first branch (retail computes it twice). No divs row. */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern u8 D_L13_001D66B0[8];
extern u8 *D_L13_0021EF74[];
extern u8 *D_L13_001E8E80[];
extern void func_003C2F58(u8 *, s32, u8 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L13_003C5E20(u8 *);

void func_L13_003C5EA8(u8 *o) {
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
    if (*(u16 *)(o + 0x96) >= 0x65) {
        func_L01_003303B8(o + 0x10, 0, 6, 6, 6, 6, 10, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003C2880(o);
        return;
    }
    func_003C2F58(o, 0, (u8 *)&v90);
    n = func_00382468(0x28);
    rnd = func_003824E0(500.0f, 1500.0f);
    r = func_L01_0046A610(&v90, D_L13_001D66B0, 0x11, 0x60, 0x101010, n, 252000.016f, rnd, 1.0f, 0.0f, 0.0f);
    if (r != 0) {
        r[2] = *D_L13_0021EF74[0];
        r[3] = 0x44;
    }
    if (*(u16 *)(o + 0x96) >= 0x3D) {
        if (*(s32 *)(s + 0x20) != 0) {
            V4 a;
            V4 b;
            *(u128_t *)&a = *(u128_t *)s;
            *(u128_t *)&b = *(u128_t *)(s + 0x10);
            func_003C4098(s, &a, &b, 0.005f);
            if (0.6f < func_0038CEA8(s)) {
                func_0038CF68(s, s, 0.6f);
            }
            if (*(s32 *)(s + 0x20) == 1) {
                func_0038CF68(s, s, 0.6f);
            }
        }
    }
    {
        V4 a;
        *(u128_t *)&a = *(u128_t *)(o + 0x10);
        func_0038D890(s, s, s + 0x10, 0.13962635f);
        *(f32 *)(o + 0xF4) = -func_0038D160(func_0038CED8(s), *(f32 *)(s + 8));
        *(f32 *)(o + 0xF8) = func_0038D160(*(f32 *)s, *(f32 *)(s + 4));
        *(f32 *)(o + 0xF0) = func_0038DAB8(*(f32 *)(o + 0xF0), 0.13962635f);
        vec_add_ba(o + 0x10, o + 0x10, s);
        owner = *(s32 *)(o + 0xB8);
        func_L01_004CB320();
        hit = func_003D3CB0(&a, o + 0x10, 0, owner, 0);
    }
    if (hit != 0) {
        u8 *g = D_L13_001E8E80[0x18 / 4];
        if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
            g[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        u8 *g = D_L13_001E8E80[0x18 / 4];
        if (g == 0 || (u32)(*(u16 *)(g + 0xAA) - 0x199A) >= 3) {
            func_L01_003303B8(&D_L13_001E8E80[0x20 / 4], 0, 6, 6, 6, 6, 10, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003C2880(o);
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
        func_L01_00404A10(func_L13_003C5E20, o);
    }
    *(u16 *)(o + 0x96) = *(u16 *)(o + 0x96) + 1;
}
/* localdecomp:end func_L13_003C5EA8 */
