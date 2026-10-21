/* US draft of func_003C3860 (rac3-uya-decomp func_003BE340, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C3860 */
extern void func_003C3638();
extern void func_003C36C0();
extern void func_003C3800();
s32 func_003CB3E0_003C3860(s32, s32, s32, s32);      /* extern */
extern s32 D_001DA498;
extern s32 D_001DA49C;
extern s32 D_001DA4D4;

void func_003C3860(void) {
    s32 var_a3;

    func_003C36C0();
    func_003C3638();
    var_a3 = 1;
    if (D_001DA4D4 != 0) {
        D_001DA4D4 = 0;
        var_a3 = 3;
    }
    D_001DA498 = func_003CB3E0_003C3860(D_001DA49C, D_001DA498, -1, var_a3);
    func_003C3800();
}
/* localdecomp:end func_003C3860 */
