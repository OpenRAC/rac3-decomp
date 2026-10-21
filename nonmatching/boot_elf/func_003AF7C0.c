/* US draft of func_003AF7C0 (rac3-uya-decomp func_003AF620, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-fopt-stack` `@ps2as` (a single-function override). */


/* localdecomp:start func_003AF7C0 */
extern void func_003AC590();
__asm__(".extern D_001D5C78, 16");
void func_003AF7C0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, u8 a9) {
    if (D_001D5C78 != 0) {
        func_003AC590(D_001D5C78 + 0x1FCA8, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
}
/* localdecomp:end func_003AF7C0 */
