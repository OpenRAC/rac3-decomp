/* US draft of func_003A9338 (rac3-uya-decomp func_003A3DE8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A9338 */
extern u32 *D_001DA050_003A9338;
void func_003A9338(s32 a0, u32 a1) {
    D_001DA050_003A9338[0] = a1 | 0x30000000;
    D_001DA050_003A9338[1] = a0;
    D_001DA050_003A9338[2] = 0;
    D_001DA050_003A9338[3] = 0;
    D_001DA050_003A9338 += 4;
}
/* localdecomp:end func_003A9338 */
