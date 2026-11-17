/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: MATCH with the file line (-O2 -G8 -fopt-stack -mno-check-zero-division) + -mvu0-use-vf0-vf2, default assembler (no @ps2as needed); without the flag vf17 spilled. Prototype (s32, void *) is the file's own extern (line 151). C in near/func_L01_00385188.xhigh.c
 */
#include "common.h"
#include "vu0.h"

extern void func_0038D000(void *, void *, void *);

/* localdecomp:start func_L01_00385188 */
extern f32 D_001DDD88_sda;
__asm__(".extern D_001DDD88_sda, 4");

void func_L01_00385188(s32 a0, void *a1) {
    vu0_v4 r;
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = D_001DDD88_sda;
    v.w = 1.0f;
    *(vu0_q *)&r = *(vu0_q *)&v;
    func_0038D000(&r, &r, (u8 *)a0 + 0xC0);
    vec_add_ba(a1, &r, (u8 *)a0 + 0x10);
}
/* localdecomp:end func_L01_00385188 */
