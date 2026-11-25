#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[16];
    u8 unk31;
    u8 pad32[2];
    u16 unk34;
} M3C7568;
typedef struct Moby Moby;
typedef struct {
    char pad0[0x550];
    Moby *child;
} Vars;
struct Moby {
    char pad0[0x42];
    unsigned char anim;
    char pad43[0x48 - 0x43];
    float animSpeed;
    char pad4C[0x68 - 0x4C];
    Vars *vars;
};
typedef int u128_3C9E88 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; u128_3C9E88 pos; u8 pad20[0xE0]; } M_3C9E88;
typedef struct { u8 pad[0x30]; u128_3C9E88 x30; u8 pad40[0x40]; } E_3C9E88;
typedef struct { u8 pad[0x60]; s32 x60; s32 x64; } T_3C9E88;
typedef struct { u8 pad[0x47C]; s32 x47C; u8 pad480[0x10]; u8 x490; u8 x491; u8 pad492[0x4A0 - 0x492]; u128_3C9E88 x4A0; } V_3C9E88;
typedef struct O_3C9E88 O_3C9E88;
struct O_3C9E88 { u8 pad[0x20]; u8 x20; u8 pad21[0x68 - 0x21]; void *x68; u8 pad6C[0xB8 - 0x6C]; O_3C9E88 *xB8; u8 xBC; };
typedef struct M_3CC220 M_3CC220;
typedef struct {
    u8 pad0[0xB0];
    u8 bB0[0xC4 - 0xB0];
    M_3CC220 *tgt;
    u8 padC8[0xD4 - 0xC8];
    f32 fD4;
} V_3CC220;
struct M_3CC220 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3CC220 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
};
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x30 - 0x1C];
} L_3CC220;
typedef struct {
    u8 pad0[0x18];
    M_3CC220 *m18;
} G_3CC220;
typedef struct {
    u8 pad0[44];
    s32 w2C;
    u8 pad1[64 - 48];
    s32 w40;
} Obj3CEDD0;
typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby3CEDD0;
typedef struct {
    void (*f0)(Moby3CEDD0 *);
    s32 pad;
    s32 (*f8)(Moby3CEDD0 *);
} Vt3CEDD0;
typedef int s128 __attribute__((mode(TI)));
typedef struct S_3CF0C0o {
    u8 pad0[0x10];
    s128 x10;
    u8 x20;
    u8 pad21[0xAA - 0x21];
    s16 xAA;
    u8 padac[0xF8 - 0xAC];
    f32 xF8;
    u8 padfc[4];
} S_3CF0C0o;
typedef struct S_3CF0C0f {
    u8 pad0[8];
    s32 (*x8)(S_3CF0C0o *);
    u8 padc[8];
    void (*x14)(S_3CF0C0o *, s32, s128 *, f32 *);
} S_3CF0C0f;
typedef struct S_3CF0C0p {
    u8 pad0[0x28];
    s32 x28;
    s32 x2C;
    u8 pad30[0x10];
    s32 x40;
    u8 pad44[0xE8 - 0x44];
    s32 xE8;
    s32 xEC;
} S_3CF0C0p;

typedef struct {
    u8 pad0[0xF8];
    f32 xF8;
} Self_003D0850;
typedef struct {
    u8 pad0[0x2C];
    s32 w2C;
    u8 pad30[0x40 - 0x30];
    s32 w40;
    u8 pad44[0xBC - 0x44];
    s32 xBC[4];
    u8 padCC[0x130 - 0xCC];
    f32 x130;
} Obj_003D0850;
typedef struct {
    u8 pad0[32];
    u8 b20;
    u8 pad1[170 - 33];
    s16 hAA;
} Moby_003D0850;
typedef struct {
    void (*f0)(Moby_003D0850 *);
    void (*f4)(Moby_003D0850 *, f32, f32, f32);
    s32 (*f8)(Moby_003D0850 *);
} Vt_003D0850;

typedef struct {
    u8 pad0[0x68];
    u8 *vars;
} O_003CB9B0;
typedef struct {
    u8 pad0[0x491];
    u8 x491;
    u8 pad492[0x550 - 0x492];
    u8 *child;
} V_003CB9B0;

/* localdecomp:start func_L01_003C8DE8 */

extern s32 func_L01_004BA800(void);
extern void func_L01_004450F0(M3C7568 *, s32, s32);

void func_L01_003C8DE8(M3C7568 *m) {
    u8 st = m->state;

    switch (st) {
    case 0:
        if (func_L01_004BA800() != 0) {
            m->unk31 = 0;
            m->unk34 |= 1;
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004BA800() == 0) {
            m->unk31 = st;
            m->unk34 &= ~1;
            func_L01_004450F0(m, 0, -1);
        }
        break;
    }
}
/* localdecomp:end func_L01_003C8DE8 */

