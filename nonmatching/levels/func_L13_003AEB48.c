/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "@ps2as added to the file line" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: byte-exact with --as ps2as only: inline lui/ori/mtc1 float constants (0.02f, 0.0004f); L13_003ADA98.c line has no @ps2as (28 diffs without it). Prototype must be void f(void *) (file declares it so). C in near/
 */
#include "common.h"

/* localdecomp:start func_L13_003AEB48 */
extern void func_L13_003AF048(u8 *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 D_L13_001DE678;
__asm__(".extern D_L13_001DE678, 4");
extern f32 D_L13_001DE67C;
__asm__(".extern D_L13_001DE67C, 4");
extern f32 D_L13_001DE680;
__asm__(".extern D_L13_001DE680, 4");

void func_L13_003AEB48(void *arg0) {
    u8 *self = arg0;

    func_L13_003AF048(*(u8 **)(self + 0x68) + 0x150, D_L13_001DE678 * 0.020000001f, D_L13_001DE67C * 0.00040000002f, D_L13_001DE680 * 0.00040000002f);
    if (self[0x43] != 2) {
        func_003C3A10(self, 2, 0, 10);
    }
}
/* localdecomp:end func_L13_003AEB48 */
