#include "common.h"

/* localdecomp:start func_L39_0054A250 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    s32 a[5];
} V20_0054A250;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x42 - 0x21];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    void *p68;
} O_0054A250;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
} P_0054A250;
typedef struct {
    u8 pad0[0x10];
    void *(*fn10)(void *);
} Vt_0054A250;
typedef struct {
    u8 pad0[0x14];
    Vt_0054A250 *vt;
} R_0054A250;
typedef struct {
    u8 pad0[0x1A4];
    s32 w1A4;
} Q_0054A250;
typedef struct {
    u8 pad0[0x2D8];
    s16 h2D8;
    u8 pad2DA[0x30C - 0x2DA];
    s32 w30C;
    u8 pad310[0x3B0 - 0x310];
    f32 v3B0[4];
    u8 pad3C0[0x3E0 - 0x3C0];
    P_0054A250 *p3E0;
    u8 pad3E4[0x460 - 0x3E4];
    s32 w460;
    u8 pad464[0x1310 - 0x464];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 pad1A08[0x1A14 - 0x1A08];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 b1A40[1];
    u8 pad1A41[0x24FE - 0x1A41];
    u8 b24FE;
    u8 pad24FF;
    u8 b2500;
    u8 pad2501[0x2524 - 0x2501];
    s32 w2524;
    u8 pad2528[0x2534 - 0x2528];
    Q_0054A250 *p2534;
    u8 pad2538[0x2544 - 0x2538];
    s32 w2544;
} E_0054A250;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s32 w34;
    u8 pad38[0x3C - 0x38];
    s32 w3C;
    E_0054A250 *p40;
    void *p44;
} M_0054A250;
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
typedef struct {
    u8 pad0[0x26];
    u8 b86;
    u8 pad27[0x2C - 0x27];
    u32 w8C;
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x50 - 0x48];
} W_0054A250;
typedef struct {
    u8 pad0[0x10];
    u128_t q10;
} Z_0054A250;
typedef struct {
    u8 pad0[0x10];
    u128_t q10;
    u8 pad20[0x100 - 0x20];
    u8 big[16];
} S_0054A250;
typedef struct {
    f32 pos[3];
    s32 w;
    s32 x;
} L_0054A250;

extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern f32 *func_00382348(void *);
extern s32 func_L39_00647430(void *);
extern void *func_L39_005BAFA8(void *, void *, void *, s32, s32, f32, f32, f32, f32, f32, s32, s32, void *, s32, s32, s32);
extern void func_L39_005FE6A0(f32, f32, f32, f32, void *, void *, void *, void *, s32);
extern s32 func_L39_005FED60(void *, void *, void *, void *, void *, void *, s32, s32, s32, s32, f32);
extern void func_L39_0061C4D0(void *, void *);
extern void func_L39_00622288(void *);
extern s32 func_L39_006732D0(void *, s32, s32, void *);
extern R_0054A250 *func_L39_0061D1D8(s32);
extern void func_L39_00621D60(void *, s32);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L39_0054CF30(void *, void *, void *, s32, s32, void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L01_003F2278(s32, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L39_0054A8E0(u8 *);

extern f32 D_L39_0024B010;
__asm__(".extern D_L39_0024B010, 4");
extern f32 D_L39_0024B014;
__asm__(".extern D_L39_0024B014, 4");
extern f32 D_L39_0024B018;
__asm__(".extern D_L39_0024B018, 4");
extern f32 D_L39_0024B01C;
__asm__(".extern D_L39_0024B01C, 4");
typedef union {
    u8 b[16];
    u32 w[4];
    f32 f[4];
} Buf_0054A250;

extern u8 D_L39_004997E0[];

static inline u32 Dec_0054A250(u8 *q, Buf_0054A250 *bp) {
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = bp->b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = bp->w[0] ^ (u32)q;
    b = bp->w[1] ^ a;
    bp->w[0] = a;
    bp->w[1] = b;
    return b;
}

static inline s32 DecEq_0054A250(u8 *q, s32 v, Buf_0054A250 *bp) {
    return Dec_0054A250(q, bp) == v;
}

static inline s32 Busy_0054A250(E_0054A250 *s, Buf_0054A250 *bp) {
    return DecEq_0054A250(&s->b19E4, 1, bp) || DecEq_0054A250(&s->b19E4, 0x1D, bp) ||
           s->b24FE != 0 || s->b2500 != 0;
}
extern V20_0054A250 D_L39_0024B020;
extern s32 D_L39_0024D528[8] __attribute__((section(".sdata")));
extern u8 D_L39_00470580[];
extern T_0054A250 D_L39_0049C890[];

void func_L39_0054A250(O_0054A250 *obj) {
    M_0054A250 *m = obj->p68;
    E_0054A250 *e = m->p40;
    f32 vec[4];
    Buf_0054A250 v30;
    L_0054A250 loc;
    W_0054A250 w;
    S_0054A250 sx;
    u8 flag;
    s32 r;

    if (e != 0) {
        if (e->b1A14 != 0) {
            func_003C2F58(obj, 0, vec);
        }
    }
    if (obj->b42 == obj->b43 && (obj->b60 & 2)) {
        func_L01_00444F38(obj, 1, 0, 2, 0);
    }
    m->p44 = 0;
    if (e != 0) {
        P_0054A250 *p = e->p3E0;
        if (p != 0 && p->b20 != 254 && p->b20 != 253) {
            f32 *q = func_00382348(p);
            if (q != 0 && 0.0f < *q) {
                m->p44 = e->p3E0;
            }
        }
        if (e->b1A14 != 0) {
            flag = Busy_0054A250(e, &v30);
            if (flag == 0 && e->w1310 == 0 && m->p44 == 0) {
                *(V20_0054A250 *)&loc = D_L39_0024B020;

                r = func_L39_00647430(e);
                m->p44 = func_L39_005BAFA8(vec, &e->v3B0, sx.big, 0, 0, 0.3926991f, 0.7853982f, 11.1f, 0.0f, 0.0f, r, 0, &loc, 1, e->h2D8, 0);
            }
        }
    }
    if (e != 0) {
        if (e->b1A14 != 0) {
            func_L39_005FE6A0(D_L39_0024B014, D_L39_0024B010, D_L39_0024B01C * 0.020000001f, D_L39_0024B018 * 0.00040000002f, e, (u8 *)m + 0x20, vec, m->p44, 0);
            m->w34 = func_L39_005FED60(e, vec, (u8 *)m + 0x20, m, (u8 *)m + 0x10, obj, 1, 0, 0, 0,
                                       D_L39_0024B018 * 0.00040000002f);
        }
    }
    switch (obj->b20) {
    case 0:
        func_L39_0061C4D0(obj, &m->p40);
        e = m->p40;
        obj->b20 = 1;
        m->w3C = -1;
    case 1:
        if (e == 0) {
            return;
        }
        if (e->w30C >= 18) {
            func_L39_00622288(e);
        }
        r = func_L39_006732D0(e->b1A40, 0, 1, &w);
        if (r == 8) {
            if (e->b1A14 == 0) {
                func_003C2F58(obj, 0, vec);
            }
            if (w.b86 & 0x80) {
                v30.f[0] = w.f9C;
                v30.f[1] = w.fA0;
                v30.f[2] = w.fA4;
                v30.f[3] = 0;
            } else {
                loc.pos[0] = w.f90;
                loc.pos[1] = w.f94;
                loc.pos[2] = w.f98;
                loc.w = 0;
                if (w.w8C != 0xFFFFFFFF) {
                    R_0054A250 *rr = func_L39_0061D1D8(w.w8C);
                    Z_0054A250 *zz = rr ? rr->vt->fn10(rr) : 0;
                    if (zz != 0) {
                        *(u128_t *)&loc = zz->q10;
                    }
                }
                sx.q10 = *(u128_t *)&loc;
                func_L39_005FE6A0(D_L39_0024B014, D_L39_0024B010, D_L39_0024B01C * 0.020000001f, D_L39_0024B018 * 0.00040000002f, e, &v30, vec, &sx, 0);
            }
            D_L39_0024D528[e->w2544] = 1;
            func_L39_00621D60(e, -1);
            m->w3C = func_L01_003F2058(D_L39_00470580, e->p2534);
            func_L01_00444F38(obj, 2, 0, 2, 0);
            func_L39_0054CF30(obj, vec, &v30, 0, e->w2524, e);
            func_L39_005F33E0(0, 0, obj);
            {
                T_0054A250 *t;
                if (func_L39_00648AE0(e, 5)) {
                    u8 *d = (u8 *)D_L39_0049C890;
                    t = (T_0054A250 *)(d + (((s8 *)d)[0x2A1] << 7));
                } else {
                    u8 *d = (u8 *)D_L39_0049C890;
                    t = (T_0054A250 *)(d + 0x280);
                }
                m->f30 = 1.0f / t->f28;
            }
        } else if (r == 4) {
            if ((e->p2534->w1A4 & e->w460) != 0 || D_L39_0024D528[e->w2544] == 1) {
                func_L39_005F33E0(1, 0, obj);
                D_L39_0024D528[e->w2544] = 0;
            }
        }
        if (r != 8 || e->b1A07 == 0) {
            if (m->w3C >= 0) {
                func_L01_003F2278(m->w3C, e->p2534);
                m->w3C = -1;
            }
        }
        obj->b20 = 1;
        break;
    }
    if (e->b1A14 != 0) {
        func_L01_00404A10(func_L39_0054A8E0, obj);
    }
}
/* localdecomp:end func_L39_0054A250 */

