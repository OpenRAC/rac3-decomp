/* US draft of func_003A9108 (rac3-uya-decomp func_003A3BB8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A9108 */
extern Struct227600 D_00227580;
extern s32 D_001DA048[];
extern u32 *D_001DA050_g;
extern s32 D_001DA05C_g;
extern void func_003A90A0(void);
void func_003A9108(void) {
    u8 *p = (u8 *)&D_00227580;
    D_001DA048[0] = *(s32 *)(p + 0xC);
    D_001DA048[1] = *(s32 *)(p + 0x10);
    D_001DA050_g = *(u32 **)(p + 0xC);
    D_001DA05C_g = 0;
    func_003A90A0();
}
/* localdecomp:end func_003A9108 */
