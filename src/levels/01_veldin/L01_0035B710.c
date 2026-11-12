#include "common.h"

/* localdecomp:start func_L01_0035B710 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x10]; u8 b31; u8 p32[2]; u16 h34; u8 p36[0x32];
    u8 *p68; u8 p6C[0x2A]; u16 h96; s32 w98; u8 p9C[0xE]; u16 hAA;
} M_5B710;
typedef struct { u8 p0[0x98]; s32 w98; } Q_5B710;
typedef struct { vu0_v4 vel; u8 p10[4]; s32 w14; u8 p18[4]; Q_5B710 *q1C; u8 p20[4]; f32 f24; s32 w28; } P_5B710;
typedef struct { u8 p0[0x18]; Q_5B710 *w18; u8 p1C[4]; vu0_v4 v20; } T_5B710;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_5B710;
extern T_5B710 D_L01_001EAA00;
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_004561B8(void *);
extern void func_003C2880(void *);
extern s32 func_L01_00459590(void *, s32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_0035BB00();
extern void func_L01_0035BC18();
void func_L01_0035B710(M_5B710 *m) {
    s32 st = m->b20;
    P_5B710 *p = (P_5B710 *)m->p68;
    vu0_v4 v90;
    vu0_v4 vA0;
    S_5B710 sB0;
    switch (st) {
    case 1: {
        s32 save;
        vu0_v4 *pv = &v90;
        *pv = m->pos;
        vec_add_ba(&m->pos, &p->vel, &m->pos);
        if (m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
            m->pos.z < 2.0f || 1021.0f < m->pos.z) goto kill;
        p->w14++;
        save = p->q1C->w98;
        p->q1C->w98 = 0;
        func_L01_004CB320();
        if (func_003D3CB0(pv, &m->pos, 0, m, 0)) {
            T_5B710 *t = &D_L01_001EAA00;
            if (t->w18 == 0 || t->w18 != p->q1C) {
                vu0_v4 *tv;
                tv = &t->v20;
                m->pos = *tv;
                m->b20 = 2;
                vA0 = p->vel;
                func_0038CE20(&vA0, &vA0, 3.0f);
                vA0.w = 5627.925f;
                func_L01_00446760(&sB0, m, p->w28, &vA0, p->f24);
                sB0.b19 = st;
                sB0.h1A = m->hAA;
                sB0.b18 = 0;
                if (t->w18 != 0) {
                    if (t->w18 != p->q1C) func_003D4D00(tv, 0, m, &sB0, 1.0f);
                } else {
                    func_003D4D00(tv, 0, m, &sB0, 0.6f);
                }
            }
        }
        func_L01_004CB358();
        p->q1C->w98 = save;
        if (p->w14 < 0x97) break;
        goto kill;
    }
    case 2:
        func_L01_003303B8((u8 *)&m->pos, 0, 5, 2, 2, 2, 0, 0, 0.25f, 1.0f, 0.0f, 2.0f, 0, 1, 0, 0, 1, 0,
                          0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                          0x280000FF, 0x3064FF, 0);
        func_L01_004450F0(m, 4, -1);
        break;
    case 4:
        if (func_L01_004561B8(m)) {
            m->w98 = 0;
            m->h34 |= 1;
            m->b31 = 0;
        }
        if (m->h96 >= 9) {
        kill:
            func_003C2880(m);
            return;
        }
        m->h96++;
        break;
    }
    vA0 = m->pos;
    vA0.w = 0.5f;
    if (func_L01_00459590(&vA0, 0, 96.0f) > 0) {
        func_L01_00404A10(func_L01_0035BB00, m);
        sB0.v = m->pos;
        func_L01_0035BC18(m, &sB0.v, &v90);
    }
}
/* localdecomp:end func_L01_0035B710 */

/* localdecomp:start func_L01_0035BB00 */
typedef struct { char p0[0x10]; f32 x; } S;
typedef struct { char p0[0x10]; char p10[0x10]; u8 kind; char p21[0x47]; S *s; } H;

extern s32 D_001DD6AC_sda;
__asm__(".extern D_001DD6AC_sda, 4");
extern s32 D_001DD6B0_sda;
__asm__(".extern D_001DD6B0_sda, 4");
extern f32 D_001DD6B4_sda;
__asm__(".extern D_001DD6B4_sda, 4");
extern f32 D_001DD6B8_sda;
__asm__(".extern D_001DD6B8_sda, 4");
extern f32 D_001DD6BC_sda;
__asm__(".extern D_001DD6BC_sda, 4");

extern f32 func_0040F3F8(f32 a, f32 b);
extern f32 func_00443A78(void);
extern void func_0040A6C0(void *p, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f);

void func_L01_0035BB00(H *a0) {
    S *s;
    f32 r;
    if (a0 != 0 && a0->kind != 0xFE && a0->kind != 0xFD) {
        s = a0->s;
        r = func_0040F3F8(s->x, D_001DD6B4_sda * 0.01745329238474369f);
        s->x = r;
        r = func_0040F3F8(-r * 1.5f, 0.0f);
        func_0040A6C0(a0->p10, D_001DD6AC_sda, D_001DD6B0_sda, 1, D_001DD6BC_sda, 0.0799999982118f, r);
        func_0040A6C0(a0->p10, 0x31, 0x10007FFF, 1, 0.36000001430511475f, 0.0799999982118f, s->x * 0.5f);
        r = func_00443A78();
        func_0040A6C0(a0->p10, 0x2F, 0x507F7F7F, 1, D_001DD6B8_sda, 0.0799999982118f, r);
    }
}
/* localdecomp:end func_L01_0035BB00 */

/* localdecomp:start func_L01_0035BC18 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; vu0_v4 *vel; } M_5BC18;
extern u8 *D_L01_00221098[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_003C4C18(f32 *, f32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
void func_L01_0035BC18(M_5BC18 *m, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v30;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 *vel;
    f32 len;
    s32 n;
    s32 i;
    a = *pa;
    vel = m->vel;
    b = *pb;
    len = func_0038CEA8(vel);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_0038CF68(&d, &d, len / (f32)n);
    func_003C5180(&m->pos, &v60, 1);
    for (i = 0; i < n / 2; i++) {
        s32 life = (s32)func_L01_00443A18(1.0f, 3.0f);
        s32 r;
        s32 size;
        s32 color;
        u8 *p;
        f32 s = func_003824E0(0.1f, 0.2f) * 0.020000001f;
        func_0038CE20(&v30, &v60, -s);
        r = func_00382498(3, 6);
        if (func_0013D3E0() & 2) {
            size = 0x40;
            color = 0x407FFF;
        } else {
            size = 0x60;
            color = 0x4040FF;
        }
        p = func_L01_0046A610(&c, &v30, (r * 5 + 2) / 6, size, color, life, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (p != 0) {
            p[2] = *D_L01_00221098[0x5C / 4];
            p[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    if (func_00382468(2)) {
        s32 color;
        s32 x;
        u8 *p;
        func_0038CE20(&v70, vel, -0.040000003f);
        color = 0x7F80DFFF;
        func_003C4C18(&v70.x, 0.120000005f);
        v70.z += 0.060000002f;
        if (func_00382468(2)) color = 0x7F407FFF;
        x = func_00382498(8, 0x11);
        p = func_L01_00465738(&m->pos, &v70, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = 0.0024f;
            p[2] = *D_L01_00221098[0xD4 / 4];
        }
    }
}
/* localdecomp:end func_L01_0035BC18 */
