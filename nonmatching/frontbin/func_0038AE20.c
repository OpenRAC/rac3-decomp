/* US draft of func_0038AE20 (rac3-uya-decomp func_003866E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038AE20 */
extern u32 *D_001DA050_0038AE20;
extern u8 D_00141850[];
void func_0038AE20(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_003A9440(0x4E, ((D_001A1ED0[2] >> 13) | 0x31000000) | (0x8000UL << 17));
    func_003A9440(1, (long)a0 | ((long)a1 << 8) | ((long)a2 << 16) | ((long)a3 << 24));
    D_001DA050_0038AE20[0] = 0x30000014;
    D_001DA050_0038AE20[1] = (u32)D_00141850;
    D_001DA050_0038AE20[2] = 0;
    D_001DA050_0038AE20[3] = 0x50000014;
    D_001DA050_0038AE20 += 4;
    func_003A9440(0x4E, 0x31000000 | (D_001A1ED0[2] >> 13));
}
/* localdecomp:end func_0038AE20 */
