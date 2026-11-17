#include "common.h"

/* declared by functions of L39_0063A030.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_0063AC60 */
typedef union Buf_0063AC60 {
    u8 b[8];
    u32 w[2];
} Buf_0063AC60;

typedef struct VT_0063AC60 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_0063AC60;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;
extern void func_L39_0062B718(void *);
extern void func_L39_0063B0A8(void *);
extern void func_003C6FB0(s32, void *, void *, void *);

static inline void Prep_0063AC60(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void ClrSet_0063AC60(u8 *q) {
    Buf_0063AC60 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0063AC60(q);
    key = ((u32 *)D_L39_004997E0)[((u32)q * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

void func_L39_0063AC60(u8 *g) {
    *(f32 *)(g + 0x1E0) = 0.8f;
    *(f32 *)(g + 0x1E4) = 0.7f;
    *(f32 *)(g + 0x1F4) = 0.45f;
    *(f32 *)(g + 0x1E8) = *(f32 *)(g + 0x1E0);
    *(f32 *)(g + 0x1EC) = *(f32 *)(g + 0x1E4);
    *(s32 *)(g + 0x18D8) = 0;
    ClrSet_0063AC60(g + 0x19E4);
    *(f32 *)(g + 0x614) = 1.0f;
    func_L39_0062B718(g);
    (*(VT_0063AC60 **)(g + 0x14))->f34(g, 0, 1, 0, 1);
    *(f32 *)(g + 0xF0) = 1.0f;
    *(f32 *)(g + 0xF4) = 1.0f;
    *(f32 *)(g + 0xF8) = 1.0f;
    g[0x1A13] = 0;
    func_L39_0063B0A8(g);
    func_003C6FB0(*(s32 *)(g + 0x2524), g + 0x24DC, g + 0x24E0, g + 0x24E4);
}
/* localdecomp:end func_L39_0063AC60 */

/* localdecomp:start func_L39_0063AE10 */
typedef int Q_0063AE10 __attribute__((mode(TI)));
typedef struct V_0063AE10 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0063AE10;

typedef union Buf_0063AE10 {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_0063AE10;

extern u8 D_L39_004997E0[];
extern void func_L39_00631AD8(u8 *);
extern void func_L39_00631CB0(u8 *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);
extern void func_L01_00511158(void *, void *, void *, f32);
extern void func_L01_00439790(void *, s32, void *, f32, f32);

/* reads an obfuscated 16-bit value stored as an index byte at q */
static __inline__ s16 get_half_0063AE10(u8 *q) {
    Buf_0063AE10 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    u32 a;
    u32 c;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 24; i += 3) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    c = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (c >> 16) / (((c ^ (c >> 16)) << 16) + 1);
    return buf.h[2];
}

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063AE10(u8 *q) {
    Buf_0063AE10 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_0063AE10(u8 *o) {
    V_0063AE10 v;
    u8 *m;
    f32 f;
    f32 d;

    (*(u8 **)(o + 0x2524))[0xA8] = 0xFF;
    *(Q_0063AE10 *)(*(u8 **)(o + 0x2524) + 0x10) = *(Q_0063AE10 *)(o + 0xA0);
    func_L39_00631AD8(o);
    *(Q_0063AE10 *)(*(u8 **)(o + 0x2524) + 0xF0) = *(Q_0063AE10 *)(o + 0xB0);
    func_L39_00631CB0(o);
    func_0038CC88(*(u8 **)(o + 0x2524) + 0xC0, o + 0x20, 0x30);
    func_003C7C38(*(u8 **)(o + 0x2524));
    m = *(u8 **)(o + 0x2524);
    if (*(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[6] != 0) {
        m[0x63] = 0x10;
    } else {
        (*(u8 **)(o + 0x2524))[0x63] = 0x10;
    }
    if (get_half_0063AE10(o + 0x313) != 0) {
        return;
    }
    if (*(s32 *)(*(u8 **)(o + 0x2524) + 0x98) == 0) {
        return;
    }
    v = *(V_0063AE10 *)(o + 0xA0);
    func_L01_00511158(o, &v, &v, *(f32 *)(o + 0x1E4));
    d = *(f32 *)(o + 0x1E0) - *(f32 *)(o + 0x1E4);
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_L01_00439790(*(u8 **)(o + 0x2524), 0, &v, *(f32 *)(o + 0x1F4), d);
    f = *(f32 *)(o + 0x1F4) + 0.05f;
    if ((get_state_0063AE10(o + 0x19E6) ^ 4) == 0) {
        f += 0.15f;
    }
    v = *(V_0063AE10 *)(o + 0xA0);
    func_L01_00511158(o, &v, &v, f);
    d = *(f32 *)(o + 0x1E0) - f;
    if (d < 0.05f) {
        d = 0.05f;
    }
    func_L01_00439790(*(u8 **)(o + 0x2524), 1, &v, *(f32 *)(o + 0x1F4), d);
}
/* localdecomp:end func_L39_0063AE10 */

INCLUDE_ASM("asm/levels", func_L39_0063B0A8);

/* localdecomp:start func_L39_0063B5E0 */
typedef union Buf_0063B5E0 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_0063B5E0;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static __inline__ void Prep_0063B5E0(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static __inline__ f32 DecF_0063B5E0(u8 *q) {
    Buf_0063B5E0 buf;
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

static __inline__ void SetF_0063B5E0(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_0063B5E0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0063B5E0(q);
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

static __inline__ s32 LtF_0063B5E0(u8 *q, f32 v) {
    return DecF_0063B5E0(q) < v;
}

typedef struct Cam_0063B5E0 {
    u8 pad0[0x44];
    f32 f44;
} Cam_0063B5E0;

typedef struct Lnk_0063B5E0 {
    u8 pad0[4];
    Cam_0063B5E0 *p4;
} Lnk_0063B5E0;

void func_L39_0063B5E0(u8 *g, s32 dmg) {
    if (g[0x1A14] != 0 && dmg != 0) {
        u8 *q = g + 0x2476;
        f32 f = dmg;
        *(s32 *)(g + 0x24D4) = dmg;
        SetF_0063B5E0(q, DecF_0063B5E0(q) - f);
        if ((u8)LtF_0063B5E0(g + 0x2476, 0.0f)) {
            SetF_0063B5E0(g + 0x2476, 0.0f);
        }
        *(s32 *)(g + 0x2514) = 300;
        if (*(Lnk_0063B5E0 **)(g + 0x2558) != 0 && (*(Lnk_0063B5E0 **)(g + 0x2558))->p4 != 0) {
            (*(Lnk_0063B5E0 **)(g + 0x2558))->p4->f44 = DecF_0063B5E0(g + 0x2476);
        }
    }
}
/* localdecomp:end func_L39_0063B5E0 */
