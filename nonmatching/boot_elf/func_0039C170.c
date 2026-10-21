/* US draft of func_0039C170 (rac3-uya-decomp func_0039C058, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_0039C170 */
extern void func_0039C0E8();
extern s32 D_001D4CEC_g;
void func_0039C170(void *a, s32 b, void *c) {
    func_0039C0E8(a, b, c);
    D_001D4CEC_g |= 0x4000;
}
/* localdecomp:end func_0039C170 */
