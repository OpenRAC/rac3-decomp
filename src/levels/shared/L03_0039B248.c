#include "common.h"

/* localdecomp:start func_L03_0039B248 */
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

void func_L03_0039B248(u8 *a) {
    if (a[32] == 0) {
        *(s32 *)(*(u8 **)(a + 104) + 8) = 0;
        func_L01_004450F0(a, 4, -1);
    }
}
/* localdecomp:end func_L03_0039B248 */

/* localdecomp:start func_L03_0039B280 */
#include "vu0.h"
extern u8 D_001A4C60[];
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s16 *D_L03_0021C620[];
extern s32 D_L03_001DF9D8;
extern f32 func_0038CE68(void *, void *);
extern s32 func_00382380(void *, s32, s32);
typedef struct { s32 w0; s32 w4; u8 pad8[4]; u8 bC; } S_39B280;
s32 func_L03_0039B280(u8 *a0) {
    S_39B280 *s = *(S_39B280 **)(a0 + 0x68);
    s16 *p;
    u8 *e;
    s32 w;
    vu0_v4 d;
    w = s->w0;
    if (w == -1) return 0;
    if (s->bC != 0) {
        vec_sub_ba(&d, D_001A4C60, a0 + 0x10);
        if (0.0f < func_0038CE68(D_L03_001DFA80 + (w << 7), &d)) return 1;
    }
    if (func_00382380(D_001A4C60, s->w0, 0) != 0) {
ret1:
        return 1;
    }
    if (s->w4 == -1) return 0;
    p = D_L03_0021C620[s->w4];
    while ((s->w4 & 0xFF) != 0xFF && s->w4 <= D_L03_001DF9D8 && p != 0
           && (p[-1] >= 0 || p == D_L03_0021C620[s->w4])) {
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) return 0;
        if (func_00382380(e + 0x10, s->w0, 0) != 0) goto ret1;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L03_0039B280 */
