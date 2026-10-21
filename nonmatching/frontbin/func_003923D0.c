/* US draft of func_003923D0 (rac3-uya-decomp func_0038DB98, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003923D0 */
extern u32 *D_001DA050;
extern s32 D_001D4CF8_003923D0;
void func_003923D0(void) {
    D_001DA050[0] = 0x30000009;
    D_001DA050[1] = (D_001D4CF8_003923D0 + 0xC0) & 0xFFFFFFF;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000009;
    D_001DA050 += 4;
}
/* localdecomp:end func_003923D0 */
