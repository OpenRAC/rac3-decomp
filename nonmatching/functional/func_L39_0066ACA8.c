/* functional: high. Compiles at level 39; PAL asm transcribed (colour table D_002462A8 for kinds >= 2, fixed colours for kinds 0/1 by slot type); bytes differ in scheduling. */
#include "common.h"
typedef struct S_0066ACA8 {
    u8 pad0[0x2D0];
    u8 *model;
    u8 pad2D4[0x2FC - 0x2D4];
    u16 type;
} S_0066ACA8;

extern u8 D_L39_002462A8[];
extern void func_L01_0043B9E8(void *, s32, s32, s32);

/* Sets the slot model's tint: a table entry per colour index (kinds 0/1 are fixed per slot type),
   written straight into the model's colour word for type 0, else through the tint call. */
void func_L39_0066ACA8(S_0066ACA8 *s, s32 kind) {
    s32 r;
    s32 g;
    s32 b;

    if (kind == 0) {
        if ((s16)s->type == 0) {
            r = 10;
            g = 10;
            b = 250;
        } else {
            r = 60;
            g = 60;
            b = 100;
        }
    } else if (kind == 1) {
        if ((s16)s->type == 1) {
            r = 120;
            g = 15;
            b = 0;
        } else if ((s16)s->type == 0) {
            r = 250;
            g = 10;
            b = 10;
        } else {
            r = 100;
            g = 60;
            b = 60;
        }
    } else {
        r = D_L39_002462A8[kind * 3];
        g = D_L39_002462A8[kind * 3 + 1];
        b = D_L39_002462A8[kind * 3 + 2];
    }
    if (s->type == 0) {
        *(s32 *)(s->model + 0x78) = (b << 16) | (g << 8) | r;
    } else {
        func_L01_0043B9E8(s->model, r, g, b);
    }
}
