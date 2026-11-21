/* functional: high. Near miss with 2 diffs (alias D_001D5520_00391328 is the unsized lui/lw view of D_001D5520, same address as the gp store at gp-0x7390). Asm re-read: branch-likely store only when v != 0; movz selects 2 vs 3. The extern lines for D_00143950/D_001D5520/func_12A950/func_12BEE8 are in the file already. */
extern s32 D_001D5520_00391328[];
void func_00391328(void) {
    s32 v;
    func_12A950();
    v = D_00143950[0];
    if (v) D_001D5520 = 0;
    if (D_001D5520_00391328[0]) {
        func_12BEE8(0, 0, 0x50, 1);
    } else {
        func_12BEE8(0, 1, v ? 3 : 2, 0);
    }
}
