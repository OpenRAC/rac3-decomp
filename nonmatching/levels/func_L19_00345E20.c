/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: MATCH only with both added to the line of src/levels/shared/L19_00345E20.c (vec_add_ba + vec_add_ab; float constant 0.006f is lui/ori/mtc1, with only the vu0 flag 42 diff, with only @ps2as the vu0.h helpers do not compile). D_001DD2A8_sda f32 with .extern 4, ...
 */
#include "common.h"

/* localdecomp:start func_L19_00345E20 */
#include "vu0.h"
extern f32 D_001DD2A8_sda;
__asm__(".extern D_001DD2A8_sda, 4");
extern f32 func_0038DAB8(f32, f32);
extern void func_003C2880(void *);

void func_L19_00345E20(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * D_001DD2A8_sda;
    *(f32 *)(s + 8) = *(f32 *)(s + 8) - 0.006f;
    vec_add_ba(a0 + 0x10, a0 + 0x10, s);
    vec_add_ab(a0 + 0xF0, a0 + 0xF0, s + 0x10);
    *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), *(f32 *)(s + 0x10));
    *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), *(f32 *)(s + 0x14));
    *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), *(f32 *)(s + 0x18));
    a0[0xBC]--;
    if (a0[0xBC] == 0) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L19_00345E20 */