/* localdecomp:start func_L39_0054A8E0 */
extern s32 D_L39_00241118;
extern void func_L39_005FE358(u8 *, u8 *, s32, s32, f32);

void func_L39_0054A8E0(u8 *m) {
    u8 *p;
    u8 *q;

    if (m == 0) {
        return;
    }
    if (m[32] == 254) {
        return;
    }
    if (m[32] == 253) {
        return;
    }
    p = *(u8 **)(m + 104);
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 64);
    if (q == 0) {
        return;
    }
    if (q[9417] != D_L39_00241118) {
        return;
    }
    if (*(s32 *)(p + 52) == 0) {
        return;
    }
    func_L39_005FE358(p, p + 16, 0, 1, 1.0f);
}
/* localdecomp:end func_L39_0054A8E0 */

/* localdecomp:start func_L39_0054A960 */
typedef struct {
    float pos[3];
    char pad0C[52];
    struct { char pad[728]; short h; } *p64;
    int p68;
} Src0054A040;

typedef struct {
    char pad0[104];
    Src0054A040 *src;
} Obj0054A040;

typedef struct {
    char pad0[2];
    unsigned char flags;
    unsigned char type;
    char pad4[4];
    unsigned int w8;
    float a[3];
    float b[3];
} Msg0054A040;

