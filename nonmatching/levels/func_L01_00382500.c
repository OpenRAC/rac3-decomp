/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: MATCH only with both added to the line of src/levels/shared/L01_0037EFC8.c (vec_add_ab; the 1.0f/0.9f arguments are lui/mtc1 immediates, GNU as would pool them). func_L01_00382578 is defined LATER in the file as (s32, s32, s32): the block declares that and ...
 */
#include "common.h"

/* localdecomp:start func_L01_00382500 */
#include "vu0.h"
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00382578(s32 a0, s32 a1, s32 alpha);
extern u8 D_001DDCE0_sda[8];
__asm__(".extern D_001DDCE0_sda, 8");
extern s32 D_L01_001E1E94;

void func_L01_00382500(u8 *a0) {
    vu0_v4 v;

    func_0038D000(&v, D_001DDCE0_sda, a0 + 0xC0);
    vec_add_ab(&v, a0 + 0x10, &v);
    ((void (*)(void *, s32, s32, f32, f32, f32, f32))func_L01_00382578)(&v, 0x78, D_L01_001E1E94 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00382500 */
