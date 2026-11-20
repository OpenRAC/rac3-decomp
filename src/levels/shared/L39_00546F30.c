#include "common.h"

/* localdecomp:start func_L39_00546F30 */
typedef struct {
    char pad0[0x3];
    u8 flags;
} Ent;

extern Ent *func_L39_0061D7B0(s32);

void func_L39_00546F30(s32 id, f32 *a, f32 *b) {
    Ent *e = func_L39_0061D7B0(id);
    Ent *r;

    r = 0;
    if (e != 0) {
        if (e->flags & 0xF) {
            r = 0;
        } else {
            r = e;
        }
    }

    if (r != 0) {
        if (a != 0) {
            *a = 4.0f;
        }
        if (b != 0) {
            *b = 7.0f;
        }
    } else {
        if (a != 0) {
            *a = 7.0f;
        }
        if (b != 0) {
            *b = 15.0f;
        }
    }
}
/* localdecomp:end func_L39_00546F30 */

/* localdecomp:start func_L39_00546FE0 */
#include "vu0.h"

typedef int q_00546FE0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00546FE0;
typedef union { u8 b[8]; u32 w[2]; } Buf_00546FE0;
typedef struct { f32 x, y, z; } V3_00546FE0;

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_00546FE0;

typedef struct O_00546FE0 O_00546FE0;
typedef struct {
    u8 pad0[0x34];
    void (*f34)(O_00546FE0 *, s32, s32, s32, s32);
} Vt_00546FE0;

struct O_00546FE0 {
    u8 pad0[0x14];
    Vt_00546FE0 *vt;
    u8 pad18[0xA0 - 0x18];
    u8 bA0[0x380 - 0xA0];
    q_00546FE0 q380;
    q_00546FE0 q390;
    V_00546FE0 v3A0;
    q_00546FE0 q3B0;
    u8 pad3C0[0x3E0 - 0x3C0];
    s32 w3E0;
    u8 pad3E4[0x1078 - 0x3E4];
    s32 w1078;
    u8 pad107C[0x122C - 0x107C];
    s32 w122C;
    u8 pad1230[0x1250 - 0x1230];
    f32 f1250;
    u8 pad1254[0x1338 - 0x1254];
    f32 f1338;
    s32 w133C;
    u8 pad1340[0x19E4 - 0x1340];
    u8 b19E4;
    u8 p19E5;
    u8 b19E6;
    u8 p19E7[0x1A07 - 0x19E7];
    u8 b1A07;
    u8 b1A08;
    u8 p1A09[0x1A0D - 0x1A09];
    u8 b1A0D;
    u8 p1A0E[0x1A14 - 0x1A0E];
    u8 b1A14;
    u8 p1A15[0x1A40 - 0x1A15];
    u8 b1A40[0x24C9 - 0x1A40];
    u8 b24C9;
    u8 p24CA[0x2524 - 0x24CA];
    P_00546FE0 *p2524;
    u8 p2528[0x2534 - 0x2528];
    void *p2534;
    u8 p2538[0x2544 - 0x2538];
    s32 w2544;
    s32 w2548;
};

typedef struct {
    f32 f0;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    f32 fC;
    V_00546FE0 v10;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    q_00546FE0 q30;
    s32 w40;
    f32 f44;
    s32 w48;
    s32 w4C;
    O_00546FE0 *o;
    V3_00546FE0 v54;
} M_00546FE0;

typedef struct {
    u8 pad0[0x10];
    V_00546FE0 v10;
    u8 b20;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    M_00546FE0 *m;
    u8 pad6C[0xAA - 0x6C];
    u16 hAA;
    u8 padAC[0xC0 - 0xAC];
    V_00546FE0 vC0;
    V_00546FE0 vD0;
    V_00546FE0 vE0;
} A_00546FE0;

typedef struct {
    u8 pad0[0x3C];
    f32 x, y, z;
    u8 pad48[0x50 - 0x48];
} S_00546FE0;

