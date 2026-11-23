#include "common.h"

/* NTSC-U counterpart of func_L18_00323278 (src/levels/shared/L18_00322F80.c) */
/* localdecomp:start func_L18_00322C10 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00323278;
typedef struct {
    u8 p0[0x10]; V_00323278 v10; V_00323278 v20; u8 *w30; s32 w34; f32 f38; f32 f3C; f32 f40; f32 f44;
    f32 f48; f32 f4C; f32 f50; f32 f54; u8 p58[4]; f32 f5C; s32 w60; s32 w64;
} P_00323278;
typedef struct { u8 p0[0x24]; f32 f24; } C_00323278;
typedef struct {
    u8 p0[0x10]; V_00323278 pos; u8 b20; u8 p21[3]; C_00323278 *cls; u8 p28[4]; f32 f2C; u8 b30; u8 b31; s16 h32;
    u8 p34[0x34]; P_00323278 *vars; u8 p6C[0x88]; f32 fF4; f32 fF8;
} M_00323278;
typedef struct { u8 p0[0x10]; V_00323278 pos; } H_00323278;
typedef struct { u8 p0[0x25C0]; H_00323278 *hero; } G_00323278;
typedef struct { u8 p0[0x18]; H_00323278 *w18; u8 p1C[4]; V_00323278 v20; u8 p30[0x10]; V_00323278 v40; } T_00323278;
extern G_00323278 D_001A4BE0;
extern T_00323278 D_L18_001EAB00;
extern M_00323278 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003C26C8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L18_00322B10(s32, void *, void *, s32, void *, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_0040C260(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L18_00322918(u8 *, void *, void *, f32, f32);
extern void func_003BD360(void *);

M_00323278 *func_L18_00322C10(u8 *owner, V_00323278 *at, V_00323278 *to, s32 a3, s32 t0, f32 f12, f32 f13, f32 f14, f32 f15) {
    M_00323278 *m;
    P_00323278 *p;
    V_00323278 v;
    V_00323278 dir;
    V_00323278 vel;
    T_00323278 *t;

    m = func_003BCFB0(0x15A5, 0x80);
    if (m == 0) {
        return 0;
    }
    m->b30 = 0xFF;
    m->fF8 = f12;
    m->fF4 = f13;
    m->h32 = 0xFF;
    m->b31 = 1;
    m->b20 = 0;
    m->f2C = m->cls->f24 * 0.25f;
    p = m->vars;
    p->w30 = owner;
    p->w64 = t0;
    m->pos = *at;
    p->v20 = *at;
    p->v10 = *to;
    p->f50 = func_0037E250(-0.0064466665f, 0.0064466665f);
    p->f54 = func_0037E250(-0.01604f, 0.01604f);
    p->f38 = f14;
    p->f5C = f15;
    p->f3C = 0;
    p->f40 = 0;
    p->f44 = 0;
    p->f48 = func_0037E250(-0.785398f, 0.785398f);
    p->f4C = func_0037E250(-0.785398f, 0.785398f);
    p->w60 = a3;
    p->w34 = 0xFA;
    func_003C26C8(m);
    func_0039FE80(0, 0, m);
    v = D_001A4BE0.hero->pos;
    v.z = at->z;
    if (func_L18_00322B10(-1, &v, at, 0, p->w30, 0) != 0) {
        t = &D_L18_001EAB00;
        if (t->w18 == 0 || (t->w18 != D_001A4BE0.hero && t->w18 != (H_00323278 *)p->w30)) {
            m->pos = t->v20;
            func_0037E4B8(&dir, p->f38, m->fF8, -m->fF4);
            func_L01_0040C260(&vel, &dir, &t->v40);
            func_00388830(&vel, &vel, 0.033333335f);
            func_L18_00322918((u8 *)m, &vel, 0, 0.0f, 0.0f);
            func_003BD360(m);
            return 0;
        }
    }
    return m;
}
/* localdecomp:end func_L18_00322C10 */
