/* Ported from rac4-decomp's func_L00_0053BEF0 (a twin of this function's code), names renamed from retail's
   relocations; 3 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    char _p10[0x1C - 0x10];
    s32 f1C;
    s32 f20;
} Type1;

s32 func_L39_00684218(Type1 *arg0) {
    arg0->fC = 0;
    arg0->f1C = 0;
    arg0->f20 = 0;
    return -1;
}
