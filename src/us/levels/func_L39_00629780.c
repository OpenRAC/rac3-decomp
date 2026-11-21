#include "common.h"

/* NTSC-U counterpart of func_L39_0062BF58 (src/levels/shared/L39_0062BE20.c) */
extern s32 D_L39_002462C8[2];
extern u8 D_L39_00272690[];
extern s32 D_L39_00271C40[];
extern void func_L39_005A8F80(void *, void *);

/* localdecomp:start func_L39_00629780 */
typedef struct {
    u8 pad0[6];
    u8 b6[2];
    f32 v8[4];
    s32 w18;
    u8 pad1C[4];
    u8 b20;
    u8 b21;
    u8 b22[2];
    f32 f24;
    s32 w28;
    u8 pad2C[4];
    s16 s30;
    u8 b32;
    u8 b33;
    s32 w34;
    u8 *p38[2];
} Obj_0062BF58;

typedef struct {
    u8 pad0[0x40];
    u8 b40;
    u8 b41;
    u8 b42[2];
    f32 f44;
} Pl_0062BF58;

typedef struct {
    u8 pad0[0x614];
    f32 f614;
    u8 pad618[8];
    s32 w620;
    u8 pad624[0x740 - 0x624];
    Obj_0062BF58 *objA[2];
    Obj_0062BF58 *objB[2];
    u8 pad750[4];
    s32 w754;
    u8 pad758[0xD44 - 0x758];
    f32 fD44;
    u8 padD48[0xD84 - 0xD48];
    f32 fD84;
    f32 fD88;
    u8 padD8C[0xDF4 - 0xD8C];
    f32 fDF4;
    u8 padDF8[0xE34 - 0xDF8];
    f32 fE34;
    f32 fE38;
    u8 padE3C[0x2524 - 0xE3C];
    Pl_0062BF58 *pl;
    u8 pad2528[0x2D00 - 0x2528];
    u8 buf[4][0x400];
} G_0062BF58;