/* localdecomp:start func_L01_003C8E90 */
int func_L01_003C8E90(void) {
    return 1376;
}
/* localdecomp:end func_L01_003C8E90 */

INCLUDE_ASM("asm/levels", func_L01_003C8E98);

/* localdecomp:start func_L01_003CA630 */
extern s32 func_L01_00335F48(s32);
extern s32 func_L01_003CA6D8(u8 *, u8 *);

s32 func_L01_003CA630(s32 arg) {
    s32 r = func_L01_00335F48(arg);
    func_L01_003CA6D8((u8 *)r, (u8 *)arg);
    return r;
}
/* localdecomp:end func_L01_003CA630 */

/* localdecomp:start func_L01_003CA670 */
extern void func_L01_004450F0(M3C7568 *, s32, s32);
extern void func_003C2880(s32);
extern void func_L01_0044EA78(u8 *, u8 *);
extern void func_L01_003361D8(u8 *);

void func_L01_003CA670(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    if (*(s32 *)(s0 + 1360) != 0) {
        func_003C2880(*(s32 *)(s0 + 1360));
        *(s32 *)(s0 + 1360) = 0;
    }
    func_L01_0044EA78(a0, s0 + 1232);
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 1, -1);
    func_L01_003361D8(a0);
}
/* localdecomp:end func_L01_003CA670 */

/* localdecomp:start func_L01_003CA6D8 */
typedef int u128_3CA6D8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x30]; f32 f30; s16 h34; u8 pad36[2]; u8 b38, b39; u8 pad3A[5]; u8 b3F; f32 f40;
    u8 pad44[0x14]; u8 b58; u8 pad59; u8 b5A; u8 pad5B[0x85];
    u8 bE0, bE1, bE2; u8 padE3[3]; u8 bE6; u8 padE7[9];
    f32 fF0, fF4, fF8, fFC, f100, f104; s16 h108; u8 pad10A[2]; f32 f10C; u8 pad110[8];
    u8 b118, b119; u8 pad11A[0x28]; u8 b142, b143; u8 pad144[3]; u8 b147, b148, b149, b14A, b14B; u8 pad14C[0x44];
    f32 f190, f194, f198, f19C, f1A0; u8 pad1A4[0x18]; f32 f1BC, f1C0, f1C4; u8 pad1C8[0x2E8];
    u128_3CA6D8 q4B0, q4C0; u8 pad4D0[0x80]; s32 w550;
} Vars_3CA6D8;
typedef struct { u8 pad0[0x7A]; s16 h7A; } Other_3CA6D8;
typedef struct { u8 pad0[0x10]; s32 w10; u8 pad14[0x30]; u16 h44; } Owner_3CA6D8;
extern s32 D_001D545C;
extern f32 D_L01_001DAA30;
extern u8 D_0014275B[];
extern f32 D_L01_002F1510[];
extern s32 func_L01_0041A4F0(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_00456160(void *, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);

s32 func_L01_003CA6D8(u8 *self, u8 *other) {
    Vars_3CA6D8 *s0;
    Owner_3CA6D8 *o;
    Other_3CA6D8 *t4;
    s32 a1;
    s32 a;
    f32 f20;
    u16 fl;
    s32 v;
    f32 k15;
    f32 k02;


    if (self[0x20] >= 2 || self == 0) {
        return 0;
    }
    t4 = *(Other_3CA6D8 **)(other + 0x68);
    fl = *(u16 *)(self + 0x34) & 0xFFBC;
    o = *(Owner_3CA6D8 **)(self + 0x24);
    *(u16 *)(self + 0x34) = fl;
    s0 = *(Vars_3CA6D8 **)(self + 0x68);
    *(u16 *)(self + 0x34) = fl | (o->h44 & 0x1000);
    *(s32 *)(self + 0x98) = o->w10;
    s0->h108 = 0;
    s0->b118 = 0xFF;
    s0->bE1 = 8;
    s0->bE2 = 8;
    s0->f100 = 0.5f;
    s0->b147 = 1;
    s0->b148 = 0;
    s0->b149 = 0;
    s0->b14A = 0;
    s0->bE0 = 0x1B;
    s0->fF4 = 0.010000001f;
    k15 = 0.15f;
    k02 = 0.020000001f;
    s0->bE6 = 8;
    s0->f104 = 0.5f;
    s0->f10C = k15;
    s0->fF8 = 0.014f;
    s0->fF0 = k02;
    s0->fFC = 0.00080000004f;
    s0->b14B = 0xFF;
    s0->b142 = 6;
    s0->b143 = 0x10;
    s0->b119 = 1;
    s0->f190 = 0.4f;
    s0->f194 = 0.3f;
    s0->f198 = 2.2f;
    s0->f19C = 2.0f;
    s0->f1A0 = 1.5707964f;
    s0->f1C0 = 3.1415927f;
    s0->f1BC = 0.00392f;
    s0->f1C4 = 2.0f;
    if (D_001D545C == 4) {
        a = *(s16 *)(self + 0xB2);
        if (a == 0x20 || (u16)(*(u16 *)(self + 0xB2) - 0x22B) < 7 || a == 0x4ED) {
            s0->f190 = 0.78f;
        }
    }
    s0->b38 = 1;
    s0->f40 = 0.5f;
    s0->b39 = 0;
    s0->b3F = 0;
    a1 = t4->h7A;
    if (a1 != -1) {
        f20 = (f32)a1;
        if (func_L01_0041A4F0() != 0) {
            v = (s32)(f20 * ((D_001D545C == 7 && D_0014275B[0] != 0) ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C]));
        } else {
            v = (s32)f20;
        }
        s0->h34 = v;
    } else if (s0->h34 == 0 || s0->f30 <= 0.0f) {
        if (func_L01_0041A4F0() != 0) {
            s0->h34 = (s32)(((D_001D545C == 7 && D_0014275B[0] != 0) ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C]) * 30.0f);
        } else {
            s0->h34 = 0x1E;
        }
    }
    s0->b58 = 0x14;
    s0->b5A = 0xE;
    s0->f30 = (f32)s0->h34;
    s0->q4B0 = *(u128_3CA6D8 *)(self + 0x10);
    s0->q4C0 = *(u128_3CA6D8 *)(self + 0xF0);
    func_0038CB78((u8 *)s0 + 0x4D0, 0, 0x80);
    if (s0->w550 == 0) {
        u8 *p = func_003C24B0(0x19C1, 0x80);
        s0->w550 = (s32)p;
        func_L01_00456160(p, self);
    }
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(self, 2, -1);
    func_003C7C38(self);
    return 1;
}
/* localdecomp:end func_L01_003CA6D8 */

