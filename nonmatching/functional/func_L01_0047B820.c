/* functional: high. PAL port of the NTSC-U draft rewritten from the PAL asm (PAL constants 0.06f and 0.94f, buffer D_L01_001E0500, strings D_L01_001D80E8/F0/F8, gp float D_L01_001D80E4); level data above 0x1D5680 is named D_L01_ (it moves per level: 1D80E4 in L01 is 1D7FA4 in L02); only a one-instruction ordering difference in the first branch (59 positional diffs are a shift). */
#include "common.h"
extern char D_L01_001E0500[];
extern char D_L01_001D80E8[];
extern char D_L01_001D80F0[];
extern char D_L01_001D80F8[];
extern f32 D_L01_001D80E4;
__asm__(".extern D_L01_001D80E4, 4");
extern s32 func_0011B2E8(char *, const char *, ...);

void func_L01_0047B820(s32 a, s32 b) {
    if (b == 0) {
        if (a == 0) {
            func_0011B2E8(D_L01_001E0500, D_L01_001D80E8);
        } else {
            func_0011B2E8(D_L01_001E0500, D_L01_001D80F0, a);
        }
        D_L01_001D80E4 = 0.0f;
        return;
    }
    if ((f32)a < (f32)b * 0.15f) {
        D_L01_001D80E4 = D_L01_001D80E4 + 0.060000002f;
        if (2.0f <= D_L01_001D80E4) {
            D_L01_001D80E4 = D_L01_001D80E4 - 2.0f;
        }
    } else {
        if (1.0f < D_L01_001D80E4) {
            D_L01_001D80E4 = 2.0f - D_L01_001D80E4;
        }
        D_L01_001D80E4 = D_L01_001D80E4 * 0.94f;
    }
    func_0011B2E8(D_L01_001E0500, D_L01_001D80F8, a);
}
