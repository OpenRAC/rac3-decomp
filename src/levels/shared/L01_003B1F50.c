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

INCLUDE_ASM("asm/levels", func_L01_003B1F50);

INCLUDE_ASM("asm/levels", func_L01_003B2688);

INCLUDE_ASM("asm/levels", func_L01_003B2728);

/* localdecomp:start func_L01_003B28D0 */
extern void func_L01_004450F0(s32, s32, s32);
void func_L01_003B28D0(s32 a0) {
    func_L01_004450F0(a0, 10, -1);
}
/* localdecomp:end func_L01_003B28D0 */

/* localdecomp:start func_L01_003B28F0 */
s32 func_L01_003B28F0(u8 *obj) {
    return obj[32] == 10;
}
/* localdecomp:end func_L01_003B28F0 */

/* localdecomp:start func_L01_003B2900 */
extern void func_L01_004450F0(s32, s32, s32);
void func_L01_003B2900(u8 *obj) {
    *(s32 *)(*(u8 **)(obj + 104) + 96) = 0;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 1, -1);
}
/* localdecomp:end func_L01_003B2900 */

/* localdecomp:start func_L01_003B2928 */
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);

void func_L01_003B2928(u8 *moby) {
    s32 idx = *(s32 *)(*(u8 **)(moby + 104) + 24);
    u8 *p;

    if (idx != -1) {
        p = D_L01_001E001C + idx * 256;
        while (p != 0 && *(s16 *)(p + 170) != 6628) {
            func_L01_003B3368(p);
            p = func_L01_003B3430(p);
        }
    }
}
/* localdecomp:end func_L01_003B2928 */

/* localdecomp:start func_L01_003B29A8 */
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);

void func_L01_003B29A8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 *p = D_L01_001E0100[0] + (*(s32 *)(v + 16) << 7);
    func_L01_004F50C8(p + 48, p + 112, 0, 1);
    if (*(s32 *)(v + 20) != -1) {
        func_L01_003EE650(*(s32 *)(v + 20));
    }
}
/* localdecomp:end func_L01_003B29A8 */

INCLUDE_ASM("asm/levels", func_L01_003B2A08);

INCLUDE_ASM("asm/levels", func_L01_003B2AA0);

/* localdecomp:start func_L01_003B2DC8 */
extern void func_L01_00459AF8_003B2DC8();
 
void func_L01_003B2DC8(void) {
    func_L01_00459AF8_003B2DC8();
}
/* localdecomp:end func_L01_003B2DC8 */

INCLUDE_ASM("asm/levels", func_L01_003B2DE8);

INCLUDE_ASM("asm/levels", func_L01_003B2F80);

/* localdecomp:start func_L01_003B3050 */
extern void func_L01_004450F0(s32, s32, s32);
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE634;
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;
void func_L01_003B3050(u8 *a0) {
    D_L01_001DE630 = 0;
    D_L01_001DE634 = 0;
    D_L01_001DE638 = 0;
    D_L01_001DE63C = 0;
    D_L01_001DE640 = 0;
    D_L01_001DE644 = 0;
    D_L01_001DE648 = 0;
    a0[48] = 255;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 1, -1);
}
/* localdecomp:end func_L01_003B3050 */

INCLUDE_ASM("asm/levels", func_L01_003B3098);

INCLUDE_ASM("asm/levels", func_L01_003B31B8);

INCLUDE_ASM("asm/levels", func_L01_003B3368);

INCLUDE_ASM("asm/levels", func_L01_003B3430);

/* localdecomp:start func_L01_003B3450 */
extern s32 D_L01_001DE634;

void func_L01_003B3450(s32 a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 v = D_L01_001DE634;
    s32 w = *(s32 *)(p + 80);
    *(s32 *)(p + 88) = v;
    D_L01_001DE634 = a0;
    *(s32 *)(p + 84) = w;
}
/* localdecomp:end func_L01_003B3450 */

INCLUDE_ASM("asm/levels", func_L01_003B3470);

INCLUDE_ASM("asm/levels", func_L01_003B3508);

INCLUDE_ASM("asm/levels", func_L01_003B3548);

INCLUDE_ASM("asm/levels", func_L01_003B36A8);

INCLUDE_ASM("asm/levels", func_L01_003B3C48);

INCLUDE_ASM("asm/levels", func_L01_003B41E0);

INCLUDE_ASM("asm/levels", func_L01_003B4240);

LINKER_REMNANT("asm/levels", func_L01_003B42C0);

