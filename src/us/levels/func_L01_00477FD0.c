#include "common.h"

/* NTSC-U counterpart of func_L01_0047B820 (src/levels/shared/L01_0047B798.c): 0.06 -> 0.05; 0.94 -> 0.95 */
/* localdecomp:start func_L01_00477FD0 */
__asm__(".extern D_L01_001D80E4_00477FD0, 4");
extern f32 D_L01_001D80E4_00477FD0;
extern char D_L01_001E0580[] __attribute__((section(".sdata")));
extern char D_L01_001D80E8_00477FD0[];
extern char D_L01_001D80F0_00477FD0[];
extern char D_L01_001D80F8_00477FD0[];
extern s32 func_0011B2E8(char *, char *, ...);

void func_L01_00477FD0(s32 a, s32 b) {
    if (b == 0) {
        if (a == 0) {
            func_0011B2E8(D_L01_001E0580, D_L01_001D80E8_00477FD0);
        } else {
            func_0011B2E8(D_L01_001E0580, D_L01_001D80F0_00477FD0, a);
        }
        D_L01_001D80E4_00477FD0 = 0.0f;
        return;
    }
    if ((f32)a < (f32)b * 0.15f) {
        D_L01_001D80E4_00477FD0 = D_L01_001D80E4_00477FD0 + 0.0500000007f;
        if (2.0f <= D_L01_001D80E4_00477FD0) {
            D_L01_001D80E4_00477FD0 = D_L01_001D80E4_00477FD0 - 2.0f;
        }
    } else {
        if (1.0f < D_L01_001D80E4_00477FD0) {
            D_L01_001D80E4_00477FD0 = 2.0f - D_L01_001D80E4_00477FD0;
        }
        D_L01_001D80E4_00477FD0 = D_L01_001D80E4_00477FD0 * 0.949999988f;
    }
    func_0011B2E8(D_L01_001E0580, D_L01_001D80F8_00477FD0, a, b);
}
/* localdecomp:end func_L01_00477FD0 */
