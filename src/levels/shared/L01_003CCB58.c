#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[16];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
} M3C7568;
typedef struct Moby Moby;
typedef struct {
    char pad0[0x550];
    Moby *child;
} Vars;
struct Moby {
    char pad0[0x42];
    unsigned char anim;
    char pad43[0x48 - 0x43];
    float animSpeed;
    char pad4C[0x68 - 0x4C];
    Vars *vars;
};
typedef int u128_3C9E88 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; u128_3C9E88 pos; u8 pad20[0xE0]; } M_3C9E88;
typedef struct { u8 pad[0x30]; u128_3C9E88 x30; u8 pad40[0x40]; } E_3C9E88;
typedef struct { u8 pad[0x60]; s32 x60; s32 x64; } T_3C9E88;
typedef struct { u8 pad[0x47C]; s32 x47C; u8 pad480[0x10]; u8 x490; u8 x491; u8 pad492[0x4A0 - 0x492]; u128_3C9E88 x4A0; } V_3C9E88;
typedef struct O_3C9E88 O_3C9E88;
struct O_3C9E88 { u8 pad[0x20]; u8 x20; u8 pad21[0x68 - 0x21]; void *x68; u8 pad6C[0xB8 - 0x6C]; O_3C9E88 *xB8; u8 xBC; };
typedef struct M_3CC220 M_3CC220;
typedef struct {
    u8 pad0[0xB0];
    u8 bB0[0xC4 - 0xB0];
    M_3CC220 *tgt;
    u8 padC8[0xD4 - 0xC8];
    f32 fD4;
} V_3CC220;
struct M_3CC220 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3CC220 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
};
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x30 - 0x1C];
} L_3CC220;
typedef struct {
    u8 pad0[0x18];
    M_3CC220 *m18;
} G_3CC220;
typedef struct {
    u8 pad0[44];
    s32 w2C;
    u8 pad1[64 - 48];
    s32 w40;
} Obj3CEDD0;
typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby3CEDD0;
typedef struct {
    void (*f0)(Moby3CEDD0 *);
    s32 pad;
    s32 (*f8)(Moby3CEDD0 *);
} Vt3CEDD0;
typedef int s128 __attribute__((mode(TI)));
typedef struct S_3CF0C0o {
    u8 pad0[0x10];
    s128 x10;
    u8 x20;
    u8 pad21[0xAA - 0x21];
    s16 xAA;
    u8 padac[0xF8 - 0xAC];
    f32 xF8;
    u8 padfc[4];
} S_3CF0C0o;
typedef struct S_3CF0C0f {
    u8 pad0[8];
    s32 (*x8)(S_3CF0C0o *);
    u8 padc[8];
    void (*x14)(S_3CF0C0o *, s32, s128 *, f32 *);
} S_3CF0C0f;
typedef struct S_3CF0C0p {
    u8 pad0[0x28];
    s32 x28;
    s32 x2C;
    u8 pad30[0x10];
    s32 x40;
    u8 pad44[0xE8 - 0x44];
    s32 xE8;
    s32 xEC;
} S_3CF0C0p;

typedef struct {
    u8 pad0[0xF8];
    f32 xF8;
} Self_003D0850;
typedef struct {
    u8 pad0[0x2C];
    s32 w2C;
    u8 pad30[0x40 - 0x30];
    s32 w40;
    u8 pad44[0xBC - 0x44];
    s32 xBC[4];
    u8 padCC[0x130 - 0xCC];
    f32 x130;
} Obj_003D0850;
typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby_003D0850;
typedef struct {
    void (*f0)(Moby_003D0850 *);
    void (*f4)(Moby_003D0850 *, f32, f32, f32);
    s32 (*f8)(Moby_003D0850 *);
} Vt_003D0850;

typedef struct {
    u8 pad0[0x68];
    u8 *vars;
} O_003CB9B0;
typedef struct {
    u8 pad0[0x491];
    u8 x491;
    u8 pad492[0x550 - 0x492];
    u8 *child;
} V_003CB9B0;

/* localdecomp:start func_L01_003CCB58 */
typedef int Q_3CCB58 __attribute__((mode(TI)));
extern void func_L01_003CCED8_003CCB58(M_3CC220 *, void *);
extern int func_0038CAD0(void *);
extern void func_003C2880(s32);
extern void func_L01_003CD068_003CCB58(u8 *);
extern void func_L01_00404A10_003CCB58(void *, void *);

void func_L01_003CCB58(M_3CC220 *m) {
    u8 *v = (u8 *)m->vars;
    Q_3CCB58 old;
    switch (m->b20) {
    case 0:
        m->b20 = 1;
    case 1: {
        u8 *pos = m->pos;
        old = *(Q_3CCB58 *)pos;
        vec_add_ba(pos, v, pos);
        func_L01_003CCED8_003CCB58(m, &old);
        if (func_0038CAD0(v + 0x10)) {
            m->b20 = 2;
        }
        break;
    }
    case 2:
        func_003C2880((s32)m);
        return;
    }
    func_L01_00404A10_003CCB58(func_L01_003CD068_003CCB58, m);
}
/* localdecomp:end func_L01_003CCB58 */

/* localdecomp:start func_L01_003CCC20 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CCC20;
typedef struct { V4_3CCC20 dir; s32 x10; s32 x14; s32 x18; f32 x1C; void *x20; s32 x24; } D_3CCC20;
typedef struct {
    u8 pad0[0x10]; V4_3CCC20 pos; u8 x20; u8 pad21[0xF]; u8 x30; u8 pad31; s16 x32; u8 pad34[0x34];
    D_3CCC20 *x68; u8 pad6C[0x54]; V4_3CCC20 xC0; V4_3CCC20 xD0; V4_3CCC20 xE0;
} M_3CCC20;
__asm__(".extern D_L01_001DEF90, 4");
__asm__(".extern D_L01_001DEF94, 4");
__asm__(".extern D_L01_001DEF98, 4");
__asm__(".extern D_L01_001DEF9C, 4");
__asm__(".extern D_L01_001DEFA0, 4");
__asm__(".extern D_L01_001DEFC0, 4");
__asm__(".extern D_L01_001DEFE0, 4");
__asm__(".extern D_L01_001DF000, 4");
extern f32 D_L01_001DEF90;
extern f32 D_L01_001DEF94;
extern f32 D_L01_001DEF98;
extern f32 D_L01_001DEF9C;
extern s32 D_L01_001DEFA0;
extern s32 D_L01_001DEFA4;
extern f32 D_L01_001DEFC0;
extern f32 D_L01_001DEFE0;
extern s32 D_L01_001DF000;
extern u8 D_L01_001D66B0[8];
extern void func_003C5180(void *, void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_00470C78(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 a3, s32 spin,
                             void *velocity, s32 t2, s32 t3, s16 arg8, s32 arg9);

M_3CCC20 *func_L01_003CCC20(void *owner, u8 *pos, V4_3CCC20 *dir, f32 f, s32 a3) {
    V4_3CCC20 m;
    V4_3CCC20 v;
    V4_3CCC20 r;
    M_3CCC20 *p;
    D_3CCC20 *d;
    s32 i;

    func_003C5180(pos, &m, 1);
    p = (M_3CCC20 *)func_003C24B0(0x1B33, 0x80);
    if (p != 0) {
        d = p->x68;
        d->x10 = 0x43;
        p->x30 = 0xFF;
        p->x32 = 0xFF;
        p->x20 = 0;
        p->pos = *(V4_3CCC20 *)pos;
        d->dir = *dir;
        d->x1C = f;
        d->x18 = 0;
        d->x14 = 0;
        func_0038CF68((f32 *)&v, dir, 1.0f);
        p->xC0 = v;
        func_0038CE90(&p->xD0, &p->xC0, &m);
        func_0038CF68((f32 *)&p->xD0, &p->xD0, 1.0f);
        func_0038CE90(&p->xE0, &p->xD0, &p->xC0);
        p->xC0.w = p->xD0.w = p->xE0.w = 0.0f;
        d->x20 = owner;
        d->x24 = a3;
        for (i = 0; i < 10; i++) {
            func_00382580(&r, 0.100000009f, 0.200000018f);
            func_L01_00474078(pos, &r, (func_00382498(10, 0x19) * 5 + 2) / 6, D_L01_001DEF90, D_L01_001DEF94,
                              D_L01_001DEF98, D_L01_001DEF9C, D_L01_001DEFA0, D_L01_001DEFA4, 0, 0);
        }
        for (i = 0; i < 4; i++)
            func_L01_0046B458(pos, 0xC, (&D_L01_001DEFC0)[i], (&D_L01_001DEFE0)[i], (&D_L01_001DEFA0)[i],
                              2, 1, D_L01_001D66B0, 0.0f, 1);
        for (; i < 7; i++)
            func_L01_00470C78(pos, 0x11, (&D_L01_001DEFC0)[i], (&D_L01_001DEFE0)[i], (&D_L01_001DEFA0)[i], 2, 2,
                              D_L01_001D66B0, 0, (&D_L01_001DF000)[i - 4], 6, 1);
    }
    return p;
}
/* localdecomp:end func_L01_003CCC20 */

