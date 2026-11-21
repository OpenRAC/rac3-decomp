#include "common.h"

/* NTSC-U counterpart of func_L07_0035DFD0 (src/levels/shared/L07_0035DFD0.c): the lifetime is 0xB5 frames (60 Hz), not 0x97 */
/* localdecomp:start func_L07_0035D0F0 */
#include "vu0.h"
typedef struct {
    u8 p0[0x20]; u8 b20; u8 p21[0x89]; s16 hAA;
} H_0035D0F0;
typedef struct {
    vu0_v4 vel; u8 p10[4]; s32 w14; s32 light; void *q1C; u8 p20[4]; f32 f24; s32 w28;
} P_0035D0F0;
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x47]; P_0035D0F0 *p68; u8 p6C[0x3E]; u16 hAA;
} M_0035D0F0;
typedef struct { u8 p0[0x18]; H_0035D0F0 *w18; u8 p1C[4]; vu0_v4 v20; } T_0035D0F0;
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } S_0035D0F0;
typedef struct { f32 r; f32 g; f32 b; f32 x; vu0_v4 pos; } L_0035D0F0;
extern T_0035D0F0 D_L07_001E8C00;
extern L_0035D0F0 D_L07_001EFD40[];
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern void func_003BD360(void *);
extern s32 func_003894E8(void *, f32);
extern void func_L01_004026A0_0035D0F0(void *, void *);
extern void func_L01_00421FE0(s32);
extern s32 func_L01_00421F08(void *, f32, f32, f32, f32, f32);
extern void func_L07_0035D5B0(u8 *);
extern void func_L07_0035D738(void *, vu0_v4 *, vu0_v4 *);

void func_L07_0035D0F0(M_0035D0F0 *m) {
    s32 st = m->b20;
    P_0035D0F0 *p = m->p68;
    vu0_v4 v90;
    vu0_v4 vA0;
    S_0035D0F0 sB0;
    switch (st) {
    case 0: {
        s32 hit;
        vu0_v4 *pv = &v90;
        *pv = m->pos;
        vec_add_ba(&m->pos, &p->vel, &m->pos);
        if (m->pos.x < 2.0f || 1021.0f < m->pos.x || m->pos.y < 2.0f || 1021.0f < m->pos.y ||
            m->pos.z < 2.0f || 1021.0f < m->pos.z) {
            if (p->light != -1) func_L01_00421FE0(p->light);
            p->light = -1;
            func_003BD360(m);
            return;
        }
        p->w14++;
        func_L01_004C76B8();
        hit = func_003CE740(pv, &m->pos, 0, m, 0);
        if (hit) {
            H_0035D0F0 *h = D_L07_001E8C00.w18;
            if (h != 0 && h->hAA == 0x186D && h->b20 != 2 && h->b20 != 5) h->b20 = 4;
        }
        func_L01_004C76F0();
        if (hit) {
            T_0035D0F0 *t = &D_L07_001E8C00;
            if (t->w18 == 0 || t->w18 != p->q1C) {
                vu0_v4 *tv;
                tv = &t->v20;
                m->pos = *tv;
                m->b20 = 1;
                vA0 = p->vel;
                func_003886E8(&vA0, &vA0, 2.0f);
                vA0.w = 5627.925f;
                func_L01_00443628(&sB0, m, p->w28, &vA0, p->f24);
                sB0.b19 = 1;
                sB0.h1A = m->hAA;
                sB0.b18 = 0;
                if (t->w18 != 0) {
                    if (t->w18 != p->q1C) func_003CF790(tv, 0, m, &sB0, 4.0f);
                } else {
                    func_003CF790(tv, 0, m, &sB0, 4.0f);
                }
            }
        }
        if (p->light == -1) {
            p->light = func_L01_00421F08(&m->pos, 5.0f, 0.0f, 0.45f, 0.2f, 1.0f);
        } else {
            L_0035D0F0 *l = &D_L07_001EFD40[p->light];
            l->pos = m->pos;
            l->pos.z = l->pos.z + 1.0f;
            l->pos.w = 5.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->x = 0.0f;
        }
        if (p->w14 < 0xB5) break;
        if (p->light != -1) func_L01_00421FE0(p->light);
        p->light = -1;
        func_003BD360(m);
        return;
    }
    case 1:
        func_00388830(&vA0, p, -0.5f);
        vec_add_ba(&vA0, &m->pos, &vA0);
        func_L01_0032FE90(&vA0, 0, 15, 12, 12, 12, 12, 1, 1.0f, 0.0f, 0.0f, 0.0f, 1, 1, 1, 1, 0, 1,
                          0x210000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430,
                          0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
        if (p->light != -1) func_L01_00421FE0(p->light);
        p->light = -1;
        func_003BD360(m);
        return;
    }
    vA0 = m->pos;
    vA0.w = 0.5f;
    if (func_003894E8(&vA0, 96.0f) > 0) {
        func_L01_004026A0_0035D0F0(func_L07_0035D5B0, m);
        sB0.v = m->pos;
        func_L07_0035D738(m, &sB0.v, &v90);
    }
}
/* localdecomp:end func_L07_0035D0F0 */
