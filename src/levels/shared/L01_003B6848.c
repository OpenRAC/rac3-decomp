#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;
typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;
typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;
typedef void (*Fn_003B52B0)(u8 *, s32);

extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);
extern s32 func_L01_003B3548(u8 *);

/* localdecomp:start func_L01_003B6848 */
extern void func_0038D308(void *, void *);
extern E_3B5048 *func_L01_00449050(M_3B5048 *);
extern void func_003C3938(M_3B5048 *, s32, s32);
extern A_3B5048 *func_00382348(M_3B5048 *);
extern void func_L01_00326AF0(M_3B5048 *, A_3B5048 *);
extern B_3B5048 *func_L01_00448FF0(M_3B5048 *);
extern void func_L01_0043B9E8(M_3B5048 *, s32, s32, s32);

void func_L01_003B6848(void *owner, M_3B5048 *m, M_3B5048 *src) {
    C_3B5048 *c;
    A_3B5048 *a;
    B_3B5048 *b;
    m->b7F = 0;
    if (owner != 0) {
        m->b21 = 255;
    }
    if (src != 0) {
        V_3B5048 *v = src->w68;
        m->b30 = v->b81;
        m->h32 = v->h82;
        m->pos = src->pos;
        m->vF0 = src->vF0;
        func_0038D308(m->vC0, &m->vF0);
    }
    func_L01_00449050(m)->w8 = owner;
    m->b20 = 0;
    m->h34 &= ~2;
    c = m->w24;
    m->b95 = 0;
    if (c != 0) {
        m->h34 &= ~0x45;
        m->h34 |= c->h44 & 0x1000;
        m->w98 = c->w10;
        m->b31 = 1;
        func_003C3938(m, 0, 0);
    }
    a = func_00382348(m);
    if (a != 0) {
        if (src != 0) {
            func_L01_00326AF0(m, a);
        }
        a->f0 = a->h4;
    }
    b = func_L01_00448FF0(m);
    if (b != 0) {
        b->b1A = 0;
        b->h38 = 0;
        if (b->h0 != 0) {
            b->h0 = 0;
            func_L01_0043B9E8(m, b->b4, b->b5, b->b6);
            b->h2 = 1;
        }
    }
}
/* localdecomp:end func_L01_003B6848 */

/* localdecomp:start func_L01_003B69A0 */

extern void func_003C7C38(Obj_003B51A0 *);

void func_L01_003B69A0(void *a, void *b, Obj_003B51A0 *o) {
    o->fn64(o);
    if (o->w24) func_003C7C38(o);
}
/* localdecomp:end func_L01_003B69A0 */

/* localdecomp:start func_L01_003B69E0 */
extern s32 func_L01_003272A8(s32);
extern s32 func_L01_0043B618(s32);
extern void func_L01_003272F0(s32, u8);
extern s32 func_L01_0043B750(s32, s32);

s32 func_L01_003B69E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 neg = 0;
    if (a4 < 0) neg = 1;
    if (neg == 0) {
        a3 = func_L01_003272A8(a4);
    }
    if (a3 == 255) {
        a3 = func_L01_0043B618(a2);
        if (neg == 0) {
            func_L01_003272F0(a4, a3);
        }
    } else if (func_L01_0043B750(a3, a2) == 0) {
        a3 = 255;
    }
    return a3;
}
/* localdecomp:end func_L01_003B69E0 */

/* localdecomp:start func_L01_003B6A80 */
extern void func_L01_004095C8(char *, char *, char *);
void func_L01_003B6A80(void *a, char *b, char *c) {
    if (*(int *)(b + 288) == 1) {
        func_L01_004095C8(c, c + 16, c + 240);
    }
}
/* localdecomp:end func_L01_003B6A80 */

/* localdecomp:start func_L01_003B6AB0 */
extern void func_L01_003B6848(void *owner, M_3B5048 *m, M_3B5048 *src);

extern u8 *func_L01_00326A10(s32);

u8 *func_L01_003B6AB0(u8 *a0, s32 *a1, s32 a2, s32 a3, Fn_003B52B0 *cb) {
    u8 *r;

    r = func_L01_00326A10(a3);
    if (r == 0) {
        return 0;
    }
    ((void (*)(u8 *, u8 *, s32))func_L01_003B6848)(a0, r, a2);
    (*cb)(r, a2);
    if (a3 == a1[0]) {
        a1[48]++;
        if (a1[71] == 0) {
            *(u8 **)&a1[71] = r;
        }
    }
    return r;
}
/* localdecomp:end func_L01_003B6AB0 */
