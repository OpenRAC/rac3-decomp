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
extern void func_L01_003CA6D8(s32, s32);

s32 func_L01_003CA630(s32 arg) {
    s32 r = func_L01_00335F48(arg);
    func_L01_003CA6D8(r, arg);
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

INCLUDE_ASM("asm/levels", func_L01_003CA6D8);

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

INCLUDE_ASM("asm/levels", func_L01_003CAC78);

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

INCLUDE_ASM("asm/levels", func_L01_003CBB40);

INCLUDE_ASM("asm/levels", func_L01_003CBEF0);

INCLUDE_ASM("asm/levels", func_L01_003CC610);

INCLUDE_ASM("asm/levels", func_L01_003CC808);

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

INCLUDE_ASM("asm/levels", func_L01_003CC9C8);

/* localdecomp:start func_L01_003CCB58 */
typedef int Q_3CCB58 __attribute__((mode(TI)));
extern void func_L01_003CCED8_003CCB58(M_3CC220 *, void *);
extern int func_0038CAD0(void *);
extern void func_003C2880(s32);
extern void func_L01_003CD068_003CCB58(u8 *);
extern void func_L01_00404A10_003CCB58(void *, void *);

void func_L01_003CCB58(M_3CC220 *m) {
    u8 *v = (u8 *)m->vars;
    Q_3CCB58 old;
    switch (m->b20) {
    case 0:
        m->b20 = 1;
    case 1: {
        u8 *pos = m->pos;
        old = *(Q_3CCB58 *)pos;
        vec_add_ba(pos, v, pos);
        func_L01_003CCED8_003CCB58(m, &old);
        if (func_0038CAD0(v + 0x10)) {
            m->b20 = 2;
        }
        break;
    }
    case 2:
        func_003C2880((s32)m);
        return;
    }
    func_L01_00404A10_003CCB58(func_L01_003CD068_003CCB58, m);
}
/* localdecomp:end func_L01_003CCB58 */

INCLUDE_ASM("asm/levels", func_L01_003CCC20);

/* localdecomp:start func_L01_003CCED8 */
__asm__(".extern D_L01_001DF00C_003CCED8, 4");
__asm__(".extern D_L01_001DF010_003CCED8, 4");
extern f32 D_L01_001DF00C_003CCED8;
extern f32 D_L01_001DF010_003CCED8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    M_3CC220 *tgt;
    s32 w24;
} V_3CCED8_003CCED8;
extern M_3CC220 *D_L01_001EAA18_003CCED8[];
extern G_3CC220 D_L01_001EAA00_003CCED8;
extern void func_L01_004CB320_003CCED8(void);
extern void func_L01_004CB358_003CCED8(void);
extern int func_L01_003FA5F0_003CCED8(void *, void *, int, M_3CC220 *, int);
extern void func_L01_0040E620_003CCED8(f32 *, V_3CCED8_003CCED8 *, f32);
extern void func_L01_00446A70_003CCED8(M_3CC220 *, M_3CC220 *, int, void *, f32 *, f32);
extern void func_L01_003CD248_003CCED8(void *, int, int, int, M_3CC220 *);

void func_L01_003CCED8(M_3CC220 *m, void *a1) {
    f32 buf[4];
    void *pos = m->pos;
    V_3CCED8_003CCED8 *v = (V_3CCED8_003CCED8 *)m->vars;
    M_3CC220 *p;
    int r;
    f32 f;

    func_L01_004CB320_003CCED8();
    r = func_L01_003FA5F0_003CCED8(a1, pos, 0, m, 0);
    if (r != 0) {
        p = D_L01_001EAA18_003CCED8[0];
        if (p != 0 && p->hAA == 6253 && p->b20 != 2 && p->b20 != 5) {
            p->b20 = 4;
        }
    }
    func_L01_004CB358_003CCED8();
    if (r == 0) {
        return;
    }
    if (D_L01_001EAA00_003CCED8.m18 != 0) {
        if (D_L01_001EAA00_003CCED8.m18 != v->tgt && (D_L01_001EAA00_003CCED8.m18->h34 & 0x4000)) {
            f = D_L01_001DF00C_003CCED8;
            if (v->w24 == 0) {
                f *= 0.5f;
            }
            func_L01_0040E620_003CCED8(buf, v, f);
            buf[2] = D_L01_001DF010_003CCED8;
            buf[3] = 5627.9248046875f;
            func_L01_00446A70_003CCED8(D_L01_001EAA00_003CCED8.m18, m, 0x10001, m->pos, buf, v->f1C);
            func_L01_003CD248_003CCED8(m->pos, 10, 2, 1, m);
        }
        if (D_L01_001EAA00_003CCED8.m18 != 0) {
            m->b20 = 2;
            return;
        }
    }
    func_L01_003CD248_003CCED8(m->pos, 15, 5, 0, m);
    m->b20 = 2;
}
/* localdecomp:end func_L01_003CCED8 */

