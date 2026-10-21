/* US draft of func_003AF628 (rac3-uya-decomp func_003AA080, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AF628 */
extern s32 D_001D5C78;
extern s32 D_001D52F0;
void func_003AF628(void) {
    if (D_001D5C78 != 0) {
        func_003AF090(D_001D5C78 + 0x1FCA8, D_001D52F0);
    }
}
/* localdecomp:end func_003AF628 */
