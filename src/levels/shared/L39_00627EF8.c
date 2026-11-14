#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* declared by functions of L39_00622990.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern void func_L39_00623FB8(void *);
extern void func_L39_006244E0(u8 *);

/* declared by functions of L39_00623FB8.c, which this file was cut from */
extern u8 D_L39_004997E0[];

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

/* localdecomp:start func_L39_00628038 */
typedef union Buf_00628038 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00628038;

extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;

static inline u32 Dec_00628038(u8 *q) {
    Buf_00628038 buf;
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

static inline s32 DecEq_00628038(u8 *q, s32 v) {
    return Dec_00628038(q) == v;
}

static inline void Prep_00628038(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set16_00628038(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00628038 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00628038(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

typedef struct Pkt_00628038 {
    s8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 pad5[3];
    s32 w8;
} Pkt_00628038;

typedef struct VT_00628038 {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
    u8 pad20[0x34 - 0x20];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_00628038;

typedef struct Sub_00628038 {
    u8 pad0[0xAA];
    s16 hAA;
} Sub_00628038;

typedef struct Obj_00628038 {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x14 - 4];
    VT_00628038 *vt;
    u8 pad18[0x1C - 0x18];
    Sub_00628038 *p1C;
    u8 pad20[0x2544 - 0x20];
    u8 b2544;
} Obj_00628038;

typedef struct Net_00628038 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x170 - 8];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Net_00628038;

extern s32 D_L39_002405B8;
extern Obj_00628038 *func_L39_0061D1D8(s32);
extern s32 func_L39_0066F558(s32);
extern s32 func_L39_005B4398(s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00670AE0(void *);
extern s32 func_L39_0053D838(void *);

void func_L39_00628038(u8 *g, s32 on) {
    s32 t;

    if (DecEq_00628038(g + 0x19E4, 0x90)) {
        return;
    }
    if (on != 0) {
        g[0x2501] = 1;
    } else {
        g[0x2501] = 0;
    }
    t = DecEq_00628038(g + 0x19E8, 0x14);
    if (g[0x1A14] != 0) {
        if (!t) {
            Pkt_00628038 pk;
            Obj_00628038 *o;

            o = func_L39_0061D1D8(*(s32 *)(g + 0x24CC));
            if (o != 0 && (o->b3 & 0xF) == 0 && o->vt->f1C(o, *(s32 *)(g + 0x2548)) == 0) {
                pk.b0 = o->b2544;
            } else if (o != 0 && (o->b3 & 0xF) == 2 && o->p1C != 0) {
                pk.b0 = func_L39_0066F558(o->p1C->hAA);
            } else {
                pk.b0 = -1;
            }
            pk.b2 = g[0x2544];
            pk.b1 = Dec_00628038(g + 0x19E4);
            pk.b3 = g[0x24D0];
            pk.w8 = *(s32 *)(g + 0x24CC);
            pk.b4 = func_L39_005B4398(0x10);
            if (((Net_00628038 *)D_001A5CD0)->w170 == 0) {
                func_0014AD08(((Net_00628038 *)D_001A5CD0)->b7D4 | 0x40, ((Net_00628038 *)D_001A5CD0)->w4, -1, D_L39_002405B8, 0xC, &pk);
            }
            func_L39_00670AE0(&pk);
        }
    }
    Set16_00628038(g + 0x31C, func_L39_0053D838(g));
    *(s32 *)(g + 0x610) = 0;
    g[0x1A13] = 0;
    (*(VT_00628038 **)(g + 0x14))->f34(g, 0x90, 0, 1, 1);
}
/* localdecomp:end func_L39_00628038 */

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
extern void func_L39_00629290();
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

/* localdecomp:start func_L39_00629290 */
typedef union Buf_00629290 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[4];
} Buf_00629290;

typedef struct V3_00629290 {
    f32 x, y, z;
} V3_00629290;

extern struct Mp_00628428 *D_L39_00241640;
extern u8 D_L39_00483A00[];
extern void func_L39_0066C928(s32, s32 *, void *);
extern void func_L39_00662AA0(s32, void *, s32);

static __inline__ s16 Dec16_00629290(u8 *q) {
    Buf_00629290 buf;
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

static __inline__ void Copy_00629290(V3_00629290 *d, V3_00629290 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

static __inline__ void Send16_00629290(s32 r, u16 v) {
    u16 h = v;
    func_L39_00662AA0(r, &h, 2);
}

void func_L39_00629290(u8 *g) {
    s32 r;
    u16 s;

    s = Dec16_00629290(g + 0x1A40);
    if (((s8 *)D_L39_00241640)[0x19C] == 0) {
        s &= 0xFFFD;
    }
    s &= 0x33FF;
    if (s == 0 && Dec16_00629290(g + 0x1A41) == 0) {
        return;
    }
    r = 0;
    func_L39_0066C928(0x1AFC, &r, g);
    {
        V3_00629290 va;
        V3_00629290 vb;
        Copy_00629290(&va, (V3_00629290 *)(g + 0xA0));
        Copy_00629290(&vb, (V3_00629290 *)(g + 0x250));
        func_L39_00662AA0(r, &va, 12);
        func_L39_00662AA0(r, &vb, 12);
    }
    Send16_00629290(r, s);
    {
        s32 rr = r;
        Send16_00629290(rr, Dec16_00629290(g + 0x1A41));
    }
}
/* localdecomp:end func_L39_00629290 */

/* localdecomp:start func_L39_00629550 */
typedef union Buf_00629550 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00629550;

typedef struct Rec_00629550 {
    u8 b0;
    u8 b1;
    u8 pad2[0x10];
    u8 a12[0x10];
    u8 a22[0x10];
} Rec_00629550;

typedef struct Msg_00629550 {
    u8 pad0[2];
    s8 b2;
    s8 b3;
} Msg_00629550;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u8 D_L39_0049C340[];
extern u8 D_L39_0049C341[];
extern u32 D_L39_0024B9C8;
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern void func_L39_00673B68(void *, s32);

static __inline__ s16 Dec16C_00629550(u8 *q) {
    Buf_00629550 buf;
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

static __inline__ s16 Dec16D_00629550(u8 *q) {
    Buf_00629550 buf;
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
        *d++ = D_L39_0049C340[m + ((k + i) & 7) * 129];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ s32 DecEq16D_00629550(u8 *q, s32 v) {
    u8 *p = q;
    return Dec16D_00629550(p) == v;
}

static __inline__ void PrepD_00629550(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_0049C340[0];
    } else {
        t = *q;
        *q = D_L39_0049C341[0];
        D_L39_0049C341[0] = t;
    }
}

static __inline__ void Set16D_00629550(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00629550 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepD_00629550(q);
    key = ((u32 *)D_L39_0049C340)[((u32)hk * D_L39_0024B9C8) % 258];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_0049C340[m + ((k + i) & 7) * 129] = *d++;
    }
}

void func_L39_00629550(u8 *g, Msg_00629550 *m) {
    s32 bit = m->b3;
    s32 ok;
    s32 bit2;
    u8 *r;
    s32 cur;
    u8 *r2;

    if (bit == -1 || bit == 10) {
        return;
    }
    if ((Dec16C_00629550(g + 0x1A41) >> bit) & 1) {
        return;
    }
    ok = 1;
    if (m->b2 >= 0 && *(s32 *)(D_L39_0024CE20[m->b2] + 0x2548) == *(s32 *)(g + 0x2548)) {
        ok = 0;
    }
    if (!ok) {
        return;
    }
    bit2 = m->b3;
    if ((Dec16C_00629550(g + 0x1A41) >> bit2) & 1) {
        return;
    }
    r = (u8 *)(m->b3 + (s32)g);
    r += 0x1A62;
    cur = Dec16D_00629550(r);
    Set16D_00629550(r, cur + 1);
    r2 = (u8 *)(m->b3 + (s32)g);
    r2 += 0x1A62;
    if (DecEq16D_00629550(r2, 3)) {
        func_L39_00673B68(g + 0x1A40, m->b3);
    }
}
/* localdecomp:end func_L39_00629550 */

INCLUDE_ASM("asm/levels", func_L39_00629958);
