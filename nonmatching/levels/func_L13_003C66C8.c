/* NTSC-U draft (Claude wave C2): C of func_L13_003C4500, the NTSC-U twin of func_L13_003C66C8, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003C4500", whose code is not the PAL one).
 * Worker's note: flags: needs @ps2as (inline li.s 0.0583333 in f20) that its PAL file L13_003C66C8.c lacks; with @ps2as 9 words differ (retail sets f20 before the first jal func_0037E208 and orders its arg setup a0 then a1; mine puts the f20 constant after the call); locals ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L13_003C66C8 (src/levels/shared/L13_003C66C8.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L13_003C4500 */
extern u128_t D_L13_001DEC00[];
extern u8 D_L13_001D66E0[];
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, void *, s32, s32, f32, f32, f32, f32, f32, s32);

void func_L13_003C4500(u8 *a0) {
    f32 v0[4] __attribute__((aligned(16)));
    u128_t p[2];
    u16 t;
    f32 f;

    t = *(u16 *)(a0 + 0x96);
    if (t == 0) {
        f = 0.058333337f;
        p[0] = D_L13_001DEC00[0];
        p[1] = D_L13_001DEC00[1];
        *(u16 *)(a0 + 0x96) = func_0037E208(30, 90);
        func_003886E8(v0, D_L13_001D66E0, f);
        func_L02_003E0520(a0, &p[func_0037E1D8(2)], v0, 10, 0, 3.0f, f, 1.0f, 10.0f, 1.0f, 0);
    } else {
        *(u16 *)(a0 + 0x96) = t - 1;
    }
}
/* localdecomp:end func_L13_003C4500 */
