#include "common.h"

/* declared by functions of L39_00637D38.c, which this file was cut from */
extern void func_L39_00637E10(void *);

/* localdecomp:start func_L39_00637EC8 */
#include "vu0.h"

typedef struct V4_00637EC8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00637EC8;

typedef union Buf_00637EC8 {
    V4_00637EC8 v;
    u8 b[8];
    u32 w[2];
} Buf_00637EC8;

typedef struct Msg_00637EC8 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    f32 pos[3];
    f32 rot[3];
    s16 h1C;
    u8 b1E;
} Msg_00637EC8;

typedef struct VT_00637EC8 {
    u8 pad0[0x30];
    void (*f30)(void *);
    void (*f34)(void *, s32, s32, s32, s32);
} VT_00637EC8;

typedef struct P2524_00637EC8 {
    u8 pad0[0x10];
    V4_00637EC8 v10;
    u8 pad20[0x41 - 0x20];
    u8 b41;
    u8 pad42;
    u8 b43;
    u8 pad44[0xC0 - 0x44];
    u8 bC0[0x40];
} P2524_00637EC8;

typedef struct P50_00637EC8 {
    u8 pad0[0x94];
    s32 w94;
} P50_00637EC8;

typedef struct P2530_00637EC8 {
    u8 pad0[0x50];
    P50_00637EC8 *p50;
    u8 pad54[0x458 - 0x54];
    s32 w458;
} P2530_00637EC8;

typedef struct Self_00637EC8 {
    u8 pad0[0x14];
    VT_00637EC8 *vt;
    u8 pad18[0x20 - 0x18];
    V4_00637EC8 v20;
    u8 pad30[0x40 - 0x30];
    V4_00637EC8 v40;
    u8 pad50[0xA0 - 0x50];
    V4_00637EC8 vA0;
    V4_00637EC8 vB0;
    u8 padC0[0xE0 - 0xC0];
    f32 fE0[4];
    u8 padF0[0x260 - 0xF0];
    V4_00637EC8 v260;
    u8 pad270[0x2DE - 0x270];
    s16 h2DE;
    u8 pad2E0[0x424 - 0x2E0];
    s32 w424;
    u8 pad428[0x11A0 - 0x428];
    u8 b11A0[0x40];
    f32 f11E0;
    u8 pad11E4[0x1200 - 0x11E4];
    s32 w1200;
    u8 pad1204[0x1280 - 0x1204];
    u16 h1280;
    u8 pad1282[0x1290 - 0x1282];
    V4_00637EC8 v1290;
    u8 pad12A0[0x12C0 - 0x12A0];
    f32 f12C0;
    u8 pad12C4[0x12CC - 0x12C4];
    s32 w12CC;
    u8 pad12D0[0x12D8 - 0x12D0];
    s32 w12D8;
    u8 pad12DC[0x132C - 0x12DC];
    f32 f132C;
    u8 pad1330[0x1334 - 0x1330];
    s32 w1334;
    u8 pad1338[0x1630 - 0x1338];
    u8 b1630[0x150];
    u8 b1780[4];
    u8 pad1784[0x19E6 - 0x1784];
    u8 b19E6;
    u8 pad19E7[0x1A06 - 0x19E7];
    u8 b1A06;
    u8 pad1A07[0x1A14 - 0x1A07];
    u8 b1A14;
    u8 b1A15;
    u8 pad1A16[0x24C9 - 0x1A16];
    u8 b24C9;
    u8 pad24CA[0x251C - 0x24CA];
    s32 w251C;
    u8 pad2520[0x2524 - 0x2520];
    P2524_00637EC8 *p2524;
    u8 pad2528[0x2530 - 0x2528];
    P2530_00637EC8 *p2530;
    s32 w2534;
    f32 f2538;
    f32 f253C;
    f32 f2540;
    s32 w2544;
    u8 pad2548[0x44ED - 0x2548];
    u8 b44ED;
} Self_00637EC8;

typedef struct Tab_00637EC8 {
    u8 pad0[0xA4];
    u8 bA4[0x100];
} Tab_00637EC8;

typedef struct Net_00637EC8 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x170 - 8];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Net_00637EC8;

