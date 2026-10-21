/* US draft of func_003B4678 (rac3-uya-decomp func_003B44C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B4678 */
extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C[];
extern s32 D_001DA110[];
extern u8 D_001D8918[];
s32 *func_003B4678(void) {
    if (D_001DA114 == 0) { D_001DA10C[0] = D_001D8918; D_001DA108 = 1; D_001DA114 = 1; D_001DA110[0] = 0; }
    return &D_001DA108;
}
/* localdecomp:end func_003B4678 */
