/* US draft of func_00392260 (rac3-uya-decomp func_0038DA28, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00392260 */
extern unsigned long D_001D07E8[];
void func_00392260(s32 arg0, long arg1, long arg2) {
    D_001D07E8[0] = arg0 | (arg1 << 8) | (arg2 << 0x10) | (unsigned long)0x80000000;
}
/* localdecomp:end func_00392260 */
