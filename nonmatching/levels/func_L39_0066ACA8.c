/* PAL near miss (k6 Opus, 2026-11-26): 39 differences (tools/check.py, level 39), from 52: the colour table as a 3-byte RGB struct array declared with a small size, so each byte gets its own la as in retail. Left: register allocation (retail r/g/b in a1/a2/a3, the object in t0, the 0x2FC halfword loaded with lhu in each branch and tested with sll 16). */
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
    if ((u16)self->h2FC == 0) {
        *(s32 *)(self->w2D0 + 0x78) = (b << 16) | (g << 8) | r;
    } else {
        func_L39_005AC528(self->w2D0);
    }
}
/* localdecomp:end func_L39_0066ACA8 */
