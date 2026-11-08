/* Ported from rac4-decomp's func_L00_0051ED40 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 Type1;
typedef struct Type2 {
    char _p0[0x8];
    void (*f8)(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3);
} Type2;
struct Type1 {
    Type2 *f0;
};

void func_L39_004E2F40(Type1 *arg0, s32 arg1) {
    arg0->f0->f8(arg0, 5, 0, arg1);
}
