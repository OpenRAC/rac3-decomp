#include "common.h"

/* NTSC-U counterpart of func_L02_003A0C18 (src/levels/shared/L02_003A04D0.c) */
#include "vu0.h"
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

/* localdecomp:start func_L02_0039EE78 */
#include "vu0.h"
typedef int u128_003A0C18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A0C18;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x14 - 0x8];
    u8 b14;
    u8 b15;
    u8 b16;
    u8 pad17;
    u8 b18;
} M_003A0C18;
typedef struct { u8 pad0[0x10]; V_003A0C18 pos; u8 pad20[0xE0]; } E_003A0C18;
typedef struct { u8 pad0[0x68]; M_003A0C18 *x68; } O_003A0C18;

extern u8 D_L02_0021E158[];
extern u8 *D_L02_001DEA1C_0039EE78;
__asm__(".extern D_L02_001DEA1C_0039EE78, 16");
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

static __inline__ E_003A0C18 *moby_003A0C18(s32 idx) {
    return (E_003A0C18 *)(D_L02_001DEA1C_0039EE78 + (idx << 8));
}

void func_L02_0039EE78(O_003A0C18 *o) {
    M_003A0C18 *m = o->x68;
    E_003A0C18 *e;
    V_003A0C18 v0;
    V_003A0C18 v10;
    f32 ang;
    f32 a;
    f32 b;
    s32 i;
    s32 c1;
    s32 col;
    s32 keep;
    u8 *tb;
    s32 d1;
    u8 *p;

    e = m->b18 != 0 ? moby_003A0C18(m->x4) : moby_003A0C18(m->x0);
    ang = 0.0f;
    tb = D_L02_0021E158;
    for (i = 0; i < 40; i++) {
        *(u128_003A0C18 *)&v10 = 0;
        keep = 0;
        v10.x = func_00388978(ang) * 0.4f;
        v10.y = func_00388960(ang) * 0.4f;
        v10.z = 1.75f;
        *(u128_003A0C18 *)&v0 = *(u128_003A0C18 *)&v10;
        vec_add_ba(&v10, &e->pos, &v0);
        v0.z = 0.0f;
        func_00388830(&v0, &v0, (func_0037E250(-1.0f, 1.0f) + 10.0f) * (1.0f / 60.0f));
        c1 = func_0037E208(0xF, 0x19);
        a = func_0037E250(-0.1f, 0.1f) + 0.5f;
        b = func_0037E250(-4.0f, 4.0f) + 15.0f;
        col = (m->b16 << 16) | (m->b15 << 8) | m->b14;
        d1 = func_0037E1D8(2);
        b = b * (0.4f / 1440.0f);
        p = func_L01_0046C468(&v10, &v0, c1, col, d1 != 0 ? -1 : 1, 0x40, 0x20, a * 210000.0f,
                              a * 210000.0f, b, 0);
        if (p != 0) {
            keep = p[8] + 0x20;
            p[2] = **(u8 **)(tb + 0x164);
        }
        p = func_L01_0046C468(&v10, &v0, c1, 0xF7F7F7, func_0037E1D8(2) != 0 ? -1 : 1, 0x30, 0x30,
                              a * 0.4f * 210000.0f, a * 0.4f * 210000.0f, b, 0);
        if (p != 0) {
            p[2] = **(u8 **)(tb + 0x164);
            p[8] = keep;
        }
        ang = func_00389380(ang, 0.15707964f);
    }
}
/* localdecomp:end func_L02_0039EE78 */
