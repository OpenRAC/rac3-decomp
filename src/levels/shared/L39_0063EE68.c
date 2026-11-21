#include "common.h"

/* localdecomp:start func_L39_0063EE68 */
void func_L39_0063EE68(void) {

}
/* localdecomp:end func_L39_0063EE68 */

/* localdecomp:start func_L39_0063EE70 */
void func_L39_0063EE70(void) {

}
/* localdecomp:end func_L39_0063EE70 */

/* localdecomp:start func_L39_0063EE78 */
extern u8 D_L39_004997E0[];
typedef struct { u8 pad[0xA4]; u8 bA4[4]; } G_0063EE78;
extern G_0063EE78 D_001A5810;
extern void func_L39_0063FDA8(u8 *);
extern void func_L39_00643F50(u8 *, u8 *);
extern void func_L39_00643B98(u8 *);
extern void func_L39_00672C30(u8 *);
extern void func_L39_006439E0(u8 *);

void func_L39_0063EE78(u8 *a) {
    u32 buf[2];
    if ((({
        u8 *p = a + 0x19E4;
        s32 x;
        if (*p == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 i, n, m, k;
            n = *p;
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
        x;
    }) ^ 0x31) == 0 ||
        (({
        u8 *p = a + 0x19E4;
        s32 x;
        if (*p == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 i, n, m, k;
            n = *p;
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
        x;
    }) ^ 0x8F) == 0 ||
        (({
        u8 *p = a + 0x19E6;
        s32 x;
        if (*p == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 i, n, m, k;
            n = *p;
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
        x;
    }) ^ 3) == 0)
        a[0x1A10] = 1;
    else
        a[0x1A10] = 0;
    func_L39_0063FDA8(a);
    if (*(s32 *)(a + 0x478) != 10) {
        if (D_001A5810.bA4[*(s32 *)(a + 0x2544)] != 0) {
            *(s32 *)(a + 0x460) |= 8;
        } else if (*(s32 *)(a + 0x460) & 8) {
            *(s32 *)(a + 0x460) &= ~8;
        }
    }
    func_L39_00643F50(a, *(u8 **)(a + 0x2524));
    if ((*(u8 **)(a + 0x2524))[0x31] != 0) {
        func_L39_00643B98(a);
    }
    func_L39_00672C30(a + 0x1A40);
    func_L39_006439E0(a);
}
/* localdecomp:end func_L39_0063EE78 */

/* localdecomp:start func_L39_0063F0C0 */
void func_L39_0063F0C0(void) {

}
/* localdecomp:end func_L39_0063F0C0 */

INCLUDE_ASM("asm/levels", func_L39_0063F0C8);

/* localdecomp:start func_L39_0063FC90 */
/* from the Dec2 pattern of func_L39_0065D0A0 (same decode, table D_L39_004997E0, stride 255) */
typedef union Buf_0063FC90 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0063FC90;

extern u8 D_L39_004997E0[];
extern void func_L39_00563370(void);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L01_0043B9E8(s32, s32, s32, s32);

static __inline__ s16 Dec2_0063FC90(u8 *q) {
    Buf_0063FC90 buf;
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

void func_L39_0063FC90(u8 *s) {
    s32 r;

    if (s[0x1A16] != 0) {
        func_L39_00563370();
        s[0x1A16] = 0;
    }
    if (Dec2_0063FC90(s + 0x316) != 0) {
        r = func_L39_005B43C8(0x7F, 0xFF);
        func_L01_0043B9E8(*(s32 *)(s + 0x2524), r, *(s32 *)(s + 0x24E0), r);
    } else {
        func_L01_0043B9E8(*(s32 *)(s + 0x2524), *(s32 *)(s + 0x24DC), *(s32 *)(s + 0x24E0), *(s32 *)(s + 0x24E4));
    }
}
/* localdecomp:end func_L39_0063FC90 */

INCLUDE_ASM("asm/levels", func_L39_0063FDA8);

/* localdecomp:start func_L39_00640698 */
extern s32 func_L39_0063BDE0(void *, void *);
extern void func_L01_0044E740(void *);
extern void func_003C2880(void *);

void func_L39_00640698(u8 *a)
{
    s32 i;
    for (i = 5; i >= 0; i--) {
        u8 *p = a + (5 - i) * 0x50;
        if (*(void **)(p + 0x450) != 0) {
            if (func_L39_0063BDE0(a, *(void **)(p + 0x450)) != 0) {
                p[0x46A] = 0;
                func_L01_0044E740(a + 0x1780);
            }
            func_003C2880(*(void **)(p + 0x450));
            *(void **)(p + 0x450) = 0;
        }
        if (*(void **)(p + 0x454) != 0) {
            func_003C2880(*(void **)(p + 0x454));
            *(void **)(p + 0x454) = 0;
        }
    }
}
/* localdecomp:end func_L39_00640698 */

LINKER_REMNANT("asm/levels", func_L39_00640728);

/* localdecomp:start func_L39_00640738 */
typedef union {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_00640738;

typedef struct { u8 pad0[0xC]; u8 b0C; } N_00640738;
typedef struct { u8 pad0[0x24]; N_00640738 *p24; } M_00640738;
typedef struct { u8 pad0[0x1A4]; u32 w1A4; } P_00640738;
typedef struct { u8 pad0[0x34]; s32 w34; } Q_00640738;

typedef struct {
    M_00640738 *p00;
    M_00640738 *p04;
    u8 pad08[0x11];
    u8 b19;
    u8 b1A;
    u8 pad1B;
    u8 b1C;
    u8 b1D;
    u8 pad1E[2];
    s32 w20;
    s32 w24;
    s32 w28;
    u8 pad2C[0x24];
} __attribute__((aligned(16))) Pl_00640738;

typedef struct {
    u8 pad000[0x2D8];
    s16 h2D8;
    u8 pad2DA[0x16];
    s32 w2F0;
    u8 pad2F4[0x83];
    u8 b377;
    u8 pad378[0xD8];
    Pl_00640738 pl[2];
    u8 pad4F0[0x250];
    Q_00640738 *p740;
    Q_00640738 *p744;
    s32 w748;
    u8 pad74C[8];
    s32 w754;
    u8 pad758[0x948];
    s32 w10A0;
    u8 pad10A4[0x1DC];
    u16 h1280;
    u8 pad1282[0x3E];
    f32 f12C0;
    u8 pad12C4[0x60C];
    s32 w18D0[2];
    u8 pad18D8[0x10C];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1E];
    u8 b1A05;
    u8 pad1A06;
    u8 b1A07;
    u8 pad1A08[4];
    u8 b1A0C;
    u8 pad1A0D;
    u8 b1A0E;
    u8 pad1A0F[3];
    u8 b1A12;
    u8 b1A13;
    u8 pad1A14[3];
    u8 b1A17;
    u8 pad1A18;
    u8 h19[2];
    u8 pad1A1B[4];
    u8 h1F[2];
    u8 pad1A21[4];
    u8 h25[2];
    u8 pad1A27[4];
    u8 h2B[2];
    u8 pad1A2D[4];
    u8 b1A31;
    u8 pad1A32[0xE];
    u8 b1A40;
    u8 pad1A41[0xABE];
    u8 b24FF;
    u8 pad2500[0x1C];
    s32 w251C;
    u8 pad2520[0x14];
    P_00640738 *p2534;
} S_00640738;

typedef struct {
    u8 pad00[4];
    s16 h04;
    u8 pad06[5];
    s8 b0B;
    u8 pad0C[0x10];
    s16 h1C;
    u8 pad1E[3];
    s8 b21;
    u8 pad22[0x5E];
} E_00640738;

__asm__(".extern D_L39_0024B9C8, 16");
extern u32 D_L39_0024B9C8;
extern u8 D_L39_00480760[];
extern u8 D_L39_00480761[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u8 D_L39_00483A00[];
extern E_00640738 D_L39_0049C890[];

extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_00639D90(void *);
extern s32 func_L39_00648AE0(void *, s32);
extern s32 func_L01_0040E020(void *);
extern void func_L39_00621D30(void *);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_00622288(void *);
extern s32 func_L01_004944E8_00640738(s32);
extern void func_L01_003EE640_00640738(s32);
extern void func_003C3A10(void *, s32, s32, s32);

static __inline__ E_00640738 *FindE_00640738(S_00640738 *s, s32 i) {
    if (func_L39_00648AE0(s, i)) {
        return &D_L39_0049C890[D_L39_0049C890[i].b21];
    }
    return &D_L39_0049C890[i];
}

/* Store v into the protected variable whose handle byte is *h. The key multiply reads hk, a second
   copy of the handle pointer: retail keeps that copy in its own register (`move $t0, $t2` ahead of the
   *h == 0 test) and uses it for nothing else; see docs/game/protected-values.md. */
static __inline__ void SetA_00640738(u8 *h, u32 v) {
    u8 *hk = h;
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)hk * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[0] = (u32)h ^ k;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

static __inline__ void SetAVN_00640738(u8 *h, u32 v) {
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)h * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[0] = (u32)h ^ k;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

/* Store 0: retail's zero stores keep no second copy of h. */
static __inline__ void ClrA_00640738(u8 *hp) {
    u8 *h = hp;
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_00480760[0];
    } else {
        u8 t = *h;
        *h = D_L39_00480761[0];
        D_L39_00480761[0] = t;
    }
    k = ((u32 *)D_L39_00480760)[((u32)h * D_L39_0024B9C8) % 0x182];
    o = ((u32)h - *h) & 7;
    buf.w[1] = k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480760[((o + i) & 7) * 0xC1 + id] = *p++;
    }
}

/* Store v into the protected variable whose handle byte is *h. The key multiply reads hk, a second
   copy of the handle pointer: retail keeps that copy in its own register (`move $t0, $t2` ahead of the
   *h == 0 test) and uses it for nothing else; see docs/game/protected-values.md. */
static __inline__ void SetB3_00640738(u8 *h, u32 v) {
    u8 *hk = h;
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_004997E0[0];
    } else {
        u8 t = *h;
        *h = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
    k = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 0x1FE];
    o = ((u32)h - *h) & 7;
    buf.w[0] = (u32)h ^ k;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[id + ((o + i) & 7) * 0xFF] = *p++;
    }
}

/* Store 0: retail's zero stores keep no second copy of h. */
static __inline__ void ClrB3_00640738(u8 *h) {
    Buf_00640738 buf;
    u32 k;
    s32 o;
    s32 id;
    s32 i;
    u8 *p;

    if (*h == 0) {
        *h = ++D_L39_004997E0[0];
    } else {
        u8 t = *h;
        *h = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
    k = ((u32 *)D_L39_004997E0)[((u32)h * D_L39_0024B9C8) % 0x1FE];
    o = ((u32)h - *h) & 7;
    buf.w[1] = k;
    buf.w[0] = (u32)h ^ k;
    id = *h + 1;
    p = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[id + ((o + i) & 7) * 0xFF] = *p++;
    }
}

static __inline__ u32 GetA_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_00480760[((k + i) & 7) * 0xC1 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}


static __inline__ u32 GetB3_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 0xFF];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}

