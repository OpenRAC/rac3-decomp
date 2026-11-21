#include "common.h"

/* NTSC-U counterpart of func_L39_00546FE0 (src/levels/shared/L39_00546F30.c) */
/* localdecomp:start func_L39_00546750 */
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

extern u8 D_L39_004998A0[];
extern E_00546FE0 D_L39_0049C950[];
extern C_00546FE0 D_L39_0024DF80[];
extern O_00546FE0 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern s32 D_L39_002638C0[];
extern u8 D_L39_00470580_00546750[];
extern s32 D_L39_0024B0C0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0C0, 4");
extern s32 D_L39_0024B0B0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0B0, 4");
extern s32 D_L39_0024B0B4 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0B4, 4");
extern s32 D_L39_0024B0B8_00546750 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0B8_00546750, 4");
extern s32 D_L39_0024B0BC __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0BC, 4");
extern s32 D_L39_0024B0E4 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0E4, 4");
extern s32 D_L39_0024B0A0_00546750 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B0A0_00546750, 4");

extern void func_L39_00619D58(u8 *, u8 **);
extern s32 func_003883C8(void *);
extern s32 func_00388398(void *);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern s32 func_L01_0040BB20(void *);
extern s32 func_L39_00637548(void *);
extern void func_L39_005466A0(s32 id, f32 *a, f32 *b);
extern f32 func_003887C8(void *, void *);
extern s32 func_L39_005FD580(f32, f32 *, s32 *, s32);
extern s16 func_L39_0061E558(u8 *, s32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_006719D8(void *);
extern s32 func_L39_00670988(void *p, s32 a1, s32 a2, s32 a3);
extern s32 func_L39_00646268(u8 *, s32);
extern void func_L39_0061F5C0(void *, s32);
extern s32 func_L01_003F0118(void *, void *);
extern f32 func_L39_005B25C8_00546750(void);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_003F0338(s32, void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_00454298(u8 *, void *, void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L39_00547818(void *, void *);
extern void func_L39_00547D30(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern void func_L39_005FD6D8(void);
extern void func_L01_00443840(void *, void *);
extern void func_00388BF0(void *, void *);
extern void func_00388E58(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_00389118(void *out, void *a, void *b);
extern void func_003BF2F8(f32 *q, void *axis, f32 angle);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_00389380(f32, f32);
extern R_00546FE0 *func_L39_005474F8_00546750(void *, void *, void *, void *, f32);

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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
    if (func_L39_00646268((u8 *)o, id) != 0) {
        return &D_L39_0049C950[D_L39_0049C950[id].b21];
    }
    return &D_L39_0049C950[id];
}

static __inline__ s32 query_00546FE0(void *pos, s32 flags, void *ign, s32 info, f32 r, s32 player) {
    O_00546FE0 *p = D_L39_0024CF20[player];
    s32 n;

    player = -1;
    if (p != 0) {
        player = p->w2548;
    }
    func_L39_005FD658(player);
    n = func_003CF790(pos, flags, ign, info, r);
    func_L39_005FD6D8();
    return n;
}

void func_L39_00546750(A_00546FE0 *a0) {
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
        func_L39_00619D58((u8 *)a0, (u8 **)&m->o);
    }
    if (m->o == 0) {
        return;
    }
    o = m->o;
    if (a0->b20 == 6 && func_003883C8(&m->h4) != 0) {
        func_L39_005F0CE0(2, 0, a0);
        a0->b20 = 1;
    }
    if (a0->b42 == a0->b43 && (a0->b60 & 2)) {
        func_L01_00441E00((u8 *)a0, 1, 0, 2, 0);
    }
    if (state_00546FE0(o, 1)) {
        o->vt->f34(o, 0x1D, 0, 0, 1);
    }
    func_L01_0040BB20(m);
    if (net_00546FE0(o) && func_L39_00637548(o) != 0) {
        if (o->f1250 >= 0.8f) {
            o->w1078 = o->w122C;
            func_L39_005466A0(o->w122C, &dist, 0);
            if (dist > func_003887C8(o->bA0, (u8 *)o->w122C + 0x10)) {
                color = 0x700000FF;
            } else {
                color = 0x601080FF;
            }
        } else {
            color = func_L39_005FD580(150.0f, &o->f1338, &o->w133C, 0);
        }
        if (net_00546FE0(o)) {
            func_L01_003F4D78(o->b24C9, a0, color, 0, 0x20, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    } else if (net_00546FE0(o) && state_00546FE0(o, 0x1D)) {
        if (m->f0 > 0.0f && func_L39_0061E558((u8 *)o, -1) != 0) {
            color = 0x600000FF;
        } else {
            color = 0x600FFF0F;
        }
        if (net_00546FE0(o)) {
            func_L01_003F4D78(o->b24C9, a0, color, 0, 0x20, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    } else if (!net_00546FE0(o)) {
        func_L39_006719D8(o);
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

    res = func_L39_00670988(o->b1A40, 0, 1, (s32)&s);
    if (res == 8) {
        s32 v = o->p2524->b43;

        if (v == ent_00546FE0(o, 2)->hC || bonus_00546FE0(o) || aim_00546FE0(o)) {
            m->h6 = D_L39_0024B0B0;
            m->h8 = D_L39_0024B0B8_00546750;
            m->hA = D_L39_0024B0C0;
            m->w48 = 1;
        } else {
            m->h6 = 2;
            m->w48 = 0;
            m->h8 = D_L39_0024B0B4;
            m->hA = D_L39_0024B0BC;
        }
        if (!net_00546FE0(o)) {
            V3_00546FE0 *v = &m->v54;

            v->x = s.x;
            v->y = s.y;
            v->z = s.z;
        }
        func_L39_0061F5C0(o, -1);
        m->w4C = func_L01_003F0118(D_L39_00470580_00546750, o->p2534);
        a0->b20 = 2;
        m->fC = func_L39_005B25C8_00546750();
        func_003BE4F0(a0, 2, 0, 0);
        m->f20 = 1.0f / (f32)m->h8;
        m->f24 = 1.0f / (f32)m->hA;
        m->f28 = func_L39_005B25C8_00546750();
        m->f2C = func_L39_005B25C8_00546750();
        m->w40 = D_L39_0024B0E4;
        m->f44 = 1.0f / (f32)m->w40;
    } else if (res == 4) {
        func_L39_005F0CE0(4, 0, a0);
    }
    }
    if ((res != 8 || !busy_00546FE0(o)) && m->w4C >= 0) {
        func_L01_003F0338(m->w4C, o->p2534);
        m->w4C = -1;
    }
    if (m->h6 == 0) {
        func_003883C8(&m->hA);
        func_003883C8(&m->h8);
        func_00388398(&m->w40);
        {
        unsigned long t8 = *(u32 *)&m->h8;
        if (t8 != 0) {
            func_L01_004026A0(func_L39_00547D30, a0);
        }
        }
    }
    if ((a0->b20 == 2 || a0->b20 == 3) && func_003883C8(&m->h6) != 0) {
        if (o->w1078 != 0) {
            func_L01_00454298((u8 *)o->w1078, &m->v10, &o->q3B0, 1.0f);
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
            func_003BDA38(a0, 0, &m->v10);
            func_L39_00547818(a0, &m->v10);
            m->q30 = o->q3B0;
            func_L01_004026A0(func_L39_00547D30, a0);
            func_L39_005F0CE0(0, 0, a0);
            if (m->w48 != 0) {
                if (net_00546FE0(o)) {
                    (&D_L39_0024DF80[o->b24C9])->f20 = 0.12f;
                    (&D_L39_0024DF80[o->b24C9])->w28 = 0x1e;
                    (&D_L39_0024DF80[o->b24C9])->w2C = 0;
                }
                if (net_00546FE0(o)) {
                    (&D_L39_0024DF80[o->b24C9])->f20 = 0.12f;
                    (&D_L39_0024DF80[o->b24C9])->w28 = 0x1e;
                    (&D_L39_0024DF80[o->b24C9])->w2C = 0;
                }
            } else {
                if (net_00546FE0(o)) {
                    (&D_L39_0024DF80[o->b24C9])->f20 = 0.06f;
                    (&D_L39_0024DF80[o->b24C9])->w28 = 0x1e;
                    (&D_L39_0024DF80[o->b24C9])->w2C = 0;
                }
                if (net_00546FE0(o)) {
                    (&D_L39_0024DF80[o->b24C9])->f20 = 0.06f;
                    (&D_L39_0024DF80[o->b24C9])->w28 = 0x1e;
                    (&D_L39_0024DF80[o->b24C9])->w2C = 0;
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
            m->h4 = 0x1c;
            l.a = a0;
            l.w74 = 0x10001;
            l.w80 = 1;
            l.b78 = 3;
            l.b79 = 2;
            l.h7A = a0->hAA;
            l.f7C = ent_00546FE0(o, 2)->f30 * 2.0f;
            l.w88 = 0;
            func_003886E8(&pos, &a0->vD0, -1.35f);
            vec_add_ba(&pos, &pos, &a0->v10);
            func_003886E8(&off, &a0->vC0, 0.275f);
            vec_add_ab(&pos, &pos, &off);
            n = query_00546FE0(&pos, 1, o->p2524, 0, 1.5f, o->w2544);
            {
                s32 k;

                for (k = 0; k < n; k++) {
                    if (D_L39_002638C0[k] != (s32)o->p2524) {
                        func_003886E8(&l.v, &a0->vD0, -1.5f);
                        l.v.w = 5627.925f;
                        func_L01_00443840((void *)D_L39_002638C0[k], &l);
                    }
                }
            }
            func_00388BF0(m130, &D_L39_0024B0A0_00546750);
            func_00388E58(m100, m130);
            func_003BDA38(a0, 0, &base);
            if (func_L39_00637548(o) != 0 && !aim_00546FE0(o)) {
                q_00546FE0 *cam = &o->q380;

                *(q_00546FE0 *)&mtx[0] = o->q380;
                *(q_00546FE0 *)&mtx[1] = o->q390;
                func_00388830(&mtx[2], &o->v3A0, -0.1f);
                func_00388EB8(&mtx[3], cam, m100);
            } else if (o->b1A08 == 1) {
                func_003886E8(&mtx[0], &a0->vD0, -1.0f);
                func_003886E8(&mtx[1], &a0->vC0, -1.0f);
                func_003886E8(&mtx[2], &a0->vE0, 0.1f);
                func_00388EB8(&mtx[3], &a0->vC0, m100);
            } else {
                q_00546FE0 *cam = &o->q380;

                *(q_00546FE0 *)&mtx[0] = o->q380;
                *(q_00546FE0 *)&mtx[1] = o->q390;
                func_003886E8(&mtx[2], &o->v3A0, -0.1f);
                func_00388EB8(&mtx[3], cam, m100);
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
                func_003BF2F8((f32 *)&quat, &mtx[1], ang);
                func_00389118(&dir, &mtx[0], &quat);
                func_00389118(&fwd, &mtx[2], &quat);
                roll = func_00389380(func_L39_005B2510(range * 0.5f, range * 1.5f), roll);
                func_003BF2F8((f32 *)&quat, &mtx[0], roll);
                func_00389118(&dir, &dir, &quat);
                func_00389118(&fwd, &fwd, &quat);
                func_003886E8(&dir, &dir, 32.0f);
                vec_add_ab(&from, &base, &fwd);
                vec_add_ab(&to, &from, &dir);
                r = func_L39_005474F8_00546750(a0, &from, &to, &l, ang);
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
/* localdecomp:end func_L39_00546750 */
