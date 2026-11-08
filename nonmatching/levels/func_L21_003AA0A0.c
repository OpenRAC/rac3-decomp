/* Ported from rac4-decomp's func_L01_003CC6B0 (a twin of this function's code), names renamed from retail's
   relocations; 6 instruction(s) still differ under this file's flags. */
extern u8 D_L21_002C43C0[];

s32 func_L21_003AA0A0(s32 arg0, s32 arg1, u32 *arg2) {
    if (arg1)
        return 0;
    *arg2 = 68;
    return (u32)D_L21_002C43C0;
}