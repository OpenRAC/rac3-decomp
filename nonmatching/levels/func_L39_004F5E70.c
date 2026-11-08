/* Ported from rac4-decomp's func_003FE6C0 (a twin of this function's code), names renamed from retail's
   relocations; 8 instruction(s) still differ under this file's flags. */
extern void func_L39_004F5F80(void *);
extern s32 func_00403308(void *, s32, s32);

s32 func_L39_004F5E70(u8 *arg0)
{
    func_L39_004F5F80(arg0);
    return func_00403308(arg0 + 12, 0, 8);
}