/* Ported from rac2-decomp's func_002A0180 (a twin of this function's code), names renamed from retail's
   relocations; 7 instruction(s) still differ under this file's flags. */
extern void func_001264E0(int);
extern char D_L39_0047FB60[];
extern void *D_L39_0024BB70 __attribute__((section(".sdata")));
extern int D_001E0468 __attribute__((section(".sdata")));
extern void func_003CB300(void *, int);
extern void func_0038CD28(void *, void *, int);
extern void func_L39_005ABE58(void);

void func_L39_005ABE58(void)
{
    func_001264E0(0);
    func_0038CD28((void *)0x70003800, D_L39_0047FB60, 0x800);
    func_003CB300(D_L39_0024BB70, D_001E0468);
}