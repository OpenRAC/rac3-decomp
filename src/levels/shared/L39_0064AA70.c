#include "common.h"

/* localdecomp:start func_L39_0064AA70 */
#include "vu0.h"

typedef int u128_0064AA70 __attribute__((mode(TI)));

typedef union Buf_0064AA70 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_0064AA70;

typedef struct VT_0064AA70 {
    u8 pad0[0x30];
    void (*fn30)(void *);
} VT_0064AA70;

typedef struct Anim_0064AA70 {
    u8 pad0[0x41];
    u8 b41;
    u8 b42;
    u8 b43;
} Anim_0064AA70;

typedef struct Glob_0064AA70 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0064AA70;

extern Glob_0064AA70 D_001A5810;
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern s32 D_L39_00246018;

extern s32 func_L39_006384C0(void *, f32, f32, f32);
extern s32 func_L39_00638DF0(void *);
extern void func_L39_00632D78(void *, s32, f32);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern void func_L39_0062B740(void *, f32, f32, f32, f32);
extern void func_L39_00633620(void *, f32, f32);
extern void func_L39_0062D0C8(void *, f32);
extern void func_L39_00632A20(void *, void *, void *, f32);
extern void func_L39_006314E0(void *, s32);
extern void func_L39_00633748(void *);

