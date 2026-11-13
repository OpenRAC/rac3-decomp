#include "common.h"

/* declared by functions of L39_00668620.c, which this file was cut from */
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_L39_002461F8;
extern E_665D48 D_L39_00337700[];

/* localdecomp:start func_L39_0066ADA0 */
/* LOG: first draft 67 diff; MATCH after (a) b382 read twice instead of a local c, (b) `(Dec ^ 0x14) == 0`,
 * (c) a per-function alias D_L39_0024BB90_0066ADA0 (.extern 16) for the non-delay-slot store (retail's lui $at form). */
typedef struct Ply_0066ADA0 {
    u8 pad0[0x2D0];
    s32 w2D0;
    u8 pad2D4[0x19E6 - 0x2D4];
    u8 b19E6;
    u8 pad19E7[0x1A14 - 0x19E7];
    u8 b1A14;
    u8 pad1A15[0x24C9 - 0x1A15];
    u8 b24C9;
} Ply_0066ADA0;

typedef struct Ref_0066ADA0 {
    u8 pad0[0x382];
    u8 b382;
} Ref_0066ADA0;

typedef struct Obj_0066ADA0 {
    u8 pad0[0x23];
    u8 b23;
    u8 pad24[0x34 - 0x24];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Ref_0066ADA0 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} Obj_0066ADA0;

typedef struct Ent_0066ADA0 {
    u8 pad0[0x2D0];
    Obj_0066ADA0 *o2D0;
    u8 pad2D4[4];
    Ply_0066ADA0 *p2D8;
    Ply_0066ADA0 *p2DC;
    u8 pad2E0[0x340 - 0x2E0];
} Ent_0066ADA0;

typedef union Buf_0066ADA0 {
    u8 b[8];
    u32 w[2];
} Buf_0066ADA0;

extern s32 D_L39_002461F8;
extern s32 D_L39_00241118;
extern s32 D_L39_0024BB90;
extern s32 D_L39_0024BB90_0066ADA0;
__asm__(".extern D_L39_0024BB90_0066ADA0, 16");
extern u8 D_L39_004997E0[];
extern Ply_0066ADA0 *func_L39_0061BF38(s32);

