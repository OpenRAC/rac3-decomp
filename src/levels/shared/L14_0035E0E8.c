#include "common.h"

typedef struct {
    u8 p00[0x10];
    f32 x10;
    f32 y14;
    f32 z18;
    f32 w1C;
    u8 state20;
    u8 p21[0x13];
    u16 flags34;
    u8 p36[0xC];
    u8 b42;
    u8 b43;
    u8 p44[0x1C];
    u8 b60;
    u8 p61[7];
    void *vars68;
    u8 p6C[0x95 - 0x6C];
    u8 sub95;
    u8 p96[2];
    s32 w98;
} Moby_0035E1C0;
typedef struct {
    u8 p00[0x30];
    f32 f30;
    u8 p34[0x10];
    u8 b44;
    u8 p45[0x57];
    f32 f9C;
    u8 pA0[8];
    s32 fA8;
    u8 pAC[0x44];
    s32 fF0;
    u8 pF4[0x1C];
    f32 v110[4];
    u8 p120[0x40];
    f32 v160[4];
    u8 p170[0xB0];
    f32 v220[4];
    u8 p230[4];
    s16 s234;
    u8 p236[0x9A];
    s32 f2D0;
    s32 f2D4;
    u8 p2D8[4];
    s32 t2DC;
    s32 f2E0;
    s32 f2E4;
    s32 f2E8;
    s32 f2EC;
    s32 f2F0;
    s32 f2F4;
    u8 p2F8[4];
    s32 t2FC;
    f32 v300[4];
    f32 v310[4];
    s32 f320;
    u8 p324[4];
    s32 f328;
    s32 f32C;
} Vars_0035E1C0;

/* localdecomp:start func_L14_0035E0E8 */
extern u16 *D_L14_0021CCE0[];
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern s32 D_L14_001DF758;

void func_L14_0035E0E8(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L14_0021CCE0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L14_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L14_0021CCE0[a0[0x21]])) {
        e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            u8 *q = *(u8 **)(e + 0x68);
            if (*(s32 *)(q + 0x328) != 0) {
                *(u8 **)(q + 0x32C) = a0;
                *(s32 *)(q + 0x328) = 0;
                *(u16 *)(e + 0x34) &= 0xFFFD;
                return;
            }
        }
    }
}
/* localdecomp:end func_L14_0035E0E8 */

/* localdecomp:start func_L14_0035E1C0 */
#include "vu0.h"


__asm__(".extern D_L14_001DF71C, 16");
extern u8 *D_L14_001DF71C;
extern s32 D_L14_001DF240;
extern u8 *D_L14_0021DF80[];
extern u8 D_L14_001D66B0;

