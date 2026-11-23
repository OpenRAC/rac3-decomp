#include "common.h"

/* NTSC-U counterpart of func_L39_0051CEF8 (src/levels/shared/L39_0051CEF8.c) */
/* localdecomp:start func_L39_0051CB88 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051CEF8;

typedef struct {
    u8 pad0[0xAA];
    s16 type;
} T_0051CEF8;

typedef struct {
    u8 pad0[0x7C];
    f32 f7C;
    s32 f80;
    s32 f84;
    u8 pad88[0x8];
    s32 f90;
    u8 pad94[0x8];
    s32 f9C;
} P_0051CEF8;

typedef struct {
    u8 pad0[0x10];
    V4_0051CEF8 pos;
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[0x11];
    u8 b43;
    u8 pad44[0x4];
    f32 f48;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[0x7];
    P_0051CEF8 *pv;
    u8 pad6C[0x3];
    u8 b6F;
    u8 pad70[0x38];
    u8 bA8;
    u8 padA9[0x47];
    V4_0051CEF8 vF0;
} M_0051CEF8;

typedef struct {
    u8 pad0[0x240];
    M_0051CEF8 *f240;
    u8 pad244[0x10];
    s32 f254;
    u8 pad258[0x23];
    u8 b27B;
} C_0051CEF8;

typedef struct {
    u8 pad0[0x1A4];
    s32 f1A4;
    u8 pad1A8[0x2C];
    s32 f1D4;
} G_0051CEF8;

typedef struct {
    u8 pad0[0x20];
    u8 v20[0x80];
    V4_0051CEF8 vA0;
    V4_0051CEF8 vB0;
    u8 padC0[0x60];
    V4_0051CEF8 v120;
    u8 pad130[0xE84];
    f32 fFB4;
    u8 padFB8[0xA52];
    u8 b1A0A;
    u8 pad1A0B[0x9];
    u8 b1A14;
    u8 pad1A15[0xA43];
    s32 f2458;
    u8 pad245C[0x70];
    u32 f24CC;
    s32 f24D0;
    u8 pad24D4[0x5C];
    C_0051CEF8 *f2530;
    G_0051CEF8 *f2534;
    u8 pad2538[0x10];
    s32 f2548;
    u8 pad254C[0x27E4];
    V4_0051CEF8 v4D30;
} Pl_0051CEF8;

typedef struct O_0051CEF8 O_0051CEF8;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(O_0051CEF8 *, s32);
} VT_0051CEF8;
struct O_0051CEF8 {
    u32 f0;
    u8 pad4[0x10];
    VT_0051CEF8 *vt;
};

typedef struct {
    u8 pad0[0x20];
    T_0051CEF8 *f20;
} H_0051CEF8;

typedef struct {
    u32 f0;
} I_0051CEF8;

typedef struct {
    u8 pad0[0x2D8];
    I_0051CEF8 *f2D8;
    u8 pad2DC[0x34];
    f32 f310;
} R_0051CEF8;

typedef struct {
    V4_0051CEF8 a;
    V4_0051CEF8 b;
} Q_0051CEF8;

extern Pl_0051CEF8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20, 32");
extern u8 D_L39_0024DF80[];
extern T_0051CEF8 *D_L39_0025F858 __attribute__((section(".data")));
extern f32 D_L39_0024A970;
__asm__(".extern D_L39_0024A970, 4");
extern f32 D_L39_0024A974;
__asm__(".extern D_L39_0024A974, 4");
extern f32 D_L39_0024A978_0051CB88;
__asm__(".extern D_L39_0024A978_0051CB88, 4");
extern f32 D_L39_0024A97C_0051CB88;
__asm__(".extern D_L39_0024A97C_0051CB88, 4");
extern f32 D_L39_0024A980_0051CB88;
__asm__(".extern D_L39_0024A980_0051CB88, 4");
extern f32 D_L39_0024A984_0051CB88;
__asm__(".extern D_L39_0024A984_0051CB88, 4");
extern f32 D_L39_0024A988_0051CB88;
__asm__(".extern D_L39_0024A988_0051CB88, 4");

extern void func_L39_0051D918(void *, s32, s32);
extern void *func_L01_00444358(void *, s32, s32);
extern O_0051CEF8 *func_L39_0061A728(void *);
extern void func_L01_00444070(void *, f32);
extern s32 func_00388398(void *);
extern void func_L39_0061E358(void *, s32, s32, s32);
extern void func_00388BF0(void *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L39_005C2098(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern R_0051CEF8 *func_L39_0061B038(void *);
extern void func_L39_00635C68(void *);
extern s32 func_L39_005B2498(s32);
extern void func_L39_00630530(void *, s32, f32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_00630DD8(void *, f32, f32);
extern void func_L39_00630E28(void *, f32);
extern s32 func_L39_00554508(void *, void *, void *, f32, f32, f32, f32);
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_00452EC8(void *);
extern void func_L39_0062DD00(void *);
extern void func_L39_00638860(void *);

void func_L39_0051CB88(M_0051CEF8 *a0) {
    P_0051CEF8 *pv = a0->pv;
    Pl_0051CEF8 *pl = D_L39_0024CF20[pv->f9C];
    O_0051CEF8 *o;
    H_0051CEF8 *h;
    R_0051CEF8 *r;
    T_0051CEF8 *t;
    s32 bits;
    s32 m;
    u8 is_local;
    s32 res;
    f32 rnd;
    Q_0051CEF8 q;
    V4_0051CEF8 d;

    if (pv->f84 > 0 || pl == 0 || pl->f2458 == 0) {
        func_L39_0051D918(a0, pv->f84 == 2, pv->f84 == 3);
        return;
    }
    if (pl->b1A14 != 0) {
        h = func_L01_00444358(a0, 0xB030001, 0);
        if (h != 0) {
            if (h->f20 != 0) {
                o = func_L39_0061A728(h->f20);
            } else {
                o = 0;
            }
            if (o == 0 || o->vt->f1C(o, pl->f2548) == 0
                || (h->f20 != 0 && h->f20->type == 0x18AB)) {
                pl->f24CC = o != 0 ? o->f0 : 0xFFFFFFFF;
                pl->f24D0 = -1;
                func_L39_0061E358(pl, 0, 0, 0);
                return;
            }
        }
    }
    a0->bA8 = 0xFF;
    func_L01_00444070(a0, 0.5f);
    func_00388398(&pv->f80);
    if (pv->f80 == 0 && pl != 0 && pl->b1A14 != 0) {
        func_L39_0061E358(pl, 1, 0, 0);
        return;
    }
    is_local = pl->b1A14;
    if (is_local != 0) {
        V4_0051CEF8 *pos = &a0->pos;
        pl->vA0 = *pos;
        pl->vB0 = a0->vF0;
        pl->b1A0A = 2;
        func_00388BF0(pl->v20, &pl->vB0);
        if (a0->b31 != 0 && func_L01_0040C018(D_L39_0024DF80, pos) < 144.0f) {
            func_L01_00444188(a0);
            a0->b6F = 11;
        }
    } else {
        if (a0->b31 != 0 && func_L01_0040C018(D_L39_0024DF80, &a0->pos) < 144.0f) {
            func_L01_00444188(a0);
            a0->b6F = 11;
        }
    }

    switch (a0->b20) {
    case 0:
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        a0->f48 = 1.0f;
        if (pl->f2534->f1D4 == 0) {
            func_L01_00441FB8(a0, 4, -1);
            pv->f90 = func_L39_005B24C8(400, 600);
            if (a0->b43 != 2) {
                func_003BE4F0(a0, 2, 0, 4);
            }
            a0->f48 = D_L39_0024A978_0051CB88;
        } else {
            m = func_L39_005C2098(0x40, 0);
            bits = pl->f2534->f1A4;
            if (bits & m) {
                func_L01_00441FB8(a0, 6, -1);
                pv->f90 = func_L39_005B24C8(180, 360);
                if (a0->b43 != 5) {
                    func_003BE4F0(a0, 5, 0, 4);
                }
            } else if (bits & 0x80) {
                func_L01_00441FB8(a0, 5, -1);
                pv->f90 = func_L39_005B24C8(180, 360);
                if (a0->b43 != 3) {
                    func_003BE4F0(a0, 3, 0, 10);
                }
            } else if (bits & 0x20) {
                func_L01_00441FB8(a0, 7, -1);
                pv->f90 = func_L39_005B24C8(180, 360);
                if (a0->b43 != 4) {
                    func_003BE4F0(a0, 4, 0, 10);
                }
            } else if (a0->b60 & 2) {
                rnd = func_L39_005B2510(0.0f, 100.0f);
                if (0.0f <= rnd && rnd < 50.0f) {
                    if (a0->b43 != 0) {
                        func_003BE4F0(a0, 0, 0, 10);
                    }
                }
                if (50.0f <= rnd && rnd < 100.0f) {
                    if (a0->b43 != 1) {
                        func_003BE4F0(a0, 1, 0, 10);
                    }
                }
            }
        }
        q.a = a0->pos;
        q.a.z += 0.5f;
        if (func_L01_003F9498(&q.a, 4, a0, D_L39_0024A984_0051CB88) == 0) {
            break;
        }
        t = D_L39_0025F858;
        if (t == 0) {
            break;
        }
        if (t->type != 0x107C && t->type != 0x107E) {
            break;
        }
        r = func_L39_0061B038(t);
        if (fabs_asm(r->f310) > 0.05000000447034836f) {
            pl->f24CC = r->f2D8 != 0 ? r->f2D8->f0 : 0xFFFFFFFF;
            pl->f24D0 = -1;
            func_L39_0061E358(pl, 0, 1, 0);
        }
        break;
    case 5:
        func_L39_00635C68(pl);
        if ((a0->b60 & 2) && a0->b43 != 3) {
            func_003BE4F0(a0, 3, 0, 10);
        }
        if (func_00388398(&pv->f90) != 0) {
            func_L01_00441FB8(a0, 1, -1);
            pv->f90 = func_L39_005B24C8(120, 600);
            if (a0->b43 != func_L39_005B2498(2)) {
                func_003BE4F0(a0, func_L39_005B2498(2), 0, 10);
            }
        }
        break;
    case 6:
        if (a0->b60 & 2) {
            func_L01_00441FB8(a0, 1, -1);
            pv->f90 = func_L39_005B24C8(120, 600);
            if (a0->b43 != func_L39_005B2498(2)) {
                func_003BE4F0(a0, func_L39_005B2498(2), 0, 10);
            }
        }
        do {
            goto tail4;
        } while (0);
    case 7:
        func_L39_00635C68(pl);
        if (a0->b60 & 2) {
            func_L01_00441FB8(a0, 1, -1);
            pv->f90 = func_L39_005B24C8(120, 600);
            if (a0->b43 != func_L39_005B2498(2)) {
                func_003BE4F0(a0, func_L39_005B2498(2), 0, 10);
            }
        }
        break;
    case 4:
        if (pl->f2534->f1D4 != 0) {
            func_L01_00441FB8(a0, 1, -1);
            pv->f90 = func_L39_005B24C8(400, 600);
        }
        a0->f48 = D_L39_0024A978_0051CB88;
        m = func_L39_005C2098(0x40, 0);
        bits = pl->f2534->f1A4;
        if (bits & m) {
            func_L01_00441FB8(a0, 6, -1);
            pv->f90 = func_L39_005B24C8(180, 360);
            if (a0->b43 != 5) {
                func_003BE4F0(a0, 5, 0, 10);
            }
        } else if (bits & 0x80) {
            func_L01_00441FB8(a0, 5, -1);
            pv->f90 = func_L39_005B24C8(180, 360);
            if (a0->b43 != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
        } else if (bits & 0x20) {
            func_L01_00441FB8(a0, 7, -1);
            pv->f90 = func_L39_005B24C8(180, 360);
            if (a0->b43 != 4) {
                func_003BE4F0(a0, 4, 0, 10);
            }
        }
    tail4:
        func_L39_00630530(pl, 0, D_L39_0024A970 * 0.016666668f);
        func_L39_00630AC0(pl, 0, 0.1f, 0.25f, 0.2036217451f);
        a0->vF0.z = pl->vB0.z;
        func_L39_00630DD8(pl, D_L39_0024A974 * 0.0102777779f, D_L39_0024A974 * 0.008333334f);
        func_L39_00630E28(pl, 99999.0f);
        vec_add_ba(&q.a, &a0->pos, &pl->v120);
        q.b = a0->pos;
        pv->f7C = -0.03333333507f;
        q.a.z += pv->f7C;
        res = func_L39_00554508(a0, &q, pl, D_L39_0024A984_0051CB88, D_L39_0024A988_0051CB88, D_L39_0024A980_0051CB88, -1.0f);
        if (res >= 3) {
            func_L39_0061E358(pl, 0, 1, res == 4);
            return;
        }
        if (pv->f7C < 0.0f && (res == 0 || res == 1)) {
            if (D_L39_0024A97C_0051CB88 < a0->pos.z - func_003BE7F0(&a0->pos, 0, a0, 0.5f)) {
                pv->f7C = 0.0f;
                func_L01_00441FB8(a0, 3, -1);
            }
        }
        if (pl->b1A14 == 0) {
            vec_sub_ba(&d, &pl->v4D30, &a0->pos);
            func_003886E8(&d, &d, 0.1f);
            vec_add_ab(&a0->pos, &a0->pos, &d);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0) != 0) {
            pv->f7C = 0.0f;
        }
        pv->f7C -= 0.0027222223579883575f;
        func_L39_00630530(pl, 0, D_L39_0024A970 * 0.5f * 0.016666668f);
        func_L39_00630AC0(pl, 0, 0.1f, 0.25f, 0.2036217451f);
        a0->vF0.z = pl->vB0.z;
        func_L39_00630DD8(pl, D_L39_0024A974 * 0.0102777779f, D_L39_0024A974 * 0.008333334f);
        func_L39_00630E28(pl, 99999.0f);
        vec_add_ba(&q.a, &a0->pos, &pl->v120);
        if (0.0f < pl->fFB4 && a0->pos.z - func_003BE7F0(&a0->pos, 0, 0, 0.5f) < 0.4f) {
            if (a0->b43 != 2) {
                func_003BE4F0(a0, 2, 0, 4);
            }
        } else {
            if (a0->b43 != 0) {
                func_003BE4F0(a0, 0, 0, 4);
            }
        }
        q.a.z += pv->f7C;
        res = func_L39_00554508(a0, &q, pl, D_L39_0024A984_0051CB88, D_L39_0024A988_0051CB88, D_L39_0024A980_0051CB88, -1.0f);
        if (res >= 3) {
            func_L39_0061E358(pl, 0, 1, res == 4);
            return;
        }
        if (res == 2) {
            pv->f7C = 0.0f;
            func_L01_00441FB8(a0, 0, -1);
        }
        break;
    }

    if (a0->b20 == 1 || a0->b20 == 7 || a0->b20 == 5) {
        if (D_L39_0024A97C_0051CB88 < a0->pos.z - func_003BE7F0(&a0->pos, 0, a0, 0.5f)) {
            pv->f7C = 0.0f;
            func_L01_00441FB8(a0, 3, -1);
        }
    }
    if (pl != 0) {
        pl->vA0 = a0->pos;
        pl->vB0 = a0->vF0;
        func_L39_0062DD00(pl);
        func_L39_00638860(pl);
        pl->f2530->f240 = a0;
        pl->f2530->f254 = 0;
        pl->f2530->b27B = 1;
    }
}
/* localdecomp:end func_L39_0051CB88 */
