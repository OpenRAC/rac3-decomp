/* NTSC-U draft (Claude wave K): C of func_L02_0039EE78, the NTSC-U twin of func_L02_003A0C18, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L02_0039EE78", whose code is not the PAL one).
 * Worker's note: Needs -mvu0-use-vf0-vf2 (vec_add_ba) and @ps2as (lui/ori float literals) added to the PAL line (-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses). Ring of 40 particles (func_L01_0046C468 twice per step: coloured 0x40/0x20 sprite then white ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L02_0039FAF0 (src/levels/shared/L02_0039FAF0.c) */
/* localdecomp:start func_L02_0039EE78 */
#include "vu0.h"
typedef int u128_0039EE78 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0039EE78;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x14 - 0x8];
    u8 b14;
    u8 b15;
    u8 b16;
    u8 pad17;
    u8 b18;
} M_0039EE78;
typedef struct { u8 pad0[0x10]; V_0039EE78 pos; } E_0039EE78;
typedef struct { u8 pad0[0x68]; M_0039EE78 *x68; } O_0039EE78;
typedef struct { u8 pad0[0x164]; u8 **x164; } T_0039EE78;

extern u8 *D_L02_001DEA1C[];
extern T_0039EE78 D_L02_0021E158;
__asm__(".extern D_L02_0021E158, 16");
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L02_0039EE78(O_0039EE78 *o) {
    M_0039EE78 *m = o->x68;
    E_0039EE78 *e = (E_0039EE78 *)(D_L02_001DEA1C[0] + ((m->b18 != 0 ? m->x4 : m->x0) << 8));
    V_0039EE78 v0;
    V_0039EE78 v10;
    f32 ang = 0.0f;
    f32 a;
    f32 b;
    s32 i;
    s32 c1;
    s32 col;
    s32 keep;
    u8 *tb = (u8 *)&D_L02_0021E158;
    s32 d1;
    u8 *p;

    for (i = 0x27; i >= 0; i--) {
        *(u128_0039EE78 *)&v10 = 0;
        keep = 0;
        v10.x = func_00388978(ang) * 0.4f;
        v10.y = func_00388960(ang) * 0.4f;
        v10.z = 1.75f;
        *(u128_0039EE78 *)&v0 = *(u128_0039EE78 *)&v10;
        vec_add_ba(&v10, &e->pos, &v0);
        v0.z = 0.0f;
        func_00388830(&v0, &v0, (func_0037E250(-1.0f, 1.0f) + 10.0f) * 0.016666668f);
        c1 = func_0037E208(0xF, 0x19);
        a = func_0037E250(-0.1f, 0.1f) + 0.5f;
        b = func_0037E250(-4.0f, 4.0f) + 15.0f;
        col = (m->b16 << 16) | (m->b15 << 8) | m->b14;
        d1 = func_0037E1D8(2);
        b = b * 0.00027777778f;
        p = func_L01_0046C468(&v10, &v0, c1, col, d1 != 0 ? -1 : 1, 0x40, 0x20, 0, a * 210000.0f,
                              a * 210000.0f, b);
        if (p != 0) {
            keep = p[8] + 0x20;
            p[2] = **(u8 ***)(tb + 0x164);
        }
        p = func_L01_0046C468(&v10, &v0, c1, 0xF7F7F7, func_0037E1D8(2) != 0 ? -1 : 1, 0x30, 0x30, 0,
                              a * 0.4f * 210000.0f, a * 0.4f * 210000.0f, b);
        if (p != 0) {
            p[8] = keep;
            p[2] = **(u8 ***)(tb + 0x164);
        }
        ang = func_00389380(ang, 0.15707964f);
    }
}
/* localdecomp:end func_L02_0039EE78 */
