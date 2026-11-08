/* Ported from rac4-decomp's func_L00_0051CC98 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    s32 f10;
} Type1;
extern s32 func_0011D2EC(s32 arg0, s32 arg1, s32 arg2);

s32 func_L39_004E0E98(Type1 *arg0, Type1 *arg1) {
    s32 d = arg0->fC - arg1->fC;
    if (d != 0) {
        return d;
    }
    return func_0011D2EC(arg0->f10, arg1->f10, arg0->fC);
}