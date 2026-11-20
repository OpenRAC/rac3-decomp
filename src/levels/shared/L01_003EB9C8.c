#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[28]; u8 *p; } E_3EAB98;
typedef struct {
    u8 pad0[56];
    u8 f38;
    u8 f39;
    u8 pad3A[8];
    s8 f42;
    s8 f43;
} Info_003EBD50;
typedef struct {
    u8 pad0[28];
    Info_003EBD50 *info;
} Ent_003EBD50;
typedef struct {
    u8 pad0[124];
    u8 f7C;
    u8 pad7D;
    s16 f7E;
    u8 pad80[4];
    s16 f84;
    s16 f86;
} Obj_003EBD50;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[675 - 576];
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Ent003EC730;
typedef int u128_3EC828 __attribute__((mode(TI)));
typedef struct { u8 p0[0x200]; u8 b200[0x30]; u128_3EC828 q230; u8 pad[0x460 - 0x240]; } E_3EC828;
typedef struct { u8 p0[0x30]; u128_3EC828 q30; u8 p40[0x54]; s32 w94; } M_3EC828;
typedef int s128_003ED620 __attribute__((mode(TI)));
typedef struct {
    u8 pad[128];
} E_003ED620;
typedef struct {
    s32 f0;
    s32 f4;
} H_003ED620;
typedef struct {
    u8 pad[8];
    H_003ED620 *h;
} Obj_003ED620;
extern s128_003ED620 D_L01_001E29C0[];
extern E_003ED620 D_001A30B0[];
typedef struct { s32 x0; u8 pad4[0xC64 - 4]; s32 xC64; } G_3EF740;

typedef struct {
    u8 pad0[0x7D];
    u8 f7D;
    s16 f7E;
    u8 pad80[0x86 - 0x80];
    s16 f86;
    u8 pad88[0x94 - 0x88];
    s32 w94;
} Obj_003EC990;
typedef struct {
    u8 pad0[0xFC];
    s32 xFC;
    s32 x100;
} Sub_003EC990;

typedef struct {
    u8 b0, b1, b2, b3;
    s16 s4, s6, s8, s10, s12;
    u8 e, f;
} Rec_003F2058;
typedef struct {
    u8 pad[0x54C];
    u8 b54C;
    u8 pad54D[0x557 - 0x54D];
    u8 b557;
} Ctx_003F2058;
typedef struct {
    Rec_003F2058 r[8];
} Tab_003F2058;

/* localdecomp:start func_L01_003EB9C8 */
extern void func_0038D328(void *, void *);
extern void func_0038D590(void *, void *);
void func_L01_003EB9C8(u8 *m) {
    u8 v[64] __attribute__((aligned(16)));
    u8 *p;
    u8 *s;
    *(s32 *)(*(u8 **)(m + 112) + 192) = 4;
    s = *(u8 **)(m + 112) + 48;
    *(f32 *)(s + 32) = 0.05f;
    *(f32 *)(s + 36) = 0.3f;
    *(f32 *)(s + 40) = 1.0f;
    *(s16 *)(s + 44) = 1;
    qzero(s);
    p = *(u8 **)(m + 112);
    qzero(p);
    *(f32 *)(p + 24) = 1.0f;
    *(s16 *)(p + 28) = 1;
    *(f32 *)(p + 16) = 0.3f;
    *(f32 *)(p + 20) = 0.3f;
    func_0038D328(v, m + 64);
    func_0038D590(m, v);
    *(s16 *)(m + 126) = 0;
}
/* localdecomp:end func_L01_003EB9C8 */

/* localdecomp:start func_L01_003EBA68 */
extern char *D_L01_001DF804_003EBA68;
extern u8 D_L01_001E2B90_003EBA68[];
extern s32 func_L01_0040DFC0_003EBA68(void *);
extern void func_L01_00445438_003EBA68(void *, void *, void *, f32);
extern void func_L01_00445510_003EBA68(void *, void *, void *, f32);
extern void func_L01_003F5FC0_003EBA68(void *, void *, void *);
extern f32 func_L01_0040F440_003EBA68(f32, f32);
extern f32 func_L01_00445320_003EBA68(f32, f32, f32);
extern f32 func_L01_004453B8_003EBA68(f32, f32, f32);
extern f32 func_L01_004451D0_003EBA68(f32, f32, f32, f32, f32);
extern void func_L01_003F5F10_003EBA68(void *, void *, void *);
extern f32 func_L01_003F3520_003EBA68(void *, f32, f32, f32, f32, f32);
extern f32 func_L01_003F35B0_003EBA68(void *, f32, f32, f32, f32, f32);
extern void func_L01_0040EB88_003EBA68(void *, void *);
extern void func_L01_0040EDF0_003EBA68(void *, void *);
extern void func_L01_00404AD8_003EBA68(void *, void *);
extern void func_L01_003EB750_003EBA68(void);

void func_L01_003EBA68(u8 *a0) {
    f32 mtx[16] __attribute__((aligned(16)));
    u8 *m = *(u8 **)(a0 + 0x70);
    u8 *e = *(u8 **)(D_L01_001DF804_003EBA68 + *(s16 *)(a0 + 0x84) * 32 + 28);
    u8 *ro = m + 0x30;
    f32 *pos = (f32 *)(m + 0x80);
    s32 *tm = (s32 *)(m + 0xE0);
    u8 st = a0[0x88];

    if (st == 1 || st == 4) {
        *(u128_t *)(a0 + 0x30) = *(u128_t *)(m + 0x80);
        *(u128_t *)(a0 + 0x40) = *(u128_t *)(m + 0x90);
    } else if (st == 2) {
        f32 n, t;
        func_L01_0040DFC0_003EBA68(tm);
        n = tm[1];
        t = (f32)(tm[1] - tm[0]) / n;
        func_L01_00445438_003EBA68(a0 + 0x30, a0 + 0x30, pos, t);
        func_L01_00445510_003EBA68(a0 + 0x40, a0 + 0x40, m + 0x90, t);
    } else if (st == 3) {
        f32 da, db, t, n;
        f32 *c;
        u8 *h;
        u8 *hero;

        if (func_L01_0040DFC0_003EBA68(tm) != 0) {
            *(u128_t *)(a0 + 0x30) = *(u128_t *)(m + 0x80);
            *(u128_t *)(a0 + 0x40) = *(u128_t *)(m + 0x90);
        } else {
            c = (f32 *)tm;
            n = tm[1];
            t = (f32)(tm[1] - tm[0]) / n;
            h = D_L01_001E2B90_003EBA68 + *(s32 *)(a0 + 0x94) * 0x460;
            func_L01_003F5FC0_003EBA68(m + 0xE8, pos, h + 0x40);
            da = func_L01_0040F440_003EBA68(c[2], c[7]);
            db = func_L01_0040F440_003EBA68(pos[6], *(f32 *)(D_L01_001E2B90_003EBA68 + *(s32 *)(a0 + 0x94) * 0x460 - 0x138));
            if ((da > 0.34906584f && db < -0.34906584f) || (da < -0.34906584f && db > 0.34906584f)) {
                f32 d = c[2] - c[7];
                if ((d < 0.0f && 0.0f < db) || (0.0f < d && db < 0.0f)) {
                    d = -d;
                }
                c[7] += func_L01_00445320_003EBA68(0.0f, d, t);
            } else {
                c[7] = func_L01_004453B8_003EBA68(c[7], c[2], t);
            }
            c[9] += (c[4] - c[9]) * func_L01_004451D0_003EBA68(c[17], 0.0f, 1.0f, c[18], t);
            c[8] = func_L01_004453B8_003EBA68(c[8], c[3], t);
            hero = D_L01_001E2B90_003EBA68 + *(s32 *)(a0 + 0x94) * 0x460;
            func_L01_00445438_003EBA68(c + 12, c + 12, hero + 0x40, t);
            func_L01_003F5F10_003EBA68(a0 + 0x30, c + 7, c + 12);
            func_L01_00445510_003EBA68(a0 + 0x40, a0 + 0x40, pos + 4, t);
        }
    } else {
        if (*(s16 *)(m + 0x1C) == 1) {
            *(f32 *)(a0 + 0x30) = func_L01_003F3520_003EBA68(m, *(f32 *)(a0 + 0x30), pos[0], *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), *(f32 *)(m + 0x18));
            *(f32 *)(a0 + 0x34) = func_L01_003F3520_003EBA68(m + 4, *(f32 *)(a0 + 0x34), pos[1], *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), *(f32 *)(m + 0x18));
            *(f32 *)(a0 + 0x38) = func_L01_003F3520_003EBA68(m + 8, *(f32 *)(a0 + 0x38), pos[2], *(f32 *)(m + 0x10), *(f32 *)(m + 0x14), *(f32 *)(m + 0x18));
        }
        if (*(s16 *)(ro + 0x2C) == 1) {
            *(f32 *)(a0 + 0x40) = func_L01_003F35B0_003EBA68(ro, *(f32 *)(a0 + 0x40), pos[4], *(f32 *)(ro + 0x20), *(f32 *)(ro + 0x24), *(f32 *)(ro + 0x28));
            *(f32 *)(a0 + 0x44) = func_L01_003F35B0_003EBA68(m + 0x34, *(f32 *)(a0 + 0x44), pos[5], *(f32 *)(ro + 0x20), *(f32 *)(ro + 0x24), *(f32 *)(ro + 0x28));
            *(f32 *)(a0 + 0x48) = func_L01_003F35B0_003EBA68(m + 0x38, *(f32 *)(a0 + 0x48), pos[6], *(f32 *)(ro + 0x20), *(f32 *)(ro + 0x24), *(f32 *)(ro + 0x28));
        }
    }
    func_L01_0040EB88_003EBA68(mtx, a0 + 0x40);
    func_L01_0040EDF0_003EBA68(a0, mtx);
    if (e[0x20] != 0) {
        func_L01_00404AD8_003EBA68(func_L01_003EB750_003EBA68, 0);
    }
}
/* localdecomp:end func_L01_003EBA68 */

