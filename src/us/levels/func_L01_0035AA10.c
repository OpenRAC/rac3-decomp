#include "common.h"

/* NTSC-U counterpart of func_L01_0035B710 (src/levels/01_veldin/L01_0035B710.c): 151 -> 181; 9 -> 11 */
/* localdecomp:start func_L01_0035AA10 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x10]; u8 b31; u8 p32[2]; u16 h34; u8 p36[0x32];
    u8 *p68; u8 p6C[0x2A]; u16 h96; s32 w98; u8 p9C[0xE]; u16 hAA;
} M_5B710;
typedef struct { u8 p0[0x98]; s32 w98; } Q_5B710;
typedef struct { vu0_v4 vel; u8 p10[4]; s32 w14; u8 p18[4]; Q_5B710 *q1C; u8 p20[4]; f32 f24; s32 w28; } P_5B710;
typedef struct { u8 p0[0x18]; Q_5B710 *w18; u8 p1C[4]; vu0_v4 v20; } T_5B710;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_5B710;
extern T_5B710 D_L01_001EAA80;
extern void func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern s32 func_L01_00452EC8(void *);
extern void func_003BD360(void *);
extern s32 func_L01_004562A0(void *, s32, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_0035AE00();
extern void func_L01_0035AF18();
void func_L01_0035AA10(M_5B710 *m) {
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
        func_L01_004C76B8();
        if (func_003CE740(pv, &m->pos, 0, m, 0)) {
            T_5B710 *t = &D_L01_001EAA80;
            if (t->w18 == 0 || t->w18 != p->q1C) {
                vu0_v4 *tv;
                tv = &t->v20;
                m->pos = *tv;
                m->b20 = 2;
                vA0 = p->vel;
                func_003886E8(&vA0, &vA0, 3.0f);
                vA0.w = 5627.925f;
                func_L01_00443628(&sB0, m, p->w28, &vA0, p->f24);
                sB0.b19 = st;
                sB0.h1A = m->hAA;
                sB0.b18 = 0;
                if (t->w18 != 0) {
                    if (t->w18 != p->q1C) func_003CF790(tv, 0, m, &sB0, 1.0f);
                } else {
                    func_003CF790(tv, 0, m, &sB0, 0.6f);
                }
            }
        }
        func_L01_004C76F0();
        p->q1C->w98 = save;
        if (p->w14 < 0xB5) break;
        goto kill;
    }
    case 2:
        func_L01_0032FE90((u8 *)&m->pos, 0, 5, 2, 2, 2, 0, 0, 0.25f, 1.0f, 0.0f, 2.0f, 0, 1, 0, 0, 1, 0,
                          0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                          0x280000FF, 0x3064FF, 0);
        func_L01_00441FB8(m, 4, -1);
        break;
    case 4:
        if (func_L01_00452EC8(m)) {
            m->w98 = 0;
            m->h34 |= 1;
            m->b31 = 0;
        }
        if (m->h96 >= 11) {
        kill:
            func_003BD360(m);
            return;
        }
        m->h96++;
        break;
    }
    vA0 = m->pos;
    vA0.w = 0.5f;
    if (func_L01_004562A0(&vA0, 0, 96.0f) > 0) {
        func_L01_004026A0(func_L01_0035AE00, m);
        sB0.v = m->pos;
        func_L01_0035AF18(m, &sB0.v, &v90);
    }
}
/* localdecomp:end func_L01_0035AA10 */
