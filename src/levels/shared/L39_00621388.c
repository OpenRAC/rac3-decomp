#include "common.h"

/* localdecomp:start func_L39_00621388 */
/* log: MATCH only with --as ps2as (file is not @ps2as): retail reads D_L39_00241128 via lui/lw after the jal and via $gp in
   branch delay slots (wiki "Mixed access in one function"); default assembler gives $gp everywhere (38 diff).
   Dec as static inline like func_L39_00621600. */
typedef struct Obj_00621388 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x98 - 0x36];
    s32 x98;
} Obj_00621388;

typedef struct Ent_00621388 {
    Obj_00621388 *a;
    Obj_00621388 *b;
    u8 pad8[0x20];
    s32 x28;
    u8 pad2C[0x50 - 0x2C];
} Ent_00621388;

typedef struct S_00621388 {
    u8 pad0[0x424];
    Obj_00621388 *x424;
    u8 pad428[0x450 - 0x428];
    Ent_00621388 ent[6];
    u8 pad630[0x19E4 - 0x630];
    u8 b19E4;
} S_00621388;

typedef struct Aj_00621388 {
    u8 pad0[0xAA];
    s16 hAA;
} Aj_00621388;

typedef struct G_00621388 {
    u8 pad0[0x44];
    s16 h44;
    u8 pad46[0x1A0 - 0x46];
    Aj_00621388 *arr[1];
} G_00621388;

extern u8 D_L39_004997E0[];
extern G_00621388 D_L39_0025CEC0;
extern s32 D_L39_00241128;
extern s32 func_L39_00639D90(void *);

void func_L39_00621388(S_00621388 *p) {
    s32 i;
    s32 j;
    s32 found;
    S_00621388 *e;
    Obj_00621388 *o;
    s32 r;
    u32 buf[2];

    p->x424->h34 |= 1;
    {
        u8 *q;
        s32 n;
        s32 k;
        s32 m;
        s32 t;
        u8 *d;

        q = &p->b19E4;
        if (*q == 0) {
            r = 0;
            goto d1;
        }
            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            d = (u8 *)buf;
            for (t = 0; t < 40; t += 5) {
                *d++ = D_L39_004997E0[m + ((k + t) & 7) * 255];
            }
            buf[0] ^= (u32)q;
            buf[1] ^= buf[0];
            r = buf[1];
    }
    d1:;
    if ((r ^ 0x1D) != 0) {
        {
        u8 *q;
        s32 n;
        s32 k;
        s32 m;
        s32 t;
        u8 *d;

        q = &p->b19E4;
        if (*q == 0) {
            r = 0;
            goto d2;
        }
            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            d = (u8 *)buf;
            for (t = 0; t < 40; t += 5) {
                *d++ = D_L39_004997E0[m + ((k + t) & 7) * 255];
            }
            buf[0] ^= (u32)q;
            buf[1] ^= buf[0];
            r = buf[1];
        }
    d2:;
        if ((r ^ 1) != 0 && func_L39_00639D90(p) == 0) {
            p->x424->x98 = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (i == 0 && func_L39_00639D90(p) == 2) {
            continue;
        }
        if (D_L39_00241128 == 2) {
            found = 0;
            for (j = 0; j < D_L39_0025CEC0.h44; j++) {
                if (D_L39_0025CEC0.arr[j]->hAA == 0) {
                    found = 1;
                }
            }
            if (found) {
                continue;
            }
        }
        e = (S_00621388 *)((u8 *)p + i * 0x50);
        if (e->ent[0].a) e->ent[0].a->h34 |= 1;
        if (e->ent[0].b) e->ent[0].b->h34 |= 1;
    }
    if (p->ent[0].x28 == 10) {
        o = p->ent[0].a;
        if (o && D_L39_00241128 == 0 && o->b20) {
            o->h34 &= 0xFFBE;
        }
    }
}
/* localdecomp:end func_L39_00621388 */