/* localdecomp:start func_L01_003CCED8 */
__asm__(".extern D_L01_001DF00C_003CCED8, 4");
__asm__(".extern D_L01_001DF010_003CCED8, 4");
extern f32 D_L01_001DF00C_003CCED8;
extern f32 D_L01_001DF010_003CCED8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    M_3CC220 *tgt;
    s32 w24;
} V_3CCED8_003CCED8;
extern M_3CC220 *D_L01_001EAA18_003CCED8[];
extern G_3CC220 D_L01_001EAA00_003CCED8;
extern void func_L01_004CB320_003CCED8(void);
extern void func_L01_004CB358_003CCED8(void);
extern int func_L01_003FA5F0_003CCED8(void *, void *, int, M_3CC220 *, int);
extern void func_L01_0040E620_003CCED8(f32 *, V_3CCED8_003CCED8 *, f32);
extern void func_L01_00446A70_003CCED8(M_3CC220 *, M_3CC220 *, int, void *, f32 *, f32);
extern void func_L01_003CD248_003CCED8(void *, int, int, int, M_3CC220 *);

void func_L01_003CCED8(M_3CC220 *m, void *a1) {
    f32 buf[4];
    void *pos = m->pos;
    V_3CCED8_003CCED8 *v = (V_3CCED8_003CCED8 *)m->vars;
    M_3CC220 *p;
    int r;
    f32 f;

    func_L01_004CB320_003CCED8();
    r = func_L01_003FA5F0_003CCED8(a1, pos, 0, m, 0);
    if (r != 0) {
        p = D_L01_001EAA18_003CCED8[0];
        if (p != 0 && p->hAA == 6253 && p->b20 != 2 && p->b20 != 5) {
            p->b20 = 4;
        }
    }
    func_L01_004CB358_003CCED8();
    if (r == 0) {
        return;
    }
    if (D_L01_001EAA00_003CCED8.m18 != 0) {
        if (D_L01_001EAA00_003CCED8.m18 != v->tgt && (D_L01_001EAA00_003CCED8.m18->h34 & 0x4000)) {
            f = D_L01_001DF00C_003CCED8;
            if (v->w24 == 0) {
                f *= 0.5f;
            }
            func_L01_0040E620_003CCED8(buf, v, f);
            buf[2] = D_L01_001DF010_003CCED8;
            buf[3] = 5627.9248046875f;
            func_L01_00446A70_003CCED8(D_L01_001EAA00_003CCED8.m18, m, 0x10001, m->pos, buf, v->f1C);
            func_L01_003CD248_003CCED8(m->pos, 10, 2, 1, m);
        }
        if (D_L01_001EAA00_003CCED8.m18 != 0) {
            m->b20 = 2;
            return;
        }
    }
    func_L01_003CD248_003CCED8(m->pos, 15, 5, 0, m);
    m->b20 = 2;
}
/* localdecomp:end func_L01_003CCED8 */

/* localdecomp:start func_L01_003CD068 */
typedef int u128_t_3CD068 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CD068;
__asm__(".extern D_L01_001DF028, 4");
__asm__(".extern D_L01_001DF018, 4");
__asm__(".extern D_L01_001DF058, 4");
__asm__(".extern D_L01_001DF068, 4");
__asm__(".extern D_L01_001DF038, 4");
__asm__(".extern D_L01_001DF048, 4");
extern u32 D_L01_001DF028;
extern u32 D_L01_001DF02C;
extern u32 D_L01_001DF030;
extern f32 D_L01_001DF018;
extern f32 D_L01_001DF01C;
extern f32 D_L01_001DF020;
extern u32 D_L01_001DF058;
extern u32 D_L01_001DF05C;
extern u32 D_L01_001DF060;
extern s32 D_L01_001DF068;
extern s32 D_L01_001DF06C;
extern s32 D_L01_001DF070;
extern f32 D_L01_001DF038;
extern f32 D_L01_001DF03C;
extern f32 D_L01_001DF040;
extern f32 D_L01_001DF048;
typedef struct { f32 a; f32 b; } P_3CD068;
__asm__(".extern D_L01_001DF04C, 16");
extern P_3CD068 D_L01_001DF04C;
extern f32 func_0038CEA8(void *);
extern f32 func_00382538(void);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040A4A0(void *, void *, s32, u32, s32, s32, f32, f32, f32);

void func_L01_003CD068(u8 *self) {
    u8 *d;
    V4_3CD068 v;

    *(u128_t_3CD068 *)&v = 0;
    d = *(u8 **)(self + 0x68);
    v.w = 1.0f;
    *(f32 *)(d + 0x14) = *(f32 *)(d + 0x14) - 0.1f;
    if (*(f32 *)(d + 0x14) <= -8.0f)
        *(f32 *)(d + 0x14) = *(f32 *)(d + 0x14) + 8.0f;
    *(f32 *)(d + 0x18) = *(f32 *)(d + 0x18) + func_0038CEA8(d);
    func_003D9508(self + 0x10, 0x31, D_L01_001DF028, 1, D_L01_001DF018, 0.0f, func_00382538());
    func_003D9508(self + 0x10, 0x31, D_L01_001DF02C, 0, D_L01_001DF01C, 0.0f, func_00382538());
    func_003D9508(self + 0x10, 0x2F, D_L01_001DF030, 1, D_L01_001DF020, 0.0f, func_00382538());
    if (1.0f < *(f32 *)(d + 0x18)) {
        func_L01_0040A4A0(self, &v, 1, D_L01_001DF058, D_L01_001DF068, 0x17, D_L01_001DF038, D_L01_001DF048, *(f32 *)(d + 0x14));
        func_L01_0040A4A0(self, &v, 1, D_L01_001DF05C, D_L01_001DF06C, 0x17, D_L01_001DF03C, D_L01_001DF04C.a, *(f32 *)(d + 0x14));
        func_L01_0040A4A0(self, &v, 1, D_L01_001DF060, D_L01_001DF070, 0x17, D_L01_001DF040, D_L01_001DF04C.b, *(f32 *)(d + 0x14));
    }
}
/* localdecomp:end func_L01_003CD068 */

