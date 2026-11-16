/* PAL near miss (Claude wave S2/pal): near miss: 2 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as -mvu0-use-vf0-vf2").
 * Worker's note: 5 diff with the file flags (2 diff with -msplit-addresses added: only `swc1 $f0,0x30($s0)` vs `lui $a0` order); retail interleaves lui $a1 / swc1 / lui $a0 / addiu $a0 / jal / addiu $a1 (split addresses), the file line has -mno-split-addresses. ...
 */
#include "common.h"

extern f32 func_0038DAB8(f32, f32);

/* localdecomp:start func_L01_0037E620 */
extern u8 D_L01_001E1D70[];
extern u8 D_L01_002B3AC0[];
extern void func_L01_0040B858(void *, void *);

void func_L01_0037E620(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    void *b;

    *(f32 *)(s + 0x30) = func_0038DAB8(*(f32 *)(s + 0x30), 0.017453292f);
    b = D_L01_002B3AC0;
    func_L01_0040B858(D_L01_001E1D70, b);
}
/* localdecomp:end func_L01_0037E620 */
