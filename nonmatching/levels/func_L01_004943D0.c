/* Ported from rac4-decomp's func_L00_0062A688 (a twin of this function's code), names renamed from retail's
   relocations; 4 instruction(s) still differ under this file's flags. */


s32 func_L01_004943D0(void *object)
{
    s32 value = *(s32 *)((u8 *)object + 0x10);
    if (value == 0) {
        return *(s32 *)((u8 *)object + 0x0C);
    }
    return value;
}
