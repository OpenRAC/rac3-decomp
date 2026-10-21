/* US draft of func_00389370 (rac3-uya-decomp func_00384C98, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-fno-schedule-insns` `@ps2as` (a single-function override). */


/* localdecomp:start func_00389370 */
extern u32 *D_001DA050_00389370;
extern u32 *D_001D9BF4_00389370;
extern u32 *D_001D9BF8_00389370;
extern void func_003A02E8();
extern s32 func_003A9618_00389370();
void func_00389370(void) {
    D_001D9BF8_00389370 = D_001DA050_00389370;
    D_001DA050_00389370 += 4;
    D_001D9BF4_00389370[0] = 0x20000000;
    D_001D9BF4_00389370[1] = (u32)D_001DA050_00389370;
    D_001D9BF4_00389370[2] = 0;
    D_001D9BF4_00389370[3] = 0;
    func_003A02E8();
    func_003A9618_00389370();
    D_001DA050_00389370[0] = 0x20000000;
    D_001DA050_00389370[1] = (u32)(D_001D9BF4_00389370 + 4);
    D_001DA050_00389370[2] = 0;
    D_001DA050_00389370[3] = 0;
    D_001DA050_00389370 += 4;
    D_001D9BF8_00389370[0] = 0x20000000;
    D_001D9BF8_00389370[1] = (u32)D_001DA050_00389370;
    D_001D9BF8_00389370[2] = 0;
    D_001D9BF8_00389370[3] = 0;
}
/* localdecomp:end func_00389370 */