INCLUDE_ASM("asm/levels", func_L01_003CD068);

INCLUDE_ASM("asm/levels", func_L01_003CD248);

/* localdecomp:start func_L01_003CD778 */
typedef int Q_3CD778 __attribute__((mode(TI)));
extern void func_L01_003CDDD8(void *, int, int, int, M_3CC220 *, int);
extern void func_L01_003CDB08(M_3CC220 *, int);
extern void func_L01_003CE2E8(u8 *);
extern int func_0038CAD0(void *);
extern void func_L01_003CDCE8(u8 *);
extern void func_L01_00404A10_003CD778(void *, void *);

void func_L01_003CD778(M_3CC220 *m) {
    V_3CC220 *v = m->vars;
    Q_3CD778 old;
    switch (m->b20) {
    case 0:
        m->b20 = 1;
    case 1: {
        u8 *pos = m->pos;
        old = *(Q_3CD778 *)pos;
        vec_add_ba(pos, v->bB0, pos);
        func_L01_003CDB08(m, (int)&old);
        func_L01_003CE2E8((u8 *)m);
        if (func_0038CAD0((u8 *)v + 0xD0)) {
            m->b20 = 2;
            func_L01_003CDDD8(pos, 20, 5, 0, m, v->tgt != 0);
        }
        break;
    }
    case 2:
        func_003C2880((s32)m);
        return;
    }
    func_L01_00404A10_003CD778(func_L01_003CDCE8, m);
}
/* localdecomp:end func_L01_003CD778 */

INCLUDE_ASM("asm/levels", func_L01_003CD878);

/* localdecomp:start func_L01_003CDB08 */





extern M_3CC220 *D_L01_001EAA18[];
extern G_3CC220 D_L01_001EAA00;
extern void func_0038CF68(f32 *, void *, f32);
extern void func_L01_00446760(L_3CC220 *, M_3CC220 *, int, f32 *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern int func_003D3CB0(int, void *, int, M_3CC220 *, L_3CC220 *);
extern void func_L01_00446978(M_3CC220 *, L_3CC220 *);
extern void func_L01_003CDDD8(void *, int, int, int, M_3CC220 *, int);

void func_L01_003CDB08(M_3CC220 *m, int a1) {
    f32 buf[4];
    L_3CC220 l;
    void *pos = m->pos;
    V_3CC220 *v = m->vars;
    M_3CC220 *p;
    int r;

    func_0038CF68(buf, v->bB0, 1.0f);
    func_L01_00446760(&l, m, 0x410001, buf, v->fD4);
    l.b18 = 5;
    l.h1A = m->hAA;
    l.b19 = 3;
    func_L01_004CB320();
    r = func_003D3CB0(a1, pos, 16, m, &l);
    if (r != 0) {
        p = D_L01_001EAA18[0];
        if (p != 0 && p->hAA == 6253 && p->b20 != 2 && p->b20 != 5) {
            p->b20 = 4;
        }
    }
    func_L01_004CB358();
    if (r == 0) {
        return;
    }
    if (D_L01_001EAA00.m18 != 0) {
        if (D_L01_001EAA00.m18 != v->tgt && (D_L01_001EAA00.m18->h34 & 0x4000)) {
            func_0038CF68(buf, v->bB0, 1.0f);
            func_L01_00446760(&l, m, 0x410001, buf, v->fD4);
            l.b18 = 5;
            l.b19 = 3;
            l.h1A = m->hAA;
            func_L01_00446978(D_L01_001EAA00.m18, &l);
            func_L01_003CDDD8(m->pos, 30, 10, 1, m, v->tgt != 0);
        }
        if (D_L01_001EAA00.m18 != 0) {
            m->b20 = 2;
            return;
        }
    }
    func_L01_003CDDD8(m->pos, 20, 5, 0, m, v->tgt != 0);
    m->b20 = 2;
}
/* localdecomp:end func_L01_003CDB08 */

/* localdecomp:start func_L01_003CDCE8 */
__asm__(".extern D_L01_001DF160, 8");
__asm__(".extern D_L01_001DF170, 8");
__asm__(".extern D_L01_001DF180, 8");
__asm__(".extern D_L01_001DF190, 8");
extern f32 D_L01_001DF160[2];
extern s32 D_L01_001DF170[2];
extern s32 D_L01_001DF180[2];
extern s32 D_L01_001DF190[2];
extern f32 func_00382538(void);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040C948(u8 *, s32);

void func_L01_003CDCE8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 f = *(f32 *)(s + 0xCC) - 0.1f;
    s32 i;
    *(f32 *)(s + 0xCC) = f;
    if (f <= -8.0f) {
        *(f32 *)(s + 0xCC) = f + 8.0f;
    }
    for (i = 0; i < 3; i++) {
        func_003D9508(a0 + 0x10, D_L01_001DF180[i], D_L01_001DF170[i], D_L01_001DF190[i], D_L01_001DF160[i], 0.0f, func_00382538());
    }
    func_L01_0040C948(s, *(s32 *)(s + 0xC0));
}
/* localdecomp:end func_L01_003CDCE8 */