/* localdecomp:start func_L01_003EBED0 */
s32 func_L01_003EBED0(void) {
    return 0;
}
/* localdecomp:end func_L01_003EBED0 */

/* localdecomp:start func_L01_003EBED8 */
extern s32 D_001A4E18[];
extern void func_L01_003EBA68(u8 *a0);
extern void func_L01_003F6048(void *a0, u8 *a1, f32 f12);
void func_L01_003EBED8(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 112) + 224;
    D_001A4E18[0] = 2;
    func_L01_003EBA68(a0);
    if (*(s32 *)(s0 + 64) != 0) {
        a0[137] = 0;
        func_L01_003F6048(*(void **)(a0 + 148), a0 + 48, 0.5f);
    }
}
/* localdecomp:end func_L01_003EBED8 */

/* localdecomp:start func_L01_003EBF38 */
void func_L01_003EBF38(void) {

}
/* localdecomp:end func_L01_003EBF38 */

/* localdecomp:start func_L01_003EBF40 */
typedef int q_3EBF40 __attribute__((mode(TI)));
typedef struct {
    s32 x0;
    f32 x4;
    f32 x8;
    s32 xC;
} S30_3EBF40_003EBF40;
typedef struct {
    q_3EBF40 x0;
    f32 x10;
    f32 x14;
    s32 x18;
    s16 h1C;
    s16 h1E;
    u8 pad20[0x10];
    S30_3EBF40_003EBF40 s;
} P0_3EBF40_003EBF40;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    f32 x34;
    s32 x38;
    s32 x3C;
    s32 x40;
    s32 x44;
    f32 x48;
    f32 x4C;
    u8 pad50[8];
    f32 x58;
    f32 x5C;
} Q_3EBF40_003EBF40;
typedef struct {
    f32 x0;
    f32 x4;
    u8 pad8[8];
    f32 x10;
    f32 x14;
} A_3EBF40_003EBF40;
typedef struct {
    f32 x0;
    s32 x4;
    void *x8;
} T_3EBF40_003EBF40;
typedef struct {
    P0_3EBF40_003EBF40 p0;
    Q_3EBF40_003EBF40 q;
    A_3EBF40_003EBF40 a;
    T_3EBF40_003EBF40 t;
} P_3EBF40_003EBF40;
typedef struct {
    q_3EBF40 x0;
    q_3EBF40 x10;
    q_3EBF40 x20;
    q_3EBF40 x30;
} S_3EBF40_003EBF40;
typedef struct {
    u8 pad0[0xF0];
    s32 xF0;
    u8 padF4[0x100 - 0xF4];
    s32 x100;
    u8 pad104[0x138 - 0x104];
    u8 *x138;
    f32 x13C;
} B_3EBF40_003EBF40;
typedef struct {
    u8 pad0[0x54];
    S_3EBF40_003EBF40 *x54;
    u8 pad58[0x150 - 0x58];
    B_3EBF40_003EBF40 b;
    u8 pad290[0x2A0 - 0x290];
    s16 h2A0;
    u8 pad2A2;
    u8 b2A3;
    u8 pad2A4[0x324 - 0x2A4];
    s32 x324;
} E_3EBF40_003EBF40;
typedef struct {
    q_3EBF40 x0;
    q_3EBF40 x10;
    q_3EBF40 x20;
    q_3EBF40 x30;
    q_3EBF40 x40;
    u8 pad50[0x20];
    P_3EBF40_003EBF40 *pv;
    u8 pad74[0x7E - 0x74];
    s16 h7E;
    u8 pad80[0x94 - 0x80];
    s32 w94;
} M_3EBF40_003EBF40;
extern Ent003EC730 D_L01_001E2A40_003EBF40[];
extern f32 func_L01_0040E8F8_003EBF40(f32);
extern f32 func_L01_0040E910_003EBF40(f32);
extern void func_L01_0040E620_003EBF40(void *, void *, f32);
extern f32 func_L01_0040E9C0_003EBF40(f32, f32);

void func_L01_003EBF40(u8 *mp) {
    M_3EBF40_003EBF40 *m = (M_3EBF40_003EBF40 *)mp;
    E_3EBF40_003EBF40 *e = (E_3EBF40_003EBF40 *)&D_L01_001E2A40_003EBF40[m->w94];
    P_3EBF40_003EBF40 *pv = m->pv;
    Q_3EBF40_003EBF40 *q = &pv->q;
    B_3EBF40_003EBF40 *b = &e->b;
    P_3EBF40_003EBF40 *pv2;
    T_3EBF40_003EBF40 *t;
    A_3EBF40_003EBF40 *a;
    P0_3EBF40_003EBF40 *p0;
    S30_3EBF40_003EBF40 *s;
    P_3EBF40_003EBF40 *pb;

    q->x4C = 1.5f;
    q->x48 = 0.20943952f;
    q->x58 = 0.0017453292f;
    q->x5C = -0.004363323f;
    q->x40 = 0;
    q->x44 = b->xF0;
    a = &m->pv->a;
    a->x0 = 4.64f;
    a->x4 = 0.5f;
    a->x10 = 2.0f;
    a->x14 = 0.05f;
    p0 = &m->pv->p0;
    qzero(&p0->x0);
    p0->x10 = 0.01f;
    p0->x14 = 0.3f;
    p0->h1E = 100;
    p0->h1C = 0;
    p0->x18 = 0;
    pb = m->pv;
    s = &pb->p0.s;
    s->x4 = 0.02f;
    s->x8 = 0.2f;
    s->xC = 0;
    pb->p0.s.x0 = 0;
    pv2 = m->pv;
    t = &pv2->t;
    t->x4 = 0;
    m->x30 = e->x54->x30;
    m->x0 = e->x54->x0;
    m->x10 = e->x54->x10;
    m->x20 = e->x54->x20;
    m->x40 = m->x0;
    m->h7E = 0;
    if ((u32)(b->x100 - 0x2B) < 2) {
        pv2->t.x0 = b->x13C;
        t->x8 = b->x138;
        q->x30 = func_L01_0040E8F8_003EBF40(pv2->t.x0);
        q->x34 = func_L01_0040E910_003EBF40(pv2->t.x0);
        q->x38 = 0;
    } else {
        vec_sub_ba(&q->x30, b->x138 + 0x10, &m->x30);
        q->x38 = 0;
        q->x3C = 0;
        func_L01_0040E620_003EBF40(&q->x30, &q->x30, 1.0f);
        pv2->t.x0 = func_L01_0040E9C0_003EBF40(q->x30, q->x34);
        t->x8 = b->x138;
    }
    e->b2A3 = 2;
    e->h2A0 = 1;
    ((E_3EBF40_003EBF40 *)&D_L01_001E2A40_003EBF40[m->w94])->x324 = 50;
}
/* localdecomp:end func_L01_003EBF40 */

