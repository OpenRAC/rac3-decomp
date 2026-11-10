/* Ported from rac4-decomp's func_L00_004FFF68 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type2 {
    char _p0[0x10];
    s32 f10;
} Type2;
typedef struct Type1 {
    char _p0[0x60];
    s32 f60;
    char _p64[0xDC - 0x64];
    Type2 *fDC;
} Type1;

s32 func_L39_004C4168(Type1 *arg0) {
    if (arg0 != 0 && arg0->f60 != 0) {
        return arg0->f60;
    }
    if (arg0->fDC == 0) {
        return 0;
    }
    return arg0->fDC->f10;
}
