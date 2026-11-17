#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_004B32E8 */
/* Ps2EeAs only uses $gp for this if it knows it is small before the use. */
__asm__(".extern D_L01_001DAAB0, 4");
extern u8 *D_L01_001DAAB0;
extern void func_0038D2D0(void *a0, f32 a1);
void func_L01_004B32E8(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        func_0038D2D0(D_L01_001DAAB0 + i * 64, 1.0f);
    }
}
/* localdecomp:end func_L01_004B32E8 */

/* localdecomp:start func_L01_004B3338 */
extern u8 *D_L01_001E0ED4;
extern u8 *D_L01_001E0EDC;
extern u8 *D_L01_0023C500[];
extern void func_L01_0040E800(void *, void *, void *);
extern f32 func_L01_0040E468(void *);
extern void func_L01_0040E3F0(void *, void *, f32);

void func_L01_004B3338(s32 idx, s32 flag) {
    u8 *e = D_L01_001E0ED4 + (idx << 5);
    u8 *m = D_L01_001E0EDC + (idx << 6);
    s32 c0 = 0;
    s32 c1 = 0;
    s32 c2 = 0;
    f32 one;
    f32 s;
    if (e[0x1E] & 2) {
        c0 = e[0] & 0x3F;
        c1 = e[4] & 0x3F;
        c2 = e[8] & 0x3F;
    }
    one = 1.0f;
    func_L01_0040E800(e, D_L01_0023C500[e[0x1D]] + 0x50, m);
    s = func_L01_0040E468(m);
    s = fmax_asm(s, func_L01_0040E468(m + 0x10));
    s = fmax_asm(s, func_L01_0040E468(m + 0x20));
    *(f32 *)(e + 0xC) = *(f32 *)(D_L01_0023C500[e[0x1D]] + 0x5C) * s;
    func_L01_0040E3F0(e, e, *(f32 *)(m + 0x3C));
    vec_add_ba(e, e, m + 0x30);
    *(f32 *)(m + 0xC) = one / func_L01_0040E468(m);
    *(f32 *)(m + 0x1C) = one / func_L01_0040E468(m + 0x10);
    *(f32 *)(m + 0x2C) = one / func_L01_0040E468(m + 0x20);
    if (flag != 0) {
        e[0x1E] |= 1;
    }
    if (e[0x1E] & 2) {
        e[0] = c0 | (e[0] & 0xC0);
        e[4] = c1 | (e[4] & 0xC0);
        e[8] = c2 | (e[8] & 0xC0);
    }
}
/* localdecomp:end func_L01_004B3338 */

INCLUDE_ASM("asm/levels", func_L01_004B44CC);
