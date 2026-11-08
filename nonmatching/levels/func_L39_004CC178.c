/* Ported from rac4-decomp's func_L00_00507F78 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0x8];
    s32 f8;
    char _pC[0x10 - 0xC];
    s32 f10;
} Type1;

void func_L39_004CC178(Type1 *arg0, s32 arg1) {
    if (arg0->f10 != arg1) {
        arg0->f8 = 0;
    }
    arg0->f10 = arg1;
}
