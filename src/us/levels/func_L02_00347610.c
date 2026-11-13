#include "common.h"

/* NTSC-U counterpart of func_L02_003484D8 (src/levels/02_florana/L02_003484D8.c) */
/* localdecomp:start func_L02_00347610 */
/* func_L02_00347610: Florana enemy update (an AI state machine on the moby state byte +0x20 with a
   phase switch on +0x95 first), 15,032 bytes, one place (level 02). No rac1/rac2/rac4 twin; written
   from retail. Needs -mvu0-use-vf0-vf2 on this file's line (vec_add/vec_sub/qzero/fabs_asm/abs_asm
   from include/vu0.h). State 40's ground test is the game's integer abs (abs_asm: retail's
   blezl/neg pair) applied to the comparison, (pos.z - ground < 0.1f), as the original wrote it.
   What it took: no pointer locals for field addresses except state 37's func_003BEC60 call, whose
   first and third arguments are block locals (its a1 is set before the f12 move); case-local
   temporaries; argument order decides precomputation; callees that return a value
   (func_L01_00458A08 returns s32) free v0 differently; in states 25 and 30 the ~1 mask comes
   before the f080 store. */
#include "vu0.h"

typedef struct Vec_3484D8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_3484D8;

typedef union PathEnt_3484D8 {
    s32 n;
    Vec_3484D8 v;
} PathEnt_3484D8;

typedef struct Moby_3484D8 Moby_3484D8;
typedef struct Pv_3484D8 Pv_3484D8;

typedef struct Cls_3484D8 {
    u8 pad0[0x10];
    s32 i010;
    u8 pad14[0x44 - 0x14];
    u16 H044;
} Cls_3484D8;

struct Moby_3484D8 {
    /* 0x000 */ u8 pad0[0x10];
    /* 0x010 */ Vec_3484D8 pos;
    /* 0x020 */ u8 b020;
    /* 0x021 */ u8 pad21[3];
    /* 0x024 */ Cls_3484D8 *p024;
    /* 0x028 */ u8 pad28[0x34 - 0x28];
    /* 0x034 */ union { u16 H; u8 b; } u34;
    /* 0x036 */ u8 pad36[0x42 - 0x36];
    /* 0x042 */ u8 b042;
    /* 0x043 */ u8 b043;
    /* 0x044 */ u8 pad44[0x60 - 0x44];
    /* 0x060 */ u8 b060;
    /* 0x061 */ u8 pad61[0x68 - 0x61];
    /* 0x068 */ Pv_3484D8 *pv;
    /* 0x06C */ u8 pad6C[0x94 - 0x6C];
    /* 0x094 */ u8 b094;
    /* 0x095 */ u8 b095;
    /* 0x096 */ u8 pad96[2];
    /* 0x098 */ s32 i098;
    /* 0x09C */ u8 pad9C[0xA8 - 0x9C];
    /* 0x0A8 */ u8 bA8;
    /* 0x0A9 */ u8 padA9;
    /* 0x0AA */ u16 HAA;
    /* 0x0AC */ u8 padAC[0xBC - 0xAC];
    /* 0x0BC */ u8 bBC;
    /* 0x0BD */ u8 padBD[3];
    /* 0x0C0 */ Vec_3484D8 vC0;
    /* 0x0D0 */ Vec_3484D8 vD0;
    /* 0x0E0 */ Vec_3484D8 vE0;
    /* 0x0F0 */ s32 iF0;
    /* 0x0F4 */ s32 iF4;
    /* 0x0F8 */ f32 fF8;
    /* 0x0FC */ u8 padFC[4];
};

typedef struct Child_3484D8 {
    Vec_3484D8 v00;
    u8 pad10[4];
    f32 f14;
    u8 pad18[8];
    Moby_3484D8 *m20;
    u8 pad24[0x30 - 0x24];
    Vec_3484D8 v30;
} Child_3484D8;

typedef struct Rec80_3484D8 {
    u8 pad0[0x30];
    Vec_3484D8 v30;
    u8 pad40[0x40];
} Rec80_3484D8;

struct Pv_3484D8 {
    /* 0x000 */ u8 pad0[0x40];
    /* 0x040 */ f32 f040;
    /* 0x044 */ u8 b044;
    /* 0x045 */ u8 pad45[0x5F - 0x45];
    /* 0x05F */ u8 b05F;
    /* 0x060 */ u8 pad60[0x78 - 0x60];
    /* 0x078 */ f32 f078;
    /* 0x07C */ f32 f07C;
    /* 0x080 */ f32 f080;
    /* 0x084 */ u8 pad84[0x98 - 0x84];
    /* 0x098 */ f32 f098;
    /* 0x09C */ u8 pad9C[0xA4 - 0x9C];
    /* 0x0A4 */ f32 f0A4;
    /* 0x0A8 */ s32 i0A8;
    /* 0x0AC */ u8 padAC[0x120 - 0xAC];
    /* 0x120 */ f32 f120;
    /* 0x124 */ u8 pad124[0x160 - 0x124];
    /* 0x160 */ u8 x160[0x17B - 0x160];
    /* 0x17B */ u8 b17B;
    /* 0x17C */ u8 pad17C[0x220 - 0x17C];
    /* 0x220 */ Vec_3484D8 v220;
    /* 0x230 */ Moby_3484D8 *m230;
    /* 0x234 */ s16 h234;
    /* 0x236 */ u8 pad236[0x2D0 - 0x236];
    /* 0x2D0 */ s32 i2D0;
    /* 0x2D4 */ u8 pad2D4[2];
    /* 0x2D6 */ s16 h2D6;
    /* 0x2D8 */ s32 i2D8;
    /* 0x2DC */ s32 i2DC;
    /* 0x2E0 */ Moby_3484D8 *m2E0;
    /* 0x2E4 */ u8 pad2E4[0x958 - 0x2E4];
    /* 0x958 */ f32 f958;
    /* 0x95C */ u8 pad95C[0x9D8 - 0x95C];
    /* 0x9D8 */ f32 f9D8;
    /* 0x9DC */ u8 pad9DC[0x9F0 - 0x9DC];
    /* 0x9F0 */ Vec_3484D8 v9F0;
    /* 0xA00 */ Vec_3484D8 vA00;
    /* 0xA10 */ Vec_3484D8 vA10;
    /* 0xA20 */ s32 iA20;
    /* 0xA24 */ u8 xA24[8];
    /* 0xA2C */ s32 iA2C;
    /* 0xA30 */ s32 iA30;
    /* 0xA34 */ u8 padA34[4];
    /* 0xA38 */ s32 iA38;
    /* 0xA3C */ f32 fA3C;
    /* 0xA40 */ u8 padA40[4];
    /* 0xA44 */ s32 iA44;
    /* 0xA48 */ s32 iA48;
    /* 0xA4C */ s32 iA4C;
    /* 0xA50 */ s32 iA50;
    /* 0xA54 */ s32 iA54;
    /* 0xA58 */ s32 iA58;
    /* 0xA5C */ s32 iA5C;
    /* 0xA60 */ s32 iA60;
    /* 0xA64 */ s32 iA64;
    /* 0xA68 */ s32 iA68;
    /* 0xA6C */ u8 padA6C[4];
    /* 0xA70 */ s32 iA70;
    /* 0xA74 */ s32 iA74;
    /* 0xA78 */ s32 iA78;
    /* 0xA7C */ u8 padA7C[4];
    /* 0xA80 */ Vec_3484D8 vA80;
    /* 0xA90 */ Vec_3484D8 vA90;
    /* 0xAA0 */ Vec_3484D8 vAA0;
    /* 0xAB0 */ u8 padAB0[0x10];
    /* 0xAC0 */ s32 iAC0;
    /* 0xAC4 */ u8 padAC4[0xAD0 - 0xAC4];
    /* 0xAD0 */ Moby_3484D8 *mAD0;
    /* 0xAD4 */ u8 padAD4[0xAF0 - 0xAD4];
    /* 0xAF0 */ Vec_3484D8 vAF0;
    /* 0xB00 */ s32 iB00;
    /* 0xB04 */ s32 iB04;
    /* 0xB08 */ s32 iB08;
    /* 0xB0C */ s32 iB0C;
    /* 0xB10 */ u8 padB10[4];
    /* 0xB14 */ u8 *pB14;
    /* 0xB18 */ s32 iB18;
    /* 0xB1C */ s32 iB1C;
    /* 0xB20 */ u8 padB20[4];
    /* 0xB24 */ s32 iB24;
};