typedef struct {
    u8 pad0[0xC];
    s16 hC;
    u8 padE[0x21 - 0xE];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x30 - 0x2C];
    f32 f30;
    u8 pad34[0x80 - 0x34];
} E_00546FE0;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[0x28 - 0x24];
    s32 w28;
    s32 w2C;
    u8 pad30[0x460 - 0x30];
} C_00546FE0;

typedef struct {
    V_00546FE0 v;
    A_00546FE0 *a;
    u32 w74;
    u8 b78;
    u8 b79;
    u16 h7A;
    f32 f7C;
    s32 w80;
    s32 w84;
    s32 w88;
} L_00546FE0;

typedef struct {
    u8 pad0[0x98];
    s32 w98;
} R_00546FE0;

extern u8 D_L39_004997E0[];
extern E_00546FE0 D_L39_0049C890[];
extern C_00546FE0 D_L39_0024DE80[];
extern O_00546FE0 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern s32 D_L39_002637C0[];
extern u8 D_L39_00470480[];
extern s32 D_L39_0024AFB0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AFB0, 4");
extern s32 D_L39_0024AFA0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AFA0, 4");
extern s32 D_L39_0024AFA4 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AFA4, 4");
extern s32 D_L39_0024AFA8 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AFA8, 4");
extern s32 D_L39_0024AFAC __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AFAC, 4");
extern s32 D_L39_0024AFD4 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AFD4, 4");
extern s32 D_L39_0024AF90 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AF90, 4");