INCLUDE_ASM("asm/levels", func_L01_003EC1A0);

/* localdecomp:start func_L01_003EC650 */
extern Ent003EC730 D_L01_001E2A40_003EC650[];
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);

void func_L01_003EC650(u8 *o)
{
    u8 *e = (u8 *)&D_L01_001E2A40_003EC650[*(s32 *)(o + 0x94)];
    u8 *p = *(u8 **)(o + 0x70);
    f32 *pa = (f32 *)(p + 0x30);
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 c;
    f32 a;
    f32 r;

    t = *(vu0_v4 *)(e + 0x190);
    e += 0x150;
    t.z += *(f32 *)(p + 0x8C);
    vec_sub_ba(&d, &t, o + 0x30);
    func_0038CF68(&d, &d, 1.0f);
    a = 1.5707964f - func_0038D0C8(func_0038CE68(&d, o));
    if (*(s32 *)(e + 0x100) == 0x24) {
        *pa += 0.017f;
        if (1.0f < *pa) {
            *pa = 1.0f;
        }
        r = a * *pa;
    } else {
        r = func_00382C58(pa, 0.0f, a, 0.02f, 0.175f, 0.0f);
    }
    func_0038CE90(&c, &d, o + 0x40);
    func_0038D890(o, o + 0x40, &c, r);
    func_0038CF68(o + 0x40, o, 1.0f);
    *(vu0_v4 *)o = *(vu0_v4 *)(o + 0x40);
    func_0038CE90(o + 0x10, o, &D_L01_001E2A40_003EC650[*(s32 *)(o + 0x94)].pad0[0x60] + 0x20);
    func_0038CF68(o + 0x10, o + 0x10, 1.0f);
    func_0038CE90(o + 0x20, o + 0x10, o);
}
/* localdecomp:end func_L01_003EC650 */

/* localdecomp:start func_L01_003EC848 */
extern void func_L01_003EC650_003EC848(void *);
extern void func_L01_003EC848(void *);

extern void func_L01_003EC1A0_003EC848();
void func_L01_003EC848(void *p) {
    func_L01_003EC1A0_003EC848(p);
    func_L01_003EC650_003EC848(p);
}
/* localdecomp:end func_L01_003EC848 */

LINKER_REMNANT("asm/levels", func_L01_003EC878);

/* localdecomp:start func_L01_003EC898 */
s32 func_L01_003EC898(void) {
    return 0;
}
/* localdecomp:end func_L01_003EC898 */

/* localdecomp:start func_L01_003EC8A0 */
extern u8 D_L01_001E2A40_003EC8A0[];
extern void func_L01_003EBF40(u8 *);
extern void func_L01_003EC848_003EC8A0(void *);
extern void func_L01_003F6048(void *a0, u8 *a1, f32 f12);
void func_L01_003EC8A0(u8 *m) {
    u8 *q;
    u8 *r;
    u8 *pv;
    s32 st;
    q = D_L01_001E2A40_003EC8A0 + *(s32 *)(m + 148) * 1120;
    r = q + 336;
    pv = *(u8 **)(m + 112) + 184;
    st = *(s32 *)(r + 256);
    if (st == 43 || (u32)(st - 35) < 3) {
        if (*(s32 *)(pv + 8) != *(s32 *)(r + 312)) {
            *(u128_t *)(*(u8 **)(q + 84) + 48) = *(u128_t *)(m + 48);
            *(u128_t *)*(u8 **)(q + 84) = *(u128_t *)m;
            *(u128_t *)(*(u8 **)(q + 84) + 16) = *(u128_t *)(m + 16);
            *(u128_t *)(*(u8 **)(q + 84) + 32) = *(u128_t *)(m + 32);
            func_L01_003EBF40(m);
            *(s32 *)(D_L01_001E2A40_003EC8A0 + *(s32 *)(m + 148) * 1120 + 804) = 37;
        }
    }
    func_L01_003EC848_003EC8A0(m);
    func_L01_003F6048(*(void **)(m + 148), m + 48, 0.5f);
    *(s32 *)(*(u8 **)(m + 112) + 128) = 0;
}
/* localdecomp:end func_L01_003EC8A0 */

/* localdecomp:start func_L01_003EC990 */
extern Ent003EC730 D_L01_001E2A40[];

void func_L01_003EC990(Obj_003EC990 *obj) {
    u8 *e = (u8 *)D_L01_001E2A40 + obj->w94 * 0x460;
    Sub_003EC990 *s = (Sub_003EC990 *)(e + 0x150);
    if (s->xFC != obj->f86 && s->x100 != 6) {
        obj->f7D = 0;
        obj->f7E = 3;
    }
}
/* localdecomp:end func_L01_003EC990 */

/* localdecomp:start func_L01_003EC9E0 */
extern char * D_L01_001DF804 __attribute__((section(".sdata")));
extern char *D_L01_001DF804 __attribute__((section(".sdata")));

/* from rac2-decomp's func_L00_00429020, renamed */
void func_L01_003EC9E0(int i) {
    unsigned char *q;
    q = *(unsigned char **)(D_L01_001DF804 + i * 0x20 + 0x1C);
    q[0x38] = 1;
    q[0x39] = 0;
}
/* localdecomp:end func_L01_003EC9E0 */

/* localdecomp:start func_L01_003ECA10 */
extern char *D_L01_001DF804;
int func_L01_003ECA10(int i) {
    unsigned char *p = *(unsigned char **)(D_L01_001DF804 + i * 32 + 28);
    int r = 0;
    if (p[68]) {
        r = p[57] != 0;
    }
    return r;
}
/* localdecomp:end func_L01_003ECA10 */

LINKER_REMNANT("asm/levels", func_L01_003ECA40);

