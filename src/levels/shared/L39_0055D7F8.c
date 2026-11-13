#include "common.h"

/* localdecomp:start func_L39_0055D7F8 */
s32 func_L39_0055D7F8(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x107e;
}
/* localdecomp:end func_L39_0055D7F8 */

/* localdecomp:start func_L39_0055D808 */
s32 func_L39_0055D808(u8 *a0) {
    return *(s16 *)(a0 + 0xAA) == 0xCBE;
}
/* localdecomp:end func_L39_0055D808 */

/* localdecomp:start func_L39_0055D818 */
s32 func_L39_0055D818(u8 *a0) {
    return *(s16 *)(a0 + 0xAA) == 0x1A47;
}
/* localdecomp:end func_L39_0055D818 */

/* localdecomp:start func_L39_0055D828 */
typedef struct E_0055D828 {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0x98 - 0x36];
    s32 w98;
} E_0055D828;

typedef struct P_0055D828 {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x44 - 0x14];
    u16 h44;
} P_0055D828;

typedef struct R_0055D828 {
    s32 w0;
    s32 w4;
    s32 w8;
} R_0055D828;

typedef struct Q_0055D828 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x200 - 0x36];
    u32 w200;
    s32 w204;
    s32 w208;
    u8 pad20C[0x220 - 0x20C];
    s32 w220;
    s32 w224;
    u8 pad228[0x24C - 0x228];
    s32 w24C;
    u8 pad250[0x258 - 0x250];
    E_0055D828 *p258;
} Q_0055D828;

typedef struct S_0055D828 {
    u8 pad0[0x24];
    P_0055D828 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Q_0055D828 *p68;
    u8 pad6C[0x98 - 0x6C];
    s32 w98;
    u8 pad9C[0xA8 - 0x9C];
    u8 bA8;
} S_0055D828;

extern s32 D_001A5DF8[];
__asm__(".extern D_L39_0024112C, 16");
extern s32 D_L39_0024112C;
__asm__(".extern D_L39_0024BF5C_0055D828, 16");
extern u8 *D_L39_0024BF5C_0055D828;
extern void func_L39_005F2FF8(void *, s32);
extern s32 func_L39_0055D808(u8 *);
extern s32 func_L39_0055D818(u8 *);

void func_L39_0055D828(S_0055D828 *s) {
    P_0055D828 *p = s->p24;
    Q_0055D828 *q = s->p68;
    s32 t;
    R_0055D828 *r = (R_0055D828 *)((u8 *)q + 0x200);

    s->h34 &= 0xFFBE;
    s->h34 |= p->h44 & 0x1000;
    s->w98 = p->w10;
    q->p258->h34 |= 0x41;
    q->p258->h34 &= 0xEFFF;
    q->p258->w98 = 0;
    func_L39_005F2FF8(q->p258, 1);
    s->bA8 = 0xFF;
    r->w4 = 0;
    t = D_L39_0024112C + 0x32;
    r->w8 = D_001A5DF8[0];
    q->w200 = 0xFFFFFFFF;
    q->w224 = t;
    q->w220 = 0;
    q->f30 = q->h34;
    if (q->w24C >= 0) {
        if (func_L39_0055D808(D_L39_0024BF5C_0055D828 + (q->w24C << 8)) == 0) {
            func_L39_0055D818(D_L39_0024BF5C_0055D828 + (q->w24C << 8));
        }
    }
}
/* localdecomp:end func_L39_0055D828 */

/* localdecomp:start func_L39_0055D948 */
typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0x43 - 0x36];
    u8 f43;
    u8 pad44[0x48 - 0x44];
    f32 f48;
    u8 pad4C[0x68 - 0x4C];
    u8 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
} Obj_0055D948;

typedef struct {
    u8 pad0[0x230];
    s32 f230;
    u8 pad234[0x258 - 0x234];
    Obj_0055D948 *f258;
} Aux_0055D948;

