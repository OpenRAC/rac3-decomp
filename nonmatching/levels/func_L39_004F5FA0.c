/* Ported from rac4-decomp's func_003FE7F0 (a twin of this function's code), names renamed from retail's
   relocations; 4 instruction(s) still differ under this file's flags. */
extern void func_L39_004F5FC8(void *);
extern s32 func_00403440(s32);

s32 func_L39_004F5FA0(u8 *arg0)
{
    func_L39_004F5FC8(arg0);
    return func_00403440(*(s32 *)(arg0 + 8));
}