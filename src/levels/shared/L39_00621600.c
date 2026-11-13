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

INCLUDE_ASM("asm/levels", func_L39_006217C0);

/* localdecomp:start func_L39_00621D30 */
void func_L39_00621D30(void *arg0) {
    s32 var_v1;
    void *var_v0;

    *(s32 *)((u8 *)arg0 + 0x1094) = 0;
    var_v1 = 3;
    *(s32 *)((u8 *)arg0 + 0x1098) = 0;
    var_v0 = arg0;
    do {
        *(s32 *)((u8 *)var_v0 + 0x10B4) = 0;
        var_v1 -= 1;
        *(s32 *)((u8 *)var_v0 + 0x10B8) = 0;
        var_v0 += 0x10;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_L39_00621D30 */

INCLUDE_ASM("asm/levels", func_L39_00621D60);

/* localdecomp:start func_L39_00622288 */
typedef struct {
    u8 pad0[0x43];
    u8 b43;
} Obj2524_00622288;

typedef struct {
    u8 pad0[0x748];
    s32 s748;
    u8 pad74C[8];
    s32 s754;
    u8 pad758[0x19E4 - 0x758];
    u8 b19E4;
    u8 pad19E5[0x1A05 - 0x19E5];
    u8 b1A05;
    u8 pad1A06;
    u8 b1A07;
    u8 pad1A08[0x2448 - 0x1A08];
    s32 s2448;
    u8 pad244C[0x2524 - 0x244C];
    Obj2524_00622288 *p2524;
} Self_00622288;

extern u8 D_L39_004997E0[];
extern void func_L39_0062B4A8(void *, s32, s32, s32, f32);
extern s32 func_L39_006223B0(u8 *, s32);

void func_L39_00622288(Self_00622288 *s) {
    u32 buf[2];
    u8 *q;
    u8 *d;
    u32 x;
    s32 n, k, m, i;
    long t;

    if (s->b1A07 != 0) {
        if (s->s2448 == 0x32 && s->s748 != 0) {
            return;
        }
        s->b1A07 = 0;
        s->b1A05 = 0;
        if (s->s748 != 0) {
            s->s754 = 1;
        } else {
            q = &s->b19E4;
            x = 0;
            t = *q;
            if (t != 0) {
                n = *q;
                k = ((u32)q - n) & 7;
                m = n + 1;
                d = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)q;
                buf[1] ^= buf[0];
                x = buf[1];
            }
            if (x == 0 && s->p2524->b43 == s->s2448) {
                func_L39_0062B4A8(s, func_L39_006223B0((u8 *)s, 0), 0, 0, -2.0f);
            }
        }
        s->b1A07 = 0;
        s->b1A05 = 0;
    }
}
/* localdecomp:end func_L39_00622288 */

/* localdecomp:start func_L39_006223B0 */
typedef struct {
    u8 pad0[12];
    s16 h12;
    u8 pad1[33 - 14];
    s8 b33;
    u8 pad2[128 - 34];
} Ent_0061FC10;
extern Ent_0061FC10 D_L39_0049C890[];
extern s32 func_L39_00648AE0(u8 *, s32);
s32 func_L39_006223B0(u8 *p, s32 a) {
    s32 i;
    Ent_0061FC10 *e;
    if (a != 0) {
        if (p[6661] == 0) return 0;
        if (p[6664] != 0) return 0;
        i = -1;
        if (*(s32 *)(p + 1140) == 2) i = *(s32 *)(p + 1144);
        if (i == -1) return 0;
        if (func_L39_00648AE0(p, i)) {
            e = &D_L39_0049C890[D_L39_0049C890[i].b33];
        } else {
            e = &D_L39_0049C890[i];
        }
        return e->h12;
    }
    return 0;
}
/* localdecomp:end func_L39_006223B0 */

INCLUDE_ASM("asm/levels", func_L39_00622450);