INCLUDE_ASM("asm/levels", func_L01_003CDDD8);

/* localdecomp:start func_L01_003CE2E8 */
__asm__(".extern D_L01_001DF0A8, 4");
__asm__(".extern D_L01_001DF0A0, 4");
__asm__(".extern D_L01_001DF0A4, 4");
extern void func_L01_0043A778(s32, s32, u8 *);
extern s32 func_L01_0040F550(s32, s32, f32);
extern void func_L01_0040C8A0(u8 *, s32);
extern s32 D_L01_001DF0A8;
extern s32 D_L01_001DF0A0;
extern s32 D_L01_001DF0A4;

void func_L01_003CE2E8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s + 0xC4) != 0) {
        f32 f;
        s32 a;
        s32 b;
        s32 c;
        func_L01_0043A778(*(s32 *)(s + 0xC4), *(s32 *)(s + 0xC8), s);
        *(s128 *)(s + 0x10) = *(s128 *)(a0 + 0x10);
        f = (f32)*(s32 *)(s + 0xD0);
        f = f / (f32)((D_L01_001DF0A8 * 5 + 2) / 6);
        a = func_L01_0040F550(0, D_L01_001DF0A0, f);
        b = D_L01_001DF0A4;
        *(s32 *)(s + 0x24) = a;
        c = func_L01_0040F550(0, b, f);
        b = D_L01_001DF0A0;
        *(s32 *)(s + 0x2C) = c;
        c = func_L01_0040F550(0, b, f);
        b = D_L01_001DF0A4;
        *(s32 *)(s + 0x20) = c;
        c = func_L01_0040F550(0, b, f);
        *(s32 *)(s + 0x28) = c;
        func_L01_0040C8A0(s, *(s32 *)(s + 0xC0));
    }
}
/* localdecomp:end func_L01_003CE2E8 */

/* localdecomp:start func_L01_003CE3D0 */
typedef int Q_3CE3D0 __attribute__((mode(TI)));
typedef struct {
    f32 v0[4];
    u8 pad10[4];
    f32 f14;
    s32 t18;
    s32 t1C;
    f32 f20;
    f32 f24;
} V_3CE3D0_003CE3D0;
typedef struct M_3CE3D0_003CE3D0 M_3CE3D0_003CE3D0;
struct M_3CE3D0_003CE3D0 {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    V_3CE3D0_003CE3D0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
    u8 padAC[0xB2 - 0xAC];
    s16 hB2;
    u8 padB4[0xB8 - 0xB4];
    M_3CE3D0_003CE3D0 *obj;
    u8 padBC[0xC0 - 0xBC];
    u8 rot[0x10];
};

