/* Ported from rac4-decomp's func_L00_0071AB38 (a twin of this function's code), names renamed from retail's
   relocations; 3 instruction(s) still differ under this file's flags. */
typedef struct Type3 Type3;
typedef struct Type2 {
    char _p0[0xE8];
    void (*fE8)(Type3 *arg0);
} Type2;
struct Type3 {
    char _p0[0x58];
    Type2 *f58;
};
typedef struct Type1 {
    char _p0[0xB0];
    Type3 *fB0;
} Type1;

void func_L39_00699668(Type1 *arg0) {
    Type3 *o = arg0->fB0;
    o->f58->fE8(o);
}
