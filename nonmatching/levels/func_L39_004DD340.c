/* Ported from rac4-decomp's func_L00_00519140 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct Type1 {
    char _p0[0x4];
    s32 f4;
} Type1;
extern void func_L39_004E48A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_L39_004DD340(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_L39_004E48A8(arg0->f4, 0x12, arg1, 2, arg2, arg3, 0x12);
}