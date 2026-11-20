#include "common.h"

/* localdecomp:start func_L39_00524E00 */
typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00524E00;
typedef struct {
    u8 pad0[0x1C];
    s32 (*fn)(void *, s32);
} VT_00524E00;
typedef struct {
    u8 p0[3];
    u8 b3;
    u8 p4[0x14 - 4];
    VT_00524E00 *vt;
    u8 p18[0x19E4 - 0x18];
    u8 b19E4;
    u8 p19E5;
    u8 b19E6;
    u8 p19E7[0x2530 - 0x19E7];
    u8 *p2530;
} G_00524E00;

extern u8 D_L39_004997E0[];
extern void *func_L39_0061D7B0(void *);
extern u8 *func_00382348(void *);

/* the 5-step byte decode of an obfuscated u32, as in matched func_L39_00560618 */
static __inline__ u32 dec5_00524E00(u8 *p) {
    Buf_00524E00 buf;
    u32 a;
    u32 b;
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
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

s32 func_L39_00524E00(void *self, s32 a1) {
    u8 *a0 = self;
    G_00524E00 *g;
    u8 *e;
    u8 *h;
    s16 s;
    u8 host;
    u8 st;

    if (a0 == 0 || a0[0x20] == 0xFE || a0[0x20] == 0xFD) return 0;
    e = *(u8 **)(a0 + 0x24);
    if (e == 0) return 0;
    if (e[0x46] != 5) return 0;
    g = func_L39_0061D7B0(a0);
    if (g != 0) {
        if (g->vt->fn(g, a1) != 0) return 0;
        st = g->b3;
        if ((st & 0xF) == 0) {
            if ((dec5_00524E00(&g->b19E6) ^ 0x14) == 0
                || (host = g->p2530 != 0 ? (g->p2530[0x27B] != 0 && (dec5_00524E00(&g->b19E4) ^ 0x31) == 0) : 0)) {
                return 0;
            }
        }
    } else if (*(u16 *)(a0 + 0x34) & 1) {
        return 0;
    }
    s = *(s16 *)(a0 + 0xAA);
    if (s == 0x10AA) return 0;
    if (s == 0x1080) return 0;
    h = func_00382348(a0);
    if (h == 0 || h[0xE] == 3) return 0;
    return 1;
}
/* localdecomp:end func_L39_00524E00 */

/* localdecomp:start func_L39_00525030 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00525030;
typedef struct R_00525030 { u8 pad0[0x10]; void *p10; } R_00525030;
typedef struct M_00525030 {
    u8 pad0[0x10];
    V_00525030 pos;
    u8 pad20[4];
    R_00525030 *p24;
    u8 pad28[0x70];
    void *p98;
    u8 pad9C[0xE];
    s16 hAA;
    u8 padAC[0x14];
    V_00525030 vC0;
    u8 padD0[0x10];
    V_00525030 vE0;
    u8 padF0[8];
    f32 fF8;
} M_00525030;
typedef struct G_00525030 {
    u8 pad0[0xA0];
    f32 fA0;
    f32 fA4;
    u8 padA8[0x2B4 - 0xA8];
    f32 f2B4;
    u8 pad2B8[0x2D8 - 0x2B8];
    s16 h2D8;
    u8 pad2DA[0x2524 - 0x2DA];
    M_00525030 *p2524;
    u8 pad2528[0x2548 - 0x2528];
    s32 i2548;
} G_00525030;
typedef struct T_00525030 { u8 pad0[0x10]; M_00525030 *target; u8 pad14[0x40]; G_00525030 *g; } T_00525030;
typedef struct S_00525030 { u8 pad0[0x68]; T_00525030 *t; } S_00525030;
typedef struct C_00525030 { u8 pad0[0x18]; M_00525030 *hit; u8 pad1C[4]; V_00525030 pos; } C_00525030;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_00524E00(void *, s32);
extern u8 *func_00382348(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_00382760(void *, f32, f32, f32);
extern M_00525030 *D_L39_00292C20[];
extern C_00525030 D_L39_0025F740;
extern V_00525030 D_L39_0025F760;
__asm__(".extern D_L39_002429BC, 16");
extern s32 D_L39_002429BC;
extern s32 D_001D72B0_sda;
M_00525030 *func_L39_00525030(S_00525030 *self, V_00525030 *src, f32 *yawOut, f32 *pitchOut) {
    V_00525030 pos;
    V_00525030 *pp;
    V_00525030 tmp;
    V_00525030 end;
    M_00525030 *list[128];
    V_00525030 mpos;
    V_00525030 off;
    V_00525030 v250;
    V_00525030 v260;
    T_00525030 *t;
    G_00525030 *g;
    M_00525030 *result;
    M_00525030 *m;
    M_00525030 *hit;
    u8 *r;
    s32 idx;
    s32 n;
    s32 i;
    s32 j;
    s32 found;
    f32 best;
    f32 yaw, pitch, dyaw, dist, d, a, l, ang, rad, sub;

    best = 12.0f;
    pp = &pos;
    *pp = *src;
    t = self->t;
    g = t->g;
    result = 0;
    func_0038CE20(&tmp, &g->p2524->vE0, 0.5f);
    vec_add_ba(&end, &g->p2524->pos, &tmp);
    if (func_003D3CB0(&end, pp, 6, g->p2524, 0) != 0) {
        *(vu0_q *)pp = *(vu0_q *)&D_L39_0025F760;
        return 0;
    }
    n = 0;
    for (idx = 0; (m = D_L39_00292C20[idx]) != 0; idx++) {
        if (m == g->p2524) continue;
        if (func_L39_00524E00(m, g->i2548) == 0) continue;
        mpos = m->pos;
        r = func_00382348(m);
        if (r == 0) continue;
        func_0038CE20(&off, &m->vE0, *(f32 *)(r + 0x10));
        found = 0;
        vec_add_ab(&mpos, &mpos, &off);
        yaw = func_0038D160(mpos.x - pp->x, mpos.y - pp->y);
        d = func_0038CF38(pp, &mpos);
        pitch = func_0038D160(d, mpos.z - pp->z);
        dyaw = func_0038DBA0(*yawOut, yaw);
        dist = func_0038CF00(pp, &mpos);
        if (D_L39_002429BC != 0 || g->h2D8 != 0 || D_001D72B0_sda != 0) {
            if (dist < 2.5f) {
                vec_sub_ab(&v250, &m->pos, &g->p2524->pos);
                d = func_0038CE68(&v250, &g->p2524->vE0);
                if (fabs_asm(d) < 2.0f) {
                    func_0038CE20(&v260, &g->p2524->vE0, d);
                    vec_sub_ab(&v250, &v250, &v260);
                    a = func_0038CE68(&v250, &g->p2524->vC0);
                    l = func_0038CEA8(&v250);
                    if (l != 0.0f) {
                        if (1.5707964f - func_0038D0C8(a / l) < 1.0471976f) {
                            found = 1;
                        }
                    }
                }
            }
        } else {
            if (dist < 2.5f) {
                M_00525030 *p = g->p2524;
                if (func_0038DBA0(p->fF8, func_0038D160(m->pos.x - g->fA0, m->pos.y - g->fA4)) < 1.0471976f) {
                    if (fabs_asm(pp->z - mpos.z) < 2.0f) {
                        found = 1;
                    }
                }
            }
        }
        if (found) {
            if (func_003D3CB0(pp, &mpos, 6, g->p2524, 0) == 0) {
                *pitchOut = -pitch;
                result = m;
                *yawOut = yaw;
                break;
            }
        }
        if (best < dist && m != t->target) continue;
        if (12.0f < dist) continue;
        func_00382760(&off, dist, *yawOut, *pitchOut + g->f2B4 * 0.5f);
        vec_add_ab(&off, &off, pp);
        ang = func_0038D0C8(func_0038CF00(&off, &mpos) / (dist + dist)) * 2.0f;
        if (0.2617994f < ang) {
            r = func_00382348(m);
            if (r != 0) {
                rad = r[0xA] * 0.125f;
                sub = func_0038D0C8(rad / dist);
                if (rad < dist) {
                    ang -= sub;
                    if (ang < 0.0f) ang = 0.0f;
                }
            }
        }
        if (!(ang < 0.2617994f)) continue;
        found = 1;
        v250 = *pp;
        for (i = 0; func_003D3CB0(&v250, &mpos, 6, self, 0) != 0 && ++i < 7; ) {
            hit = D_L39_0025F740.hit;
            if (hit != 0) {
                if (hit->hAA == 0x10AA || hit->hAA == 0x1080) {
                    list[n] = hit;
                    n++;
                    hit->p98 = 0;
                    if (n >= 0x80) break;
                    v250 = D_L39_0025F740.pos;
                    continue;
                }
                if (hit == m) break;
            }
            found = 0;
            break;
        }
        if (found) {
            *pitchOut = -pitch;
            best = dist;
            if (dyaw < 0.17453292f) *yawOut = yaw;
            result = m;
            if (m == t->target) return result;
        }
    }
    for (j = 0; j < n; j++) {
        list[j]->p98 = list[j]->p24->p10;
    }
    return result;
}
/* localdecomp:end func_L39_00525030 */

/* localdecomp:start func_L39_00525690 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00525690;
typedef union { u8 b[16]; u32 w[4]; u16 h[8]; } Buf_00525690;
typedef struct { V_00525690 r[4]; } M_00525690;
typedef struct { u8 pad0[0x2F8]; u32 w2F8; } P2528_00525690;
typedef struct { u8 pad0[0x27B]; u8 b27B; } P2530_00525690;
typedef struct G_00525690 G_00525690;
typedef struct { u8 pad0[0x34]; void (*f34)(G_00525690 *, s32, s32, s32, s32); } VT_00525690;
struct G_00525690 {
    u8 pad0[0x14];
    VT_00525690 *vt;
    u8 pad18[0x380 - 0x18];
    u8 m380[0x1078 - 0x380];
    void *p1078;
    u8 pad107C[0x122C - 0x107C];
    u8 *p122C;
    u8 pad1230[0x1250 - 0x1230];
    f32 f1250;
    u8 pad1254[0x1310 - 0x1254];
    s32 w1310;
    u8 pad1314[0x1338 - 0x1314];
    u8 m1338[4];
    u8 m133C[0x19E4 - 0x133C];
    u8 b19E4;
    u8 pad19E5[0x1A07 - 0x19E5];
    u8 b1A07;
    u8 b1A08;
    u8 pad1A09[0x1A14 - 0x1A09];
    u8 b1A14;
    u8 pad1A15[0x1A40 - 0x1A15];
    u8 m1A40;
    u8 b1A41;
    u8 pad1A42[0x23C0 - 0x1A42];
    u8 m23C0[0x2460 - 0x23C0];
    G_00525690 *p2460;
    u8 b2464;
    u8 pad2465[0x24C9 - 0x2465];
    u8 b24C9;
    u8 pad24CA[0x2524 - 0x24CA];
    void *p2524;
    P2528_00525690 *p2528;
    u8 pad252C[0x2530 - 0x252C];
    P2530_00525690 *p2530;
    u8 pad2534[0x2544 - 0x2534];
    s32 w2544;
    s32 w2548;
    void *p254C;
};
typedef struct {
    V_00525690 pos;
    u8 *p10;
    f32 f14;
    f32 f18;
    s16 h1C;
    s16 h1E;
    u8 pad20[0x38 - 0x20];
    f32 f38;
    u8 pad3C[0x44 - 0x3C];
    s32 w44;
    f32 f48;
    f32 f4C;
    s32 w50;
    G_00525690 *g;
    u8 b58;
    s8 b59;
    u8 b5A;
    u8 pad5B;
    s32 w5C;
} V68_00525690;
typedef struct {
    u8 pad0[0x10];
    V_00525690 pos;
    u8 b20;
    u8 pad21[0x43 - 0x21];
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    V68_00525690 *v;
    u8 pad6C[0xC0 - 0x6C];
    V_00525690 mC0;
    V_00525690 mD0;
} O_00525690;
typedef struct { f32 f0; s16 h4; u8 pad6[0xE - 6]; u8 bE; u8 padF[0x17 - 0xF]; u8 b17; } I_00525690;
typedef struct { u8 pad0[0x21]; s8 b21; u8 pad22[0x30 - 0x22]; f32 f30; u8 pad34[0x80 - 0x34]; } E_00525690;
typedef struct { u8 pad0[0xD0]; u8 bD0; u8 padD1[0xDC - 0xD1]; void *pDC; u8 padE0[0x80 - 0xE0 + 0x80]; } S_00525690;

extern s32 D_L39_0024112C;
__asm__(".extern D_L39_0024AA00, 4");
extern s32 D_L39_0024AA00;
__asm__(".extern D_L39_0024AA04, 4");
extern void *D_L39_0024AA04;
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern G_00525690 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern void *D_L39_002637C0[];
extern E_00525690 D_L39_0049C890[];
extern u8 D_001FE020[];
extern f32 D_L39_0024AA28;
extern f32 D_L39_0024AA2C;
extern s32 D_L39_0024AA20;
extern s32 D_L39_0024AA24;

extern void func_L39_0061C4D0(void *, void *);
extern void func_L39_005DB0E0(s32, f32, s32);
extern s32 func_L39_00639D90(void *);
extern s32 func_L39_00524E00(void *, s32);
extern s32 func_L39_005FFD20(f32, f32 *, s32 *, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_0038CB00(void *);
extern s32 func_L39_006732D0(void *, s32, s32, s32);
extern s32 func_L39_00673498(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L39_00621D60(void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L39_00674320(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D4D00(void *, f32, s32, void *, s32);
extern void func_L39_005FFE78(void);
extern s32 func_0038CAD0(void *);
extern u8 *func_00382348(void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_00451D38(void *, s32, s32, f32);
extern void func_L39_005DB148(s32, f32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_00557600(void *, void *);
extern u8 *func_L39_005285A8(u8 *, s32);
extern void func_L39_00526340(void *);
extern s32 func_L39_005F2FA0(void *, s32);
extern void func_L39_005F3088(s32);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_L39_00622288(void *);

static __inline__ u32 dec_00525690(u8 *q) {
    Buf_00525690 buf;
    s32 n, k, m, i;
    u8 *d;
    u32 a, b;

    if (*q == 0) return 0;
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}


static __inline__ E_00525690 *ent_00525690(G_00525690 *g, s32 id) {
    return func_L39_00648AE0((u8 *)g, id) ? &D_L39_0049C890[D_L39_0049C890[id].b21] : &D_L39_0049C890[id];
}

static __inline__ G_00525690 *pl_00525690(void *m) {
    u8 *x = (u8 *)func_L39_0061D7B0(m);
    if (x != 0 && (x[3] & 0xF) == 0) return (G_00525690 *)x;
    return 0;
}

void func_L39_00525690(O_00525690 *o) {
    V68_00525690 *v = o->v;
    G_00525690 *g = v->g;
    void *target = 0;
    I_00525690 *info = 0;
    G_00525690 *h1;
    s32 one;
    G_00525690 *h2;
    G_00525690 *h3;

    D_L39_0024AA00 = D_L39_0024112C;
    D_L39_0024AA04 = o;
    if (o->b20 == 0) {
        v->f38 = 1.0f;
        func_L39_0061C4D0(o, &v->g);
        g = v->g;
        o->b20 = 1;
        v->b59 = -1;
        v->w5C = -1;
        v->b5A = 0;
        if (v->g->b1A14) func_L39_005DB0E0(0, 0.0f, v->g->b24C9);
    }
    if (func_L39_00639D90(g)) {
        u8 hit;
        s32 r = func_L39_005FFD20(150.0f, (f32 *)g->m1338, (s32 *)g->m133C, hit = g->f1250 >= 0.7f && func_L39_00524E00(g->p122C, g->w2548));
        if (g->b1A14) {
            func_L01_003F6F20(g->b24C9, o, r, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    func_0038CB00(&v->h1C);
    one = 1;
    func_L39_006732D0(&g->m1A40, 0, one, 0);
    if ((u8)func_L39_00673498(&g->m1A40, 0)) {
        if (o->b43 != 2) func_003C3A10(o, 2, 0, 0);
        if (g->b1A07 == 0) func_L39_00621D60(g, -1);
        if (v->h1E == 0) v->h1E = one;
        if (v->h1C == 0) v->h1C = 12;
        func_003C2F58(o, 0, v);
        if ((dec_00525690(&g->b19E4) ^ 1) == 0) g->vt->f34(g, 0x1D, 1, 0, 1);
        {
        V_00525690 dir;
        *(vu0_q *)&dir = 0;
        {
            if ((dec_00525690(&g->b19E4) ^ 0x1D) == 0) {
                M_00525690 m;
                func_0038D5B0(&m, g->m23C0);
                dir.z = 1.0f;
                func_0038D028(&dir, &dir, &m);
            } else if (g->b1A08 == 1) {
                func_0038CE20(&dir, &o->mD0, -1.0f);
            } else {
                dir.x = 1.0f;
                func_0038D000(&dir, &dir, g->m380);
            }
        }
        v->f48 = func_0038D160(dir.x, dir.y);
        v->f4C = func_0038D160(func_0038CED8(&dir), dir.z);
        if (g->b1A14 == 0) {
            func_L39_00674320(g);
            if (g->p1078 != 0 && func_L39_00524E00(g->p1078, g->w2548)) target = g->p1078;
        }
        {
        if (v->g->w1310 != 0 && v->g->b1A14 != 0) {
            if (v->g->p122C != 0) {
                if (g->f1250 > 0.7f && func_0038CF00(v, v->g->p122C + 0x10) < 12.0f) {
                    if (func_L39_00524E00(g->p122C, g->w2548)) target = v->g->p122C;
                } else if (func_L01_0040E548(v, v->g->p122C + 0x10) < 6.25f) {
                    V_00525690 a;
                    V_00525690 b;
                    void *p;
                    G_00525690 *e;
                    s32 id;
                    s32 n, i;
                    void **pp;

                    func_0038CE20(&a, &o->mD0, -1.35f);
                    vec_add_ba(&a, &a, &o->pos);
                    func_0038CE20(&b, &o->mC0, -0.275f);
                    vec_add_ab(&a, &a, &b);
                    p = g->p2524;
                    id = g->w2544;
                    e = D_L39_0024CE20[id];
                    id = e != 0 ? e->w2548 : -1;
                    func_L39_005FFDF8(id);
                    n = func_003D4D00(&a, 1.5f, 1, p, 0);
                    func_L39_005FFE78();
                    pp = D_L39_002637C0;
                    for (i = 0; i < n; i++) {
                        if (*pp != g->p2524 && func_L39_00524E00(*pp, g->w2548)) {
                            target = *pp;
                            break;
                        }
                        pp++;
                    }
                }
            }
        } else if (target == 0) {
            V_00525690 tmp = v->pos;
            target = func_L39_00525030((S_00525030 *)o, (V_00525030 *)&tmp, &v->f48, &v->f4C);
        }
        }
        func_0038CAD0(&v->w44);
        if (v->p10 != 0) {
            u8 host;
            h1 = pl_00525690(v->p10);
            if (v->p10 == 0 || v->p10[0x20] == 0xFE || v->p10[0x20] == 0xFD
                || (h1 != 0 && ((h1->p2528 != 0 && !(h1->p2528->w2F8 & 0x4000000))
                    || (host = h1->p2530 != 0 ? (h1->p2530->b27B != 0 && (dec_00525690(&h1->b19E4) ^ 0x31) == 0) : 0)))) {
                v->p10 = 0;
                v->w44 = 0;
            }
        }
        if (target != 0 || v->w44 != 0) {
            E_00525690 *e;
            if (target != 0) {
                info = (I_00525690 *)func_00382348(target);
                if (target != v->p10 && v->w44 == 0) {
                    v->p10 = target;
                    v->f14 = info->h4;
                    v->f18 = info->f0;
                    v->w44 = 0x13;
                    if (v->f14 <= 1.0f) v->f18 = 0.0f;
                }
                g->p1078 = target;
            }
            {
            f32 rate = 1.2f;
            e = ent_00525690(g, 9);
            v->f18 -= e->f30 * 0.020000001f * rate;
            }
            if (v->f18 < 0.0f) v->f18 = 0.0f;
            v->f38 = v->f18 / v->f14;
        } else {
            v->f38 = 1.0f;
        }
        {
            s32 r = func_L01_00451D38(&v->w50, D_L39_0024AA20, D_L39_0024AA24,
                                      func_003C4088(D_L39_0024AA28, D_L39_0024AA2C, v->f38) * 0.017453292f * 0.020000001f);
            if (g->b1A14) func_L39_005DB0E0(r, v->f38, g->b24C9);
        }
        h2 = pl_00525690(v->p10);
        if (h2 != 0 && h2->b1A14) func_L39_005DB148(h2->b24C9, v->f38);
        if (v->p10 != 0 && v->f18 <= 0.0f) {
            func_L39_005F33E0(3, 0, o);
            h3 = pl_00525690(v->p10);
            if (h3 != 0) {
                if (((h3->p2528 == 0 && h3->p254C == 0) || (h3->p2528 != 0 && (h3->p2528->w2F8 & 0x4000000))) && info != 0) {
                    u8 *q;
                    u16 bits;
                    info->b17 = 9;
                    q = &g->b1A41;
                    if (*q == 0) {
                        bits = 0;
                    } else {
                        Buf_00525690 buf;
                        s32 n, k, m, i;
                        u8 *d;
                        u32 a0, b0;
                        n = *q;
                        k = ((u32)q - n) & 7;
                        m = n + 1;
                        d = buf.b;
                        for (i = 0; i < 24; i += 3) {
                            *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
                        }
                        a0 = buf.w[0] ^ (u32)q;
                        b0 = buf.w[1] ^ a0;
                        buf.w[0] = a0;
                        buf.w[1] = (b0 >> 16) / (((b0 ^ (b0 >> 16)) << 16) + 1);
                        bits = buf.h[2];
                    }
                    h3->p2460 = g;
                    h3->b2464 = (bits >> 9) & 1;
                    if (info->bE == 1) {
                        if (func_L39_005B43C8(1, 2) == 1) info->bE = 4;
                        else info->bE = 2;
                    }
                }
            } else {
                s32 ok = 1;
                if (info != 0 && info->bE == 2) ok = 0;
                if (ok) {
                    if (func_L39_005B43C8(1, 2) == 1) func_L39_00557600(v->p10, g);
                    else func_L39_005285A8(v->p10, (s32)g);
                }
                v->p10 = 0;
            }
        }
        func_L39_00526340(o);
        if (func_L39_005F2FA0(o, v->w5C) == 0) v->w5C = func_L39_005F33E0(1, 4, o);
        }
    } else {
        v->b58 = one;
        v->p10 = 0;
        v->h1E = 0;
        v->w44 = 0;
        if (v->w5C >= 0) {
            s32 id = v->w5C;
            if (id != -1 && ((S_00525690 *)(D_001FE020 + (id << 7)))->pDC == o && ((S_00525690 *)(D_001FE020 + (id << 7)))->bD0 != 0) {
                func_L39_005F3088(id);
            }
            v->w5C = -1;
        }
        if (o->b60 & 2) func_L01_00444F38((u8 *)o, 1, 0, 1, 0);
        func_L39_00622288(g);
        if (g->b1A14) {
            f32 t = func_003C4088(D_L39_0024AA28, D_L39_0024AA2C, v->f38) * 0.017453292f * 0.020000001f;
            s32 r = func_L01_00451D38(&v->w50, D_L39_0024AA20, D_L39_0024AA24, t);
            func_L39_005DB0E0(r, 1.0f, g->b24C9);
        }
    }
}
/* localdecomp:end func_L39_00525690 */

/* localdecomp:start func_L39_00526280 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos[12];
} T_00526280;

extern T_00526280 D_L39_003B5140[];
extern void func_0038CE20(void *, void *, f32);

void func_L39_00526280(u8 *a0)
{
    vu0_v4 d;
    u8 *v;
    s32 id;
    s32 i;
    vu0_q q1, q2;

    v = *(u8 **)(a0 + 0x68);
    id = 0;
    if (*(u8 **)(v + 0x54) != 0) {
        id = *(s32 *)(*(u8 **)(v + 0x54) + 0x2544);
    }
    if (v[0x58] != 0) {
        v[0x58] = 0;
        *(f32 *)(v + 0x30) = 1.0f;
        func_0038CE20(&d, a0 + 0xC0, -*(f32 *)(v + 0x30));
        i = id;
        *(vu0_q *)&D_L39_003B5140[i].pos[0] = *(vu0_q *)v;
        for (i = 1; i < 12; i++) {
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(D_L39_003B5140[id].pos[i - 1]));
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q2) : "j"(q2), "j"(q1));
            __asm__("sqc2 %1, %0" : "=m"(D_L39_003B5140[id].pos[i]) : "j"(q2));
        }
        *(s32 *)(v + 0x3C) = 0;
        *(s32 *)(v + 0x20) = 0;
        *(s32 *)(v + 0x24) = 0;
        *(s32 *)(v + 0x34) = 0;
        *(s32 *)(v + 0x2C) = 0;
    }
}
/* localdecomp:end func_L39_00526280 */

/* localdecomp:start func_L39_00526340 */
#include "vu0.h"
typedef vu0_v4 V_00526340;
typedef struct G_00526340 {
    u8 pad0[0x250];
    V_00526340 v250;
    u8 pad260[0x2524 - 0x260];
    M_00525030 *p2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 i2544;
} G_00526340;
typedef struct T_00526340 {
    V_00526340 pos;
    M_00525030 *target;
    u8 pad14[0x30 - 0x14];
    f32 f30;
    f32 f34;
    u8 pad38[0x48 - 0x38];
    f32 f48;
    f32 f4C;
    u8 pad50[4];
    G_00526340 *g;
} T_00526340;
typedef struct S_00526340 {
    u8 pad0[0x10];
    V_00526340 pos;
    u8 pad20[0x68 - 0x20];
    T_00526340 *t;
    u8 pad6C[0xD0 - 0x6C];
    V_00526340 vD0;
} S_00526340;
typedef struct { s32 c[5]; } K_00526340;
extern f32 func_L01_0044AE78(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_L39_005FFB48(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L39_005BE900(void *, void *, f32);
extern void func_L39_00526FC0(u8 *);
extern void func_L01_00404A10(void *, void *);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern f32 func_L39_005B4468(f32, f32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_0046E5A8(void *, s32, f32, f32, s32, s32, s32, f32 *, s32);
extern V_00526340 D_L39_003B5740_00526340[][12];
extern V_00526340 D_L39_003B5D40_00526340[][12];
extern V_00526340 D_L39_003B6340[][12][20];
extern K_00526340 D_L39_0024AA08;
__asm__(".extern D_L39_00242930, 16");
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));
extern u8 *D_L39_0029699C __attribute__((section(".data")));
static __inline__ void qcopy_00526340(void *d, void *s) { *(vu0_q *)d = *(vu0_q *)s; }

/* from rac2-decomp's func_L00_003C6B98 */
void func_L39_00526340(void *obj) {
    S_00526340 *self = obj;
    V_00526340 v0;
    V_00526340 v10;
    V_00526340 v20;
    V_00526340 v30;
    V_00526340 v40;
    M_00525030 *list[128];
    V_00526340 v250;
    V_00526340 v260;
    V_00526340 v270;
    union {
        V_00526340 m[4];
        struct {
            K_00526340 cols;
            V_00526340 axis;
            V_00526340 perp;
        } tr;
    } u;
    s32 col = 0;
    s32 num = 0;
    f32 r1;
    f32 ang;
    T_00526340 *t;
    G_00526340 *g;
    M_00525030 *hit = 0;
    u8 *r = 0;
    u8 *p = 0;
    s32 idx;
    s32 n;
    s32 i;
    s32 j = 0;
    s32 k = 0;
    s32 l = 0;
    s32 cnt = 0;
    s32 s = 0;
    f32 dist;
    f32 d;
    f32 len;
    f32 frac;
    f32 scale;
    f32 w;
    f32 a;
    f32 range;
    f32 step;

    t = self->t;
    g = t->g;
    idx = 0;
    if (g != 0) {
        idx = g->i2544;
    }
    v20.x = 0.0f;
    v20.w = 1.0f;
    func_L39_00526280((u8 *)self);
    t->f34 = func_L01_0044AE78(t->f34 + 0.20071286f);
    func_0038CF68(&v0, &self->vD0, -t->f30);
    if (t->target != 0 && (r = func_00382348(t->target)) != 0) {
        func_0038CE20(&v40, &t->target->vE0, *(f32 *)(r + 0x10));
        vec_add_ab(&v30, &t->target->pos, &v40);
    } else {
        func_00382760(&v30, 12.0f, t->f48, t->f4C);
        vec_add_ab(&v30, &v30, &t->pos);
    }
    n = 0;
    dist = 12.0f;
    i = 0;
    if (t->target == 0) {
        qcopy_00526340(&v40, &t->pos);
        for (; func_003D3CB0(&v40, &v30, 0x14, g->p2524, 0) != 0 && ++i < 7; ) {
            hit = D_L39_0025F740.hit;
            if (hit != 0 && (hit->hAA == 0x10AA || hit->hAA == 0x1080)) {
                list[n] = hit;
                n++;
                hit->p98 = 0;
                if (n < 0x80) {
                    qcopy_00526340(&v40, &D_L39_0025F740.pos);
                    continue;
                }
            }
            vec_sub_ab(&v250, &t->pos, &D_L39_0025F760);
            d = func_0038CE68(&g->p2524->vE0, &v250);
            func_0038CE20(&v260, &g->p2524->vE0, d);
            vec_sub_ab(&v270, &v250, &v260);
            dist = func_0038CEA8(&v270);
            break;
        }
        for (l = 0; l < n; l++) {
            list[l]->p98 = list[l]->p24->p10;
        }
    } else {
        vec_sub_ba(&v40, &t->pos, &t->target->pos);
        d = func_0038CE68(&g->p2524->vE0, &v40);
        func_0038CE20(&v250, &g->p2524->vE0, d);
        vec_sub_ab(&v260, &v40, &v250);
        dist = func_0038CEA8(&v260);
    }
    t->f30 = dist * 0.08333f;
    qcopy_00526340(&D_L39_003B5140[idx].pos[0], &t->pos);
    qcopy_00526340(&D_L39_003B5740_00526340[idx][0], &t->pos);
    qcopy_00526340(&D_L39_003B5D40_00526340[idx][0], &t->pos);
    for (j = 1; j < 12; j++) {
        func_L39_005FFB48(&D_L39_003B5140[idx].pos[j], &D_L39_003B5140[idx].pos[j]);
        frac = (f32)j * 0.08333f;
        w = frac * (0.4f - 0.9f) + 0.9f;
        vec_sub_ab(&v10, &D_L39_003B5140[idx].pos[j], &D_L39_003B5140[idx].pos[j - 1]);
        if (j >= 7 && t->target != 0) {
            vec_sub_ab(&v40, &t->target->pos, &D_L39_003B5140[idx].pos[j]);
            func_0038CF68(&v40, &v40, t->f30);
            func_0038CDF8(&v0, &v0, &v40, 0.2f);
        }
        func_0038CDF8(&v40, &v10, &v0, w);
        len = func_0038CEA8(&v40);
        if (len == 0.0f) {
            qcopy_00526340(&D_L39_003B5140[idx].pos[j], &D_L39_003B5140[idx].pos[j - 1]);
        } else {
            func_0038CE20(&v40, &v40, t->f30 / len);
            vec_add_ba(&D_L39_003B5140[idx].pos[j], &D_L39_003B5140[idx].pos[j - 1], &v40);
        }
        vec_sub_ab(&v250, &D_L39_003B5140[idx].pos[j], &D_L39_003B5140[idx].pos[j - 1]);
        func_0038CE90(&v260, &v250, &g->v250);
        func_0038CF68(&v260, &v260, frac * 1.184f + 0.05f);
        for (k = 0; k < 20; k++) {
            func_0038D890(&v270, &v260, &v250, (f32)k * 0.31415921f);
            vec_add_ba(&D_L39_003B6340[idx][j][k], &v270, &D_L39_003B5140[idx].pos[j]);
        }
        qcopy_00526340(&u.m[3], &D_L39_003B5140[idx].pos[j]);
        func_0038CF68(&u.m[0], &v250, 1.0f);
        func_0038CF68(&u.m[1], &v260, 1.0f);
        func_0038CE90(&u.m[2], &u.m[1], &u.m[0]);
        scale = frac * 0.49f + 0.01f;
        ang = func_L01_0044AE78(t->f34 + (f32)j * 0.39968038f);
        v20.y = scale * func_0038D0B0(ang);
        v20.z = scale * func_0038D098(ang);
        func_0038D028(&D_L39_003B5740_00526340[idx][j], &v20, u.m);
        v20.z = -v20.z;
        func_0038D028(&D_L39_003B5D40_00526340[idx][j], &v20, u.m);
    }
    qcopy_00526340(&v40, &self->pos);
    v40.w = 32.0f;
    cnt = 2;
    if (func_L39_005BE900(&v40, &range, 64.0f) != -1) {
        if (!(range < 256.0f)) {
            if (range < 1024.0f) {
                cnt = 4;
            } else {
                cnt = 8;
            }
        }
    } else {
        cnt = 0x80;
    }
    if (cnt < 0x80) {
        func_L01_00404A10(func_L39_00526FC0, self);
    }
    a = func_L39_005B4410(0.1f, 1.7f);
    s = func_L39_005B4398(2);
    if (s == 0) {
        s--;
    }
    if (func_L39_005B4398(cnt) == 0) {
        qcopy_00526340(&v250, &D_L39_003B5740_00526340[idx][11]);
        p = func_L01_0046B458((u8 *)&v250, 0x19, a * 0.1f, a, 0x7F10107F, 0, s, D_L39_00242930, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_0029699C[7];
        }
        s = -s;
        p = func_L01_0046B458((u8 *)&v250, 0x19, a * 0.07f, a * 0.7f, 0x7F7F7F7F, 1, s, D_L39_00242930, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_0029699C[7];
        }
    }
    if (func_L39_005B4398(cnt) == 0) {
        qcopy_00526340(&v250, &D_L39_003B5D40_00526340[idx][11]);
        p = func_L01_0046B458((u8 *)&v250, 0x19, a * 0.1f, a, 0x7F104FFF, 0, s, D_L39_00242930, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_0029699C[7];
        }
        s = -s;
        p = func_L01_0046B458((u8 *)&v250, 0x19, a * 0.07f, a * 0.7f, 0x7F7F7F7F, 1, s, D_L39_00242930, 0.003f, 1);
        if (p != 0) {
            p[2] = D_L39_0029699C[7];
        }
    }
    vec_sub_ab(&v260, &D_L39_003B5140[idx].pos[1], &D_L39_003B5140[idx].pos[0]);
    step = 0.2f * 1.2f;
    func_0038CF68(&v260, &v260, step);
    if (func_L39_005B4398(cnt) == 0) {
        func_0038CF68(&v270, &self->vD0, -0.25f);
        vec_add_ba(&v250, &D_L39_003B5140[idx].pos[0], &v270);
        u.tr.cols = D_L39_0024AA08;
        col = u.tr.cols.c[func_L39_005B4398(5)];
        r1 = func_L39_005B4468(0.0f, 0.2617994f);
        func_0038D890(&u.tr.axis, &v260, &g->v250, func_L39_005B4468(0.0f, 0.2617994f));
        func_0038CE90(&u.tr.perp, &v260, &g->v250);
        func_0038D890(&u.tr.axis, &u.tr.axis, &u.tr.perp, r1);
        num = (s32)(dist * 1.2f / step);
        if (t->target != 0) {
            num *= 3;
        }
        p = func_L01_0046E5A8(&v250, num, a * 0.1f, a, col, 0, s, (f32 *)&u.tr.axis, (s32)t->target);
        if (p != 0) {
            p[2] = D_L39_0029699C[6];
        }
        p = func_L01_0046E5A8(&v250, num, a * 0.07f, a * 0.7f, 0x7F7F7F7F, 1, -s, (f32 *)&u.tr.axis, (s32)t->target);
        if (p != 0) {
            p[2] = D_L39_0029699C[6];
        }
    }
}
/* localdecomp:end func_L39_00526340 */

/* localdecomp:start func_L39_00526FC0 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    f32 uv[4][2];
    long a;
    long tex;
    long c;
    long d;
} S_00526FC0;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad2C[0x3C - 0x2C];
    f32 f3C;
    u8 pad40[0x54 - 0x40];
    u8 *p54;
} V_00526FC0;

extern vu0_v4 D_L39_003B5740[];
extern vu0_v4 D_L39_003B5D40[];
extern vu0_v4 D_L39_003B6200[][12][20];
extern void func_L39_00527460_00526FC0(void *, void *, s32, s32, f32, f32, f32, f32, s32, s32);
extern void func_L39_00527A38(u8 *);
extern long func_L39_00589890(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003D2DA0(void *, s32, s32);

static __inline__ void qcopy_00526FC0(vu0_v4 *d, vu0_v4 *s) { *d = *s; }

void func_L39_00526FC0(u8 *m) {
    S_00526FC0 s;
    vu0_v4 d0;
    vu0_v4 d1;
    vu0_v4 n;
    vu0_v4 e;
    V_00526FC0 *v;
    u8 *p;
    s32 idx;
    u32 col;
    s32 i, j, k;
    f32 y, u0, u1;

    if (m == 0) return;
    if (*(s16 *)(m + 0xAA) != 0x10A7) return;
    if (m[0x20] == 0xFE) return;
    if (m[0x20] == 0xFD) return;
    v = *(V_00526FC0 **)(m + 0x68);
    if (v == 0) return;
    idx = 0;
    p = v->p54;
    if (p != 0) idx = *(s32 *)(p + 0x2544);

    v->f28 -= 0.36f;
    if (v->f28 <= -8.0f) v->f28 += 8.0f;
    func_L39_00527460_00526FC0(&D_L39_003B5740[idx * 12], p + 0x23A0, 0x80, 0x40, 0.05f, 0.4f, 0.9f, v->f28, 0xC, 0x103FFF);
    col = 0x400000FF;
    func_L39_00527460_00526FC0(&D_L39_003B5D40[idx * 12], p + 0x23A0, 0x80, 0x40, 0.05f, 0.4f, 0.9f, v->f28, 0xC, 0x10107F);
    func_L39_00527A38(m);
    s.tex = func_L39_00589890(0xD);
    s.c = 0xFF9000000260;
    s.d = 0x8000000048;
    s.a = 0;
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.col[0] = col;

    y = v->f3C;
    v->f3C = y - 0.048f;
    if (v->f3C <= -8.0f) v->f3C += 8.0f;
    v->f20 -= 0.012f;
    if (v->f20 <= -7.0f) v->f20 += 7.0f;
    v->f24 += 0.012f;
    if (v->f24 >= 5.0f) v->f24 -= 5.0f;

    for (i = 2; i < 12; i++) {
        u0 = v->f20;
        u1 = v->f24;
        for (j = 0; j < 20; j++) {
            k = (j + 1) % 20;
            qcopy_00526FC0(&s.pos[0], D_L39_003B6200[idx][i + 1] + j);
            qcopy_00526FC0(&s.pos[1], D_L39_003B6200[idx][i + 1] + k);
            qcopy_00526FC0(&s.pos[2], D_L39_003B6200[idx][i] + j);
            qcopy_00526FC0(&s.pos[3], D_L39_003B6200[idx][i] + k);
            vec_sub_ba(&d0, &s.pos[0], &s.pos[1]);
            vec_sub_ab(&d1, &s.pos[2], &s.pos[1]);
            func_0038CE90(&n, &d1, &d0);
            vec_sub_ab(&e, &s.pos[1], p + 0x23A0);
            if (func_0038CE68(&n, &e) >= 0.0f) {
                u0 += 0.05f;
                u1 += 0.05f;
            } else {
                f32 x;
                if (i == 11) {
                    s.col[1] = 0xFF;
                    s.col[0] = 0xFF;
                }
                x = y - 0.066667f;
                s.uv[0][0] = y;
                s.uv[0][1] = u0;
                s.uv[1][0] = y;
                s.uv[1][1] = u0 + 0.05f;
                s.uv[2][0] = x;
                s.uv[2][1] = u0;
                s.uv[3][0] = x;
                s.uv[3][1] = u0 + 0.05f;
                u0 += 0.05f;
                func_003D2DA0(&s, 0, 0);
                s.uv[0][0] = y;
                s.uv[0][1] = u1;
                s.uv[1][0] = y;
                s.uv[1][1] = u1 + 0.05f;
                s.uv[2][0] = x;
                s.uv[2][1] = u1;
                s.uv[3][0] = x;
                s.uv[3][1] = u1 + 0.05f;
                u1 += 0.05f;
                func_003D2DA0(&s, 0, 0);
            }
        }
        y += 0.066667f;
    }
}
/* localdecomp:end func_L39_00526FC0 */

/* localdecomp:start func_L39_00527460 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00527460;

typedef struct {
    V_00527460 v[4];
    s32 col[4];
    f32 uv[8];
    long tag[4];
} S_00527460;

extern long func_L39_00589890(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003A9440(s32, unsigned long);

void func_L39_00527460(V_00527460 *pts, V_00527460 *center, s32 a1, s32 a2, s32 n, s32 color,
                       f32 unused, f32 height, f32 width, f32 u) {
    S_00527460 s1;
    S_00527460 s2;
    V_00527460 nrm;
    V_00527460 h;
    V_00527460 d0;
    V_00527460 d1;
    V_00527460 e;
    V_00527460 f;
    V_00527460 a;
    V_00527460 b;
    V_00527460 d2;
    V_00527460 g;
    V_00527460 *p;
    s32 c1;
    s32 c2;
    s32 i;
    f32 len;
    f32 l0;
    f32 l1;
    f32 la;
    f32 lb;

    s1.tag[1] = func_L39_00589890(0xE);
    s1.tag[3] = 0x8000000048L;
    s1.tag[2] = 0xFF9000000260L;
    s1.tag[0] = 0;
    c1 = (a1 << 24) | 0x7F7F7F;
    s1.col[0] = s1.col[1] = s1.col[2] = s1.col[3] = c1;
    s2.tag[1] = func_L39_00589890(0x10);
    s2.tag[3] = s1.tag[3];
    s2.tag[2] = s1.tag[2];
    s2.tag[0] = s1.tag[0];
    c2 = color | (a2 << 24);
    s2.col[0] = s2.col[1] = s2.col[2] = s2.col[3] = c2;
    s2.uv[0] = 0.0f;
    s2.uv[1] = 0.0f;
    s2.uv[2] = 0.0f;
    s2.uv[3] = 1.0f;
    s2.uv[4] = 1.0f;
    s2.uv[5] = 0.0f;
    s2.uv[6] = 1.0f;
    s2.uv[7] = 1.0f;
    s1.uv[0] = u + s2.uv[0];
    s1.uv[1] = s2.uv[1];
    s1.uv[2] = u + s2.uv[2];
    s1.uv[3] = s2.uv[3];
    s1.uv[4] = u + s2.uv[4];
    s1.uv[5] = s2.uv[5];
    s1.uv[6] = u + s2.uv[6];
    s1.uv[7] = s2.uv[7];

    vec_sub_ab(&d0, &pts[0], center);
    vec_sub_ab(&d1, &pts[1], &pts[0]);
    func_0038CE90(&nrm, &d1, &d0);
    l0 = func_0038CEA8(&nrm);
    if (l0 != 0.0f) {
        l0 = 1.0f / l0;
    }
    func_0038CE20(&nrm, &nrm, l0 * 0.05f);
    vec_add_ba(&s1.v[0], &pts[0], &nrm);
    vec_sub_ab(&s1.v[1], &pts[0], &nrm);

    for (i = 1; i < n - 1; i++) {
        p = &pts[i];
        vec_sub_ab(&d0, p, center);
        vec_sub_ab(&d1, p + 1, p);
        func_0038CE90(&nrm, &d1, &d0);
        l1 = func_0038CEA8(&nrm);
        if (l1 != 0.0f) {
            l1 = 1.0f / l1;
        }
        func_0038CE20(&nrm, &nrm, l1 * 0.05f);
        vec_add_ba(&s1.v[2], p, &nrm);
        vec_sub_ab(&s1.v[3], p, &nrm);
        if (i == 1) {
            s1.col[0] = s1.col[1] = 0x7F7F7F;
        } else if (i == n - 2) {
            s1.col[2] = s1.col[3] = 0x7F7F7F;
        } else if (i == 2) {
            s1.col[0] = s1.col[1] = c1;
        }
        func_003D2DA0(&s1, 0, 0);
        s1.v[0] = s1.v[2];
        s1.v[1] = s1.v[3];
    }

    for (i = 0; i < n - 1; i++) {
        p = &pts[i];
        vec_sub_ab(&a, p, center);
        vec_sub_ab(&b, p + 1, center);
        la = func_0038CEA8(&a);
        lb = func_0038CEA8(&b);
        if (lb < la) {
            if (lb == 0.0f) {
                b = a;
            } else {
                func_0038CE20(&b, &b, la / lb);
            }
        } else {
            if (la == 0.0f) {
                a = b;
            } else {
                func_0038CE20(&a, &a, lb / la);
            }
        }
        vec_add_ba(&e, center, &a);
        vec_add_ab(&f, center, &b);
        vec_sub_ba(&d1, &f, &e);
        func_0038CE20(&g, &d1, width);
        vec_sub_ab(&e, &e, &g);
        vec_add_ab(&f, &f, &g);
        vec_sub_ba(&d2, center, &e);
        func_0038CE90(&nrm, &d2, &d1);
        len = func_0038CEA8(&nrm);
        if (len != 0.0f) {
            len = 1.0f / len;
        }
        func_0038CE20(&h, &nrm, height * len);
        vec_add_ba(&s2.v[0], &e, &h);
        vec_sub_ab(&s2.v[1], &e, &h);
        vec_add_ba(&s2.v[2], &f, &h);
        vec_sub_ab(&s2.v[3], &f, &h);
        if (i == 0) {
            s2.col[0] = s2.col[1] = color;
        } else if (i == n - 2) {
            s2.col[2] = s2.col[3] = color;
        } else if (i == 1) {
            s2.col[0] = s2.col[1] = c2;
        }
        func_003D2DA0(&s2, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L39_00527460 */

/* localdecomp:start func_L39_00527A38 */
#include "vu0.h"
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_00527A38;
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L39_0024AA30[] __attribute__((section(".sdata")));

void func_L39_00527A38(u8 *m) {
    S_00527A38 s;
    vu0_v4 mat[4];
    vu0_v4 p;
    vu0_v4 d;
    u8 *t;
    s32 k;
    s32 i;
    vu0_v4 *c;

    t = *(u8 **)(*(u8 **)(m + 0x68) + 0x54);
    k = 0;
    if (t != 0) {
        k = *(s32 *)(t + 0x2544);
    }
    s.x78 = func_L39_00589890(0xB);
    c = D_L39_0024AA30;
    s.x88 = 0x8000000048L;
    s.x80 = 0xFF9000000260L;
    s.c[3] = 0x7F207F7F;
    s.c[2] = 0x7F207F7F;
    s.c[1] = 0x7F207F7F;
    s.c[0] = 0x7F207F7F;
    s.x70 = 0;
    s.x50 = 0.0f;
    s.x54 = 0.0f;
    s.x58 = 0.0f;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    func_0038CF68(&d, m + 0xD0, -0.5f);
    vec_add_ba(&mat[3], &D_L39_003B5140[k].pos[0], &d);
    vec_sub_ba(&d, t + 0x23A0, &mat[3]);
    func_0038CF68(&mat[0], &d, 1.0f);
    func_0038CE90(&mat[1], &mat[0], t + 0x250);
    func_0038CF68(&mat[1], &mat[1], -1.0f);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&p, &c[i], 0.4f);
        func_0038D028(&s.m[i], &p, mat);
    }
    func_003D2DA0(&s, 0, 0);
    s.c[3] = -1;
    s.c[2] = -1;
    s.c[1] = -1;
    s.c[0] = -1;
    for (i = 0; i < 4; i++) {
        func_0038CE20(&p, &c[i], 0.1f);
        func_0038D028(&s.m[i], &p, mat);
    }
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L39_00527A38 */

/* localdecomp:start func_L39_00527C88 */
typedef struct {
    u8 p00[0x10];
    V_00525030 pos;
    u8 state;
    u8 p21[0x27];
    f32 f48;
    u8 p4C[0x14];
    u8 f60;
    u8 p61[7];
    struct P_00527C88 *f68;
    u8 p6C[0x54];
    V_00525030 vC0;
    u8 pD0[0x28];
    f32 fF8;
} O_00527C88;
typedef struct {
    u8 p0[0xA0];
    V_00525030 posA0;
    u8 pB0[0x2474];
    void *f2524;
} Q_00527C88;
typedef struct P_00527C88 {
    u8 p0[0x78];
    u8 f78[0x18];
    s32 f90;
    u8 p94[8];
    Q_00527C88 *f9C;
} P_00527C88;

extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L39_005287B0();
extern void func_L01_004471A8(void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004455E8(void *, f32, f32, void *, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L39_005B5558(void *, void *, void *, f32, s32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00451290(void *, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_003C3D30(void *, s32, s32, f32);
__asm__(".extern D_L39_002429C0, 16");
extern s32 D_L39_002429C0;

void func_L39_00527C88(O_00527C88 *obj) {
    V_00525030 t0;
    V_00525030 t1;
    V_00525030 pos;
    V_00525030 t30;
    V_00525030 t40;
    P_00527C88 *p;
    Q_00527C88 *q;
    void *w;
    f32 r2;
    s32 n;

    p = obj->f68;
    if (func_L01_00447490(obj, 0x8010000, 0)) {
        func_L39_005287B0(obj);
        return;
    }
    q = p->f9C;
    func_0038D160(obj->pos.x - q->posA0.x, obj->pos.y - q->posA0.y);
    func_L01_004471A8(obj, 0.5f);
    switch (obj->state) {
    case 0:
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (obj->f60 & 2) {
            r2 = func_L39_005B4410(0.0f, 100.0f);
            if (r2 >= 0.0f && r2 < 20.0f) {
                func_003C3A10(obj, 0, 0, 8);
            }
            if (r2 >= 20.0f && r2 < 50.0f) {
                func_003C3A10(obj, 4, 0, 8);
            }
            if (r2 >= 50.0f && r2 < 100.0f) {
                func_003C3A10(obj, 1, 0, 8);
            }
        }
        if (func_0038CF38(&obj->pos, &q->posA0) < 2.0f && D_L39_002429C0 == 0 && D_L39_002429BC == 0) {
            func_L01_004450F0(obj, 2, -1);
            func_003C3A10(obj, 2, 0, 8);
            obj->f48 = 0.75f;
        }
        if (func_0038CAD0(&p->f90)) {
            if (D_L39_002429C0 == 0 && D_L39_002429BC == 0) {
                if (func_L39_005B4398(2)) {
                    func_L01_004450F0(obj, 5, -1);
                    p->f90 = (func_L39_005B43C8(400, 600) * 5 + 2) / 6;
                    func_003C3A10(obj, 2, 0, 8);
                    obj->f48 = 0.75f;
                } else {
                    func_L01_004450F0(obj, 6, -1);
                    p->f90 = (func_L39_005B43C8(180, 360) * 5 + 2) / 6;
                    func_003C3A10(obj, 3, 0, 8);
                }
            }
        }
        break;
    case 6:
        if (obj->f60 & 2) {
            func_003C3A10(obj, 3, 0, 8);
        }
        if (func_0038CAD0(&p->f90)) {
            func_L01_004450F0(obj, 1, -1);
            p->f90 = (func_L39_005B43C8(120, 600) * 5 + 2) / 6;
            func_003C3A10(obj, func_L39_005B4398(2), 0, 8);
        }
        break;
    case 5:
        if (obj->f60 & 2) {
            func_003C3A10(obj, 2, 0, 8);
            obj->f48 = 0.75f;
        }
        if (func_0038CF38(&obj->pos, &q->posA0) < 2.0f) {
            func_L01_004450F0(obj, 2, -1);
            obj->f48 = 0.1f;
            func_003C3A10(obj, 2, 0, 8);
        }
        if (func_0038CAD0(&p->f90)) {
            func_L01_004450F0(obj, 1, -1);
            p->f90 = (func_L39_005B43C8(400, 600) * 5 + 2) / 6;
        }
        w = p->f78;
        func_L01_004455E8(obj, func_0038DAB8(obj->fF8, func_L39_005B4410(-30.0f, 30.0f) * 0.0174532924f), 0.000209439531f, w, 0.000628318579f, 0.0157079641f);
        func_0038CF68(&t1, &obj->vC0, 0.00500000035f);
        vec_add_ba(&t0, &obj->pos, &t1);
        pos = obj->pos;
        if (func_L39_005B5558(obj, &obj->pos, &t0, 0.1f, 2, 0.7f, 0.25f, 0.52359879f)) {
            if (func_L01_003FB640(&obj->pos, 1, obj, 0.5f) && D_L39_0025F740.hit != 0) {
                obj->pos = pos;
            }
        } else {
            func_L01_004455E8(obj, func_0038DAB8(obj->fF8, func_L39_005B4410(20.0f, 135.0f) * 0.0174532924f), 6.98131698e-05f, w, 0.000628318579f, 0.0157079641f);
        }
        break;
    case 2:
        if (func_0038CF38(&obj->pos, &q->posA0) < 2.0f) {
            w = p->f78;
            func_L01_004455E8(obj, func_0038DAB8(obj->fF8, func_L39_005B4410(-30.0f, 30.0f) * 0.0174532924f), 0.000209439531f, w, 0.000628318579f, 0.0157079641f);
            func_0038CF68(&t1, &obj->vC0, 0.00500000035f);
            vec_add_ba(&t0, &obj->pos, &t1);
            pos = obj->pos;
            if (func_L39_005B5558(obj, &obj->pos, &t0, 0.5f, 2, 0.7f, 0.25f, 0.52359879f)) {
                if (func_L01_003FB640(&obj->pos, 1, obj, 0.5f) && D_L39_0025F740.hit != 0) {
                    obj->pos = pos;
                }
            } else {
                func_L01_004455E8(obj, func_0038DAB8(obj->fF8, func_L39_005B4410(-90.0f, -10.0f) * 0.0174532924f), 8.37758125e-05f, w, 0.000628318579f, 0.0157079641f);
            }
        } else {
            obj->f48 = 1.0f;
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 4:
        func_L01_00451290(obj, &pos, 0);
        func_0038CF68(&pos, &pos, 4.0f);
        vec_add_ba(&t30, &obj->pos, &pos);
        func_0038CF68(&pos, &pos, -1.0f);
        vec_add_ba(&t40, &obj->pos, &pos);
        if (func_003D3CB0(&t40, &t30, 0, obj, 0)) {
            if (D_L39_0025F740.hit != q->f2524) {
                obj->pos = D_L39_0025F740.pos;
            }
        }
        n = func_003D5630();
        if (n > 0 && n != 10 && D_L39_002429C0 == 0) {
            func_L39_005287B0(obj);
            return;
        }
        func_L01_004450F0(obj, 0, -1);
        break;
    }
    if (D_L39_002429C0 == 0 && D_L39_002429BC == 0) {
        pos = obj->pos;
        pos.z += 0.5f;
        obj->pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
    }
    if (obj->pos.x < 2.0f || 1021.0f < obj->pos.x || obj->pos.y < 2.0f || 1021.0f < obj->pos.y ||
        obj->pos.z < 2.0f || 1021.0f < obj->pos.z) {
        func_L39_005287B0(obj);
    }
}
/* localdecomp:end func_L39_00527C88 */

/* localdecomp:start func_L39_005285A8 */
extern u8 *func_003C24B0(s32, s32);
extern void func_003C25D8(u8 *, s32);
extern void func_0038D570(void *, void *);
extern void func_003C48A8(void *, void *);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005B49A8(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_003C7C38(void *);
extern u8 *func_00382348(void *);
extern void func_L39_00528B38(s32);
extern u8 D_L39_00273610[];
extern s32 D_L39_00271B40[];
extern s32 D_L39_00271F00[];
__asm__(".extern D_L39_002429C0, 16");
extern s32 D_L39_002429C0;
extern s32 D_L39_002429BC;

u8 *func_L39_005285A8(u8 *a0, s32 a1) {
    u8 *object = func_003C24B0(0x10AA, 0xA0);
    u8 *state;
    u8 kind;
    vu0_q buf[4];
    u8 *q;
    if (object != 0) {
        state = *(u8 **)(object + 0x68);
        kind = object[0x22];
        func_003C25D8(object, 0x1080);
        object[0x22] = D_L39_00273610[0];
        *(s32 *)(object + 0x24) = D_L39_00271B40[object[0x22]];
        *(s32 *)(object + 0x64) = D_L39_00271F00[kind];
        *(u8 **)(object + 0x68) = state;
        object[0x30] = 0x7F;
        *(s16 *)(object + 0x32) = 0x7F;
        object[0x31] = 1;
        *(f32 *)(object + 0x48) = func_L39_005B4410(0.85f, 1.15f);
        *(vu0_q *)(object + 0x10) = *(vu0_q *)(a0 + 0x10);
        if (D_L39_002429C0 != 0 || D_L39_002429BC != 0) {
            func_0038D570(buf, a0 + 0xC0);
            func_003C48A8(buf, object + 0xF0);
        } else {
            qzero(object + 0xF0);
            *(f32 *)(object + 0xF8) = func_L39_005B44C8();
        }
        object[0x20] = 0;
        *(s16 *)(state + 0x76) = 0;
        *(s16 *)(state + 0x74) = func_L39_005B43C8(100, 250);
        *(s32 *)(state + 0x90) = 500;
        *(s32 *)(state + 0x94) = 25;
        *(s32 *)(state + 0x9C) = a1;
        *(s32 *)(state + 0x7C) = 0;
        *(s32 *)(state + 0x98) = 0;
        object[0x20] = 4;
        func_L39_00528B38((s32)object);
        *(s32 *)(object + 0x98) = *(s32 *)(*(u8 **)(object + 0x24) + 0x10);
        *(f32 *)(state + 0x88) = 1.0f;
        *(s32 *)(state + 0x80) = -1;
        q = func_00382348(a0);
        q[0x17] = 9;
        if (*(u16 *)(object + 0x34) & 0x1000) {
            func_L39_005B49A8(a0, 0, 3);
        }
        if (q != 0 && q[0xE] == 1) {
            q[0xE] = 2;
        } else {
            func_003C2880(a0);
        }
        *(u8 **)(state + 0x70) = a0;
        func_003C7C38(object);
    }
    return object;
}
/* localdecomp:end func_L39_005285A8 */

/* localdecomp:start func_L39_005287B0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005287B0;
typedef struct { u8 pad0[0x10]; V_005287B0 pos; } O_005287B0;
typedef struct { u8 pad0[0x140]; f32 x; f32 y; } T_005287B0;
extern s32 D_L39_0024D4E0_b;
extern T_005287B0 D_L39_0024DCC0;
__asm__(".extern D_L39_0024AA70, 4");
extern f32 D_L39_0024AA70;
__asm__(".extern D_L39_0024AA74, 4");
extern f32 D_L39_0024AA74;
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L39_005D2930(void *, void *, s32);
extern void func_L39_00528AF0(s32);
extern void func_003C2880(void *);
void func_L39_005287B0(O_005287B0 *o) {
    V_005287B0 v0;
    V_005287B0 v1;
    s32 i;
    f32 a, b, c;
    f32 ang, spd, dir, s;

    for (i = 0; i < 0x21 - D_L39_0024D4E0_b; i++) {
        a = func_L39_005B4410(0.0f, 0.37f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&v1, a, b, c);
        v1.z += func_L39_005B4410(0.35f, 0.6f);
        vec_add_ba(&v1, &v1, &o->pos);
        a = func_L39_005B4410(0.002f, 0.020000001f);
        b = func_L39_005B44C8();
        c = func_L39_005B44C8();
        func_00382760(&v0, a, b, c);
        func_L39_005C8CA8(&v1, &v0, 0x4F20507F, 0x102F, func_L39_005B43C8(0x19, 0x2F), 150000.0f);
    }
    for (i = 0; i < 0x32 - D_L39_0024D4E0_b; i++) {
        ang = func_0038D160(D_L39_0024DCC0.x - o->pos.x, D_L39_0024DCC0.y - o->pos.y);
        func_L39_005B4468(1.0f, 2.0f);
        v0.x = o->pos.x + func_L39_005B4468(0.0f, 0.15f);
        v0.y = o->pos.y + func_L39_005B4468(0.0f, 0.15f);
        v0.z = o->pos.z + func_L39_005B4468(0.0f, 0.15f);
        s = D_L39_0024AA70;
        spd = s * 0.020000001f;
        dir = func_0038DAB8(ang, func_L39_005B4468(0.0f, -1.5707964f));
        v1.x = func_0038D098(dir) * spd;
        v1.y = func_0038D0B0(dir) * spd;
        s = D_L39_0024AA74;
        v1.z = s * 0.020000001f;
        func_L39_005D2930(&v0, &v1, 0xFA);
    }
    func_L39_00528AF0((s32)o);
    func_003C2880(o);
}
/* localdecomp:end func_L39_005287B0 */
