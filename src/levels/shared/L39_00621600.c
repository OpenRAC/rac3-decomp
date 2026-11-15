#include "common.h"

/* localdecomp:start func_L39_00621600 */
typedef struct Inner_00621600 {
    u8 pad0[0x10];
    s32 x10;
} Inner_00621600;

typedef struct Obj_00621600 {
    u8 pad0[0x24];
    Inner_00621600 *x24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x98 - 0x36];
    s32 x98;
} Obj_00621600;

typedef struct Slot_00621600 {
    Obj_00621600 *a;
    Obj_00621600 *b;
    u8 pad8[0x20];
    s32 x28;
    u8 pad2C[0x50 - 0x2C];
} Slot_00621600;

typedef struct S_00621600 {
    u8 pad0[0x424];
    Obj_00621600 *x424;
    u8 pad428[0x450 - 0x428];
    Slot_00621600 slot[6];
    u8 pad630[0x19E4 - 0x630];
    u8 b19E4;
    u8 pad19E5[0x1A0B - 0x19E5];
    u8 b1A0B;
    u8 pad1A0C[0x1A10 - 0x1A0C];
    u8 b1A10;
    u8 pad1A11[0x2480 - 0x1A11];
    s16 h2480;
    u8 pad2482[0x251C - 0x2482];
    s32 x251C;
} S_00621600;

extern u8 D_L39_004997E0[];

void func_L39_00621600(S_00621600 *p) {
    s32 i;
    u32 buf[2];
    u8 *q;
    s32 n;
    s32 k;
    s32 m;
    s32 j;
    u8 *d;
    s32 r;

    p->x424->h34 &= 0xFFFE;
    q = &p->b19E4;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = (u8 *)buf;
        for (j = 0; j < 40; j += 5) {
            *d++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
        }
        buf[0] ^= (u32)q;
        buf[1] ^= buf[0];
        r = buf[1];
    }
    if ((r ^ 0x90) == 0) {
        p->x424->x98 = 0;
    } else {
        p->x424->x98 = p->x424->x24->x10;
    }
    for (i = 0; i < 0x1E0; i += 0x50) {
        S_00621600 *e = (S_00621600 *)((u8 *)p + i);
        if (e->slot[0].a) e->slot[0].a->h34 &= 0xFFFE;
        if (e->slot[0].b) e->slot[0].b->h34 &= 0xFFFE;
    }
    if (p->x251C != 0) {
        if (p->slot[0].x28 == 10) {
            if (p->slot[0].a) p->slot[0].a->h34 |= 1;
            if (p->slot[0].b) p->slot[0].b->h34 |= 1;
        }
    }
    if (p->h2480 != 0) {
        if (p->slot[3].a) p->slot[3].a->h34 |= 0x41;
        if (p->slot[3].b) p->slot[3].b->h34 |= 0x41;
    }
    if ((p->b1A10 != 0 && p->slot[0].x28 == 10) || p->b1A0B != 0) {
        if (p->slot[0].a) p->slot[0].a->h34 |= 0x41;
    }
}
/* localdecomp:end func_L39_00621600 */