extern u16 *D_L39_002927E0[];
__asm__(".extern D_L39_0024BF5C, 16");
struct E_0055DB18;
extern struct E_0055DB18 *D_L39_0024BF5C;
extern s32 D_L39_0024BF98;
__asm__(".extern D_L39_0024BF98_b, 16");
extern s32 D_L39_0024BF98_b;
extern void func_L39_005F2FF8(void *, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
struct S_0055D828;
extern void func_L39_0055D828(struct S_0055D828 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L39_0055D948(s32 id) {
    u16 *p;
    u8 idx;
    Obj_0055D948 *obj;
    Aux_0055D948 *aux;

    if (id == 0xFF) {
        return;
    }
    p = D_L39_002927E0[id];
    idx = id;
    if (idx == 0xFF) {
        return;
    }
    if (D_L39_0024BF98_b < id) {
        return;
    }
    if (p == 0) {
        return;
    }
    do {
        obj = (Obj_0055D948 *)((u8 *)D_L39_0024BF5C + ((*p & 0x7FFF) << 8));
        if (obj == 0) {
            return;
        }
        obj->f34 = (obj->f34 | 0x41) & 0xEFFF;
        obj->f98 = 0;
        aux = (Aux_0055D948 *)obj->f68;
        func_L39_005F2FF8(obj, 1);
        if (aux->f258 != 0) {
            aux->f258->f34 |= 0x41;
            aux->f258->f34 &= 0xEFFF;
            aux->f258->f98 = 0;
            func_L39_005F2FF8(aux->f258, 1);
        }
        if (func_003D4D00((u8 *)obj + 0x10, 1, 0, 0, 0.75f) == 0) {
            func_L39_0055D828((struct S_0055D828 *)obj);
            if (aux->f230 != 0) {
                func_L01_004450F0(obj, 3, -1);
            } else {
                if (obj->f43 != 0) {
                    func_003C3A10(obj, 0, 0, 1);
                }
                obj->f48 = 1.0f;
                func_L01_004450F0(obj, 1, -1);
            }
        } else {
            func_L01_004450F0(obj, 9, -1);
        }
        p++;
        if (idx == 0xFF) {
            break;
        }
        if (D_L39_0024BF98 < id) {
            break;
        }
        if (p == 0) {
            break;
        }
    } while ((s16)p[-1] >= 0 || p == D_L39_002927E0[id]);
}
/* localdecomp:end func_L39_0055D948 */

/* localdecomp:start func_L39_0055DB18 */
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
typedef struct S_0055DB18 {
    u8 pad[0x24C];
    s32 f24C;
} S_0055DB18;
__asm__(".extern D_L39_0024BF5C, 16");
extern E_0055DB18 *D_L39_0024BF5C;
extern T_0055DB18 *D_L39_00352B4C[];
extern s32 func_L39_0055D808(u8 *);
extern s32 func_L39_0055D818(u8 *);

s32 func_L39_0055DB18(S_0055DB18 *self)
{
    s32 r = -1;
    if (self->f24C >= 0) {
        if (func_L39_0055D808((u8 *)&D_L39_0024BF5C[self->f24C])) {
            r = D_L39_00352B4C[0]->w88[D_L39_0024BF5C[self->f24C].f68->f1C];
        } else if (func_L39_0055D818((u8 *)&D_L39_0024BF5C[self->f24C])) {
            r = D_L39_00352B4C[0]->wA8[D_L39_0024BF5C[self->f24C].f68->f2C];
        }
    }
    return r;
}
/* localdecomp:end func_L39_0055DB18 */

/* localdecomp:start func_L39_0055DBE8 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L39_0055DBE8(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L39_0055DBE8 */

/* localdecomp:start func_L39_0055DC30 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
typedef struct {
    u8 pad0[0x55];
    u8 b55;
} S_55D1B8;

extern S_55D1B8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern void func_L39_006626E8(S_55D1B8 *p);

void func_L39_0055DC30(s32 a0) {
    S_55D1B8 *p;
    ((void (*)(s32 a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(a0, 1, 0, 250);
    p = func_L39_0066DD30(a0, 2, 0);
    if (p != 0 && p->b55 != 0) {
        func_L39_006626E8(p);
    }
}
/* localdecomp:end func_L39_0055DC30 */

/* localdecomp:start func_L39_0055DC90 */
extern S_55D1B8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L39_0055DC90(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 0, 0) != 0;
}
/* localdecomp:end func_L39_0055DC90 */

/* localdecomp:start func_L39_0055DCB8 */
extern S_55D1B8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L39_0055DCB8(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 1, 0) != 0;
}
/* localdecomp:end func_L39_0055DCB8 */
