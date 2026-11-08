/* Ported from rac2-decomp's func_002A90C8 (a twin of this function's code), names renamed from retail's
   relocations; 8 instruction(s) still differ under this file's flags. */
extern s32 func_L01_00446A70(s32 a, s32 b, s32 c, s32 d, s32 e, float duration);
extern s8 D_001A8BD0[];

s32 func_L01_00446BC8(s32 a, s32 b, s32 c, s32 d, float duration) {
    return func_L01_00446A70(a, b, c, d, (s32)D_001A8BD0, duration);
}