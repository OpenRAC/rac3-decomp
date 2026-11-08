/* Ported from rac4-decomp's func_00436970 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
extern s32 D_3284A0[];

void func_L39_00554D98(s32 arg0, s32 arg1) {
    s32 *var_a1;
    s32 i;
    var_a1 = &D_3284A0[arg1 * 4];
    for (i = 0; i < 4; i++) {
        if (*var_a1 == 0) {
            *var_a1 = arg0;
            return;
        }
        var_a1 += 1;
    }
}
