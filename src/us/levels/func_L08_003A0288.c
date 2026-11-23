#include "common.h"

/* NTSC-U counterpart of func_L08_003A1FA0 (src/levels/shared/L08_003A1BE8.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A1FA0;
typedef struct { s32 n; s32 pad[3]; V4_003A1FA0 pt[1]; } Path_003A1FA0;
extern u8 D_L08_001D66B0_003A0288[8];
extern f32 D_L08_001DE280_003A0288;
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void *func_L08_003A81D8(void *, void *, void *, f32, f32);

/* localdecomp:start func_L08_003A0288 */
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)
#define P8(p, o) (((struct { u8 _p[o]; u8 *v; } *)(p))->v)


extern u8 *D_L08_001DF21C_003A0288;
extern Path_003A1FA0 *D_L08_0021D140_003A0288[];
extern s32 D_001D545C;
extern s32 D_L08_001DE270_003A0288;
__asm__(".extern D_L08_001DE270_003A0288, 4");
extern f32 D_L08_001DE274_003A0288;
__asm__(".extern D_L08_001DE274_003A0288, 4");
extern f32 D_L08_001DE278_003A0288;
__asm__(".extern D_L08_001DE278_003A0288, 4");
extern f32 D_L08_001DE27C_003A0288;
__asm__(".extern D_L08_001DE27C_003A0288, 4");
extern f32 D_L08_001DE284_003A0288;
__asm__(".extern D_L08_001DE284_003A0288, 4");
extern s32 D_L08_001DE288_003A0288;
__asm__(".extern D_L08_001DE288_003A0288, 4");
extern s32 D_L08_001DE28C_003A0288;
__asm__(".extern D_L08_001DE28C_003A0288, 4");
extern s32 D_L08_001DE290_003A0288;
__asm__(".extern D_L08_001DE290_003A0288, 4");
extern s32 D_L08_001DE294;
__asm__(".extern D_L08_001DE294, 4");
__asm__(".extern D_L08_001DE280_003A0288, 4");
extern f32 D_L08_001DE298;
__asm__(".extern D_L08_001DE298, 4");