static __inline__ u32 GetB3b_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 0xFF];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.b[4];
}

static __inline__ u32 GetB5_00640738(u8 *q) {
    Buf_00640738 buf;
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

static __inline__ u32 GetC_00640738(u8 *q) {
    Buf_00640738 buf;
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
        *d++ = D_L39_00483A00[((k + i) & 7) * 0xD1 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ s32 EqA_00640738(u8 *q, u32 v) { return GetA_00640738(q) == v; }
static __inline__ s32 EqB3_00640738(u8 *q, u32 v) { return GetB3_00640738(q) == v; }
static __inline__ s32 EqB5_00640738(u8 *q, u32 v) { return GetB5_00640738(q) == v; }
static __inline__ s32 EqC_00640738(u8 *q, u32 v) { return GetC_00640738(q) == v; }

static __inline__ void CopyA_00640738(u8 *d, u8 *src) {
    u8 *q = src;

    SetA_00640738(d, GetA_00640738(q));
}

static __inline__ u32 Map_00640738(u32 v) {
    if (v == 0x19) {
        return 0;
    }
    return v;
}

static __inline__ s32 Mode_00640738(S_00640738 *s) {
    if (s->pl[0].w24 == 2) {
        return s->pl[0].w28;
    }
    return -1;
}

static __inline__ s32 IsMode_00640738(s32 m) {
    if (m == 6 || m == 12) {
        return 1;
    }
    return 0;
}

void func_L39_00640738(S_00640738 *s, s32 b) {
    s32 f, g;
    u32 t, v, x1, x2, y, z;
    u32 w1, w2, w3, w4, w5, w6;
    s32 c;
    E_00640738 *e;

    if (b == 0 && s->b1A0E != 0 && s->pl[0].w28 != 10) {
        s->b1A12 = 1;
    }
    if (s->b1A0C != 0 && b == 0 && (s->b1A12 == 0 || s->pl[0].w28 == 10)) {
        s->b1A12 = 0;
        return;
    }
    f = 0;
    if (func_L01_004606E8(0x80, 3, 0, (s32)s->p2534) == 0 && s->b1A12 == 0) {
        goto L9D0;
    }
    if (b != 0) {
        goto F30;
    }
    w1 = s->pl[0].w28;
    if (w1 == 10) {
        goto L9D0;
    }
    if (s->b1A13 != 0) {
        goto L9D0;
    }
    if (s->b1A12 != 0 && w1 != 0) {
        SetA_00640738(&s->h25[b], w1);
    }
    { u32 st = 10; SetA_00640738(&s->h1F[b], st); }
    f = 1;
L9D0:
    if (b != 0) {
        goto F34;
    }
    if (s->b1A13 == 0) {
        goto LCDC;
    }
    if (s->pl[0].w28 == 0xB) {
        goto LCD0;
    }
    if (EqA_00640738(&s->h1F[0], 0xB)) {
        goto LCD0;
    }
    if (EqB5_00640738(&s->b19E6, 0x14)) {
        goto LCD0;
    }
    w2 = s->pl[0].w28;
    if (w2 != 0) {
        SetA_00640738(&s->h25[0], w2);
    }
    { u32 st = 0xB; SetA_00640738(&s->h1F[0], st); }
    f = 1;
LCD0:
    if (s->b1A13 != 0) {
        goto F34;
    }
LCDC:
    t = s->p2534->w1A4;
    if (!(t & 0x20)) {
        if (!(t & 8)) {
            goto F34;
        }
        if (func_L39_00639D90(s) == 0) {
            goto F34;
        }
    }
    if (s->b1A0E != 0) {
        goto F34;
    }
    if (EqB5_00640738(&s->b19E4, 0x13) && s->w2F0 < 8) {
        goto F34;
    }
    if (EqB5_00640738(&s->b19E4, 0x14)) {
        goto F30;
    }
    w3 = s->w18D0[b];
    if (s->pl[0].w28 == w3) {
        goto F34;
    }
    if (w3 == 0) {
        goto F34;
    }
    SetA_00640738(&s->h1F[b], w3);
    f = 1;
F30:
F34:
    if (b != 1) {
        goto L17B0;
    }
    if (s->b377 == 0) {
        goto L12C0;
    }
    c = GetC_00640738(&s->b1A40);
    if ((((u32)c >> 14) & 1) == 0) {
        goto L12B4;
    }
    if (s->w18D0[1] == 0xE && s->pl[b].w28 != 0) {
        goto L12B8;
    }
    { u32 st = 0xE; SetA_00640738(&s->h19[1], st); }
    w4 = s->pl[b].w28;
    if (w4 != 0) {
        SetA_00640738(&s->h25[b], w4);
    } else {
        u32 st = 0x19;
        SetA_00640738(&s->h25[b], st);
    }
    goto L17B0;
L12B4:
L12B8:
    if (s->b377 != 0) {
        goto L162C;
    }
L12C0:
    c = GetC_00640738(&s->b1A40);
    if ((s16)c >= 0) {
        goto L162C;
    }
    if (s->w18D0[1] == 0xF && s->pl[b].w28 != 0) {
        goto L162C;
    }
    { u32 st = 0xF; SetA_00640738(&s->h19[1], st); }
    w5 = s->pl[b].w28;
    if (w5 != 0) {
        SetA_00640738(&s->h25[b], w5);
    } else {
        u32 st = 0x19;
        SetA_00640738(&s->h25[b], st);
    }
    goto L17B0;
L162C:
    if (s->h2D8 != 0) {
        goto L17B0;
    }
    if (s->pl[1].w28 != 0xE) {
        goto L17B0;
    }
    if (GetA_00640738(&s->h25[1]) != 0) {
        { u32 st = 1; SetA_00640738(&s->h2B[1], st); }
    }
L17B0:
    if (GetA_00640738(&s->h2B[b]) == 0) {
        goto L20B8;
    }
    ClrA_00640738(&s->h2B[b]);
    if (GetA_00640738(&s->h25[b]) == 0) {
        goto L20B8;
    }
    w6 = s->pl[b].w28;
    if (GetA_00640738(&s->h25[b]) == w6) {
        goto L20B8;
    }
    if (EqA_00640738(&s->h25[b], 0x19)) {
        goto L1CEC;
    }
    if (EqA_00640738(&s->h25[b], 0xA)) {
        goto L1CEC;
    }
    y = GetA_00640738(&s->h25[b]);
    c = GetC_00640738(&s->b1A40);
    if (!((((s16)c) >> y) & 1)) {
        goto L20B8;
    }
L1CEC:
    v = Map_00640738(GetA_00640738(&s->h25[b]));
    if (!EqA_00640738(&s->h25[b], 0xA)) {
        s->w18D0[b] = v;
    }
    SetAVN_00640738(&s->h1F[b], v);
    ClrA_00640738(&s->h25[b]);
    if (b == 0) {
        z = GetA_00640738(&s->h1F[0]);
        e = FindE_00640738(s, z);
        e->h1C = 0x20;
    }
    f = 1;
L20B8:
    if (b != 0) {
        goto L2630;
    }
    if (s->w251C == 0) {
        goto L2630;
    }
    if (f == 0) {
        if (GetA_00640738(&s->h19[0]) == 0) {
            goto L2630;
        }
        x1 = GetA_00640738(&s->h1F[b]);
        if (GetA_00640738(&s->h19[b]) == x1) {
            goto L2630;
        }
    }
    if (EqA_00640738(&s->h1F[b], 0xB)) {
        goto L2630;
    }
    if (EqA_00640738(&s->h1F[b], 0xA)) {
        goto L2630;
    }
    f = 0;
    ClrA_00640738(&s->h1F[b]);
    ClrB3_00640738(&s->b1A31);
    ClrA_00640738(&s->h19[b]);
L2630:
    g = 0;
    if (GetA_00640738(&s->h19[b]) == 0) {
        goto L2E78;
    }
    x2 = GetA_00640738(&s->h1F[b]);
    if (GetA_00640738(&s->h19[b]) == x2) {
        goto L2DB0;
    }
    if (b == 1) {
        y = GetA_00640738(&s->h25[1]);
    }
    if (EqA_00640738(&s->h19[b], 0x19)) {
        ClrA_00640738(&s->h1F[b]);
        s->w18D0[b] = 0;
        goto L2DA4;
    }
    if (b == 0 && s->w18D0[0] != 0) {
        y = GetA_00640738(&s->h19[0]);
    }
    CopyA_00640738(&s->h1F[b], &s->h19[b]);
    s->w18D0[b] = GetA_00640738(&s->h1F[b]);
    if (b != 0) {
        goto L2DA4;
    }
    z = GetA_00640738(&s->h1F[0]);
    e = FindE_00640738(s, z);
    e->h1C = 0x20;
L2DA4:
    f = 1;
    g = 1;
    goto L2E74;
L2DB0:
    ClrA_00640738(&s->h19[b]);
L2E74:
L2E78:
    if (s->pl[b].b1C == 2) {
        f = 0;
    }
    if (s->pl[b].b1C == 1) {
        if (s->pl[b].b19 == 0) {
            s->pl[b].b19 = s->pl[b].b1D;
        }
    }
    if (func_L01_0040E020(&s->pl[b].b19) == 0) {
        if (s->b1A13 != 0 && s->b1A07 != 0 && IsMode_00640738(Mode_00640738(s))) {
            if (s->w748 != 0) {
                s->w754 = 1;
            }
            s->b24FF = 1;
            s->b1A07 = 0;
            s->b1A05 = 0;
            s->pl[b].b19 = 0;
        } else {
            f = 0;
        }
    }
L2F44:
    if (b != 0) {
        goto L3474;
    }
    if (f == 0) {
        goto L30BC;
    }
    SetB3_00640738(&s->b1A31, GetA_00640738(&s->h1F[0]));
    f = 0;
L30BC:
    if (GetB3_00640738(&s->b1A31) == 0) {
        goto L3474;
    }
    z = GetB3_00640738(&s->b1A31);
    z = FindE_00640738(s, z)->h04;
    if (func_L01_004944E8_00640738(z) == 0) {
        func_L01_003EE640_00640738(z);
        goto L3474;
    }
    SetA_00640738(&s->h1F[b], GetB3_00640738(&s->b1A31));
    ClrB3_00640738(&s->b1A31);
    f = 1;
L3474:
    if (f != 0) {
        s->pl[b].w20 = 3;
        func_L39_00621D30(s);
        s->w10A0 = func_L39_005B43C8(0x2A, 0x4B);
        if (s->b1A07 != 0) {
            func_L39_00622288(s);
        }
        if (b == 0) {
            switch (GetA_00640738(&s->h1F[0])) {
            case 3:
                s->f12C0 = 200.0f;
                break;
            case 4:
                s->f12C0 = 120.0f;
                break;
            case 1:
                s->f12C0 = 35.0f;
                break;
            case 2:
                s->f12C0 = 30.0f;
                break;
            case 10:
            case 11:
                s->f12C0 = 0.0f;
                break;
            default:
                s->f12C0 = 20.0f;
                break;
            }
            s->h1280 &= 0xFFDF;
        }
        s->pl[b].b1A = 0;
        ClrA_00640738(&s->h19[b]);
        s->b1A12 = 0;
        z = GetA_00640738(&s->h1F[b]);
        if (b == 0) {
            e = FindE_00640738(s, z);
            if (e->b0B != GetB3b_00640738(&s->b1A17)) {
                if (s->p740 != 0) {
                    s->p740->w34 = 1;
                }
                if (s->p744 != 0) {
                    s->p744->w34 = 1;
                }
            }
        }
        if (s->pl[b].p00 != 0 && s->pl[b].p00->p24->b0C >= 3) {
            func_003C3A10(s->pl[b].p00, 2, 0, 2);
        }
        if (s->pl[b].p04 != 0 && b != 3 && s->pl[b].p04->p24->b0C >= 3) {
            func_003C3A10(s->pl[b].p04, 2, 0, 2);
        }
        s->pl[b].w24 = 3;
    } else if (g != 0) {
        ClrA_00640738(&s->h1F[b]);
    }
}
/* localdecomp:end func_L39_00640738 */
