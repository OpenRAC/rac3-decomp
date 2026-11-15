#include "common.h"

/* localdecomp:start func_L39_00661A40 */
#include "vu0.h"

typedef union Buf_00661A40 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_00661A40;

typedef struct V_00661A40 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00661A40;

typedef struct VT_00661A40 {
    u8 pad0[0x24];
    void (*f24)(void *, void *, void *, void *, s32);
} VT_00661A40;

typedef struct L_00661A40 {
    u8 pad0[0xC0];
    s16 hC0[8];
    s16 hD0[8];
    s16 hE0[8];
    u8 pad1[0x19A - 0xF0];
    s8 b19A;
    u8 pad2;
    s8 b19C;
} L_00661A40;

typedef struct E_00661A40 {
    u8 pad[0x28];
} E_00661A40;

typedef struct Pv_00661A40 {
    void *p0;
    u8 pad4[0x2C];
    f32 f30;
    s16 h34;
    u8 pad36[0x2];
    u8 b38;
    u8 pad39[0x5];
    u8 b3E;
    u8 pad3F[0x1];
    f32 f40;
    u8 pad44[0x2C];
    void *p70;
} Pv_00661A40;

typedef struct Mob_00661A40 {
    u8 pad0[0x10];
    V_00661A40 v10;
    u8 pad20[0x4];
    u8 *p24;
    u8 pad28[0x8];
    u8 b30;
    u8 pad31[0x3];
    u16 h34;
    u8 pad36[0x2C];
    u8 b62;
    u8 pad63[0x5];
    Pv_00661A40 *p68;
    u8 pad6C[0x12];
    u8 b7E;
    u8 pad7F[0x3F];
    s8 bBE;
    u8 padBF[0x1];
    u8 oC0[0x30];
    V_00661A40 vF0;
} Mob_00661A40;

typedef struct O2534_00661A40 {
    u8 pad0[0x56C];
    void *p56C;
    u8 *p570;
} O2534_00661A40;

typedef struct O2530_00661A40 {
    u8 pad0[0x10];
    V_00661A40 v10;
    u8 pad20[0x360];
    u8 o380[0x10];
    u8 pad390[0xD0];
} O2530_00661A40;

typedef struct O4_00661A40 {
    u8 pad0[0x38];
    s32 w38;
} O4_00661A40;

typedef struct O2558_00661A40 {
    u8 pad0[0x4];
    O4_00661A40 *p4;
    u8 pad8[0x8];
    u8 o10[0x10];
    u8 pad20[0xC40];
    s32 wC60;
    s32 wC64;
} O2558_00661A40;

typedef struct P_00661A40 {
    s32 w0;
    u8 pad4[0x10];
    void *vt;
    u8 pad18[0x8];
    V_00661A40 v20;
    u8 pad30[0x10];
    V_00661A40 v40;
    u8 pad50[0x50];
    V_00661A40 vA0;
    V_00661A40 vB0;
    u8 padC0[0x20];
    f32 fE0[4];
    u8 padF0[0xF0];
    f32 f1E0;
    f32 f1E4;
    u8 pad1E8[0xC];
    f32 f1F4;
    u8 pad1F8[0x134];
    s16 h32C;
    u8 pad32E[0xF6];
    u8 *p424;
    u8 pad428[0x50];
    s32 w478;
    u8 pad47C[0xD24];
    u8 o11A0[0x40];
    f32 f11E0;
    u8 pad11E4[0x1C];
    f32 f1200;
    u8 pad1204[0x8C];
    V_00661A40 v1290;
    u8 pad12A0[0x2C];
    s32 w12CC;
    u8 pad12D0[0x8];
    s32 w12D8;
    u8 pad12DC[0x50];
    f32 f132C;
    u8 pad1330[0x6D6];
    u8 b1A06;
    u8 pad1A07[0xA];
    u8 b1A11;
    u8 pad1A12[0x2E];
    u8 o1A40[0x10];
    u8 pad1A50[0xA00];
    s32 w2450;
    u8 pad2454[0x22];
    u8 b2476;
    u8 pad2477[0x4D];
    u8 b24C4;
    u8 b24C5;
    u8 pad24C6[0x3];
    u8 b24C9;
    u8 pad24CA[0x50];
    u8 b251A;
    u8 pad251B[0x5];
    f32 *p2520;
    Mob_00661A40 *mob;
    s32 w2528;
    u8 pad252C[0x4];
    O2530_00661A40 *p2530;
    O2534_00661A40 *p2534;
    f32 f2538;
    f32 f253C;
    f32 f2540;
    s32 w2544;
    s32 w2548;
    s32 w254C;
    u8 pad2550[0x4];
    u8 b2554;
    u8 pad2555[0x3];
    O2558_00661A40 *p2558;
    u8 pad255C[0x3];
    u8 b255F;
    u8 pad2560[0x1DAC];
    u8 o430C[0x10];
    u8 pad431C[0x1E4];
} P_00661A40;

