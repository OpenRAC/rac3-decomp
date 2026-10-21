/* US draft of func_003AF3A8 (rac3-uya-decomp func_003A9E00, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AF3A8 */
extern void func_003AF068(void *, s32);
void func_003AF3A8(void) {
    s32 i;
    if (D_001D5C78 != 0) {
        for (i = 0; i < 1; i++) {
            func_003AF068((void *)(D_001D5C78 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_003AF3A8 */
