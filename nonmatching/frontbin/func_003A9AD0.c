/* US draft of func_003A9AD0 (rac3-uya-decomp func_003A4580, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A9AD0 */
extern s32 D_001DA068;
extern s32 D_001DA06C;
extern void func_11EB50(s32, s32);
extern void func_11F940(s32);
void func_003A9AD0(void) {
    if (*(volatile u32 *)0x1000E010 & 0x20000) {
        *(volatile u32 *)0x1000E010 = 0x20000;
    }
    func_11EB50(1, D_001DA068);
    func_11EB50(15, D_001DA06C);
    func_11F940(1);
    D_001DA068 = 0;
    D_001DA06C = 0;
}
/* localdecomp:end func_003A9AD0 */