/* localdecomp:start func_L01_003B42C8 */
extern s32 D_L01_001DFB40[];
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;
void func_L01_003B42C8(s32 a0, s32 a1, s32 a2, s32 a3) {
    D_L01_001DE638 = a0;
    D_L01_001DE63C = a1;
    D_L01_001DE640 = a2;
    D_L01_001DE644 = a3;
    D_L01_001DE648 = D_L01_001DFB40[0];
}
/* localdecomp:end func_L01_003B42C8 */

INCLUDE_ASM("asm/levels", func_L01_003B42E8);

INCLUDE_ASM("asm/levels", func_L01_003B4718);

/* localdecomp:start func_L01_003B4818 */
extern s32 D_001D545C[];

s32 func_L01_003B4818(void *a, u8 *b) {
    if (D_001D545C[0] != 26) {
        return 0;
    }
    return *(s32 *)(b + 36) != 0;
}
/* localdecomp:end func_L01_003B4818 */

INCLUDE_ASM("asm/levels", func_L01_003B4840);

/* localdecomp:start func_L01_003B4D58 */
extern void func_L01_00517918(s32);

void func_L01_003B4D58(void *a, u8 *b) {
    if (*(s32 *)(b + 36) != 0) {
        func_L01_00517918(0);
    }
}
/* localdecomp:end func_L01_003B4D58 */

INCLUDE_ASM("asm/levels", func_L01_003B4D80);

INCLUDE_ASM("asm/levels", func_L01_003B4FB0);

/* localdecomp:start func_L01_003B5498 */
extern void func_L01_004450F0(s32, s32, s32);
void func_L01_003B5498(u8 *obj) {
    obj[48] = 255;
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 1, -1);
}
/* localdecomp:end func_L01_003B5498 */

/* localdecomp:start func_L01_003B54C0 */
extern void func_L01_004450F0(s32, s32, s32);


void func_L01_003B54C0(Moby_003B3CC0 *m, s32 value) {
    m->w68[3] = value;
    ((void (*)(Moby_003B3CC0 *, s32, s32))func_L01_004450F0)(m, 2, -1);
    m->h34 &= ~2;
}
/* localdecomp:end func_L01_003B54C0 */

/* localdecomp:start func_L01_003B5500 */
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
void func_L01_003B5500(s32 a0, s32 a1, s32 a2) {
    u8 *p = D_L01_001E0100[0] + (a2 << 7);
    func_L01_004F50C8(p + 48, p + 112, 0, 1);
}
/* localdecomp:end func_L01_003B5500 */

/* localdecomp:start func_L01_003B5538 */
extern s32 D_L01_001DE758;
s32 *func_L01_003B5538(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 6) {
        *a2 = 4;
        return &D_L01_001DE758;
    }
    return 0;
}
/* localdecomp:end func_L01_003B5538 */

INCLUDE_ASM("asm/levels", func_L01_003B5558);

INCLUDE_ASM("asm/levels", func_L01_003B56B8);

/* localdecomp:start func_L01_003B5B40 */
s32 func_L01_003B5B40(u8 *obj) {
    u8 *p = *(u8 **)(obj + 104);
    if (*(s32 *)(p + 68) != 0) {
        return 0;
    }
    return *(s32 *)(p + 64) == 0;
}
/* localdecomp:end func_L01_003B5B40 */

/* localdecomp:start func_L01_003B5B68 */
s32 func_L01_003B5B68(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 68) != 0) {
        return 0;
    }
    return *(s32 *)(p + 64);
}
/* localdecomp:end func_L01_003B5B68 */

INCLUDE_ASM("asm/levels", func_L01_003B5B88);

INCLUDE_ASM("asm/levels", func_L01_003B5C80);

/* localdecomp:start func_L01_003B5EF0 */
s32 func_L01_003B5EF0(u8 *a) {
    return *(s32 *)(*(u8 **)(a + 0x68) + 0xC4);
}
/* localdecomp:end func_L01_003B5EF0 */

/* localdecomp:start func_L01_003B5F00 */
s32 func_L01_003B5F00(u8 *a) {
    return *(s32 *)(*(u8 **)(a + 0x68) + 0x44);
}
/* localdecomp:end func_L01_003B5F00 */

/* localdecomp:start func_L01_003B5F10 */
s32 func_L01_003B5F10(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 r = 0;
    if (*(s32 *)(p + 68) != 0) {
        r = *(s32 *)(p + 72) != 0;
    }
    return r;
}
/* localdecomp:end func_L01_003B5F10 */

/* localdecomp:start func_L01_003B5F30 */
int func_L01_003B5F30(char *a) {
    char *p = *(char **)(a + 104);
    int x = *(int *)(p + 192);
    if (x == 0) {
        return 0;
    }
    return *(int *)(p + 76) == x - *(int *)(p + 196);
}
/* localdecomp:end func_L01_003B5F30 */

