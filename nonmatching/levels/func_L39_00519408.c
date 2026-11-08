/* Ported from rac4-decomp's func_L00_00566D00 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};
s32 func_L39_00518A38(s32);

void func_L39_00519408(s32 *arg0, Type1 *arg1) {
    *arg0 = func_L39_00518A38(arg1->f4);
}