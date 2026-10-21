/* US draft of func_003A8A58 (rac3-uya-decomp func_003A3508, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A8A58 */
extern s32 D_001D4D40;
extern void *D_001DA044_003A8A58;
extern u8 D_001A30B0[];
extern void (*D_001D5BD4)(s32);
extern s32 D_00227460[];
extern s32 D_001D5B90;
extern s32 D_001D5BD8;
extern void func_0038A238(s32);
extern void func_003A1930(void *, s32, s32);
extern void func_003A1D00(void);
extern void func_003A9108(void);
void func_003A8A58(void) {
    if (D_001D4D40 == 0) { D_001D4D40 = 1; }
    func_0038A238(4);
    func_003A1930(D_001DA044_003A8A58, 1, 0x400);
    func_003A1D00();
    D_001A30B0[0x43] |= 0x10;
    func_003A9108();
    if (D_001D5BD4 != 0 && D_00227460[0] == 0 && D_001D5B90 != 2 && D_001D5B90 != 1) {
        D_001D5BD4(D_001D5BD8);
        D_001D5BD4 = 0;
        D_001D5BD8 = 0;
    }
}
/* localdecomp:end func_003A8A58 */
