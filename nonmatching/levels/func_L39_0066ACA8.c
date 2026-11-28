/* func_L39_0066ACA8 (Claude wave 13 second pass r41, 2026-11-28). Replaces the earlier draft of this function (Claude wave 13 r30 near miss (2026-11-28); replaces the draft from k6 Opus near miss (2026-11-26)). */
/* PAL near miss (wave 13 opus r41, 2026-11-28): 31 differences (build/codex/wave10/p10/check.py, level 39), from
 * the wr30 near's 36. Changed against it: r is a 64-bit unsigned long and arm 0's else assigns g before r (both
 * found by a 600 s permuter run, rewritten here); with them global allocation gives the final-test halfword
 * retail's $v1 and b retail's $a3. This is a study aid: a 64-bit red channel is not plausible original code
 * (it also adds a dsll32/dsra32 pair before the pack). Left: r/g in a0/a1 (retail a1/a2), the object in a2
 * (retail t0), retail's sll-16 test of the reloaded 0x2FC halfword (here bnez on the lhu value), the pack order
 * (retail b << 16 first, in the bnez delay slot). s32 colour locals with (b << 16) | (g << 8) | r give 39, the g/r
 * swap alone 37, a s16 idx parameter 62; cc1 -dg: allocation order idx, self, b, g, halfword, r. */
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
    unsigned long r;
    s32 g, b;
    if (idx == 0) {
        if (self->h2FC == 0) {
            r = 10; g = 10; b = 250;
        } else {
            g = 60; r = 60; b = 100;
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
