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

/* localdecomp:start func_L08_003BDA50 */
#include "vu0.h"

typedef vu0_v4 V_003BDA50;
typedef struct { char p0[0x10]; V_003BDA50 pos; char p20[4]; char *classdata; float p28, scale; } M_003BDA50;
extern s32 func_00382468(s32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_003BDA50(M_003BDA50 *m, f32 spread, f32 height) {
    V_003BDA50 point, velocity, center;
    f32 scale;
    s32 i = 0;
    s32 random;

    scale = m->scale / *(f32 *)(m->classdata + 0x24);
    qzero(&center);
    center.z += scale * height;
    vec_add_ab(&center, &m->pos, &center);
    do {
        random = func_00382468(50);
        qzero(&point);
        func_003C4C18(&point, scale * spread);
        vec_add_ab(&point, &center, &point);
        qzero(&velocity);
        func_003C4C18(&velocity, 0.004f);
        velocity.z += func_003824E0(0.0f, 0.010000001f);
        func_L01_004637C8(&point, &velocity, 0x70507080, 0, func_00382468(125) + 125,
                          (s32)(scale * (random + 100)), (s32)(scale * (random + 220)), i < 21);
        i++;
    } while (i < 35);
}
/* localdecomp:end func_L08_003BDA50 */