/* localdecomp:start func_L01_003ECA48 */
extern char *D_L01_001DF804;
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];
extern u8 *D_L01_0021F6C0[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0044BFC8(void *, s32);
extern s32 func_L01_0044C078(void *, s32);
extern s32 func_L01_004463F8(void *, u8 *, s32);

s32 func_L01_003ECA48(u8 *m) {
    u8 *d = (*(E_3EAB98 * *)&D_L01_001DF804)[*(s16 *)(m + 0x84)].p;
    u8 *p;

    if (*(s32 *)(d + 160) != -1) {
        if (D_001BBC40[D_001D545C][*(s32 *)(d + 160)] & 0x80) {
            return 0;
        }
    }
    if (*(s32 *)(d + 12) >= 0) {
        if (func_00382380(D_001A4C60, *(s32 *)(d + 12), 0)) {
            return 1;
        }
    } else if (*(s32 *)(d + 16) >= 0) {
        if (func_L01_0044BFC8(D_001A4C60, *(s32 *)(d + 16))) {
            return 1;
        }
    } else if (*(s32 *)(d + 8) >= 0) {
        if (func_L01_0044C078(D_001A4C60, *(s32 *)(d + 8))) {
            return 1;
        }
    } else if (*(s32 *)(d + 20) >= 0) {
        p = D_L01_0021F6C0[*(s32 *)(d + 20)];
        if (func_L01_004463F8(D_001A4C60, p + 16, *(s32 *)p)) {
            return 1;
        }
    } else {
        if (d[56] != 0 && d[57] == 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003ECA48 */

/* localdecomp:start func_L01_003ECB58 */
/* after func_L01_0036DB78 (screen_warp_draw) in L01_0036B670.c */
typedef struct {
    u8 pad_0[0x150];
    s16 width;
    s16 height;
} Screen_003ECB58;
extern s32 D_001D5520;
extern Screen_003ECB58 D_001CFEC0;
__asm__(".extern D_L01_001DF71C, 4");
__asm__(".extern D_L01_001DF720, 4");
__asm__(".extern D_L01_001DF724, 4");
extern s32 D_L01_001DF71C;
extern s32 D_L01_001DF720;
extern s32 D_L01_001DF724;
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
void func_L01_003ECB58(void) {
    long colour;
    long frame_tex;

    func_L01_004C5E28();
    if (D_001D5520) {
        D_L01_001DF724 = -1;
        D_L01_001DF71C = 0xEC;
        D_L01_001DF720 = 0xF0;
    }
    func_003A9440(0x47, 0x513F1);
    func_003A9440(0x42, 0x800000006A);
    frame_tex = func_00389598(0x42);
    colour = 0x6E7F7F7F;
    func_0038B4D0(0, 0, (s32)(D_001CFEC0.width * 0.5f), (s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(D_001CFEC0.width, 0, -(s32)(D_001CFEC0.width * 0.5f), (s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(0, D_001CFEC0.height, (s32)(D_001CFEC0.width * 0.5f), -(s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_0038B4D0(D_001CFEC0.width, D_001CFEC0.height, -(s32)(D_001CFEC0.width * 0.5f), -(s32)(D_001CFEC0.height * 0.5f), 0, 0, 0xFF, 0xFF, colour, frame_tex);
    func_003A9440(0x42, 0x800000006A);
    func_003A9440(0x42, 0x8000000054);
    func_0038B4D0(0, 0, D_001CFEC0.width, D_001CFEC0.height, 10, 8, D_L01_001DF71C, D_L01_001DF720, 0x7F6F6F6F, func_00389598(D_L01_001DF724));
}
/* localdecomp:end func_L01_003ECB58 */

INCLUDE_ASM("asm/levels", func_L01_003ECDD0);

INCLUDE_ASM("asm/levels", func_L01_003ED1F8);

/* localdecomp:start func_L01_003EDC90 */
extern s32 func_L01_003ECA48(u8 *m);
extern char *D_L01_001DF804;
extern s32 D_001A71AC[];
extern s32 D_001A71A4[];
s32 func_L01_003EDC90(Obj_003EBD50 *a, Obj_003EBD50 *b) {
    Info_003EBD50 *info;
    info = (*(Ent_003EBD50 * *)&D_L01_001DF804)[a->f84].info;
    if (info->f39 != 0) {
        return -1;
    }
    if (info->f38 != 0 && b->f86 != 19) {
        return 1;
    }
    if (b != 0 && b->f7E == 0) {
        if (b->f7C >= a->f7C || b->f86 == 32) {
            if (b->f86 != 32) {
                return 0;
            }
        }
    }
    if (((s32 (*)(Obj_003EBD50 *))func_L01_003ECA48)(a) == 0) {
        return 0;
    }
    if (info->f43 >= 0 && D_001A71AC[0] != info->f43) {
        return 0;
    }
    if (info->f42 >= 0 && D_001A71A4[0] != info->f42) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_003EDC90 */

/* localdecomp:start func_L01_003EDD80 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EDD80(void) {
}
/* localdecomp:end func_L01_003EDD80 */

/* localdecomp:start func_L01_003EDD88 */
extern Ent003EC730 D_L01_001E2A40[];
extern char *D_L01_001E0100;
extern f32 func_0038CF38(void *, void *);

s32 func_L01_003EDD88(u8 *a) {
    u8 *owner = (u8 *)&D_L01_001E2A40[*(s32 *)(a + 0x94)];
    u8 *st = owner + 0x150;
    u8 *own = *(u8 **)(owner + 0x50);
    u8 *sub = *(u8 **)(own + 0x70);
    u8 *move = sub + 0x180;
    u8 *rot = sub + 0x1E0;
    u8 *p;
    u32 mode;
    s32 r;

    p = *(u8 **)(D_L01_001DF804 + *(s16 *)(a + 0x84) * 32 + 28);
    if (*(s16 *)(own + 0x86) != 0) {
        goto out;
    }
    mode = st[0x12B] == 1 || st[0x12B] == 2;
    if (*(s16 *)(p + 0x4A) && !mode) goto out;
    if (*(s16 *)(p + 0x48) && mode) goto out;
    if (*(s32 *)(p + 0x34)) {
        if (fabs_asm(*(f32 *)(move + 0x34)) > 0.01f) goto out;
        if (fabs_asm(*(f32 *)(rot + 8)) > 0.01f) goto out;
    }
    if ((u32)(*(s32 *)(st + 0x100) - 0x66) >= 2 && *(f32 *)(st + 0x110) > 0.020000001f) {
    out:
        return 0;
    }
    {
        if (*(s32 *)(p + 0xC) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_0038CF38(st + 0x40,D_L01_001E0100 + *(s32 *)(p + 0xC) * 128 + 0x30) < 3.0f) return 1;
            if (func_00382380(st + 0x40,*(s32 *)(p + 0xC), 0)) return 1;
        }
        if (*(s32 *)(p + 0x10) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_0038CF38(st + 0x40,D_L01_001E0100 + *(s32 *)(p + 0x10) * 128 + 0x30) < 3.0f) return 1;
            if (func_L01_0044BFC8(st + 0x40,*(s32 *)(p + 0x10))) return 1;
        }
        if (*(s32 *)(p + 8) >= 0) {
            if (*(s32 *)(st + 0x100) == 0x66 && func_0038CF38(st + 0x40,D_L01_001E0100 + *(s32 *)(p + 8) * 128 + 0x30) < 3.0f) return 1;
            if (func_L01_0044C078(st + 0x40,*(s32 *)(p + 8))) return 1;
        }
        r = 0;
        *(s16 *)(p + 0x26) = 1;
        return r;
    }
}
/* localdecomp:end func_L01_003EDD88 */

INCLUDE_ASM("asm/levels", func_L01_003EDFF0);

/* localdecomp:start func_L01_003EE568 */
extern char *D_L01_001DF804;
extern s32 D_L01_001D545C;
extern s32 D_L01_001D6694;
extern s32 func_L01_004BA800(void);
extern s32 func_L01_003EDD88(u8 *);
extern void func_L01_003EDFF0(u8 *);
s32 func_L01_003EE568(u8 *m) {
    u8 *e;
    e = *(u8 **)(D_L01_001DF804 + *(s16 *)(m + 132) * 32 + 28);
    if (*(s16 *)(e + 38) != 0) {
        if (D_L01_001D545C != 28)
            return 0;
        if (func_L01_004BA800() != 0)
            *(s16 *)(e + 38) = 0;
        return 0;
    }
    if (D_L01_001D6694 != 0) {
        if (func_L01_003EDD88(m) != 0) {
            *(s16 *)(e + 38) = 0;
            *(s32 *)(e + 32) = 0;
            return 0;
        }
    }
    if (D_L01_001D545C == 28 && func_L01_004BA800() != 0)
        return 0;
    func_L01_003EDFF0(m);
    return 0;
}
/* localdecomp:end func_L01_003EE568 */

/* localdecomp:start func_L01_003EE638 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EE638(void) {
}
/* localdecomp:end func_L01_003EE638 */

/* localdecomp:start func_L01_003EE640 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EE640(void) {
}
/* localdecomp:end func_L01_003EE640 */

/* localdecomp:start func_L01_003EE648 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003EE648(void) {
}
/* localdecomp:end func_L01_003EE648 */

/* localdecomp:start func_L01_003EE650 */
extern char *D_L01_001DF804 __attribute__((section(".sdata")));

/* from rac2-decomp's func_L00_0042A500, renamed */
void func_L01_003EE650(int i)
{
    char *q = *(char **)(D_L01_001DF804 + i * 0x20 + 0x1C);
    *(short *)(q + 0x26) = 0;
    *(int *)(q + 0x20) = 0;
}
/* localdecomp:end func_L01_003EE650 */

/* localdecomp:start func_L01_003EE670 */


extern Ent003EC730 D_L01_001E2A40[];
extern void func_0038CC88(u8 *, void *, s32);

void func_L01_003EE670(u8 *obj)
{
    Ent003EC730 *ent = &D_L01_001E2A40[*(s32 *)(obj + 148)];

    *(u128_t *)(obj + 48) = ent->v230;
    func_0038CC88(obj, ent->b200, 48);
    *(u16 *)(obj + 126) = 0;
    ent->b2A3 = 0;
    D_L01_001E2A40[*(s32 *)(obj + 148)].f2C8 = 0.075f;
    D_L01_001E2A40[*(s32 *)(obj + 148)].f2B8 = 0.075f;
}
/* localdecomp:end func_L01_003EE670 */

/* localdecomp:start func_L01_003EE708 */
extern u8 D_L01_001E2A40_003EE708[];
extern s32 D_L01_001D6694;
extern s32 D_001A4E18[];
s32 func_L01_003EE708(u8 *a0, u8 *a1) {
    u8 *q;
    u8 *r;
    q = D_L01_001E2A40_003EE708 + *(s32 *)(a0 + 148) * 1120;
    r = q + 336;
    if (D_L01_001D6694 == 0 && *(s32 *)(r + 252) == 32 && *(s16 *)(a1 + 134) == 0 && D_001A4E18[0] <= 0)
        return 1;
    return 0;
}
/* localdecomp:end func_L01_003EE708 */

/* localdecomp:start func_L01_003EE768 */
extern void func_0038CC88(u8 *, void *, s32);
extern Ent003EC730 D_L01_001E2A40[];

void func_L01_003EE768(M_3EC828 *m) {
    E_3EC828 *e = &((E_3EC828 *)&D_L01_001E2A40)[m->w94];
    m->q30 = e->q230;
    ((void (*)(M_3EC828 *, u8 *, s32))func_0038CC88)(m, e->b200, 48);
}
/* localdecomp:end func_L01_003EE768 */

/* localdecomp:start func_L01_003EE7B0 */
__asm__(".extern D_L01_001DF728, 4");
__asm__(".extern D_L01_001DF72C, 4");
typedef struct {
    u8 pad0[0x7E];
    s16 f7E;
    u8 pad80[0x86 - 0x80];
    s16 f86;
    u8 pad88[0x94 - 0x88];
    s32 w94;
} Obj_003EE7B0;
typedef struct {
    u8 pad0[0xFC];
    s32 xFC;
} Sub_003EE7B0;
typedef struct {
    u8 pad0[0x2A3];
    u8 b2A3;
    u8 pad2A4[0x2B8 - 0x2A4];
    f32 f2B8;
    u8 pad2BC[0x2C8 - 0x2BC];
    f32 f2C8;
    u8 pad2CC[0x458 - 0x2CC];
    s32 f458;
    u8 pad45C[0x460 - 0x45C];
} Ent_003EE7B0;
extern Ent_003EE7B0 D_L01_001E2A40_003EE7B0[];
extern s32 D_L01_001D6694_003EE7B0;
extern s32 D_L01_001D6690_003EE7B0;
extern f32 D_L01_001DF728;
extern f32 D_L01_001DF72C;
void func_L01_003EE7B0(Obj_003EE7B0 *m) {
    Ent_003EE7B0 *q;
    Sub_003EE7B0 *s;
    q = &D_L01_001E2A40_003EE7B0[m->w94];
    s = (Sub_003EE7B0 *)((u8 *)q + 0x150);
    if (s->xFC == m->f86 && D_L01_001D6694_003EE7B0 == 0 && (D_L01_001D6690_003EE7B0 == 0 || D_L01_001D6690_003EE7B0 == -2))
        return;
    if (s->xFC != 4 && s->xFC != 81) {
        q->b2A3 = 0;
        m->f7E = 2;
        ((Ent_003EE7B0 *)((u8 *)D_L01_001E2A40_003EE7B0 + m->w94 * 0x460))->f2C8 = D_L01_001DF72C;
        ((Ent_003EE7B0 *)((u8 *)D_L01_001E2A40_003EE7B0 + m->w94 * 0x460))->f2B8 = D_L01_001DF728;
    } else {
        q->f458 = 2;
        m->f7E = 4;
    }
}
/* localdecomp:end func_L01_003EE7B0 */

/* localdecomp:start func_L01_003EE880 */
extern u8 *D_L01_001DFB6C;
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);

void func_L01_003EE880(char *self) {
    int *sub = *(int **)(self + 8);
    unsigned int flags;
    float distance;
    if (sub[5] == 0) return;
    if (sub[0] < 0) return;
    distance = func_0038CF00(D_L01_001E29C0, self + 0x40);
    if (distance < *(float *)(self + 0xc)) {
        char *slot;
        flags = 0;
        if (*(u8 *)(D_L01_001DFB6C + sub[0] * 32 + 0x18)) flags |= 4;
        slot = (char *)D_001A30B0 + sub[4] * 0x80;
        if (*(char **)(slot + 0x100) == self && *(u8 *)(slot + 0xD0)) return;
        if (func_0038CAD0(sub + 3)) {
            sub[4] = func_L01_004AAE90(sub[0], flags, self, 0x400);
            if (sub[2] > 0) sub[3] = (int)((sub[1] + func_00382468(sub[2] - sub[1])) * 50.0f);
        }
    } else if (*(float *)(self + 0xc) + 1.0f < distance) {
        char *slot;
        int index = sub[4];
        if (index != -1) {
            slot = (char *)D_001A30B0 + index * 0x80;
            if (*(char **)(slot + 0x100) == self && *(u8 *)(slot + 0xD0)) func_003A4F28(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L01_003EE880 */

LINKER_REMNANT("asm/levels", func_L01_003EEA00);

INCLUDE_ASM("asm/levels", func_L01_003EEA08);

/* localdecomp:start func_L01_003EEF30 */

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} Sub_003EEF30;
typedef struct { f32 x, y, z; s32 w; } __attribute__((aligned(16))) V_003EEF30;

extern u8 D_001A30B0_003EEF30[];
extern void func_0038D000(void *, void *, void *);
extern f32 func_003824E0(f32, f32);

void func_L01_003EEF30(u8 *self) {
    V_003EEF30 a;
    V_003EEF30 b;
    V_003EEF30 ra;
    V_003EEF30 rb;
    V_003EEF30 v;
    vu0_q qa, qs, qv, qp;
    Sub_003EEF30 *sub;
    f32 s;
    u8 *slot;
    s32 n;

    { __asm__("lqc2 %0, %1" : "=j"(qs) : "m"(*(vu0_v4 *)D_L01_001E29C0)); }
    sub = *(Sub_003EEF30 **)(self + 8);
    s = *(f32 *)(self + 0xC);
    b.x = s;
    b.y = s;
    b.z = s;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(self + 0x40)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qs) : "j"(qs), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qs));
    a.w = 0;
    func_0038D000(&ra, &a, self + 0x50);
    func_0038D000(&rb, &b, self + 0x50);
    if (fabs_asm(rb.x) + 1.0f >= fabs_asm(ra.x)
        && fabs_asm(rb.y) + 1.0f >= fabs_asm(ra.y)
        && fabs_asm(rb.z) + 1.0f >= fabs_asm(ra.z)) {
        slot = D_001A30B0_003EEF30 + (sub->w10 << 7);
        if (*(u8 **)(slot + 0x100) == self && *(slot + 0xD0) != 0) {
            return;
        }
        if (func_0038CAD0(&sub->wC) != 0) {
            n = func_L01_004AAE90(sub->w0, 0, self, 0x400);
            sub->w10 = n;
            if (n != -1) {
                v.x = func_003824E0(-1.0f, 1.0f);
                v.y = func_003824E0(-1.0f, 1.0f);
                v.z = func_003824E0(-1.0f, 1.0f);
                func_0038D000(&v, &v, self + 0x10);
                __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(self + 0x40)));
                __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(v));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
                __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qv));
                *(vu0_q *)(D_001A30B0_003EEF30 + (sub->w10 << 7) + 0xE0) = *(vu0_q *)&v;
            }
            if (sub->w8 > 0) {
                sub->wC = (s32)((f32)(sub->w4 + func_00382468(sub->w8 - sub->w4)) * 50.0f);
            }
        } else {
            sub->w10 = -1;
        }
    }
}
/* localdecomp:end func_L01_003EEF30 */

INCLUDE_ASM("asm/levels", func_L01_003EF140);

INCLUDE_ASM("asm/levels", func_L01_003EF2D0);

/* localdecomp:start func_L01_003EF560 */




extern u8 D_001A3190[];
extern s32 D_L01_001E2E90[];
extern s32 func_L01_004AAE90(s32, s32, void *, s32);
extern void func_003A4F28(s32);

void func_L01_003EF560(Obj_003ED620 *obj) {
    H_003ED620 *h = obj->h;
    u8 *e;
    s32 on;

    if (h->f4 != -1) {
        *(s128_003ED620 *)(D_001A3190 + (h->f4 << 7)) = D_L01_001E29C0[0];
    }
    e = (u8 *)&D_001A30B0[h->f4];
    on = 0;
    if (*(void **)(e + 256) == obj) {
        on = e[208] != 0;
    }
    if (D_L01_001E2E90[0] != 0) {
        if (!on) {
            h->f4 = func_L01_004AAE90(h->f0, 21, obj, 1024);
        }
    } else if (on) {
        func_003A4F28(h->f4);
        h->f4 = -1;
    }
}
/* localdecomp:end func_L01_003EF560 */

/* localdecomp:start func_L01_003EF628 */
extern u8 D_001A4C60[];
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045F1E8(s32, s32);
void func_L01_003EF628(u8 *a) {
    vu0_v4 v;
    vu0_v4 w;
    s32 *s;
    s = *(s32 **)(a + 8);
    vec_sub_ab(&v, D_001A4C60, a + 64);
    v.w = 0;
    func_0038D000(&w, &v, a + 80);
    if (fabs_asm(w.x) <= 1.0f && fabs_asm(w.y) <= 1.0f && fabs_asm(w.z) <= 1.0f) {
        s[2] = 1;
    } else if (s[2] != 0) {
        if (w.x < 0.0f)
            func_L01_0045F1E8(s[1], s[4]);
        else
            func_L01_0045F1E8(s[0], s[3]);
        s[2] = 0;
    }
}
/* localdecomp:end func_L01_003EF628 */

INCLUDE_ASM("asm/levels", func_L01_003EF708);

/* localdecomp:start func_L01_003EFA80 */
f32 func_L01_003EFA80(f32 a, f32 b, f32 t) {
    return a * (1.0f - t) + b * t;
}
/* localdecomp:end func_L01_003EFA80 */

INCLUDE_ASM("asm/levels", func_L01_003EFAA0);

INCLUDE_ASM("asm/levels", func_L01_003EFB38);

/* localdecomp:start func_L01_003F0140 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003EE200;
extern u8 D_001A30B0_003F0140[];
extern void func_003A4F28(s32);

void func_L01_003F0140(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    V4_003EE200 d;
    V4_003EE200 l;
    s32 flags = 0x19;
    u8 *slot;

    vec_sub_ab(&d, D_L01_001E29C0, self + 0x40);
    d.w = 0.0f;
    func_0038D000(&l, &d, self + 0x50);
    if (fabs_asm(l.x) <= 1.0f && fabs_asm(l.y) <= 1.0f && fabs_asm(l.z) <= 1.0f) {
        if (*(u8 *)(D_L01_001DFB6C + sub[0] * 32 + 0x18)) flags |= 4;
        slot = D_001A30B0_003F0140 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || !slot[0xD0]) {
            if (func_0038CAD0(sub + 3)) {
                sub[4] = func_L01_004AAE90(sub[0], flags, self, 0x400);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_00382468(sub[2] - sub[1])) * 50.0f);
                }
            } else {
                sub[4] = -1;
            }
        } else {
            *(s32 *)(slot + 0x118) = flags;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001A30B0_003F0140 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_003A4F28(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L01_003F0140 */

INCLUDE_ASM("asm/levels", func_L01_003F02D8);

/* localdecomp:start func_L01_003F08C0 */
extern s32 D_L01_001D56C0;
s32 func_L01_003F08C0(void) {
    return D_L01_001D56C0;
}
/* localdecomp:end func_L01_003F08C0 */

INCLUDE_ASM("asm/levels", func_L01_003F08C8);

/* localdecomp:start func_L01_003F1188 */
extern u8 D_L01_002A43C0[];
extern u8 D_L01_001DF780[];
extern void func_0038CBA0(void *, s32);
void func_L01_003F1188(void) {
    s32 size = D_L01_002A43C0 - D_L01_001DF780;
    if ((size & 0xF) == 0 && ((u32)D_L01_001DF780 & 0xF) == 0) {
        func_0038CBA0(D_L01_001DF780, size);
    } else {
        s32 i;
        for (i = 0; i < D_L01_002A43C0 - D_L01_001DF780; i++) {
            D_L01_001DF780[i] = 0;
        }
    }
}
/* localdecomp:end func_L01_003F1188 */

/* localdecomp:start func_L01_003F1218 */
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x15C - 0x14];
    s32 x15C;
    u8 pad160[4];
    s32 x164;
    u8 pad168[4];
    s32 x16C;
    u8 pad170[0x17C - 0x170];
    s32 x17C;
} S_003F1218;
typedef struct {
    u8 pad0[0x120];
    u16 x120;
} T_003F1218;
extern S_003F1218 D_00142430;
extern T_003F1218 D_001A7E18;
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
extern s32 D_L01_001D6694_003F1218;
extern s32 D_L01_001DF948_003F1218;
extern s32 D_L01_001DF780_003F1218;
extern s32 func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern s32 func_00396968(s32, s32);
extern void func_00396C60(s32, s32, s32, s32, s32, s32);
extern s32 func_00396A38(s32);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, s32);
extern void func_00389370(void);

