/* Ported from rac4-decomp's func_L00_0071B768 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
typedef struct Type3 {
    char _p0[0x4];
    s32 f4;
} Type3;
typedef struct Type1 {
    char _p0[0xAC];
    s32 fAC;
    Type3 *fB0[1];
    char _pB4[0x230 - 0xB4];
    s32 f230;
} Type1;

s32 func_L39_0068B178(Type1 *arg0) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < arg0->fAC; i++) {
        if (arg0->fB0[i]->f4 >= 3) {
            r = i;
            break;
        }
    }
    return r;
}
