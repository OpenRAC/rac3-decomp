#include "common.h"

/* declared by functions of L39_0055B418.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_0055B4D8 */
#include "vu0.h"
typedef int Q_0055B4D8 __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; u8 *ptr[0x980]; Q_0055B4D8 q[0x260]; } H_0055B4D8;
typedef union { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; u8 *ptr[0x40]; Q_0055B4D8 q[0x10]; } O_0055B4D8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0055B4D8;
typedef struct { u8 b[0x80]; } Snd_0055B4D8;
typedef struct { s32 w[11]; } Row_0055B4D8;
typedef union { u8 b[0x80]; s8 c[0x80]; f32 f[0x20]; } Wp_0055B4D8;

extern u8 D_L39_004997E0[];
extern Row_0055B4D8 D_L39_0047A8A8[];
extern O_0055B4D8 *D_L39_0025F740[];
extern O_0055B4D8 *D_L39_002637C0[];
extern Wp_0055B4D8 D_L39_0049C890[];
extern Snd_0055B4D8 D_L39_001FE020[];
extern s32 D_001D4BC0_sda;

extern u8 *func_L39_0061D1D8(s32);
extern void func_003C2880(void *);
extern void func_L01_003F6F20(s32, void *, u32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0055A880(void);
extern void func_L01_00404A10(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_L39_0055AD78(u8 *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00511158(void *, void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_0044AEB8(void *);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_0055B178(void *, void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_L39_00632C48(void *, f32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern s32 func_L01_00446BF0(void *, void *, void *, void *, void *, void *, s32);
extern s32 func_L01_00337EF8(void);
extern s32 func_L01_00337EA8(void);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern void func_L01_0044E468(void *, s32);
extern void func_L01_0044E298(void *, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
/* level 39 calls func_L01_00348160's place; other levels call another copy of that empty function */
extern void func_L01_00348160_0055B4D8(void *);
extern void func_L39_0062B728(void *, s32);
extern void func_L39_005F3088(s32);
extern void func_L39_0063A030(void *, s32, s32);
extern void func_L01_0044E740(void *);
extern s32 func_L39_005B8928(void *);
extern O_0055B4D8 *func_00382348(void *);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L39_0055AF88(void *, s32);

/* the hero state's decoder (as func_L39_0055AD78 writes it) */
static __inline__ u32 Dec_0055B4D8(u8 *p) {
    u32 buf[2];
    u8 *b;
    s32 x;
    long t;
    s32 i;

    t = *p;
    if (t == 0) {
        x = 0;
    } else {
        s32 m;
        s32 k;
        s32 n = *p;
        m = n + 1;
        k = ((s32)p - n) & 7;
        b = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        x = buf[1];
    }
    return x;
}

/* the same decoder with the key read once (Dec_00663DA8's form) */
static __inline__ u32 DecB_0055B4D8(u8 *q) {
    u32 buf[2];
    u32 r;
    s32 n;
    s32 m;
    s32 k;
    s32 i;
    u8 *d;

    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        m = n + 1;
        k = ((s32)q - n) & 7;
        d = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)q;
        buf[1] ^= buf[0];
        r = buf[1];
    }
    return r;
}

static __inline__ s32 Eq_0055B4D8(u32 a, u32 b) {
    return (a ^ b) == 0;
}

static __inline__ s32 IsB_0055B4D8(u8 *p, u32 v) {
    return Eq_0055B4D8(DecB_0055B4D8(p), v);
}

static __inline__ s32 Is_0055B4D8(u8 *p, u32 v) {
    return Eq_0055B4D8(Dec_0055B4D8(p), v);
}

/* the weapon table entry of gadget id (its upgraded row when func_L39_00648AE0 says so) */
static __inline__ Wp_0055B4D8 *Weap_0055B4D8(u8 *h, s32 id) {
    if (func_L39_00648AE0(h, id) != 0) {
        return &D_L39_0049C890[D_L39_0049C890[id].c[0x21]];
    }
    return &D_L39_0049C890[id];
}

void func_L39_0055B4D8(O_0055B4D8 *m) {
    H_0055B4D8 *H;
    O_0055B4D8 *pv;
    s32 st;

    H = (H_0055B4D8 *)func_L39_0061D1D8(m->i[0x90 / 4]);
    if (H == 0) {
        func_003C2880(m);
        return;
    }
    pv = (O_0055B4D8 *)m->ptr[0x68 / 4];
    H->b[0x46C] = 0;
    if (H->i[0x474 / 4] == 3) {
        return;
    }
    st = m->b[0x20];
    switch (st) {
    case 0: {
        s32 ok;
        s32 hit;
        f32 yaw;
        f32 d;
        Row_0055B4D8 *row;

        m->ptr[0xB8 / 4] = H->ptr[0x2524 / 4];
        st = Dec_0055B4D8(H->b + 0x19E4);
        if (Eq_0055B4D8(st, 1) || Is_0055B4D8(H->b + 0x19E4, 0x1D)) {
            if (((O_0055B4D8 *)H->ptr[0x2524 / 4])->uh[0x34 / 2] & 1) {
                if (H->b[0x1A14] != 0) {
                    func_L01_003F6F20(H->b[0x24C9], m, 0xFF917267, 0, 0x25, -1, 4, 1.0f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                }
            }
        }
        if (pv != 0 && pv->f[0x70 / 4] != 0.0f) {
            func_L01_00404A10(func_L39_0055A880, m);
        }
        if (D_001D4BC0_sda == 0) {
            m->uh[0x34 / 2] &= ~0x10;
        } else {
            m->u[0x78 / 4] = 0x80909090;
            m->uh[0x34 / 2] |= 0x10;
        }
        st = m->b[0x43];
        switch ((u8)st) {
        case 0:
            break;
        case 0xE:
            if (m->b[0x60] & 2) {
                func_003C3A10(m, 1, 0, 4);
            }
            return;
        default:
            if (H->b[0x1A10] != 0) {
                if ((u8)(st - 0xF) >= 2) {
                    func_003C3A10(m, 0xF, 0, 3);
                } else if ((m->b[0x60] & 2) && (u8)st == 0xF) {
                    func_003C3A10(m, 0x10, 0, 4);
                }
                return;
            }
            if ((u8)(st - 0xF) < 2) {
                func_003C3A10(m, 0xE, 0, 2);
                return;
            }
            break;
        }
        if ((m->b[0x60] & 2) && !Is_0055B4D8(H->b + 0x19E4, 0x37)
            && !Is_0055B4D8(H->b + 0x19E6, 0x22) && m->b[0x43] != 1) {
            func_003C3A10(m, 1, 0, 4);
        }
        if (m->b[0x42] == 6) {
            func_003C3938(m, 1, 0);
        }
        func_L39_0055AD78((u8 *)m);
        if (!Is_0055B4D8(H->b + 0x19E4, 0x13) && !Is_0055B4D8(H->b + 0x19E4, 0x20)
            && !Is_0055B4D8(H->b + 0x19E4, 0x2A) && !Is_0055B4D8(H->b + 0x19E4, 0x6F)
            && !Is_0055B4D8(H->b + 0x19E4, 0x14)) {
            if (m->b[0x43] >= 3) {
                if (m->b[0x43] < 6) {
                    func_003C3A10(m, 1, 0, 3);
                }
            }
        }
        {
            O_0055B4D8 *o = (O_0055B4D8 *)H->ptr[0x2524 / 4];
            if (o->b[0x43] != o->b[0x42] || o->b[0x41] - o->b[0x40] >= 3) {
                pv->uh[0x74 / 2]++;
            }
        }
        m->f[0x48 / 4] = H->f[0x610 / 4];
        row = &D_L39_0047A8A8[H->h[0x107C / 2]];
        if (!IsB_0055B4D8(H->b + 0x19E6, 6) && !Is_0055B4D8(H->b + 0x19E4, 0x2A)) {
            return;
        }
        ok = 1;
        if (H->i[0x61C / 4] != 0 || H->f[0x628 / 4] < (f32)row->w[0x1C / 4]
            || (f32)row->w[0x20 / 4] < H->f[0x628 / 4]) {
            ok = 0;
        }
        hit = 0;
        if (pv->h[0x7C / 2] != pv->h[0x74 / 2]) {
            u8 a = ((O_0055B4D8 *)H->ptr[0x2524 / 4])->b[0x42];
            if (a == ((O_0055B4D8 *)H->ptr[0x2524 / 4])->b[0x43]) {
                if (a == 0x17) {
                    s32 x = 0.0f <= H->f[0x628 / 4];
                    hit = x;
                } else if (a == 0x18) {
                    s32 x = 0.0f <= H->f[0x628 / 4];
                    hit = x;
                } else if (a == 0x19) {
                    s32 x = 12.0f <= H->f[0x628 / 4];
                    hit = x;
                } else if (a == 0x27) {
                    s32 x = 23.0f <= H->f[0x628 / 4];
                    hit = x;
                }
            }
        }
        if (hit) {
            pv->f[0x70 / 4] = 1.0f;
            pv->h[0x7C / 2] = pv->h[0x74 / 2];
        }
        d = 0.0f;
        H->q[0x1010 / 16] = H->q[0xFF0 / 16];
        H->q[0x1000 / 16] = H->q[0xFE0 / 16];
        yaw = H->f[0xB8 / 4];
        func_003C2F58(m, 1, H->b + 0xFF0);
        func_003C2F58(H->ptr[0x2524 / 4], 0, H->b + 0xFE0);
        if (Is_0055B4D8(H->b + 0x19E4, 0x13) || Is_0055B4D8(H->b + 0x19E4, 0x6F)
            || Is_0055B4D8(H->b + 0x19E4, 0x2A)) {
            yaw = func_0038D160(H->f[0xFF0 / 4] - H->f[0xA0 / 4], H->f[0xFF4 / 4] - H->f[0xA4 / 4]);
            if (D_L39_0047A8A8[H->h[0x107C / 2]].w[1] == 1) {
                yaw = func_0038DAB8(yaw, -1.5707964f);
            } else {
                yaw = func_0038DAB8(yaw, 1.5707964f);
            }
        }
        {
            V4_0055B4D8 s0;

            {
                vec_sub_ab(&s0, H->b + 0xFF0, H->b + 0xFE0);
                func_0038CF68(&s0, &s0, func_0038CEA8(&s0) + 0.17f);
                if (!Is_0055B4D8(H->b + 0x19E6, 0xF) && !Is_0055B4D8(H->b + 0x19E4, 0x6F)
                    && !Is_0055B4D8(H->b + 0x19E4, 0x14)) {
                    d = func_0038DBA0(H->f[0xB8 / 4], func_0038D160(H->f[0xFF0 / 4] - H->f[0xA0 / 4], H->f[0xFF4 / 4] - H->f[0xA4 / 4]));
                    if (d > 1.5707964f) {
                        ok = 0;
                    }
                    func_L39_0055B418(H->b, (f32 *)&s0);
                }
                vec_add_ab(H->b + 0xFF0, H->b + 0xFE0, &s0);
            }
        }
        if (!Is_0055B4D8(H->b + 0x19E4, 0x2A) && !Is_0055B4D8(H->b + 0x19E4, 0x6F) && d < 1.2217305f
            && H->i[0x2F0 / 4] >= 9) {
            V4_0055B4D8 s0, s1, s2, s3;
            f32 ang;

            {
                *(Q_0055B4D8 *)&s0 = H->q[0xA0 / 16];
                func_L01_00511158(H, &s0, &s0, 0.5f);
                ang = func_0038D160(H->f[0xFF0 / 4] - H->f[0xA0 / 4], H->f[0xFF4 / 4] - H->f[0xA4 / 4]);
                *(Q_0055B4D8 *)&s1 = H->q[0xA0 / 16];
                func_L01_00511158(H, &s1, &s1, 0.5f);
                s2.x = func_0038D098(ang) * 1.4f;
                s2.y = func_0038D0B0(ang) * 1.4f;
                s2.z = 0.0f;
                func_L39_0055B418(H->b, (f32 *)&s2);
                vec_add_ab(&s1, &s1, &s2);
                if (H->h[0x107E / 2] == 0 && func_003D3CB0(&s0, &s1, 2, 0, 0) != 0 && func_003D5630() != 0
                    && (D_L39_0025F740[0x18 / 4] == 0 || func_L01_0044AEB8(D_L39_0025F740[0x18 / 4]) != 0)) {
                    H->h[0x107E / 2] = 1;
                    func_L39_005F33E0(2, 0, m);
                    func_L39_0055B178(m, H);
                    if (D_L39_0025F740[0x18 / 4] != 0) {
                        if (H->b[0x1A06] == 0) {
                            s3.x = func_0038D098(yaw);
                            s3.y = func_0038D0B0(yaw);
                            s3.z = 0.0f;
                        } else {
                            *(Q_0055B4D8 *)&s3 = H->q[0x20 / 16];
                        }
                        func_L01_00446A70(D_L39_0025F740[0x18 / 4], m, 0x10001, &D_L39_0025F740[0x20 / 4], &s3, 1.0f);
                    }
                }
            }
        }
        if (Is_0055B4D8(H->b + 0x19E4, 0x14) && func_L39_00632C48(H, 27.0f) != 0) {
            V4_0055B4D8 s0, s1;

            {
                func_L39_005F33E0(2, 0, m);
                *(Q_0055B4D8 *)&s1 = *(Q_0055B4D8 *)&s0 = H->q[0xFF0 / 16];
                func_L01_00511158(H, &s0, &s0, 0.7f);
                func_L01_00511158(H, &s1, &s1, -0.9f);
                if (func_003D3CB0(&s0, &s1, 2, 0, 0) != 0) {
                    func_L39_0055B178(m, H);
                }
            }
        }
        if (!ok) {
            return;
        }
        {
            V4_0055B4D8 s0, s1, s2, s3;
            f32 rad;
            f32 k;
            f32 dmg;

            dmg = Weap_0055B4D8(H->b, 10)->f[0x30 / 4];
            k = 1.0f;
            if (IsB_0055B4D8(H->b + 0x19E4, 0x14)) {
                dmg = Weap_0055B4D8(H->b, 10)->f[0x34 / 4];
                k = 1.55f;
            }
            s3.x = func_0038D098(yaw);
            s3.y = func_0038D0B0(yaw);
            s3.z = 0.0f;
            func_L01_00446760(&s0, m, 0x10001, &s3, dmg);
            func_0038CFB8(&s0, &s0, k);
            s0.w = 5627.925f;
            ((u8 *)&s0)[0x19] = 1;
            ((u16 *)&s0)[0x1A / 2] = m->uh[0xAA / 2];
            s0.z = 1.0f;
            ((u8 *)&s0)[0x18] = 0;
            if (H->b[0x1A06] != 0) {
                qzero(&s3);
                func_L01_00450E48(H->ptr[0x2524 / 4], &s3, 1.0f, 0.0f, 1.0f);
            }
            if (func_L01_00446BF0(H->b + 0xFE0, H->b + 0xFF0, H->b + 0x1000, H->b + 0x1010, H->ptr[0x2524 / 4], &s0, 5) != 0
                && D_L39_0025F740[0x18 / 4] != 0 && func_L01_00337EF8() == 0 && H->h[0x107E / 2] == 0) {
                if (D_L39_0025F740[0x18 / 4] == 0 || (O_0055B4D8 *)D_L39_0025F740[0x18 / 4]->ptr[0x24 / 4] == 0
                    || ((O_0055B4D8 *)D_L39_0025F740[0x18 / 4]->ptr[0x24 / 4])->b[0x46] != 0x14) {
                    H->h[0x107E / 2] = 1;
                    func_L39_005F33E0(func_L01_00337EA8(), 0, m);
                    func_L39_0055B178(m, H);
                }
            }
            {
                V4_0055B4D8 s4, s5;

                vec_sub_ab(&s5, H->b + 0xFF0, H->b + 0xFE0);
                func_0038CF68(&s5, &s5, func_0038CEA8(&s5) - 0.085f);
                vec_add_ab(&s4, &s5, H->b + 0xFE0);
                rad = 0.35f;
                if (Is_0055B4D8(H->b + 0x19E6, 0xF)) {
                    rad = 0.7f;
                }
                if (Is_0055B4D8(H->b + 0x19E4, 0x14)) {
                    rad = 0.47f;
                }
                if (func_003D4D00(&s4, rad, 0, H->ptr[0x2524 / 4], &s0) != 0) {
                    if ((D_L39_002637C0[0] == 0 || D_L39_002637C0[0]->ptr[0x24 / 4] == 0
                         || ((O_0055B4D8 *)D_L39_002637C0[0]->ptr[0x24 / 4])->b[0x46] != 0x12)
                        && func_L01_00337EF8() == 0 && H->h[0x107E / 2] == 0) {
                        H->h[0x107E / 2] = 1;
                        func_L39_005F33E0(func_L01_00337EA8(), 0, m);
                        func_L39_0055B178(m, H);
                    }
                }
            }
        }
        break;
    }
    case 10:
    case 11: {
        V4_0055B4D8 s0, s1;
        s32 reached;
        s32 close;
        s32 hit;
        f32 dist;
        f32 k;

        func_L01_0044E468(H->b + 0x1780, 0);
        m->ptr[0xB8 / 4] = H->ptr[0x2524 / 4];
        H->b[0x46C] = 2;
        if (m->b[0x20] == 10) {
            s32 id = H->i[0x2404 / 4];
            Snd_0055B4D8 *e;
            if (id == -1 || (e = &D_L39_001FE020[id], *(u8 **)&e->b[0xDC] != H->ptr[0x2524 / 4]) || e->b[0xD0] == 0) {
                H->i[0x2404 / 4] = func_L39_005F33E0(0xB, 4, H->ptr[0x2524 / 4]);
            }
        }
        func_L01_0044E298(m, 0.0f, 0.0f, 0.48869219f);
        if (H->h[0x107E / 2] != 0 && func_0038CAD0(&pv->b[0x6C]) != 0) {
            H->h[0x107E / 2] = 0;
        }
        if (H->b[0x1A06] == 0) {
            f32 g = func_003C3D30(&m->q[1], 0, 0, 0.5f);
            f32 y = m->f[0x18 / 4];
            if (y - g < 0.8f) {
                g += 0.55f;
                if (y < g) {
                    func_003C4138(&m->f[0x18 / 4], g, 0.080000006f);
                } else {
                    func_003C4138(&m->f[0x18 / 4], g, 0.020000001f);
                }
            }
        }
        *(Q_0055B4D8 *)&s0 = m->q[1];
        if (m->b[0x20] == 10) {
            *(Q_0055B4D8 *)&s1 = H->q[0x180 / 16];
            func_0038CE20(&s1, &s1, 0.98f);
            vec_add_ba(&m->q[1], &m->q[1], &s1);
            func_0038CF68(&s1, &pv->q[4], pv->f[0x60 / 4]);
            vec_add_ab(&m->q[1], &m->q[1], &s1);
            pv->f[0x64 / 4] += 0.00136f;
            func_003C4138(&pv->f[0x60 / 4], 0.0f, pv->f[0x64 / 4]);
            if (pv->f[0x60 / 4] == 0.0f) {
                m->b[0x20] = 11;
            }
            close = 0;
            if (Is_0055B4D8(H->b + 0x19E4, 0x31) || Is_0055B4D8(H->b + 0x19E4, 0x64)
                || Is_0055B4D8(H->b + 0x19E4, 0x66)) {
                close = 1;
            }
            if (close) {
                m->b[0x20] = 11;
            }
        } else {
            reached = 0;
            *(Q_0055B4D8 *)&s1 = H->q[0x180 / 16];
            func_0038CE20(&s1, &s1, 0.98f);
            vec_add_ba(&m->q[1], &m->q[1], &s1);
            func_L01_00348160_0055B4D8(m);
            vec_sub_ab(&s1, H->b + 0x430, &m->q[1]);
            pv->f[0x64 / 4] += 0.00036f;
            pv->f[0x60 / 4] += pv->f[0x64 / 4];
            dist = func_0038CEA8(&s1);
            if (dist / pv->f[0x60 / 4] < 4.0f && m->b[0x43] != 1) {
                func_003C3A10(m, 1, 0, 4);
            }
            if (dist <= pv->f[0x60 / 4]) {
                pv->f[0x60 / 4] = dist;
                reached = 1;
            }
            func_0038CF68(&s1, &s1, pv->f[0x60 / 4]);
            vec_add_ab(&m->q[1], &m->q[1], &s1);
            if (dist / pv->f[0x60 / 4] < 3.0f && H->i[0x630 / 4] != -1) {
                s32 id;
                Snd_0055B4D8 *e;
                func_L39_0062B728(H, 2);
                H->i[0x634 / 4] = 0xD;
                id = H->i[0x2404 / 4];
                if (id != -1 && (e = &D_L39_001FE020[id], *(u8 **)&e->b[0xDC] == H->ptr[0x2524 / 4]) && e->b[0xD0] != 0) {
                    func_L39_005F3088(id);
                }
                H->i[0x2404 / 4] = -1;
            }
            close = 0;
            if (Is_0055B4D8(H->b + 0x19E4, 0x31) || Is_0055B4D8(H->b + 0x19E4, 0x64)
                || Is_0055B4D8(H->b + 0x19E4, 0x66) || dist > 32.0f) {
                close = 1;
            }
            if (reached || close) {
                s32 id;
                Snd_0055B4D8 *e;
                if (!close) {
                    func_L39_0063A030(H, 5, 0);
                }
                id = H->i[0x2404 / 4];
                if (id != -1 && (e = &D_L39_001FE020[id], *(u8 **)&e->b[0xDC] == H->ptr[0x2524 / 4]) && e->b[0xD0] != 0) {
                    func_L39_005F3088(id);
                }
                H->i[0x2404 / 4] = -1;
                func_L01_0044E740(H->b + 0x1780);
                H->b[0x46A] = 0;
                m->b[0x20] = 0;
            }
        }
        hit = 0;
        if (func_003D3CB0(&s0, &m->q[1], 2, 0, 0) != 0 && func_003D5630() != 0) {
            if (D_L39_0025F740[0x18 / 4] == 0 || func_L39_005B8928(D_L39_0025F740[0x18 / 4]) == 0) {
                hit = ((s32 *)D_L39_0025F740)[0x1C / 4] != 0;
            }
        }
        if (hit || pv->h[0x76 / 2] != 0) {
            pv->h[0x76 / 2] = 0;
            if (H->h[0x107E / 2] == 0) {
                pv->i[0x6C / 4] = 0x19;
                H->h[0x107E / 2] = 1;
                func_L39_005F33E0(2, 0, m);
            }
            if (m->b[0x20] == 10) {
                func_L39_0055B178(m, H);
                pv->f[0x60 / 4] *= 0.5f;
                m->b[0x20] = 11;
            }
        }
        k = 1.2f;
        if (m->b[0x20] == 11) {
            k = -0.37f;
        }
        {
            V4_0055B4D8 s2, s3, s4, s5, s6, s7;

            func_0038CF68(&s4, &pv->q[4], k);
            func_L01_00446760(&s1, m, 0x10001, &s4, Weap_0055B4D8(H->b, 10)->f[0x30 / 4]);
            s1.z = 1.0f;
            if (H->b[0x1A06] != 0) {
                qzero(&s1);
                func_L01_00450E48(H->ptr[0x2524 / 4], &s1, k, 0.0f, 1.0f);
            }
            ((u8 *)&s1)[0x19] = 1;
            s1.w = 5627.925f;
            ((u8 *)&s1)[0x18] = 0;
            ((u16 *)&s1)[0x1A / 2] = H->uh[0x108C / 2] + 1;
            func_003C2F58(m, 1, &s5);
            if (func_003D4D00(&s5, 0.4f, 0, H->ptr[0x2524 / 4], &s1) != 0
                || (func_003C2F58(m, 0, &s5), func_003D4D00(&s5, 0.4f, 0, H->ptr[0x2524 / 4], &s1) != 0)) {
                if (H->h[0x107E / 2] == 0 && D_L39_0025F740[0x18 / 4] != 0
                    && (D_L39_0025F740[0x18 / 4]->ptr[0x24 / 4] == 0 || ((O_0055B4D8 *)D_L39_0025F740[0x18 / 4]->ptr[0x24 / 4])->b[0x46] != 0x14)) {
                    O_0055B4D8 *q = func_00382348(D_L39_0025F740[0x18 / 4]);
                    if (q == 0 || q->h[0x1C / 2] == 0 || (O_0055B4D8 *)q->ptr[0x18 / 4] != m) {
                        *(Q_0055B4D8 *)&s7 = D_L39_0025F740[0x18 / 4]->q[1];
                        func_003C4098(&s6, &s5, &s7, 0.5f);
                        func_L39_0055AF88(&s6, 5);
                        pv->i[0x6C / 4] = 0x19;
                        H->h[0x107E / 2] = 1;
                        func_L39_005F33E0(func_L01_00337EA8(), 0, m);
                    }
                }
            }
        }
        break;
    }
    }
}
/* localdecomp:end func_L39_0055B4D8 */
