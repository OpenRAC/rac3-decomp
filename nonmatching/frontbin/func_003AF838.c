/* Near miss of func_003AF838 with its file's own flags: tools/check.py reports 2 diff
   (the US draft it started from: 14).
   What differs: D_001D5C78 now matches (lui/lw via the unsized alias D_001D5C78_0037D1A8,
   which is declared that way in src/frontbin/381140.c); still 2 diffs, both on the second
   global: ours `lw $v0, %lo(D_0031D050)($v0)` / `bnez $v0` vs retail `lw $v1,
   %lo(D_0031D050)($v0)` / `bnez $v1` — i.e. retail loads into a register different from the
   lui base, ours folds the load into the base register. With the file's `-mno-split-addresses`
   every symbol or constant load is emitted by gcc as `lw $r, sym` and expanded by the
   assembler reusing the destination register, so base==dest; the retail's distinct
   base/dest...
*/

/* func_003AF838: retail reads D_001D5C78 through lui/lo, so it needs an
   unsized (never small data) declaration.  D_001D5C78_0037D1A8 is the same
   address declared that way in another file (src/frontbin/381140.c). */

extern s32 D_001D5C78_0037D1A8[];
extern s32 D_0031D050[];
extern void func_00396568();
extern void func_003AF498();

void func_003AF838(void) {
    if (D_001D5C78_0037D1A8[0] != 0 && D_0031D050[0] == 0) {
        func_00396568(1);
        func_003AF498();
    }
}
