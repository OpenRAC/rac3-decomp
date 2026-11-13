#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* localdecomp:start func_L39_00622990 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L39_004997E0[];
extern void func_L01_003F3768(s32);
extern void func_L01_003F3740(s32);
extern s32 func_L39_0062CD88(void *);
extern void func_L39_00621308(void *);
extern void func_0038D328(void *, void *);
extern void func_0038D2A0(void *);
extern void func_0038D5B0(void *, void *);
extern void func_L39_00623FB8(void *);
extern void func_L39_006244E0(u8 *);
extern void func_L39_00624658(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_0063B5E0(void *, s32);
extern void func_L39_00628038(void *, s32);

typedef union Buf_00622990 {
    u8 b[8];
    u32 w[2];
} Buf_00622990;

typedef struct {
    u8 pad0[0x2C];
    void (*f2C)(void *);
    u8 pad30[4];
    void (*f34)(void *, s32, s32, s32, s32);
} Vt_00622990;

typedef struct {
    u8 pad0[0x1FC0];
    f32 ring[32];
    u8 pad2040[0x300];
    s32 idx;
    s32 cnt;
} R_00622990;

typedef struct {
    u8 pad0[0x14];
    Vt_00622990 *vt;
} G_00622990;

void func_L39_00622990(u8 *g) {
    u128_t bufa[1];
    Buf_00622990 dbuf;
    u8 *a;
    u8 *b;

    if (g[0x1A14] != 0) {
        func_L01_003F3768(g[0x24C9]);
    }
    *(u128_t *)(g + 0x100) = *(u128_t *)(g + 0xA0);
    g[0x1A06] = func_L39_0062CD88(g);
    *(s32 *)(g + 0x200) = 0;
    ((G_00622990 *)g)->vt->f2C(g);
    if (g[0x1A14] != 0) {
        bufa[0] = *(u128_t *)(g + 0xE0);
    }
    ((R_00622990 *)g)->ring[((R_00622990 *)g)->idx] = *(f32 *)(g + 0xB8);
    *(s32 *)(g + 0x2340) = (*(s32 *)(g + 0x2340) + 1) % 32;
    *(s32 *)(g + 0x2344) += 1;
    if (*(s32 *)(g + 0x2344) > 32) {
        *(s32 *)(g + 0x2344) = 32;
    }
    func_L39_00621308(g);
    a = g + 0x20;
    b = g + 0x60;
    func_0038D328(a, g + 0xB0);
    func_0038D2A0(b);
    func_0038D5B0(b, a);
    func_L39_00623FB8(g);
    func_L39_006244E0(g);
    func_L39_00624658(g);
    if (g[0x1A14] != 0) {
        if (g[0x216] != 0 && (({
            u8 *q = g + 0x19E4;
            u32 a;
            u32 r;
            if (*q == 0) {
                r = 0;
            } else {
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = dbuf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = dbuf.w[0] ^ (u32)q;
                dbuf.w[0] = a;
                dbuf.w[1] ^= a;
                r = dbuf.w[1];
            }
            r;
        }) ^ 0x31) != 0 && (({
            u8 *q = g + 0x19E6;
            u32 a;
            u32 r;
            if (*q == 0) {
                r = 0;
            } else {
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = dbuf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = dbuf.w[0] ^ (u32)q;
                dbuf.w[0] = a;
                dbuf.w[1] ^= a;
                r = dbuf.w[1];
            }
            r;
        }) ^ 0x14) != 0 &&
            func_003D3CB0(bufa, g + 0xE0, 2, *(void **)(g + 0x2524), 0) != 0) {
            func_L39_0063B5E0(g, 0xF);
            ((G_00622990 *)g)->vt->f34(g, 0x76, 0, 0, 0);
            func_L39_00628038(g, 1);
        }
        func_L01_003F3740(g[0x24C9]);
    }
}
/* localdecomp:end func_L39_00622990 */

INCLUDE_ASM("asm/levels", func_L39_00622C28);

INCLUDE_ASM("asm/levels", func_L39_006233A8);

/* localdecomp:start func_L39_00623FB8 */
extern u8 D_L39_004997E0[];
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L01_004482A0_00623FB8(f32, f32, f32, f32, void *, void *);
extern f32 func_0038CF38(void *, void *);

typedef union Buf_00623FB8 {
    u8 b[8];
    u32 w[2];
} Buf_00623FB8;

void func_L39_00623FB8(void *arg0) {
    u8 *g = arg0;
    Buf_00623FB8 buf;
    f32 *p = *(f32 **)(g + 0x2520);

    *(f32 *)(g + 0x1E8) = p[5];
    *(f32 *)(g + 0x1EC) = p[6];
    *(f32 *)(g + 0x1F0) = p[4];
    if ((({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0) {
        if (*(s16 *)(g + 0x14BC) < *(s32 *)(g + 0x2F0) && g[0x14AE] == 0) {
            *(f32 *)(g + 0x1EC) = *(f32 *)(g + 0x14C8);
        }
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 6) == 0) {
        *(f32 *)(g + 0x1EC) = (*(f32 **)(g + 0x2520))[7];
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 4) == 0 || g[0x24FD] != 0) {
        *(f32 *)(g + 0x1E8) = 0.8f - (*(f32 **)(g + 0x2520))[4];
    } else if ((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x7E) == 0) {
        *(f32 *)(g + 0x1F0) = 0.8f;
    }
    if (g[0x216] == 0 || (({
        u8 *q = g + 0x19E8;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x12) == 0 || (({
        u8 *q = g + 0x19EB;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x12) == 0 ||
        *(f32 *)(g + 0x1E4) < (*(f32 **)(g + 0x2520))[6] - 0.17f || (({
        u8 *q = g + 0x19E6;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            a = buf.w[0] ^ (u32)q;
            buf.w[0] = a;
            buf.w[1] ^= a;
            r = buf.w[1];
        }
        r;
    }) ^ 0x11) == 0 ||
        g[0x374] != 0 || func_0038CF38(g + 0x1D0, g + 0xA0) > *(f32 *)(g + 0x1F4) * 0.5f) {
        func_003C4138((f32 *)(g + 0x1E0), *(f32 *)(g + 0x1E8), 0.024f);
        func_003C4138((f32 *)(g + 0x1E4), *(f32 *)(g + 0x1EC), 0.024f);
        func_L01_004482A0_00623FB8(*(f32 *)(g + 0x1F0), 0.028800001f, 0.43200004f, 0.080000006f, g + 0x1F4, g + 0x1F8);
    }
}
/* localdecomp:end func_L39_00623FB8 */

/* localdecomp:start func_L39_006244E0 */
/* decode step as Dec16_00629098 in this file (same loop and (b >> 16) / ... step), inlined by hand, returning byte 4 */
typedef union Buf_006244E0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_006244E0;

typedef struct { u8 pad0[0x18]; void *f18; u8 pad1C[0x24]; u8 v40[8]; f32 f48; } S_006244E0;

extern u8 D_L39_004997E0[];
extern s32 D_L39_0024112C;
extern S_006244E0 D_L39_0025F740;
extern void func_L39_0062A4C0(u8 *);
extern s32 func_L39_00634E58(u8 *, void *, f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_L39_005B8928(void *);

void func_L39_006244E0(u8 *g) {
    u8 *q = g + 0x1A18;
    u8 r;

    if (*q == 0) {
        r = 0;
    } else {
        Buf_006244E0 buf;
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
        for (i = 0; i < 24; i += 3) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
        r = buf.b[4];
    }
    if (r == 0) {
        func_L39_0062A4C0(g);
        if ((D_L39_0024112C + g[0x24C9]) % 3 == 0) {
            g[0x214] = 0;
            g[0x215] = 0;
            *(f32 *)(g + 0x208) = 4.0f;
            if (func_L39_00634E58(g, g + 0x208, 0.7f, 4.0f) != 0) {
                *(f32 *)(g + 0x210) = func_0038D160(D_L39_0025F740.f48, func_0038CED8(D_L39_0025F740.v40));
                if (D_L39_0025F740.f18 != 0) {
                    g[0x215] = 1;
                    if (func_L39_005B8928(D_L39_0025F740.f18) != 0) {
                        g[0x214] = 1;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006244E0 */

INCLUDE_ASM("asm/levels", func_L39_00624658);

/* localdecomp:start func_L39_00626910 */
extern void func_L39_006323B8(void *, void *, void *, f32);
extern void func_L39_00632328(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);

void func_L39_00626910(void *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4)
{
    if (arg2 != 0) {
        func_L39_006323B8(arg0, arg1, arg1, arg3);
        func_L39_00632328(arg0, arg1, arg1, arg4);
    } else {
        func_L39_00632298(arg0, arg1, arg1, arg3);
        func_L39_00632558(arg0, arg1, arg1, arg4);
    }
}
/* localdecomp:end func_L39_00626910 */

INCLUDE_ASM("asm/levels", func_L39_00626998);

/* localdecomp:start func_L39_00626D18 */
void func_L39_00626D18(u8 *p) {
    *(s32 *)(p + 9424) = -1;
    *(u32 *)(p + 9420) = 0xFFFFFFFFU;
    *(s32 *)(p + 9308) = 0;
}
/* localdecomp:end func_L39_00626D18 */

INCLUDE_ASM("asm/levels", func_L39_00626D38);

/* localdecomp:start func_L39_00627EF8 */
extern void func_14AD08(s32, s32, s32, s32, s32, void *);
extern u8 D_001A5CD0[];

void func_L39_00627EF8(u8 *s, f32 *v, s32 flag) {
    S_00627EF8 loc;
    u8 *p;
    u8 *d;

    loc.b1 = s[0x2544];
    p = *(u8 **)(s + 0x2558);
    loc.b0 = p[0xC34];
    loc.b2 = p[0xC31];
    if (flag != 0) {
        loc.b2 |= 0x40;
    }
    d = D_001A5CD0;
    loc.x = v[0];
    loc.y = v[1];
    loc.z = v[2];
    if (*(s32 *)(d + 0x170) == 0) {
        s32 a = *(s32 *)(d + 4);
        u8 b = d[0x7D4];
        func_14AD08(b | 0x80, a, -1, *(s32 *)0x2405E4, 16, &loc);
    }
}
/* localdecomp:end func_L39_00627EF8 */

/* localdecomp:start func_L39_00627F88 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[2];
    u8 flags;
} Msg6257B0;

extern void func_0038CC88(void *, void *, s32);
extern void func_003C4A40(s32, void *);

void func_L39_00627F88(u8 *s, Msg6257B0 *m) {
    if (s[6676] != 0) {
        return;
    }
    if (s[9468] == 0) {
        s[9468] = 1;
        func_0038CC88(s + 9452, m, 16);
    } else {
        s[9466] |= m->flags;
        *(f32 *)(s + 9452) += m->x;
        *(f32 *)(s + 9456) += m->y;
        *(f32 *)(s + 9460) += m->z;
    }
    if ((*(s8 *)(s + 9465) & 0xF0) == 0) {
        func_003C4A40(*(s32 *)(s + 9508), s + 9476);
    }
}
/* localdecomp:end func_L39_00627F88 */

INCLUDE_ASM("asm/levels", func_L39_00628038);

/* localdecomp:start func_L39_00628428 */
typedef union Buf_00628428 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00628428;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static inline void Prep_00628428(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline f32 DecF_00628428(u8 *q) {
    Buf_00628428 buf;
    u32 a;
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
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static inline void SetF_00628428(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_00628428 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00628428(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

typedef struct Mp_00628428 {
    u8 pad0[0x19A];
    s8 b19A;
    u8 pad19B;
    s8 b19C;
} Mp_00628428;

typedef struct Obj_00628428 {
    u8 pad0[0x34];
    u16 h34;
} Obj_00628428;

typedef struct Cam_00628428 {
    u8 pad0[0x44];
    f32 f44;
} Cam_00628428;

typedef struct Lnk_00628428 {
    u8 pad0[4];
    Cam_00628428 *p4;
} Lnk_00628428;

typedef struct Ret_00628428 {
    u8 pad0[0xE];
    u8 bE;
} Ret_00628428;

extern Mp_00628428 *D_L39_00241640;
extern void func_L39_00629290(void);
extern void func_L39_00628760(void *);
extern void func_L39_00647AD0(void *, s32);
extern s32 func_L39_00647A20(void *);
extern void func_L39_00673540(void *, s32, s32);
extern void func_L39_00673A80(void *, s32);
extern void func_L39_00629098(u8 *);
extern Ret_00628428 *func_00382348(void *);
extern void func_L39_00671448(void *, void *, void *, s32);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00647730(void *, void *);
extern void func_L39_0063A030(void *, s32, s32);

void func_L39_00628428(u8 *g) {
    u8 a[16];
    u8 b[16];
    s32 r;
    Ret_00628428 *p;

    if (g[0x1A14] != 0 && g[0x2501] == 0) {
        func_L39_00629290();
    }
    *(s8 *)(g + 0x2502) = -1;
    func_L39_00628760(g);
    if (D_L39_00241640->b19C != 0) {
        func_L39_00647AD0(g, 3);
    } else {
        r = func_L39_00647A20(g);
        func_L39_00673540(g + 0x1A40, r, 1);
        func_L39_00673A80(g + 0x1A40, r);
    }
    if (D_L39_00241640->b19A != 0) {
        func_L39_00673540(g + 0x1A40, 0xF, 0);
    }
    g[0x1A0A] = 0;
    (*(Obj_00628428 **)(g + 0x2524))->h34 &= 0x7FFF;
    g[0x1A15] = 0;
    func_L39_00629098(g);
    *(s32 *)(g + 0x2458) = 0;
    SetF_00628428(g + 0x2476, 15.0f);
    if (*(Lnk_00628428 **)(g + 0x2558) != 0 && (*(Lnk_00628428 **)(g + 0x2558))->p4 != 0 &&
        (g[0x1A14] != 0 || (*(Lnk_00628428 **)(g + 0x2558))->p4->f44 == 0.0f)) {
        (*(Lnk_00628428 **)(g + 0x2558))->p4->f44 = DecF_00628428(g + 0x2476);
    }
    p = func_00382348(*(void **)(g + 0x2524));
    if (p != 0) {
        p->bE = 1;
    }
    if (g[0x1A14] != 0) {
        func_L39_00671448(g, a, b, 0);
        func_L39_00637EC8(g, a, b, 0, 1, 1, 1);
        func_L39_00647730(g, a);
        *(s32 *)(g + 0xF0) = 0;
        *(s32 *)(g + 0xF4) = 0;
        *(s16 *)(g + 0x2488) = 1;
        *(f32 *)(g + 0xF8) = 2.0f;
        func_L39_0063A030(g, 0x1A, 0x10);
    }
}
/* localdecomp:end func_L39_00628428 */

INCLUDE_ASM("asm/levels", func_L39_00628760);

/* localdecomp:start func_L39_00629098 */
typedef union Buf_00629098 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00629098;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static inline void Prep_00629098(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set16_00629098(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00629098 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00629098(q);
    buf.h[2] = v;
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static inline s16 Dec16_00629098(u8 *q) {
    Buf_00629098 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

extern void func_003C2880(s32);

void func_L39_00629098(u8 *g) {
    if (*(s32 *)(g + 0x13F4) != 0) {
        func_003C2880(*(s32 *)(g + 0x13F4));
        *(s32 *)(g + 0x13F4) = 0;
    }
    if (Dec16_00629098(g + 0x313) != 0) {
        Set16_00629098(g + 0x313, 0);
    }
    *(f32 *)(g + 0x1E0) = 0.8f;
    *(f32 *)(g + 0x1E4) = 0.7f;
    *(f32 *)(g + 0x1F4) = 0.45f;
    *(f32 *)(g + 0x1E8) = *(f32 *)(g + 0x1E0);
    *(f32 *)(g + 0x1EC) = *(f32 *)(g + 0x1E4);
}
/* localdecomp:end func_L39_00629098 */

INCLUDE_ASM("asm/levels", func_L39_00629290);

INCLUDE_ASM("asm/levels", func_L39_00629550);

INCLUDE_ASM("asm/levels", func_L39_00629958);