extern s32 D_L39_00246270[4] __attribute__((section(".sdata")));
extern s32 D_L39_002462C8[2];
extern u8 D_L39_00272690[];
extern s32 D_L39_00271C40[];
extern void func_L39_00629648(u8 *, s32, s32, s32, s32);
extern void func_L39_005A8F80(void *, void *);
extern s32 func_L39_00629458(void *, s32, s32);
extern s32 func_L39_0062F1C0(void *, void *, s32);
extern s32 func_L39_0062F1D8(void *, s32, f32 *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00436C90(void *, void *);
extern void func_L01_00437170(u8 *, u8 *, s32, s32, s32, s32);

void func_L39_00629780(G_0062BF58 *g) {
    Obj_0062BF58 *o;
    s32 i;
    s32 j;
    s32 k;
    s32 x;
    s32 fg;
    u8 flag8;
    s32 diff;
    s32 r;
    u8 *tbl;
    f32 f;
    f32 c2;
    f32 c1;
    s32 fading = 1;

    for (i = 0; i < 2; i++) {
        x = 0;
        fg = func_L39_00629458(g, i, g->pl->b42[1]);
        flag8 = (fg & 0x40) > 0;
        if (g->objA[i] != 0 && g->objA[i]->w34 != 0) {
            if (func_003BEBF8(g->objA[i]->v8, 0.0f, 0.1f) == 0.0f) {
                func_L01_00436C90(g->pl, &g->objA[i]);
            }
        } else if (fg != 0) {
            if (g->objA[i] == 0) {
                x = 1;
                if (fg & 0x20) {
                    ((void (*)(u8 *, s32, s32, s32, s32, s32))func_L39_00629648)((u8 *)g, i, flag8, 0, 0, 0xF);
                } else {
                    s32 v = func_L39_0062F1C0(g, g->pl, g->pl->b42[1]);
                    s32 a;
                    if (g->w620 < 0) {
                        a = 1.0f / g->f614;
                    } else {
                        a = D_L39_00246270[g->w620];
                    }
                    ((void (*)(u8 *, s32, s32, s32, s32, s32))func_L39_00629648)((u8 *)g, i, flag8, v, g->pl->b41, a);
                }
            }
        } else {
            if (g->objA[i] == 0) {
                continue;
            }
            if (g->objA[i]->b32 == 0) {
                g->objA[i]->w34 = fading;
                if (func_003BEBF8(g->objA[i]->v8, 0.0f, 0.15f) == 0.0f) {
                    func_L01_00436C90(g->pl, &g->objA[i]);
                }
            }
        }
        {
            Obj_0062BF58 *p = g->objA[i];
            if (p == 0) {
                continue;
            }
            if (flag8 && p->w18 == 0) {
                tbl = D_L39_00272690;
                p->w18 = D_L39_00271C40[tbl[D_L39_002462C8[i]]];
            }
        }
        o = g->objA[i];
        if (o == 0) {
            continue;
        }
        diff = (g->pl->b42[0] ^ g->pl->b42[1]) != 0;
        if (g->objB[i] != 0 && g->w754 == 0) {
            func_003BEBF8(o->v8, 0.0f, 0.15f);
        } else if (g->pl->b42[1] == 0x2B) {
            func_003BEBF8(o->v8, 0.0f, 0.15f);
        } else if (o->w34 == 0) {
            func_003BEBF8(o->v8, 1.0f, 0.25f);
        }
        o->s30 = 0;
        r = func_L39_0062F1D8(g, g->pl->b42[1], &f);
        if (r != 0 || o->b32 != 0) {
            if (f != 0.0f) {
                c1 = 0.05f;
                c2 = 0.3f;
                g->fE34 = c1;
                g->fE38 = c2;
                g->fDF4 = f;
                g->fD44 = f;
                g->fD84 = c1;
                g->fD88 = c2;
            }
            if (r != 0 && (o->b32 == 0 || o->b22[1] != 0)) {
                if (x == 0) {
                    func_L01_00437170((u8 *)g->pl, (u8 *)o, 0, 0, 0xF, 0);
                }
                o->b33 = 0;
                o->b32 = 1;
            }
            if (r == 0) {
                s32 v = func_L39_0062F1C0(g, g->pl, g->pl->b42[1]);
                if (o->b33 == 0) {
                    s32 a;
                    o->b33 = 1;
                    if (g->w620 < 0) {
                        a = 1.0f / g->f614;
                    } else {
                        a = D_L39_00246270[g->w620];
                    }
                    func_L01_00437170((u8 *)g->pl, (u8 *)o, v, g->pl->b41, a, 0);
                    if (fg != 0) {
                        o->b32 = 0;
                    }
                } else if (o->b22[1] != v && diff) {
                    s32 a;
                    if (g->w620 < 0) {
                        a = 1.0f / g->f614;
                    } else {
                        a = D_L39_00246270[g->w620];
                    }
                    func_L01_00437170((u8 *)g->pl, (u8 *)o, v, g->pl->b41, a, 0);
                } else if (!diff) {
                    o->b32 = 0;
                    o->w34 = fading;
                }
            }
            for (j = 0; j < 2; j++) {
                o->p38[j] = g->buf[i * 2 + j];
                if (o->b22[j] < 0x17 && flag8) {
                    o->b6[j] = 1;
                } else if (o->b22[j] != 0xFF) {
                    o->b6[j] = 0;
                }
            }
            func_L39_005A8F80(g->pl, o);
        } else {
            if (x == 0) {
                s32 v = func_L39_0062F1C0(g, g->pl, g->pl->b42[1]);
                if (!diff && o->b22[0] != 0xFF) {
                    for (k = 0; k < 2; k++) {
                        o->b22[k] = func_L39_0062F1C0(g, g->pl, g->pl->b42[k]);
                    }
                } else if (o->b22[1] != v && fg != 0) {
                    s32 a;
                    if (g->w620 < 0) {
                        a = 1.0f / g->f614;
                    } else {
                        a = D_L39_00246270[g->w620];
                    }
                    func_L01_00437170((u8 *)g->pl, (u8 *)o, v, g->pl->b41, a, 0);
                }
                if (!diff && o->b22[0] != 0xFF) {
                    o->b20 = g->pl->b40;
                    o->b21 = g->pl->b41;
                    o->f24 = g->pl->f44;
                    o->w28 = 0;
                } else if (o->b22[0] != 0xFF && fg != 0) {
                    o->b21 = g->pl->b41;
                    o->f24 = g->pl->f44;
                    o->w28 = 0;
                }
            }
            for (j = 0; j < 2; j++) {
                o->p38[j] = g->buf[i * 2 + j];
                if (o->b22[j] != 0xFF) {
                    if (o->b22[j] < 0x17 && flag8) {
                        o->b6[j] = 1;
                    } else if (o->b22[j] != 0xFF) {
                        o->b6[j] = 0;
                    }
                }
            }
            func_L39_005A8F80(g->pl, o);
        }
    }
}
/* localdecomp:end func_L39_00629780 */
