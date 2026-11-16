/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: MATCH only with --as ps2as (line 1217 of config/levels/text_parts.txt, src/levels/shared/L13_003ADA98.c, has no @ps2as: retail has the float constants as lui/ori/mtc1 immediates, default gas makes gp-relative lwc1 literals: 28 diff); needs the three .extern ...
 */
#include "common.h"

/* localdecomp:start func_L13_003AEBC8 */
__asm__(".extern D_L13_001DE684, 4");
__asm__(".extern D_L13_001DE688, 4");
__asm__(".extern D_L13_001DE68C, 4");
extern f32 D_L13_001DE684;
extern f32 D_L13_001DE688;
extern f32 D_L13_001DE68C;
extern void func_L13_003AF048(u8 *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L13_003AEBC8(void *arg0) {
    u8 *a0 = arg0;

    func_L13_003AF048(*(u8 **)(a0 + 0x68) + 0x150, D_L13_001DE684 * 0.020000001f, D_L13_001DE688 * 0.00040000002f, D_L13_001DE68C * 0.00040000002f);
    if (a0[0x43] != 3) {
        func_003C3A10(a0, 3, 0, 8);
    }
}
/* localdecomp:end func_L13_003AEBC8 */
