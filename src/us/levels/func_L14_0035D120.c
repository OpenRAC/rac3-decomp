#include "common.h"

/* NTSC-U counterpart of func_L14_0035E1C0 (src/levels/shared/L14_0035E0E8.c) */
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
extern u8 *D_L14_001DF71C_0035D120;

/* localdecomp:start func_L14_0035D120 */
#include "vu0.h"


__asm__(".extern D_L14_001DF71C_0035D120, 16");
extern u8 *D_L14_001DF71C_0035D120;
extern s32 D_L14_001DF240_0035D120;
extern u8 *D_L14_0021DF80_0035D120[];
extern u8 D_L14_001D66B0_0035D120;

extern s32 func_L14_0035E230(u8*a0);
extern void func_L14_0035D048(u8*a0);
extern s32 func_L14_0035E860(Moby_0035E1C0 *);
extern void func_L14_0035E6F0(Moby_0035E1C0 *);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00451078(void *, void *);
extern void func_L02_00350598(void *);
extern s32 func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90_0035D120(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_00407180(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern f32 *func_0037E0B8(void *);
extern void func_L01_00457440(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00458AE0(void *, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_L09_0034FFC0(void *, f32, void *, void *, s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_0044E108(void *, void *, void *, f32);
extern void func_L01_00458E48(void *, void *, s32, s32);

void func_L14_0035D120(Moby_0035E1C0 *m) {
    Vars_0035E1C0 *v = m->vars68;
    vu0_v4 p90;
    vu0_v4 pA0;

    if (func_L14_0035E230(m)) {
        func_003BD360(m);
        return;
    }
    switch (m->sub95) {
    case 0:
        if (v->s234 == 1 && func_00388398(&v->t2DC)) {
            func_L01_00441FB8(m, 3, 2);
            if (v->f2E8 != -1) {
                func_L01_00441FB8(m, 6, -1);
                if (v->f2F0 != 0 && m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
            } else {
                if (m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
                func_L01_00441FB8(m, 4, -1);
            }
            break;
        }
        if (v->f2E0 != 0 && func_00388398(&v->t2DC)) {
            v->f2E0 = 0;
            if (v->f2D4 < 300) {
                v->f2D4 = func_0037E208(0x1E0, 600);
            }
        }
        break;
    case 1:
        if (v->s234 == 1) {
            func_L01_00441FB8(m, 3, 2);
            if (v->f2E8 != -1) {
                func_L01_00441FB8(m, 6, -1);
                if (v->f2F0 != 0 && m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
            } else {
                if (m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
                func_L01_00441FB8(m, 4, -1);
            }
        }
        break;
    case 2:
        if (v->s234 != 1) {
            if (m->b43 != 0) {
                func_003BE4F0(m, 0, 0, 10);
            }
            func_L01_00441FB8(m, 2, 1);
            v->f2D4 = func_0037E208(0x244, 600);
        }
        break;
    case 3: {
        s32 r = func_L01_00451078(m, v->v160);
        s32 s0;
        if ((r & 1) || v->f30 <= 0.0f) {
            func_L02_00350598(m);
            func_L14_0035D048(m);
            func_L01_0044ED60(m, 0x7FFF, &D_L14_001D66B0_0035D120, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
            func_0039FE80(0xE, 0, m);
            func_L01_0032FE90_0035D120(&m->x10, 0, 3, 3, 3, 5, 3, 0, 0.85f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(m);
            return;
        }
        if (r & 2) {
            if (v->s234 == 1) {
                if (m->b43 != 0) {
                    func_003BE4F0(m, 0, 0, 10);
                }
                s0 = v->f2E8;
                if (s0 != -1) {
                    func_L01_00441FB8(m, 6, 2);
                    if (v->f2F0 != 0 && m->b43 != 5) {
                        func_003BE4F0(m, 5, 0, 7);
                    }
                } else {
                    func_L01_00441FB8(m, 4, 2);
                    if (m->b43 != 5) {
                        func_003BE4F0(m, 5, 0, 10);
                    }
                    if (v->f2EC != s0) {
                        if (m->b43 != 5) {
                            func_003BE4F0(m, 5, 0, 10);
                        }
                        func_L01_00441FB8(m, 7, 2);
                    }
                }
            } else {
                if (m->b43 != 0) {
                    func_003BE4F0(m, 0, 0, 10);
                }
                func_L01_00441FB8(m, 2, 1);
                v->f2D4 = func_0037E208(0x244, 600);
            }
        }
        break;
    }
    case 7:
        m->w98 = 0;
        m->flags34 = (m->flags34 | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
        if (v->f32C != 0) {
            v->f328 = 0;
            func_L01_00441FB8(m, 3, 2);
            if (v->f2E8 != -1) {
                func_L01_00441FB8(m, 6, -1);
                if (v->f2F0 != 0 && m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
            } else {
                if (m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
                func_L01_00441FB8(m, 4, -1);
            }
            func_L01_00407180(m, &m->x10, (u8 *)m + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
        }
        break;
    case 5:
        if (v->f2D0 == 2) {
            func_L01_00441FB8(m, 1, 0);
        } else {
            f32 h = func_003BE7F0(&m->x10, 0, m, 1.0f);
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
        if (m->b42 == 0 && func_0037E1D8(100) == 0) {
            if (m->b43 != 1) {
                func_003BE4F0(m, 1, 0, 10);
            }
        }
        if (m->b42 == 1 && (m->b60 & 2) && m->b43 != 0) {
            func_003BE4F0(m, 0, 0, 10);
        }
        break;
    case 10:
        if (D_L14_001DF240_0035D120 >= 3) {
            u8 *e = D_L14_001DF71C_0035D120 + (v->f320 << 8);
            f32 *q = func_0037E0B8(e);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || *q <= 0.0f) {
                func_L01_00441FB8(m, 1, 0);
                func_L01_00407180(m, &m->x10, (u8 *)m + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
            }
        }
        break;
    case 3:
        if (v->f2E4 == 2) {
            func_L01_00457440(m, v->v220);
        } else {
            func_L01_00458A08(m, func_00388A28(v->v220[0] - m->x10, v->v220[1] - m->y14));
        }
        if (func_00388800(&m->x10, v->v220) < 10.0f) {
            if (m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 10);
            }
            func_L01_00441FB8(m, 4, -1);
        }
        break;
    case 6: {
        u8 *tp = D_L14_0021DF80_0035D120[v->f2E8];
        func_L01_00458AE0(m, v->f2E8);
        if (func_00388800(&m->x10, tp + (*(s32 *)tp << 4)) < (f32)v->f2E4 * 0.5f) {
            s32 five = 5;
            func_L01_00441FB8(m, 4, -1);
            if (m->b43 != five) {
                func_003BE4F0(m, 5, 0, 10);
            }
            if (v->f2EC != -1) {
                if (m->b43 != five) {
                    func_003BE4F0(m, 5, 0, 10);
                }
                func_L01_00441FB8(m, 7, -1);
            }
        }
        if (m->b42 == 5) {
            v->fA8 |= 0x10;
            func_L01_00458A08(m, func_00388A28(v->v220[0] - m->x10, v->v220[1] - m->y14));
            if (func_L14_0035E860(m) && m->b43 != 6) {
                func_003BE4F0(m, 6, 0, 2);
            }
        }
        if (m->b42 == 6) {
            v->fA8 |= 0x10;
            func_L01_00458A08(m, func_00388A28(v->v220[0] - m->x10, v->v220[1] - m->y14));
            if (func_L01_0044AF40(m, 1.0f)) {
                func_003BDA38(m, 0, &p90);
                vec_sub_ab(&pA0, v->v220, &p90);
                func_00388830(&pA0, &pA0, 0.25f);
                func_L09_0034FFC0(m, (f32)v->b44, &pA0, &p90, 0);
            }
            if ((m->b60 & 2) && m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 2);
            }
        }
        break;
    }
    case 4:
        if (func_L01_00452EC8(m)) {
            f32 h, k;
            *(vu0_q *)v->v310 = *(vu0_q *)&m->x10;
            h = func_0037E2A8();
            k = func_0037E250(2.0f, 2.5f);
            qzero(v->v300);
            v->v300[0] = func_00388960(h) * k;
            v->v300[1] = func_00388978(h) * k;
            vec_add_ab(v->v300, v->v310, v->v300);
            func_L01_00458A70(m, 0.0013888889f, 0.025000002f, 0.0069813174f, 0.20943953f);
        }
        {
            f32 h;
            func_L01_00458A08(m, func_00388A28(v->v220[0] - m->x10, v->v220[1] - m->y14));
            h = func_003BE7F0(&m->x10, 0, 0, 0.5f);
            if (h < m->z18) {
                func_L01_0044E108(m, v->v110, v->v110, v->f9C);
                if (m->z18 < h) {
                    m->z18 = h;
                }
            }
        }
        v->fA8 |= 0x10;
        func_L01_00457440(m, v->v300);
        if (func_00388800(&m->x10, v->v300) < 0.5f || v->fF0 >= 20) {
            f32 h, k;
            h = func_0037E2A8();
            k = func_0037E250(2.0f, 2.5f);
            qzero(v->v300);
            v->v300[0] = func_00388960(h) * k;
            v->v300[1] = func_00388978(h) * k;
            vec_add_ab(v->v300, v->v310, v->v300);
        }
        if (func_L14_0035E860(m) && func_00388398(&v->t2FC) && m->b42 == 5) {
            if (m->b43 != 6) {
                func_003BE4F0(m, 6, 0, 3);
            }
        } else if (m->b42 != 6 && m->b43 != 6 && m->b43 != 5) {
            func_003BE4F0(m, 5, 0, 3);
        }
        if (func_L01_0044AF40(m, 1.0f) && m->b42 == 6) {
            func_003BDA38(m, 0, &p90);
            vec_sub_ba(&pA0, v->v220, &p90);
            func_00388830(&pA0, &pA0, 0.25f);
            func_L09_0034FFC0(m, (f32)v->b44, &pA0, &p90, 0);
            v->t2FC = 120;
        }
        if (func_L01_0044AF40(m, 25.0f) && m->b42 == 6) {
            if (m->b43 != 0xB) {
                func_003BE4F0(m, 0xB, 0, 5);
            }
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 11:
        if (m->b60 & 2) {
            func_L01_00441FB8(m, 4, -1);
            if (m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 6);
            }
            v->t2FC = 120;
        }
        break;
    case 7: {
        f32 h;
        func_L01_00458A08(m, func_00388A28(v->v220[0] - m->x10, v->v220[1] - m->y14));
        h = func_003BE7F0(&m->x10, 0, 0, 0.5f);
        func_L01_0044E108(m, v->v110, v->v110, v->f9C);
        if (m->z18 < h) {
            m->z18 = h;
        }
        if (func_L14_0035E860(m) && func_00388398(&v->t2FC)) {
            if (m->b43 != 6) {
                func_003BE4F0(m, 6, 0, 3);
            }
        } else if (m->b43 != 5) {
            func_003BE4F0(m, 5, 0, 3);
        }
        if (func_L01_0044AF40(m, 3.5f) && m->b42 == 6) {
            func_003BDA38(m, 0, &p90);
            vec_sub_ab(&pA0, v->v220, &p90);
            func_00388830(&pA0, &pA0, 0.25f);
            func_L09_0034FFC0(m, (f32)v->b44, &pA0, &p90, 0);
        }
        if ((m->b60 & 2) && m->b42 == 6) {
            u8 *p;
            f32 d1, d2;
            v->t2FC = 60;
            func_L01_00441FB8(m, 8, -1);
            if (m->b43 != 0) {
                func_003BE4F0(m, 0, 0, 10);
            }
            p = D_L14_0021DF80_0035D120[v->f2EC];
            d1 = func_00388800(&m->x10, p + 0x10);
            d2 = func_00388800(&m->x10, p + (*(s32 *)p << 4));
            if (d2 < d1) {
                func_L01_00458E48(m, D_L14_0021DF80_0035D120[v->f2EC], 0, *(s32 *)p - 1);
            } else {
                func_L01_00458E48(m, D_L14_0021DF80_0035D120[v->f2EC], *(s32 *)p - 1, 0);
            }
            if (v->f2F4 != 0) {
                func_L01_00441FB8(m, 8, -1);
                if (m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 7);
                }
            }
        }
        break;
    }
    case 8:
        if (func_L01_00458AE0(m, v->f2EC)) {
            func_L01_00441FB8(m, 7, -1);
            if (m->b43 != 5) {
                func_003BE4F0(m, 5, 0, 10);
            }
        }
        if (m->b42 == 5) {
            v->fA8 |= 0x10;
            func_L01_00458A08(m, func_00388A28(v->v220[0] - m->x10, v->v220[1] - m->y14));
            if ((func_L01_0044AF40(m, 1.0f) || func_L01_0044AF40(m, 10.0f) || func_L01_0044AF40(m, 20.0f)) && func_L14_0035E860(m)) {
                func_003BDA38(m, 0, &p90);
                vec_sub_ab(&pA0, v->v220, &p90);
                func_00388830(&pA0, &pA0, 0.25f);
                func_L09_0034FFC0(m, (f32)v->b44, &pA0, &p90, 0);
            }
        }
        break;
    }
    func_L14_0035E6F0(m);
}
/* localdecomp:end func_L14_0035D120 */
