#include "common.h"

/* localdecomp:start func_L39_0066E010 */
typedef struct S_0066E010q {
    u8 pad0[0x38];
    s32 w38;
} S_0066E010q;

typedef struct S_0066E010p {
    u8 pad0[4];
    S_0066E010q *w4;
} S_0066E010p;

typedef struct S_0066E010 {
    u8 pad0[0x2558];
    S_0066E010p *w2558;
} S_0066E010;

typedef struct S_0066E010d {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x170 - 0xC];
    s32 w170;
} S_0066E010d;

extern S_0066E010d D_001A5CD0;
extern S_0066E010 *func_L39_0061C488(s32);
extern s32 *func_L39_00668620(s32);
extern s32 *func_L39_0066C238(s32);
extern s32 func_L39_0066E100(s32, s32, s32, s32, s32, s32, s32, void *);

s32 func_L39_0066E010(void *a0, s32 a1, void *a2, s32 a3, void *a4) {
    S_0066E010 *pl;
    s32 *e;
    s32 id;
    S_0066E010d *d = &D_001A5CD0;
    if (d->w8 < 0 || d->w170 != 0) {
        return -1;
    }
    id = 0;
    pl = func_L39_0061C488(a3);
    if (pl != 0) {
        id = pl->w2558->w4->w38;
    } else {
        e = func_L39_00668620(a3);
        if (e != 0) {
            id = *e;
        } else {
            e = func_L39_0066C238(a3);
            if (e != 0) {
                id = *e;
            }
        }
    }
    return func_L39_0066E100(((S_0066E010 *)a0)->w2558->w4->w38, id, a1, 1, 0, 0, (s32)a2, a4);
}
/* localdecomp:end func_L39_0066E010 */

/* localdecomp:start func_L39_0066E100 */
#include "vu0.h"

typedef struct S_0066E100v {
    f32 x;
    f32 y;
    f32 z;
} S_0066E100v;

typedef struct S_0066E100v4 {
    f32 x;
    f32 y;
    f32 z;
    s32 w;
} S_0066E100v4;

typedef struct S_0066E100pl {
    u8 pad0[0x2524];
    s32 w2524;
} S_0066E100pl;

typedef struct S_0066E100n {
    u8 pad0[0x10];
    S_0066E100v4 pos;
    u8 pad20[0x28 - 0x20];
    s32 w28;
    s32 w2C;
    u8 pad30[0x34 - 0x30];
    s16 h34;
    s16 h36;
    s32 w38;
    s32 w3C;
    void *w40;
    void *w44;
    void *w48;
    S_0066E100pl *w4C;
    s32 w50;
    s32 w54;
    s32 w58;
    s32 w5C;
    s32 w60;
    s32 w64;
} S_0066E100n;

typedef struct S_0066E100d {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x128 - 8];
    s32 w128;
    u8 pad12C[0x170 - 0x12C];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} S_0066E100d;

typedef struct S_0066E100b {
    S_0066E100v pos;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
    u8 b1C;
} S_0066E100b;

extern s32 D_L39_00241160;
extern s32 D_L39_002405AC;
extern S_0066E100n *func_L39_0066DF40(void);
extern S_0066E100pl *func_L39_0061BFB0(s32);
extern void *func_L39_006685D8(s32);
extern void *func_L39_0066C1F0(s32);
extern s32 func_00197498(s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

s32 func_L39_0066E100(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, void *a7v) {
    S_0066E100v *a7 = a7v;
    S_0066E100n *n;
    S_0066E100b b;
    s32 t;
    if (a2 >= 5) {
    n = func_L39_0066DF40();
    if (n != 0) {
    n->h34 = a2;
    n->w64 = a3;
    if (a7 != 0) {
        S_0066E100v4 *p = &n->pos;
        p->x = a7->x;
        p->y = a7->y;
        p->z = a7->z;
        p->w = 0;
    } else {
        qzero(&n->pos);
    }
    n->w54 = a0;
    if ((((u32)a0 >> 24) & 0xF) == 0) {
        n->w4C = func_L39_0061BFB0(a0);
        if (n->w4C != 0) {
            n->w2C = n->w4C->w2524;
        } else {
            n->w2C = 0;
        }
    }
    n->w50 = a1;
    n->w40 = 0;
    n->w44 = 0;
    n->w48 = 0;
    t = ((u32)a1 >> 24) & 0xF;
    if (t == 0) {
        n->w40 = func_L39_0061BFB0(a1);
    } else if (t == 3) {
        n->w44 = func_L39_006685D8(a1);
    } else if (t == 2) {
        n->w48 = func_L39_0066C1F0(a1);
    }
    n->w60 = 0;
    n->w5C = 0x106D;
    if (a3 != 0) {
        S_0066E100d *d;
        S_0066E100v4 *q;
        n->w28 = a6;
        n->h36 = 0;
        n->w38 = (D_L39_00241160 * 5 + 2) / 6;
        d = (S_0066E100d *)&D_001A5CD0;
        n->w3C = d->w128;
        n->w58 = func_00197498(1);
        q = &n->pos;
        b.b1C = a2;
        b.w18 = n->w58;
        b.w10 = a0;
        b.w14 = a1;
        b.pos.x = q->x;
        b.pos.y = q->y;
        b.pos.z = q->z;
        b.wC = d->w128;
        if (d->w170 == 0) {
            func_0014AD08(d->b7D4, d->w4, -1, D_L39_002405AC, 0x20, &b);
        }
    } else {
        n->w3C = a5;
        n->h36 = 1;
        n->w58 = a4;
        n->w38 = 0;
    }
    return n->w58;
    }
    }
    return -1;
}
/* localdecomp:end func_L39_0066E100 */
