/* US draft of func_003D9FB8 (rac3-uya-decomp func_003D9E70, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003D9FB8 */
extern s32 D_001D4BB0[];
extern void func_003DCFA8(s32);
extern void func_003A99D0(void);
void func_003D9FB8(void) {
    func_003DCFA8(D_001D4BB0[0]);
    func_003A99D0();
}
/* localdecomp:end func_003D9FB8 */
