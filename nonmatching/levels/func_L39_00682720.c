/* Ported from rac4-decomp's func_L00_007131A8 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
typedef struct Type1 Type1;
typedef struct Type2 {
    char _p0[0x12C];
    void (*f12C)(Type1 *arg0, s32 arg1, s32 arg2);
} Type2;
struct Type1 {
    char _p0[0x58];
    Type2 *f58;
};

void func_L39_00682720(Type1 *arg0) {
    arg0->f58->f12C(arg0, 0, 0);
}
