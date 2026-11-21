/* NEAR MISS: same control flow and operations (verified by reading), only register allocation differs. Retail keeps r,g,b in $a1,$a2,$a3, the table base in $a0 and the object in $t0; this C puts the object in $a2 and r,g,b in $v0,$v1,$a3 (52 words differ, all register names). u8/u32/param variants of r,g,b did not change it. */
#include "common.h"
typedef struct {
    u8 pad0[0x2D0];
    u8 *w2D0;
    u8 pad2D4[0x2FC - 0x2D4];
    s16 h2FC;
} S_0066ACA8;
extern u8 D_L39_002462A8[];
extern void func_L39_005AC528(void *);
void func_L39_0066ACA8(S_0066ACA8 *self, s32 idx) {
    s32 r, g, b;
    if (idx == 0) {
        if (self->h2FC == 0) {
            r = 10; g = 10; b = 250;
        } else {
            r = 60; g = 60; b = 100;
        }
    } else if (idx == 1) {
        if (self->h2FC == idx) {
            r = 120; g = 15; b = 0;
        } else if (self->h2FC == 0) {
            r = 250; g = 10; b = 10;
        } else {
            r = 100; g = 60; b = 60;
        }
    } else {
        r = D_L39_002462A8[idx * 3];
        g = D_L39_002462A8[idx * 3 + 1];
        b = D_L39_002462A8[idx * 3 + 2];
    }
    if ((u16)self->h2FC == 0) {
        *(s32 *)(self->w2D0 + 0x78) = (b << 16) | (g << 8) | r;
    } else {
        func_L39_005AC528(self->w2D0);
    }
}