__asm__(".extern D_L01_001DF1DC_003CE3D0, 4");
__asm__(".extern D_L01_001DF1E0_003CE3D0, 4");
__asm__(".extern D_L01_001DF1E4_003CE3D0, 4");
__asm__(".extern D_L01_001DF1E8_003CE3D0, 4");
__asm__(".extern D_L01_001DF1EC_003CE3D0, 4");
__asm__(".extern D_L01_001DF1F4_003CE3D0, 4");
__asm__(".extern D_L01_001DF1F8_003CE3D0, 4");
__asm__(".extern D_L01_001DF204_003CE3D0, 4");
__asm__(".extern D_L01_001DF208_003CE3D0, 4");
extern f32 D_L01_001DF1DC_003CE3D0;
extern f32 D_L01_001DF1E0_003CE3D0;
extern f32 D_L01_001DF1E4_003CE3D0;
extern f32 D_L01_001DF1E8_003CE3D0;
extern f32 D_L01_001DF1EC_003CE3D0;
extern f32 D_L01_001DF1F4_003CE3D0;
extern f32 D_L01_001DF1F8_003CE3D0;
extern f32 D_L01_001DF204_003CE3D0;
extern f32 D_L01_001DF208_003CE3D0;
extern s32 D_L01_001DFB40_003CE3D0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern M_3CC220 *D_L01_001EAA18_003CE3D0[];
extern void func_L01_00446760_003CE3D0(L_3CC220 *, M_3CC220 *, int, f32 *, f32);
extern void func_L01_004CB320_003CE3D0(void);
extern void func_L01_004CB358_003CE3D0(void);
extern int func_003D3CB0(int, void *, int, M_3CC220 *, L_3CC220 *);
extern int func_0038CAD0(void *);
extern void func_003C2880(s32);
extern s32 func_L01_003FB640_003CE3D0(void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_003303B8_003CE3D0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_004450F0_003CE3D0(M3C7568 *, s32, s32);
extern void func_0038CF68(f32 *, void *, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_003CE8A8_003CE3D0(M_3CE3D0_003CE3D0 *);
extern void func_L01_00404A10_003CE3D0(void *, void *);

void func_L01_003CE3D0(M_3CE3D0_003CE3D0 *m) {
    V_3CE3D0_003CE3D0 *v = m->vars;
    vu0_v4 np;
    f32 buf[4];
    L_3CC220 l;
    f32 s;
    int r;
    u8 *pos;
    M_3CE3D0_003CE3D0 *o;
    L_3CC220 *lp;

    if (m->b20 == 2) {
        v->f20 = v->f20 - D_L01_001DF1E4_003CE3D0;
        if (v->f20 < 0.01f) {
            func_003C2880((s32)m);
            return;
        }
    } else {
        if (v->f20 < D_L01_001DF1E0_003CE3D0) {
            v->f20 = v->f20 + D_L01_001DF1DC_003CE3D0;
            if (D_L01_001DF1E0_003CE3D0 < v->f20) {
                v->f20 = D_L01_001DF1E0_003CE3D0;
            }
        }
        vec_add_ba(&np, m->pos, v);
        func_L01_00446760_003CE3D0(&l, (M_3CC220 *)m->obj, 1, (f32 *)v, v->f14);
        l.b18 = 1;
        l.h1A = m->hAA;
        o = m->obj;
        func_L01_004CB320_003CE3D0();
        r = func_003D3CB0((int)m->pos, &np, 0, (M_3CC220 *)o, &l);
        if (r != 0) {
            M_3CC220 *p = D_L01_001EAA18_003CE3D0[0];
            if (p != 0 && p->hAA == 0x186D && p->b20 != 2 && p->b20 != 5) {
                p->b20 = 4;
            }
        }
        func_L01_004CB358_003CE3D0();
        pos = m->pos;
        lp = &l;
        if (r != 0 ||
            (((D_L01_001DFB40_003CE3D0 + m->obj->hB2) & 1) && func_L01_003FB640_003CE3D0(pos, 1, m->obj, D_L01_001DF1E8_003CE3D0) != 0) ||
            func_0038CAD0(&v->t18) != 0) {
            func_003D4D00(pos, 0, m->obj, lp, D_L01_001DF1EC_003CE3D0);
            func_L01_003303B8_003CE3D0(pos, 0, 5, 5, 5, 5, 5, 0, 0.2f, 0.0f, 0.0f, 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x38F7, 0xF7, 0x40FF, 0xFF, 0xFF, 0x30FF,
                              0x7F0060FF, 0x280000FF, 0x30FF, 0);
            func_003A52A0(0, 0, (u8 *)m);
            func_L01_004450F0_003CE3D0((M3C7568 *)m, 2, -1);
        }
        *(vu0_v4 *)m->pos = np;
    }
    if (func_0038CAD0(&v->t1C) != 0) {
        if (D_L01_001DF1F8_003CE3D0 < v->f24) {
            v->f24 = v->f24 - D_L01_001DF1F4_003CE3D0;
            if (v->f24 < D_L01_001DF1F8_003CE3D0) {
                v->f24 = D_L01_001DF1F8_003CE3D0;
            }
        }
    }
    s = v->f24 * v->f20;
    func_0038CF68(buf, m->rot, -D_L01_001DF204_003CE3D0 * s);
    vec_add_ab(buf, buf, m->pos);
    buf[3] = D_L01_001DF208_003CE3D0 * s;
    if ((D_001D545C != 1 || m->obj->hAA != 0xC23 ? func_0038DC20(buf, 64.0f) : func_0038DC20(buf, 255.0f)) >= 0) {
        func_L01_00404A10_003CE3D0(func_L01_003CE8A8_003CE3D0, m);
    }
}
/* localdecomp:end func_L01_003CE3D0 */

INCLUDE_ASM("asm/levels", func_L01_003CE780);

INCLUDE_ASM("asm/levels", func_L01_003CE8A8);

INCLUDE_ASM("asm/levels", func_L01_003CEE90);

/* localdecomp:start func_L01_003CF5E0 */
extern void func_L01_0043A778_003CF5E0(s32, s32, u8 *);
extern void func_L01_0043A6E0_003CF5E0(void *, s32, void *);
extern void func_L01_0040E620_003CF5E0(void *, void *, f32);
extern void func_L01_0040A8C0_003CF5E0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98_003CF5E0(void *, s32, void *, void *, s32, s32, f32, s32, s32, s32);
__asm__(".extern D_L01_001DF25C_003CF5E0, 4");
__asm__(".extern D_L01_001DF260_003CF5E0, 4");
extern const u32 D_L01_001DF25C_003CF5E0;
extern s32 D_L01_001DF260_003CF5E0;

void func_L01_003CF5E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 w1[4] __attribute__((aligned(16)));
    f32 w2[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 t;
    u8 *q;

    t = *(f32 *)(s + 0x600) - 0.1f;
    *(f32 *)(s + 0x600) = t;
    if (t <= -8.0f) {
        *(f32 *)(s + 0x600) = t + 8.0f;
    }
    func_L01_0043A778_003CF5E0((s32)a0, 0, (u8 *)a);
    func_L01_0043A778_003CF5E0((s32)a0, 2, (u8 *)b);
    func_L01_0043A778_003CF5E0((s32)a0, 1, (u8 *)c);
    func_L01_0043A778_003CF5E0((s32)a0, 3, (u8 *)d);
    vec_sub_ba(w1, a, c);
    func_L01_0040E620_003CF5E0(w1, w1, *(f32 *)(s + 0x608));
    vec_add_ba(c, w1, a);
    vec_sub_ba(w2, b, d);
    func_L01_0040E620_003CF5E0(w2, w2, *(f32 *)(s + 0x604));
    vec_add_ab(d, w2, b);
    func_L01_0043A6E0_003CF5E0(a0, 1, m);
    *(vu0_q *)w = *(vu0_q *)m;
    func_L01_0040E620_003CF5E0(w, w, -2.75f);
    *(vu0_q *)(s + 0x410) = *(vu0_q *)w;
    *(f32 *)(s + 0x41C) = 1.0f;
    *(vu0_q *)w = *(vu0_q *)m;
    func_L01_0040E620_003CF5E0(w, w, 0.75f);
    *(vu0_q *)(s + 0x400) = *(vu0_q *)w;
    *(f32 *)(s + 0x40C) = 1.0f;
    q = s + 0x400;
    func_L01_0040A8C0_003CF5E0(a, c, D_L01_001DF25C_003CF5E0, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x600));
    func_L01_0040A8C0_003CF5E0(b, d, D_L01_001DF25C_003CF5E0, 1, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0x6FFFFFFF, 0.035f, 0.45f, *(f32 *)(s + 0x600));
    func_L01_0040A8C0_003CF5E0(a, c, D_L01_001DF25C_003CF5E0, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x600));
    func_L01_0040A8C0_003CF5E0(b, d, D_L01_001DF25C_003CF5E0, 1, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0x7F96006B, 0.08f, 0.75f, *(f32 *)(s + 0x600));
    func_L01_00408C98_003CF5E0(q, D_L01_001DF260_003CF5E0, s, s + 0x200, *(s32 *)(s + 0x60C), *(s32 *)(s + 0x61C), *(f32 *)(s + 0x618), *(s32 *)(s + 0x610), *(s32 *)(s + 0x614), 5);
}
/* localdecomp:end func_L01_003CF5E0 */