void func_L01_003F1218(void) {
    s32 a;
    s32 n;
    f32 ang;

    if (!((u32)(D_00142430.x15C - 15) < 2 || D_00142430.x164 == 15 || D_L01_001DF780_003F1218 != 0)) {
        return;
    }
    if (D_00142430.x16C != 0 || D_00142430.x10 != 0) {
        D_00142430.x17C = 0;
        D_001D4CE8 = 0x18;
        D_001D4CEC = 0x40;
        D_L01_001DF780_003F1218 = 0;
        if (D_L01_001D6694_003F1218 == 0) {
            func_003A0EC0(4, 1, 1, 0, 0);
        } else {
            func_003A0EC0(4, 2, 1, 0, 0);
        }
        return;
    }
    a = D_L01_001DF780_003F1218;
    if (a == -1) {
        if (D_L01_001D6694_003F1218 != 0) {
            return;
        }
        if (D_001A7E18.x120 == 0) {
            D_001A7E18.x120 = 1;
        }
        D_L01_001DF780_003F1218 = 0;
        return;
    }
    if (D_L01_001D6694_003F1218 == 0 && D_001A7E18.x120 == 0) {
        func_003A0EC0(4, 1, 2, 0, 0);
        D_L01_001DF780_003F1218 = -1;
        return;
    }
    if ((u32)(D_00142430.x15C - 15) < 2 || D_00142430.x164 == 15) {
        D_L01_001DF780_003F1218 = 25;
    } else {
        D_L01_001DF780_003F1218 = a - 1;
    }
    func_00389240(0);
    n = 55;
    func_003A9440(0x47, 0x2004B);
    func_00396C60(func_00396968(0x755D, 0), 0x1A9, 0xFA, 0x40, 0x40, 0x80);
    ang = (f32)(D_L01_001DF948_003F1218 % n) * -6.28318548f / (f32)n;
    func_00397638(7312.0f, 4512.0f, 272.0f, 272.0f, ang, 0x40, 0x40, func_00396A38(func_00396968(0x755D, 1)));
    func_00389370();
    if (D_001D4CE8 == 3) {
        D_L01_001DF780_003F1218 = 0;
    }
}
/* localdecomp:end func_L01_003F1218 */

