/* Ported from rac4-decomp's func_0045F460 (a twin of this function's code), names renamed from retail's
   relocations; 6 instruction(s) still differ under this file's flags. */
s32 func_0012C220();
s32 func_L39_0059D8F0(s32);

s32 func_L39_0059D940(void) {
    s32 temp_v0;
    temp_v0 = func_0012C220();
    if (temp_v0 < 0) {
        return 0;
    }
    return func_L39_0059D8F0(temp_v0);
}