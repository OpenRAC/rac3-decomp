/* Resolved in the third retry on 2026-11-15: integrated in L07_003A80A0.c.
   Full PAL level build MATCH; 2 differences resolved with an unsized
   section(".sdata") declaration for D_L07_001D66B0 (as in the sibling
   func_L07_003BA098), file flags unchanged. Retained as historical evidence. */
/* Retry 2026-11-15: baseline remains 2 differences with the owning file flags. Typed pvars fields and aligned aggregate copies emitted the same bytes; the shared Vec4f is only 4-aligned and regressed to unaligned copies. Stopped after three distinct correct-size wordings gave identical residuals. Future retry needs a same-flag sibling or scheduler evidence, not another argument cast or layout rewrite. */
/* near miss (level 7, Annihilation Nation): 2 differences: retail sets the call's 0 argument (move $a1,$zero) before lw $a3,0x68($t0); store order found, tried casts of the callee and locals for the arguments (8 wordings) */
#include "common.h"

/* localdecomp:start func_L07_003A8D70 */
extern u8 D_L07_001D66B0[];
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003A8D70(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    *(u128_t *)(arg0 + 0x10) = *(u128_t *)(p + 0xD0);
    *(u128_t *)(p + 0xD0) = *(u128_t *)D_L07_001D66B0;
    *(s32 *)(p + 0xC0) = 0;
    *(s16 *)(p + 0xC4) = 0;
    *(s16 *)(p + 0xC6) = 0;
    *(s32 *)(p + 0xC8) = 0;
    func_L01_004450F0(arg0, 0, -1);
}
/* localdecomp:end func_L07_003A8D70 */
