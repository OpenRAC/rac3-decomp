#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

/* declared by functions of L39_0062D7C8.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);

/* localdecomp:start func_L39_00630548 */
#include "vu0.h"

typedef union Buf_00630548 {
    u8 b[8];
    u32 w[2];
    u128_t q;
    f32 f[4];
} Buf_00630548;

typedef struct T1_00630548 {
    u8 pad0[0x1E];
    u16 h1E;
} T1_00630548;

typedef struct T2_00630548 {
    u8 pad0[0x3C];
    s32 w3C;
} T2_00630548;

typedef struct G_00630548 {
    u8 pad0[0x18];
    void *p18;
    s32 s1C;
    Vec4 v20;
    u8 pad30[0x10];
    Vec4 v40;
} G_00630548;

typedef struct Self_00630548 {
    /* 0x000 */ u8 pad0[0xA0];
    /* 0x0A0 */ Vec4 vA0;
    /* 0x0B0 */ u8 padB0[0xD0 - 0xB0];
    /* 0x0D0 */ Vec4 vD0;
    /* 0x0E0 */ u8 padE0[0x1F4 - 0xE0];
    /* 0x1F4 */ f32 f1F4;
    /* 0x1F8 */ u8 pad1F8[0x230 - 0x1F8];
    /* 0x230 */ Vec4 v230;
    /* 0x240 */ Vec4 v240;
    /* 0x250 */ Vec4 v250;
    /* 0x260 */ Vec4 v260;
    /* 0x270 */ Vec4 v270;
    /* 0x280 */ Vec4 v280;
    /* 0x290 */ f32 f290[2];
    /* 0x298 */ f32 f298[2];
    /* 0x2A0 */ f32 f2A0[2];
    /* 0x2A8 */ f32 f2A8;
    /* 0x2AC */ f32 f2AC;
    /* 0x2B0 */ f32 f2B0;
    /* 0x2B4 */ f32 f2B4;
    /* 0x2B8 */ f32 f2B8;
    /* 0x2BC */ f32 f2BC;
    /* 0x2C0 */ f32 f2C0;
    /* 0x2C4 */ f32 f2C4;
    /* 0x2C8 */ s32 s2C8;
    /* 0x2CC */ void *p2CC;
    /* 0x2D0 */ s32 s2D0;
    /* 0x2D4 */ s32 s2D4;
    /* 0x2D8 */ s16 h2D8;
    /* 0x2DA */ s16 h2DA;
    /* 0x2DC */ s16 h2DC;
    /* 0x2DE */ s16 h2DE;
    /* 0x2E0 */ u8 pad2E0[0x370 - 0x2E0];
    /* 0x370 */ s16 h370;
    /* 0x372 */ u8 pad372[0x37B - 0x372];
    /* 0x37B */ u8 b37B;
    /* 0x37C */ u8 pad37C[0x420 - 0x37C];
    /* 0x420 */ void *p420;
    /* 0x424 */ u8 pad424[0x14AC - 0x424];
    /* 0x14AC */ u8 b14AC;
    /* 0x14AD */ u8 pad14AD[0x1620 - 0x14AD];
    /* 0x1620 */ s32 s1620;
    /* 0x1624 */ u8 pad1624[0x19E4 - 0x1624];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 pad19E5;
    /* 0x19E6 */ u8 b19E6;
    /* 0x19E7 */ u8 pad19E7[0x1A06 - 0x19E7];
    /* 0x1A06 */ u8 b1A06;
    /* 0x1A07 */ u8 pad1A07[0x1A14 - 0x1A07];
    /* 0x1A14 */ u8 b1A14;
    /* 0x1A15 */ u8 pad1A15[0x2524 - 0x1A15];
    /* 0x2524 */ s32 s2524;
    /* 0x2528 */ u8 pad2528[0x2544 - 0x2528];
    /* 0x2544 */ s32 s2544;
} Self_00630548;

__asm__(".extern D_L39_0024112C, 16");
extern s32 D_L39_0024112C;
extern G_00630548 D_L39_0025F740;
extern u8 D_L39_004997E0[];

