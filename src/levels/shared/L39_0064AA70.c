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

INCLUDE_ASM("asm/levels", func_L39_0064BC28);
