/* Ported from rac4-decomp's func_L00_0051EE28 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 Type1;
typedef struct Type2 {
    char _p0[0x18];
    void (*f18)(Type1 *arg0);
} Type2;
struct Type1 {
    Type2 *f0;
};

void func_L39_004FCD30(Type1 *arg0) {
    arg0->f0->f18(arg0);
}
