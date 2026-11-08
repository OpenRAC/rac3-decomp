/* Ported from rac4-decomp's func_L00_007634B0 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0x260];
    u8 f260[20];
} Type1;

void func_L39_0069F618(Type1 *arg0, u8 *arg1) {
    s32 i;
    for (i = 0; i < 8; i++) {
        arg1[i] = arg0->f260[i];
    }
}