static inline u32 Dec_0064AA70(u8 *q) {
    Buf_0064AA70 buf;
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

static inline s32 DecEq_0064AA70(u8 *q, s32 v) {
    return Dec_0064AA70(q) == v;
}

static inline s32 Busy_0064AA70(u8 *o) {
    return DecEq_0064AA70(o + 0x19E4, 1) || DecEq_0064AA70(o + 0x19E4, 0x1D) ||
           o[0x24FE] != 0 || o[0x2500] != 0;
}

static inline f32 DecF_0064AA70(u8 *q) {
    Buf_0064AA70 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
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
    return buf.f[1];
}

static inline s32 DecFEq_0064AA70(u8 *q, f32 v) {
    return DecF_0064AA70(q) == v;
}

static inline u16 Dec2_0064AA70(u8 *q) {
    Buf_0064AA70 buf;
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
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

void func_L39_0064AA70(u8 *o) {
    f32 v;
    f32 s;
    s32 a;
    s32 r;
    u8 c;

    if (DecEq_0064AA70(o + 0x19E7, 0x76) && DecEq_0064AA70(o + 0x19E4, 0x90)) {
        (*(VT_0064AA70 **)(o + 0x14))->fn30(o);
        return;
    }
    func_L39_006384C0(o, 3.7f, 0.0f, 0.35f);
    if (D_001A5810.bA4[*(s32 *)(o + 0x2544)] != 0 ||
        ((c = Busy_0064AA70(o)) != 0 && (o[0x1A0A] != 0 || o[0x1A14] == 0))) {
        *(u128_0064AA70 *)(o + 0xFC0) = *(u128_0064AA70 *)(o + 0x11A0);
        *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x11E0);
    } else if (*(s16 *)(o + 0x3E4) != 0) {
        *(u128_0064AA70 *)(o + 0xFC0) = *(u128_0064AA70 *)(o + 0x23C0);
        *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x23B8);
    } else {
        func_L39_00632D78(o, 0, 1.0f);
    }
    if (DecEq_0064AA70(o + 0x19E4, 3)) {
        if (func_L39_00638DF0(o) != 0) {
            return;
        }
    }
    if (o[0x24FE] == 0 && *(s16 *)(o + 0x320) == 0) {
        if (DecEq_0064AA70(o + 0x19E4, 4) || DecEq_0064AA70(o + 0x19E4, 1) ||
            DecEq_0064AA70(o + 0x19E4, 0x1D) || o[0x24FD] != 0) {
            if (DecEq_0064AA70(o + 0x19E4, 4)) {
                func_L39_00633308(o, 0, 0.00288000028f, 0.100800008f, 0.139626354f);
            } else {
                func_L39_00633308(o, 0, 0.0532800034f, 0.187199995f, 0.244346097f);
            }
            v = *(f32 *)(o + 0xFD4);
            if (0.00698131742f < fabs_asm(v)) {
                a = v < 0.0f;
                if (DecEq_0064AA70(o + 0x19E4, 4) || o[0x24FD] != 0) {
                    a += 14;
                } else {
                    a = 3;
                }
                if ((*(Anim_0064AA70 **)(o + 0x2524))->b43 != a &&
                    ((*(Anim_0064AA70 **)(o + 0x2524))->b43 != 40 || 21.0f <= *(f32 *)(o + 0x628))) {
                    r = 7;
                    if (DecFEq_0064AA70(o + 0x2476, 1.0f)) {
                        r = 10;
                    }
                    if (DecEq_0064AA70(o + 0x19EA, 0x22) || DecEq_0064AA70(o + 0x19E7, 0x22)) {
                        r = 12;
                    }
                    if (DecEq_0064AA70(o + 0x19EA, 0x85) || DecEq_0064AA70(o + 0x19E7, 0x85)) {
                        r = 12;
                    }
                    if (DecEq_0064AA70(o + 0x19E7, 0x13)) {
                        r = 11;
                    }
                    if (DecEq_0064AA70(o + 0x19EA, 6) || DecEq_0064AA70(o + 0x19EA, 0x2C)) {
                        r = 15;
                    }
                    if (DecEq_0064AA70(o + 0x19EB, 4) && o[0x14AC] >= 5) {
                        r = 11;
                    }
                    if (a == 3) {
                        func_L39_0062B4A8(o, 3, D_L39_00246018, 0, r);
                    } else {
                        func_L39_0062B4A8(o, a, 0, 0, r);
                    }
                    *(f32 *)(o + 0x610) = fabs_asm(*(f32 *)(o + 0xFD4)) * 5.0f / 6.0f / 0.0663225204f;
                    if (*(f32 *)(o + 0x610) < 0.55f) {
                        *(f32 *)(o + 0x610) = 0.55f;
                    }
                    if (2.5f < *(f32 *)(o + 0x610)) {
                        *(f32 *)(o + 0x610) = 2.5f;
                    }
                }
            } else if (v == 0.0f && o[0x1A07] == 0) {
                if (DecEq_0064AA70(o + 0x19E4, 4) || o[0x24FD] != 0) {
                    a = 13;
                } else {
                    a = 0;
                }
                if ((*(Anim_0064AA70 **)(o + 0x2524))->b43 != a) {
                    func_L39_0062B4A8(o, a, 0, 0, 6.0f);
                }
            }
        }
    }
    *(s32 *)(o + 0xFB0) = 0;
    if (DecEq_0064AA70(o + 0x19E4, 3)) {
        f32 t = *(f32 *)(o + 0x1AC) + 1.0f;
        Anim_0064AA70 *an;
        if (1.0f < t) {
            t = 1.0f;
        }
        s = t * 0.0108000003f;
        *(f32 *)(o + 0x2484) = s;
        an = *(Anim_0064AA70 **)(o + 0x2524);
        if (an->b42 == an->b43) {
            f32 q = *(f32 *)(o + 0x1A4) / s;
            if (4.0f < q && (f32)an->b41 < 5.5f) {
                func_L39_0062B740(o, 13.0f, q, 0.5f, -1.0f);
                if (1.1f < *(f32 *)(o + 0x610)) {
                    *(f32 *)(o + 0x610) = 1.1f;
                }
            } else if (6.5f < (f32)(*(Anim_0064AA70 **)(o + 0x2524))->b41) {
                *(f32 *)(o + 0x610) = 1.0f;
            }
        }
    } else if (DecEq_0064AA70(o + 0x19E4, 4) || o[0x24FD] != 0) {
        s = 0.0108000003f;
    } else {
        s = 0.00708000083f;
    }
    func_L39_00633620(o, 0.0f, s);
    qzero(o + 0x120);
    func_L39_0062D0C8(o, s);
    if (o[0x377] != 0 && (Dec2_0064AA70(o + 0x1A40) >> 14) & 1) {
        if (0.2f < *(f32 *)(o + 0x2AC)) {
            func_L39_00632A20(o, o + 0x120, o + 0x150, 0.00879999995f);
            return;
        }
        func_L39_00632A20(o, o + 0x120, o + 0x120, 0.0216000006f);
        if (*(s32 *)(o + 0x2CC) != 0) {
            *(u128_0064AA70 *)(o + 0xA0) = *(u128_0064AA70 *)(o + 0x260);
            *(f32 *)(o + 0x2AC) = 0.0f;
            *(s16 *)(o + 0x2DE) = 0;
        }
        return;
    }
    func_L39_006314E0(o, 0);
    if (*(s16 *)(o + 0x2DE) != 0) {
        func_L39_00632A20(o, o + 0x120, o + 0x160, 0.0100000007f);
        func_L39_00633748(o);
    } else {
        func_L39_00632A20(o, o + 0x120, o + 0x120, 0.0216000006f);
    }
}
/* localdecomp:end func_L39_0064AA70 */