typedef struct Hit_3484D8 {
    u8 pad0[0x18];
    s8 c18;
    s8 c19;
    u16 H1A;
    u8 pad1C[0x30 - 0x1C];
} Hit_3484D8;

extern s32 D_001D6694_sda_00347610;
__asm__(".extern D_001D6694_sda_00347610, 4");
extern s32 D_001A71A4[];
extern u8 D_001A4C60[];
extern Moby_3484D8 *D_L02_001DEA1C;
extern Rec80_3484D8 *D_L02_001DEB00;
extern PathEnt_3484D8 *D_L02_0021C780[];
extern f32 D_L02_001DCFB0;
__asm__(".extern D_L02_001DCFB0, 4");
extern f32 D_L02_001DCFB4;
__asm__(".extern D_L02_001DCFB4, 4");

extern int abs(int);
extern f32 *func_0037E0B8(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389468(f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BD360(void *);
extern void func_003BD9A0(void *, s32, void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern void func_003BEBF8(f32 *, f32, f32);
extern void func_003BEC60(f32 *, f32, void *, f32, f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_003CF790(void *, s32, void *, void *, f32);
extern s32 func_003D00C0(void);
extern void func_L01_00301508(void *, s32, f32, f32);
extern void func_L01_003154D8(void *, s32, s32);
extern void func_L01_00402498(void *, void *);
extern f32 func_L01_00436500(void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00442998(s32, s32, s32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443648(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern f32 func_L01_00445758(void *, f32, void *, s32, f32, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L01_0044CB08(void *, void *, s32, s32);
extern f32 func_L01_0044E128(void *, s32, s32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00454C30(void *, void *, s32, s32, f32);
extern void func_L01_00455E98(void *, void *, void *);
extern void func_L01_00455EC8(void *, void *, void *);
extern void func_L01_00457440(void *, void *);
extern void func_L01_00457590(void *, void *, f32);
extern s32 func_L01_00457708(void *, f32);
extern void func_L01_00457728(void *, void *);
extern s32 func_L01_00458A08(void *, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458AE0(void *, s32);
extern s32 func_L01_00458B30(void *, void *);
extern void func_L01_00458E48(void *, void *, s32, s32);
extern s32 func_L01_00459F10(void *, void *);
extern void func_L01_00465410(void *, void *, s32, s32);
extern void func_L01_00467288(void *, void *, s32, f32, f32);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L02_0034AFD0(void *);
extern void func_L02_0034B7D8(void *);
extern void func_L02_0034B878(void *);
extern s32 func_L02_0034BA10(void *);
extern void func_L02_003510F8(void);
extern void func_L02_00351210(void *);
extern void func_L02_003512C0(void *);
extern s32 func_L02_0042DDE0(void *, void *, s32, f32, f32, f32, f32);

void func_L02_00347610(Moby_3484D8 *s) {
    Vec_3484D8 a;
    Vec_3484D8 b;
    Vec_3484D8 c;
    Vec_3484D8 d;
    Hit_3484D8 e;
    Pv_3484D8 *v;
    f32 ang;
    f32 r;
    s32 i;
    s32 j;
    s32 n;

    v = s->pv;
    if (func_L02_0034AFD0(s)) {
        func_003BD360(s);
        return;
    }
    if (D_001D6694_sda_00347610 == 2) {
        if ((s->u34.b ^ 1) & 1) {
            s->i098 = 0;
            s->u34.H = (s->u34.H | 0x41) & 0xEFFF;
            func_L01_004A6DF8(s, 1);
            v->iB1C = 1;
        }
        return;
    }
    if (v->iB1C) {
        s->u34.H &= 0xFFBE;
        s->u34.H |= s->p024->H044 & 0x1000;
        s->i098 = s->p024->i010;
        v->iB1C = 0;
    }
    if (D_001A71A4[0] == 0x74) {
        return;
    }

    switch (s->b095) {
    case 0: {
        Moby_3484D8 *m;
        f32 *hp;
        s32 flag;
        if (func_L01_00452EF0(s) && v->h2D6 == 0) {
            v->h2D6 = func_0037E208(0, 30);
        }
        flag = 0;
        if (v->iA50 == -1 || (m = &D_L02_001DEA1C[v->iA50], hp = func_0037E0B8(m), m == 0) ||
            m->b020 == 0xFE || m->b020 == 0xFD || (hp != 0 && *hp <= 0.0f) ||
            func_L01_00453210(D_001A4C60, v->iA48)) {
            flag = 1;
        }
        if (v->iA64 != 0xFF && func_L01_00442998(v->iA64, -1, 1)) {
            flag = 0;
        }
        if (flag && v->h234 == 1 && func_003883C8(&v->h2D6)) {
            if (v->iA60) {
                s->bA8 = 0xFF;
                func_L01_00441FB8(s, 0x18, 2);
                if (s->b043 != 0xE) {
                    func_003BE4F0(s, 0xE, 0, 6);
                }
            } else {
                if (s->b043 != 6) {
                    func_003BE4F0(s, 6, func_0037E208(0, 5), func_0037E208(6, 10));
                }
                func_L01_00441FB8(s, 8, 2);
                if (v->i2DC != -1) {
                    func_L01_00441FB8(s, 0xA, -1);
                }
                if (v->iA30 != -1) {
                    func_L01_00441FB8(s, 0x23, -1);
                    if (s->b043 != 7) {
                        func_003BE4F0(s, 7, 0, 10);
                    }
                    if (func_00388800(&s->pos, &D_L02_0021C780[v->iA30][1]) > 0.5f) {
                        if (s->b043 != 6) {
                            func_003BE4F0(s, 6, 0, 10);
                        }
                        func_L01_00441FB8(s, 0x27, -1);
                    }
                }
                if (v->iA44 != -1) {
                    func_L01_00441FB8(s, 0xB, -1);
                }
                if (v->iA58) {
                    v->iA58 = 0;
                    s->u34.H &= 0xFFBE;
                    s->u34.H |= s->p024->H044 & 0x1000;
                    s->i098 = s->p024->i010;
                    if (s->b043 != 0xC) {
                        func_003BE4F0(s, 0xC, 0, 10);
                    }
                    func_L01_00441FB8(s, 0x20, -1);
                    if (v->iA58 == 2) {
                        func_L01_00441FB8(s, 0x21, -1);
                    }
                }
            }
        } else if (v->i2D8 && func_003883C8(&v->h2D6) && flag) {
            if (v->iA60) {
                s->bA8 = 0xFF;
                func_L01_00441FB8(s, 0x18, 2);
                if (s->b043 != 0xE) {
                    func_003BE4F0(s, 0xE, 0, 6);
                }
            } else {
                if (s->b043 != 6) {
                    func_003BE4F0(s, 6, func_0037E208(0, 5), func_0037E208(6, 10));
                }
                func_L01_00441FB8(s, 8, 2);
                if (v->i2DC != -1) {
                    func_L01_00441FB8(s, 0xA, -1);
                }
                if (v->iA30 != -1) {
                    func_L01_00441FB8(s, 0x23, -1);
                    if (s->b043 != 7) {
                        func_003BE4F0(s, 7, 0, 10);
                    }
                    if (func_00388800(&s->pos, &D_L02_0021C780[v->iA30][1]) > 0.5f) {
                        if (s->b043 != 6) {
                            func_003BE4F0(s, 6, 0, 10);
                        }
                        func_L01_00441FB8(s, 0x27, -1);
                    }
                }
                if (v->iA44 != -1) {
                    func_L01_00441FB8(s, 0xB, -1);
                }
                if (v->iA58) {
                    v->iA58 = 0;
                    s->u34.H &= 0xFFBE;
                    s->u34.H |= s->p024->H044 & 0x1000;
                    s->i098 = s->p024->i010;
                    if (s->b043 != 0xC) {
                        func_003BE4F0(s, 0xC, 0, 10);
                    }
                    func_L01_00441FB8(s, 0x20, -1);
                    if (v->iA58 == 2) {
                        func_L01_00441FB8(s, 0x21, -1);
                    }
                }
            }
            v->i2D8 = 0;
            if (v->i2D0 < 0x12C) {
                v->i2D0 = func_0037E208(0x1E0, 0x258);
            }
        }
        break;
    }
    case 1:
        if (v->h234 == 1) {
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, func_0037E208(0, 5), func_0037E208(6, 10));
            }
            func_L01_00441FB8(s, 8, 2);
            if (v->iA44 != -1) {
                func_L01_00441FB8(s, 0xB, -1);
            }
            if (v->iA30 != -1) {
                func_L01_00441FB8(s, 0x23, -1);
                if (s->b043 != 7) {
                    func_003BE4F0(s, 7, 0, 10);
                }
                if (func_00388800(&s->pos, &D_L02_0021C780[v->iA30][1]) > 0.5f) {
                    if (s->b043 != 6) {
                        func_003BE4F0(s, 6, 0, 10);
                    }
                    func_L01_00441FB8(s, 0x27, -1);
                }
            }
        }
        break;
    case 4:
        s->pos.z -= 0.20000002f;
        break;
    case 2:
        if (v->h234 != 1 && !func_L01_00452EF0(s) && s->b020 < 0x1F && func_0037E1D8(20) == 0) {
            if (s->b043 != 0) {
                func_003BE4F0(s, 0, 0, 10);
            }
            func_L01_00441FB8(s, 7, 1);
            if (v->iA78 || v->iA74 != -1) {
                if (s->b043 != 5) {
                    func_003BE4F0(s, 5, func_0037E1D8(2), func_0037E208(7, 15));
                }
                func_L01_00441FB8(s, 6, 0);
            }
            v->i2D0 = func_0037E208(0x244, 0x258);
        }
        break;
    case 3: {
        s32 n;
        if (func_L01_00452EF0(s)) {
            v->iA30 = -1;
        }
        n = func_L01_00451078(s, v->x160);
        if (v->iB18 == 0 && v->b17B == 0 &&
            fabs_asm(func_003BE7F0(&s->pos, 0, s, 0.5f) - s->pos.z) > 7.0f) {
            func_0039FE80(10, 0, s);
            v->iB18 = 1;
        }
        if (v->iB24 == 0 && v->b17B) {
            v->iB24 = 1;
            func_0039FE80(11, 0, s);
        }
        if (n & 1) {
            func_L02_0034B7D8(s);
            func_L01_003154D8(s, 0, 0);
            return;
        }
        if (n & 2) {
            if (v->h234 == 1) {
                if (s->b043 != 6) {
                    func_003BE4F0(s, 6, func_0037E208(0, 5), func_0037E208(8, 10));
                }
                func_L01_00441FB8(s, 8, 2);
                if (v->iA44 != -1) {
                    func_L01_00441FB8(s, 0xB, -1);
                } else if (s->bBC) {
                    if (s->b043 != 0x12) {
                        func_003BE4F0(s, 0x12, 0, 10);
                    }
                    func_L01_00441FB8(s, 0x10, 2);
                } else if (func_00388800(&s->pos, &v->v220) < 8.0f) {
                    func_L01_00441FB8(s, 9, -1);
                    if (s->b043 != 5) {
                        func_003BE4F0(s, 5, 0, func_0037E208(10, 12));
                    }
                }
            } else {
                if (s->b043 != 0) {
                    func_003BE4F0(s, 0, 0, 10);
                }
                func_L01_00441FB8(s, 7, 1);
                if (v->iA78) {
                    if (s->b043 != 5) {
                        func_003BE4F0(s, 5, 0, 10);
                    }
                    func_L01_00441FB8(s, 6, 0);
                }
                v->i2D0 = func_0037E208(0x244, 0x258);
            }
        }
        break;
    }
    }

    switch (s->b020) {
    case 1:
        break;
    case 3: {
        PathEnt_3484D8 *pa;
        f32 t;
        s32 n;
        func_L01_00457708(s, s->fF8);
        if (s->b060 & 2) {
            func_L01_00441FB8(s, 4, -1);
            if (s->b043 != 5) {
                func_003BE4F0(s, 5, 0, 10);
            }
            if (v->iA54 != -1) {
                pa = D_L02_0021C780[v->iA54];
                t = func_00388800(&s->pos, &pa[1]);
                if (func_00388800(&s->pos, &pa[pa[0].n]) < t) {
                    func_L01_00458E48(s, D_L02_0021C780[v->iA54], 0, pa[0].n - 1);
                } else {
                    func_L01_00458E48(s, D_L02_0021C780[v->iA54], pa[0].n - 1, 0);
                }
                func_L01_00441FB8(s, 5, -1);
            }
        }
        break;
    }
    case 5:
        if (func_L01_00452EC8(s)) {
            func_L01_00458A70(s, 0.0044444446f, D_L02_001DCFB4 * 0.016666668f, 0.0069813174f, 0.41887906f);
            if (v->iB04 && s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
        }
        if (func_L01_00458B30(s, D_L02_0021C780[v->iA54])) {
            if (s->b043 != func_0037E1D8(2) + 1) {
                func_003BE4F0(s, func_0037E1D8(2) + 1, 0, 10);
            }
            func_L01_00441FB8(s, 3, -1);
        }
        break;
    case 6: {
        if (func_L01_00452EC8(s)) {
            a = v->vA00;
            func_L01_00455EC8(s, &a, &v->vA80);
            v->iA30 = -1;
            if (v->iA74 != -1) {
                v->vA00 = ((Rec80_3484D8 *)((u8 *)D_L02_001DEB00 + (v->iA74 << 7)))->v30;
            }
        }
        func_L01_00458A70(s, 0.0044444446f, D_L02_001DCFB4 * 0.016666668f, 0.0034906587f, 0.41887906f);
        if (func_00388800(&s->pos, &v->vA80) < 0.75f) {
            v->vAA0 = v->vA80 = v->vA90;
            func_L01_00454C30(s, &v->vA80, 1, 0, 6.0f);
            v->vAF0 = s->pos;
            v->iAC0 = 0;
        }
        if (func_00388800(&s->pos, &v->vAF0) > 4.0f) {
            v->vAA0 = v->vA80 = v->vA90;
            func_L01_00454C30(s, &v->vA80, 1, 0, 6.0f);
            v->vAF0 = s->pos;
            v->iAC0 = 0;
        }
        if (func_00388800(&s->pos, &v->vA00) > 5.0f) {
            func_L01_00457440(s, &v->vA80);
        } else {
            func_L01_00457440(s, &v->vA00);
        }
        if (func_L02_0034BA10(s) == 1) {
            func_L01_00441FB8(s, 0x1F, -1);
            if (s->b043 != 0xC) {
                func_003BE4F0(s, 0xC, 5, 6);
            }
        }
        if (func_00388800(&s->pos, &v->vA00) <= 0.5f) {
            func_L01_00441FB8(s, 4, -1);
        }
        break;
    }
    case 4: {
        f32 ang;
        f32 r;
        if (func_L01_00452EC8(s)) {
            ang = func_0037E2A8();
            r = func_0037E250(2.0f, 5.0f);
            qzero(&v->vA10);
            v->vA10.x = func_00388960(ang) * r;
            v->vA10.y = func_00388978(ang) * r;
            vec_add_ab(&v->vA10, &v->vA10, &v->vA00);
            v->iA20 = func_0037E208(300, 530);
            if (v->iB00 != -1 && !func_L01_00453210(&v->vA10, v->iB00)) {
                v->vA10 = v->vA00;
            }
            func_L01_00458A70(s, 0.0044444446f, D_L02_001DCFB4 * 0.016666668f, 0.0012605157f, 0.104719765f);
        }
        func_L01_00445758(&s->fF8, func_00388A28(v->vA10.x - s->pos.x, v->vA10.y - s->pos.y), v->xA24, 0,
                          0.0012605157f, 0.0012605157f, 0.023271058f);
        func_L01_00457590(s, &v->vA10, s->fF8);
        if (func_00388800(&s->pos, &v->vA10) < 0.75f) {
            ang = func_0037E2A8();
            r = func_0037E250(2.0f, 6.0f);
            qzero(&v->vA10);
            v->vA10.x = func_00388960(ang) * r;
            v->vA10.y = func_00388978(ang) * r;
            vec_add_ab(&v->vA10, &v->vA10, &v->vA00);
        }
        if (func_00388398(&v->iA20)) {
            if (s->b043 != func_0037E1D8(2) + 1) {
                func_003BE4F0(s, func_0037E1D8(2) + 1, 0, 10);
            }
            func_L01_00441FB8(s, 3, -1);
        }
        break;
    }
    case 8: {
        if (func_L01_00452EC8(s)) {
            func_L01_00455E98(s, v->m230, &v->vA80);
            func_L01_00458A70(s, 0.011111111f, D_L02_001DCFB0 * 0.016666668f, 0.0069813174f, 0.20943953f);
        }
        if (v->iA5C && v->iB08 != -1 && v->iB0C != -1 && func_L01_00453210(&v->v220, v->iB08)) {
            func_L01_00441FB8(s, 0x1D, -1);
        }
        if (v->m230 != v->mAD0) {
            func_L01_00455E98(s, v->m230, &v->vA80);
        }
        if (v->mAD0 != 0) {
            v->vA90 = v->mAD0->pos;
            a = v->mAD0->pos;
        } else {
            a = v->vA90;
        }
        if (func_00388800(&v->vAA0, &a) > 1.0f) {
            v->vAA0 = v->vA80 = v->vA90;
            func_L01_00454C30(s, &v->vA80, 1, 0, 6.0f);
            v->vAF0 = s->pos;
            v->iAC0 = 0;
        }
        if (func_00388800(&s->pos, &v->vA80) < 0.75f) {
            v->vAA0 = v->vA80 = v->vA90;
            func_L01_00454C30(s, &v->vA80, 1, 0, 6.0f);
            v->vAF0 = s->pos;
            v->iAC0 = 0;
        }
        if (func_00388800(&s->pos, &v->vAF0) > 4.0f || v->iAC0 >= 11) {
            v->vAA0 = v->vA80 = v->vA90;
            func_L01_00454C30(s, &v->vA80, 1, 0, 6.0f);
            v->vAF0 = s->pos;
            v->iAC0 = 0;
        }
        func_L01_00457440(s, &v->vA80);
        if (v->f120 < v->f098 * 0.8f) {
            v->iAC0++;
        }
        if (func_L02_0034BA10(s) == 1 &&
            func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 1.3962634f) {
            func_L01_00441FB8(s, 0x1F, -1);
            if (s->b043 != 0xC) {
                func_003BE4F0(s, 0xC, 5, 6);
            }
        }
        if (func_00388800(&s->pos, &v->v220) < 10.0f &&
            func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.2617994f &&
            v->iA5C == 0) {
            if (func_003CE740(&s->pos, &v->v220, 2, s, 0) == 0) {
                func_L01_00441FB8(s, 0xD, -1);
                if (s->b043 != 0x11) {
                    func_003BE4F0(s, 0x11, 0, func_0037E208(6, 8));
                }
            }
            if (func_00388800(&s->pos, &v->v220) < 3.0f) {
                func_L01_00441FB8(s, 0x14, -1);
                if (s->b043 != 0x16) {
                    func_003BE4F0(s, 0x16, 2, 7);
                }
            }
        }
        if (v->iA5C && func_00388800(&s->pos, &v->v220) < 3.0f &&
            func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.2617994f) {
            func_L01_00441FB8(s, 0x14, -1);
            if (s->b043 != 0x16) {
                func_003BE4F0(s, 0x16, 2, 7);
            }
        }
        break;
    }
    case 29: {
        Vec_3484D8 *p;
        p = &((Rec80_3484D8 *)((u8 *)D_L02_001DEB00 + (v->iB0C << 7)))->v30;
        if (func_00388800(&s->pos, p) > 0.75f) {
            func_L01_00457440(s, p);
        } else {
            func_L01_00458A08(s, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y));
            if (func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.2617994f) {
                func_L01_00441FB8(s, 0xD, -1);
                if (s->b043 != 0x11) {
                    func_003BE4F0(s, 0x11, 0, func_0037E208(6, 8));
                }
            }
        }
        if (!func_L01_00453210(&v->v220, v->iB08)) {
            func_L01_00441FB8(s, 8, -1);
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
        }
        break;
    }
    case 9: {
        if (func_L01_00452EC8(s)) {
            func_L01_00458A70(s, 0.0044444446f, D_L02_001DCFB4 * 0.016666668f, 0.0069813174f, 0.20943953f);
        }
        func_L01_00458A70(s, 0.0044444446f, D_L02_001DCFB4 * 0.016666668f, 0.0069813174f, 0.20943953f);
        func_L01_00457440(s, &v->v220);
        if (func_L02_0034BA10(s) == 1) {
            func_L01_00441FB8(s, 0x1F, -1);
            if (s->b043 != 0xC) {
                func_003BE4F0(s, 0xC, 5, 6);
            }
        }
        if (func_00388800(&s->pos, &v->v220) < 3.0f &&
            func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.2617994f) {
            func_L01_00441FB8(s, 0x14, -1);
            if (s->b043 != 0x16) {
                func_003BE4F0(s, 0x16, 2, 7);
            }
        }
        break;
    }
    case 24:
        if (func_L01_00452EC8(s)) {
            func_L01_00458A70(s, 0.0044444446f, D_L02_001DCFB4 * 0.016666668f, 0.0012605157f, 0.104719765f);
            v->i0A8 |= 4;
            v->f07C = v->f078 = 0.7f;
            s->u34.H |= 0x100;
            v->f080 = 12.566371f;
            v->i0A8 |= 1;
        }
        func_00388830(&a, &s->vC0, 4.0f);
        vec_add_ab(&a, &a, &s->pos);
        func_L01_00459F10(s, &a);
        b = s->pos;
        func_00388830(&c, &s->vE0, 0.25f);
        vec_add_ab(&b, &b, &c);
        if (fabs_asm(func_003BE7F0(&b, 0, s, 0.5f) - s->pos.z) < 5.0f) {
            if (s->b043 != 0xF) {
                func_003BE4F0(s, 0xF, 0, 10);
            }
            func_L01_00441FB8(s, 0x19, -1);
        }
        break;
    case 25: {
        f32 t;
        if (func_L01_00452EC8(s)) {
            v->i0A8 &= ~4;
            s->u34.H &= 0xFEFF;
            v->i0A8 &= ~1;
            v->f080 = 12.566371f;
            s->iF0 = 0;
            s->iF4 = 0;
            s->fF8 = func_00389380(s->fF8, 3.1415927f);
        }
        if (func_L01_00436500(s) > 3.0f && s->b042 == 0xF) {
            c = s->pos;
            func_00388830(&d, &s->vE0, 0.25f);
            vec_add_ba(&c, &c, &d);
            t = func_003BE7F0(&c, 0, s, 0.5f);
            a = s->pos;
            func_003BEC60(&a.z, t, &v->iA2C, 0.16666667f, 2.0f, 1.5f);
            vec_sub_ab(&b, &a, &s->pos);
            func_L01_00457728(s, &b);
        }
        if (s->b060 & 2) {
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 6);
            }
            func_L01_00441FB8(s, 8, -1);
        }
        break;
    }
    case 30:
        if (func_L01_00452EC8(s) && (u32)(s->b094 - 0x17) < 3) {
            v->i0A8 &= ~4;
            s->u34.H &= 0xFEFF;
            v->i0A8 &= ~1;
            v->f080 = 12.566371f;
            s->iF0 = 0;
            s->iF4 = 0;
            s->fF8 = func_00389380(s->fF8, 3.1415927f);
        }
        break;
    case 11: {
        Rec80_3484D8 *rec;
        if (func_L01_00452EC8(s)) {
            func_L01_00458A70(s, 0.011111111f, D_L02_001DCFB0 * 0.016666668f, 0.0069813174f, 0.20943953f);
        }
        rec = (Rec80_3484D8 *)((u8 *)D_L02_001DEB00 + (v->iA44 << 7));
        func_L01_00457440(s, &rec->v30);
        if (func_L02_0034BA10(s) == 1) {
            func_L01_00441FB8(s, 0x1F, -1);
            if (s->b043 != 0xC) {
                func_003BE4F0(s, 0xC, 5, 6);
            }
        }
        if (func_00388800(&s->pos, &rec->v30) < 0.5f) {
            func_L01_00441FB8(s, 0xC, -1);
        }
        break;
    }
    case 12: {
        func_L01_00458A08(s, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y));
        if (func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.2617994f) {
            if (v->iA48 == -1 && func_003CE740(&s->pos, &v->v220, 2, s, 0) == 0) {
                func_L01_00441FB8(s, 0xD, -1);
                if (s->b043 != 0x11) {
                    func_003BE4F0(s, 0x11, 0, 6);
                }
            } else if (func_L01_00453210(&v->v220, v->iA48) && func_003CE740(&s->pos, &v->v220, 2, s, 0) == 0) {
                func_L01_00441FB8(s, 0xD, -1);
                if (s->b043 != 0x11) {
                    func_003BE4F0(s, 0x11, 0, 6);
                }
                if (v->iA5C) {
                    v->iA44 = -1;
                    func_L01_00441FB8(s, 8, -1);
                    if (s->b043 != 6) {
                        func_003BE4F0(s, 6, 0, 10);
                    }
                }
            } else {
                func_L01_00441FB8(s, 0x16, -1);
                if (s->b043 != 3) {
                    func_003BE4F0(s, 3, 0, 10);
                }
            }
        }
        break;
    }
    case 22: {
        if (func_L01_00453210(&v->v220, v->iA48) && func_0037E1D8(5) == 0 && func_003CE740(&s->pos, &v->v220, 2, s, 0) == 0) {
            func_L01_00441FB8(s, 0xD, -1);
            if (s->b043 != 0x11) {
                func_003BE4F0(s, 0x11, 0, func_0037E208(6, 8));
            }
            if (v->iA5C) {
                v->iA44 = -1;
                func_L01_00441FB8(s, 8, -1);
                if (s->b043 != 6) {
                    func_003BE4F0(s, 6, 0, 10);
                }
            }
        }
        a = s->pos;
        a.z += v->f040;
        if (v->iA48 == -1 && func_003CE740(&a, &v->v220, 2, s, 0) == 0) {
            func_L01_00441FB8(s, 0xD, -1);
            if (s->b043 != 0x11) {
                func_003BE4F0(s, 0x11, 0, func_0037E208(6, 8));
            }
            if (v->iA5C) {
                v->iA44 = -1;
                func_L01_00441FB8(s, 8, -1);
                if (s->b043 != 6) {
                    func_003BE4F0(s, 6, 0, 10);
                }
            }
        }
        break;
    }
    case 10:
        if (func_L01_00452EC8(s)) {
            func_L01_00458A70(s, 0.011111111f, D_L02_001DCFB0 * 0.016666668f, 0.0069813174f, 0.20943953f);
        }
        if (func_L01_00458AE0(s, v->i2DC) ||
            (func_00388800(&s->pos, &v->v220) < 10.0f && v->iA5C == 0 && v->iA68 == 0) ||
            (v->iA5C && func_00388800(&s->pos, &v->v220) < 4.0f && v->iA68 == 0)) {
            func_L01_00441FB8(s, 8, -1);
        }
        if (func_L02_0034BA10(s) == 1) {
            func_L01_00441FB8(s, 0x1F, -1);
            if (s->b043 != 0xC) {
                func_003BE4F0(s, 0xC, 5, 6);
            }
        }
        break;
    case 13: {
        Child_3484D8 *ch;
        if (func_L01_0044AF40(s, 18.0f) && s->b042 == 0x11) {
            ch = (Child_3484D8 *)v->m2E0->pv;
            s->bBC = 1;
            v->m2E0->b020 = 0;
            func_003BD9A0(s, 0, &a);
            ch->f14 = 0.25f;
            if (func_00388800(&s->pos, &v->v220) < 6.0f) {
                ch->f14 = 0.32f;
            }
            ch->v00 = b;
            ch->v30 = v->v220;
            ch->m20 = v->m230;
            func_00388830(ch, ch, -1.0f);
            func_00388830(ch, ch, 0.4166667f);
            v->m2E0->u34.H &= 0xFFFD;
            v->m2E0->u34.H &= 0xFFFB;
        }
        if (func_L01_0044AF40(s, 23.0f)) {
            if (s->b043 != 0x13) {
                func_003BE4F0(s, 0x13, 0, 10);
            }
            func_L01_00441FB8(s, 0x11, -1);
            if (func_0037E1D8(2)) {
                if (s->b043 != 0x14) {
                    func_003BE4F0(s, 0x14, 0, 10);
                }
                func_L01_00441FB8(s, 0x12, -1);
            }
            if (v->iA70) {
                if (s->b043 != 0x12) {
                    func_003BE4F0(s, 0x12, 0, 10);
                }
                func_L01_00441FB8(s, 0x10, -1);
            }
        }
        break;
    }
    case 17: {
        Moby_3484D8 *m;
        f32 t;
        func_L01_00458A70(s, 0.0044444446f, 0.016666668f, 0.0012605157f, 0.104719765f);
        m = v->m2E0;
        t = func_003893C8(func_00388A28(m->pos.x - s->pos.x, m->pos.y - s->pos.y), s->fF8) * 0.5f;
        v->f958 = v->f9D8 = t;
        a = s->vD0;
        func_00388830(&a, &a, 5.0f);
        vec_add_ab(&a, &a, &s->pos);
        func_L02_0042DDE0(s, &a, 0x10, func_00388A28(a.x - s->pos.x, a.y - s->pos.y), -1.0f, -1.0f, -1.0f);
        if (s->bBC == 0) {
            func_L01_00441FB8(s, 0x13, -1);
            if (s->b043 != 0x15) {
                func_003BE4F0(s, 0x15, 1, 3);
            }
            v->m2E0->u34.H |= 2;
        }
        break;
    }
    case 18: {
        Moby_3484D8 *m;
        f32 t;
        func_L01_00458A70(s, 0.0044444446f, 0.016666668f, 0.0012605157f, 0.104719765f);
        m = v->m2E0;
        t = func_003893C8(func_00388A28(m->pos.x - s->pos.x, m->pos.y - s->pos.y), s->fF8) * 0.5f;
        v->f958 = v->f9D8 = t;
        a = s->vD0;
        func_00388830(&a, &a, -5.0f);
        vec_add_ab(&a, &a, &s->pos);
        func_L02_0042DDE0(s, &a, 0x10, func_00388A28(a.x - s->pos.x, a.y - s->pos.y), -1.0f, -1.0f, -1.0f);
        if (s->bBC == 0) {
            func_L01_00441FB8(s, 0x13, -1);
            if (s->b043 != 0x15) {
                func_003BE4F0(s, 0x15, 1, 3);
            }
            v->m2E0->u34.H |= 2;
        }
        break;
    }
    case 14: {
        f32 ang;
        f32 r;
        if (func_L01_00452EC8(s)) {
            ang = func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
            ang = func_00389380(func_00389380(s->fF8, 3.1415927f), ang);
            r = func_0037E250(7.0f, 8.0f);
            qzero(&v->v9F0);
            v->v9F0.x = func_00388960(ang) * r;
            v->v9F0.y = func_00388978(ang) * r;
            vec_add_ab(&v->v9F0, &s->pos, &v->v9F0);
        }
        func_L01_00457440(s, &v->v9F0);
        if (func_00388800(&s->pos, &v->v9F0) < 1.0f ||
            (v->m2E0->b020 == 1 && func_00388800(&s->pos, &v->m2E0->pos) < 12.0f)) {
            func_L01_00441FB8(s, 0xF, -1);
        }
        break;
    }
    case 15: {
        Moby_3484D8 *m;
        m = v->m2E0;
        func_L01_00458A08(s, func_00388A28(m->pos.x - s->pos.x, m->pos.y - s->pos.y));
        if (func_00389468(s->fF8, func_00388A28(v->m2E0->pos.x - s->pos.x, v->m2E0->pos.y - s->pos.y)) < 0.61086524f) {
            func_L01_00441FB8(s, 0x10, -1);
            if (s->b043 != 0x12) {
                func_003BE4F0(s, 0x12, 0, 10);
            }
        }
        break;
    }
    case 16: {
        Moby_3484D8 *m;
        f32 t;
        m = v->m2E0;
        t = func_003893C8(func_00388A28(m->pos.x - s->pos.x, m->pos.y - s->pos.y), s->fF8) * 0.5f;
        v->f958 = v->f9D8 = t;
        if (s->bBC == 0) {
            func_L01_00441FB8(s, 0x13, -1);
            if (s->b043 != 0x15) {
                func_003BE4F0(s, 0x15, 1, 3);
            }
            v->m2E0->u34.H |= 2;
        }
        break;
    }
    case 19:
        func_L02_00351210(v->m2E0);
        func_L01_00402498(func_L02_003510F8, v->m2E0);
        func_L01_0044CB08(s, v->m2E0, 0, 0);
        if (func_L01_0044AF40(s, 27.0f) && s->b042 == 0x15) {
            func_L01_00441FB8(s, 8, -1);
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
            if (v->iA44 != -1) {
                if (func_00388800(&s->pos, &((Rec80_3484D8 *)((u8 *)D_L02_001DEB00 + (v->iA44 << 7)))->v30) > 5.0f) {
                    if (s->b043 != 6) {
                        func_003BE4F0(s, 6, 0, 10);
                    }
                    func_L01_00441FB8(s, 0xB, -1);
                } else {
                    func_L01_00441FB8(s, 0xD, -1);
                    if (s->b043 != 0x11) {
                        func_003BE4F0(s, 0x11, 0, func_0037E208(6, 8));
                    }
                }
            }
            func_L02_003512C0(v->m2E0);
        }
        break;
    case 20:
        if (s->b060 & 2) {
            if (s->b043 != 4) {
                func_003BE4F0(s, 4, 0, 10);
            }
            func_L01_00441FB8(s, 0x1C, -1);
        }
        if (func_L01_00436500(s) > 15.0f) {
            func_003BDA38(v->m2E0, 0, &a);
            func_00388830(&b, &s->vC0, 0.5f);
            func_003886E8(&b, &b, 2.0f);
            b.w = 5627.925f;
            if (v->b05F == 0) {
                func_L01_00443628(&e, s, 1, &b, v->b044);
            } else {
                func_L01_00443628(&e, s, 0x10001, &b, v->b044);
            }
            e.c19 = 1;
            e.H1A = s->HAA;
            e.c18 = 0;
            func_003CF790(&a, 0, s, &e, 0.6f);
        }
        break;
    case 28:
        if (s->b060 & 2) {
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
            func_L01_00441FB8(s, 8, -1);
        }
        break;
    case 31: {
        f32 t;
        if (func_L01_00452EC8(s)) {
            v->vA10.z = s->pos.z;
        }
        if (s->b042 == 0xC) {
            t = func_L01_00436500(s);
            if (t > 8.0f && t < 24.0f) {
                func_00388830(&c, &s->vC0, 0.21875f);
                vec_add_ba(&a, &s->pos, &c);
            }
            if (t > 8.0f && t < 16.0f) {
                func_003BEC60(&a.z, v->vA10.z + 1.5f, &v->iA2C, 0.1875f, 0.375f, 0.1875f);
            }
            if (t == 16.0f) {
                v->iA2C = 0;
            }
            if (t > 16.0f && t < 24.0f) {
                func_003BEC60(&a.z, func_003BE7F0(&s->pos, 0, 0, 0.5f), &v->iA2C, 0.03125f, 0.375f, 0.28125f);
            }
            if (t > 8.0f && t < 24.0f) {
                vec_sub_ab(&b, &a, &s->pos);
                func_L01_00457728(s, &b);
            }
        }
        if (s->b060 & 2) {
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
            if (s->b094 == 0xA) {
                func_L01_00441FB8(s, 0xA, -1);
            } else if (s->b094 == 0xB) {
                func_L01_00441FB8(s, 0xB, -1);
            } else {
                func_L01_00441FB8(s, 8, -1);
            }
            if (s->b094 == 6 || s->b095 == 0) {
                func_L01_00441FB8(s, 6, -1);
                if (s->b043 != 5) {
                    func_003BE4F0(s, 5, 0, 10);
                }
            }
        }
        break;
    }
    case 32: {
        f32 t;
        if (func_L01_00452EC8(s)) {
            v->vA10.z = s->pos.z;
        }
        if (s->b042 == 0xC) {
            t = func_L01_00436500(s);
            if (t > 8.0f && t < 24.0f) {
                func_00388830(&c, &s->vC0, 0.21875f);
                vec_add_ba(&a, &s->pos, &c);
            }
            if (t > 8.0f && t < 16.0f) {
                func_003BEC60(&a.z, v->vA10.z + 1.5f + 3.0f, &v->iA2C, 0.5625f, 1.125f, 0.5625f);
            }
            if (t == 16.0f) {
                v->iA2C = 0;
            }
            if (t > 16.0f && t < 24.0f) {
                func_003BEC60(&a.z, func_003BE7F0(&s->pos, 0, 0, 0.5f), &v->iA2C, 0.09375f, 1.125f, 0.84375f);
            }
            if (t > 8.0f && t < 24.0f) {
                vec_sub_ab(&b, &a, &s->pos);
                func_L01_00457728(s, &b);
            }
        }
        if (s->b060 & 2) {
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
            if (s->b094 == 0xA) {
                func_L01_00441FB8(s, 0xA, -1);
            } else if (s->b094 == 0xB) {
                func_L01_00441FB8(s, 0xB, -1);
            } else {
                func_L01_00441FB8(s, 8, -1);
            }
        }
        break;
    }
    case 33: {
        f32 t;
        if (func_L01_00452EC8(s)) {
            v->vA10.z = s->pos.z;
        }
        if (s->b042 == 0xC) {
            t = func_L01_00436500(s);
            if (t > 8.0f && t < 24.0f) {
                func_00388830(&c, &s->vC0, 0.21875f);
                vec_add_ba(&a, &s->pos, &c);
            }
            if (t > 8.0f && t < 16.0f) {
                func_003BEC60(&a.z, v->vA10.z + 1.5f, &v->iA2C, 0.5625f, 1.125f, 0.5625f);
            }
            if (t == 16.0f) {
                v->iA2C = 0;
            }
            if (t > 16.0f && t < 24.0f) {
                func_003BEC60(&a.z, func_003BE7F0(&s->pos, 0, 0, 0.5f), &v->iA2C, 0.09375f, 1.125f, 0.84375f);
            }
            if (t > 8.0f && t < 24.0f) {
                vec_sub_ab(&b, &a, &s->pos);
                func_L01_00457728(s, &b);
            }
        }
        if (s->b060 & 2) {
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
            if (s->b094 == 0xA) {
                func_L01_00441FB8(s, 0xA, -1);
            } else if (s->b094 == 0xB) {
                func_L01_00441FB8(s, 0xB, -1);
            } else {
                func_L01_00441FB8(s, 8, -1);
            }
        }
        break;
    }
    case 35: {
        PathEnt_3484D8 *pa;
        if (func_L01_00436500(s) > 5.0f && s->b042 == 7) {
            pa = D_L02_0021C780[v->iA30];
            func_003BEBF8(&s->pos.z, pa[1].v.z - 3.75f, 0.33333334f);
            func_L01_00458A08(s, func_00388A28(pa[2].v.x - s->pos.x, pa[2].v.y - s->pos.y));
        }
        if (s->b060 & 2) {
            v->iA38 = 0;
            func_L01_00441FB8(s, 0x24, -1);
            if (s->b043 != 8) {
                func_003BE4F0(s, 8, 0, 10);
            }
            v->fA3C = 0.06666667f;
        }
        break;
    }
    case 36: {
        PathEnt_3484D8 *pa;
        func_L01_00443648(s, &s->pos, 0x8000000, 0.75f, 1.0f, 1.0f, 0, 1, 0);
        pa = D_L02_0021C780[v->iA30];
        b = s->pos;
        b.z += 4.5f;
        vec_sub_ba(&a, &pa[v->iA38 + 2], &pa[v->iA38 + 1]);
        func_00388830(&a, &a, v->fA3C);
        vec_add_ba(&s->pos, &a, &s->pos);
        v->fA3C += 0.0016666667f;
        if (v->fA3C > 0.23333335f) {
            v->fA3C = 0.23333335f;
        }
        func_00388800(&s->pos, &pa[v->iA38 + 2]);
        if (func_00388800(&s->pos, &pa[v->iA38 + 2]) < 0.25f) {
            v->iA38++;
            if (v->iA38 >= pa[0].n - 1) {
                func_L01_00441FB8(s, 0x25, -1);
                if (s->b043 != 0xB) {
                    func_003BE4F0(s, 0xB, 0, 4);
                }
                func_003BE7F0(&s->pos, 0, 0, 0.5f);
            }
        }
        break;
    }
    case 37: {
        if (func_L01_00452EC8(s)) {
            v->iA2C = 0;
        }
        func_L01_00443648(s, &s->pos, 0x8000000, 0.75f, 1.0f, 1.0f, 0, 1, 0);
        if (func_L01_00436500(s) < 16.0f || s->b042 != 0xB) {
            {f32 *z = &s->pos.z; void *p = &v->iA2C; func_003BEC60(z, func_003BE7F0(&s->pos, 0, 0, 0.5f), p, 0.0055555557f, 0.010833333f, 0.35000002f);}
            a.x = func_00388960(s->fF8) * v->fA3C;
            a.y = func_00388978(s->fF8) * v->fA3C;
            a.z = 0.0f;
            v->fA3C -= 0.0016666667f;
            vec_add_ba(&s->pos, &a, &s->pos);
        }
        func_L01_0044AF40(s, 10.0f);
        if (func_L01_0044AF40(s, 18.0f) && s->b042 == 0xB) {
            v->iA30 = -1;
            func_L01_00441FB8(s, 8, -1);
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 6);
            }
            if (v->i2DC != -1) {
                func_L01_00441FB8(s, 0xA, -1);
            }
            if (v->iA4C == -1) {
                if (func_00389468(s->fF8, func_00388A28(v->v220.x - s->pos.x, v->v220.y - s->pos.y)) < 0.34906584f &&
                    v->iA5C == 0 && func_003CE740(&s->pos, &v->v220, 2, s, 0) == 0) {
                    if (s->b043 != 0x11) {
                        func_003BE4F0(s, 0x11, 0, 6);
                    }
                    func_L01_00441FB8(s, 0xD, -1);
                }
            } else {
                func_L01_00441FB8(s, 0x27, -1);
                v->iA30 = v->iA4C;
            }
        }
        break;
    }
    case 40: {
        func_L01_00443648(s, &s->pos, 0x8000000, 0.75f, 1.0f, 1.0f, 0, 1, 0);
        func_003BEBF8(&s->pos.z, func_003BE7F0(&s->pos, 0, 0, 0.5f), 0.5833334f);
        a.x = func_00388960(s->fF8) * v->fA3C;
        a.y = func_00388978(s->fF8) * v->fA3C;
        a.z = 0.0f;
        vec_add_ba(&s->pos, &a, &s->pos);
        if (abs_asm(s->pos.z - func_003BE7F0(&s->pos, 0, 0, 0.5f) < 0.1f)) {
            if (s->b043 != 0xB) {
                func_003BE4F0(s, 0xB, 0, 3);
            }
            func_L01_00441FB8(s, 0x26, -1);
        }
        break;
    }
    case 38: {
        func_L01_00443648(s, &s->pos, 0x8000000, 0.75f, 1.0f, 1.0f, 0, 1, 0);
        if (func_L01_00436500(s) < 5.0f || s->b042 != 0xB) {
            func_003BEBF8(&s->pos.z, func_003BE7F0(&s->pos, 0, 0, 0.5f), 0.13333334f);
            a.x = func_00388960(s->fF8) * v->fA3C;
            a.y = func_00388978(s->fF8) * v->fA3C;
            a.z = 0.0f;
            vec_add_ba(&s->pos, &a, &s->pos);
        }
        if (s->b060 & 2) {
            func_L01_00441FB8(s, 8, -1);
            if (s->b043 != 6) {
                func_003BE4F0(s, 6, 0, 10);
            }
            if (v->i2DC != -1) {
                func_L01_00441FB8(s, 0xA, -1);
            }
            if (v->iA4C != -1) {
                func_L01_00441FB8(s, 0x27, -1);
                v->iA30 = v->iA4C;
            }
        }
        break;
    }
    case 39: {
        Vec_3484D8 *p;
        p = &D_L02_0021C780[v->iA30][1].v;
        func_L01_00457440(s, p);
        if (func_00388800(&s->pos, p) <= v->f0A4) {
            v->iA4C = -1;
            func_L01_00441FB8(s, 0x23, -1);
            if (s->b043 != 7) {
                func_003BE4F0(s, 7, 0, 10);
            }
        }
        break;
    }
    }

    if ((u32)(s->b020 - 0x20) >= 2 && func_L01_0044E128(&s->pos, 0, 0) < 0.1f && s->b095 != 4 && s->b095 != 3 &&
        (func_003D00C0() == 0 || func_003D00C0() == 1)) {
        func_L01_00441FB8(s, 0x1B, 4);
        if (s->b043 != 0xA) {
            func_003BE4F0(s, 0xA, 0, 6);
        }
        a = s->pos;
        func_L01_00301508(&a, 3, 3.25f, 1.025f);
        for (i = 0; i < 3; i++) {
            b.x = s->pos.x + func_0037E250(-0.3f, 0.3f);
            b.y = s->pos.y + func_0037E250(-0.3f, 0.3f);
            b.z = s->pos.z;
            func_L01_00467288(&b, &s->pos.z, -1, func_0037E250(0.5f, 0.75f), 5250.0f);
        }
        for (j = 0; j < 16; j++) {
            ang = func_0037E2A8();
            r = func_0037E250(0.0f, 0.050000004f);
            b.x = func_00388960(ang) * r;
            b.y = func_00388978(ang) * r;
            b.z = func_0037E250(0.050000004f, 0.13333334f);
            c.x = s->pos.x + b.x * 8.0f;
            c.y = s->pos.y + b.x * 8.0f;
            c.z = s->pos.z - func_0037E250(0.0f, 0.2f);
            n = func_0037E1D8(2);
            func_L01_00465410(&c, &b, n, func_0037E208(90, 120));
        }
    }
    func_L02_0034B878(s);
}
/* localdecomp:end func_L02_00347610 */
