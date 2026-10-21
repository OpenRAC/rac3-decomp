/* US draft of func_003B4738 (rac3-uya-decomp func_003B4588, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B4738 */
extern s32 D_001DA12C;
extern s32 D_001DA120;
extern u8 *D_001DA124[];
extern u8 D_001D88B8[];
s32 *func_003B4738(void) {
    if (D_001DA12C == 0) { D_001DA124[0] = D_001D88B8; D_001DA120 = 1; D_001DA12C = 1; }
    return &D_001DA120;
}
/* localdecomp:end func_003B4738 */