extern int func_L39_0061D780(int);

void func_L39_0054A960(Obj0054A040 *obj, Msg0054A040 *msg)
{
    Src0054A040 *s;
    float *d;
    float *p;

    if (msg->type != 8)
        return;
    s = obj->src;
    d = msg->b;
    p = (float *)((char *)s + 32);
    d[0] = p[0];
    d[1] = p[1];
    d[2] = p[2];
    if (s->p68) {
        msg->w8 = func_L39_0061D780(s->p68);
    } else {
        if (s->p64 && s->p64->h) {
            msg->flags |= 0x80;
        }
        msg->w8 = 0xFFFFFFFF;
    }
    {
        float *dd = msg->a;
        float *pp = s->pos;
        dd[0] = pp[0];
        dd[1] = pp[1];
        dd[2] = pp[2];
    }
}
/* localdecomp:end func_L39_0054A960 */

/* localdecomp:start func_L39_0054AA20 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x128 - 0xC];
    s32 w128;
} S_1A5CD0_0054AA20;

extern S_1A5CD0_0054AA20 D_001A5CD0_0054AA20;
extern s32 D_L39_0024B038_0054AA20;
__asm__(".extern D_L39_0024B038_0054AA20, 4");
extern s32 D_L39_003BDD20[][24];

s32 func_L39_0054AA20(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 24; i++) {
        if (D_L39_003BDD20[D_001A5CD0_0054AA20.w8][i] == 0) {
            for (j = 0; j < 8; j++) {
                if ((&D_L39_0024B038_0054AA20)[j * 2] == i && D_001A5CD0_0054AA20.w128 - 2000 < (&D_L39_0024B038_0054AA20)[j * 2 + 1]) {
                    break;
                }
                if ((&D_L39_0024B038_0054AA20)[j * 2] == i) {
                    (&D_L39_0024B038_0054AA20)[j * 2] = -1;
                }
            }
            if (j < 8) {
                continue;
            }
            for (j = 0; j < 8; j++) {
                if ((&D_L39_0024B038_0054AA20)[j * 2] == -1) {
                    (&D_L39_0024B038_0054AA20)[j * 2] = i;
                    (&D_L39_0024B038_0054AA20)[j * 2 + 1] = D_001A5CD0_0054AA20.w128;
                    break;
                }
            }
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0054AA20 */

/* localdecomp:start func_L39_0054AB58 */
typedef struct {
    u8 pad0[0x128];
    s32 w128;
} S_1A5CD0_0054AB58;
typedef struct {
    s32 id;
    s32 t;
} E_0054AB58;

