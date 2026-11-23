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
