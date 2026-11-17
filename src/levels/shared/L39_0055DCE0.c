#include "common.h"

/* declared by functions of L39_0055D7F8.c, which this file was cut from */
extern u16 *D_L39_002927E0[];
struct E_0055DB18;
extern struct E_0055DB18 *D_L39_0024BF5C;
extern s32 D_L39_0024BF98;
extern void func_L01_004450F0(void *, s32, s32);
typedef struct T_0055DB18 {
    u8 pad[0x88];
    s32 w88[8];
    s32 wA8[8];
} T_0055DB18;
typedef struct Q_0055DB18 {
    u8 pad0[0x1C];
    s32 f1C;
    u8 pad20[0xC];
    s32 f2C;
} Q_0055DB18;
typedef struct E_0055DB18 {
    u8 pad[0x68];
    Q_0055DB18 *f68;
    u8 pad2[0x100 - 0x6C];
} E_0055DB18;
extern E_0055DB18 *D_L39_0024BF5C;
extern T_0055DB18 *D_L39_00352B4C[];

/* localdecomp:start func_L39_0055DCE0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0055DCE0;

typedef struct R_0055DCE0 {
    u32 w0;
    s32 w4;
    s32 w8;
} R_0055DCE0;

typedef struct Q_0055DCE0 {
    u8 pad0[0x30];
    s32 w30;
    u8 pad34[0x200 - 0x34];
    R_0055DCE0 r;
    u8 pad20C[0x21C - 0x20C];
    s32 w21C;
    s32 w220;
    u8 pad224[0x228 - 0x224];
    s32 w228;
    s32 w22C;
    s32 w230;
} Q_0055DCE0;

typedef struct S_0055DCE0 {
    u8 pad0[0x10];
    V4_0055DCE0 pos;
    u8 b20;
    u8 b21;
    u8 pad22[0x30 - 0x22];
    u8 b30;
    u8 pad31[0x68 - 0x31];
    Q_0055DCE0 *p68;
    u8 pad6C[0xAC - 0x6C];
    s32 wAC;
} S_0055DCE0;

typedef struct O2_0055DCE0 O2_0055DCE0;
typedef struct {
    u8 pad0[0x10];
    s32 (*fn)(O2_0055DCE0 *);
} VT_0055DCE0;
struct O2_0055DCE0 {
    u8 pad0[0x14];
    VT_0055DCE0 *vt;
};

typedef struct {
    u8 pad0[0x2D0];
    s32 w2D0;
} E_0055DCE0;

typedef struct {
    u8 pad0[0x18F];
    s8 b18F;
} G_0055DCE0;

typedef struct {
    u8 pad0[0x40];
    s32 w40[2];
} T_0055DCE0;

typedef struct {
    u8 pad0[0x2548];
    s32 w2548;
} P_0055DCE0;

__asm__(".extern D_L39_0024BF5C, 16");
__asm__(".extern D_L39_00241640, 16");
extern G_0055DCE0 *D_L39_00241640;
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00242930, 16");
extern s32 D_L39_00242930;
extern void func_L39_00662B18(void *, void *, s32);
extern E_0055DCE0 *func_L39_006685D8(u32);
extern O2_0055DCE0 *func_L39_0061D1D8(u32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32,
                              s32, s32, f32, f32, s32, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3718(s32, void *);
extern P_0055DCE0 *func_L39_0061BF38(s32);
extern void func_L39_00648960(void *, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_L39_0055D948(s32);
typedef int u128_0055DCE0 __attribute__((mode(TI)));

void func_L39_0055DCE0(S_0055DCE0 *self, u32 *msg) {
    Q_0055DCE0 *q = self->p68;
    R_0055DCE0 *r = &q->r;
    u32 type = msg[0] & 0xF;

    switch (type) {
    case 0: {
        s32 t;
        if (r->w4 != 0) {
            break;
        }
        t = msg[1] + (msg[0] >> 13);
        if (q->w21C < t) {
            q->w21C = t;
            func_L39_00662B18(msg, r, 4);
            if (q->r.w0 != 0xFFFFFFFF) {
                if (((q->r.w0 >> 24) & 0xF) == 3) {
                    q->w220 = func_L39_006685D8(q->r.w0)->w2D0;
                } else {
                    O2_0055DCE0 *o = func_L39_0061D1D8(q->r.w0);
                    q->w220 = (o != 0) ? o->vt->fn(o) : 0;
                }
                if (q->w220 != 0) {
                    if (self->b20 == 1) {
                        func_L01_004450F0(self, 2, -1);
                    } else {
                        func_L01_004450F0(self, 4, -1);
                    }
                } else {
                    if (q->w230 != 0) {
                        if (self->b20 != 3) {
                            func_L01_004450F0(self, 3, -1);
                        }
                    } else {
                        if (self->b20 != 1) {
                            func_L01_004450F0(self, 1, -1);
                        }
                    }
                    q->w228 = 0;
                }
            } else {
                q->w220 = 0;
                if (q->w230 != 0) {
                    if (self->b20 != 3) {
                        func_L01_004450F0(self, 3, -1);
                    }
                } else {
                    if (self->b20 != 1) {
                        func_L01_004450F0(self, 1, -1);
                    }
                }
                q->w228 = 0;
            }
        }
        break;
    }
    case 1:
        if (self->b20 != 7) {
            V4_0055DCE0 sph;
            V4_0055DCE0 *pos;
            u16 *p;
            s32 n;
            s32 found;

            pos = &self->pos;
            sph = self->pos;
            sph.w = 3.5f;
            if (func_L39_005BE900(&sph, 0, self->b30) != -1) {
                V4_0055DCE0 v;
                s32 h;
                func_L01_003303B8(pos, 0, 5, 5, 5, 5, 5, 0, 0.75f, 0.0f, 0.0f, 2.0f, 0, 1, 1, 0,
                                  1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_L01_00451FE0(self, 0x1F, &D_L39_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f,
                                  -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                if (q->w230 != 0) {
                    h = func_L39_005F33E0(1, 0, self);
                } else {
                    h = func_L39_005F33E0(5, 0, self);
                }
                *(u128_0055DCE0 *)&v = 0;
                v.z = 1.0f;
                func_L39_005F3718(h, &v);
            }
            func_L01_004450F0(self, 7, -1);

            n = 0;
            for (p = D_L39_002927E0[self->b21];
                 self->b21 != 0xFF && self->b21 <= D_L39_0024BF98 && p != 0 &&
                 ((s16)p[-1] >= 0 || p == D_L39_002927E0[self->b21]);
                 p++) {
                S_0055DCE0 *o = (S_0055DCE0 *)&D_L39_0024BF5C[*p & 0x7FFF];
                if (o == 0) {
                    break;
                }
                if (o->b20 == 7) {
                    n++;
                }
            }
            if (n != 1) {
                goto done;
            }
            found = 0;
            if (D_L39_00241640 != 0 && D_L39_00241640->b18F == 0) {
                found = 1;
            }
            if (found) {
                goto done;
            }
            if (q->w22C >= 0) {
                if (q->w22C < 2) {
                    u16 *p2;
                    S_0055DCE0 *e = (S_0055DCE0 *)((E_0055DB18 *)((u8 *)D_L39_0024BF5C + (((T_0055DCE0 *)D_L39_00352B4C[0])->w40[q->w22C] << 8)))->f68;
                    for (p2 = D_L39_002927E0[e->wAC];
                         (e->wAC & 0xFF) != 0xFF && e->wAC <= D_L39_0024BF98 && p2 != 0 &&
                         ((s16)p2[-1] >= 0 || p2 == D_L39_002927E0[e->wAC]);
                         p2++) {
                        S_0055DCE0 *o = (S_0055DCE0 *)&D_L39_0024BF5C[*p2 & 0x7FFF];
                        if (o == 0) {
                            break;
                        }
                        if (o == self) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
            if (!found) {
                s32 i;
                for (i = 0; i < *D_L39_00241120; i++) {
                    P_0055DCE0 *pl = func_L39_0061BF38(i);
                    if (pl->w2548 == q->w22C) {
                        func_L39_00648960(pl, 0x25);
                    }
                }
            }
        }
    done:
        r->w4 = 1;
        r->w8 = msg[1];
        r->w0 = 0xFFFFFFFF;
        q->w30 = 0;
        func_003C3938(self, 0, 0);
        q->w220 = 0;
        break;
    case 2: {
        s32 a;
        func_L39_00662B18(msg, &a, 4);
        break;
    }
    case 3: {
        s32 a, b;
        func_L39_00662B18(msg, &a, 4);
        func_L39_00662B18(msg, &b, 4);
        ((void (*)(s32, s32))func_L39_0055D948)(a, b);
        break;
    }
    }
}
/* localdecomp:end func_L39_0055DCE0 */

INCLUDE_ASM("asm/levels", func_L39_0055E2E0);
