/* US draft of func_003926E8 (rac3-uya-decomp func_0038DEB0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003926E8 */
extern u32 *D_001DA050;
extern u8 D_001D0070[];
void func_003926E8(void) {
    D_001DA050[0] = 0x30000026;
    D_001DA050[1] = (u32)D_001D0070;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000026;
    D_001DA050 += 4;
}
/* localdecomp:end func_003926E8 */
