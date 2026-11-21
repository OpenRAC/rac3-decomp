#include "common.h"

/* NTSC-U counterpart of func_L39_00666518 (src/levels/shared/L39_00666518.c) */
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_00663C40 */
typedef int q_00666518 __attribute__((mode(TI)));

typedef union V4_00666518 {
    q_00666518 q;
    f32 f[4];
} V4_00666518;

typedef union Buf_00666518 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00666518;

typedef struct V_00666518 {
    f32 x, y, z;
    s32 w;
} V_00666518;

typedef struct Cfg_00666518 {
    f32 f0, f4, f8;
    u8 padC[0x10 - 0xC];
    f32 f10, f14, f18;
    s32 w1C;
    u8 pad20[0x38 - 0x20];
    s32 w38;
    u8 b3C;
    u8 pad3D[3];
    s32 w40;
    f32 f44;
    u8 pad48[0x54 - 0x48];
    s32 w54;
    s32 w58[3];
    s32 w64[3];
    s32 w70[3];
} Cfg_00666518;

typedef struct Own_00666518 {
    u8 pad0[4];
    Cfg_00666518 *p4;
    u8 pad8[0x10 - 8];
    u8 a10[0x100 - 0x10];
    void *p100;
    u8 pad104[0x1B0 - 0x104];
    u8 a1B0[1];
} Own_00666518;

typedef struct Mp_00666518 {
    u8 a0[8][0x10];
    u8 pad80[0xC0 - 0x80];
    s16 hC0[8];
    s16 hD0[8];
} Mp_00666518;

typedef struct Mdl_00666518 {
    u8 pad0[0x7E];
    u8 b7E;
} Mdl_00666518;

typedef struct Sub_00666518 {
    u8 pad0[0x46];
    u8 b46;
} Sub_00666518;

typedef struct Ren_00666518 {
    void *p0;
    u8 pad4[0x30 - 4];
    f32 f30;
    s16 h34;
    u8 pad36[2];
    u8 b38;
    u8 pad39[0x3E - 0x39];
    u8 b3E;
    u8 pad3F;
    f32 f40;
    u8 pad44[0x70 - 0x44];
    struct Pl_00666518 *p70;
} Ren_00666518;

typedef struct Ob_00666518 {
    u8 pad0[0x10];
    V4_00666518 q10;
    u8 pad20[0x24 - 0x20];
    Sub_00666518 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x62 - 0x36];
    u8 b62;
    u8 pad63[0x68 - 0x63];
    Ren_00666518 *p68;
    u8 pad6C[0x7E - 0x6C];
    u8 b7E;
    u8 pad7F[0xBE - 0x7F];
    u8 bBE;
    u8 padBF[0xC0 - 0xBF];
    u8 aC0[0xF0 - 0xC0];
    V4_00666518 qF0;
} Ob_00666518;

typedef struct Tbl_00666518 {
    u8 pad0[0x10];
    f32 f10, f14, f18;
    u8 pad1C[0x70 - 0x1C];
} Tbl_00666518;

typedef struct Ent_00666518 {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20[0x80 - 0x20];
} Ent_00666518;

typedef struct Vt_00666518 {
    u8 pad0[0x24];
    void (*fn24)(struct Pl_00666518 *, Mdl_00666518 *, Cfg_00666518 *, V_00666518 *, s32);
} Vt_00666518;


typedef struct Pl_00666518 {
    s32 w0;
    u8 pad4[0x10];
    Vt_00666518 *vt;
    u8 pad18[0x8];
    V4_00666518 v20;
    u8 pad30[0x70];
    V4_00666518 vA0;
    V4_00666518 vB0;
    u8 padC0[0x20];
    f32 aE0[4];
    u8 padF0[0xF0];
    f32 f1E0;
    f32 f1E4;
    u8 pad1E8[0xC];
    f32 f1F4;
    u8 pad1F8[0x22C];
    u8 *p424;
    u8 pad428[0xD78];
    u8 a11A0[0x40];
    f32 f11E0;
    u8 pad11E4[0x1C];
    f32 f1200;
    u8 pad1204[0x8C];
    V4_00666518 v1290;
    u8 pad12A0[0x2C];
    s32 w12CC;
    u8 pad12D0[0x8];
    s32 w12D8;
    u8 pad12DC[0x708];
    u8 h19E4;
    u8 pad19E5[0x5B];
    u8 a1A40[0x13];
    u8 h1A53;
    u8 pad1A54[0x8F4];
    s32 w2348;
    s32 w234C;
    u8 pad2350[0x60];
    V4_00666518 v23B0;
    u8 a23C0[0x30];
    u8 pad23F0[0x86];
    u8 h2476;
    u8 pad2477[0xA3];
    u8 b251A;
    u8 pad251B[0x5];
    Tbl_00666518 *p2520;
    Ob_00666518 *p2524;
    u8 pad2528[0x8];
    u8 *p2530;
    u8 pad2534[0x10];
    s32 w2544;
    s32 w2548;
    u8 pad254C[0x8];
    u8 h2554;
    u8 pad2555[0x3];
    struct Own_00666518 *p2558;
    u8 pad255C[0x3];
    u8 b255F;
    u8 pad2560[0x2824];
    s32 w4D84;
    u8 pad4D88[0x38];
} Pl_00666518;

