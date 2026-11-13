#include "common.h"

/* declared by functions of L39_0062BC30.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_0062BE20 */
typedef struct {
    u8 pad0[6];
    u8 b6;
    u8 b7;
    s32 w8;
    u8 padC[0x18 - 0xC];
    s32 w18;
    u8 pad1C[0x20 - 0x1C];
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    s32 w24;
    s32 w28;
    s32 w2C;
    u8 pad30[2];
    u8 b32;
    u8 pad33[5];
    u8 *p38;
    u8 *p3C;
} S_0062BE20;

extern s32 D_L39_002460E8[2];
extern s32 D_L39_00246148[2];
extern u8 D_L39_00272590[];
extern s32 D_L39_00271B40[];
extern S_0062BE20 *func_L39_005AAD08(void *, s32, void *, s32);
extern void func_L39_005AAE60(void *, void *);

void func_L39_0062BE20(u8 *g, s32 i, s32 a2, s32 a3, s32 a4) {
    S_0062BE20 **tab = (S_0062BE20 **)(g + 0x740);
    S_0062BE20 **slot = tab + i;
    S_0062BE20 *o;
    if (*slot == 0) {
        s32 sz = D_L39_002460E8[i];
        o = func_L39_005AAD08(*(void **)(g + 0x2524), sz, g + (i * 0x3C0 + 0x2580), 0x3C0);
        *slot = o;
        o->w8 = 0;
        o->b32 = 0;
        o->b22 = a3;
        o->b20 = a4;
        o->b23 = a3;
        o->b21 = a4;
        o->p38 = g + (i * 0x800 + 0x2D00);
        o->p3C = g + (i * 0x800 + 0x3100);
        o->b6 = a2;
        o->b7 = a2;
        o->w24 = 0;
        o->w28 = 0;
        o->w2C = 0;
        if (a2) {
            o->w18 = D_L39_00271B40[D_L39_00272590[D_L39_00246148[i]]];
        }
        func_L39_005AAE60(*(void **)(g + 0x2524), o);
    }
}
/* localdecomp:end func_L39_0062BE20 */

INCLUDE_ASM("asm/levels", func_L39_0062BF58);

/* localdecomp:start func_L39_0062C6A0 */
#include "vu0.h"

typedef int q_0062C6A0 __attribute__((mode(TI)));

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_0062C6A0;

typedef struct {
    u8 pad0[0x5];
    u8 b5;
    u8 pad6[0x8 - 0x6];
    f32 f8;
    u8 padC[0x23 - 0xC];
    u8 b23;
    u8 pad24[0x28 - 0x24];
    s32 w28;
} Obj_0062C6A0;

typedef struct {
    u8 pad0[0xE];
    s16 hE;
    s16 h10;
    u8 pad12[0x21 - 0x12];
    s8 b21;
    u8 pad22[0x80 - 0x22];
} Ent_0062C6A0;

typedef struct {
    u8 pad0[0x10];
    q_0062C6A0 q10;
    u8 pad20[0xC0 - 0x20];
    q_0062C6A0 qC0;
    q_0062C6A0 qD0;
    q_0062C6A0 qE0;
    u8 padF0[0x380 - 0xF0];
    q_0062C6A0 q380;
    q_0062C6A0 q390;
    q_0062C6A0 q3A0;
} Src_0062C6A0;

typedef struct {
    u8 pad0[0xB0];
    q_0062C6A0 qB0;
    u8 padC0[0x380 - 0xC0];
    q_0062C6A0 q380;
    q_0062C6A0 q390;
    q_0062C6A0 q3A0;
    union {
        q_0062C6A0 q;
        f32 f[4];
    } u3B0;
    union {
        q_0062C6A0 q;
        f32 f[4];
    } u3C0;
    u8 pad3D0[0x3E4 - 0x3D0];
    s16 h3E4;
    u8 pad3E6[0x474 - 0x3E6];
    s32 w474;
    s32 w478;
    u8 pad47C[0x748 - 0x47C];
    Obj_0062C6A0 *objs[2];
    u8 pad750[0x754 - 0x750];
    s32 w754;
    u8 pad758[0x858 - 0x758];
    f32 f858;
    u8 pad85C[0x908 - 0x85C];
    f32 f908;
    u8 pad90C[0x1310 - 0x90C];
    s32 w1310;
    u8 pad1314[0x19E4 - 0x1314];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A05 - 0x19E7];
    u8 b1A05;
    u8 b1A06;
    u8 b1A07;
    u8 pad1A08[0x1A14 - 0x1A08];
    u8 b1A14;
    u8 pad1A15[0x23B0 - 0x1A15];
    q_0062C6A0 q23B0;
    q_0062C6A0 q23C0;
    q_0062C6A0 q23D0;
    q_0062C6A0 q23E0;
    u8 pad23F0[0x2448 - 0x23F0];
    s32 w2448;
    s32 w244C;
    u8 pad2450[0x2524 - 0x2450];
    Src_0062C6A0 *p2524;
    u8 pad2528[0x2530 - 0x2528];
    Src_0062C6A0 *p2530;
    s32 w2534;
} G_0062C6A0;

