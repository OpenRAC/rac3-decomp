#include "common.h"

/* NTSC-U counterpart of func_L07_0035B3B8 (src/levels/07_annihilation_nation/L07_0035B3B8.c) */
#include "vu0.h"

/* localdecomp:start func_L07_0035A4F8 */
typedef union { vu0_q q; f32 f[4]; } QV_35B3B8;
struct M_35B3B8;
typedef struct V_35B3B8 {
    u8 pad0[0x64];
    f32 f64;
    u8 pad68[0x134 - 0x68];
    u8 f134[0xC];
    struct M_35B3B8 *f140;
    u8 f144[0xC];
    s32 f150;
    u8 pad154[0x160 - 0x154];
    QV_35B3B8 v160;
    QV_35B3B8 v170;
    QV_35B3B8 v180;
    QV_35B3B8 v190;
    QV_35B3B8 v1A0;
    u8 pad1B0[0x1C0 - 0x1B0];
    s32 f1C0;
    u8 pad1C4[4];
    f32 f1C8;
    f32 f1CC;
    struct M_35B3B8 *f1D0;
    f32 f1D4;
} V_35B3B8;
typedef struct M_35B3B8 {
    u8 pad0[0x10];
    union { vu0_q pos; f32 pf[4]; };
    u8 state;
    u8 pad21[0x1F];
    u8 pad40[2];
    u8 anim;
    u8 b43;
    u8 pad44[4];
    f32 speed;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[7];
    V_35B3B8 *vars;
    u8 pad6C[0xC];
    u32 w78;
    u8 pad7C[0xF8 - 0x7C];
    f32 yaw;
} M_35B3B8;
typedef struct { M_35B3B8 *p; s32 pad[3]; } G16_35B3B8;
extern G16_35B3B8 D_001A71A0;
extern G16_35B3B8 D_L07_001E8C18_0035A4F8;
extern vu0_q D_001A4C60;