extern Pl_00666518 D_L39_00310A00[];
extern u8 D_L39_0047B3F8[];
extern s32 D_L39_0047A780[];
extern Mp_00666518 *D_L39_002417C0;
extern Tbl_00666518 D_L39_0049C810[];
extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u8 D_L39_00483AC0[];
extern u8 D_L39_00483AC1[];
extern u32 D_L39_0024BAC8;
extern Ent_00666518 D_L39_0049C950[];
extern s32 D_001A5A50[][8];
extern s32 D_001A5AB0[][8];
extern s32 D_001A5B10[][8];
extern u8 *D_L39_0024CF20[] __attribute__((section(".sdata")));
extern u8 D_L39_00246330_00663C40[] __attribute__((section(".sdata")));

extern void func_L39_0061E448(void);
extern void *func_L39_0065FC38(u8 *p);
extern void func_00388550(void *, void *, s32);
extern Mdl_00666518 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, s32);
extern void *func_001206F4(void *, void *);
extern void func_L39_0055CB20(u8 *);
extern void func_003C26C8(void *);
extern void func_L39_00619A68(void *, s32);
extern void func_L39_0061C568(void *, void *, s32);
extern void func_00388BD0(void *, void *);
extern void func_00388BF0(void *, void *);
extern void func_L39_0062F938(u8 *, f32 *, s32, f32, f32, f32);
extern void func_L01_00410840(void *, void *, f32, u8 *, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L39_00671138(void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

static __inline__ void Prep_00666518(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004998A0[0];
    } else {
        t = *q;
        *q = D_L39_004998A1[0];
        D_L39_004998A1[0] = t;
    }
}

static __inline__ void SetF_00666518(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_00666518 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00666518(q);
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ void Set_00666518(u8 *q, u32 v) {
    u8 *hk = q;
    Buf_00666518 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00666518(q);
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = v ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ f32 DecF_00666518(u8 *q) {
    Buf_00666518 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static __inline__ void PrepC_00666518(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00483AC0[0];
    } else {
        t = *q;
        *q = D_L39_00483AC1[0];
        D_L39_00483AC1[0] = t;
    }
}

static __inline__ void Set16C_00666518(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00666518 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    PrepC_00666518(q);
    key = ((u32 *)D_L39_00483AC0)[((u32)hk * D_L39_0024BAC8) % 418];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00483AC0[((k + i) & 7) * 209 + m] = *d++;
    }
}

static __inline__ Pl_00666518 *Ctor_00666518(Pl_00666518 *p) {
    func_L39_0065FC38((u8 *)p);
    p->vt = (Vt_00666518 *)D_L39_0047B3F8;
    return p;
}

static __inline__ Ob_00666518 *moby_00666518(Pl_00666518 *g) { return g->p2524; }

static __inline__ void Copy_00666518(V4_00666518 *d, V4_00666518 *s) {
    d->q = s->q;
}

void func_L39_00663C40(Own_00666518 *o) {
    V_00666518 v;
    s32 idx;
    Pl_00666518 *g;
    Mdl_00666518 *m;
    s32 i;
    f32 f;
    u8 team;
    f32 hp;

    func_L39_0061E448();
    idx = o->p4->w54;
    g = Ctor_00666518(&D_L39_00310A00[idx]);
    m = func_003BCFB0(D_L39_0047A780[D_L39_002417C0->hC0[idx]], 0x80);
    func_L01_00452E70(m, 0);
    m->b7E = (m->b7E | 0x80) & 0x8F | D_L39_002417C0->hD0[idx] * 16;
    v.x = o->p4->f10;
    v.y = o->p4->f14;
    v.z = o->p4->f18;
    v.w = 0;
    g->vt->fn24(g, m, o->p4, &v, idx);
    team = o->p4->b3C;
    g->b255F = 0xFF;
    g->b251A = team;
    g->p2520 = &D_L39_0049C810[g->b251A];
    g->w0 = o->p4->w38;
    g->w2548 = o->p4->w40;
    SetF_00666518(&g->h2476, o->p4->f44);
    SetF_00666518(&g->h2554, o->p4->f44);
    for (i = 0; i < 3; i++) {
        D_001A5A50[i][idx] = o->p4->w58[i];
        D_001A5AB0[i][idx] = o->p4->w64[i];
        D_001A5B10[i][idx] = o->p4->w70[i];
    }
    func_001206F4(o->a1B0, D_L39_002417C0->a0[idx]);
    func_L39_0055CB20((u8 *)g);
    g->w4D84 = 0;
    if (moby_00666518(g) != 0) {
        moby_00666518(g)->p68->p0 = &moby_00666518(g)->p68->f30;
        hp = DecF_00666518(&g->h2476);
        moby_00666518(g)->p68->f30 = hp;
        moby_00666518(g)->p68->h34 = 0xF;
        moby_00666518(g)->p68->f40 = 0.65f;
        moby_00666518(g)->p68->b38 = g->w2548;
        moby_00666518(g)->p68->b3E = 1;
        moby_00666518(g)->p68->p70 = g;
        moby_00666518(g)->h34 |= 0x1020;
        moby_00666518(g)->h34 |= 0x46;
        moby_00666518(g)->b7E |= 2;
        moby_00666518(g)->p24->b46 = 5;
        moby_00666518(g)->b62 = 0;
        Copy_00666518(&moby_00666518(g)->q10, &g->vA0);
        Copy_00666518(&moby_00666518(g)->qF0, &g->vB0);
        func_003C26C8(moby_00666518(g));
    }
    g->w234C = 0;
    g->w2348 = 0;
    g->f1F4 = D_L39_0049C810[g->b251A].f10;
    g->f1E0 = D_L39_0049C810[g->b251A].f14;
    g->f1E4 = D_L39_0049C810[g->b251A].f18;
    func_L39_00619A68(moby_00666518(g), g->w2544);
    if (g->w2548 == 0) {
        moby_00666518(g)->bBE |= 0x10;
        moby_00666518(g)->bBE &= ~8;
    } else if (g->w2548 == 1) {
        moby_00666518(g)->bBE |= 8;
        moby_00666518(g)->bBE &= ~0x10;
    }
    D_L39_0024CF20[idx] = (u8 *)g;
    g->p2558 = o;
    {
        V_00666518 p;
        s32 t;
        t = o->p4->w1C;
        p.x = o->p4->f0;
        p.y = o->p4->f4;
        p.z = o->p4->f8;
        o->p100 = D_L39_00246330_00663C40 + g->b251A * 0x28;
        func_L39_0061C568(o->a10, &p, t);
    }
    Copy_00666518((V4_00666518 *)(g->p2530 + 0x10), &g->vB0);
    Copy_00666518(&g->v23B0, &g->vB0);
    func_00388BD0(g->p2530 + 0x380, &g->vB0);
    func_00388BF0(&g->v20, &g->vB0);
    func_00388BD0(moby_00666518(g)->aC0, &g->vB0);
    g->f1200 = 0.0f;
    g->f11E0 = g->vB0.f[2];
    Copy_00666518(&g->v1290, &g->v20);
    f = g->f1200;
    func_L39_0062F938((u8 *)g, g->aE0, 1, f, f, 0.7f);
    func_00388550(g->a23C0, g->p2530 + 0x380, 0x30);
    func_L01_00410840(g->a11A0, &g->vA0, g->vB0.f[2], g->p424, f);
    g->w12CC = 0;
    g->w12D8 = g->w2544;
    func_0037E4B8(&g->v1290, 1.0f, g->f11E0, -g->f1200);
    func_L39_00671138(g->a1A40, 1);
    Set16C_00666518(&g->h1A53, D_L39_0049C950[1].h1E);
    Set_00666518(&g->h19E4, 0);
    func_003BE4F0(moby_00666518(g), 0, 0, -1);
}
/* localdecomp:end func_L39_00663C40 */