/* localdecomp:start func_L01_003CF918 */
extern void func_003C2F58(u8 *, s32, f32 *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(f32 *, void *, f32);
extern void func_L01_0044C280_003CF918(void *, void *, void *, s32, f32);
extern void func_003C3FC0(void *, void *);
__asm__(".extern D_L01_001DF260_003CF918, 4");
extern s32 D_L01_001DF260_003CF918;
extern u8 D_001A4C60[];

void func_L01_003CF918(u8 *a0) {
    vu0_v4 p0;
    vu0_v4 mtx[4];
    vu0_v4 p1;
    vu0_v4 d;
    vu0_v4 zero;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 out;
    u8 *v = *(u8 **)(a0 + 0x68);

    *(f32 *)(v + 0x618) = 0.0f;
    func_003C2F58(a0, 3, (f32 *)&p0);
    func_003C2EC0(a0, 3, mtx);
    func_003C2F58(a0, 2, (f32 *)&p1);
    vec_sub_ba(&d, &p1, &p0);
    func_0038CF68((f32 *)&d, &d, *(f32 *)(v + 0x604));
    vec_add_ab(&p0, &d, &p1);
    if (*(f32 *)(v + 0x618) == 0.0f) {
        s32 n = D_L01_001DF260_003CF918;
        *(s32 *)(v + 0x60C) = (*(s32 *)(v + 0x60C) + 1) % n;
        if (*(s32 *)(v + 0x61C) < n) {
            *(s32 *)(v + 0x61C) = *(s32 *)(v + 0x61C) + 1;
        }
    }
    zero.x = 0.0f;
    zero.y = 0.0f;
    zero.z = 0.0f;
    zero.w = 0.0f;
    if (*(s32 *)(v + 0x620) >= 2) {
        s32 n = D_L01_001DF260_003CF918;
        s32 i = (*(s32 *)(v + 0x60C) - 1 + n) % n;
        vec_sub_ab(&a, &p0, D_001A4C60);
        vec_sub_ba(&b, v + i * 16, D_001A4C60);
        func_L01_0044C280_003CF918(&out, &b, &a, 0, 0.5f);
        func_003C3FC0(v + 0x200 + *(s32 *)(v + 0x60C) * 16, &zero);
        vec_add_ba(v + *(s32 *)(v + 0x60C) * 16, &out, D_001A4C60);
        *(s32 *)(v + 0x60C) = (*(s32 *)(v + 0x60C) + 1) % D_L01_001DF260_003CF918;
    }
    func_003C3FC0(v + 0x200 + *(s32 *)(v + 0x60C) * 16, &zero);
    *(s128 *)(v + *(s32 *)(v + 0x60C) * 16) = *(s128 *)&p0;
}
/* localdecomp:end func_L01_003CF918 */
