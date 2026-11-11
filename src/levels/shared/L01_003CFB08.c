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

/* localdecomp:start func_L01_003D0850 */
__asm__(".extern D_L01_001DF2C0, 4");
__asm__(".extern D_L01_001DF2C8, 8");
extern s32 D_L01_001E0058;
extern u16 *D_L01_0021DE20[];
extern f32 D_L01_001DF2C0;
extern f32 D_L01_001DF2C8[2];

void func_L01_003D0850(Self_003D0850 *self, Obj_003D0850 *obj) {
    u16 *list;
    Moby_003D0850 *e;
    Vt_003D0850 *h;
    s32 n;

    n = 0;
    for (list = D_L01_0021DE20[obj->w2C];
         (obj->w2C & 0xFF) != 255 && obj->w2C <= D_L01_001E0058 && list != 0
         && (((s16 *)list)[-1] >= 0 || list == D_L01_0021DE20[obj->w2C]);
         list++) {
        e = (Moby_003D0850 *)((*(u8 **)&D_L01_001E001C) + ((*list & 0x7FFF) << 8));
        if (e == 0) {
            break;
        }
        obj->xBC[n] = 0;
        if (e->b20 == 254) {
            n++;
            continue;
        }
        if (e->b20 == 253) {
            n++;
            continue;
        }
        if (obj->w40 != -1) {
            h = ((Vt_003D0850 * (*)(s32, s32, s32))func_L01_0043B568)(e->hAA, 1, 28);
            if (h == 0) {
                continue;
            }
            if (h->f8(e) != 0) {
                continue;
            }
        }
        h = ((Vt_003D0850 * (*)(s32, s32, s32))func_L01_0043B568)(7032, 0, 16);
        h->f4(e, self->xF8, D_L01_001DF2C8[n], obj->x130 + D_L01_001DF2C0);
        n++;
    }
}
/* localdecomp:end func_L01_003D0850 */

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
