/* US draft of func_003BE3F0 (rac3-uya-decomp func_003B8EF8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BE3F0 */
extern s16 D_0016C5A2[];
extern s32 func_0038CAD0(s32 *);
void func_003BDF60(s16, s32, s32, s32);
extern u8 D_001DA2C0_003BE3F0;

s32 func_003BE3F0(void) {
    s32 temp_s0;

    temp_s0 = func_0038CAD0(&D_001DA2C0_003BE3F0) != 0;
    func_003BDF60(D_0016C5A2[0], 0x12C, 0xF, 0xF);
    return temp_s0;
}
/* localdecomp:end func_003BE3F0 */
