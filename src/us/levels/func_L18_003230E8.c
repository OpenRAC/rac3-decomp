#include "common.h"

/* NTSC-U counterpart of func_L18_00323760 (src/levels/shared/L18_00322F80.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00323278;
typedef struct { u8 p0[0x10]; V_00323278 pos; } H_00323278;
typedef struct { u8 p0[0x18]; H_00323278 *w18; u8 p1C[4]; V_00323278 v20; u8 p30[0x10]; V_00323278 v40; } T_00323278;
extern T_00323278 D_L18_001EAB00;
extern s32 func_L18_00322B10(s32, void *, void *, s32, void *, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_0040C260(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L18_00322918(u8 *, void *, void *, f32, f32);
extern void func_003BD360(void *);
#include "vu0.h"
typedef struct { u8 p0[0x38]; f32 f38; } P_00323518;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; P_00323518 *vars; } M_00323518;
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L18_003230E8 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0xAA]; s16 xAA; } T_00323760;
typedef struct { u8 pad0[0x24]; f32 x24; } U_00323760;
typedef struct {
    u8 pad0[0x10]; u128_t x10; u128_t x20; T_00323760 *x30; u8 x34[4]; f32 x38; f32 x3C; f32 x40; f32 x44;
    u8 pad48[0x5C - 0x48]; f32 x5C; s32 x60;
} M_00323760;
typedef struct {
    u8 pad0[0x10]; u128_t x10; u8 pad20[4]; U_00323760 *x24; u8 pad28[4]; f32 x2C; u8 pad30; u8 x31; u8 pad32[0x68 - 0x32];
    M_00323760 *x68; u8 pad6C[0xAA - 0x6C]; u16 xAA; u8 padAC[0xF4 - 0xAC]; f32 xF4; f32 xF8;
} O_00323760;
typedef struct {
    u128_t x0; void *x10; s32 x14; u8 x18; u8 x19; u16 x1A; f32 x1C; s32 x20; u8 pad24[4]; s32 x28; u8 pad2C[4];
} S_00323760;
typedef struct { u8 pad0[0x18]; T_00323760 *x18; s32 x1C; u128_t x20; u8 pad30[0x10]; u128_t x40; } G_00323760;
__asm__(".extern D_L18_001DC7E4, 4");
__asm__(".extern D_L18_001DC7E8, 4");
__asm__(".extern D_L18_001DC7EC, 4");
__asm__(".extern D_L18_001DC7F0, 4");
extern f32 D_L18_001DC7E4;
extern f32 D_L18_001DC7E8;
extern f32 D_L18_001DC7EC;
extern f32 D_L18_001DC7F0;
extern void func_L18_00323498(u8 *);
extern void func_L01_004026A0(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_L18_00454598(f32, f32, f32, f32, f32, f32 *);
extern f32 func_003887A0(void *);
extern f32 func_00388770(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388880(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BD360(void *);
extern s32 func_00388398(void *);

void func_L18_003230E8(O_00323760 *o) {
    M_00323760 *m;
    u128_t ray[2];
    vu0_v4 v;
    S_00323760 s;
    vu0_v4 w;
    s32 hit;
    T_00323760 *t;
    T_00323760 *t2;
    u128_t *src;
    vu0_v4 *pw;
    u128_t *pos;
    f32 k;

    if (o == 0 || (m = o->x68) == 0) {
        return;
    }
    o->x2C += (o->x24->x24 - o->x2C) * 0.05f;
    m->x38 += (D_L18_001DC7E4 - m->x38) * 0.1f;
    func_L01_004026A0(func_L18_00323498, o);
    vec_sub_ba(&v, &m->x10, &o->x10);
    o->xF8 = func_L18_00454598(o->xF8, func_00388A28(v.x, v.y),
                               D_L18_001DC7EC, D_L18_001DC7E8, D_L18_001DC7F0, &m->x3C);
    o->xF4 = func_L18_00454598(o->xF4, -func_00388A28(func_003887A0(&v), v.z),
                               D_L18_001DC7EC, D_L18_001DC7E8, D_L18_001DC7F0, &m->x40);
    vec_sub_ab(&v, &m->x10, &m->x20);
    if (func_00388770(&v) < 6.0f) {
        m->x44 *= func_00388770(&v) / 6.0f;
    } else {
        m->x44 += 0.1f;
    }
    func_0037E4B8(&ray[1], m->x38, o->xF8, -o->xF4);
    if (o->x31 != 0) {
        func_L18_00322EB0((M_00323518 *)o, (vu0_v4 *)&ray[1]);
    }
    pos = &o->x10;
    ray[0] = o->x10;
    vec_add_ab(&m->x20, &m->x20, &ray[1]);
    o->x10 = m->x20;
    if (((f32 *)&o->x10)[0] < 0.0f || ((f32 *)&o->x10)[1] < 0.0f || ((f32 *)&o->x10)[2] < 0.0f) {
        func_003BD360(o);
        return;
    }
    s.x10 = o;
    s.x14 = 0x1030001;
    s.x1C = m->x5C;
    s.x20 = 1;
    s.x0 = ray[1];
    func_00388880(&s, &s, 1.0f);
    ((f32 *)&s.x0)[2] = 1.0f;
    ((f32 *)&s.x0)[3] = 5627.9248f;
    s.x18 = 3;
    s.x19 = 3;
    s.x1A = o->xAA;
    s.x28 = m->x60;
    hit = func_L18_00322B10(-1, ray, pos, 0, m->x30, (s32)&s);
    if (hit != 0) {
        t = ((G_00323760 *)&D_L18_001EAB00)->x18;
        if ((t != 0 && t != m->x30 && t->xAA != 0x15A5) || ((G_00323760 *)&D_L18_001EAB00)->x1C > 0) {
            src = &((G_00323760 *)&D_L18_001EAB00)->x20;
            o->x10 = *src;
            func_0037E4B8(&ray[1], m->x38, o->xF8, -o->xF4);
            pw = &w;
            func_L01_0040C260((f32 *)pw, (f32 *)&ray[1], (f32 *)&((G_00323760 *)&D_L18_001EAB00)->x40);
            func_00388830(pw, pw, 0.033333335f);
            k = 1.5f;
            t2 = ((G_00323760 *)&D_L18_001EAB00)->x18;
            if (t2 != 0 && t2 != m->x30 && t2->xAA != 0x15A5) {
                k = 2.5f;
            }
            func_L18_00322918((u8 *)m->x30, pw, pos, k, m->x5C);
            func_003BD360(o);
            return;
        }
    }
    if (func_00388398(m->x34) != 0) {
        func_003BD360(o);
    }
}
/* localdecomp:end func_L18_003230E8 */
