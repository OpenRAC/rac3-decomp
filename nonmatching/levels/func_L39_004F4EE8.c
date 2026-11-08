/* Ported from rac2-decomp's func_L00_004338A8 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
extern void func_L39_004F73F0(char *p);

char *func_L39_004F4EE8(char *object)
{
    func_L39_004F73F0(object + 8);
    return object;
}