extern s32 func_L14_0035F2F8(u8*a0);
extern void func_L14_0035E0E8(u8*a0);
extern s32 func_L14_0035F928(Moby_0035E1C0 *);
extern void func_L14_0035F7B8(Moby_0035E1C0 *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L02_003516A8(void *);
extern s32 func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_00409598(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 *func_00382348(void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_0045BDE8(void *, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L09_00350968(void *, f32, void *, void *, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00451388(void *, void *, void *, f32);
extern void func_L01_0045C150(void *, void *, s32, s32);

void func_L14_0035E1C0(Moby_0035E1C0 *m) {
    Vars_0035E1C0 *v = m->vars68;
    vu0_v4 p90;
    vu0_v4 pA0;

    if (func_L14_0035F2F8(m)) {
        func_003C2880(m);
        return;
    }
    switch (m->sub95) {
    case 0:
        if (v->s234 == 1 && func_0038CAD0(&v->t2DC)) {
            func_L01_004450F0(m, 3, 2);
            if (v->f2E8 != -1) {
                func_L01_004450F0(m, 6, -1);
                if (v->f2F0 != 0 && m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
            } else {
                if (m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
                func_L01_004450F0(m, 4, -1);
            }
            break;
        }
        if (v->f2E0 != 0 && func_0038CAD0(&v->t2DC)) {
            v->f2E0 = 0;
            if (v->f2D4 < 250) {
                v->f2D4 = (func_00382498(0x1E0, 600) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (v->s234 == 1) {
            func_L01_004450F0(m, 3, 2);
            if (v->f2E8 != -1) {
                func_L01_004450F0(m, 6, -1);
                if (v->f2F0 != 0 && m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
            } else {
                if (m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
                func_L01_004450F0(m, 4, -1);
            }
        }
        break;
    case 2:
        if (v->s234 != 1) {
            if (m->b43 != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
            func_L01_004450F0(m, 2, 1);
            v->f2D4 = (func_00382498(0x244, 600) * 5 + 2) / 6;
        }
        break;
    case 3: {
        s32 r = func_L01_00454370(m, v->v160);
        s32 s0;
        if ((r & 1) || v->f30 <= 0.0f) {
            func_L02_003516A8(m);
            func_L14_0035E0E8(m);
            func_L01_00451FE0(m, 0x7FFF, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
            func_003A52A0(0xE, 0, m);
            func_L01_003303B8(&m->x10, 0, 3, 3, 3, 5, 3, 0, 0.85f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003C2880(m);
            return;
        }
        if (r & 2) {
            if (v->s234 == 1) {
                if (m->b43 != 0) {
                    func_003C3A10(m, 0, 0, 8);
                }
                s0 = v->f2E8;
                if (s0 != -1) {
                    func_L01_004450F0(m, 6, 2);
                    if (v->f2F0 != 0 && m->b43 != 5) {
                        func_003C3A10(m, 5, 0, 6);
                    }
                } else {
                    func_L01_004450F0(m, 4, 2);
                    if (m->b43 != 5) {
                        func_003C3A10(m, 5, 0, 8);
                    }
                    if (v->f2EC != s0) {
                        if (m->b43 != 5) {
                            func_003C3A10(m, 5, 0, 8);
                        }
                        func_L01_004450F0(m, 7, 2);
                    }
                }
            } else {
                if (m->b43 != 0) {
                    func_003C3A10(m, 0, 0, 8);
                }
                func_L01_004450F0(m, 2, 1);
                v->f2D4 = (func_00382498(0x244, 600) * 5 + 2) / 6;
            }
        }
        break;
    }
    case 7:
        m->w98 = 0;
        m->flags34 = (m->flags34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        if (v->f32C != 0) {
            v->f328 = 0;
            func_L01_004450F0(m, 3, 2);
            if (v->f2E8 != -1) {
                func_L01_004450F0(m, 6, -1);
                if (v->f2F0 != 0 && m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
            } else {
                if (m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
                func_L01_004450F0(m, 4, -1);
            }
            func_L01_00409598(m, &m->x10, (u8 *)m + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
        }
        break;
    case 5:
        if (v->f2D0 == 2) {
            func_L01_004450F0(m, 1, 0);
        } else {
            f32 h = func_003C3D30(&m->x10, 0, m, 1.0f);
            if (h > 0.0f) {
                m->z18 = h;
            }
        }
        break;
    }

    switch (m->state20) {
    case 1:
    case 5:
    case 9:
        break;
    case 2:
        if (m->b42 == 0 && func_00382468(100) == 0) {
            if (m->b43 != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
        }
        if (m->b42 == 1 && (m->b60 & 2) && m->b43 != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
        break;
    case 10:
        if (D_L14_001DF240 >= 3) {
            u8 *e = D_L14_001DF71C + (v->f320 << 8);
            f32 *q = func_00382348(e);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || *q <= 0.0f) {
                func_L01_004450F0(m, 1, 0);
                func_L01_00409598(m, &m->x10, (u8 *)m + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
            }
        }
        break;
    case 3:
        if (v->f2E4 == 2) {
            func_L01_0045A748(m, v->v220);
        } else {
            func_L01_0045BD10(m, func_0038D160(v->v220[0] - m->x10, v->v220[1] - m->y14));
        }
        if (func_0038CF38(&m->x10, v->v220) < 10.0f) {
            if (m->b43 != 5) {
                func_003C3A10(m, 5, 0, 8);
            }
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 6: {
        u8 *tp = D_L14_0021DF80[v->f2E8];
        func_L01_0045BDE8(m, v->f2E8);
        if (func_0038CF38(&m->x10, tp + (*(s32 *)tp << 4)) < (f32)v->f2E4 * 0.5f) {
            s32 five = 5;
            func_L01_004450F0(m, 4, -1);
            if (m->b43 != five) {
                func_003C3A10(m, 5, 0, 8);
            }
            if (v->f2EC != -1) {
                if (m->b43 != five) {
                    func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 7, -1);
            }
        }
        if (m->b42 == 5) {
            v->fA8 |= 0x10;
            func_L01_0045BD10(m, func_0038D160(v->v220[0] - m->x10, v->v220[1] - m->y14));
            if (func_L14_0035F928(m) && m->b43 != 6) {
                func_003C3A10(m, 6, 0, 2);
            }
        }
        if (m->b42 == 6) {
            v->fA8 |= 0x10;
            func_L01_0045BD10(m, func_0038D160(v->v220[0] - m->x10, v->v220[1] - m->y14));
            if (func_L01_0044E1B8(m, 1.0f)) {
                func_003C2F58(m, 0, &p90);
                vec_sub_ab(&pA0, v->v220, &p90);
                func_0038CF68(&pA0, &pA0, 0.3f);
                func_L09_00350968(m, (f32)v->b44, &pA0, &p90, 0);
            }
            if ((m->b60 & 2) && m->b43 != 5) {
                func_003C3A10(m, 5, 0, 2);
            }
        }
        break;
    }
    case 4:
        if (func_L01_004561B8(m)) {
            f32 h, k;
            *(vu0_q *)v->v310 = *(vu0_q *)&m->x10;
            h = func_00382538();
            k = func_003824E0(2.0f, 2.5f);
            qzero(v->v300);
            v->v300[0] = func_0038D098(h) * k;
            v->v300[1] = func_0038D0B0(h) * k;
            vec_add_ab(v->v300, v->v310, v->v300);
            func_L01_0045BD78(m, 0.002f, 0.030000001f, 0.010053097f, 0.25132743f);
        }
        {
            f32 h;
            func_L01_0045BD10(m, func_0038D160(v->v220[0] - m->x10, v->v220[1] - m->y14));
            h = func_003C3D30(&m->x10, 0, 0, 0.5f);
            if (h < m->z18) {
                func_L01_00451388(m, v->v110, v->v110, v->f9C);
                if (m->z18 < h) {
                    m->z18 = h;
                }
            }
        }
        v->fA8 |= 0x10;
        func_L01_0045A748(m, v->v300);
        if (func_0038CF38(&m->x10, v->v300) < 0.5f || v->fF0 >= 20) {
            f32 h, k;
            h = func_00382538();
            k = func_003824E0(2.0f, 2.5f);
            qzero(v->v300);
            v->v300[0] = func_0038D098(h) * k;
            v->v300[1] = func_0038D0B0(h) * k;
            vec_add_ab(v->v300, v->v310, v->v300);
        }
        if (func_L14_0035F928(m) && func_0038CAD0(&v->t2FC) && m->b42 == 5) {
            if (m->b43 != 6) {
                func_003C3A10(m, 6, 0, 2);
            }
        } else if (m->b42 != 6 && m->b43 != 6 && m->b43 != 5) {
            func_003C3A10(m, 5, 0, 2);
        }
        if (func_L01_0044E1B8(m, 1.0f) && m->b42 == 6) {
            func_003C2F58(m, 0, &p90);
            vec_sub_ba(&pA0, v->v220, &p90);
            func_0038CF68(&pA0, &pA0, 0.3f);
            func_L09_00350968(m, (f32)v->b44, &pA0, &p90, 0);
            v->t2FC = 100;
        }
        if (func_L01_0044E1B8(m, 25.0f) && m->b42 == 6) {
            if (m->b43 != 0xB) {
                func_003C3A10(m, 0xB, 0, 4);
            }
            func_L01_004450F0(m, 0xB, -1);
        }
        break;
    case 11:
        if (m->b60 & 2) {
            func_L01_004450F0(m, 4, -1);
            if (m->b43 != 5) {
                func_003C3A10(m, 5, 0, 5);
            }
            v->t2FC = 100;
        }
        break;
    case 7: {
        f32 h;
        func_L01_0045BD10(m, func_0038D160(v->v220[0] - m->x10, v->v220[1] - m->y14));
        h = func_003C3D30(&m->x10, 0, 0, 0.5f);
        func_L01_00451388(m, v->v110, v->v110, v->f9C);
        if (m->z18 < h) {
            m->z18 = h;
        }
        if (func_L14_0035F928(m) && func_0038CAD0(&v->t2FC)) {
            if (m->b43 != 6) {
                func_003C3A10(m, 6, 0, 2);
            }
        } else if (m->b43 != 5) {
            func_003C3A10(m, 5, 0, 2);
        }
        if (func_L01_0044E1B8(m, 3.5f) && m->b42 == 6) {
            func_003C2F58(m, 0, &p90);
            vec_sub_ab(&pA0, v->v220, &p90);
            func_0038CF68(&pA0, &pA0, 0.3f);
            func_L09_00350968(m, (f32)v->b44, &pA0, &p90, 0);
        }
        if ((m->b60 & 2) && m->b42 == 6) {
            u8 *p;
            f32 d1, d2;
            v->t2FC = 50;
            func_L01_004450F0(m, 8, -1);
            if (m->b43 != 0) {
                func_003C3A10(m, 0, 0, 8);
            }
            p = D_L14_0021DF80[v->f2EC];
            d1 = func_0038CF38(&m->x10, p + 0x10);
            d2 = func_0038CF38(&m->x10, p + (*(s32 *)p << 4));
            if (d2 < d1) {
                func_L01_0045C150(m, D_L14_0021DF80[v->f2EC], 0, *(s32 *)p - 1);
            } else {
                func_L01_0045C150(m, D_L14_0021DF80[v->f2EC], *(s32 *)p - 1, 0);
            }
            if (v->f2F4 != 0) {
                func_L01_004450F0(m, 8, -1);
                if (m->b43 != 5) {
                    func_003C3A10(m, 5, 0, 6);
                }
            }
        }
        break;
    }
    case 8:
        if (func_L01_0045BDE8(m, v->f2EC)) {
            func_L01_004450F0(m, 7, -1);
            if (m->b43 != 5) {
                func_003C3A10(m, 5, 0, 8);
            }
        }
        if (m->b42 == 5) {
            v->fA8 |= 0x10;
            func_L01_0045BD10(m, func_0038D160(v->v220[0] - m->x10, v->v220[1] - m->y14));
            if ((func_L01_0044E1B8(m, 1.0f) || func_L01_0044E1B8(m, 10.0f) || func_L01_0044E1B8(m, 20.0f)) && func_L14_0035F928(m)) {
                func_003C2F58(m, 0, &p90);
                vec_sub_ab(&pA0, v->v220, &p90);
                func_0038CF68(&pA0, &pA0, 0.3f);
                func_L09_00350968(m, (f32)v->b44, &pA0, &p90, 0);
            }
        }
        break;
    }
    func_L14_0035F7B8(m);
}
/* localdecomp:end func_L14_0035E1C0 */

/* localdecomp:start func_L14_0035F2F8 */
extern s32 func_L14_0035F538(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L02_003516A8(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 D_001D545C;
extern s32 D_001D67C4;

s32 func_L14_0035F2F8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);

    if (a0[0x20] == 0 && func_L14_0035F538(a0) != 0) {
        return 1;
    }
    if (v[0x3E] == 2) {
        goto die;
    }
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 0) != 0) {
        func_L01_003A6BB0(a0);
    }
    if (v[0x5E] != 0) {
die:
        func_L02_003516A8(a0);
        return 1;
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5F] != 0) {
        if (D_001D545C == 0x16 && *(s32 *)(v + 0x330) == 0) {
            s32 n = D_001D67C4;
            *(s32 *)(v + 0x330) = 1;
            n++;
            D_001D67C4 = n;
            if (n >= 15) {
                func_L01_00459C50(0x17);
            }
        }
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else if (*(s32 *)(v + 0x324) != 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 4, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L14_0035F2F8 */

INCLUDE_ASM("asm/levels", func_L14_0035F538);
