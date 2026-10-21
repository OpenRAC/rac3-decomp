#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_003CAA80);

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

INCLUDE_ASM("asm/levels", func_L01_003CB8E8);

INCLUDE_ASM("asm/levels", func_L01_003CB9B0);

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

INCLUDE_ASM("asm/levels", func_L01_003CC8D8);

INCLUDE_ASM("asm/levels", func_L01_003CC9C8);

INCLUDE_ASM("asm/levels", func_L01_003CCB58);

INCLUDE_ASM("asm/levels", func_L01_003CCC20);

INCLUDE_ASM("asm/levels", func_L01_003CCED8);

INCLUDE_ASM("asm/levels", func_L01_003CD068);

INCLUDE_ASM("asm/levels", func_L01_003CD248);

INCLUDE_ASM("asm/levels", func_L01_003CD778);

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

INCLUDE_ASM("asm/levels", func_L01_003CDCE8);

INCLUDE_ASM("asm/levels", func_L01_003CDDD8);

INCLUDE_ASM("asm/levels", func_L01_003CE2E8);

INCLUDE_ASM("asm/levels", func_L01_003CE3D0);

INCLUDE_ASM("asm/levels", func_L01_003CE780);

INCLUDE_ASM("asm/levels", func_L01_003CE8A8);

INCLUDE_ASM("asm/levels", func_L01_003CEE90);

INCLUDE_ASM("asm/levels", func_L01_003CF5E0);

INCLUDE_ASM("asm/levels", func_L01_003CF918);

INCLUDE_ASM("asm/levels", func_L01_003CFAE8);

INCLUDE_ASM("asm/levels", func_L01_003CFB08);

INCLUDE_ASM("asm/levels", func_L01_003D0530);

/* localdecomp:start func_L01_003D06E0 */
extern M_3C9E88 *D_L01_001E001C;



extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];
extern Vt3CEDD0 *func_L01_0043B568(s32, s32, s32);
s32 func_L01_003D06E0(s32 a0, Obj3CEDD0 *obj) {
    u8 *m;
    u8 *p;
    u16 *list;
    Moby3CEDD0 *e;
    Vt3CEDD0 *h;

    if (obj->w40 != -1) {
        m = (*(u8 * *)&D_L01_001E001C) + (obj->w40 << 8);
        if (*(u16 *)(m + 52) & 2) {
            return 0;
        }
        p = *(u8 **)(*(u8 **)(m + 104) + 284);
        if (p == 0) {
            return 0;
        }
        obj->w2C = p[33];
    }
    for (list = D_L01_0021DE20[obj->w2C];
         (obj->w2C & 0xFF) != 255 && obj->w2C <= D_L01_001E0058 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_L01_0021DE20[obj->w2C]);
         list++) {
        e = (Moby3CEDD0 *)((*(u8 * *)&D_L01_001E001C) + ((*list & 0x7FFF) << 8));
        if (e == 0) {
            break;
        }
        if (e->b20 == 254) {
            continue;
        }
        if (e->b20 == 253) {
            continue;
        }
        if (obj->w40 != -1) {
            h = func_L01_0043B568(e->hAA, 1, 28);
            if (h == 0) {
                continue;
            }
            if (h->f8(e) != 0) {
                continue;
            }
        }
        h = func_L01_0043B568(7032, 0, 16);
        h->f0(e);
    }
    return 1;
}
/* localdecomp:end func_L01_003D06E0 */

INCLUDE_ASM("asm/levels", func_L01_003D0850);

/* localdecomp:start func_L01_003D09D0 */
extern Vt3CEDD0 *func_L01_0043B568(s32, s32, s32);
extern M_3C9E88 *D_L01_001E001C;


extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];

void func_L01_003D09D0(s32 a0, S_3CF0C0p *p) {
    S_3CF0C0o *src;
    S_3CF0C0o *o;
    S_3CF0C0f *h;
    S_3CF0C0f *f;
    u16 *list;
    s32 n;
    s128 buf;
    f32 val;

    if (p->x2C == -1 || p->x28 == -1) {
        return;
    }
    src = &(*(S_3CF0C0o * *)&D_L01_001E001C)[p->x28];
    h = ((S_3CF0C0f * (*)(s32, s32, s32))func_L01_0043B568)(6877, 0, 104);
    n = 0;
    for (list = D_L01_0021DE20[p->x2C];
         (p->x2C & 0xFF) != 255 && p->x2C <= D_L01_001E0058 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_L01_0021DE20[p->x2C]);
         list++) {
        o = &(*(S_3CF0C0o * *)&D_L01_001E001C)[*list & 0x7FFF];
        if (o == 0) {
            break;
        }
        if (o->x20 == 254) {
            continue;
        }
        if (o->x20 == 253) {
            continue;
        }
        if (p->x40 != -1) {
            f = ((S_3CF0C0f * (*)(s32, s32, s32))func_L01_0043B568)(o->xAA, 1, 28);
            if (f == 0) {
                continue;
            }
            if (f->x8(o) != 0) {
                continue;
            }
        }
        h->x14(src, n, &buf, &val);
        n++;
        o->x10 = buf;
        o->xF8 = val;
    }
    p->xEC = 0;
    p->xE8 = 5;
}
/* localdecomp:end func_L01_003D09D0 */

/* localdecomp:start func_L01_003D0B70 */
extern void func_L01_003D22A8(s32);
extern s32 func_L01_00513EF0(void);
extern void func_L01_003F5AC0(s32, s32);
extern u8 *D_L01_001E2A90[];

void func_L01_003D0B70(s32 a0, u8 *a1) {
    func_L01_003D22A8(a0);
    if (func_L01_00513EF0()) return;
    if (*(s16 *)(D_L01_001E2A90[0] + 134)) return;
    func_L01_003F5AC0(0, 1);
    a1[177] = 1;
}
/* localdecomp:end func_L01_003D0B70 */

INCLUDE_ASM("asm/levels", func_L01_003D0BD0);
