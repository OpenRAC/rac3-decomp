/* functional: high. Checked against PAL asm; byte-exact under check.py --flags=-mno-split-addresses (a per-function override the file's own flags do not have), so not a legitimate match under the file's flags. */
extern s32 D_001DA12C;
extern s32 D_001DA120;
extern u8 *D_001DA124[];
extern u8 D_001D88B8[];
s32 *func_003B4738(void) {
    if (D_001DA12C == 0) {
        D_001DA124[0] = D_001D88B8;
        D_001DA120 = 1;
        D_001DA12C = 1;
    }
    return &D_001DA120;
}