INCLUDE_ASM("asm/levels", func_L01_003F1478);

/* localdecomp:start func_L01_003F1600 */
extern s32 D_00143950[];
extern s8 D_L01_001E6DE1[];
extern s32 D_L01_001DF948;
extern void func_L01_00461818(void);
extern void func_L01_004BA278(void);
extern void func_L01_003F26E0(void);
extern s32 func_0012C908(s32);

s32 func_L01_003F1600(void) {
    s32 limit = 9600;
    s32 r;

    if (D_00143950[0] != 0) {
        limit = 11520;
    }
    if (limit < *(volatile s32 *)0x10000800 && D_L01_001E6DE1[0] == 0) {
        func_L01_00461818();
        func_L01_004BA278();
    }
    func_L01_003F26E0();
    r = func_0012C908(0);
    D_L01_001DF948++;
    return r;
}
/* localdecomp:end func_L01_003F1600 */

/* localdecomp:start func_L01_003F1680 */
extern void func_L01_003F1E68(void *a, s32 b, void *c);
extern G_3EF740 D_L01_00237800;
extern s16 D_001CD018[];
extern u8 D_L01_001D667B;
extern void func_003A9108(void);
extern void func_0013CA28(void);
extern void func_0013B620(void);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_L01_0041A6E0(void);
extern void func_L01_0042B4F8(s32, s32);
extern void func_L01_00430110(s32);
extern void func_L01_0045A720(s32);
extern void func_003A1930(s32, s32, s32);
extern void func_L01_0041BFE8(void);
extern void func_L01_00478608(void);
void func_L01_003F1680(s32 a0) {
    s32 n;
    func_003A9108();
    func_0013CA28();
    func_0013B620();
    func_003A5430();
    func_003A1C28();
    n = D_001CD018[0];
    if (D_L01_00237800.x0 != 0) {
        n = D_L01_00237800.xC64;
    }
    func_L01_0041A6E0();
    func_L01_0042B4F8(0, a0);
    func_L01_00430110(0);
    func_L01_0045A720(0);
    func_003A1930(n, 1, 1024);
    func_L01_0041BFE8();
    func_L01_00478608();
    ((void (*)(void))func_L01_003F1E68)();
    D_L01_001D667B = 0;
}
/* localdecomp:end func_L01_003F1680 */