extern s32 func_L08_003A1638(void *);
extern void func_L08_003A1DD8(void *);
extern s32 func_L08_003A1F48(u8 *, s32);
extern s32 func_L08_003A20D8(u8 *, s32);
extern void func_L08_003A1A58(void *);
extern void func_L02_003F1FE8(s32, u32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern void func_003BD360(void *);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L01_0044ED60(u8 *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00458E48(void *, void *, s32, s32);
extern void func_L01_00457440(void *, void *);
extern void func_L01_00443790(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_L01_00436500(void *);
extern s32 func_L01_00458AE0(void *, s32);
extern s32 func_L01_004562A0(void *, s32, f32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_00444740(void *, void *, s32, f32, f32);
extern void func_L01_003154D8(void *, s32, s32);
extern void func_003BF6A8(void *, f32);
extern void func_003BDA38(void *, s32, void *);

#define kill_3A1FA0(obj) { \
    u8 *o_ = (obj); \
    f32 a_ = 3.0f; \
    f32 b_ = 6.0f; \
    f32 c_ = -1.0f; \
    f32 d_ = 1.0f; \
    func_L01_0044ED60(o_, 0x4FFF, D_L08_001D66B0_003A0288, a_, b_, a_, b_, 0xFF, c_, c_, 0xB4, 0, 0, 0x23, d_, d_, 0, 3); \
    func_L01_0044ED60(o_, 0x4FFF, D_L08_001D66B0_003A0288, a_, b_, a_, b_, 0xFF, c_, c_, 0xB4, 0, 0, 0x23, d_, d_, 0, 3); \
    func_L01_004412D0(o_, 0, 3); \
    func_003BD360(o_); \
}

#define kill_cur_3A1FA0(st) { \
    s32 idx_ = S32(st, 0x318) ? S32(st, 0x2F8) : S32(st, 0x2E0); \
    if (idx_ != -1) { \
        kill_3A1FA0(D_L08_001DF21C_003A0288 + (idx_ << 8)) \
        if (S32(st, 0x318) == 0) { \
            S32(st, 0x2E0) = -1; \
        } else { \
            S32(st, 0x2F8) = -1; \
        } \
    } \
}

void func_L08_003A0288(u8 *m) {
    u8 *st = P8(m, 0x68);
    V4_003A1FA0 v10;
    V4_003A1FA0 v20;
    V4_003A1FA0 v30;
    s32 i;
    s32 t;
    s32 fl;
    s32 k;
    s32 r;
    Path_003A1FA0 *p;
    f32 d0;
    f32 dz;
    f32 f;

    if (func_L08_003A1638(m) != 0) {
        func_003BD360(m);
        return;
    }
    switch (U8(m, 0x95)) {
    case 3:
        fl = 0;
        if (func_L08_003A1F48(m, 0)) {
            fl = 1;
            S32(st, 0x318) = 0;
        } else if (func_L08_003A1F48(m, 1)) {
            S32(st, 0x318) = 1;
            fl = 1;
        }
        if (S32(st, 0x320) != 0) {
            if (func_L01_00453210(st + 0x220, S32(st, 0x2D8))) {
                func_L01_00441FB8(m, 1, 0);
            }
        }
        if (S32(st, 0x324) != 0) {
            if (func_L01_00453210(st + 0x220, S32(st, 0x2F0))) {
                func_L01_00441FB8(m, 1, 0);
            }
        }
        if (fl) {
            s32 cur;
            ((struct { u8 _p[0x320]; s32 v[2]; } *)st)->v[S32(st, 0x318)] = 1;
            U16(m, 0x34) &= 0xFFBE;
            U16(m, 0x34) |= U16(P8(m, 0x24), 0x44) & 0x1000;
            S32(m, 0x98) = S32(P8(m, 0x24), 0x10);
            func_L01_00441FB8(m, 4, 1);
            if (U8(m, 0x43) != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
            cur = S32(st, 0x318) ? S32(st, 0x2F8) : S32(st, 0x2E0);
            if (cur != -1) {
                func_L01_00441FB8(m, 2, 1);
            }
        }
        break;
    case 0:
        if (S16(st, 0x234) == 1) {
            if (func_L08_003A20D8(m, 0)) {
                S32(st, 0x318) = 0;
                if (S32(st, 0x320) == 0) {
                    func_L01_00441FB8(m, 0xB, 3);
                } else {
                    func_L01_00441FB8(m, 4, 1);
                    if (U8(m, 0x43) != 2) {
                        func_003BE4F0(m, 2, 0, 10);
                    }
                }
            } else if (func_L08_003A20D8(m, 1)) {
                S32(st, 0x318) = 1;
                if (S32(st, 0x324) == 0) {
                    func_L01_00441FB8(m, 0xB, 3);
                } else {
                    func_L01_00441FB8(m, 4, 1);
                    if (U8(m, 0x43) != 2) {
                        func_003BE4F0(m, 2, 0, 10);
                    }
                }
            }
        }
        break;
    case 1:
        if (S16(st, 0x234) != 1 && func_L01_00452EF0(m) == 0) {
            func_L01_00441FB8(m, 6, 0);
            if (U8(m, 0x43) != 3) {
                func_003BE4F0(m, 3, 0, 10);
            }
            S32(st, 0x30C) = func_0037E208(0x244, 0x258);
        }
        func_L01_00443648(m, m + 0x10, 0x10000, 0, 1, 0, D_L08_001DE298, 8.0f, 1.0f);
        break;
    case 2:
        t = func_L01_00451078(m, st + 0x160);
        if (func_L01_00452EC8(m) && U8(m, 0x94) == 2) {
            kill_cur_3A1FA0(st)
        }
        if (t & 1) {
            func_L08_003A1A58(m);
            func_L01_003154D8(m, 7, 0);
            { V4_003A1FA0 *p20 = &v20;
            V4_003A1FA0 *p10 = &v10;
            for (i = 4; i < 8; i++) {
                func_003BDA38(m, i, p20);
                v10 = v20;
                v10.w = 5.0f;
                if (func_L01_004562A0(p10, 0, 255.0f) >= 0) {
                    func_L08_0039FF30(m, (u8 *)p20);
                }
            } }
            if (S32(st, 0x2E0) != -1) {
                kill_3A1FA0(D_L08_001DF21C_003A0288 + (S32(st, 0x2E0) << 8))
            }
            if (S32(st, 0x2F8) != -1) {
                kill_3A1FA0(D_L08_001DF21C_003A0288 + (S32(st, 0x2F8) << 8))
            }
            return;
        }
        if (t & 2) {
            if (S16(st, 0x234) == 1) {
                func_L01_00441FB8(m, 4, 1);
                if (U8(m, 0x43) != 2) {
                    func_003BE4F0(m, 2, 0, 10);
                }
            } else {
                func_L01_00441FB8(m, 1, 0);
                S32(st, 0x30C) = func_0037E208(0x244, 0x258);
            }
        }
        break;
    }

    switch (U8(m, 0x20)) {
    case 1:
        if (func_L01_00452EC8(m) && U8(m, 0x43) != 1) {
            func_003BE4F0(m, 1, 0, 10);
        }
        break;
    case 2:
        if (S32(st, 0x318) != 0 && S32(st, 0x2E8) == -1) {
            S32(st, 0x318) = 0;
        }
        { s32 n2 = S32(st, 0x318) ? S32(st, 0x2E8) : S32(st, 0x2D0);
        p = D_L08_0021D140_003A0288[n2]; }
        if (func_L01_00452EC8(m)) {
            if (D_001D545C == 8) {
                func_L02_003F1FE8(0xB76, 0x4650);
            }
            if (U8(m, 0x43) != 0) {
                func_003BE4F0(m, 0, 0, 10);
            }
            d0 = func_L01_0040C040(&p->pt[0], st + 0x2C0);
            if (func_L01_0040C040((u8 *)p + (p->n << 4), st + 0x2C0) < d0) {
                F32(m, 0x10) = p->pt[p->n - 1].x;
                F32(m, 0x14) = p->pt[p->n - 1].y;
            } else {
                F32(m, 0x10) = p->pt[0].x;
                F32(m, 0x14) = p->pt[0].y;
            }
            F32(m, 0xF8) = func_00388A28(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14));
        }
        if (func_L01_0044AF40(m, 20.0f) && U8(m, 0x42) == 0) {
            u8 *o;
            if (S32(st, 0x318) != 0) {
                o = D_L08_001DF21C_003A0288 + (S32(st, 0x2F8) << 8);
            } else {
                o = D_L08_001DF21C_003A0288 + (S32(st, 0x2E0) << 8);
            }
            if (S32(st, 0x2E0) == -1 && S32(st, 0x318) == 0 && S32(st, 0x2F8) != -1) {
                o = D_L08_001DF21C_003A0288 + (S32(st, 0x2F8) << 8);
            }
            kill_3A1FA0(o)
            if (S32(st, 0x318) == 0) {
                S32(st, 0x2E0) = -1;
            } else {
                S32(st, 0x2F8) = -1;
            }
        }
        if (U8(m, 0x60) & 2) {
            func_L01_00441FB8(m, 4, -1);
            if (U8(m, 0x43) != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
        }
        break;
    case 4:
        if (S32(st, 0x318) != 0 && S32(st, 0x2E8) == -1) {
            S32(st, 0x318) = 0;
        }
        if (S32(st, 0x318) == 0 && S32(st, 0x2E0) != -1) {
            kill_3A1FA0(D_L08_001DF21C_003A0288 + (S32(st, 0x2E0) << 8))
            if (S32(st, 0x318) == 0) {
                S32(st, 0x2E0) = -1;
            }
        } else if (S32(st, 0x318) != 0 && S32(st, 0x2F8) != -1) {
            kill_3A1FA0(D_L08_001DF21C_003A0288 + (S32(st, 0x2F8) << 8))
            if (S32(st, 0x318) != 0) {
                S32(st, 0x2F8) = -1;
            }
        }
        k = S32(st, 0x318) ? S32(st, 0x2E8) : S32(st, 0x2D0);
        if (func_L01_00452EC8(m)) {
            S32(st, 0xA8) &= ~4;
            S32(st, 0xA8) &= ~0x10;
            F32(st, 0x78) = 0.7f;
            F32(st, 0x7C) = 0.7f;
            U16(m, 0x34) &= 0xFEFF;
            F32(st, 0x80) = 12.566371f;
            S32(st, 0xA8) |= 3;
            if (k != -1) {
                p = D_L08_0021D140_003A0288[k];
                d0 = func_L01_0040C040(&p->pt[0], st + 0x2C0);
                if (func_L01_0040C040((u8 *)p + (p->n << 4), st + 0x2C0) < d0) {
                    func_L01_00458E48(m, p, 0, 0);
                } else {
                    func_L01_00458E48(m, p, p->n - 1, p->n - 1);
                }
            }
            if (U8(m, 0x43) != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
        }
        if (k == -1) {
            func_L01_00457440(m, st + 0x220);
            if (func_00388800(m + 0x10, st + 0x220) < D_L08_001DE284_003A0288) {
                func_L01_00441FB8(m, 9, -1);
                if (U8(m, 0x43) != 6) {
                    func_003BE4F0(m, 6, 0, 10);
                }
            }
        } else {
            dz = fabs_asm(F32(m, 0x18) - F32(st, 0x228));
            r = func_L01_00458AE0(m, k);
            if (func_00388800(m + 0x10, st + 0x220) < D_L08_001DE284_003A0288) {
                func_L01_00441FB8(m, 9, -1);
                if (U8(m, 0x43) != 6) {
                    func_003BE4F0(m, 6, 0, 10);
                }
            } else if (r != 0 || U16(m, 0x96) >= 0x3D || dz > 3.0f) {
                func_L01_00441FB8(m, 7, -1);
                if (U8(m, 0x43) != 4) {
                    func_003BE4F0(m, 4, 0, 10);
                }
            }
            if (func_00388800(m + 0x10, st + 0x220) < 6.0f) {
                func_L01_00441FB8(m, 7, -1);
                if (U8(m, 0x43) != 4) {
                    func_003BE4F0(m, 4, 0, 10);
                }
            }
        }
        if (!func_L01_00453210(st + 0x220, S32(st, 0x318) ? S32(st, 0x2F0) : S32(st, 0x2D8))) {
            func_L01_00441FB8(m, 6, -1);
            if (U8(m, 0x43) != 3) {
                func_003BE4F0(m, 3, 0, 10);
            }
        }
        func_L01_00443648(m, m + 0x10, 0x10000, 0, 1, 0, D_L08_001DE298, 8.0f, 1.0f);
        break;
    case 6:
        if (func_L01_00452EC8(m) && U8(m, 0x43) != 3) {
            func_003BE4F0(m, 3, 0, 10);
        }
        func_L01_00457440(m, st + 0x2C0);
        if (func_00388800(m + 0x10, st + 0x2C0) < F32(st, 0xA4)) {
            func_L01_00441FB8(m, 1, 0);
            if (U8(m, 0x43) != 1) {
                func_003BE4F0(m, 1, 0, 10);
            }
        }
        break;
    case 7:
        func_L01_00458A08(m, func_00388A28(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14)));
        if (func_L01_00452EC8(m) && U8(m, 0x43) != 4) {
            func_003BE4F0(m, 4, 0, 10);
        }
        if (U8(m, 0x60) & 2) {
            func_L01_00441FB8(m, 8, -1);
            if (U8(m, 0x43) != 5) {
                func_003BE4F0(m, 5, 0, 3);
            }
        }
        break;
    case 8:
        func_L01_00458A08(m, func_00388A28(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14)));
        if (func_L01_00452EC8(m)) {
            S32(st, 0x328) = 0;
        }
        if (U8(m, 0x60) & 2) {
            func_L01_00441FB8(m, 4, -1);
            if (U8(m, 0x43) != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
        }
        if (D_L08_001DE278_003A0288 < func_L01_00436500(m) && S32(st, 0x328) < D_L08_001DE270_003A0288) {
            f32 dist = func_00388800(m + 0x10, st + 0x220);
            f32 sp;
            V4_003A1FA0 *pv = &v10;
            v10 = *(V4_003A1FA0 *)(st + 0x220);
            if (S32(st, 0x328) != 0) {
                func_003BF6A8(pv, D_L08_001DE274_003A0288 * dist);
            }
            sp = D_L08_001DE27C_003A0288 * dist;
            func_003BDA38(m, 2, &v20);
            sp = sp * 0.0166666675f;
            vec_sub_ab(&v30, &v10, &v20);
            func_00388830(&v30, &v30, sp);
            v30.z = func_L01_00444740(&v20, pv, 0, sp, -(D_L08_001DE280_003A0288 * 0.00027777778f));
            func_L08_003A81D8(&v20, &v30, m, (f32)U8(st, 0x44), D_L08_001DE280_003A0288);
            S32(st, 0x328)++;
        }
        break;
    case 9:
        if (func_L01_00452EC8(m) && U8(m, 0x43) != 6) {
            func_003BE4F0(m, 6, 0, 10);
        }
        func_L01_00458A08(m, func_00388A28(F32(st, 0x220) - F32(m, 0x10), F32(st, 0x224) - F32(m, 0x14)));
        f = func_L01_00436500(m);
        if (f < (f32)D_L08_001DE294 && (f32)D_L08_001DE290_003A0288 < f) {
            func_L01_00443790(m, 0, 1, 0, 1, 0, 1.0f, 5.0f, 1.5f);
        }
        if (f < (f32)D_L08_001DE28C_003A0288 && (f32)D_L08_001DE288_003A0288 < f) {
            func_L01_00443790(m, 1, 1, 0, 1, 0, 1.0f, 5.0f, 1.5f);
        }
        if (U8(m, 0x60) & 2) {
            func_L01_00441FB8(m, 4, -1);
            if (U8(m, 0x43) != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
        }
        break;
    }
    func_L08_003A1DD8(m);
}
/* localdecomp:end func_L08_003A0288 */