extern S_1A5CD0_0054AB58 D_001A5CD0;
extern E_0054AB58 D_L39_0024B038;
__asm__(".extern D_L39_0024B038, 8");
extern s32 D_L39_0024B03C[] __attribute__((section(".sdata")));

void func_L39_0054AB58(s32 a) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_L39_0024B038)[i].id == a) {
            if (D_001A5CD0.w128 - 2000 < D_L39_0024B03C[i * 2]) {
                (&D_L39_0024B038)[i].id = -1;
                return;
            }
        }
    }
}
/* localdecomp:end func_L39_0054AB58 */

/* localdecomp:start func_L39_0054ABC0 */
typedef struct {
    u8 pad0[0x64];
    s32 w64;
    s32 w68;
} S_0054ABC0;
typedef struct {
    u8 pad0[0x68];
    S_0054ABC0 *p68;
    u8 pad6C[0x94 - 0x6C];
    u8 b94;
} O_0054ABC0;

extern s32 D_L39_003BDD20[][24];

void func_L39_0054ABC0(O_0054ABC0 *o) {
    S_0054ABC0 *s = o->p68;

    if (s->w64 != -1) {
        o->b94 = s->w64;
        D_L39_003BDD20[s->w68][s->w64] = 0;
    }
}
/* localdecomp:end func_L39_0054ABC0 */

INCLUDE_ASM("asm/levels", func_L39_0054AC10);

INCLUDE_ASM("asm/levels", func_L39_0054B4B8);

/* localdecomp:start func_L39_0054C2B0 */
typedef int u128_0054C2B0 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x2544];
    s32 w2544;
} A_0054C2B0;
typedef struct {
    u8 pad0[0x2548];
    s32 w2548;
} B_0054C2B0;
typedef struct {
    u8 pad0[0x54];
    s32 w54;
    A_0054C2B0 *p58;
} S_0054C2B0;
typedef struct {
    u8 pad0[0x10];
    u128_0054C2B0 pos;
    u8 pad20[0x68 - 0x20];
    S_0054C2B0 *p68;
} O_0054C2B0;
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x34 - 0x22];
    f32 f34;
    u8 pad38[0x80 - 0x38];
} T_0054C2B0;

extern void func_0038CE20(u128_0054C2B0 *, u128_0054C2B0 *, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D4D00(void *, f32, s32, void *, s32);
extern void func_L01_00447718(void *, void *, void *, s32, void *, s32, s32, s32, s32, f32, f32, f32);
extern B_0054C2B0 *D_L39_0024CE20[2];
__asm__(".extern D_L39_0024CE20, 16");
extern u8 D_L39_002637C0[];

static inline T_0054C2B0 *TabGet_0054C2B0(void *s, s32 mode) {
    T_0054C2B0 *e;
    if (func_L39_00648AE0(s, mode)) {
        e = &((T_0054C2B0 *)D_L39_0049C890)[((T_0054C2B0 *)((u8 *)D_L39_0049C890 + (mode << 7)))->b21];
    } else {
        e = (T_0054C2B0 *)((u8 *)D_L39_0049C890 + (mode << 7));
    }
    return e;
}

/* from func_L01_00384E68 */
void func_L39_0054C2B0(O_0054C2B0 *m, u128_0054C2B0 *dir, void *hit, s32 a3) {
    u128_0054C2B0 back;
    u128_0054C2B0 centre;
    S_0054C2B0 *s = m->p68;
    u128_0054C2B0 *pos;
    B_0054C2B0 *b;
    f32 splash;
    s32 count;
    s32 a;
    s32 fl;
    u128_0054C2B0 *cp;

    func_0038CE20(&back, dir, -3.0f);
    splash = TabGet_0054C2B0(s->p58, 4)->f34;
    pos = &m->pos;
    a = s->p58->w2544;
    b = D_L39_0024CE20[a];
    a = -1;
    if (b != 0) {
        a = b->w2548;
    }
    func_L39_005FFDF8(a);
    count = func_003D4D00(pos, 4.0f, 0x10, m, 0);
    func_L39_005FFE78();
    cp = &centre;
    centre = m->pos;
    fl = a3 ? 0x1010000 : 0x1010001;
    func_L01_00447718(m, cp, D_L39_002637C0, count, hit, fl, 3, 1, -1, splash, (f32)s->w54, 1.0f);
}
/* localdecomp:end func_L39_0054C2B0 */