extern s32 func_L07_0035BA90(M_35B3B8 *);
extern void func_L07_0035BD48(M_35B3B8 *, f32);
extern void func_L07_0035C1B8(M_35B3B8 *);
extern void func_L07_0035BBF0(M_35B3B8 *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_003C1BA8(u8 *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00457590(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 *func_0037E0B8(void *);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern f32 func_L01_00436500(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003BEC60(void *, void *, f32, f32, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00457728(void *, void *);
extern s32 func_00388398(void *);

void func_L07_0035A4F8(M_35B3B8 *m) {
    V_35B3B8 *v = m->vars;
    QV_35B3B8 pos0;
    QV_35B3B8 t;

    func_L07_0035BA90(m);
    switch (m->state) {
    case 3: {
        s32 mode;
        f32 ang;
        f32 *yp;
        QV_35B3B8 *vp;
        if (func_L01_00452EC8(m)) {
            M_35B3B8 *p = D_001A71A0.p;
            v->f1D0 = p;
            v->v190.q = p->pos;
            v->v180.q = p->pos;
            v->v1A0.q = p->pos;
            func_L07_0035BD48(m, 12.0f);
            v->v170.q = m->pos;
            func_L01_00458A70(m, 0.003611111f, 0.041666668f, 0.0034906587f, 0.20943953f);
        }
        mode = func_L01_003C1BA8((u8 *)m);
        if (mode == 0) {
            func_L07_0035C1B8(m);
            pos0.q = D_001A4C60;
            if (func_00388800(&v->v1A0, &pos0) > 1.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035BD48(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            vp = &v->v180;
            if (func_00388800(&m->pos, vp) < 0.75f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035BD48(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            if (func_00388800(&m->pos, &v->v170) > 4.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035BD48(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            v->v190.q = v->f1D0->pos;
            yp = &m->yaw;
            func_L01_00457590(m, vp, m->yaw);
            ang = func_00388A28(v->v180.f[0] - m->pf[0], v->v180.f[1] - m->pf[1]);
            func_L01_00445758(yp, ang, v->f134, 0.008726646f, 0.008726646f, 0.5235988f, 0);
        }
        if (func_00388800(&m->pos, &D_001A4C60) < 2.0f) {
            if (m->b43 != 5) func_003BE4F0(m, 5, 0, 10);
            func_L01_00441FB8(m, 0, -1);
        }
        if (mode == 1) {
            if (v->f1CC <= m->pf[2] || fabs_asm(m->pf[2] - v->f1CC) < 0.5f) {
                func_L01_00441FB8(m, 7, -1);
            } else {
                func_L01_00441FB8(m, 8, -1);
            }
            if (m->b43 != 8) func_003BE4F0(m, 8, 0, 8);
        } else if (mode == 2) {
            yp = &m->yaw;
            ang = func_00388A28(v->v190.f[0] - m->pf[0], v->v190.f[1] - m->pf[1]);
            func_L01_00445758(yp, ang, v->f134, 0.008726646f, 0.008726646f, 0.5235988f, 0);
        }
        break;
    }
    case 7: {
        f32 d;
        f32 *s;
        vu0_q *pp;
        pp = &m->pos;
        pos0.q = m->pos;
        if (func_L01_00452EC8(m)) {
            v->f1C8 = 0;
            v->f1D4 = m->pf[2];
            v->v160.f[2] = v->f1CC;
            v->f150 = 0;
        }
        if (v->f140) {
            s = func_0037E0B8(v->f140);
            d = func_00388800(pp, &v->f140->pos);
            if (d < 1.5f && v->f140 && v->f140->state != 0xFE && v->f140->state != 0xFD && s && *s > 0.0f) {
                func_L07_0035BBF0(m);
                break;
            }
            func_L01_003F9498(&m->pos, 1, (u8 *)m, 0.3f);
            if (D_L07_001E8C18_0035A4F8.p == v->f140) {
                func_L07_0035BBF0(m);
                break;
            }
        }
        d = func_L01_00436500(m);
        if ((m->anim == 8 && 7.0f <= d) || (*(long *)&m->pad40 & 0xFFFF0000) == 0x07FF0000 ||
            m->anim == 6 || (m->anim == 7 && d <= 28.0f)) {
            if (m->pf[2] != v->f1CC) {
                f32 k = 0.16666667f;
                t.f[0] = func_00388960(m->yaw) * k;
                t.f[1] = func_00388978(m->yaw) * k;
                t.f[2] = 0;
                vec_add_ab(&pos0, &pos0, &t);
            }
        }
        if (m->b43 == 6) {
            if (fabs_asm(v->f1CC - m->pf[2]) <= 1.35f) {
                if (m->anim == 6) func_003BE4F0(m, 7, 0, 0);
                else func_003BE4F0(m, 7, 0, 8);
            } else if (m->anim != 6) {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.0013888889f, 0.0027777778f, 0.06666667f);
            } else {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.011111111f, 0.027777778f, 0.6333334f);
            }
        }
        if ((*(long *)&m->pad40 & 0xFFFF0000) == 0x08080000) {
            if (7.0f <= func_L01_00436500(m) && m->anim == m->b43) {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1D4 + 1.35f, 0.019444445f, 0.0055555557f, 0.5f);
            }
            if (m->b60 & 2) {
                v->f1C8 = 0;
                if (m->b43 != 6) func_003BE4F0(m, 6, 0, 15);
            }
        }
        if (m->anim == 7) {
            if (func_L01_00436500(m) <= 28.0f) {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.008333334f, 0.027777778f, 0.125f);
            }
            if (m->b60 & 2) {
                if (m->b43 != 3) func_003BE4F0(m, 3, 0, 10);
                func_L01_00441FB8(m, 3, -1);
            }
        }
        if (m->b43 == 7 && m->anim != m->b43 && m->anim != 6) {
            func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.0013888889f, 0.008333334f, 0.06666667f);
        }
        vec_sub_ab(&t, &pos0, &m->pos);
        func_L01_00457728(m, &t);
        break;
    }
    case 8: {
        f32 d;
        f32 *s;
        vu0_q *pp;
        pp = &m->pos;
        pos0.q = m->pos;
        if (func_L01_00452EC8(m)) {
            v->f1C8 = 0;
            v->f1D4 = m->pf[2];
            v->v160.f[2] = v->f1CC;
            v->f150 = 0;
        }
        if (v->f140) {
            s = func_0037E0B8(v->f140);
            d = func_00388800(pp, &v->f140->pos);
            if (d < 1.5f && v->f140 && v->f140->state != 0xFE && v->f140->state != 0xFD && s && *s > 0.0f) {
                func_L07_0035BBF0(m);
                break;
            }
            func_L01_003F9498(&m->pos, 1, (u8 *)m, 0.3f);
            if (D_L07_001E8C18_0035A4F8.p == v->f140) {
                func_L07_0035BBF0(m);
                break;
            }
        }
        d = func_L01_00436500(m);
        if ((m->anim == 8 && 7.0f <= d) || (*(long *)&m->pad40 & 0xFFFF0000) == 0x07FF0000 ||
            m->anim == 6 || (m->anim == 7 && d <= 28.0f)) {
            if (m->pf[2] != v->f1CC) {
                f32 k = 0.21666668f;
                t.f[0] = func_00388960(m->yaw) * k;
                t.f[1] = func_00388978(m->yaw) * k;
                t.f[2] = 0;
                vec_add_ab(&pos0, &m->pos, &t);
            }
        }
        if (m->b43 == 6) {
            if (fabs_asm(v->f1CC - m->pf[2]) <= 1.0f && v->f1C8 <= 0.0f) {
                if (m->anim == 6) func_003BE4F0(m, 7, 0, 0);
                else func_003BE4F0(m, 7, 0, 8);
            } else if (m->anim != 6) {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.011111111f, 0.027777778f, 0.6333334f);
            } else {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.011111111f, 0.027777778f, 0.6333334f);
            }
        }
        if ((*(long *)&m->pad40 & 0xFFFF0000) == 0x08080000) {
            if (7.0f <= func_L01_00436500(m) && m->anim == m->b43) {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC + 4.0f, 0.019444445f, 0.0055555557f, 1.0f);
            }
            if (m->b60 & 2) {
                if (m->b43 != 6) func_003BE4F0(m, 6, 0, 15);
            }
        }
        if (m->anim == 7) {
            if (func_L01_00436500(m) <= 28.0f) {
                func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.011111111f, 0.027777778f, 0.6333334f);
            }
            if (m->b60 & 2) {
                if (m->b43 != 3) func_003BE4F0(m, 3, 0, 10);
                func_L01_00441FB8(m, 3, -1);
            }
        }
        if (m->b43 == 7 && m->anim != m->b43 && m->anim != 6) {
            func_003BEC60(&pos0.f[2], &v->f1C8, v->f1CC, 0.011111111f, 0.027777778f, 0.6333334f);
        }
        vec_sub_ab(&t, &pos0, &m->pos);
        func_L01_00457728(m, &t);
        break;
    }
    case 0: {
        s32 hit;
        hit = 0;
        if (m->anim == 5) {
            if (func_L01_0044AF40(m, 59.0f)) {
                hit = 1;
                if (func_0037E1D8(2)) {
                    if (m->b43 != hit) func_003BE4F0(m, 1, 0, 4);
                } else {
                    if (m->b43 != 4) func_003BE4F0(m, 4, 0, 4);
                }
            }
        }
        if (m->anim == 4) {
            if (func_L01_0044AF40(m, 30.0f)) {
                hit = 1;
                if (func_0037E1D8(2)) {
                    if (m->b43 != hit) func_003BE4F0(m, 1, 0, 4);
                } else {
                    if (m->b43 != 5) func_003BE4F0(m, 5, 0, 4);
                }
            }
        }
        if (m->anim == 1) {
            if (func_L01_0044AF40(m, 35.0f)) {
                hit = 1;
                if (func_0037E1D8(2)) {
                    if (m->b43 != 5) func_003BE4F0(m, 5, 0, 4);
                } else {
                    if (m->b43 != 4) func_003BE4F0(m, 4, 0, 4);
                }
            }
        }
        if (hit) {
            if (!func_0037E1D8(10)) {
                if (m->b43 != 2) func_003BE4F0(m, 2, 0, 17);
                func_L01_00441FB8(m, 1, -1);
            }
            if (4.0f < func_00388800(&m->pos, &D_001A4C60)) {
                if (m->b43 != 3) func_003BE4F0(m, 3, 0, 10);
                func_L01_00441FB8(m, 3, -1);
            }
        }
        break;
    }
    case 1: {
        f32 ang;
        f32 *yp;
        if (func_L01_00452EC8(m)) {
            f32 a;
            f32 b;
            v->f64 = 0.4f;
            func_L01_00458A70(m, 0.00027777778f, 0.004166667f, 0.0017453294f, 0.017453294f);
            a = func_0037E2A8();
            b = func_0037E250(2.0f, 6.0f);
            qzero(&v->v160);
            v->v160.f[0] = func_00388960(a) * b;
            v->v160.f[1] = func_00388978(a) * b;
            vec_add_ba(&v->v160, &v->v160, &D_001A4C60);
        }
        func_L01_00457590(m, &v->v160, m->yaw);
        yp = &m->yaw;
        ang = func_00388A28(v->v160.f[0] - m->pf[0], v->v160.f[1] - m->pf[1]);
            func_L01_00445758(yp, ang, v->f134, 0.0012605157f, 0.0012605157f, 0.017453294f, 0);
        if (func_00388800(&m->pos, &v->v160) <= 0.5f) {
            f32 a;
            f32 b;
            a = func_0037E2A8();
            b = func_0037E250(2.0f, 6.0f);
            qzero(&v->v160);
            v->v160.f[0] = func_00388960(a) * b;
            v->v160.f[1] = func_00388978(a) * b;
            vec_add_ab(&v->v160, &v->v160, &D_001A4C60);
        }
        if (7.0f < func_00388800(&m->pos, &D_001A4C60)) {
            if (m->b43 != 3) func_003BE4F0(m, 3, 0, 10);
            func_L01_00441FB8(m, 3, -1);
        }
        break;
    }
    case 5: {
        s32 mode;
        f32 ang;
        f32 *yp;
        QV_35B3B8 *vp;
        vu0_q *pp;
        f32 *s;
        if (func_L01_00452EC8(m)) {
            M_35B3B8 *p;
            func_L01_00458A70(m, 0.003611111f, 0.041666668f, 0.0034906587f, 0.20943953f);
            p = v->f140;
            v->f1D0 = p;
            v->v190.q = p->pos;
            v->v180.q = p->pos;
            v->v1A0.q = p->pos;
            func_L07_0035BD48(m, 12.0f);
            v->v170.q = m->pos;
            m->w78 = 0x80202080;
        }
        mode = func_L01_003C1BA8((u8 *)m);
        if (mode == 0) {
            func_L07_0035C1B8(m);
            pos0.q = v->f1D0->pos;
            if (func_00388800(&v->v1A0, &pos0) > 1.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035BD48(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            pp = &m->pos;
            vp = &v->v180;
            if (func_00388800(pp, vp) < 0.75f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035BD48(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            if (func_00388800(pp, &v->v170) > 4.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035BD48(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            yp = &m->yaw;
            func_L01_00457590(m, vp, m->yaw);
            ang = func_00388A28(v->v180.f[0] - m->pf[0], v->v180.f[1] - m->pf[1]);
            func_L01_00445758(yp, ang, v->f134, 0.008726646f, 0.008726646f, 0.5235988f, 0);
        }
        v->v190.q = v->f1D0->pos;
        if (mode == 1) {
            if (v->f1CC <= m->pf[2] || fabs_asm(m->pf[2] - v->f1CC) < 0.5f) {
                func_L01_00441FB8(m, 7, -1);
            } else {
                func_L01_00441FB8(m, 8, -1);
            }
            if (m->b43 != 8) func_003BE4F0(m, 8, 0, 8);
        } else if (mode == 2) {
            yp = &m->yaw;
            ang = func_00388A28(v->v190.f[0] - m->pf[0], v->v190.f[1] - m->pf[1]);
            func_L01_00445758(yp, ang, v->f134, 0.008726646f, 0.008726646f, 0.5235988f, 0);
        }
        if (v->f140) {
            s = func_0037E0B8(v->f140);
            if (v->f140 == 0 || v->f140->state == 0xFE || v->f140->state == 0xFD || (s && *s <= 0.0f)) {
                func_L01_00441FB8(m, 3, -1);
                if (m->b43 != 3) func_003BE4F0(m, 3, 0, 10);
            }
            if (func_00388800(&m->pos, &v->f140->pos) < 1.5f) func_L07_0035BBF0(m);
        } else {
            func_L01_00441FB8(m, 3, -1);
            if (m->b43 != 3) func_003BE4F0(m, 3, 0, 10);
        }
        break;
    }
    }
    if (func_00388398(v->f144)) func_L07_0035BBF0(m);
}
/* localdecomp:end func_L07_0035A4F8 */
