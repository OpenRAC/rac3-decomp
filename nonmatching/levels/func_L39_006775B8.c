/* Ported from rac4-decomp's func_004F4E58 (a twin of this function's code), names renamed from retail's
   relocations; 4 instruction(s) still differ under this file's flags. */
extern s8 D_221F2F_[];
#define D_221F2F (D_221F2F_[0])

void func_L39_006775B8(void) {
    s32 var_v1;
    s8 *var_v0;
    var_v1 = 0xF;
    var_v0 = &D_221F2F;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