/* localdecomp:start func_L01_003F1740 */
extern void func_L01_003F5748(s32);

void func_L01_003F1740(void) {
    func_L01_003F5748(0);
}
/* localdecomp:end func_L01_003F1740 */

INCLUDE_ASM("asm/levels", func_L01_003F1760);

/* localdecomp:start func_L01_003F1780 */
extern void func_00384CC8();
void func_L01_003F1780(void) {
    ((s32 * (*)(s32))func_00384CC8)(2);
}
/* localdecomp:end func_L01_003F1780 */

/* localdecomp:start func_L01_003F17A0 */
extern void func_00384CC8();
void func_L01_003F17A0(void) {
    func_00384CC8(3);
}
/* localdecomp:end func_L01_003F17A0 */

/* localdecomp:start func_L01_003F17C0 */
extern f32 D_L01_001DF788[2];

void func_L01_003F17C0(void *a0, s32 *out) {
    s32 i;
    f32 big = 1000000.0f;
    for (i = 0; i < 4; i++) {
        f32 best = big;
        s32 bi = -1;
        s32 j;
        for (j = 0; j < 4; j++) {
            if (D_L01_001DF788[j] < best) {
                best = D_L01_001DF788[j];
                bi = j;
            }
        }
        out[i] = bi;
        D_L01_001DF788[bi] = big;
    }
}
/* localdecomp:end func_L01_003F17C0 */

/* localdecomp:start func_L01_003F1850 */
extern s32 D_001D52F0;
extern void (*D_L01_001DF9C0_003F1850[])(void);
extern void (*D_L01_001DF9D0_003F1850[])(void);
extern s32 D_L01_001E0054_003F1850;
extern s32 D_00143950[];
extern f32 D_L01_001DFB50_003F1850;
extern f32 D_L01_001DF788_003F1850[2];
extern void func_L01_00403168_003F1850(s32);
extern void func_L01_00403440_003F1850(s32);
extern void func_L01_004C59F8_003F1850(s32);
extern void func_L01_004C58D8_003F1850(void);
extern void func_L01_004C5858_003F1850(void);

void func_L01_003F1850(s32 a0, s32 a1, s32 a2, s32 a3) {
    f32 t;
    f32 d;

    D_001D52F0 = a0;
    if (D_L01_001DF9C0_003F1850[a0] != 0) {
        D_L01_001DF9C0_003F1850[a0]();
    }
    func_L01_00403168_003F1850(a1);
    if (a2 == 0) {
        D_L01_001E0054_003F1850 = 1;
    }
    t = *(volatile u32 *)0x10000800;
    d = t / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_L01_00403440_003F1850(a0);
    D_L01_001DF788_003F1850[a0] = D_L01_001DFB50_003F1850 - d;
    if (a3 == 0) {
        func_L01_004C59F8_003F1850(1);
        func_L01_004C58D8_003F1850();
        func_L01_004C5858_003F1850();
    }
    if (D_L01_001DF9D0_003F1850[a0] != 0) {
        D_L01_001DF9D0_003F1850[a0]();
    }
}
/* localdecomp:end func_L01_003F1850 */

/* localdecomp:start func_L01_003F19B0 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003F19B0(void) {
}
/* localdecomp:end func_L01_003F19B0 */

INCLUDE_ASM("asm/levels", func_L01_003F19B8);

/* localdecomp:start func_L01_003F1E68 */
extern void func_L01_0045E4B0();
extern s32 D_L01_001DFB40;

void func_L01_003F1E68(void *a, s32 b, void *c) {
    func_L01_0045E4B0(a, b, c);
    D_L01_001DFB40 += 1;
}
/* localdecomp:end func_L01_003F1E68 */

/* localdecomp:start func_L01_003F1E98 */
extern void func_0038CBC8(char *, s32);
extern char D_L01_001D5480[] __attribute__((section(".sdata")));
extern u8 D_L01_001D5477 __attribute__((section(".sdata")));
extern u8 D_L01_001D548F __attribute__((section(".sdata")));
extern u8 *D_L01_001E0ED4;
extern s32 D_L01_001E0EE0;

