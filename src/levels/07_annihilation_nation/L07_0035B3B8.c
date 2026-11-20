#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_0035B3B8 */
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
extern G16_35B3B8 D_001E8C18;
extern vu0_q D_001A4C60;

extern s32 func_L07_0035C958(M_35B3B8 *);
extern void func_L07_0035CC10(M_35B3B8 *, f32);
extern void func_L07_0035D080(M_35B3B8 *);
extern void func_L07_0035CAB8(M_35B3B8 *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_003C3410(u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045A898(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 *func_00382348(void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0045AA30(void *, void *);
extern s32 func_0038CAD0(void *);

void func_L07_0035B3B8(M_35B3B8 *m) {
    V_35B3B8 *v = m->vars;
    QV_35B3B8 pos0;
    QV_35B3B8 t;

    func_L07_0035C958(m);
    switch (m->state) {
    case 3: {
        s32 mode;
        f32 ang;
        f32 *yp;
        QV_35B3B8 *vp;
        if (func_L01_004561B8(m)) {
            M_35B3B8 *p = D_001A71A0.p;
            v->f1D0 = p;
            v->v190.q = p->pos;
            v->v180.q = p->pos;
            v->v1A0.q = p->pos;
            func_L07_0035CC10(m, 12.0f);
            v->v170.q = m->pos;
            func_L01_0045BD78(m, 0.0052000005f, 0.050000004f, 0.0050265486f, 0.25132743f);
        }
        mode = func_L01_003C3410((u8 *)m);
        if (mode == 0) {
            func_L07_0035D080(m);
            pos0.q = D_001A4C60;
            if (func_0038CF38(&v->v1A0, &pos0) > 1.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035CC10(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            vp = &v->v180;
            if (func_0038CF38(&m->pos, vp) < 0.75f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035CC10(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            if (func_0038CF38(&m->pos, &v->v170) > 4.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035CC10(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            v->v190.q = v->f1D0->pos;
            yp = &m->yaw;
            func_L01_0045A898(m, vp, m->yaw);
            ang = func_0038D160(v->v180.f[0] - m->pf[0], v->v180.f[1] - m->pf[1]);
            func_L01_00448890(yp, ang, v->f134, 0.012566371f, 0.012566371f, 0.62831855f, 0);
        }
        if (func_0038CF38(&m->pos, &D_001A4C60) < 2.0f) {
            if (m->b43 != 5) func_003C3A10(m, 5, 0, 8);
            func_L01_004450F0(m, 0, -1);
        }
        if (mode == 1) {
            if (v->f1CC <= m->pf[2] || fabs_asm(m->pf[2] - v->f1CC) < 0.5f) {
                func_L01_004450F0(m, 7, -1);
            } else {
                func_L01_004450F0(m, 8, -1);
            }
            if (m->b43 != 8) func_003C3A10(m, 8, 0, 7);
        } else if (mode == 2) {
            yp = &m->yaw;
            ang = func_0038D160(v->v190.f[0] - m->pf[0], v->v190.f[1] - m->pf[1]);
            func_L01_00448890(yp, ang, v->f134, 0.012566371f, 0.012566371f, 0.62831855f, 0);
        }
        break;
    }
    case 7: {
        f32 d;
        f32 *s;
        vu0_q *pp;
        pp = &m->pos;
        pos0.q = m->pos;
        if (func_L01_004561B8(m)) {
            v->f1C8 = 0;
            v->f1D4 = m->pf[2];
            v->v160.f[2] = v->f1CC;
            v->f150 = 0;
        }
        if (v->f140) {
            s = func_00382348(v->f140);
            d = func_0038CF38(pp, &v->f140->pos);
            if (d < 1.5f && v->f140 && v->f140->state != 0xFE && v->f140->state != 0xFD && s && *s > 0.0f) {
                func_L07_0035CAB8(m);
                break;
            }
            func_L01_003FB640(&m->pos, 1, (u8 *)m, 0.3f);
            if (D_001E8C18.p == v->f140) {
                func_L07_0035CAB8(m);
                break;
            }
        }
        d = func_L01_004395E0(m);
        if ((m->anim == 8 && 7.0f <= d) || (*(long *)&m->pad40 & 0xFFFF0000) == 0x07FF0000 ||
            m->anim == 6 || (m->anim == 7 && d <= 28.0f)) {
            if (m->pf[2] != v->f1CC) {
                f32 k = 0.20000002f;
                t.f[0] = func_0038D098(m->yaw) * k;
                t.f[1] = func_0038D0B0(m->yaw) * k;
                t.f[2] = 0;
                vec_add_ab(&pos0, &pos0, &t);
            }
        }
        if (m->b43 == 6) {
            if (fabs_asm(v->f1CC - m->pf[2]) <= 1.35f) {
                if (m->anim == 6) func_003C3A10(m, 7, 0, 0);
                else func_003C3A10(m, 7, 0, 7);
            } else if (m->anim != 6) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.002f, 0.004f, 0.080000006f);
            } else {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.016f, 0.040000003f, 0.76000005f);
            }
        }
        if ((*(long *)&m->pad40 & 0xFFFF0000) == 0x08080000) {
            if (7.0f <= func_L01_004395E0(m) && m->anim == m->b43) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1D4 + 1.35f, 0.028f, 0.008f, 0.6f);
            }
            if (m->b60 & 2) {
                v->f1C8 = 0;
                if (m->b43 != 6) func_003C3A10(m, 6, 0, 12);
            }
        }
        if (m->anim == 7) {
            if (func_L01_004395E0(m) <= 28.0f) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.012f, 0.040000003f, 0.15f);
            }
            if (m->b60 & 2) {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0(m, 3, -1);
            }
        }
        if (m->b43 == 7 && m->anim != m->b43 && m->anim != 6) {
            func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.002f, 0.012f, 0.080000006f);
        }
        vec_sub_ab(&t, &pos0, &m->pos);
        func_L01_0045AA30(m, &t);
        break;
    }
    case 8: {
        f32 d;
        f32 *s;
        vu0_q *pp;
        pp = &m->pos;
        pos0.q = m->pos;
        if (func_L01_004561B8(m)) {
            v->f1C8 = 0;
            v->f1D4 = m->pf[2];
            v->v160.f[2] = v->f1CC;
            v->f150 = 0;
        }
        if (v->f140) {
            s = func_00382348(v->f140);
            d = func_0038CF38(pp, &v->f140->pos);
            if (d < 1.5f && v->f140 && v->f140->state != 0xFE && v->f140->state != 0xFD && s && *s > 0.0f) {
                func_L07_0035CAB8(m);
                break;
            }
            func_L01_003FB640(&m->pos, 1, (u8 *)m, 0.3f);
            if (D_001E8C18.p == v->f140) {
                func_L07_0035CAB8(m);
                break;
            }
        }
        d = func_L01_004395E0(m);
        if ((m->anim == 8 && 7.0f <= d) || (*(long *)&m->pad40 & 0xFFFF0000) == 0x07FF0000 ||
            m->anim == 6 || (m->anim == 7 && d <= 28.0f)) {
            if (m->pf[2] != v->f1CC) {
                f32 k = 0.26000002f;
                t.f[0] = func_0038D098(m->yaw) * k;
                t.f[1] = func_0038D0B0(m->yaw) * k;
                t.f[2] = 0;
                vec_add_ab(&pos0, &m->pos, &t);
            }
        }
        if (m->b43 == 6) {
            if (fabs_asm(v->f1CC - m->pf[2]) <= 1.0f && v->f1C8 <= 0.0f) {
                if (m->anim == 6) func_003C3A10(m, 7, 0, 0);
                else func_003C3A10(m, 7, 0, 7);
            } else if (m->anim != 6) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.016f, 0.040000003f, 0.76000005f);
            } else {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.016f, 0.040000003f, 0.76000005f);
            }
        }
        if ((*(long *)&m->pad40 & 0xFFFF0000) == 0x08080000) {
            if (7.0f <= func_L01_004395E0(m) && m->anim == m->b43) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC + 4.0f, 0.028f, 0.008f, 1.2f);
            }
            if (m->b60 & 2) {
                if (m->b43 != 6) func_003C3A10(m, 6, 0, 12);
            }
        }
        if (m->anim == 7) {
            if (func_L01_004395E0(m) <= 28.0f) {
                func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.016f, 0.040000003f, 0.76000005f);
            }
            if (m->b60 & 2) {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0(m, 3, -1);
            }
        }
        if (m->b43 == 7 && m->anim != m->b43 && m->anim != 6) {
            func_003C41A0(&pos0.f[2], &v->f1C8, v->f1CC, 0.016f, 0.040000003f, 0.76000005f);
        }
        vec_sub_ab(&t, &pos0, &m->pos);
        func_L01_0045AA30(m, &t);
        break;
    }
    case 0: {
        s32 hit;
        hit = 0;
        if (m->anim == 5) {
            if (func_L01_0044E1B8(m, 59.0f)) {
                hit = 1;
                if (func_00382468(2)) {
                    if (m->b43 != hit) func_003C3A10(m, 1, 0, 3);
                } else {
                    if (m->b43 != 4) func_003C3A10(m, 4, 0, 3);
                }
            }
        }
        if (m->anim == 4) {
            if (func_L01_0044E1B8(m, 30.0f)) {
                hit = 1;
                if (func_00382468(2)) {
                    if (m->b43 != hit) func_003C3A10(m, 1, 0, 3);
                } else {
                    if (m->b43 != 5) func_003C3A10(m, 5, 0, 3);
                }
            }
        }
        if (m->anim == 1) {
            if (func_L01_0044E1B8(m, 35.0f)) {
                hit = 1;
                if (func_00382468(2)) {
                    if (m->b43 != 5) func_003C3A10(m, 5, 0, 3);
                } else {
                    if (m->b43 != 4) func_003C3A10(m, 4, 0, 3);
                }
            }
        }
        if (hit) {
            if (!func_00382468(10)) {
                if (m->b43 != 2) func_003C3A10(m, 2, 0, 14);
                func_L01_004450F0(m, 1, -1);
            }
            if (4.0f < func_0038CF38(&m->pos, &D_001A4C60)) {
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
                func_L01_004450F0(m, 3, -1);
            }
        }
        break;
    }
    case 1: {
        f32 ang;
        f32 *yp;
        if (func_L01_004561B8(m)) {
            f32 a;
            f32 b;
            v->f64 = 0.4f;
            func_L01_0045BD78(m, 0.00040000002f, 0.0050000004f, 0.0025132743f, 0.020943953f);
            a = func_00382538();
            b = func_003824E0(2.0f, 6.0f);
            qzero(&v->v160);
            v->v160.f[0] = func_0038D098(a) * b;
            v->v160.f[1] = func_0038D0B0(a) * b;
            vec_add_ba(&v->v160, &v->v160, &D_001A4C60);
        }
        func_L01_0045A898(m, &v->v160, m->yaw);
        yp = &m->yaw;
        ang = func_0038D160(v->v160.f[0] - m->pf[0], v->v160.f[1] - m->pf[1]);
            func_L01_00448890(yp, ang, v->f134, 0.0018151426f, 0.0018151426f, 0.020943953f, 0);
        if (func_0038CF38(&m->pos, &v->v160) <= 0.5f) {
            f32 a;
            f32 b;
            a = func_00382538();
            b = func_003824E0(2.0f, 6.0f);
            qzero(&v->v160);
            v->v160.f[0] = func_0038D098(a) * b;
            v->v160.f[1] = func_0038D0B0(a) * b;
            vec_add_ab(&v->v160, &v->v160, &D_001A4C60);
        }
        if (7.0f < func_0038CF38(&m->pos, &D_001A4C60)) {
            if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
            func_L01_004450F0(m, 3, -1);
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
        if (func_L01_004561B8(m)) {
            M_35B3B8 *p;
            func_L01_0045BD78(m, 0.0052000005f, 0.050000004f, 0.0050265486f, 0.25132743f);
            p = v->f140;
            v->f1D0 = p;
            v->v190.q = p->pos;
            v->v180.q = p->pos;
            v->v1A0.q = p->pos;
            func_L07_0035CC10(m, 12.0f);
            v->v170.q = m->pos;
            m->w78 = 0x80202080;
        }
        mode = func_L01_003C3410((u8 *)m);
        if (mode == 0) {
            func_L07_0035D080(m);
            pos0.q = v->f1D0->pos;
            if (func_0038CF38(&v->v1A0, &pos0) > 1.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035CC10(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            pp = &m->pos;
            vp = &v->v180;
            if (func_0038CF38(pp, vp) < 0.75f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035CC10(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            if (func_0038CF38(pp, &v->v170) > 4.0f) {
                v->v180.q = v->f1D0->pos;
                v->v1A0.q = v->f1D0->pos;
                func_L07_0035CC10(m, 12.0f);
                v->v170.q = m->pos;
                v->f1C0 = 0;
            }
            yp = &m->yaw;
            func_L01_0045A898(m, vp, m->yaw);
            ang = func_0038D160(v->v180.f[0] - m->pf[0], v->v180.f[1] - m->pf[1]);
            func_L01_00448890(yp, ang, v->f134, 0.012566371f, 0.012566371f, 0.62831855f, 0);
        }
        v->v190.q = v->f1D0->pos;
        if (mode == 1) {
            if (v->f1CC <= m->pf[2] || fabs_asm(m->pf[2] - v->f1CC) < 0.5f) {
                func_L01_004450F0(m, 7, -1);
            } else {
                func_L01_004450F0(m, 8, -1);
            }
            if (m->b43 != 8) func_003C3A10(m, 8, 0, 7);
        } else if (mode == 2) {
            yp = &m->yaw;
            ang = func_0038D160(v->v190.f[0] - m->pf[0], v->v190.f[1] - m->pf[1]);
            func_L01_00448890(yp, ang, v->f134, 0.012566371f, 0.012566371f, 0.62831855f, 0);
        }
        if (v->f140) {
            s = func_00382348(v->f140);
            if (v->f140 == 0 || v->f140->state == 0xFE || v->f140->state == 0xFD || (s && *s <= 0.0f)) {
                func_L01_004450F0(m, 3, -1);
                if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
            }
            if (func_0038CF38(&m->pos, &v->f140->pos) < 1.5f) func_L07_0035CAB8(m);
        } else {
            func_L01_004450F0(m, 3, -1);
            if (m->b43 != 3) func_003C3A10(m, 3, 0, 8);
        }
        break;
    }
    }
    if (func_0038CAD0(v->f144)) func_L07_0035CAB8(m);
}
/* localdecomp:end func_L07_0035B3B8 */

/* localdecomp:start func_L07_0035C880 */
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L07_0035C880(u8 *a0)
{
    u8 buf[0x10];
    s32 v;

    v = a0[0x20] == 5 ? 0x40202080 : 0x40802020;
    func_003C2F58(a0, 2, buf);
    func_003D9508(buf, 0xB, v, 1, 0.1f, 0.08f, 0.0f);
    func_003C2F58(a0, 3, buf);
    func_003D9508(buf, 0xB, v, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L07_0035C880 */

/* localdecomp:start func_L07_0035C958 */
extern void *func_L01_00450010(void *, s32, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L07_0035C880(u8 *);
extern s32 D_001DD6B0;
__asm__(".extern D_001DD6B0, 4");
s32 func_L07_0035C958(M_35B3B8 *self) {
    vu0_q pos;
    V_35B3B8 *v = self->vars;
    if (self->state != 5) {
        void *p;
        pos = self->pos;
        p = func_L01_00450010(&pos, 0, 1.5707964f, 20.0f, -1.0f, -1.0f);
        v->f140 = p;
        if (p && self->state != 8 && self->state != 7) {
            v->f1D0 = p;
            func_L01_004450F0(self, 5, -1);
            if (D_001DD6B0 == 2) {
                func_003C3A10(self, 0, 0, 0);
                self->speed = 2.0f;
            } else {
                func_003C3A10(self, 3, 0, 8);
                self->speed = 2.0f;
            }
        }
    }
    if (self->anim == 2) self->speed = 0.5f;
    else self->speed = 1.0f;
    func_L01_00404808(func_L07_0035C880, self);
    return 0;
}
/* localdecomp:end func_L07_0035C958 */