extern void func_L39_0063D240(void *, s32);
extern void func_L01_004606A8(s32);
extern void func_0038D328(void *, void *);
extern void func_0038D308(void *, void *);
extern s32 func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern void func_L01_0044E740(void *);
extern void func_L39_00622288(void *);
extern void func_L39_0063EC78(void *);
extern void func_L39_0062B670(void *, s32, s32);
extern void func_L39_00630548(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00412E70(void *, V4_00637EC8 *, f32, f32, s32);
extern void func_L01_00412FE0(void *, V4_00637EC8 *, f32, f32);
extern void func_L39_00646B98(void *);
extern void func_L39_0057B4C0(s32, s32);
extern void func_L39_005AC128(void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern u8 D_L39_004997E0[];
typedef struct G_00637EC8 {
    u8 pad0[0x450];
    s32 w450;
} G_00637EC8;

extern G_00637EC8 D_L39_0024DE80;
__asm__(".extern D_L39_0024DE80, 16");
extern Tab_00637EC8 D_001A5810;
extern Net_00637EC8 D_001A5CD0;
extern s32 D_002405D0;

void func_L39_00637EC8(void *self, void *a1, void *a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    Self_00637EC8 *s = self;
    V4_00637EC8 *pos = a1;
    V4_00637EC8 *rot = a2;
    f32 save;
    Buf_00637EC8 buf;
    u8 *q;
    u32 r;
    s32 eq;

    if (s->b1A14 != 0 && s->w251C != 0) {
        func_L39_0063D240(s, 1);
    }
    if (a5 != 0) {
        func_L01_004606A8(s->w2534);
    }
    if (pos->x < 2.0f || pos->x > 1021.0f || pos->y < 2.0f || pos->y > 1021.0f ||
        pos->z < 2.0f || pos->z > 1021.0f) {
        if (pos->x < 2.0f) pos->x = 2.0f;
        if (pos->x > 1021.0f) pos->x = 1021.0f;
        if (pos->y < 2.0f) pos->y = 2.0f;
        if (pos->y > 1021.0f) pos->y = 1021.0f;
        if (pos->z < 2.0f) pos->z = 2.0f;
        if (pos->z > 1021.0f) pos->z = 1021.0f;
    }
    s->vA0 = *pos;
    s->p2524->v10 = *pos;
    s->vB0 = *rot;
    func_0038D328(&s->v20, &s->vB0);
    func_0038D308(s->p2524->bC0, &s->vB0);
    s->v1290 = s->v20;
    s->f11E0 = s->vB0.z;
    s->w1200 = 0;
    if (s->v40.z < 0.866f) {
        s->b1A06 = 1;
    }
    func_L39_00632180((u8 *)s, s->fE0, 1, 0.0f, 0.0f, 0.7f);
    s->vt->f30(s);
    func_L01_0044E740(s->b1630);
    func_L01_0044E740(s->b1780);
    s->h2DE = 1;
    func_L39_00622288(s);
    func_L39_0063EC78(s);
    if (a3 != -1) {
        s->vt->f34(s, a3, 1, 1, 1);
    }
    func_L39_0062B670(s, s->p2524->b43, s->p2524->b41);

    q = &s->b19E6;
    if (*q == 0) {
        r = 0;
    } else {
        s32 n, k, m, i;
        u8 *d;
        u32 x, y;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        x = buf.w[0] ^ (u32)q;
        y = buf.w[1] ^ x;
        buf.w[0] = x;
        buf.w[1] = y;
        r = y;
    }
    eq = (r == 0x11);
    if (eq) {
        D_L39_0024DE80.w450 = 1;
    } else {
        D_L39_0024DE80.w450 = 0;
    }
    func_L39_00630548(s);
    if (func_0038CF00(&s->vA0, &s->v260) < 1.0f) {
        s->vA0 = s->v260;
    }
    {
        save = s->f12C0;
        if (D_001A5810.bA4[s->w2544] == 1) {
            s->f132C = 2.0f;
        } else {
            s->f132C = 1.15f;
        }
        func_0038CF68(&buf.v, &s->v40, s->f132C);
        vec_add_ab(&buf.v, &buf.v, &s->vA0);
        func_L01_00412E70(s->b11A0, &buf.v, s->vB0.z, 0.0f, s->w424);
        if (s->b1A14 != 0) {
            s->w12CC = s->b24C9;
        } else {
            s->w12CC = 0;
        }
        s->w1334 = 0;
        s->w12D8 = s->w2544;
        if (s->v40.z > 0.99f) {
            s->h1280 |= 2;
        } else {
            s->h1280 &= ~2;
        }
        func_L01_00412FE0(s->b11A0, &buf.v, s->vB0.z, 0.0f);
    }
    func_L39_00646B98(s);
    s->p2530->w458 = 1;
    s->f12C0 = save;
    if (a4 != 0 && s->b1A14 != 0) {
        func_L39_0057B4C0(s->p2530->p50->w94, 1);
    }
    func_L39_005AC128(s->p2524);
    if (s->b1A14 != 0) {
        Msg_00637EC8 m;

        m.b0 = s->w2544;
        func_0038CC88(m.pos, pos, 12);
        func_0038CC88(m.rot, rot, 12);
        m.b2 = a5;
        m.h1C = a3;
        m.b1E = a6;
        m.b1 = s->b1A15;
        m.b3 = s->b44ED;
        if (D_001A5CD0.w170 == 0) {
            func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.w4, -1, D_002405D0, 0x20, &m);
        }
        s->f2538 = s->vA0.x;
        s->f253C = s->vA0.y;
        s->f2540 = s->vA0.z;
    }
}
/* localdecomp:end func_L39_00637EC8 */
