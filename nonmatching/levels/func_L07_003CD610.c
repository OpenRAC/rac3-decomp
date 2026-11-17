/* PAL level 7 near miss, newly reconstructed 2026-11-16: 17 -> 15 raw
   positional differences with owning default-assembler flags. An incomplete
   table .sdata declaration fixes two entry words; only the 0.15f literal-pool
   expansion remains, shortening the body by eight bytes. Diagnostic Ps2EeAs
   is MATCH, not an accepted owning-file setting. No divs_nops row required.
   Recheck: UYA_TOOLCHAIN=~/sn UYA_RUNNER=~/bin/wibo venv/bin/python
   tools/check.py nonmatching/levels/func_L07_003CD610.c func_L07_003CD610
   --target level_07. Flags: -O2 -G8 -fopt-stack -mno-check-zero-division.
   S_003CD938 comes from the owning file's prelude. Existing documentation
   proposes a true eight-byte extern hint for CD9F8 as a possible file-wide
   Ps2EeAs route; that whole-file proof remains future work for this draft.
   Stop after three compiles when diagnostic identified the sole literal
   blocker. No source-level literal/asm workaround proposed. Not linked. */
#include "common.h"
#include "structs/moby.h"
typedef int TI_003CD610 __attribute__((mode(TI)));
extern S_003CD938 D_L07_001DE6F4[] __attribute__((section(".sdata")));
extern void func_L07_003BB2A8(f32 *, f32 *, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);
extern void func_L07_003CEA60(void *);

void func_L07_003CD610(struct Moby *m) {
    TI_003CD610 vectors[2];
    u8 *p = m->pvar;
    f32 angle;
    func_L07_003BB2A8((f32 *)vectors, (f32 *)(p + 0x130), *(f32 *)(p + 0x410), D_L07_001DE6F4[p[0x404]].f0 - 0.5f);
    angle = func_0038DB00(*(f32 *)(p + 0x414), *(f32 *)(p + 0x410)) * 0.15f;
    vectors[1] = *(TI_003CD610 *)&m->position;
    func_L01_0045A7A8(m, (f32 *)vectors, angle);
    func_L07_003CEA60(m);
}