/* localdecomp:start func_L01_003CAA80 */
extern u8 D_L01_001E2A40[];
extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
extern void func_L01_0044FD88(u8 *, u8 *, s32, s32);
extern f32 func_L01_0040E548(u8 *, u8 *);
extern void func_L01_004472C0(u8 *);
extern void func_L01_0044E850(u8 *, u8 *, s32, f32, f32);

void func_L01_003CAA80(u8 *a0) {
    u8 *x = 0;
    u8 *s;
    if (*(u8 *)(a0 + 0x20) != 0) {
        u8 *q = *(u8 **)(*(u8 **)(a0 + 0xB8) + 0xB8);
        s = *(u8 **)(a0 + 0x68);
        if (q != 0) {
            x = *(u8 **)(q + 0x68);
        }
        if (x == 0 || *(u8 *)(x + 0x94) == 0) {
            if (func_L01_00452FB0(a0, s + 0xD0, 0, 1, 0) != 0) {
                *(s16 *)(s + 0x36) = 0x4B;
            }
        } else {
            *(u8 *)(a0 + 0xA8) = 0xFF;
        }
        if (*(u8 **)(s + 0x550) != 0) {
            *(long *)(*(u8 **)(s + 0x550) + 0x38) = *(long *)(a0 + 0x38);
            func_L01_0044FD88(a0, *(u8 **)(s + 0x550), 0, 0);
            if (*(u8 *)(*(u8 **)(s + 0x550) + 0x31) != 0 && func_L01_0040E548(D_L01_001E2A40, *(u8 **)(s + 0x550) + 0x10) < 576.0f) {
                func_L01_004472C0(*(u8 **)(s + 0x550));
                *(u8 *)(*(u8 **)(s + 0x550) + 0x6F) = 0x16;
            }
        }
        if (*(u8 *)(a0 + 0x31) != 0 && func_L01_0040E548(D_L01_001E2A40, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            *(u8 *)(a0 + 0x6F) = 0x16;
        }
        func_L01_0044E850(a0, s + 0x4D0, 0, 0.0432f, 0.43200004f);
    }
}
/* localdecomp:end func_L01_003CAA80 */

/* localdecomp:start func_L01_003CABE8 */



extern void func_003C3A10(Moby *, int, int, int);

void func_L01_003CABE8(Moby *m, int anim, int a2, int a3, float speed) {
    Vars *v = m->vars;

    if (m->anim != anim) {
        func_003C3A10(m, anim, a2, a3);
        m->animSpeed = speed;
        if (v->child != 0) {
            func_003C3A10(v->child, anim, a2, a3);
            v->child->animSpeed = speed;
        }
    }
}
/* localdecomp:end func_L01_003CABE8 */

/* localdecomp:start func_L01_003CAC78 */
#include "vu0.h"
extern u8 D_L01_001D66B0[8];
extern void func_003C2F58_003CAC78(s32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_003B1750(void *, void *, void *, u32, u32, u32, u32, f32, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);

void func_L01_003CAC78(u8 *o) {
    vu0_v4 a, b, c;
    u8 *st;
    u8 *own;
    f32 r;

    st = *(u8 **)(o + 0x68);
    own = *(u8 **)(*(u8 **)(*(u8 **)(o + 0xB8) + 0xB8) + 0x68);
    *(vu0_q *)&b = *(vu0_q *)(st + 0x4A0);
    func_003C2F58_003CAC78(*(s32 *)(st + 0x550), 0, &a);
    r = func_003824E0(0.0f, 1.0f);
    if (r <= *(f32 *)(own + 0x84)) {
        f32 ang, h;
        vec_sub_ab(&c, &b, &a);
        ang = func_0038DB00(func_0038D160(c.x, c.y), func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_0038D160(func_0038CED8(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_00382760(&c, 1.0f, func_0038DAB8(func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003B1750(o, &a, &c, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, *(f32 *)(own + 0x80), 0.6499999761581421f);
    } else {
        f32 ang, h;
        b.x += func_L01_00443A18(0.0f, 0.2f);
        b.y += func_L01_00443A18(0.0f, 0.2f);
        b.z += func_L01_00443A18(0.0f, 0.2f);
        vec_sub_ab(&c, &b, &a);
        ang = func_0038DB00(func_0038D160(c.x, c.y), func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)));
        h = func_0038D160(func_0038CED8(&c), c.z);
        if (0.4363323152065277f < ang) {
            ang = 0.4363323152065277f;
        } else if (ang < -0.4363323152065277f) {
            ang = -0.4363323152065277f;
        }
        func_00382760(&c, 1.0f, func_0038DAB8(func_0038DAB8(*(f32 *)(st + 0x518), *(f32 *)(o + 0xF8)), ang), h);
        func_L01_003B1750(o, &a, &c, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.6499999761581421f);
    }
    func_L01_0046A610(&a, D_L01_001D66B0, 0x11, 0x50, 0xFF1010, 0, func_003824E0(8.0f, 10.0f) * 0.25f * 210000.0f, 600.0f, 0.949999988079071f, 0.0f, 0.0f);
}
/* localdecomp:end func_L01_003CAC78 */

/* localdecomp:start func_L01_003CB000 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB000(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 4, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB000 */

/* localdecomp:start func_L01_003CB060 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB060(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 5, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB060 */

/* localdecomp:start func_L01_003CB0C0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB0C0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 6, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB0C0 */

/* localdecomp:start func_L01_003CB120 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB120(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 7, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB120 */

/* localdecomp:start func_L01_003CB180 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB180(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 8, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB180 */

/* localdecomp:start func_L01_003CB1E0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB1E0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 9, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB1E0 */

/* localdecomp:start func_L01_003CB240 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB240(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 10, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB240 */

/* localdecomp:start func_L01_003CB2A0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB2A0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 11, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB2A0 */

/* localdecomp:start func_L01_003CB300 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB300(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 12, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB300 */

/* localdecomp:start func_L01_003CB360 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB360(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 14, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB360 */

/* localdecomp:start func_L01_003CB3C0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB3C0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 15, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB3C0 */

/* localdecomp:start func_L01_003CB420 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB420(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 16, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB420 */

/* localdecomp:start func_L01_003CB480 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB480(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 17, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB480 */

/* localdecomp:start func_L01_003CB4E0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB4E0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 18, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB4E0 */

/* localdecomp:start func_L01_003CB540 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB540(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 19, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB540 */

/* localdecomp:start func_L01_003CB5A0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB5A0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 20, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB5A0 */

/* localdecomp:start func_L01_003CB600 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB600(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 21, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB600 */

/* localdecomp:start func_L01_003CB660 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB660(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 22, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB660 */

/* localdecomp:start func_L01_003CB6C0 */
extern void func_L01_00445130(u8 *, s32, s32);

s32 func_L01_003CB6C0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_L01_00445130(a0, 23, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB6C0 */

/* localdecomp:start func_L01_003CB720 */
extern void func_L01_004450F0(M3C7568 *, s32, s32);
extern M_3C9E88 *D_L01_001E001C;
extern E_3C9E88 *D_L01_001E0100;
s32 func_L01_003CB720(O_3C9E88 *a0, s32 a1, s32 a2) {
    V_3C9E88 *v = a0->x68;
    T_3C9E88 *t = a0->xB8->xB8->x68;
    u8 old = a0->x20;

    if (v->x491) {
        return 0;
    }
    v->x490 = a1;
    v->x47C = a2;
    if (a0->x20 != 24) {
        if (t->x60 != -1) {
            v->x4A0 = *(u128_3C9E88 *)((u8 *)D_L01_001E001C + (t->x60 << 8) + 0x10);
        } else if (t->x64 != -1) {
            v->x4A0 = *(u128_3C9E88 *)((u8 *)D_L01_001E0100 + (t->x64 << 7) + 0x30);
        }
        a0->xBC = 0;
        ((void (*)(O_3C9E88 *, s32, s32))func_L01_004450F0)(a0, 24, -1);
    }
    return a0->x20 != old;
}
/* localdecomp:end func_L01_003CB720 */

/* localdecomp:start func_L01_003CB7E0 */
extern void func_L01_004450F0(M3C7568 *, s32, s32);
s32 func_L01_003CB7E0(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 25, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB7E0 */

/* localdecomp:start func_L01_003CB840 */
extern void func_L01_004450F0(M3C7568 *, s32, s32);
s32 func_L01_003CB840(u8 *a0, s32 a1, s32 a2) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (p[1169] != 0) {
        return 0;
    }
    p[1168] = a1;
    *(s32 *)(p + 1148) = a2;
    ((void (*)(u8 *a0, s32 a1, s32 a2))func_L01_004450F0)(a0, 26, -1);
    return a0[32] != old;
}
/* localdecomp:end func_L01_003CB840 */

/* localdecomp:start func_L01_003CB8A0 */
s32 func_L01_003CB8A0(u8 *obj) {
    return obj[32] == 27;
}
/* localdecomp:end func_L01_003CB8A0 */

/* localdecomp:start func_L01_003CB8B0 */
s32 func_L01_003CB8B0(u8 *a) {
    u8 t = a[32];
    s32 r = 0;
    if (t == 28 || a == 0 || t == 254 || t == 253) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003CB8B0 */

/* localdecomp:start func_L01_003CB8E8 */
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2F58(u8 *, s32, f32 *);

void func_L01_003CB8E8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 buf[4];

    func_L01_00409598(m, m + 0x10, m + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
    if (*(u8 **)(v + 0x550) != 0) {
        func_003C2F58(m, 0, buf);
        func_L01_00409598(*(u8 **)(v + 0x550), (u8 *)buf, m + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
    }
}
/* localdecomp:end func_L01_003CB8E8 */

/* localdecomp:start func_L01_003CB9B0 */
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(M3C7568 *, s32, s32);

void func_L01_003CB9B0(O_003CB9B0 *a0) {
    V_003CB9B0 *v = (V_003CB9B0 *)a0->vars;

    func_L01_00409598((u8 *)a0, (u8 *)a0 + 0x10, (u8 *)a0 + 0xF0, 1, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
    func_L01_00409598(v->child, v->child + 0x10, v->child + 0xF0, 1, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
    v->x491 = 1;
    ((void (*)(void *, s32, s32))func_L01_004450F0)(a0, 3, -1);
}
/* localdecomp:end func_L01_003CB9B0 */

/* localdecomp:start func_L01_003CBA70 */
extern void func_L01_004AA7E8(u8 *, s32);

void func_L01_003CBA70(u8 *a0) {
    u8 *s1;
    *(s32 *)(a0 + 152) = 0;
    *(u16 *)(a0 + 52) |= 0x41;
    *(u16 *)(a0 + 52) &= ~0x1000;
    s1 = *(u8 **)(a0 + 104);
    func_L01_004AA7E8(a0, 1);
    *(u16 *)(a0 + 52) |= 2;
    if (*(u8 **)(s1 + 1360) != 0) {
        *(u16 *)(*(u8 **)(s1 + 1360) + 52) |= 0x41;
        *(u16 *)(*(u8 **)(s1 + 1360) + 52) &= ~0x1000;
        *(s32 *)(*(u8 **)(s1 + 1360) + 152) = 0;
        func_L01_004AA7E8(*(u8 **)(s1 + 1360), 1);
        *(u16 *)(*(u8 **)(s1 + 1360) + 52) |= 2;
    }
}
/* localdecomp:end func_L01_003CBA70 */

/* localdecomp:start func_L01_003CBB10 */
int func_L01_003CBB10(u8 *a) {
    return *(int *)(a + 104);
}
/* localdecomp:end func_L01_003CBB10 */

/* localdecomp:start func_L01_003CBB18 */
extern u8 D_L01_002BB4B0[];

u8 *func_L01_003CBB18(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 4) {
        *a2 = 156;
        return D_L01_002BB4B0;
    }
    return 0;
}
/* localdecomp:end func_L01_003CBB18 */

/* localdecomp:start func_L01_003CBB40 */
extern u8 D_001A4BE0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern void func_003C4360(f32 *, f32, f32, f32, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);

void func_L01_003CBB40(u8 *obj, u8 *q) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 u;
    vu0_v4 n;
    f32 x;
    f32 old;
    f32 l;
    f32 ad;
    u8 *h;

    t.x = func_0038D098(*(f32 *)(q + 0x488)) * *(f32 *)(q + 0x48C);
    t.y = func_0038D0B0(*(f32 *)(q + 0x488)) * *(f32 *)(q + 0x48C);
    t.z = 0.0f;
    vec_add_ab(&t, &t, q + 0x4B0);
    old = *(f32 *)(q + 0x238);
    vec_sub_ab(&d, &t, obj + 0x10);
    *(f32 *)(q + 0x238) = 0.0f;
    d.z = 0.0f;
    func_0038CF68(&u, &d, 1.0f);
    func_0038CE90(&n, &u, obj + 0xE0);
    func_0038CF68(&n, &n, 1.0f);
    x = func_0038CE68(&n, q + 0x230);
    if (0.0014000001f < x) {
        x = 0.0014000001f;
    } else if (x < -0.0014000001f) {
        x = -0.0014000001f;
    }
    func_0038CF68(&n, &n, x);
    vec_sub_ba(q + 0x230, q + 0x230, &n);
    l = func_0038CED8(&d);
    x = func_0038CED8(q + 0x230);
    func_003C4360(&x, l, 0.0028000001f, 0.0016000001f, 0.120000005f);
    func_0038CF68(&u, &d, 0.0028000001f);
    vec_add_ab(q + 0x230, q + 0x230, &u);
    if (x < func_0038CED8(q + 0x230)) {
        func_0038CF68(q + 0x230, q + 0x230, x);
    }
    if (obj[0x20] == 0x13) {
        *(f32 *)(q + 0x238) = old + 0.040000003f;
        if (-0.10000001f < *(f32 *)(q + 0x238))
            *(f32 *)(q + 0x238) = -0.10000001f;
    } else {
        *(f32 *)(q + 0x238) = old;
        h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0xB0 && (ad = fabs_asm(*(f32 *)(h + 0x88) - *(f32 *)(obj + 0x18))) < 2.25f) {
            if (*(f32 *)(obj + 0x18) < *(f32 *)(h + 0x88)) {
                *(f32 *)(q + 0x238) = old - 0.020000001f;
                if (*(f32 *)(q + 0x238) < -0.26000002f)
                    *(f32 *)(q + 0x238) = -0.26000002f;
            } else {
                *(f32 *)(q + 0x238) = old + 0.020000001f;
                if (-0.18f < *(f32 *)(q + 0x238))
                    *(f32 *)(q + 0x238) = -0.18f;
            }
        } else if (*(s32 *)(h + 0x25C4) == 0xB0 && 10.0f < ad) {
            if (*(f32 *)(obj + 0x18) < *(f32 *)(h + 0x88)) {
                *(f32 *)(q + 0x238) = old + 0.020000001f;
                if (-0.18f < *(f32 *)(q + 0x238))
                    *(f32 *)(q + 0x238) = -0.18f;
            } else {
                *(f32 *)(q + 0x238) = old - 0.020000001f;
                if (*(f32 *)(q + 0x238) < -0.26000002f)
                    *(f32 *)(q + 0x238) = -0.26000002f;
            }
        } else {
            *(f32 *)(q + 0x238) = *(f32 *)(q + 0x238) - 0.020000001f;
            if (*(f32 *)(q + 0x238) < -0.22000001f)
                *(f32 *)(q + 0x238) = -0.22000001f;
        }
    }
    vec_add_ba(obj + 0x10, obj + 0x10, q + 0x230);
    *(f32 *)(q + 0x220) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
}
/* localdecomp:end func_L01_003CBB40 */

/* localdecomp:start func_L01_003CBEF0 */
extern void func_0038CC88(void *, void *, s32);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9740(void *, s32, f32, s32, s32, s32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);

void func_L01_003CBEF0(u8 *obj) {
    vu0_v4 r;
    vu0_v4 a;
    vu0_v4 p;
    vu0_v4 m1[4];
    vu0_v4 m2[4];
    vu0_v4 m3[4];
    u8 *v = *(u8 **)(obj + 0x68);
    f32 t;
    f32 k0;
    f32 k1;
    s32 i;
    s32 col;

    func_0038CE20((f32 *)&a, obj + 0xC0, -0.1f);
    a.z = a.z - 0.15f;
    qzero(&r);
    r.z = func_00382538();
    func_0038D328(m1, &r);
    func_0038CC88(m2, m1, 0x40);
    func_0038CC88(m3, m1, 0x40);
    if (obj[0x20] == 0x14) {
        if (*(s32 *)(v + 0x554) >= 6)
            return;
        t = (f32)*(s32 *)(v + 0x554) / 5.0f;
        k1 = 1.0f - t * 0.5f;
        k0 = 1.0f - t * 0.9f;
        func_0038CE20((f32 *)&m1[0], &m1[0], func_003824E0(0.9f, 1.1f) * 0.55f * k0);
        func_0038CE20((f32 *)&m1[1], &m1[1], func_003824E0(0.9f, 1.1f) * 0.55f * k0);
        func_0038CE20((f32 *)&m1[2], &m1[2], func_003824E0(0.8f, 1.2f) * 0.45f * k1);
        func_0038CE20((f32 *)&m2[0], &m2[0], func_003824E0(0.9f, 1.1f) * 0.3f * k0);
        func_0038CE20((f32 *)&m2[1], &m2[1], func_003824E0(0.9f, 1.1f) * 0.3f * k0);
        func_0038CE20((f32 *)&m2[2], &m2[2], func_003824E0(0.8f, 1.2f) * 0.9f * k1);
        func_0038CE20((f32 *)&m3[0], &m3[0], func_003824E0(0.9f, 1.1f) * 0.15f * k0);
        func_0038CE20((f32 *)&m3[1], &m3[1], func_003824E0(0.9f, 1.1f) * 0.15f * k0);
        func_0038CE20((f32 *)&m3[2], &m3[2], func_003824E0(0.8f, 1.2f) * k1);
    } else {
        func_0038CE20((f32 *)&m1[0], &m1[0], func_003824E0(0.9f, 1.1f) * 0.55f);
        func_0038CE20((f32 *)&m1[1], &m1[1], func_003824E0(0.9f, 1.1f) * 0.55f);
        func_0038CE20((f32 *)&m1[2], &m1[2], func_003824E0(0.8f, 1.2f) * 0.45f);
        func_0038CE20((f32 *)&m2[0], &m2[0], func_003824E0(0.9f, 1.1f) * 0.3f);
        func_0038CE20((f32 *)&m2[1], &m2[1], func_003824E0(0.9f, 1.1f) * 0.3f);
        func_0038CE20((f32 *)&m2[2], &m2[2], func_003824E0(0.8f, 1.2f) * 0.9f);
        func_0038CE20((f32 *)&m3[0], &m3[0], func_003824E0(0.9f, 1.1f) * 0.15f);
        func_0038CE20((f32 *)&m3[1], &m3[1], func_003824E0(0.9f, 1.1f) * 0.15f);
        func_0038CE20((f32 *)&m3[2], &m3[2], func_003824E0(0.8f, 1.2f));
    }
    for (i = 0; i < 2; i++) {
        func_003C2F58(obj, i + 1, (f32 *)&p);
        vec_sub_ab(&m1[3], &p, &m1[2]);
        vec_add_ab(&m1[3], &m1[3], &a);
        func_003D9740(m1, 0x1E, 0.0f, 0x7F00307F, 5, 1);
        vec_sub_ab(&m2[3], &p, &m2[2]);
        vec_add_ab(&m2[3], &m2[3], &a);
        func_003D9740(m2, 0x1E, 0.0f, 0x7F00607F, 5, 1);
        vec_sub_ab(&m3[3], &p, &m3[2]);
        vec_add_ab(&m3[3], &m3[3], &a);
        func_003D9740(m3, 0x1E, 0.0f, 0x7F00307F, 6, 1);
    }
    if (obj[0x20] == 0x12) {
        if (*(s32 *)(v + 0x554) >= 13)
            return;
        t = (f32)*(s32 *)(v + 0x554) / 12.0f;
        k0 = t * -0.70000005f + 1.2f;
        k1 = t * 1.6f + 0.15f;
        func_0038CF68(&m1[0], &m1[0], k0 * func_003824E0(0.95f, 1.05f));
        func_0038CF68(&m1[1], &m1[1], k0 * func_003824E0(0.95f, 1.05f));
        func_0038CF68(&m1[2], &m1[2], k1 * func_003824E0(0.95f, 1.05f));
        if (t < 0.8f)
            col = 0x7F20307F;
        else
            col = func_0038DBD8(0x7F20307F, 0x7F000000, (t - 0.8f) * 5.0f);
        for (i = 0; i < 2; i++) {
            func_003C2F58(obj, i + 1, (f32 *)&p);
            vec_sub_ab(&m1[3], &p, &m1[2]);
            vec_add_ab(&m1[3], &m1[3], &a);
            func_003D9740(m1, 0x1E, 0.0f, col, 4, 1);
        }
    }
}
/* localdecomp:end func_L01_003CBEF0 */

/* localdecomp:start func_L01_003CC610 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CC610;
typedef struct { u8 pad[0x5C]; u8 *p5C; } S_003CC610;

extern S_003CC610 D_L01_00221098;
__asm__(".extern D_L01_00221098, 16");
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L01_003CC610(s32 a0, s32 a1, V4_003CC610 *a2, s32 a3) {
    V4_003CC610 s;
    V4_003CC610 p;
    V4_003CC610 q;
    V4_003CC610 *pp;
    V4_003CC610 *qq;
    f32 d;
    f32 r;
    f32 t;
    s32 n;
    u8 *b;

    s = *a2;
    p = *a2;
    t = func_003C3D30(&s, 0, 0, 0.5f);
    d = s.z - t;
    p.z = t;
    if (d > 0.0f && d < 12.0f) {
        r = (d - 6.0f) / 6.0f;
        if (r > 1.0f) {
            r = 1.0f;
        } else if (r < 0.0f) {
            r = 0.0f;
        }
        n = 127 - (s32)(r * 127.0f);
        if (n >= 15 && a3 > 0) {
            pp = &p;
            qq = &q;
            do {
                q.x = func_0038D098(func_00382538()) * 0.040000003f;
                q.y = func_0038D0B0(func_00382538()) * 0.040000003f;
                q.z = 0.0060000005f;
                b = func_L01_0046FB40(pp, qq, 0x32, 0x303234, func_00382468(3), n, 7, 0, 63000.004f, 105000.0f, 0.0f);
                if (b != 0) {
                    b[2] = *D_L01_00221098.p5C;
                    b[3] = 0x48;
                }
                a3--;
            } while (a3 != 0);
        }
    }
}
/* localdecomp:end func_L01_003CC610 */

/* localdecomp:start func_L01_003CC808 */
extern s32 D_L01_001DFB40;
extern void func_0038CE20(f32 *, void *, f32);

void func_L01_003CC808(u8 *a0, u8 *a1) {
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    if (((*(s16 *)(a0 + 0xB2) + D_L01_001DFB40) & 1) == 0) {
        func_0038CE20(&d.x, a0 + 0xC0, -0.1f);
        d.z -= 0.15f;
        for (i = 0; i < 2; i++) {
            func_003C2F58(a0, i + 1, (f32 *)&p);
            vec_add_ab(&p, &p, &d);
            func_L01_003CC610((s32)a0, (s32)a1, (V4_003CC610 *)&p, 1);
        }
    }
}
/* localdecomp:end func_L01_003CC808 */

LINKER_REMNANT("asm/levels", func_L01_003CC8D0);

/* localdecomp:start func_L01_003CC8D8 */
extern void func_003A52A0(s32, s32, u8 *);
extern void func_003C2880(s32);
extern void func_L01_00409428(u8 *, u8 *, u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);

void func_L01_003CC8D8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (*(u8 *)(s + 0x30) != 0 && *(s16 *)(s + 0x28) == 1) {
        u8 *t = *(u8 **)(a0 + 0xB8);
        *(u8 *)(t + 0x23) = 0x80;
        *(u16 *)(t + 0x34) = (*(u16 *)(t + 0x34) | 1) & 0xFFFD;
        func_003A52A0(1, 0, a0);
        func_003C2880((s32)a0);
    } else if (*(s16 *)(s + 0x28) == 2) {
        u8 *t = *(u8 **)(a0 + 0xB8);
        *(u16 *)(t + 0x34) = (*(u16 *)(t + 0x34) & 0xFFBC) | 0x1000;
        *(s32 *)(t + 0x98) = *(s32 *)(*(u8 **)(t + 0x24) + 0x10);
        func_003A52A0(0, 0, a0);
        func_003C2880((s32)a0);
    } else {
        func_L01_00409428(*(u8 **)(a0 + 0xB8), s + 0x2A, s + 0x28, s, s + 0x10, *(u8 *)(s + 0x2E), *(u8 *)(s + 0x2F), *(s16 *)(s + 0x2C), *(s32 *)(s + 0x20), *(s32 *)(s + 0x24));
    }
}
/* localdecomp:end func_L01_003CC8D8 */
