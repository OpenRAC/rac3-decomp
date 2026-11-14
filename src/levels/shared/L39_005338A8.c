#include "common.h"

/* declared by functions of L39_00533790.c, which this file was cut from */
extern void func_L39_00533600(void *);

/* localdecomp:start func_L39_005338A8 */
#include "vu0.h"
typedef struct M_005338A8 {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x47]; struct P_005338A8 *p68; u8 p6C[0x3E]; u16 hAA;
    u8 pAC[0xC]; void *xB8;
} M_005338A8;
typedef struct P_005338A8 {
    vu0_v4 vel; f32 f10; s32 w14; f32 f18; s32 w1C; s32 w20; s32 w24; u8 *p28; u8 b2C; u8 b2D;
    u8 p2E[2]; vu0_v4 v30; vu0_v4 v40;
} P_005338A8;
typedef struct { u8 p0[0x18]; void *w18; u8 p1C[4]; vu0_v4 v20; } T_005338A8;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_005338A8;
extern T_005338A8 D_L39_0025F740;
extern f32 D_L39_0024BB4C;
extern s32 *D_001D5A10_sda;
__asm__(".extern D_001D5A10_sda, 4");
extern void func_L39_00533600(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00446978(void *, void *);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern s32 func_L39_005BE900(void *, f32 *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_00534220();
extern void func_L39_00534880(void *, void *, void *);
extern void func_L39_00534530(void *, void *, void *);

void func_L39_005338A8(M_005338A8 *m) {
    s32 st = m->b20;
    P_005338A8 *p = m->p68;
    vu0_v4 v90;
    vu0_v4 vA0;
    S_005338A8 sB0;
    f32 d0;
    f32 d1;
    switch (st) {
    case 0: {
        s32 mask;
        v90 = m->pos;
        vec_add_ab(&m->pos, &p->vel, &m->pos);
        if (m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
            m->pos.z < 2.0f || 1021.0f < m->pos.z) goto kill;
        p->w14++;
        if (p->b2C != 0) p->b2C--;
        func_L39_00533600(m);
        if (p->b2C == 0) {
            vu0_v4 *pv = &p->v30;
            m->pos = *pv;
            m->b20 = 1;
            vA0 = p->vel;
            func_0038CE20(&vA0, &vA0, 0.5f);
            vA0.w = 5627.925f;
            func_L01_00446760(&sB0, m, p->w1C, &vA0, p->f18);
            sB0.b19 = 1;
            sB0.h1A = m->hAA;
            sB0.b18 = 0;
            func_003D4D00(pv, 0, m, &sB0, 1.0f);
        } else {
            mask = 0;
            if (p->w14 < 0x96) {
                if (0.65f < D_L39_0024BB4C && D_L39_0024BB4C < 0.8f) mask = 1;
                else if (0.8f <= D_L39_0024BB4C) mask = 3;
            }
            if ((p->w14 & mask) == mask) {
                func_L39_005FFDF8(*(s32 *)(p->p28 + 0x2548));
                if (func_003D3CB0(&p->v40, &m->pos, 1, m, 0)) {
                    T_005338A8 *t = &D_L39_0025F740;
                    if (t->w18 == 0 || t->w18 != m->xB8) {
                        vu0_v4 *tv;
                        tv = &t->v20;
                        m->pos = *tv;
                        m->b20 = 1;
                        vA0 = p->vel;
                        func_0038CE20(&vA0, &vA0, 0.5f);
                        vA0.w = 5627.925f;
                        func_L01_00446760(&sB0, m, p->w1C, &vA0, p->f18);
                        sB0.b19 = 1;
                        sB0.h1A = m->hAA;
                        sB0.b18 = 0;
                        if (t->w18 != 0) {
                            if (t->w18 != m->xB8) func_L01_00446978(t->w18, &sB0);
                        } else {
                            func_003D4D00(tv, 0, m, &sB0, 0.6f);
                        }
                    }
                }
                func_L39_005FFE78();
                p->v40 = m->pos;
            }
        }
        if (p->w14 < 0x97) break;
        goto kill;
    }
    case 1:
        func_0038CF68(p, p, -0.1f);
        vec_add_ba(&vA0, &m->pos, &p->vel);
        func_L39_005F3488(2, 0, m, 0x1094);
        if (p->w20 != 0) {
            sB0.v = m->pos;
            sB0.v.w = 0.5f;
            if (func_L39_005BE900(&sB0, &d0, 96.0f) > 0) {
                if (d0 < 144.0f) {
                    func_L01_003303B8(&vA0, 0, 5, 2, 2, 2, 2, 1, 0.17f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 0,
                                      0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                } else if (d0 < 576.0f) {
                    func_L01_003303B8(&vA0, 0, 3, 0, 0, 0, 0, 0, 0.17f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 0,
                                      0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                } else {
                    func_L01_003303B8(&vA0, 0, 0, 0, 0, 0, 0, 0, 0.17f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 0,
                                      0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                                      0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                }
            }
        } else {
            func_L01_003303B8(&vA0, 0, 5, 2, 2, 2, 2, 0, 0.14f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 0,
                              0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    kill:
        func_003C2880(m);
        return;
    }
    if (*D_001D5A10_sda == 1) {
        vA0 = m->pos;
        vA0.w = 0.5f;
        if (func_L39_005BE900(&vA0, &d1, 96.0f) > 0) {
            func_L01_00404A10(func_L39_00534220, m);
            if (d1 < 576.0f) {
                if (p->w20 != 0) {
                    sB0.v = m->pos;
                    func_L39_00534880(m, &sB0, &v90);
                } else {
                    sB0.v = m->pos;
                    func_L39_00534530(m, &sB0, &v90);
                }
            }
        }
    } else {
        func_L01_00404A10(func_L39_00534220, m);
        if (p->w20 != 0) {
            vA0 = m->pos;
            func_L39_00534880(m, &vA0, &v90);
        } else {
            vA0 = m->pos;
            func_L39_00534530(m, &vA0, &v90);
        }
    }
}
/* localdecomp:end func_L39_005338A8 */