/* localdecomp:start func_L01_003CD248 */
typedef int u128_t_3C41F0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C41F0;
__asm__(".extern D_L01_001DF078, 4");
__asm__(".extern D_L01_001DF080, 4");
__asm__(".extern D_L01_001DF084, 4");
__asm__(".extern D_L01_001DF088, 4");
__asm__(".extern D_L01_001DF08C, 4");
__asm__(".extern D_L01_001DF090, 4");
__asm__(".extern D_L01_001DF094, 4");
__asm__(".extern D_L01_001DF098, 4");
extern s32 D_L01_001DF078;
extern s32 D_L01_001DF07C;
extern f32 D_L01_001DF080;
extern f32 D_L01_001DF084;
extern f32 D_L01_001DF088;
extern f32 D_L01_001DF08C;
extern f32 D_L01_001DF090;
extern f32 D_L01_001DF094;
extern f32 D_L01_001DF098;
extern V4_3C41F0 D_L01_001E29C0;
extern V4_3C41F0 D_001A4EC0;
extern u8 *D_L01_00221098[];
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, f32, void *, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);

void func_L01_003CD248(void *p, s32 n2, s32 n1, s32 flag, u8 *obj) {
    V4_3C41F0 *pos = p;
    V4_3C41F0 axis;
    V4_3C41F0 vel;
    V4_3C41F0 dir;
    V4_3C41F0 a;
    V4_3C41F0 c;
    V4_3C41F0 d;
    s32 spin;
    s32 k;
    s32 i, j;
    s32 one;
    s32 life;
    f32 sz;
    f32 ang;
    f32 el;
    u8 *r;
    u8 *t;
    u8 *q;

    *(u128_t_3C41F0 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    vec_sub_ab(&dir, &D_L01_001E29C0, pos);
    for (i = 0; i < n1; i++) {
        {
            a = *pos;
            a.x += func_L01_00443A18(0.0f, 0.05f);
            a.y += func_L01_00443A18(0.0f, 0.05f);
            a.z += func_L01_00443A18(0.0f, 0.05f);
            spin = func_00382468(2);
            if (spin == 0)
                spin--;
            func_0038D890(&vel, func_003824E0(-1.0471976f, 1.0471976f), &dir, &axis);
            func_0038CF68((f32 *)&vel, &vel, func_003824E0(D_L01_001DF080, D_L01_001DF084) * 0.020000001f);
            vel.z = func_003824E0(D_L01_001DF088, D_L01_001DF08C) * 0.020000001f;
            func_L01_0046B458((u8 *)&a, 0x32, func_003824E0(D_L01_001DF094, D_L01_001DF098), D_L01_001DF098,
                              D_L01_001DF078, 0, spin, &vel, D_L01_001DF090 * 1.44f, 0);
        }
    }
    for (j = 0; j < n2; j++) {
        {
            func_0038CE20(&a, &D_001A4EC0, -(func_003824E0(0.1f, 1.5f) * 0.020000001f));
            k = (s32)func_L01_00443A18(1.0f, 2.0f);
            sz = func_003824E0(0.15f, 0.35f) * 210000.0f;
            c.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
            c.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
            c.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
            r = func_L01_004669B0(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 0x4B;
                t = r + 0x20;
                r[0x3] = 0x44;
                r[0x9] = 0x44;
                *(f32 *)(t + 0x1C) = 4.0f;
                *(s32 *)(t + 0x4) = 3;
                t[0xA] = 0x30;
                t[0xB] = r[0xA];
            }
        }
    }
    one = 1;
    for (j = 0; j < 2; j++) {
        el = func_003824E0(-0.9599311f, -1.3962634f);
        ang = func_00382538();
        func_00382760(&a, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
        vec_sub_ab(&c, &D_L01_001E29C0, pos);
        func_0038CF68((f32 *)&c, &c, 0.3f);
        vec_add_ba(pos, pos, &c);
        sz = func_003824E0(20000.0f, 75000.0f);
        d.x = pos->x + func_L01_00443A18(0.0f, 0.02f);
        d.y = pos->y + func_L01_00443A18(0.0f, 0.02f);
        d.z = pos->z + func_L01_00443A18(0.01f, 0.05f);
        if (flag)
            q = func_L01_004708C8(&d, &a, D_L01_001DF078, D_L01_001DF07C, sz, 0.1f, func_00382498(8, 0x11), 1, 1, -1, one);
        else
            q = func_L01_004708C8(&d, &a, D_L01_001DF078, D_L01_001DF07C, sz, 0.1f, func_00382498(0x15, 0x32), 1, 1, -1, one);
        if (q != 0)
            q[2] = D_L01_00221098[0x16C / 4][1];
    }
}
/* localdecomp:end func_L01_003CD248 */

/* localdecomp:start func_L01_003CD778 */
typedef int Q_3CD778 __attribute__((mode(TI)));
extern void func_L01_003CDDD8(void *, int, int, int, M_3CC220 *, int);
extern void func_L01_003CDB08(M_3CC220 *, int);
extern void func_L01_003CE2E8(u8 *);
extern int func_0038CAD0(void *);
extern void func_L01_003CDCE8(u8 *);
extern void func_L01_00404A10_003CD778(void *, void *);

void func_L01_003CD778(M_3CC220 *m) {
    V_3CC220 *v = m->vars;
    Q_3CD778 old;
    switch (m->b20) {
    case 0:
        m->b20 = 1;
    case 1: {
        u8 *pos = m->pos;
        old = *(Q_3CD778 *)pos;
        vec_add_ba(pos, v->bB0, pos);
        func_L01_003CDB08(m, (int)&old);
        func_L01_003CE2E8((u8 *)m);
        if (func_0038CAD0((u8 *)v + 0xD0)) {
            m->b20 = 2;
            func_L01_003CDDD8(pos, 20, 5, 0, m, v->tgt != 0);
        }
        break;
    }
    case 2:
        func_003C2880((s32)m);
        return;
    }
    func_L01_00404A10_003CD778(func_L01_003CDCE8, m);
}
/* localdecomp:end func_L01_003CD778 */

/* localdecomp:start func_L01_003CD878 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CD878;
typedef struct {
    u8 pad0[0x20];
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    u8 pad30[0x80];
    V4_3CD878 qB0;
    void *pC0;
    s32 wC4;
    s32 wC8;
    s32 wCC;
    s32 wD0;
    f32 fD4;
} D_3CD878;
typedef struct {
    u8 pad0[0x10];
    V4_3CD878 q10;
    u8 x20;
    u8 pad21[0xF];
    u8 x30;
    u8 pad31;
    s16 x32;
    u8 pad34[0x34];
    D_3CD878 *x68;
    u8 pad6C[0x54];
    V4_3CD878 qC0;
    V4_3CD878 vD0;
    V4_3CD878 vE0;
} M_3CD878;

__asm__(".extern D_L01_001DF0F0, 4");
__asm__(".extern D_L01_001DF110, 4");
__asm__(".extern D_L01_001DF130, 4");
__asm__(".extern D_L01_001DF150, 4");
__asm__(".extern D_L01_001DF0B0, 4");
__asm__(".extern D_L01_001DF0A0, 4");
__asm__(".extern D_L01_001DF0A4, 4");
__asm__(".extern D_L01_001DF0A8, 4");
extern s32 D_L01_001DF0F0;
extern f32 D_L01_001DF110;
extern f32 D_L01_001DF130;
extern s32 D_L01_001DF150;
extern s32 D_L01_001DF0B0;
extern s32 D_L01_001DF0A0;
extern s32 D_L01_001DF0A4;
extern s32 D_L01_001DF0A8;
extern u8 D_L01_001D66B0[8];
extern void func_003C5180(void *, void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_00470C78(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 a3, s32 spin,
                             void *velocity, s32 t2, s32 t3, s16 arg8, s32 arg9);
extern void func_L01_0040C7A0(void *, void *);

M_3CD878 *func_L01_003CD878(s32 owner, V4_3CD878 *pos, V4_3CD878 *dir, s32 a3, f32 f, s32 idx) {
    V4_3CD878 m;
    V4_3CD878 v;
    M_3CD878 *p;
    D_3CD878 *d;
    s32 i;

    func_003C5180(pos, &m, 1);
    p = (M_3CD878 *)func_003C24B0(0x1B3C, 0x100);
    if (p != 0) {
        d = p->x68;
        if (idx == -1) {
            d->wD0 = (D_L01_001DF0A8 * 5 + 2) / 6;
        } else {
            d->wD0 = (idx * 5 + 2) / 6;
        }
        p->x30 = 0xFF;
        p->x32 = 0xFF;
        p->x20 = 0;
        p->q10 = *pos;
        d->qB0 = *dir;
        d->wC8 = a3;
        d->fD4 = f;
        d->wCC = 0;
        func_0038CF68((f32 *)&v, dir, 1.0f);
        p->qC0 = v;
        func_0038CE90(&p->vD0, &p->qC0, &m);
        func_0038CF68((f32 *)&p->vD0, &p->vD0, 1.0f);
        func_0038CE90(&p->vE0, &p->vD0, &p->qC0);
        p->qC0.w = p->vD0.w = p->vE0.w = 0.0f;
        d->wC4 = owner;
        for (i = 0; i < 4; i++) {
            func_L01_0046B458((u8 *)pos, 0xC, (&D_L01_001DF110)[i], (&D_L01_001DF130)[i], (&D_L01_001DF0F0)[i], 2, 1, D_L01_001D66B0, 0.0f, 1);
        }
        for (; i < 7; i++) {
            func_L01_00470C78((u8 *)pos, 0x11, (&D_L01_001DF110)[i], (&D_L01_001DF130)[i], (&D_L01_001DF0F0)[i], 2, 2, D_L01_001D66B0, 0, (&D_L01_001DF150)[i - 4], 6, 1);
        }
        d->pC0 = &D_L01_001DF0B0;
        d->w24 = d->w20 = D_L01_001DF0A0;
        d->w2C = d->w28 = D_L01_001DF0A4;
        func_L01_0040C7A0(d, &D_L01_001DF0B0);
    }
    return p;
}
/* localdecomp:end func_L01_003CD878 */

/* localdecomp:start func_L01_003CDB08 */





extern M_3CC220 *D_L01_001EAA18[];
extern G_3CC220 D_L01_001EAA00;
extern void func_0038CF68(f32 *, void *, f32);
extern void func_L01_00446760(L_3CC220 *, M_3CC220 *, int, f32 *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern int func_003D3CB0(int, void *, int, M_3CC220 *, L_3CC220 *);
extern void func_L01_00446978(M_3CC220 *, L_3CC220 *);
extern void func_L01_003CDDD8(void *, int, int, int, M_3CC220 *, int);

void func_L01_003CDB08(M_3CC220 *m, int a1) {
    f32 buf[4];
    L_3CC220 l;
    void *pos = m->pos;
    V_3CC220 *v = m->vars;
    M_3CC220 *p;
    int r;

    func_0038CF68(buf, v->bB0, 1.0f);
    func_L01_00446760(&l, m, 0x410001, buf, v->fD4);
    l.b18 = 5;
    l.h1A = m->hAA;
    l.b19 = 3;
    func_L01_004CB320();
    r = func_003D3CB0(a1, pos, 16, m, &l);
    if (r != 0) {
        p = D_L01_001EAA18[0];
        if (p != 0 && p->hAA == 6253 && p->b20 != 2 && p->b20 != 5) {
            p->b20 = 4;
        }
    }
    func_L01_004CB358();
    if (r == 0) {
        return;
    }
    if (D_L01_001EAA00.m18 != 0) {
        if (D_L01_001EAA00.m18 != v->tgt && (D_L01_001EAA00.m18->h34 & 0x4000)) {
            func_0038CF68(buf, v->bB0, 1.0f);
            func_L01_00446760(&l, m, 0x410001, buf, v->fD4);
            l.b18 = 5;
            l.b19 = 3;
            l.h1A = m->hAA;
            func_L01_00446978(D_L01_001EAA00.m18, &l);
            func_L01_003CDDD8(m->pos, 30, 10, 1, m, v->tgt != 0);
        }
        if (D_L01_001EAA00.m18 != 0) {
            m->b20 = 2;
            return;
        }
    }
    func_L01_003CDDD8(m->pos, 20, 5, 0, m, v->tgt != 0);
    m->b20 = 2;
}
/* localdecomp:end func_L01_003CDB08 */

/* localdecomp:start func_L01_003CDCE8 */
__asm__(".extern D_L01_001DF160, 8");
__asm__(".extern D_L01_001DF170, 8");
__asm__(".extern D_L01_001DF180, 8");
__asm__(".extern D_L01_001DF190, 8");
extern f32 D_L01_001DF160[2];
extern s32 D_L01_001DF170[2];
extern s32 D_L01_001DF180[2];
extern s32 D_L01_001DF190[2];
extern f32 func_00382538(void);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040C948(u8 *, s32);

void func_L01_003CDCE8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 f = *(f32 *)(s + 0xCC) - 0.1f;
    s32 i;
    *(f32 *)(s + 0xCC) = f;
    if (f <= -8.0f) {
        *(f32 *)(s + 0xCC) = f + 8.0f;
    }
    for (i = 0; i < 3; i++) {
        func_003D9508(a0 + 0x10, D_L01_001DF180[i], D_L01_001DF170[i], D_L01_001DF190[i], D_L01_001DF160[i], 0.0f, func_00382538());
    }
    func_L01_0040C948(s, *(s32 *)(s + 0xC0));
}
/* localdecomp:end func_L01_003CDCE8 */

/* localdecomp:start func_L01_003CDDD8 */
typedef int u128_003CDDD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CDDD8;
__asm__(".extern D_L01_001DF1A0, 4");
__asm__(".extern D_L01_001DF1A8, 4");
__asm__(".extern D_L01_001DF1AC, 4");
__asm__(".extern D_L01_001DF1B0, 4");
__asm__(".extern D_L01_001DF1B4, 4");
__asm__(".extern D_L01_001DF1B8, 4");
__asm__(".extern D_L01_001DF1BC, 4");
__asm__(".extern D_L01_001DF1C0, 4");
__asm__(".extern D_L01_001DF1C4, 4");
__asm__(".extern D_L01_001DF1C8, 4");
__asm__(".extern D_L01_001DF1CC, 4");
__asm__(".extern D_L01_001DF1D0, 4");
__asm__(".extern D_L01_001DF1D4, 4");
extern s32 D_L01_001DF1A0;
extern s32 D_L01_001DF1A4;
extern s32 D_L01_001DF1A8;
extern f32 D_L01_001DF1AC;
extern f32 D_L01_001DF1B0;
extern f32 D_L01_001DF1B4;
extern f32 D_L01_001DF1B8;
extern f32 D_L01_001DF1BC;
extern f32 D_L01_001DF1C0;
extern f32 D_L01_001DF1C4;
extern f32 D_L01_001DF1C8;
extern f32 D_L01_001DF1CC;
extern f32 D_L01_001DF1D0;
extern f32 D_L01_001DF1D4;
extern V4_003CDDD8 D_L01_001E29C0_003CDDD8;
extern V4_003CDDD8 D_001A4EC0_003CDDD8;
extern u8 *D_L01_00221098[];
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, f32, void *, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);

void func_L01_003CDDD8(void *p, s32 n2, s32 n1, s32 flag, M_3CC220 *unused, s32 enable) {
    V4_003CDDD8 *pos = p;
    V4_003CDDD8 axis;
    V4_003CDDD8 vel;
    V4_003CDDD8 dir;
    V4_003CDDD8 a;
    V4_003CDDD8 c;
    V4_003CDDD8 d;
    s32 spin;
    s32 k;
    s32 i, j, m;
    s32 one;
    f32 sz;
    f32 ang;
    f32 el;
    u8 *r;
    u8 *t;
    u8 *q;

    *(u128_003CDDD8 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    vec_sub_ab(&dir, &D_L01_001E29C0_003CDDD8, pos);
    for (i = 0; i < n1; i++) {
        {
            a = *pos;
            a.x += func_L01_00443A18(0.0f, 0.05f);
            a.y += func_L01_00443A18(0.0f, 0.05f);
            a.z += func_L01_00443A18(0.0f, 0.05f);
            spin = func_00382468(2);
            if (spin == 0)
                spin--;
            func_0038D890(&vel, func_003824E0(-1.0471976f, 1.0471976f), &dir, &axis);
            func_0038CF68((f32 *)&vel, &vel, func_003824E0(D_L01_001DF1AC, D_L01_001DF1B0) * 0.020000001f);
            vel.z = func_003824E0(D_L01_001DF1B4, D_L01_001DF1B8) * 0.020000001f;
            func_L01_0046B458((u8 *)&a, 0x32, func_003824E0(D_L01_001DF1C0, D_L01_001DF1C4), D_L01_001DF1C4,
                              D_L01_001DF1A8, 0, spin, &vel, D_L01_001DF1BC * 1.44f, 0);
        }
    }
    for (j = 0; j < n2; j++) {
        {
            func_0038CE20(&a, &D_001A4EC0_003CDDD8, -(func_003824E0(0.1f, 1.5f) * 0.020000001f));
            k = (s32)func_L01_00443A18(1.0f, 2.0f);
            sz = func_003824E0(D_L01_001DF1D0, D_L01_001DF1D4) * 210000.0f;
            c.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
            c.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
            c.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
            r = func_L01_004669B0(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 0x4B;
                t = r + 0x20;
                r[0x3] = 0x44;
                r[0x9] = 0x44;
                *(f32 *)(t + 0x1C) = 4.0f;
                *(s32 *)(t + 0x4) = 3;
                t[0xA] = 0x30;
                t[0xB] = r[0xA];
            }
        }
    }
    if (enable != 0) {
        for (m = 0; m < 2; m++) {
            el = func_003824E0(-0.9599311f, -1.3962634f);
            ang = func_00382538();
            func_00382760(&a, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
            vec_sub_ab(&c, &D_L01_001E29C0_003CDDD8, pos);
            func_0038CF68((f32 *)&c, &c, 0.3f);
            vec_add_ba(pos, pos, &c);
            sz = func_003824E0(D_L01_001DF1C8, D_L01_001DF1CC);
            d.x = pos->x + func_L01_00443A18(0.0f, 0.02f);
            d.y = pos->y + func_L01_00443A18(0.0f, 0.02f);
            d.z = pos->z + func_L01_00443A18(0.01f, 0.05f);
            one = 1;
            if (flag)
                q = func_L01_004708C8(&d, &a, D_L01_001DF1A0, D_L01_001DF1A4, sz, 0.1f, func_00382498(8, 0x11), 1, 1, -1, one);
            else
                q = func_L01_004708C8(&d, &a, D_L01_001DF1A0, D_L01_001DF1A4, sz, 0.1f, func_00382498(0x15, 0x32), 1, 1, -1, one);
            if (q != 0)
                q[2] = D_L01_00221098[0x16C / 4][1];
        }
    }
}
/* localdecomp:end func_L01_003CDDD8 */

/* localdecomp:start func_L01_003CE2E8 */
__asm__(".extern D_L01_001DF0A8, 4");
__asm__(".extern D_L01_001DF0A0, 4");
__asm__(".extern D_L01_001DF0A4, 4");
extern void func_L01_0043A778(s32, s32, u8 *);
extern s32 func_L01_0040F550(s32, s32, f32);
extern void func_L01_0040C8A0(u8 *, s32);
extern s32 D_L01_001DF0A8;
extern s32 D_L01_001DF0A0;
extern s32 D_L01_001DF0A4;

void func_L01_003CE2E8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s + 0xC4) != 0) {
        f32 f;
        s32 a;
        s32 b;
        s32 c;
        func_L01_0043A778(*(s32 *)(s + 0xC4), *(s32 *)(s + 0xC8), s);
        *(s128 *)(s + 0x10) = *(s128 *)(a0 + 0x10);
        f = (f32)*(s32 *)(s + 0xD0);
        f = f / (f32)((D_L01_001DF0A8 * 5 + 2) / 6);
        a = func_L01_0040F550(0, D_L01_001DF0A0, f);
        b = D_L01_001DF0A4;
        *(s32 *)(s + 0x24) = a;
        c = func_L01_0040F550(0, b, f);
        b = D_L01_001DF0A0;
        *(s32 *)(s + 0x2C) = c;
        c = func_L01_0040F550(0, b, f);
        b = D_L01_001DF0A4;
        *(s32 *)(s + 0x20) = c;
        c = func_L01_0040F550(0, b, f);
        *(s32 *)(s + 0x28) = c;
        func_L01_0040C8A0(s, *(s32 *)(s + 0xC0));
    }
}
/* localdecomp:end func_L01_003CE2E8 */

