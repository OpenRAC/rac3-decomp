/* Ported from rac4-decomp's func_L00_00717A38 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0x140];
    u8 f140[32];
} Type1;

void func_L39_00685AB0(Type1 *arg0, u8 arg1) {
    arg0->f140[arg1 >> 3] &= ~(1 << (arg1 & 7));
}
