#include "common.h"

/* localdecomp:start func_L39_0051CEF8 */
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

extern Pl_0051CEF8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern u8 D_L39_0024DE80[];
extern T_0051CEF8 *D_L39_0025F758 __attribute__((section(".data")));
extern f32 D_L39_0024A860;
__asm__(".extern D_L39_0024A860, 4");
extern f32 D_L39_0024A864;
__asm__(".extern D_L39_0024A864, 4");
extern f32 D_L39_0024A868;
__asm__(".extern D_L39_0024A868, 4");
extern f32 D_L39_0024A86C;
__asm__(".extern D_L39_0024A86C, 4");
extern f32 D_L39_0024A870;
__asm__(".extern D_L39_0024A870, 4");
extern f32 D_L39_0024A874;
__asm__(".extern D_L39_0024A874, 4");
extern f32 D_L39_0024A878;
__asm__(".extern D_L39_0024A878, 4");

extern void func_L39_0051DD30(void *, s32, s32);
extern void *func_L01_00447490(void *, s32, s32);
extern O_0051CEF8 *func_L39_0061CEA0(void *);
extern void func_L01_004471A8(void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L39_00620AF8(void *, s32, s32, s32);
extern void func_0038D328(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s16 func_L39_005B43C8(s32, s32);   /* as func_L39_0051DB38's block in this file declares it; it returns s32 (L39_005B4398.c), so each call casts */
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L39_005C42E8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern R_0051CEF8 *func_L39_0061D7B0(void *);
extern void func_L39_006384B0(void *);
extern s32 func_L39_005B4398(s32);
extern void func_L39_00632D78(void *, s32, f32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_00633620(void *, f32, f32);
extern void func_L39_00633670(void *, f32);
extern s32 func_L39_00554E60(void *, void *, void *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_004561B8(void *);
extern void func_L39_00630548(void *);
extern void func_L39_0063B0A8(void *);

void func_L39_0051CEF8(M_0051CEF8 *a0) {
    P_0051CEF8 *pv = a0->pv;
    Pl_0051CEF8 *pl = D_L39_0024CE20[pv->f9C];
    O_0051CEF8 *o;
    H_0051CEF8 *h;
    R_0051CEF8 *r;
    T_0051CEF8 *t;
    s32 bits;
    s32 m;
    s32 anim;
    u8 is_local;
    s32 res;
    f32 rnd;
    Q_0051CEF8 q;
    V4_0051CEF8 d;

    if (pv->f84 > 0 || pl == 0 || pl->f2458 == 0) {
        func_L39_0051DD30(a0, pv->f84 == 2, pv->f84 == 3);
        return;
    }
    if (pl->b1A14 != 0) {
        h = func_L01_00447490(a0, 0xB030001, 0);
        if (h != 0) {
            if (h->f20 != 0) {
                o = func_L39_0061CEA0(h->f20);
            } else {
                o = 0;
            }
            if (o == 0 || o->vt->f1C(o, pl->f2548) == 0
                || (h->f20 != 0 && h->f20->type == 0x18AB)) {
                pl->f24CC = o != 0 ? o->f0 : 0xFFFFFFFF;
                pl->f24D0 = -1;
                func_L39_00620AF8(pl, 0, 0, 0);
                return;
            }
        }
    }
    a0->bA8 = 0xFF;
    func_L01_004471A8(a0, 0.5f);
    func_0038CAD0(&pv->f80);
    if (pv->f80 == 0 && pl != 0 && pl->b1A14 != 0) {
        func_L39_00620AF8(pl, 1, 0, 0);
        return;
    }
    is_local = pl->b1A14;
    if (is_local != 0) {
        V4_0051CEF8 *pos = &a0->pos;
        pl->vA0 = *pos;
        pl->vB0 = a0->vF0;
        pl->b1A0A = 2;
        func_0038D328(pl->v20, &pl->vB0);
        if (a0->b31 != 0 && func_L01_0040E548(D_L39_0024DE80, pos) < 144.0f) {
            func_L01_004472C0(a0);
            a0->b6F = 11;
        }
    } else {
        if (a0->b31 != 0 && func_L01_0040E548(D_L39_0024DE80, &a0->pos) < 144.0f) {
            func_L01_004472C0(a0);
            a0->b6F = 11;
        }
    }

    switch (a0->b20) {
    case 0:
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        a0->f48 = 1.0f;
        if (pl->f2534->f1D4 == 0) {
            func_L01_004450F0(a0, 4, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(400, 600) * 5 + 2) / 6;
            if (a0->b43 != 2) {
                func_003C3A10(a0, 2, 0, 3);
            }
            a0->f48 = D_L39_0024A868;
        } else {
            m = func_L39_005C42E8(0x40, 0);
            bits = pl->f2534->f1A4;
            if (bits & m) {
                func_L01_004450F0(a0, 6, -1);
                pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(180, 360) * 5 + 2) / 6;
                if (a0->b43 != 5) {
                    func_003C3A10(a0, 5, 0, 3);
                }
            } else if (bits & 0x80) {
                func_L01_004450F0(a0, 5, -1);
                pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(180, 360) * 5 + 2) / 6;
                if (a0->b43 != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
            } else if (bits & 0x20) {
                func_L01_004450F0(a0, 7, -1);
                pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(180, 360) * 5 + 2) / 6;
                if (a0->b43 != 4) {
                    func_003C3A10(a0, 4, 0, 8);
                }
            } else if (a0->b60 & 2) {
                rnd = func_L39_005B4410(0.0f, 100.0f);
                if (0.0f <= rnd && rnd < 50.0f) {
                    if (a0->b43 != 0) {
                        func_003C3A10(a0, 0, 0, 8);
                    }
                }
                if (50.0f <= rnd && rnd < 100.0f) {
                    if (a0->b43 != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                }
            }
        }
        q.a = a0->pos;
        q.a.z += 0.5f;
        if (func_L01_003FB640(&q.a, 4, a0, D_L39_0024A874) == 0) {
            break;
        }
        t = D_L39_0025F758;
        if (t == 0) {
            break;
        }
        if (t->type != 0x107C && t->type != 0x107E) {
            break;
        }
        r = func_L39_0061D7B0(t);
        if (fabs_asm(r->f310) > 0.06000000238418579f) {
            pl->f24CC = r->f2D8 != 0 ? r->f2D8->f0 : 0xFFFFFFFF;
            pl->f24D0 = -1;
            func_L39_00620AF8(pl, 0, 1, 0);
        }
        break;
    case 5:
        func_L39_006384B0(pl);
        if ((a0->b60 & 2) && a0->b43 != 3) {
            func_003C3A10(a0, 3, 0, 8);
        }
        if (func_0038CAD0(&pv->f90) != 0) {
            func_L01_004450F0(a0, 1, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(120, 600) * 5 + 2) / 6;
            if (a0->b43 != func_L39_005B4398(2)) {
                func_003C3A10(a0, func_L39_005B4398(2), 0, 8);
            }
        }
        break;
    case 6:
        if (a0->b60 & 2) {
            func_L01_004450F0(a0, 1, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(120, 600) * 5 + 2) / 6;
            if (a0->b43 != func_L39_005B4398(2)) {
                anim = func_L39_005B4398(2);
                goto set_anim;
            }
        }
        goto tail4;
    case 7:
        func_L39_006384B0(pl);
        if (a0->b60 & 2) {
            func_L01_004450F0(a0, 1, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(120, 600) * 5 + 2) / 6;
            if (a0->b43 != func_L39_005B4398(2)) {
                func_003C3A10(a0, func_L39_005B4398(2), 0, 8);
            }
        }
        break;
    case 4:
        if (pl->f2534->f1D4 != 0) {
            func_L01_004450F0(a0, 1, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(400, 600) * 5 + 2) / 6;
        }
        a0->f48 = D_L39_0024A868;
        m = func_L39_005C42E8(0x40, 0);
        bits = pl->f2534->f1A4;
        if (bits & m) {
            func_L01_004450F0(a0, 6, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(180, 360) * 5 + 2) / 6;
            if (a0->b43 != 5) {
                func_003C3A10(a0, 5, 0, 8);
            }
        } else if (bits & 0x80) {
            func_L01_004450F0(a0, 5, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(180, 360) * 5 + 2) / 6;
            if (a0->b43 != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
        } else if (bits & 0x20) {
            func_L01_004450F0(a0, 7, -1);
            pv->f90 = (((s32 (*)(s32, s32))func_L39_005B43C8)(180, 360) * 5 + 2) / 6;
            anim = 4;
            if (a0->b43 != anim) {
            set_anim:
                func_003C3A10(a0, anim, 0, 8);
            }
        }
    tail4:
        func_L39_00632D78(pl, 0, D_L39_0024A860 * 0.020000001415610313f);
        func_L39_00633308(pl, 0, 0.14400000870227814f, 0.36f, 0.24434609711170197f);
        a0->vF0.z = pl->vB0.z;
        func_L39_00633620(pl, D_L39_0024A864 * 0.014800000935792923f, D_L39_0024A864 * 0.012f);
        func_L39_00633670(pl, 99999.0f);
        vec_add_ba(&q.a, &a0->pos, &pl->v120);
        q.b = a0->pos;
        pv->f7C = -0.04000000283122063f;
        q.a.z += pv->f7C;
        res = func_L39_00554E60(a0, &q, pl, D_L39_0024A874, D_L39_0024A878, D_L39_0024A870, -1.0f);
        if (res >= 3) {
            func_L39_00620AF8(pl, 0, 1, res == 4);
            return;
        }
        if (pv->f7C < 0.0f && (res == 0 || res == 1)) {
            if (D_L39_0024A86C < a0->pos.z - func_003C3D30(&a0->pos, 0, a0, 0.5f)) {
                pv->f7C = 0.0f;
                func_L01_004450F0(a0, 3, -1);
            }
        }
        if (pl->b1A14 == 0) {
            vec_sub_ba(&d, &pl->v4D30, &a0->pos);
            func_0038CE20(&d, &d, 0.1f);
            vec_add_ab(&a0->pos, &a0->pos, &d);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0) {
            pv->f7C = 0.0f;
        }
        pv->f7C -= 0.00392f;
        func_L39_00632D78(pl, 0, D_L39_0024A860 * 0.5f * 0.020000001415610313f);
        func_L39_00633308(pl, 0, 0.14400000870227814f, 0.36f, 0.24434609711170197f);
        a0->vF0.z = pl->vB0.z;
        func_L39_00633620(pl, D_L39_0024A864 * 0.014800000935792923f, D_L39_0024A864 * 0.012f);
        func_L39_00633670(pl, 99999.0f);
        vec_add_ba(&q.a, &a0->pos, &pl->v120);
        if (0.0f < pl->fFB4 && a0->pos.z - func_003C3D30(&a0->pos, 0, 0, 0.5f) < 0.4f) {
            if (a0->b43 != 2) {
                func_003C3A10(a0, 2, 0, 3);
            }
        } else {
            if (a0->b43 != 0) {
                func_003C3A10(a0, 0, 0, 3);
            }
        }
        q.a.z += pv->f7C;
        res = func_L39_00554E60(a0, &q, pl, D_L39_0024A874, D_L39_0024A878, D_L39_0024A870, -1.0f);
        if (res >= 3) {
            func_L39_00620AF8(pl, 0, 1, res == 4);
            return;
        }
        if (res == 2) {
            pv->f7C = 0.0f;
            func_L01_004450F0(a0, 0, -1);
        }
        break;
    }

    if (a0->b20 == 1 || a0->b20 == 7 || a0->b20 == 5) {
        if (D_L39_0024A86C < a0->pos.z - func_003C3D30(&a0->pos, 0, a0, 0.5f)) {
            pv->f7C = 0.0f;
            func_L01_004450F0(a0, 3, -1);
        }
    }
    if (pl != 0) {
        pl->vA0 = a0->pos;
        pl->vB0 = a0->vF0;
        func_L39_00630548(pl);
        func_L39_0063B0A8(pl);
        pl->f2530->f240 = a0;
        pl->f2530->f254 = 0;
        pl->f2530->b27B = 1;
    }
}
/* localdecomp:end func_L39_0051CEF8 */

/* localdecomp:start func_L39_0051DB38 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051DB38;
typedef struct {
    u8 pad0[0x74];
    s16 s74;
    s16 s76;
    u8 pad78[4];
    s32 f7C;
    s32 f80;
    u8 pad84[4];
    f32 f88;
    u8 pad8C[4];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
} P_0051DB38;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
} Q_0051DB38;
typedef struct {
    u8 pad0[0x10];
    V4_0051DB38 v10;
    u8 b20;
    u8 pad21[3];
    Q_0051DB38 *p24;
    u8 pad28[8];
    u8 b30;
    u8 b31;
    s16 s32;
    u8 pad34[0x34];
    P_0051DB38 *p68;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x54];
    V4_0051DB38 vF0;
} O_0051DB38;
typedef struct {
    u8 pad0[0x40];
    V4_0051DB38 v40;
    u8 pad50[0x50];
    V4_0051DB38 vA0;
    u8 padB0[0x228];
    s16 s2D8;
    u8 pad2DA[0x226A];
    s32 f2544;
} A_0051DB38;
extern O_0051DB38 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(V4_0051DB38 *, V4_0051DB38 *, s32, s32, s32);
extern s16 func_L39_005B43C8(s32, s32);
extern void func_L39_0051E2B0(O_0051DB38 *);
extern void func_003C7C38(O_0051DB38 *);
extern V4_0051DB38 D_L39_0025F760[];
extern s32 D_001A5DF8[];

O_0051DB38 *func_L39_0051DB38(O_0051DB38 *a0, A_0051DB38 *a1, s32 a2) {
    O_0051DB38 *o = func_003C24B0(0x1080, 0xA0);
    P_0051DB38 *p;
    V4_0051DB38 tmp;
    f32 t;

    if (o != 0) {
        o->b30 = 0x7F;
        o->s32 = 0x7F;
        o->b31 = 1;
        p = o->p68;
        o->v10 = a0->v10;
        o->vF0 = a0->vF0;
        o->vF0.x = 0.0f;
        o->vF0.y = 0.0f;
        if (a1->s2D8 != 0) {
            func_0038CF68(&o->v10, &a1->v40, 1.5f);
            vec_add_ab(&o->v10, &o->v10, &a1->vA0);
        }
        tmp = o->v10;
        tmp.z += 1.0f;
        if (func_003D3CB0(&tmp, &o->v10, 2, 0, 0)) {
            func_0038CF68(&tmp, &D_L39_0025F760[2], 0.005f);
            vec_add_ab(&o->v10, &D_L39_0025F760[0], &tmp);
        }
        o->b20 = 0;
        p->s76 = 0;
        p->s74 = func_L39_005B43C8(100, 250);
        p->f90 = 500;
        p->f94 = 25;
        p->f7C = 0;
        p->f98 = 0;
        p->f9C = a1->f2544;
        o->b20 = 3;
        func_L39_0051E2B0(o);
        o->f98 = o->p24->f10;
        p->f88 = 1.0f;
        t = (f32)(a2 - D_001A5DF8[0]) / 1000.0f;
        if (t < 0.0f) {
            t = 0.017f;
        }
        p->f80 = t * 50.0f;
        func_003C7C38(o);
    }
    return o;
}
/* localdecomp:end func_L39_0051DB38 */

INCLUDE_ASM("asm/levels", func_L39_0051DD30);
