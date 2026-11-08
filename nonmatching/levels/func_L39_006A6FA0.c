/* Ported from rac4-decomp's func_004EE7B0 (a twin of this function's code), names renamed from retail's
   relocations; 8 instruction(s) still differ under this file's flags. */
extern u8 D_L39_0047DA80[];
extern void func_L39_00688400(u8 *, s32);

void func_L39_006A6FA0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 4) = D_L39_0047DA80;
    func_L39_00688400(object, flags);
}