extern void func_L39_0061C4D0(u8 *, u8 **);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern s32 func_L01_0040E050(void *);
extern s32 func_L39_00639D90(void *);
extern void func_L39_00546F30(s32 id, f32 *a, f32 *b);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L39_005FFD20(f32, f32 *, s32 *, s32);
extern s16 func_L39_00620CF8(u8 *, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_00674320(void *);
extern s32 func_L39_006732D0(void *p, s32 a1, s32 a2, s32 a3);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern f32 func_L39_005B44C8(void);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_003F2278(s32, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00457588(u8 *, void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L39_00548130(void *, void *);
extern void func_L39_00548648(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L39_005FFE78(void);
extern void func_L01_00446978(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D590(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D850(void *out, void *a, void *b);
extern void func_003C4840(f32 *q, void *axis, f32 angle);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern R_00546FE0 *func_L39_00547E10_00546FE0(void *, void *, void *, void *, f32);

static __inline__ u32 decode_00546FE0(u8 *p) {
    Buf_00546FE0 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ u8 state_00546FE0(O_00546FE0 *o, u32 st) {
    s32 r = 0;

    if (decode_00546FE0(&o->b19E4) == st) {
        r = 1;
    }
    return r;
}

static __inline__ u8 bonus_00546FE0(O_00546FE0 *o) {
    s32 r = 0;

    if (decode_00546FE0(&o->b19E6) != 0) {
        r = 1;
    }
    return r;
}

static __inline__ u8 aim_00546FE0(O_00546FE0 *o) {
    return o->b1A08 != 0;
}

static __inline__ u8 busy_00546FE0(O_00546FE0 *o) {
    return o->b1A07 != 0;
}

static __inline__ u8 net_00546FE0(O_00546FE0 *o) {
    return o->b1A14 != 0;
}

static __inline__ E_00546FE0 *ent_00546FE0(O_00546FE0 *o, s32 id) {
    if (func_L39_00648AE0((u8 *)o, id) != 0) {
        return &D_L39_0049C890[D_L39_0049C890[id].b21];
    }
    return &D_L39_0049C890[id];
}

static __inline__ s32 query_00546FE0(void *pos, s32 flags, void *ign, s32 info, f32 r, s32 player) {
    O_00546FE0 *p = D_L39_0024CE20[player];
    s32 n;

    player = -1;
    if (p != 0) {
        player = p->w2548;
    }
    func_L39_005FFDF8(player);
    n = func_003D4D00(pos, flags, ign, info, r);
    func_L39_005FFE78();
    return n;
}

void func_L39_00546FE0(A_00546FE0 *a0) {
    M_00546FE0 *m;
    O_00546FE0 *o;
    u32 color;
    s32 res;
    f32 dist;

    m = a0->m;
    if (a0->b20 == 0) {
        a0->b20 = 1;
        m->h8 = 0;
        m->hA = 0;
        m->w4C = -1;
        func_L39_0061C4D0((u8 *)a0, (u8 **)&m->o);
    }
    if (m->o == 0) {
        return;
    }
    o = m->o;
    if (a0->b20 == 6 && func_0038CB00(&m->h4) != 0) {
        func_L39_005F33E0(2, 0, a0);
        a0->b20 = 1;
    }
    if (a0->b42 == a0->b43 && (a0->b60 & 2)) {
        func_L01_00444F38((u8 *)a0, 1, 0, 2, 0);
    }
    if (state_00546FE0(o, 1)) {
        o->vt->f34(o, 0x1D, 0, 0, 1);
    }
    func_L01_0040E050(m);
    if (net_00546FE0(o) && func_L39_00639D90(o) != 0) {
        if (o->f1250 >= 0.8f) {
            o->w1078 = o->w122C;
            func_L39_00546F30(o->w122C, &dist, 0);
            if (dist > func_0038CF00(o->bA0, (u8 *)o->w122C + 0x10)) {
                color = 0x700000FF;
            } else {
                color = 0x601080FF;
            }
        } else {
            color = func_L39_005FFD20(150.0f, &o->f1338, &o->w133C, 0);
        }
        if (net_00546FE0(o)) {
            func_L01_003F6F20(o->b24C9, a0, color, 0, 0x20, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    } else if (net_00546FE0(o) && state_00546FE0(o, 0x1D)) {
        if (m->f0 > 0.0f && func_L39_00620CF8((u8 *)o, -1) != 0) {
            color = 0x600000FF;
        } else {
            color = 0x600FFF0F;
        }
        if (net_00546FE0(o)) {
            func_L01_003F6F20(o->b24C9, a0, color, 0, 0x20, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    } else if (!net_00546FE0(o)) {
        func_L39_00674320(o);
    }
    if (o->w3E0 != 0) {
        o->w1078 = o->w3E0;
    }
    if (a0->b20 == 1) {
        o->b1A0D = 0;
    } else {
        o->b1A0D = 1;
    }
    {
    S_00546FE0 s;

    res = func_L39_006732D0(o->b1A40, 0, 1, (s32)&s);
    if (res == 8) {
        s32 v = o->p2524->b43;

        if (v == ent_00546FE0(o, 2)->hC || bonus_00546FE0(o) || aim_00546FE0(o)) {
            m->w48 = 1;
            m->h6 = (D_L39_0024AFA0 * 5 + 2) / 6;
            m->h8 = (D_L39_0024AFA8 * 5 + 2) / 6;
            m->hA = (D_L39_0024AFB0 * 5 + 2) / 6;
        } else {
            m->h6 = 2;
            m->w48 = 0;
            m->h8 = (D_L39_0024AFA4 * 5 + 2) / 6;
            m->hA = (D_L39_0024AFAC * 5 + 2) / 6;
        }
        if (!net_00546FE0(o)) {
            V3_00546FE0 *v = &m->v54;

            v->x = s.x;
            v->y = s.y;
            v->z = s.z;
        }
        func_L39_00621D60(o, -1);
        m->w4C = func_L01_003F2058(D_L39_00470480, o->p2534);
        a0->b20 = 2;
        m->fC = func_L39_005B44C8();
        func_003C3A10(a0, 2, 0, 0);
        m->f20 = 1.0f / (f32)m->h8;
        m->f24 = 1.0f / (f32)m->hA;
        m->f28 = func_L39_005B44C8();
        m->f2C = func_L39_005B44C8();
        m->w40 = (D_L39_0024AFD4 * 5 + 2) / 6;
        m->f44 = 1.0f / (f32)m->w40;
    } else if (res == 4) {
        func_L39_005F33E0(4, 0, a0);
    }
    }
    if ((res != 8 || !busy_00546FE0(o)) && m->w4C >= 0) {
        func_L01_003F2278(m->w4C, o->p2534);
        m->w4C = -1;
    }
    if (m->h6 == 0) {
        func_0038CB00(&m->hA);
        func_0038CB00(&m->h8);
        func_0038CAD0(&m->w40);
        {
        unsigned long t8 = *(u32 *)&m->h8;
        if (t8 != 0) {
            func_L01_00404A10(func_L39_00548648, a0);
        }
        }
    }
    if ((a0->b20 == 2 || a0->b20 == 3) && func_0038CB00(&m->h6) != 0) {
        if (o->w1078 != 0) {
            func_L01_00457588((u8 *)o->w1078, &m->v10, &o->q3B0, 1.0f);
            o->q380 = o->q3B0;
        } else if (!net_00546FE0(o)) {
            V3_00546FE0 *src = &m->v54;
            V_00546FE0 *v = (V_00546FE0 *)&o->q3B0;

            v->x = src->x;
            v->y = src->y;
            v->z = src->z;
            v->w = 0.0f;
            o->q380 = o->q3B0;
        }
        if (a0->b20 == 2) {
            a0->b20 = 3;
            func_003C2F58(a0, 0, &m->v10);
            func_L39_00548130(a0, &m->v10);
            m->q30 = o->q3B0;
            func_L01_00404A10(func_L39_00548648, a0);
            func_L39_005F33E0(0, 0, a0);
            if (m->w48 != 0) {
                if (net_00546FE0(o)) {
                    (&D_L39_0024DE80[o->b24C9])->f20 = 0.12f;
                    (&D_L39_0024DE80[o->b24C9])->w28 = 0x19;
                    (&D_L39_0024DE80[o->b24C9])->w2C = 0;
                }
                if (net_00546FE0(o)) {
                    (&D_L39_0024DE80[o->b24C9])->f20 = 0.12f;
                    (&D_L39_0024DE80[o->b24C9])->w28 = 0x19;
                    (&D_L39_0024DE80[o->b24C9])->w2C = 0;
                }
            } else {
                if (net_00546FE0(o)) {
                    (&D_L39_0024DE80[o->b24C9])->f20 = 0.06f;
                    (&D_L39_0024DE80[o->b24C9])->w28 = 0x19;
                    (&D_L39_0024DE80[o->b24C9])->w2C = 0;
                }
                if (net_00546FE0(o)) {
                    (&D_L39_0024DE80[o->b24C9])->f20 = 0.06f;
                    (&D_L39_0024DE80[o->b24C9])->w28 = 0x19;
                    (&D_L39_0024DE80[o->b24C9])->w2C = 0;
                }
            }
        } else {
            V_00546FE0 pos __attribute__((aligned(16)));
            L_00546FE0 l;
            V_00546FE0 off __attribute__((aligned(16)));
            V_00546FE0 mtx[6];
            V_00546FE0 m100[3];
            V_00546FE0 m130[4];
            V_00546FE0 base __attribute__((aligned(16)));
            V_00546FE0 fwd __attribute__((aligned(16)));
            R_00546FE0 *hits[20];
            s32 saved[20];
            V_00546FE0 quat __attribute__((aligned(16)));
            V_00546FE0 dir __attribute__((aligned(16)));
            V_00546FE0 from __attribute__((aligned(16)));
            V_00546FE0 to __attribute__((aligned(16)));
            s32 n;
            s32 i;
            s32 count;
            f32 ang;
            f32 roll;
            f32 range;

            a0->b20 = 6;
            m->h4 = 0x17;
            l.a = a0;
            l.w74 = 0x10001;
            l.w80 = 1;
            l.b78 = 3;
            l.b79 = 2;
            l.h7A = a0->hAA;
            l.f7C = ent_00546FE0(o, 2)->f30 * 2.0f;
            l.w88 = 0;
            func_0038CE20(&pos, &a0->vD0, -1.35f);
            vec_add_ba(&pos, &pos, &a0->v10);
            func_0038CE20(&off, &a0->vC0, 0.275f);
            vec_add_ab(&pos, &pos, &off);
            n = query_00546FE0(&pos, 1, o->p2524, 0, 1.5f, o->w2544);
            {
                s32 k;

                for (k = 0; k < n; k++) {
                    if (D_L39_002637C0[k] != (s32)o->p2524) {
                        func_0038CE20(&l.v, &a0->vD0, -1.5f);
                        l.v.w = 5627.925f;
                        func_L01_00446978((void *)D_L39_002637C0[k], &l);
                    }
                }
            }
            func_0038D328(m130, &D_L39_0024AF90);
            func_0038D590(m100, m130);
            func_003C2F58(a0, 0, &base);
            if (func_L39_00639D90(o) != 0 && !aim_00546FE0(o)) {
                q_00546FE0 *cam = &o->q380;

                *(q_00546FE0 *)&mtx[0] = o->q380;
                *(q_00546FE0 *)&mtx[1] = o->q390;
                func_0038CF68(&mtx[2], &o->v3A0, -0.1f);
                func_0038D5F0(&mtx[3], cam, m100);
            } else if (o->b1A08 == 1) {
                func_0038CE20(&mtx[0], &a0->vD0, -1.0f);
                func_0038CE20(&mtx[1], &a0->vC0, -1.0f);
                func_0038CE20(&mtx[2], &a0->vE0, 0.1f);
                func_0038D5F0(&mtx[3], &a0->vC0, m100);
            } else {
                q_00546FE0 *cam = &o->q380;

                *(q_00546FE0 *)&mtx[0] = o->q380;
                *(q_00546FE0 *)&mtx[1] = o->q390;
                func_0038CE20(&mtx[2], &o->v3A0, -0.1f);
                func_0038D5F0(&mtx[3], cam, m100);
            }
            count = 0;
            m->q30 = *(q_00546FE0 *)&mtx[0];
            range = 1.0471976f;
            roll = 0.0f;
            {
                s32 j;

                for (j = 0; j < 20; j++) {
                    hits[j] = 0;
                    saved[j] = 0;
                }
            }
            for (i = 0; i < 20; i++) {
                R_00546FE0 *r;

                ang = 0.32724923f;
                ang = (f32)i * ang / 20.0f;
                func_003C4840((f32 *)&quat, &mtx[1], ang);
                func_0038D850(&dir, &mtx[0], &quat);
                func_0038D850(&fwd, &mtx[2], &quat);
                roll = func_0038DAB8(func_L39_005B4410(range * 0.5f, range * 1.5f), roll);
                func_003C4840((f32 *)&quat, &mtx[0], roll);
                func_0038D850(&dir, &dir, &quat);
                func_0038D850(&fwd, &fwd, &quat);
                func_0038CE20(&dir, &dir, 32.0f);
                vec_add_ab(&from, &base, &fwd);
                vec_add_ab(&to, &from, &dir);
                r = func_L39_00547E10_00546FE0(a0, &from, &to, &l, ang);
                if (r != 0) {
                    saved[count] = r->w98;
                    hits[count] = r;
                    count++;
                    r->w98 = 0;
                }
            }
            {
                s32 j;

                for (j = 0; j < count; j++) {
                    hits[j]->w98 = saved[j];
                }
            }
            m->f0 = 1.0f / ent_00546FE0(o, 2)->f28;
        }
    }
}
/* localdecomp:end func_L39_00546FE0 */

/* localdecomp:start func_L39_00547E10 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x2524];
    void *f2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 f2544;
    s32 f2548;
} P_00547E10;

typedef struct {
    u8 pad0[0x50];
    P_00547E10 *f50;
} Q_00547E10;

typedef struct {
    u8 pad0[0x68];
    Q_00547E10 *f68;
} O_00547E10;

typedef struct {
    vu0_v4 v;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} R_00547E10;

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x30 - 0x22];
    f32 f30;
    u8 pad34[0x80 - 0x34];
} E_00547E10;

typedef struct {
    u8 pad0[0x98];
    s32 f98;
} M_00547E10;

typedef struct {
    u8 pad0[0x18];
    M_00547E10 *x18;
    s32 x1C;
    vu0_v4 x20;
} G_00547E10;

extern P_00547E10 *D_L39_0024CE20_00547E10[];
extern G_00547E10 D_L39_0025F740_00547E10;
extern E_00547E10 D_L39_0049C890_00547E10[];
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00446978_00547E10(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_005FFDF8_00547E10(s32);
extern void func_L39_005FFE78_00547E10(void);
extern s32 func_L39_00648AE0_00547E10(u8 *, s32);
extern void *func_L39_0054D5F8_00547E10(vu0_v4 *, vu0_v4 *, vu0_v4 *, s32, s32, u8 *);

M_00547E10 *func_L39_00547E10(O_00547E10 *a0, vu0_v4 *a1, vu0_v4 *a2, R_00547E10 *a3, f32 ang) {
    vu0_v4 d;
    f32 s10;
    f32 s14;
    P_00547E10 *p;
    P_00547E10 *q;
    void *t;
    s32 id;
    s32 hit;
    E_00547E10 *e;
    f32 speed;
    f32 dist;
    f32 k;
    f32 a;
    M_00547E10 *r;
    f32 lim;

    p = a0->f68->f50;
    if (p == 0) {
        return 0;
    }
    vec_sub_ab(a3, a2, a1);
    func_0038CF68(a3, a3, 1.5f);
    a3->v.w = 5627.9248f;
    id = p->f2544;
    t = p->f2524;
    q = D_L39_0024CE20_00547E10[id];
    id = -1;
    if (q != 0) {
        id = q->f2548;
    }
    func_L39_005FFDF8_00547E10(id);
    hit = func_003D3CB0(a1, a2, 0x10, t, 0);
    func_L39_005FFE78_00547E10();
    if (hit != 0) {
        vec_sub_ab(&d, a2, a1);
        func_0038CF68(&d, &d, 1.0f);
        vec_sub_ab(&d, &D_L39_0025F740_00547E10.x20, a1);
        func_L39_0054D5F8_00547E10(a1, &d, &D_L39_0025F740_00547E10.x20, 1, (s32)a0, (u8 *)p);
        if (D_L39_0025F740_00547E10.x18 != 0 && D_L39_0025F740_00547E10.x18->f98 != 0) {
            {
                s32 i = 2;

                if (func_L39_00648AE0_00547E10((u8 *)p, i)) {
                    e = &D_L39_0049C890_00547E10[D_L39_0049C890_00547E10[i].b21];
                } else {
                    e = &D_L39_0049C890_00547E10[i];
                }
            }
            speed = e->f30;
            dist = func_0038CF00(&D_L39_0025F740_00547E10.x20, a1);
            a = ang - 0.0872664601f;
            if (a < 0.0f) {
                a = 0.0f;
            }
            k = a / 0.239982769f * 0.5f;
            k = 1.0f - k;
            lim = 33.0f;
            func_L39_00546F30_00547E10((s32)D_L39_0025F740_00547E10.x18, &s10, &s14);
            if (s14 < 10.0f) {
                lim = 11.5f;
            }
            if (dist < s10) {
                a3->f1C = (speed + speed) * k;
            } else if (dist < s14) {
                a3->f1C = speed * k;
            } else if (dist < lim) {
                a3->f1C = speed * 0.6f;
            } else {
                a3->f1C = speed * 0.3f;
            }
            func_L01_00446978_00547E10(D_L39_0025F740_00547E10.x18, a3);
        }
        r = D_L39_0025F740_00547E10.x18;
    } else {
        vec_sub_ab(&d, a2, a1);
        func_L39_0054D5F8_00547E10(a1, &d, a2, 0, (s32)a0, (u8 *)p);
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_00547E10 */
