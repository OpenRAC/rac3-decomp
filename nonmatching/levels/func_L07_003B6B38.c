/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as + -mvu0-use-vf0-vf2" (its file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: MATCH only with -mvu0-use-vf0-vf2 added (the file L07_003AF398.c line lacks it; vu0.h vec_sub_ab/vec_add_ba do not compile without it: vf17 spill); C kept in near/func_L07_003B6B38.xhigh.c (check with --flags=-mvu0-use-vf0-vf2); same flag gap as ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003B6B38 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003B64D0(u8 *, s32);

void func_L07_003B6B38(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    vec_sub_ab(s + 0x2F0, a0 + 0x10, *(u8 **)(s + 0x190) + 0x10);
    *(s32 *)(s + 0x2F8) = 0;
    func_0038CF68(s + 0x2F0, s + 0x2F0, 20.0f);
    vec_add_ba(s + 0x2F0, *(u8 **)(s + 0x190) + 0x10, s + 0x2F0);
    s[0x324] = 1;
    *(u16 *)(a0 + 0x34) |= 0x5000;
    s[0x322] = 0xB;
    s[0x323] = 1;
    func_L07_003B64D0(a0, 0x13);
    a0[0xBC] = 0;
}
/* localdecomp:end func_L07_003B6B38 */