extern P_00661A40 D_L39_002FB000[];
extern u8 D_L39_0047B2E0[];

typedef struct G_00661A40 {
    s32 w0;
    s32 w4;
    s32 w8;
} G_00661A40;

extern G_00661A40 D_001A5CD0;
extern L_00661A40 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 D_001D5A50_sda;
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern u8 D_001FC6B0[];
extern s32 D_L39_00240370[] __attribute__((section(".sdata")));

typedef struct T5810_00661A40 {
    u8 pad0[0x14];
    s32 a14[3][4];
    s32 a44[3][4];
    s32 a74[3][4];
    u8 aA4[8];
} T5810_00661A40;

extern T5810_00661A40 D_001A5810;
extern s32 D_L39_0047A6C0[];
extern P_00661A40 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern s32 D_L39_002410F8[] __attribute__((section(".sdata")));
extern f32 D_L39_0049C750[];
extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;
extern O2530_00661A40 D_L39_0024DE80[];
extern O2534_00661A40 *D_L39_00241170[] __attribute__((section(".sdata")));
extern s32 D_001A58D0[][8];
extern s32 D_001A5930[][8];
extern s32 D_001A5990[][8];
extern E_00661A40 D_001DAAA0_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DAAA0_sda, 8");

extern void *func_L39_00662510(u8 *p);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L39_0061C1E0(void *, s32);
extern void func_L39_005C2FA8(void *, s32);
extern void func_L39_0066EF48(void);
extern void func_L39_00671448(void *, void *, void *, s32);
extern void func_0038D328(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_L39_00630548(void *);
extern void func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00412E70(void *, void *, f32, u8 *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_00412FE0(void *, void *, f32, f32);
extern void func_L39_00646B98(void *);
extern void func_003C7C38(void *);
extern void func_0019A180(s32, void *, void *, void *, s32, s32, f32, s32, void *);
extern void func_L39_0061ECE0(void *, void *, s32);
extern void func_L39_00673540(void *, s32, s32);
extern void func_L39_00647AD0(void *, s32);
extern s32 func_L39_00647A20(void *);
extern void func_L39_00673A80(void *, s32);
extern void func_L39_0063B0A8(void *);
extern void func_L39_0057B4C0(s32, s32);
extern void func_L39_0063AC60(u8 *);

static __inline__ P_00661A40 *Ctor_00661A40(P_00661A40 *p) {
    func_L39_00662510((u8 *)p);
    p->w2544 = -1;
    p->vt = D_L39_0047B2E0;
    return p;
}

static __inline__ void SetF_00661A40(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_00661A40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        s32 t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
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

static __inline__ f32 GetF_00661A40(u8 *q) {
    Buf_00661A40 buf;
    u32 a;

    if (*q == 0) {
        return 0.0f;
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
        buf.w[1] ^= a;
        buf.w[0] = a;
        return buf.f[1];
    }
}

void func_L39_00661A40(s32 idx) {
    P_00661A40 *g = Ctor_00661A40(&D_L39_002FB000[idx]);
    s32 slot = 0;
    s32 n;
    s32 i;
    Mob_00661A40 *m;
    V_00661A40 v0;
    V_00661A40 v1;

    n = 0;
    for (i = 0; i < 8; i++) {
        if (D_L39_00241640->hE0[i] == D_001A5CD0.w8) {
            if (n == idx) {
                slot = i;
                break;
            }
            n++;
        }
    }
    D_001A5810.aA4[slot] = D_001FC6B0[D_L39_00240370[idx] * 0x1F0 + 0x1C];
    m = (Mob_00661A40 *)func_003C24B0(D_L39_0047A6C0[D_L39_00241640->hC0[slot]], 0x80);
    func_L01_00456160((u8 *)m, 0);
    m->b7E = (m->b7E | 0x80) & 0x8F | D_L39_00241640->hD0[slot] * 16;
    *(vu0_q *)&v0 = 0;
    qzero(&v1);
    v0.x = 25.0f;
    v0.y = 25.0f;
    v0.z = 25.0f;
    ((VT_00661A40 *)g->vt)->f24(g, m, &v0, &v1, slot);
    g->w2548 = D_L39_00241640->hD0[g->w2544];
    D_L39_0024CE20[g->w2544] = g;
    func_L39_0061C1E0(g->mob, g->w2544);
    if (g->w2548 == 0) {
        g->mob->bBE |= 0x10;
        g->mob->bBE &= ~8;
    } else if (g->w2548 == 1) {
        g->mob->bBE |= 8;
        g->mob->bBE &= ~0x10;
    }
    D_L39_002410F8[slot] = D_001A5810.aA4[slot];
    g->p2520 = D_L39_0049C750;
    g->b251A = 0;
    SetF_00661A40(&g->b2476, 15.0f);
    SetF_00661A40(&g->b2554, 15.0f);
    g->b255F = 0xFF;
    g->b1A11 = 0;
    g->b24C4 = 0;
    g->b24C5 = 0;
    g->p2530 = &D_L39_0024DE80[idx];
    g->b24C9 = idx;
    g->w2528 = 0;
    g->w254C = 0;
    g->p2534 = D_L39_00241170[idx];
    if (*D_L39_00241120 >= 3) {
        func_L39_005C2FA8(g->p2534, 2);
    } else {
        func_L39_005C2FA8(g->p2534, D_001D5A50_sda);
    }
    g->p2534->p56C = func_L39_0066EF48;
    g->p2534->p570 = g->o430C;
    g->h32C = 10;
    if (*D_L39_00241120 >= 2) {
        g->mob->b62 = 0;
    }
    {
        V_00661A40 v20;
        V_00661A40 v30;
        V_00661A40 v40;
        f32 *p = g->p2520;

        g->f1F4 = p[4];
        g->f1E0 = p[5];
        g->f1E4 = p[6];
        func_L39_00671448(g, &v20, &v30, 1);
        g->vA0 = v20;
        g->vB0 = v30;
        g->p2530->v10 = v30;
        func_0038D328(&g->v20, &g->vB0);
        func_0038D308(g->mob->oC0, &g->vB0);
        if (g->v40.z < 0.866f) {
            g->b1A06 = 1;
        }
        func_L39_00630548(g);
        g->f1200 = 0.0f;
        g->v1290 = g->v20;
        g->f11E0 = g->vB0.z;
        func_L39_00632180((u8 *)g, g->fE0, 1, g->f1200, g->f1200, 0.7f);
        func_0038D308(g->p2530->o380, &v30);
        if (D_001A5810.aA4[g->w2544] == 1) {
            g->f132C = 2.0f;
        } else {
            g->f132C = 1.15f;
        }
        func_0038CF68(&v40, &g->v40, g->f132C);
        vec_add_ab(&v40, &v40, &g->vA0);
        func_L01_00412E70(g->o11A0, &v40, g->vB0.z, g->p424, 0.0f);
        g->w12CC = idx;
        g->w12D8 = g->w2544;
        func_00382760(&g->v1290, 1.0f, g->f11E0, -g->f1200);
        func_L01_00412FE0(g->o11A0, &v40, g->vB0.z, 0.0f);
        func_L39_00646B98(g);
        if (g->mob != 0) {
            g->mob->b30 = 0xFF;
            g->mob->v10 = v20;
            g->mob->vF0 = v30;
            g->mob->h34 |= 0x1000;
            g->mob->h34 |= 0x66;
            g->mob->p68->p70 = g;
            g->mob->p68->p0 = &g->mob->p68->f30;
            g->mob->p68->f30 = GetF_00661A40(&g->b2476);
            g->mob->p68->h34 = 0xF;
            g->mob->p68->f40 = 0.65f;
            g->mob->p68->b38 = g->w2548;
            g->mob->p68->b3E = 1;
            g->mob->p24[0x46] = 5;
            g->mob->b7E |= 2;
            func_003C7C38(g->mob);
        }
        for (i = 0; i < 3; i++) {
            D_001A58D0[i][slot] = D_001A5810.a14[i][idx];
            D_001A5930[i][slot] = D_001A5810.a44[i][idx];
            D_001A5990[i][slot] = D_001A5810.a74[i][idx];
        }
        func_0019A180(g->w2544, &v20, &v30, &D_001DAAA0_sda[g->b251A], g->b251A, g->w2548,
                      GetF_00661A40(&g->b2476), g->w478, &g->p2558);
        func_L39_0061ECE0(g->p2558->o10, &v20, 0);
    }
    g->w0 = g->p2558->p4->w38;
    func_L39_00673540(g->o1A40, 0xB, 0);
    func_L39_00673540(g->o1A40, 0xE, 0);
    if (D_L39_002412DC == 0x7F9) {
        func_L39_00673540(g->o1A40, 9, 0);
    }
    if (D_L39_00241640->b19C != 0) {
        func_L39_00647AD0(g, 3);
    } else {
        s32 r = func_L39_00647A20(g);
        func_L39_00673540(g->o1A40, r, 0);
        func_L39_00673A80(g->o1A40, r);
    }
    if (D_L39_00241640->b19A != 0) {
        func_L39_00673540(g->o1A40, 0xF, 0);
    }
    g->w2450 = 0;
    func_L39_0063B0A8(g);
    func_L39_0057B4C0(idx, 1);
    func_L39_0063AC60((u8 *)g);
    g->p2558->wC60 = -1;
    g->p2558->wC64 = -1;
    g->f2538 = g->vA0.x;
    g->f253C = g->vA0.y;
    g->f2540 = g->vA0.z;
}
/* localdecomp:end func_L39_00661A40 */
