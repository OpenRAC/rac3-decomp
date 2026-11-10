/* Ported from rac4-decomp's func_004033B0 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
extern s32 func_003FB530(s32);

s32 func_L39_004F7590(s32 value)
{
    return func_003FB530(value == 0 ? 1 : value);
}
