/* NTSC-U draft (Claude wave K): C of func_L01_00477FD0, the NTSC-U twin of func_L01_0047B820, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 70 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L01_00477FD0", whose code is not the PAL one).
 * Worker's note: 70 raw diff lines, 14 aligned insns differ of 74 (yours 72), draft near/func_L01_00477FD0.medium.c. FLAGS: the entry's flags lack @ps2as (float literals 0.15f / 0.05f / 2.0f / 1.0f / 0.95f are lui/ori/mtc1 in retail), so the best status is flags. Decoded: ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0047B820 (src/levels/shared/...) */
/* localdecomp:start func_L01_00477FD0 */
extern char D_L01_001E0580[];
extern char D_L01_001D80E8[];
extern char D_L01_001D80F0[];
extern char D_L01_001D80F8[];
extern f32 D_001D80E4_sda;
__asm__(".extern D_001D80E4_sda, 4");
extern s32 func_0011B2E8(char *, const char *, ...);

void func_L01_00477FD0(s32 a, s32 b) {
    if (b == 0) {
        if (a == 0) {
            func_0011B2E8(D_L01_001E0580, D_L01_001D80E8);
        } else {
            func_0011B2E8(D_L01_001E0580, D_L01_001D80F0, a);
        }
        D_001D80E4_sda = 0.0f;
        return;
    }
    if ((f32)a < (f32)b * 0.15f) {
        D_001D80E4_sda = D_001D80E4_sda + 0.05f;
        if (2.0f <= D_001D80E4_sda) {
            D_001D80E4_sda = D_001D80E4_sda - 2.0f;
        }
    } else {
        if (1.0f < D_001D80E4_sda) {
            D_001D80E4_sda = 2.0f - D_001D80E4_sda;
        }
        D_001D80E4_sda = D_001D80E4_sda * 0.95f;
    }
    func_0011B2E8(D_L01_001E0580, D_L01_001D80F8, a);
}
/* localdecomp:end func_L01_00477FD0 */
