/* Ported from rac2-decomp's func_00284E80 (a twin of this function's code), names renamed from retail's
   relocations; 8 instruction(s) still differ under this file's flags. */
extern int D_00240408 __attribute__((section(".sdata")));

int func_L39_00597E48(void)
{
    extern int func_001399B0(void *);
    return func_001399B0((void *)D_00240408);
}