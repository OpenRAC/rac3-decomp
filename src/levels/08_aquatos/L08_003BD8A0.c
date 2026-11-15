#include "common.h"

/* localdecomp:start func_L08_003BD8A0 */
#include "vu0.h"

typedef struct C_003BD8A0 {
    u8 pad0[0x24];
    f32 f24;
} C_003BD8A0;

typedef struct M_003BD8A0 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[4];
    C_003BD8A0 *p24;
    u8 pad28[4];
    f32 scale;
} M_003BD8A0;

extern void func_003C4C18(void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L08_003BD8A0(M_003BD8A0 *m, s32 n) {
    vu0_v4 v;
    vu0_v4 off;
    f32 s;

    s = m->scale / m->p24->f24;
    qzero(&off);
    func_003C4C18(&off, 0.3f);
    off.z = (f32)n * -0.035f + -0.9f;
    func_0038CE20(&off, &off, s);
    vec_add_ba(&v, &m->pos, &off);
    func_003A52A0(0, 0, (u8 *)m);
    func_L01_003303B8(&v, 0, 0, 0, 0, 2, 5, 0, s * 0.2f + func_003824E0(0.0f, 0.3f), 0.0f, 0.0f, 0.0f,
        0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x40707F, 0x3070, 0, 0, 0, 0, 0x7F60A0FF, 0x28403000, 0, 0);
}
/* localdecomp:end func_L08_003BD8A0 */

INCLUDE_ASM("asm/levels", func_L08_003BDA50);