extern Ent_0062C6A0 D_L39_0049C890[];
extern u8 D_L39_004997E0[];
extern s32 func_L39_00620CF8(u8 *, s32);
extern void func_L39_00622288(void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_L01_0043A250(u8 *, u8 *, s32, s32, s32, s32);
extern void func_L39_005AAE60(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_00439D70(void *, void *);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D000(void *, void *, void *);

void func_L39_0062C6A0(G_0062C6A0 *g) {
    Buf_0062C6A0 buf;
    s32 i;
    s32 id;
    f32 f;

    if (g->b1A07 != 0 && g->b1A05 != 0 && func_L39_00620CF8((u8 *)g, -1) == 0) {
        func_L39_00622288(g);
    }
    for (i = 0; i < 2; i++) {
        if (g->objs[i] == 0) {
            continue;
        }
        id = (g->w474 == 2) ? g->w478 : -1;
        if (id == g->w244C) {
            Ent_0062C6A0 *e;
            s32 v;
            u8 *q;
            u32 dec;

            if (func_L39_00648AE0((u8 *)g, id) != 0) {
                e = &D_L39_0049C890[D_L39_0049C890[id].b21];
            } else {
                e = &D_L39_0049C890[id];
            }
            v = e->hE;
            q = &g->b19E6;
            if (*q == 0) {
                dec = 0;
            } else {
                u32 a;
                u32 b;
                s32 n;
                s32 k;
                s32 m;
                s32 j;
                u8 *d;

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
            if ((dec ^ 0xC) == 0) {
                Ent_0062C6A0 *e2;
                if (func_L39_00648AE0((u8 *)g, id) != 0) {
                    e2 = &D_L39_0049C890[D_L39_0049C890[id].b21];
                } else {
                    e2 = &D_L39_0049C890[id];
                }
                v = e2->h10;
            }
            if (v != -1 && g->objs[i]->b23 != v) {
                g->w2448 = v;
                func_L01_0043A250((u8 *)g->p2524, (u8 *)g->objs[i], v, 0, 7, 0);
            }
        }
        func_L39_005AAE60(g->p2524, g->objs[i]);
        if (g->w754 != 0) {
            if (g->w754 == 2) {
                func_003C4138(&g->objs[i]->f8, 0.0f, 0.3f);
            } else {
                func_003C4138(&g->objs[i]->f8, 0.0f, 0.084000006f);
            }
            if (g->objs[i]->f8 == 0.0f) {
                func_L01_00439D70(g->p2524, &g->objs[i]);
                return;
            }
        } else {
            func_003C4138(&g->objs[i]->f8, 1.0f, 0.24000001f);
            if ((g->objs[i]->b5 & 2) != 0 && g->b1A05 == 0) {
                s32 id2;
                s32 c;
                g->w754 = 1;
                id2 = (g->w474 == 2) ? g->w478 : -1;
                switch (id2) {
                case 6:
                case 12:
                    c = 1;
                    break;
                default:
                    c = 0;
                    break;
                }
                if (c) {
                    g->w754 = 2;
                }
                g->objs[i]->w28 = 0;
                g->b1A07 = 0;
                return;
            }
        }
    }
    f = 0.0f;
    if (g->h3E4 != 0 || (g->w1310 == 1 && func_L01_004606E8(0x28, 2, 0, g->w2534) != 0 && func_L39_006212E8(g) != 10)) {
        u8 *q = &g->b19E4;
        u32 dec;

        if (*q == 0) {
            dec = 0;
        } else {
            u32 a;
            u32 b;
            s32 n;
            s32 k;
            s32 m;
            s32 j;
            u8 *d;

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
        if ((dec ^ 0x10) != 0) {
            goto skip;
        }
    }
    f = func_0038DAB8(g->f908, g->f858);
skip:
    if (g->w1310 < 3) {
        if (g->w1310 > 0) {
            if (g->b1A14 != 0) {
                Src_0062C6A0 *s = g->p2530;
                g->q380 = s->q380;
                g->q390 = s->q390;
                g->q3A0 = s->q3A0;
                g->u3B0.q = s->q380;
                g->u3C0.q = s->q10;
            } else {
                g->q380 = g->q23C0;
                g->q390 = g->q23D0;
                g->q3A0 = g->q23E0;
                g->u3B0.q = g->q23C0;
                g->u3C0.q = g->q23B0;
            }
            return;
        }
    }
    {
        Src_0062C6A0 *s = g->p2524;
        g->q380 = s->qC0;
        g->q390 = s->qD0;
        g->q3A0 = s->qE0;
        qzero(&g->u3B0);
        g->u3B0.f[0] = 1.0f;
        func_0038D000(&g->u3B0, &g->u3B0, &g->q380);
        g->u3C0.q = g->qB0;
        if (g->b1A06 == 0) {
            g->u3C0.f[2] = func_0038DAB8(g->u3C0.f[2], f);
        }
    }
}
/* localdecomp:end func_L39_0062C6A0 */

INCLUDE_ASM("asm/levels", func_L39_0062CB60);

INCLUDE_ASM("asm/levels", func_L39_0062CD88);
