/* US draft of func_003A9050 (rac3-uya-decomp func_003A3B00, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A9050 */
extern u32 D_001D545C;
extern u32 D_00334CB0[];
extern s32 D_001DA058;
extern s32 D_001D5BA4;
extern void func_003A90A0(void);

void func_003A9050(void) {
    u32 index = D_001D545C;

    if (index >= 0x25) {
        index = 0;
    }
    D_001D5BA4 = 0x1E000;
    D_001DA058 = D_00334CB0[index];
    func_003A90A0();
}
/* localdecomp:end func_003A9050 */
