/* Ported from rac4-decomp's func_L00_00749408 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */


void func_L39_006CAA98(u8 *owner, const u32 *input, s32 count)
{
    s32 index;
    if (count > 256)
        count = 256;
    *(s32 *)(owner + 0x6b0) = 0;
    *(s32 *)(owner + 0x660) = count;
    *(s32 *)(owner + 0x6ac) = 0;
    for (index = 0; index < *(s32 *)(owner + 0x660); index++) {
        *(u32 *)(owner + 0x2a8 + index * 4) = *input++;
    }
}
