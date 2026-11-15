#include "common.h"

/* localdecomp:start func_L39_00668660 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_00668660;
typedef struct { u8 p0[0x10]; V_00668660 v10; u8 p20[0xF8 - 0x20]; f32 fF8; } P_00668660;
typedef struct { u8 p0[0x1E0]; f32 f1E0; f32 f1E4; u8 p1E8[0xC]; f32 f1F4; u8 p1F8[0x2544 - 0x1F8]; s32 w2544; } Q_00668660;
typedef struct {
    u8 p0[0x2D0]; P_00668660 *p2D0; u8 p2D4[4]; Q_00668660 *p2D8; Q_00668660 *p2DC;
    u8 p2E0[0x1C]; s16 h2FC; u8 p2FE[8]; s16 h306; u8 p308[0xC]; f32 f314;
} E_00668660;
typedef struct { u8 p0[0xAA]; s16 hAA; } M_00668660;
typedef struct { u8 p0[0x18]; M_00668660 *p18; } G_00668660;
extern V_00668660 D_L39_0025F760_00668660[];
extern G_00668660 D_L39_0025F740;
__asm__(".extern D_001DAAF8_sda, 4");
__asm__(".extern D_001DAAFC_sda, 4");
extern f32 D_001DAAF8_sda;
extern f32 D_001DAAFC_sda;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00446E38(void *, void *, f32, s32, void *);
extern s32 func_L01_003FC480(void *, f32, f32, s32, void *);
extern s32 func_003D3CB0_00668660(void *, void *, s32, void *, s32);

void func_L39_00668660(E_00668660 *e, V_00668660 *out, s32 a2) {
    V_00668660 c;
    V_00668660 t;
    V_00668660 d;
    V_00668660 best;
    V_00668660 start;
    s32 i;
    s32 again;
    s32 hit;
    f32 rad;
    f32 h;
    f32 bot;
    f32 top;
    f32 step;
    f32 ang;
    f32 dist;
    f32 f;
    vu0_q q1, q2;

    rad = a2 ? e->p2D8->f1F4 : e->p2DC->f1F4;
    top = a2 ? e->p2D8->f1E0 : e->p2DC->f1E0;
    bot = a2 ? e->p2D8->f1E4 : e->p2DC->f1E4;
    h = top - bot;
    step = (f32)(a2 ? e->p2D8->w2544 : e->p2DC->w2544) * -2.0f * 0.017453292f;
    again = 1;
    i = 0;
    ang = -1.5707964f;
    if (a2) ang = 1.5707964f;
    dist = (e->h2FC == 2) ? D_001DAAF8_sda : 3.5f;
    if (e->h2FC == 2) {
        ang = 3.1415927f;
    }
    if (e->h306 == 3) {
        ang = func_0038DAB8(ang, 0.12217305f);
    } else if (e->h306 == 2) {
        ang = func_0038DAB8(ang, 0.24434610f);
    } else if (e->h306 == 1) {
        ang = func_0038DAB8(ang, 0.36651915f);
    }
    ang = func_0038DAB8(ang, step);
    start.q = e->p2D0->v10.q;
    start.f[2] += 1.5f;
    best.q = start.q;
    do {
        c.q = start.q;
        hit = 0;
        f = func_0038DAB8(ang, e->p2D0->fF8);
        d.f[0] = func_0038D098(f) * dist;
        d.f[1] = func_0038D0B0(f) * dist;
        d.f[2] = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)&d));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)&c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&t) : "j"(q1));
        f = func_L01_00446E38(&c, &t, rad, 0x84, e->p2D0);
        if (f > 0.9f) {
            func_0038CE20(&d, &d, f);
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)&c));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)&d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q2) : "j"(q2), "j"(q1));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&t) : "j"(q2));
            c.q = t.q;
            c.f[2] -= 2.5f;
            if (e->h2FC == 1 || func_003D3CB0_00668660(&t, &c, 4, 0, 0)) {
                f = func_L01_00446E38(&t, &c, rad, 0x84, 0);
                if (f > 0.0f) {
                    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)&t));
                    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)&c));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(q2) : "j"(q2), "j"(q1));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&d) : "j"(q2));
                    func_0038CE20(&d, &d, f);
                    __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)&t));
                    __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)&d));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
                    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&c) : "j"(q1));
                    if (f >= 1.0f) {
                        best.q = c.q;
                    } else {
                        if (h < 0.05f) h = 0.05f;
                        if (func_L01_003FC480(&c, rad, h, 4, 0)) {
                            M_00668660 *m = D_L39_0025F740.p18;
                            V_00668660 *n;
                            if (m == 0 || m->hAA == 0x1981) hit = 1;
                            n = &D_L39_0025F760_00668660[1];
                            best.q = n->q;
                            if (e->h2FC != 1) {
                                c.q = n->q;
                                t.q = n->q;
                                c.f[2] -= rad + 0.05f;
                                if (!func_003D3CB0_00668660(&t, &c, 4, 0, 0)) goto next;
                                if (hit) again = 0;
                                out->q = best.q = D_L39_0025F760_00668660[0].q;
                            } else {
                                if (hit) again = 0;
                                out->q = D_L39_0025F760_00668660[0].q;
                            }
                        } else {
                            out->q = best.q = c.q;
                        }
                        if (e->h2FC == 1) {
                            P_00668660 *p = e->p2D0;
                            if (p->v10.f[2] < out->f[2]) {
                                out->f[2] = e->p2D0->v10.f[2] - e->f314 - 0.5f;
                            }
                            if (func_003D3CB0_00668660(&e->p2D0->v10, out, 4, e->p2D0, 0)) {
                                __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)&D_L39_0025F760_00668660[0]));
                                __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)&e->p2D0->v10));
                                __asm__("vsub.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
                                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&d) : "j"(q1));
                                func_0038CF68(&d, &d, 0.05f);
                                __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(vu0_v4 *)&d));
                                __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(vu0_v4 *)&D_L39_0025F760_00668660[0]));
                                __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
                                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&c) : "j"(q1));
                                if (func_L01_003FC480(&c, rad, h, 4, e->p2D0)) {
                                    out->q = D_L39_0025F760_00668660[1].q;
                                }
                            }
                        }
                    }
                }
            }
        }
    next:
        if (++i >= 12) {
            out->q = best.q;
            again = 0;
        }
        if (a2) {
            ang = func_0038DB00(ang, D_001DAAFC_sda);
        } else {
            ang = func_0038DAB8(ang, D_001DAAFC_sda);
        }
    } while (again);
}
/* localdecomp:end func_L39_00668660 */