extern void func_L39_006318E8(void *, Vec4 *, Vec4 *, s32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_003FE908(void);
extern s32 func_003D5630(void);
extern f32 func_003C3EC8(void *, void *);
extern s32 func_L39_005B8928(void *);
extern T1_00630548 *func_00382348(void *);
extern T2_00630548 *func_003C4D58(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0013D528(void *, void *);
extern f32 func_L39_00632100(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_006321F0(void *, void *, f32, f32, f32, s32);

static __inline__ u32 decode_00630548(u8 *q, Buf_00630548 *buf) {
    u32 dec;

    if (*q == 0) {
        dec = 0;
    } else {
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf->b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf->w[0] ^ (u32)q;
        b = buf->w[1] ^ a;
        buf->w[0] = a;
        buf->w[1] = b;
        dec = b;
    }
    return dec;
}

void func_L39_00630548(u8 *p) {
    Self_00630548 *s = (Self_00630548 *)p;
    Vec4 v0;
    Vec4 v10;
    Buf_00630548 buf;
    Vec4 v30;
    Vec4 v40;
    f32 ang[2];
    Vec4 v60;
    u32 dec;
    f32 r;
    s32 i;
    Vec4 *dir;
    s32 eq;

    qzero(&s->v260);
    s->h2DE++;
    s->h2DC++;
    s->v230.f[0] = 0.0f;
    s->v230.f[1] = 0.0f;
    s->v230.f[2] = 1.0f;
    s->f2AC = 32.0f;
    s->f2B0 = 0.0f;
    s->f2A8 = 0.0f;
    s->h2DA = 0;
    s->p2CC = 0;
    if (s->s2C8 != 0) {
        s->s2C8++;
    }
    r = s->f1F4 * 2.2f;
    eq = decode_00630548(&s->b19E6, &buf) == 2;
    if (eq) {
        r = s->f1F4 * 2.9f;
    }
    func_L39_006318E8(s, &v10, &v0, 1, r, -32.0f);
    dir = &s->v250;
    if (func_003D3CB0(&v10, &v0, 2, s->s2524, 0) == 0) {
        goto end;
    }
    s->b37B = func_L01_003FE908();
    if (D_L39_0025F740.p18 != 0) {
        s->b37B = 0;
    }
    s->h370 = func_003D5630();
    if (s->h370 == 0) {
        s->f2C0 = func_003C3EC8(&D_L39_0025F740.v20, &s->v240);
        if (s->vA0.f[2] < s->f2C0 && s->s2C8 <= 0) {
            s->s2C8 = 1;
        }
        if (func_003D3CB0(&v10, &v0, 0x24, s->s2524, 0) == 0) {
            goto end;
        }
        s->b37B = func_L01_003FE908();
    }
    if (s->h370 == 13) {
        s->f2C0 = D_L39_0025F740.v20.f[2];
        v10.f[2] = D_L39_0025F740.v20.f[2] - 0.01f;
        if (func_003D3CB0(&v10, &v0, 4, s->s2524, 0) == 0) {
            goto end;
        }
    }
    if (s->h370 == 11) {
        s->f2C4 = D_L39_0025F740.v20.f[2];
    } else {
        if (D_L39_0025F740.p18 != 0) {
            T1_00630548 *t1;
            T2_00630548 *t2;

            if (func_L39_005B8928(D_L39_0025F740.p18) != 0) {
                s->h2DA = 1;
            }
            t1 = func_00382348(D_L39_0025F740.p18);
            if (t1 != 0 && (t1->h1E & 8)) {
                s->h2DA = 1;
            }
            t2 = func_003C4D58(D_L39_0025F740.p18);
            if (t2 != 0 && (t2->w3C & 8)) {
                s->h2DA = 1;
            }
        }
        if (D_L39_0025F740.s1C > 0) {
            s->v260.q = D_L39_0025F740.v20.q;
            s->f2A8 = D_L39_0025F740.v20.f[2];
            s->f2AC = func_0038CF00(&s->vA0, &s->v260);
            s->p2CC = D_L39_0025F740.p18;
            func_0013D528(&s->v230, &D_L39_0025F740.v40);
            s->f2B0 = func_L39_00632100(s, &D_L39_0025F740.v40);
            s->f2BC = func_0038D160(D_L39_0025F740.v40.f[0], D_L39_0025F740.v40.f[1]);
            vec_sub_ab(&buf, &s->v260, &s->vA0);
            if (0.0f < func_0038CE68(&buf, &s->v230)) {
                s->f2AC = -s->f2AC;
            }
            if (s->f2AC < 0.02f) {
                s->h2DC = 0;
                if (s->f2B0 <= 0.87266463f || s->b1A06 != 0) {
                    s->h2DE = 0;
                    s->p420 = D_L39_0025F740.p18;
                }
            }
        }
    }
end:
    if (s->vA0.f[2] > s->f2C0) {
        s->s2C8 = 0;
    }
    if (s->h2DE != 0) {
        s->s2D0 = 0;
    } else {
        s->s2D0++;
        s->v270.q = s->v260.q;
        eq = decode_00630548(&s->b19E4, &buf) == 0x38;
        if (!eq) {
            s->s1620 = 0;
        }
    }
    qzero(&s->v250);
    switch (s->b1A06) {
    case 0:
        s->v250.f[2] = -1.0f;
        break;
    case 1:
        if (s->v280.f[3] != 0.0f) {
            func_003C4138(&s->v280.f[3], 0.0f, 1.0f);
            s->v250.q = s->v280.q;
        } else {
            s->v250.q = s->v230.q;
            func_0038CE20(dir, dir, -1.0f);
        }
        break;
    case 2:
        r = -1.0f;
        if (0.0f < s->vD0.f[3]) {
            r = 1.0f;
        }
        vec_sub_ab(&s->v250, &s->vD0, &s->vA0);
        func_0038CF68(dir, dir, r);
        break;
    }
    s->f2B4 = 0.0f;
    s->f2B8 = 0.0f;
    s->f2A0[0] = 0.0f;
    s->f2A0[1] = 0.0f;
    s->f298[0] = 0.0f;
    s->f298[1] = 0.0f;
    s->f290[0] = 0.0f;
    s->f290[1] = 0.0f;
    if (s->b1A14 == 0 && s->s2544 != (D_L39_0024112C & 7)) {
        return;
    }
    if (s->h2D8 == 1) {
        return;
    }
    if (!(s->f2AC < 0.25f)) {
        return;
    }
    eq = decode_00630548(&s->b19E6, &buf) == 0;
    if (!eq) {
        eq = decode_00630548(&s->b19E6, &buf) == 12;
        if (!eq) {
            eq = decode_00630548(&s->b19E6, &buf) == 9;
            if (!eq) {
                eq = decode_00630548(&s->b19E6, &buf) == 7;
                if (!eq) {
                    eq = decode_00630548(&s->b19E6, &buf) == 4;
                    if (!eq || s->b14AC == 0) {
                        eq = decode_00630548(&s->b19E6, &buf) == 1;
                        if (!eq) {
                            return;
                        }
                    }
                }
            }
        }
    }
    func_L39_006304A8(p, &s->v230, buf.f);
    if (-0.7853982f < buf.f[1] && buf.f[1] < 0.7853982f) {
        s->f2B4 = buf.f[1];
    }
    if (-0.7853982f < buf.f[0] && buf.f[0] < 0.7853982f) {
        s->f2B8 = buf.f[0];
    }
    for (i = 0; i < 2; i++) {
        f32 yaw = 1.5707964f;

        if (i == 1) {
            yaw = -yaw;
        }
        func_L39_006321F0(s, &v30, 0.2f, yaw, 0.45f, 1);
        func_L39_006321F0(s, &v40, 0.2f, yaw, -0.45f, 1);
        if (func_003D3CB0(&v30, &v40, 0x22, s->s2524, 0) != 0) {
            f32 d = D_L39_0025F740.v20.f[2] - s->f2A8;

            s->f290[i] = d;
            if (0.4f < fabs_asm(d)) {
                s->f290[i] = 0.0f;
            }
            func_0013D528(&v60, &D_L39_0025F740.v40);
            func_L39_006304A8(p, &v60, ang);
            if (-0.7853982f < ang[1] && ang[1] < 0.7853982f) {
                s->f298[i] = ang[1];
            }
            if (-0.7853982f < ang[0] && ang[0] < 0.7853982f) {
                s->f2A0[i] = ang[0];
            }
        } else {
            s->f290[i] = 0.0f;
            s->f298[i] = s->f2B4;
            s->f2A0[i] = s->f2B8;
        }
    }
}
/* localdecomp:end func_L39_00630548 */
