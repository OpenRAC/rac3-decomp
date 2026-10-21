/* US draft of func_00389C48 (rac3-uya-decomp func_00385570, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00389C48 */
extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003354A0[];
extern u8 D_00335510[];
extern void func_0038CC88();
extern void func_003A9618();
s32 func_00389C48(s32 a, s32 b) {
    u8 *p;
    s32 h = D_001D4BB0 >> 8;
    if (b == 0x14) {
        func_0038CC88(D_001DA050, D_003354A0, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x100;
    } else {
        func_0038CC88(D_001DA050, D_00335510, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x400;
    }
    p = (u8 *)D_001DA050;
    *(s32 *)(p + 0x64) = a;
    *(s16 *)(p + 0x24) = h;
    D_001DA050 = D_001DA050 + 0x70;
    func_003A9618();
    return h;
}
/* localdecomp:end func_00389C48 */