/* localdecomp:start func_L39_0064BC28 */
#include "vu0.h"

typedef struct Q_0064BC28 {
    f32 x, y, z, w;
} Q_0064BC28 __attribute__((aligned(16)));

typedef struct Self_0064BC28 {
    u8 pad0[0x20 - 0x0];
    /* 0x20 */ Q_0064BC28 q20;
    u8 pad30[0xA8 - 0x30];
    /* 0xA8 */ f32 fA8;
    u8 padAC[0xB8 - 0xAC];
    /* 0xB8 */ f32 fB8;
    u8 padBC[0x120 - 0xBC];
    /* 0x120 */ f32 f120;
    u8 pad124[0x160 - 0x124];
    /* 0x160 */ f32 f160;
    u8 pad164[0x1A4 - 0x164];
    /* 0x1A4 */ f32 f1A4;
    u8 pad1A8[0x2C0 - 0x1A8];
    /* 0x2C0 */ f32 f2C0;
    u8 pad2C4[0x2C8 - 0x2C4];
    /* 0x2C8 */ s32 w2C8;
    u8 pad2CC[0x2DE - 0x2CC];
    /* 0x2DE */ s16 h2DE;
    u8 pad2E0[0x324 - 0x2E0];
    /* 0x324 */ s32 w324;
    u8 pad328[0x33A - 0x328];
    /* 0x33A */ s16 h33A;
    u8 pad33C[0x3D0 - 0x33C];
    /* 0x3D0 */ Q_0064BC28 q3D0;
    u8 pad3E0[0x3E4 - 0x3E0];
    /* 0x3E4 */ s16 h3E4;
    /* 0x3E6 */ u8 b3E6;
    u8 pad3E7[0x3E8 - 0x3E7];
    /* 0x3E8 */ f32 f3E8;
    u8 pad3EC[0x474 - 0x3EC];
    /* 0x474 */ s32 w474;
    /* 0x478 */ s32 w478;
    u8 pad47C[0xFB0 - 0x47C];
    /* 0xFB0 */ f32 fFB0;
    u8 padFB4[0xFC0 - 0xFB4];
    /* 0xFC0 */ Q_0064BC28 qFC0;
    /* 0xFD0 */ f32 fFD0;
    u8 padFD4[0xFD8 - 0xFD4];
    /* 0xFD8 */ f32 fFD8;
    u8 padFDC[0x1310 - 0xFDC];
    /* 0x1310 */ s32 w1310;
    u8 pad1314[0x1410 - 0x1314];
    /* 0x1410 */ Q_0064BC28 q1410;
    u8 pad1420[0x1428 - 0x1420];
    /* 0x1428 */ f32 f1428;
    /* 0x142C */ u8 b142C;
    u8 pad142D[0x142F - 0x142D];
    /* 0x142F */ u8 b142F;
    /* 0x1430 */ s32 w1430;
    u8 pad1434[0x15A0 - 0x1434];
    /* 0x15A0 */ Q_0064BC28 q15A0;
    /* 0x15B0 */ f32 f15B0;
    u8 pad15B4[0x19E4 - 0x15B4];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 b19E5;
    u8 pad19E6[0x1A05 - 0x19E6];
    /* 0x1A05 */ u8 b1A05;
    /* 0x1A06 */ u8 b1A06;
    u8 pad1A07[0x2468 - 0x1A07];
    /* 0x2468 */ f32 f2468;
    u8 pad246C[0x248C - 0x246C];
    /* 0x248C */ f32 f248C;
    u8 pad2490[0x2534 - 0x2490];
    /* 0x2534 */ s32 p2534;
} Self_0064BC28;

