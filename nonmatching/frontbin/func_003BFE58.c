/* US draft of func_003BFE58 (rac3-uya-decomp func_003BA948, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003BFE58 */
extern s32 D_001DA31C[];
extern void func_003CD250(s32);
void func_003BFE58(void) {
    s32 *p = D_001DA31C;
    s32 i;
    for (i = 5; i >= 0; i--, p++) {
        if (*p) { func_003CD250(*p); *p = 0; }
    }
}
/* localdecomp:end func_003BFE58 */
