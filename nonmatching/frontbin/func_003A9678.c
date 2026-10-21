/* US draft of func_003A9678 (rac3-uya-decomp func_003A4128, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A9678 */
extern u32 *D_001DA050_g;
extern u8 D_001D7300[];
void func_003A9678(void) {
    D_001DA050_g[0] = 0x30000003;
    D_001DA050_g[1] = (u32)D_001D7300;
    D_001DA050_g[2] = 0;
    D_001DA050_g[3] = 0x50000003;
    D_001DA050_g += 4;
}
/* localdecomp:end func_003A9678 */
