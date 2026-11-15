#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* declared by functions of L39_00662678.c, which this file was cut from */
extern void func_0038CC88(void *dst, void *src, s32 n);

/* localdecomp:start func_L39_00662C90 */
#include "vu0.h"
extern s32 D_001D5A1C_sda;
extern u8 D_L39_004997E0[];
extern void func_L39_005BA418(void *, void *);
extern void func_L39_00665CF8(u8 *o, s32 cmd);
extern s32 func_L02_003E71A8(f32, void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_00637120(u8 *o, s32 id, s32 limit);
extern s32 func_L39_00636F30(u8 *o, s32 id, s32 limit);
extern s32 func_L01_0040E6B8(void *, void *, f32);
extern void func_L39_00663900(u8 *a0);
extern void func_L39_0063BF40(u8 *);
extern s32 func_L39_005C42E8(s32, s32);
extern f32 func_L39_00647588(u8 *, f32 *);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);

/* a scratch quadword: the obfuscated-value getter's byte buffer, then a vector */
typedef union S_00662C90 {
    u8 b[16];
    u32 w[4];
    vu0_v4 v;
} S_00662C90;

void func_L39_00662C90(u8 *o) {
    u8 *a = *(u8 **)(o + 0x2558);
    u8 *q = *(u8 **)(a + 0xC44);
    u8 *t;
    S_00662C90 sc;
    u8 idx;
    u8 *pad;
    s32 v;

    t = (q != 0 && (a[0xC42] == 0 || D_001D5A1C_sda - *(s32 *)(a + 0xC3C) >= *(s8 *)(a + 0xC41))) ? q : 0;
    if (t == 0) {
        return;
    }
    idx = (*(u8 **)(o + 0x2558))[0xC31];
    if (idx == 0) {
        f32 s = 0.015625f;
        o[0x4D21] = 0;
        *(f32 *)(o + 0x4D30) = (f32)*(u16 *)(t + 0x10) * s;
        *(f32 *)(o + 0x4D34) = (f32)*(u16 *)(t + 0x12) * s;
        *(f32 *)(o + 0x4D38) = (f32)*(u16 *)(t + 0x14) * s;
        *(s32 *)(o + 0x4D3C) = 0;
        if (*(u32 *)(t + 0x14) & 0x1000000) {
            u32 tmp;
            u8 c;
            func_0038CC88(&tmp, t + 0x68, 4);
            func_L39_005BA418(o + 0x4D60, &tmp);
            *(s32 *)(o + 0x4D6C) = 0;
            c = t[0x6C];
            *(s32 *)(o + 0x4D8C) = c;
            func_0038CC88(o + 0x4D30, t + 0x6D, 12);
            if (o[0x4D24] != c) {
                func_L39_00665CF8(o, c);
            }
        } else {
            *(f32 *)(o + 0x4D6C) = 1.0f;
        }
        if (o[0x4D20] != 0 && o[0x4D23] == 0 && *(s32 *)(o + 0x4D88) == (t[0x16] + 255) % 256) {
            f32 r = 0.04f;
            if (*(u32 *)(t + 0x14) & 0x1000000) {
                r = 0.03f;
            }
            vec_sub_ab(o + 0x4D50, o + 0x4D30, o + 0x4D40);
            if (func_L02_003E71A8(r, o + 0x4D40, o + 0x4D30) == 0) {
                o[0x4D23] = 4;
            }
            if (*(f32 *)(o + 0x4D6C) == 0.0f) {
                f32 ang = func_0038DBA0(*(f32 *)(o + 0x4D78), *(f32 *)(o + 0x4D68));
                *(f32 *)(o + 0x4D80) = ang;
                if (ang > 114.591553f) {
                    o[0x4D21] = 1;
                }
            }
        }
    }
    func_0038CC88(*(u8 **)(o + 0x2558) + 0xC4C, t + (idx * 20 + 0x18), 20);
    if ((*(u32 *)(t + 0x14) & 0xC000000) == 0x4000000) {
        func_0038CC88(*(u8 **)(o + 0x2558) + 0xC50, t + idx * 2, 2);
        *(u32 *)(*(u8 **)(o + 0x2558) + 0x1AC) |= 4;
    } else {
        *(u32 *)(*(u8 **)(o + 0x2558) + 0x1AC) &= ~4;
    }
    if (o[0x4D23] != 0) {
        o[0x4D23]--;
        if ((({
                u8 *g = o + 0x19E4;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x31) != 0 && func_0038CEA8(o + 0x4D50) > 6.0f) {
            func_L39_00637EC8(o, o + 0x4D30, o + 0x4D60, -1, 0, 0, 0);
            o[0x4D23] = 0;
        } else if ((({
                u8 *g = o + 0x19E4;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x2C) == 0 || (({
                u8 *g = o + 0x19E6;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0xE) == 0) {
            vec_sub_ab(&sc.v, o + 0xA0, o + 0x4D30);
            func_0038CE20(&sc.v, &sc.v, -1.0f / (f32)(5 - idx));
            *(vu0_q *)(o + 0x15A0) = *(vu0_q *)&sc.v;
            if (*(f32 *)(o + 0x15A8) > 0.015f) {
                *(f32 *)(o + 0x15A8) = 0.015f;
            } else if (*(f32 *)(o + 0x15A8) < -0.015f) {
                *(f32 *)(o + 0x15A8) = -0.015f;
            }
        } else if ((({
                u8 *g = o + 0x19E6;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 7) == 0 || (({
                u8 *g = o + 0x19E6;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 2) == 0) {
            func_0038CE20(&sc.v, o + 0x4D50, 0.25f);
            *(vu0_q *)(o + 0x15A0) = *(vu0_q *)&sc.v;
            if (*(f32 *)(o + 0x15A8) > 0.015f) {
                *(f32 *)(o + 0x15A8) = 0.015f;
            } else if (*(f32 *)(o + 0x15A8) < -0.015f) {
                *(f32 *)(o + 0x15A8) = -0.015f;
            }
        } else if ((({
                u8 *g = o + 0x19E6;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x14) == 0) {
            o[0x4D23] = 0;
        } else if (func_L39_00637120(o, 0x14, 10) != 0) {
            o[0x4D23] = 0;
        } else if ((({
                u8 *g = o + 0x19E4;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x7E) == 0) {
            o[0x4D23] = 0;
        } else if ((({
                u8 *g = o + 0x19E4;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x7A) == 0) {
            o[0x4D23] = 0;
        } else if ((({
                u8 *g = o + 0x19E4;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x90) == 0) {
            o[0x4D23] = 0;
        } else if ((({
                u8 *g = o + 0x19E4;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 0x31) == 0) {
            o[0x4D23] = 0;
        } else if (func_L39_00636F30(o, 0x7E, 10) != 0) {
            o[0x4D23] = 0;
        } else if (func_L39_00636F30(o, 0x7A, 10) != 0) {
            o[0x4D23] = 0;
        } else if (func_L39_00636F30(o, 0x31, 10) != 0) {
            o[0x4D23] = 0;
        } else if (func_L39_00636F30(o, 0x90, 10) != 0) {
            o[0x4D23] = 0;
        } else if (func_L39_00636F30(o, 0x8F, 0x5A) != 0) {
            o[0x4D23] = 0;
        } else if ((({
                u8 *g = o + 0x19E6;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 4) != 0 && (({
                u8 *g = o + 0x19E6;
                u32 x;
                if (*g == 0) {
                    x = 0;
                } else {
                    s32 n = *g;
                    s32 m = n + 1;
                    s32 k = ((s32)g - n) & 7;
                    u8 *d = sc.b;
                    s32 i;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    sc.w[0] ^= (u32)g;
                    sc.w[1] ^= sc.w[0];
                    x = sc.w[1];
                }
                x;
        }) ^ 6) != 0
                   && func_L39_00636F30(o, 0x16, 10) == 0
                   && func_L39_00637120(o, 4, 10) == 0
                   && func_L39_00637120(o, 6, 10) == 0) {
            func_0038CE20(&sc.v, o + 0x4D50, 0.25f);
            *(vu0_q *)(o + 0x4D90) = *(vu0_q *)&sc.v;
            if (*(f32 *)(o + 0x4D98) > 0.015f) {
                *(f32 *)(o + 0x4D98) = 0.015f;
            } else if (*(f32 *)(o + 0x4D98) < -0.015f) {
                *(f32 *)(o + 0x4D98) = -0.015f;
            }
        } else {
            func_0038CE20(&sc.v, o + 0x4D50, 0.25f);
            sc.v.z = 0.0f;
            func_L01_0040E6B8(&sc.v, &sc.v, 0.15f);
            *(vu0_v4 *)(o + 0x15A0) = sc.v;
        }
    }
    func_L39_00663900(o);
    func_L39_0063BF40(o);
    if ((*(s32 *)(*(u8 **)(o + 0x2534) + 0x1A0) & func_L39_005C42E8(4, *(s32 *)(o + 0x2544))) == 0) {
        *(s16 *)(o + 0x338) = 0;
    }
    if (*(s32 *)(*(u8 **)(o + 0x2534) + 0x1D4) != 0) {
        *(s32 *)(o + 0x300) = 0;
        (*(s32 *)(o + 0x304))++;
    } else {
        *(s32 *)(o + 0x304) = 0;
        (*(s32 *)(o + 0x300))++;
    }
    *(f32 *)(o + 0x110) = *(f32 *)(*(u8 **)(o + 0x2534) + 0x108);
    *(f32 *)(o + 0x114) = -*(f32 *)(*(u8 **)(o + 0x2534) + 0x10C);
    *(f32 *)(o + 0x248C) = func_L39_00647588(o, (f32 *)(o + 0x110));
    if (func_0038CED8((f32 *)(o + 0x110)) < 0.25f) {
        s32 b;
        s32 tt;
        pad = *(u8 **)(o + 0x2534);
        tt = ((*(s32 *)(pad + 0x1B0) >> 13) & 1) - ((*(s32 *)(pad + 0x1B0) >> 15) & 1);
        *(f32 *)(o + 0x110) = (f32)tt;
        b = *(s32 *)(pad + 0x1B0);
        tt = (b >> 14) & 1;
        if (b & 0x1000) {
            v = 1 - tt;
        } else {
            v = -tt;
        }
        *(f32 *)(o + 0x114) = (f32)v;
    }
    *(f32 *)(o + 0x2468) = func_L39_00647588(o, (f32 *)(o + 0x110));
    *(f32 *)(o + 0x246C) = func_0038D160(*(f32 *)(o + 0x110), *(f32 *)(o + 0x114));
}
/* localdecomp:end func_L39_00662C90 */
