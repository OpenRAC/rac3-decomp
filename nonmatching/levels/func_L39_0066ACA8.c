/* Wave 13 (r30, 2026-11-28) replaces the earlier draft of this function (k6 Opus near miss (2026-11-26)). */
/* PAL near miss (wave 13 r30, 2026-11-28): 36 differences (wave10/p10/check.py, level 39), from the k6 draft's 39: the colour written as r | (g << 8) | (b << 16), which gives r retail's a1. Tried without gain: s16 local / inline accessor for the final h2FC test, switch on idx, u8/u32 colour locals, declaration and table-read orders, branch polarities, temporaries for the colour. Left: retail tests the reloaded 0x2FC halfword with sll 16 (the PRE copy's upper bits unknown), here gcse inserts plain loads so combine drops the shift; g/b in v0/v1 (retail a2/a3), the object in a2 (retail t0), the tail's shift order. */
#include "common.h"

/* localdecomp:start func_L39_0066ACA8 */
typedef struct { u8 r, g, b; } RGB_0066ACA8;
typedef struct {
    u8 pad0[0x2D0];
    u8 *w2D0;
    u8 pad2D4[0x2FC - 0x2D4];
    s16 h2FC;
} S_0066ACA8;
extern RGB_0066ACA8 D_L39_002462A8[1];
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
        r = D_L39_002462A8[idx].r;
        g = D_L39_002462A8[idx].g;
        b = D_L39_002462A8[idx].b;
    }
    if (self->h2FC == 0) {
        *(s32 *)(self->w2D0 + 0x78) = r | (g << 8) | (b << 16);
    } else {
        func_L39_005AC528(self->w2D0);
    }
}
/* localdecomp:end func_L39_0066ACA8 */