void func_L01_003F1E98(s32 a0) {
    s32 i;
    u8 *p;
    if (a0 != 0) {
        func_0038CBC8(D_L01_001D5480, 0x13);
    }
    if (D_L01_001D5477 != D_L01_001D548F) {
        p = D_L01_001E0ED4;
        for (i = 0; i < D_L01_001E0EE0; i++) {
            p[0x1E] ^= 8;
            p += 0x20;
        }
    }
}
/* localdecomp:end func_L01_003F1E98 */

/* localdecomp:start func_L01_003F1F08 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003F1F08(void) {
}
/* localdecomp:end func_L01_003F1F08 */

/* localdecomp:start func_L01_003F1F10 */
/* from rac2-decomp's func_001203C0, renamed */
void func_L01_003F1F10(void) {
}
/* localdecomp:end func_L01_003F1F10 */

LINKER_REMNANT("asm/levels", func_L01_003F1F18);

/* localdecomp:start func_L01_003F1F20 */
struct Rac2Native_5f824a0e369ccf7b_src_record {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short s4;
    unsigned short s6;
    unsigned short s8;
    unsigned short s10;
    unsigned short s12;
    unsigned char e;
    unsigned char f;
};
extern struct Rac2Native_5f824a0e369ccf7b_src_record *D_L01_002BF4A0[];
int func_L01_003F2058();

/* from rac2-decomp's func_L00_002D6900, renamed */
int func_L01_003F1F20(unsigned int index)
{
    if (index < 0x62)
        return func_L01_003F2058(D_L01_002BF4A0[index]);
    return -1;
}
/* localdecomp:end func_L01_003F1F20 */

/* localdecomp:start func_L01_003F1F60 */
extern u8 D_L01_001E2480_003F1F60[];

void func_L01_003F1F60(u8 *arg0) {
    s32 var_v1;
    s32 var_a1;
    u8 *var_v0;
    u8 temp;

    var_v1 = 0;
    if (arg0 != 0) {
        temp = arg0[0x557];
        if (temp == 0xFF) {
            return;
        }
        var_v1 = arg0[0x54C] * 4 + temp;
    }
    var_v1 = (var_v1 << 7) + (s32)D_L01_001E2480_003F1F60;
    var_v0 = (u8 *)var_v1 + 0x70;
    var_a1 = 7;
    do {
        *var_v0 = 0;
        var_a1 -= 1;
        var_v0 -= 0x10;
    } while (var_a1 >= 0);
}
/* localdecomp:end func_L01_003F1F60 */

/* localdecomp:start func_L01_003F1FC0 */
extern u8 D_L01_001E2480_003F1FC0[];

s32 func_L01_003F1FC0(s32 a0, u8 *a1) {
    s32 idx;
    u8 *p;

    idx = 0;
    if (a1 != 0) {
        idx = a1[0x54c] * 4 + a1[0x557];
    }
    p = D_L01_001E2480_003F1FC0 + (a0 * 16 + idx * 128);
    return *p != 0;
}
/* localdecomp:end func_L01_003F1FC0 */

/* localdecomp:start func_L01_003F2000 */
extern u8 D_L01_001E2480_003F2000[];

void func_L01_003F2000(void) {
    s32 i;
    s32 j;
    u8 *p;
    for (i = 0; i < 8; i++) {
        p = D_L01_001E2480_003F2000 + i * 128;
        for (j = 7; j >= 0; j--) {
            p[0] = 0;
            p[1] = 0;
            *(s16 *)(p + 0xa) = 0;
            *(s16 *)(p + 0xc) = 0;
            p[0xe] = 0;
            p += 16;
        }
    }
}
/* localdecomp:end func_L01_003F2000 */

/* localdecomp:start func_L01_003F2058 */
extern Tab_003F2058 D_L01_001E2480[];

int func_L01_003F2058(Rec_003F2058 *src, Ctx_003F2058 *ctx)
{
    int base = 0;
    int n = 0;
    int i;
    int j;

    if (ctx) {
        if (ctx->b557 == 255)
            return 0;
        base = ctx->b54C * 4 + ctx->b557;
    }

    for (n = 0; n < 8 && src[n].b0 != 255; n++)
        ;

    j = 0;
    for (i = 0; i < 8 && j < n; i++) {
        if (D_L01_001E2480[base].r[i].b0 == 0)
            j++;
    }

    if (j != n)
        return -1;

    for (j = 0; j < n; j++) {
        for (i = 0; i < 8 && D_L01_001E2480[base].r[i].b0 != 0; i++)
            ;
        if (i < 8) {
            D_L01_001E2480[base].r[i].b0 = src[j].b0;
            D_L01_001E2480[base].r[i].b1 = src[j].b1;
            D_L01_001E2480[base].r[i].b2 = src[j].b2;
            D_L01_001E2480[base].r[i].b3 = src[j].b3;
            D_L01_001E2480[base].r[i].s4 = src[j].s4;
            D_L01_001E2480[base].r[i].s6 = src[j].s6;
            D_L01_001E2480[base].r[i].s8 = src[j].s8;
            D_L01_001E2480[base].r[i].s10 = src[j].s10;
            D_L01_001E2480[base].r[i].s12 = src[j].s12;
            D_L01_001E2480[base].r[i].e = src[j].e - src[j].f;
            D_L01_001E2480[base].r[i].f = src[j].f;
            if (D_L01_001E2480[base].r[i].s10 + D_L01_001E2480[base].r[i].s12 == 0)
                D_L01_001E2480[base].r[i].s10++;
        }
    }
    return i;
}
/* localdecomp:end func_L01_003F2058 */

/* localdecomp:start func_L01_003F2278 */

void func_L01_003F2278(s32 arg0, void *arg1) {
    s32 idx = 0;
    s32 n;
    u8 *p;

    if (arg1 != 0) {
        u8 t = ((u8 *)arg1)[0x557];
        if (t == 0xFF) {
            return;
        }
        idx = ((u8 *)arg1)[0x54C] * 4 + t;
    }
    n = 7;
    p = (u8 *)D_L01_001E2480 + (idx << 7);
    do {
        n -= 1;
        if (p[1] != 0) {
            p[1] = 0;
            *(s16 *)(p + 6) = 0;
        }
        p += 0x10;
    } while (n >= 0);
}
/* localdecomp:end func_L01_003F2278 */

INCLUDE_ASM("asm/levels", func_L01_003F22D8);

/* localdecomp:start func_L01_003F26E0 */
typedef struct E_003F26E0 {
    u8 pad0[0x188];
    u8 f188;
    u8 f189;
    u8 pad1[0x558 - 0x18A];
    u8 f558;
    u8 pad2[0x5C0 - 0x559];
} E_003F26E0;
typedef struct R_003F26E0 {
    s32 v;
    u8 b;
} R_003F26E0;
extern E_003F26E0 D_001CD0C0[8];
extern u8 D_001439FE[];
__asm__(".extern D_L01_001D5FC8_003F26E0, 4");
extern s32 D_L01_001D5FC8_003F26E0;
extern s32 func_L01_003F22D8_003F26E0(R_003F26E0 *, E_003F26E0 *);

void func_L01_003F26E0(void)
{
    s32 i;
    s32 *q = &D_L01_001D5FC8_003F26E0;
    for (i = 0; i < 8; i++) {
        E_003F26E0 *p = &D_001CD0C0[i];
        if (p->f558 != 0) {
            R_003F26E0 r;
            func_L01_003F22D8_003F26E0(&r, p);
            if (D_001439FE[i] != 0) {
                s32 s = q[i] + r.v;
                q[i] = s;
                if (s >= 0x100) {
                    p->f188 = 1;
                    q[i] = s - 0xFF;
                } else {
                    p->f188 = 0;
                }
                p->f189 = r.b;
            }
        } else {
            p->f188 = 0;
            p->f189 = 0;
        }
    }
}
/* localdecomp:end func_L01_003F26E0 */