void func_L39_0066ADA0(void) {
    s32 i;
    Ent_0066ADA0 *e;
    Obj_0066ADA0 *o;
    Ply_0066ADA0 *r;
    Buf_0066ADA0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 j;
    s32 dec;
    u8 *d;
    u8 *q;
    long t;

    D_L39_0024BB90 = 0;
    for (i = 0; i < D_L39_002461F8; i++) {
        e = (Ent_0066ADA0 *)&D_L39_00337700[i];
        if (e != 0) {
            o = e->o2D0;
            if (o != 0 && o->hAA == 0x107E) {
                if (o->p68->b382 != 0) {
                    r = func_L39_0061BF38(o->p68->b382 - 1);
                    if (r != 0 && r->b24C9 == D_L39_00241118) {
                        q = &r->b19E6;
                        if (r->w2D0 == 0 || (({
                            dec = 0;
                            t = *q;
                            if (t != 0) {
                                n = *q;
                                k = ((u32)q - n) & 7;
                                m = n + 1;
                                d = buf.b;
                                for (j = 0; j < 40; j += 5) {
                                    *d++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                                }
                                a = buf.w[0] ^ (u32)q;
                                b = buf.w[1] ^ a;
                                buf.w[0] = a;
                                buf.w[1] = b;
                                dec = b;
                            }
                            dec;
                        }) ^ 0x14) == 0) {
                            D_L39_0024BB90_0066ADA0 = 2;
                        }
                    }
                }
                if (e->p2D8 != 0 && e->p2D8->b1A14 != 0 && e->p2D8->b24C9 == D_L39_00241118) {
                    D_L39_0024BB90 = 2;
                }
                if (e->p2DC != 0 && e->p2DC->b1A14 != 0 && e->p2DC->b24C9 == D_L39_00241118) {
                    D_L39_0024BB90 = 2;
                }
                if (e->p2DC != 0 && e->p2DC->b1A14 != 0 && e->p2DC->b24C9 == D_L39_00241118) {
                    e->o2D0->b23 = 0x20;
                    e->o2D0->h34 |= 0x800;
                } else {
                    e->o2D0->b23 = 0x80;
                    e->o2D0->h34 &= 0xF7FF;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0066ADA0 */

INCLUDE_ASM("asm/levels", func_L39_0066AFA0);

/* localdecomp:start func_L39_0066B6F8 */
s32 func_L39_0066B6F8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x2D0));
}
/* localdecomp:end func_L39_0066B6F8 */

/* localdecomp:start func_L39_0066B700 */
typedef struct S_0066B700 { u8 p0[0x80]; struct S_0066B700 *prev; struct S_0066B700 *next; u8 p88[8]; } S_0066B700;
extern S_0066B700 D_L39_0033C110[];
extern S_0066B700 D_L39_0033F950[];
extern S_0066B700 D_L39_0033C080[];
extern S_0066B700 D_L39_0033F8C0[];
extern S_0066B700 *D_L39_0024CF60;
__asm__(".extern D_L39_0024CF60, 12");
__asm__(".extern D_L39_0024CF64, 12");
__asm__(".extern D_L39_0024CF68, 12");
extern S_0066B700 *D_L39_0024CF68;
extern s32 D_L39_0024CF64;
extern s32 D_L39_0024CF6C;
extern void func_L39_0066C420_0066B700(void);

void func_L39_0066B700(void) {
    s32 i;
    for (i = 0; i < 100; i++) {
        if (i == 0) {
            D_L39_0033C110[i].prev = 0;
            D_L39_0033F950[i].prev = 0;
        } else {
            D_L39_0033C110[i].prev = &D_L39_0033C080[i];
            D_L39_0033F950[i].prev = &D_L39_0033F8C0[i];
        }
        if (i == 99) {
            D_L39_0033C110[i].next = 0;
            D_L39_0033F950[i].next = 0;
        } else {
            D_L39_0033C110[i].next = &D_L39_0033C110[i + 1];
            D_L39_0033F950[i].next = &D_L39_0033F950[i + 1];
        }
    }
    D_L39_0024CF60 = D_L39_0033C110;
    D_L39_0024CF68 = D_L39_0033F950;
    D_L39_0024CF64 = 0;
    D_L39_0024CF6C = 0;
    func_L39_0066C420_0066B700();
}
/* localdecomp:end func_L39_0066B700 */

/* localdecomp:start func_L39_0066B7C8 */
typedef struct { s32 w0, w4, w8; } S_0066B7C8b;
typedef struct { u8 p0[0x30]; u8 b30; u8 p31[0x68 - 0x31]; S_0066B7C8b *w68; } S_0066B7C8;
extern S_0066B7C8 *D_L39_0024CF40[8] __attribute__((section(".sdata")));
extern s32 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern S_0066B7C8 *func_003C24B0(s32, s32);
extern void func_L39_0066C420_0066B7C8(void);

void func_L39_0066B7C8(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        s32 *p = D_L39_0024CE20[i];
        S_0066B7C8b *q;
        if (p != 0) {
            D_L39_0024CF40[i] = func_003C24B0(0x173D, 0x150);
            D_L39_0024CF40[i]->b30 = 0xFF;
            q = D_L39_0024CF40[i]->w68;
            q->w4 = *p;
            q->w8 = (s32)p;
            q->w0 = 0;
        }
    }
    func_L39_0066C420_0066B7C8();
}
/* localdecomp:end func_L39_0066B7C8 */

/* localdecomp:start func_L39_0066B870 */
typedef struct { s32 id; u8 pad[44]; } S_00668F68;
extern S_00668F68 D_L39_0033B990[];

s32 func_L39_0066B870(s32 id) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (D_L39_0033B990[i].id == id) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_0066B870 */

/* localdecomp:start func_L39_0066B8A8 */
extern S_00668F68 D_L39_0033B990[];
extern u8 *func_L39_0066C1F0(s32);

u8 *func_L39_0066B8A8(u8 *ia, s32 *p) {
    s32 i = (s32)ia;
    u8 *b = (u8 *)D_L39_0033B990;
    u8 *b4 = b + 4;
    while (*p < *(s32 *)(b4 + i * 48)) {
        s32 off = *p * 4 + i * 48;
        u8 *b8 = (u8 *)&D_L39_0033B990[0].pad[4];
        u8 *r = func_L39_0066C1F0(*(s32 *)(off + b8));
        if (r != 0) {
            return r;
        }
        (*p)++;
    }
    return 0;
}
/* localdecomp:end func_L39_0066B8A8 */

/* localdecomp:start func_L39_0066B958 */
typedef struct { s32 a, b, c; } S_0066B958;
extern s32 D_001DAB38_sda;
extern S_0066B958 D_L39_00343190[];
void func_L39_0066B958(void) {
    s32 i;
    if (D_001DAB38_sda == 0) {
        for (i = 0; i < 30; i++) {
            D_L39_00343190[i].a = -1;
            D_L39_00343190[i].b = -1;
            D_L39_00343190[i].c = -1;
        }
        D_001DAB38_sda = 1;
    }
}
/* localdecomp:end func_L39_0066B958 */

/* localdecomp:start func_L39_0066B9A0 */
extern void func_L39_0066B958(void);

void func_L39_0066B9A0(s32 a, s32 b) {
    s32 i;
    func_L39_0066B958();
    for (i = 0; i < 30; i++) {
        if (D_L39_00343190[i].c == b) {
            return;
        }
        if (D_L39_00343190[i].a == -1 && D_L39_00343190[i].b == -1) {
            break;
        }
    }
    if (i != 30) {
        D_L39_00343190[i].a = a;
        D_L39_00343190[i].c = b;
    }
}
/* localdecomp:end func_L39_0066B9A0 */

/* localdecomp:start func_L39_0066BA78 */
extern void func_L39_0066B958(void);

void func_L39_0066BA78(s32 a, s32 b) {
    s32 i;
    func_L39_0066B958();
    for (i = 0; i < 30; i++) {
        if (D_L39_00343190[i].b == a) {
            return;
        }
        if (D_L39_00343190[i].a == -1 && D_L39_00343190[i].b == -1) {
            break;
        }
    }
    if (i != 30) {
        D_L39_00343190[i].b = a;
        D_L39_00343190[i].c = b;
    }
}
/* localdecomp:end func_L39_0066BA78 */