/* localdecomp:start func_L01_003CE3D0 */
typedef int Q_3CE3D0 __attribute__((mode(TI)));
typedef struct {
    f32 v0[4];
    u8 pad10[4];
    f32 f14;
    s32 t18;
    s32 t1C;
    f32 f20;
    f32 f24;
} V_3CE3D0_003CE3D0;
typedef struct M_3CE3D0_003CE3D0 M_3CE3D0_003CE3D0;
struct M_3CE3D0_003CE3D0 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    V_3CE3D0_003CE3D0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
    u8 padAC[0xB2 - 0xAC];
    s16 hB2;
    u8 padB4[0xB8 - 0xB4];
    M_3CE3D0_003CE3D0 *obj;
    u8 padBC[0xC0 - 0xBC];
    u8 rot[0x10];
};

__asm__(".extern D_L01_001DF1DC_003CE3D0, 4");
__asm__(".extern D_L01_001DF1E0_003CE3D0, 4");
__asm__(".extern D_L01_001DF1E4_003CE3D0, 4");
__asm__(".extern D_L01_001DF1E8_003CE3D0, 4");
__asm__(".extern D_L01_001DF1EC_003CE3D0, 4");
__asm__(".extern D_L01_001DF1F4_003CE3D0, 4");
__asm__(".extern D_L01_001DF1F8_003CE3D0, 4");
__asm__(".extern D_L01_001DF204_003CE3D0, 4");
__asm__(".extern D_L01_001DF208_003CE3D0, 4");
extern f32 D_L01_001DF1DC_003CE3D0;
extern f32 D_L01_001DF1E0_003CE3D0;
extern f32 D_L01_001DF1E4_003CE3D0;
extern f32 D_L01_001DF1E8_003CE3D0;
extern f32 D_L01_001DF1EC_003CE3D0;
extern f32 D_L01_001DF1F4_003CE3D0;
extern f32 D_L01_001DF1F8_003CE3D0;
extern f32 D_L01_001DF204_003CE3D0;
extern f32 D_L01_001DF208_003CE3D0;
extern s32 D_L01_001DFB40_003CE3D0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern M_3CC220 *D_L01_001EAA18_003CE3D0[];
extern void func_L01_00446760_003CE3D0(L_3CC220 *, M_3CC220 *, int, f32 *, f32);
extern void func_L01_004CB320_003CE3D0(void);
extern void func_L01_004CB358_003CE3D0(void);
extern int func_003D3CB0(int, void *, int, M_3CC220 *, L_3CC220 *);
extern int func_0038CAD0(void *);
extern void func_003C2880(s32);
extern s32 func_L01_003FB640_003CE3D0(void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_003303B8_003CE3D0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_004450F0_003CE3D0(M3C7568 *, s32, s32);
extern void func_0038CF68(f32 *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_003CE8A8_003CE3D0(M_3CE3D0_003CE3D0 *);
extern void func_L01_00404A10_003CE3D0(void *, void *);

void func_L01_003CE3D0(M_3CE3D0_003CE3D0 *m) {
    V_3CE3D0_003CE3D0 *v = m->vars;
    vu0_v4 np;
    f32 buf[4];
    L_3CC220 l;
    f32 s;
    int r;
    u8 *pos;
    M_3CE3D0_003CE3D0 *o;
    L_3CC220 *lp;

    if (m->b20 == 2) {
        v->f20 = v->f20 - D_L01_001DF1E4_003CE3D0;
        if (v->f20 < 0.01f) {
            func_003C2880((s32)m);
            return;
        }
    } else {
        if (v->f20 < D_L01_001DF1E0_003CE3D0) {
            v->f20 = v->f20 + D_L01_001DF1DC_003CE3D0;
            if (D_L01_001DF1E0_003CE3D0 < v->f20) {
                v->f20 = D_L01_001DF1E0_003CE3D0;
            }
        }
        vec_add_ba(&np, m->pos, v);
        func_L01_00446760_003CE3D0(&l, (M_3CC220 *)m->obj, 1, (f32 *)v, v->f14);
        l.b18 = 1;
        l.h1A = m->hAA;
        o = m->obj;
        func_L01_004CB320_003CE3D0();
        r = func_003D3CB0((int)m->pos, &np, 0, (M_3CC220 *)o, &l);
        if (r != 0) {
            M_3CC220 *p = D_L01_001EAA18_003CE3D0[0];
            if (p != 0 && p->hAA == 0x186D && p->b20 != 2 && p->b20 != 5) {
                p->b20 = 4;
            }
        }
        func_L01_004CB358_003CE3D0();
        pos = m->pos;
        lp = &l;
        if (r != 0 ||
            (((D_L01_001DFB40_003CE3D0 + m->obj->hB2) & 1) && func_L01_003FB640_003CE3D0(pos, 1, m->obj, D_L01_001DF1E8_003CE3D0) != 0) ||
            func_0038CAD0(&v->t18) != 0) {
            func_003D4D00(pos, 0, m->obj, lp, D_L01_001DF1EC_003CE3D0);
            func_L01_003303B8_003CE3D0(pos, 0, 5, 5, 5, 5, 5, 0, 0.2f, 0.0f, 0.0f, 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x38F7, 0xF7, 0x40FF, 0xFF, 0xFF, 0x30FF,
                              0x7F0060FF, 0x280000FF, 0x30FF, 0);
            func_003A52A0(0, 0, (u8 *)m);
            func_L01_004450F0_003CE3D0((M3C7568 *)m, 2, -1);
        }
        *(vu0_v4 *)m->pos = np;
    }
    if (func_0038CAD0(&v->t1C) != 0) {
        if (D_L01_001DF1F8_003CE3D0 < v->f24) {
            v->f24 = v->f24 - D_L01_001DF1F4_003CE3D0;
            if (v->f24 < D_L01_001DF1F8_003CE3D0) {
                v->f24 = D_L01_001DF1F8_003CE3D0;
            }
        }
    }
    s = v->f24 * v->f20;
    func_0038CF68(buf, m->rot, -D_L01_001DF204_003CE3D0 * s);
    vec_add_ab(buf, buf, m->pos);
    buf[3] = D_L01_001DF208_003CE3D0 * s;
    if ((D_001D545C != 1 || m->obj->hAA != 0xC23 ? func_0038DC20(buf, 64.0f) : func_0038DC20(buf, 255.0f)) >= 0) {
        func_L01_00404A10_003CE3D0(func_L01_003CE8A8_003CE3D0, m);
    }
}
/* localdecomp:end func_L01_003CE3D0 */

/* localdecomp:start func_L01_003CE780 */
typedef int W76Quad __attribute__((mode(TI)));
extern u8 *func_003C24B0(int,int);
extern void func_L01_004450F0(void *,int,int);
extern float func_0038CED8(void *);
extern float func_0038D160(float,float);
extern void func_0038D308(void *,void *);
extern float D_L01_001DF1D8;
extern int D_L01_001DF1F0;
__asm__(".extern D_L01_001DF1D8,4");
__asm__(".extern D_L01_001DF1F0,4");
typedef struct { W76Quad q0; int x10; float x14; int x18; int x1c; float x20; float x24; int x28; int x2c; } D_3CE780;
u8 *func_L01_003CE780(void *parent,void *position,u8 *direction,int kind,int other,float scale) {
    u8 *m;
    D_3CE780 *d;
    float speed; int color;
    m=func_003C24B0(0x1B62,0x80);
    if(m) {
        *(void **)(m+0xB8)=parent;
        *(u16 *)(m+0x34)|=1;
        m[0x31]=0;
        d=*(D_3CE780 **)(m+0x68);
        m[0x30]=255;
        func_L01_004450F0(m,1,-1);
        *(W76Quad *)(m+0x10)=*(W76Quad *)position;
        *(float *)(m+0xF4)=-func_0038D160(func_0038CED8(direction),*(float *)(direction+8));
        *(float *)(m+0xF8)=func_0038D160(*(float *)direction,*(float *)(direction+4));
        func_0038D308(m+0xC0,m+0xF0);
        *(W76Quad *)d=*(W76Quad *)direction;
        d->x14=scale;
        speed=D_L01_001DF1D8;
        color=D_L01_001DF1F0;
        d->x20=speed;
        d->x1c=color;
        d->x24=1.0f;
        d->x18=500;
        d->x28=kind;
        d->x2c=other;
    }
    return m;
}
/* localdecomp:end func_L01_003CE780 */

INCLUDE_ASM("asm/levels", func_L01_003CE8A8);

/* localdecomp:start func_L01_003CEE90 */
typedef union Obj_3CEE90 { u8 b[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; f32 f[0x40]; union Obj_3CEE90 *ptr[0x40]; s128 q[0x10]; } Obj_3CEE90;
typedef union { u8 b[0x700]; s32 i[0x1C0]; f32 f[0x1C0]; } Vars_3CEE90;
typedef union { u8 b[0x2A00]; s32 i[0xA80]; Obj_3CEE90 *ptr[0xA80]; } Hero_3CEE90;
typedef struct { u8 pad[0x6C]; f32 f6C; f32 f70; u8 pad74[0xF0 - 0x74]; } Row_3CEE90;
extern Hero_3CEE90 D_001A4BE0;
extern u8 D_001D5470[8];
extern u8 D_001425C0[];
extern Row_3CEE90 D_L01_002C5600[];
__asm__(".extern D_001D5470, 16");
__asm__(".extern D_L01_001DF258, 4");
__asm__(".extern D_L01_001DF260, 4");
__asm__(".extern D_L01_001D6694, 4");
extern f32 D_L01_001DF258;
extern s32 D_L01_001DF260;
extern s32 D_L01_001D6694;
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_00513EF0(void);
extern void func_L01_00448E10(void *);
extern void func_003C7DD8(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(u8 *, s32, f32 *);
extern void func_0038D590(void *, void *);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_003CF5E0(u8 *);
extern void func_L01_003CF918(u8 *);

void func_L01_003CEE90(Obj_3CEE90 *a0) {
    Vars_3CEE90 *v = (Vars_3CEE90 *)a0->ptr[0x68 / 4];
    s32 flag = 1;
    vu0_v4 m[4];
    L_3CC220 t;
    Row_3CEE90 *row;
    vu0_v4 *p1, *p3, *p70, *p80, *p90;
    L_3CC220 *tp;
    f32 rf;
    s32 n2;
    vu0_v4 q70;
    vu0_v4 q80;
    vu0_v4 q90;
    s32 i;
    u8 *p22;

    if (a0->b[0x20] == 0) {
        a0->b[0x30] = 0xFF;
        D_001A4BE0.b[0x25E6] = 1;
        if (D_001A4BE0.i[0x1228 / 4] != 9) {
            a0->i[0x98 / 4] = 0;
            a0->uh[0x34 / 2] = (a0->uh[0x34 / 2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            if ((Obj_3CEE90 *)D_001A4BE0.ptr[0x28D0 / 4] != a0) {
                a0->uh[0x96 / 2] = 0;
            } else {
                D_001A4BE0.ptr[0x28D0 / 4] = 0;
                func_003C2880((s32)a0);
                return;
            }
        } else {
            D_001A4BE0.ptr[0x1200 / 4]->uh[0x34 / 2] |= 0x80;
            a0->b[0x20] = 1;
            a0->uh[0x34 / 2] |= 0x100;
            a0->f[0x2C / 4] = a0->ptr[0x24 / 4]->f[0x24 / 4] * 0.3f * D_L01_001DF258;
            v->i[0x610 / 4] = 0x4096006B;
            v->i[0x614 / 4] = 0x450030;
            v->f[0x604 / 4] = 2.0f;
            v->f[0x608 / 4] = 2.0f;
            a0->uh[0x96 / 2] = 0;
        }
    }
    if (a0->b[0x20] != 1) {
        return;
    }
    if (a0->uh[0x96 / 2] < 200) {
        a0->uh[0x96 / 2] = a0->uh[0x96 / 2] + 1;
    }
    if (D_001A4BE0.i[0x1228 / 4] != 9) {
        a0->i[0x98 / 4] = 0;
        a0->uh[0x34 / 2] = (a0->uh[0x34 / 2] | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
        if ((Obj_3CEE90 *)D_001A4BE0.ptr[0x28D0 / 4] == a0) {
            D_001A4BE0.ptr[0x28D0 / 4] = 0;
            func_003C2880((s32)a0);
            return;
        }
    } else {
        if (D_001A4BE0.b[0x25E4] == 1 || D_L01_001D6694 == 2 || (D_001A4BE0.b[0x25ED] != 0 && D_001A4BE0.i[0x25C4 / 4] != 0x37)) {
            a0->i[0x98 / 4] = 0;
            a0->uh[0x34 / 2] = (a0->uh[0x34 / 2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            return;
        }
        if ((func_L01_00513EF0() == 2 || D_001A4BE0.i[0x25C4 / 4] == 1 || D_001A4BE0.i[0x25C4 / 4] == 0x1D) && D_001A4BE0.b[0x121A] == 0) {
            a0->i[0x98 / 4] = 0;
            a0->uh[0x34 / 2] = (a0->uh[0x34 / 2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
            flag = 0;
        } else {
            if (D_001A4BE0.b[0x25E4] == 3) {
                a0->i[0x98 / 4] = 0;
                a0->uh[0x34 / 2] = (a0->uh[0x34 / 2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(a0, 1);
                return;
            }
            if (D_001D5470[9] == 0) {
                a0->i[0x98 / 4] = 0;
                a0->uh[0x34 / 2] = (a0->uh[0x34 / 2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(a0, 1);
                D_001A4BE0.ptr[0x1200 / 4]->uh[0x34 / 2] &= 0xFF7F;
                if ((Obj_3CEE90 *)D_001A4BE0.ptr[0x28D0 / 4] == a0) {
                    D_001A4BE0.ptr[0x28D0 / 4] = 0;
                    func_003C2880((s32)a0);
                    return;
                }
            } else {
                D_001A4BE0.ptr[0x1200 / 4]->uh[0x34 / 2] |= 0x80;
                for (i = 0; i < 4; i++) {
                    if (D_001A4BE0.ptr[0x1E00 / 4 + i] != 0) {
                        D_001A4BE0.ptr[0x1E00 / 4 + i]->uh[0x34 / 2] |= 0x80;
                    }
                }
                a0->uh[0x34 / 2] &= 0xFFBE;
                a0->uh[0x34 / 2] |= a0->ptr[0x24 / 4]->uh[0x44 / 2] & 0x1000;
                a0->i[0x98 / 4] = a0->ptr[0x24 / 4]->i[0x10 / 4];
            }
        }
    }
    if (v->i[0x620 / 4] < 6) {
        v->i[0x620 / 4] = v->i[0x620 / 4] + 1;
    }
    if (D_001A4BE0.i[0x1228 / 4] == 9) {
        a0->q[0x10 / 16] = D_001A4BE0.ptr[0x1200 / 4]->q[0x10 / 16];
        a0->q[0xC0 / 16] = D_001A4BE0.ptr[0x1200 / 4]->q[0xC0 / 16];
        a0->q[0xD0 / 16] = D_001A4BE0.ptr[0x1200 / 4]->q[0xD0 / 16];
        a0->q[0xE0 / 16] = D_001A4BE0.ptr[0x1200 / 4]->q[0xE0 / 16];
        a0->q[0xF0 / 16] = D_001A4BE0.ptr[0x1200 / 4]->q[0xF0 / 16];
        func_L01_00448E10(&a0->b[0xC0]);
        func_003C7DD8(a0);
    } else {
        func_003C2EC0(D_001A4BE0.ptr[0x25C0 / 4], 0, m);
        a0->q[0x10 / 16] = *(s128 *)&m[3];
        func_0038D590(&a0->b[0xC0], m);
        func_L01_00448E10(&a0->b[0xC0]);
        func_003C7DD8(a0);
    }
    if ((D_001A4BE0.i[0x25C4 / 4] - 0x13 < 2U || D_001A4BE0.b[0x121A] != 0) && a0->uh[0x96 / 2] >= 9) {
        func_003C4138(&v->f[0x604 / 4], 3.5f, 0.120000005f);
        func_003C4138(&v->f[0x608 / 4], 1.5f, 0.120000005f);
        func_003C2F58((u8 *)a0, 2, (f32 *)&m[0]);
        p1 = &m[1];
        func_003C2F58((u8 *)a0, 3, (f32 *)p1);
        vec_sub_ba(&m[2], &m[0], &m[1]);
        func_0038CF68((f32 *)&m[2], &m[2], v->f[0x608 / 4]);
        vec_add_ba(&m[1], &m[2], &m[0]);
        p3 = &m[3];
        n2 = D_L01_001DF260 - 2;
        p22 = (u8 *)(((v->i[0x60C / 4] + n2) % D_L01_001DF260) * 16) + (s32)v;
        vec_sub_ab(&m[3], &v->b[v->i[0x60C / 4] * 16], p22);
        func_0038CF68((f32 *)p3, p3, 2.5f);
        m[3].z = 1.0f;
        m[3].w = 5627.9248f;
        row = &D_L01_002C5600[D_001425C0[9]];
        rf = row->f6C;
        if (D_001A4BE0.i[0x25C4 / 4] == 0x14) {
            rf = row->f70;
        }
        tp = &t;
        func_L01_00446760(tp, (M_3CC220 *)a0, 0x10000, (f32 *)p3, rf);
        t.b19 = 1;
        t.h1A = a0->h[0xAA / 2];
        t.b18 = 0;
        func_003D3CB0((int)&m[0], p1, 9, (M_3CC220 *)a0, tp);
        p80 = &q80;
        p90 = &q90;
        p70 = &q70;
        vec_sub_ba(&q90, p22, &D_001A4BE0.b[0x80]);
        vec_sub_ba(&q70, &m[1], &D_001A4BE0.b[0x80]);
        func_L01_0044C280(p80, p90, p70, 0, 0.2f);
        vec_add_ab(&q80, &q80, &D_001A4BE0.b[0x80]);
        func_003D3CB0((int)&m[0], p80, 9, (M_3CC220 *)D_001A4BE0.ptr[0x25C0 / 4], tp);
        func_L01_0044C280(p80, p90, p70, 0, 0.4f);
        vec_add_ab(&q80, &q80, &D_001A4BE0.b[0x80]);
        func_003D3CB0((int)&m[0], p80, 9, (M_3CC220 *)D_001A4BE0.ptr[0x25C0 / 4], tp);
        func_L01_0044C280(p80, p90, p70, 0, 0.6f);
        vec_add_ab(&q80, &q80, &D_001A4BE0.b[0x80]);
        func_003D3CB0((int)&m[0], p80, 9, (M_3CC220 *)D_001A4BE0.ptr[0x25C0 / 4], tp);
        func_L01_0044C280(p80, p90, p70, 0, 0.8f);
        vec_add_ba(&q80, &q80, &D_001A4BE0.b[0x80]);
        func_003D3CB0((int)&m[0], p80, 9, (M_3CC220 *)D_001A4BE0.ptr[0x25C0 / 4], tp);
        func_003D3CB0((int)&m[0], p22, 9, (M_3CC220 *)D_001A4BE0.ptr[0x25C0 / 4], tp);
    } else {
        func_003C4138(&v->f[0x604 / 4], 1.75f, 0.120000005f);
        func_003C4138(&v->f[0x608 / 4], 2.0f, 0.120000005f);
    }
    if (D_001A4BE0.i[0x1228 / 4] == 9 && flag != 0) {
        func_L01_00404808(func_L01_003CF5E0, a0);
    }
    func_L01_003CF918((u8 *)a0);
}
/* localdecomp:end func_L01_003CEE90 */

/* localdecomp:start func_L01_003CF5E0 */
extern void func_L01_0043A778_003CF5E0(s32, s32, u8 *);
extern void func_L01_0043A6E0_003CF5E0(void *, s32, void *);
extern void func_L01_0040E620_003CF5E0(void *, void *, f32);
extern void func_L01_0040A8C0_003CF5E0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98_003CF5E0(void *, s32, void *, void *, s32, s32, f32, s32, s32, s32);
__asm__(".extern D_L01_001DF25C_003CF5E0, 4");
__asm__(".extern D_L01_001DF260_003CF5E0, 4");
extern const u32 D_L01_001DF25C_003CF5E0;
extern s32 D_L01_001DF260_003CF5E0;

void func_L01_003CF5E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 w1[4] __attribute__((aligned(16)));
    f32 w2[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 t;
    u8 *q;

    t = *(f32 *)(s + 0x600) - 0.1f;
    *(f32 *)(s + 0x600) = t;
    if (t <= -8.0f) {
        *(f32 *)(s + 0x600) = t + 8.0f;
    }
    func_L01_0043A778_003CF5E0((s32)a0, 0, (u8 *)a);
    func_L01_0043A778_003CF5E0((s32)a0, 2, (u8 *)b);
    func_L01_0043A778_003CF5E0((s32)a0, 1, (u8 *)c);
    func_L01_0043A778_003CF5E0((s32)a0, 3, (u8 *)d);
    vec_sub_ba(w1, a, c);
    func_L01_0040E620_003CF5E0(w1, w1, *(f32 *)(s + 0x608));
    vec_add_ba(c, w1, a);
    vec_sub_ba(w2, b, d);
    func_L01_0040E620_003CF5E0(w2, w2, *(f32 *)(s + 0x604));
    vec_add_ab(d, w2, b);
    func_L01_0043A6E0_003CF5E0(a0, 1, m);
    *(vu0_q *)w = *(vu0_q *)m;
    func_L01_0040E620_003CF5E0(w, w, -2.75f);
    *(vu0_q *)(s + 0x410) = *(vu0_q *)w;
    *(f32 *)(s + 0x41C) = 1.0f;
    *(vu0_q *)w = *(vu0_q *)m;
    func_L01_0040E620_003CF5E0(w, w, 0.75f);
    *(vu0_q *)(s + 0x400) = *(vu0_q *)w;
    *(f32 *)(s + 0x40C) = 1.0f;
    q = s + 0x400;
    func_L01_0040A8C0_003CF5E0(a, c, D_L01_001DF25C_003CF5E0, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x600));
    func_L01_0040A8C0_003CF5E0(b, d, D_L01_001DF25C_003CF5E0, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x600));
    func_L01_0040A8C0_003CF5E0(a, c, D_L01_001DF25C_003CF5E0, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x600));
    func_L01_0040A8C0_003CF5E0(b, d, D_L01_001DF25C_003CF5E0, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x600));
    func_L01_00408C98_003CF5E0(q, D_L01_001DF260_003CF5E0, s, s + 0x200, *(s32 *)(s + 0x60C), *(s32 *)(s + 0x61C), *(f32 *)(s + 0x618), *(s32 *)(s + 0x610), *(s32 *)(s + 0x614), 5);
}
/* localdecomp:end func_L01_003CF5E0 */

/* localdecomp:start func_L01_003CF918 */
extern void func_003C2F58(u8 *, s32, f32 *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_L01_0044C280_003CF918(void *, void *, void *, s32, f32);
extern void func_003C3FC0(void *, void *);
__asm__(".extern D_L01_001DF260_003CF918, 4");
extern s32 D_L01_001DF260_003CF918;
extern u8 D_001A4C60[];

void func_L01_003CF918(u8 *a0) {
    vu0_v4 p0;
    vu0_v4 mtx[4];
    vu0_v4 p1;
    vu0_v4 d;
    vu0_v4 zero;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 out;
    u8 *v = *(u8 **)(a0 + 0x68);

    *(f32 *)(v + 0x618) = 0.0f;
    func_003C2F58(a0, 3, (f32 *)&p0);
    func_003C2EC0(a0, 3, mtx);
    func_003C2F58(a0, 2, (f32 *)&p1);
    vec_sub_ba(&d, &p1, &p0);
    func_0038CF68((f32 *)&d, &d, *(f32 *)(v + 0x604));
    vec_add_ab(&p0, &d, &p1);
    if (*(f32 *)(v + 0x618) == 0.0f) {
        s32 n = D_L01_001DF260_003CF918;
        *(s32 *)(v + 0x60C) = (*(s32 *)(v + 0x60C) + 1) % n;
        if (*(s32 *)(v + 0x61C) < n) {
            *(s32 *)(v + 0x61C) = *(s32 *)(v + 0x61C) + 1;
        }
    }
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    if (*(s32 *)(v + 0x620) >= 2) {
        s32 n = D_L01_001DF260_003CF918;
        s32 i = (*(s32 *)(v + 0x60C) - 1 + n) % n;
        vec_sub_ab(&a, &p0, D_001A4C60);
        vec_sub_ba(&b, v + i * 16, D_001A4C60);
        func_L01_0044C280_003CF918(&out, &b, &a, 0, 0.5f);
        func_003C3FC0(v + 0x200 + *(s32 *)(v + 0x60C) * 16, &zero);
        vec_add_ba(v + *(s32 *)(v + 0x60C) * 16, &out, D_001A4C60);
        *(s32 *)(v + 0x60C) = (*(s32 *)(v + 0x60C) + 1) % D_L01_001DF260_003CF918;
    }
    func_003C3FC0(v + 0x200 + *(s32 *)(v + 0x60C) * 16, &zero);
    *(s128 *)(v + *(s32 *)(v + 0x60C) * 16) = *(s128 *)&p0;
}
/* localdecomp:end func_L01_003CF918 */