INCLUDE_ASM("asm/levels", func_L01_003B5F60);

/* localdecomp:start func_L01_003B5FC8 */
s32 func_L01_003B5FC8(u8 *a) {
    return *(s32 *)(*(u8 **)(a + 0x68) + 0x4C);
}
/* localdecomp:end func_L01_003B5FC8 */

INCLUDE_ASM("asm/levels", func_L01_003B5FD8);

/* localdecomp:start func_L01_003B6108 */
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L01_003B3450(s32 a0);

void func_L01_003B6108(u8 *obj)
{
    u8 *vars = *(u8 **)(obj + 104);

    if (*(s32 *)(vars + 80) != 0 && *(s32 *)(vars + 84) == 0) {
        ((void (*)(void))func_L01_003B3450)();
    }
    if (*(s32 *)(vars + 196) < *(s32 *)(vars + 192)) {
        ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 3, -1);
    } else if (obj[32] == 4) {
        obj[188] = 1;
    } else {
        ((void (*)(u8 *, s32, s32))func_L01_004450F0)(obj, 1, -1);
    }
}
/* localdecomp:end func_L01_003B6108 */

INCLUDE_ASM("asm/levels", func_L01_003B61A0);

/* localdecomp:start func_L01_003B6250 */
extern s32 func_L01_00456250(u8 *);
extern void func_L01_00456230(u8 *, s32);
void func_L01_003B6250(u8 *a0, u8 *a1, s32 a2) {
    u8 *s = *(u8 **)(a0 + 104);
    s32 r;
    u8 x, y;
    if (*(s16 *)(a1 + 170) == *(s32 *)s) {
        r = func_L01_00456250(a1);
        x = a2 != 0;
        y = r == 0;
        x ^= y;
        if (!x) {
            if (r != 0) {
                *(s32 *)(s + 76) -= 1;
            } else {
                *(s32 *)(s + 76) += 1;
            }
            func_L01_00456230(a1, a2);
        }
    }
}
/* localdecomp:end func_L01_003B6250 */

INCLUDE_ASM("asm/levels", func_L01_003B62E0);

INCLUDE_ASM("asm/levels", func_L01_003B6370);

INCLUDE_ASM("asm/levels", func_L01_003B6458);

/* localdecomp:start func_L01_003B64C0 */


s32 func_L01_003B64C0(S_3B4CC0 *a0) {
    s32 r = a0->p68->w10 * 0;
    S_3B4CC0b *p = a0->p68;
    r = p->w10;
    if (p->w30 > 0) {
        r += p->w30;
    } else if (p->w30 < 0) {
        r += p->w1C * 2;
    }
    return r;
}
/* localdecomp:end func_L01_003B64C0 */

INCLUDE_ASM("asm/levels", func_L01_003B64F0);

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

INCLUDE_ASM("asm/levels", func_L01_003B6B68);

INCLUDE_ASM("asm/levels", func_L01_003B6EB8);

INCLUDE_ASM("asm/levels", func_L01_003B7140);

INCLUDE_ASM("asm/levels", func_L01_003B71B0);

INCLUDE_ASM("asm/levels", func_L01_003B7290);

INCLUDE_ASM("asm/levels", func_L01_003B7568);

INCLUDE_ASM("asm/levels", func_L01_003B78F8);

INCLUDE_ASM("asm/levels", func_L01_003B7AA8);

/* localdecomp:start func_L01_003B7BF8 */
extern void **func_L01_0043B568(s32 a0, s32 a1, s32 a2);
f32 func_L01_003B7BF8(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    void **v = func_L01_0043B568(*(s32 *)s0, 6, 4);
    s32 x = *(s32 *)(s0 + 284);
    if (x == 0) {
        return 0.0f;
    }
    return ((f32 (*)(s32))*v)(x);
}
/* localdecomp:end func_L01_003B7BF8 */

/* localdecomp:start func_L01_003B7C48 */
extern void func_L01_003B7C98(s32 a0);
void func_L01_003B7C48(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        ((void (*)(u8 *a0, u8 *a1))func_L01_003B7C98)(a0, v);
    }
    if (a0[32] == 1) {
        *(u16 *)(a0 + 52) |= 2;
    }
}
/* localdecomp:end func_L01_003B7C48 */

/* localdecomp:start func_L01_003B7C98 */
extern void func_L01_004450F0(s32, s32, s32);
void func_L01_003B7C98(s32 a0) {
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L01_003B7C98 */

INCLUDE_ASM("asm/levels", func_L01_003B7CB8);

LINKER_REMNANT("asm/levels", func_L01_003B8188);