typedef union Buf_0064BC28 {
    u8 b[16];
    u32 w[4];
} Buf_0064BC28;

extern u8 D_L39_004997E0[];

extern void func_L39_00647C48(u8 *state, s32 period, s32 threshold);
extern void func_L39_00647E10(u8 *state, s32 period, s32 threshold);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L01_00460818(s32, s32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_00633160(void *);
extern void func_L31_004F3CA0_0064BC28(void *, f32, f32);
extern f32 func_L39_00632818(void *, void *);
extern void func_L39_00637D38(u8 *g);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_00633428(void *);
extern void func_L39_00633CF8(void *);
extern void func_L30_004F4800_0064BC28(void *);
extern void func_L39_00633670(u8 *self, f32 angle);
extern void func_L39_00633728(void *, void *);
extern void func_L39_006314E0(void *, s32);
extern void func_L39_00633748(void *);

/* reads a protected 32-bit value stored as an index byte at q */
static __inline__ u32 get_state_0064BC28(u8 *q) {
    u32 dec;

    if (*q == 0) {
        dec = 0;
    } else {
        Buf_0064BC28 buf;
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
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    return dec;
}

void func_L39_0064BC28(Self_0064BC28 *s) {
    s32 c;
    f32 d;
    f32 scale;
    f32 a0;
    f32 a1;
    f32 r;

    c = 0;
    d = s->f2C0 - s->fA8;
    if (s->w2C8 != 0 && d < 0.25f) {
        c = 1;
    }
    if (d < 0.5f || c != 0) {
        if (0.020000001f < s->f1A4) {
            func_L39_00647C48((u8 *)s, 0, 2);
        }
        if (0.010000001f < s->f1A4) {
            func_L39_00647E10((u8 *)s, 2, 4);
        }
    }
    if (!((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_006212E8(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
        f32 x;

        if (s->f1A4 < 0.034f) {
            s->b142C = 1;
            if (2.0943952f < fabs_asm(s->fFD8) && s->f2468 == 1.0f) {
                s->b142F = 1;
            }
        }
        x = func_L01_00460818(1, s->p2534);
        if (1.9198622f < func_0038DBA0(x, func_L01_00460818(7, s->p2534)) &&
            1.2217305f < fabs_asm(s->fFD8) && s->f2468 == 1.0f) {
            s->b142F = 1;
            s->b142C = 1;
        }
        if (fabs_asm(s->fFD8) < 0.08726646f) {
            s->b142C = 0;
        }
    }
    if (s->w324 < 2 && 1.5707964f < fabs_asm(s->fFD8) && s->b3E6 != 0) {
        s->b142F = 1;
        s->b142C = 1;
    }
    if (s->b142F != 0 && fabs_asm(s->fFD8) < 0.06981317f) {
        s->b142F = 0;
    }
    if (s->f2468 < 0.2f) {
        if (s->w1430 != 0) {
            s->b142F = 1;
        }
        s->qFC0 = s->q1410;
        s->fFD0 = s->f1428;
        s->fFB0 = 0.0f;
    } else {
        s32 v;

        func_L39_00633160(s);
        v = -1;
        if (s->w474 == 2) {
            v = s->w478;
        }
        if (v == 10 && (s->f248C == 1.0f || s->w1430 != 0) && s->b1A05 == 0) {
            s->q1410 = s->qFC0;
            s->f1428 = s->fFD0;
            s->w1430 = 1;
        } else {
            s->q1410 = s->q20;
            s->f1428 = s->fB8;
        }
    }
    if (0.0f < s->f15B0) {
        func_L31_004F3CA0_0064BC28(s, 0.7f, 0.0f);
        {
            Q_0064BC28 tmp;

            tmp = s->q15A0;
            s->fFB0 = s->fFB0 + func_L39_00632818(s, &tmp);
        }
        if (s->fFB0 < 0.014f) {
            s->fFB0 = 0.014f;
        }
        qzero(&s->q15A0);
    }
    scale = 1.0f;
    if (((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_006212E8(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
        func_L39_00637D38((u8 *)s);
    } else {
        s->f3E8 = s->fB8;
        s->q3D0 = s->q20;
        if ((get_state_0064BC28(&s->b19E5) ^ 1) == 0 && s->b142F == 0 && s->b1A05 == 0) {
            func_L39_00633308(s, 0, 0.053280003f, 0.1872f, 0.2443461f);
        } else {
            f32 a = fabs_asm(s->fFD8);

            if (s->f2468 < 0.9f || (s->b1A05 != 0 && s->b142F == 0)) {
                if (0.7853982f < a) {
                    scale = 0.0f;
                }
            }
            func_L39_00633428(s);
        }
    }
    func_L39_00633CF8(s);
    func_L30_004F4800_0064BC28(s);
    if (s->b142F != 0) {
        f32 lim = 0.14500001f - fabs_asm(s->fFD8) * 0.11000001f / 3.1415927f;

        if (lim < 0.0f) {
            lim = 0.0f;
        }
        if (lim < s->fFB0) {
            s->fFB0 = lim;
        }
    }
    a0 = scale * 0.014800001f;
    a1 = 0.012f;
    if (s->b142F != 0) {
        f32 k = 2.6179938f - s->fFD8;

        if (1.0f < k) {
            k = 1.0f;
        }
        if (k < 0.2f) {
            k = 0.2f;
        }
        s->fFB0 = s->fFB0 * k;
        a1 = 0.0068000006f;
    }
    r = fabs_asm(s->fFD8);
    if (s->f2468 < 0.75f && 0.61086524f < r) {
        f32 k = 1.0f - r * 0.4f;

        if (k < 0.0f) {
            k = 0.0f;
        }
        s->fFB0 = s->fFB0 * k;
    }
    func_L39_00633620((u8 *)s, a0, a1);
    if (s->b142C != 0 || ((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_006212E8(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
        if (s->b1A06 == 0) {
            func_L39_00633670((u8 *)s, ((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_006212E8(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0) ? s->f3E8 : s->fFD0);
        } else if (((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_006212E8(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
            func_L39_00633728(s, &s->q3D0);
        } else {
            func_L39_00633728(s, &s->qFC0);
        }
    } else {
        func_L39_00633670((u8 *)s, 99999.0f);
    }
    func_L39_006314E0(s, 0);
    if (s->h33A != 0) {
        func_L39_006384C0(s, 5.0f, 0.2f, 0.35f);
    }
    if (s->h2DE != 0) {
        func_L39_00632A20(s, &s->f120, &s->f160, 0.010000001f);
        func_L39_00633748(s);
    } else {
        func_L39_00632A20(s, &s->f120, &s->f120, 0.0216f);
    }
}
/* localdecomp:end func_L39_0064BC28 */
