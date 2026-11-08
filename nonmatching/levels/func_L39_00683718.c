/* Ported from rac4-decomp's func_L00_004F7328 (a twin of this function's code), names renamed from retail's
   relocations; 4 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    char _p10[0x14 - 0x10];
    s32 f14;
    char _p18[0x1C - 0x18];
    s32 f1C;
    s32 f20;
} Type1;

s32 func_L39_00683718(Type1 *arg0) {
    arg0->fC = 0;
    arg0->f1C = 0;
    arg0->f20 = 0;
    arg0->f14 = 0;
    return -1;
}
