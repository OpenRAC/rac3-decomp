/* Ported from rac4-decomp's func_L00_00520F08 (a twin of this function's code), names renamed from retail's
   relocations; 8 instruction(s) still differ under this file's flags. */
s32 func_L39_004BEED8(s32);
s32 func_L39_004BEF28(s32);
s32 func_L39_004E4C68(s32);

s32 func_L39_004E5108(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    temp_v0 = func_L39_004BEED8(0xC);
    var_v0 = 0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_L39_004E4C68(temp_v0);
        var_v0 = temp_v0_2;
        if (temp_v0_2 == 0) {
            func_L39_004BEF28(temp_v0);
            var_v0 = temp_v0_2;
        }
    }
    return var_v0;
}