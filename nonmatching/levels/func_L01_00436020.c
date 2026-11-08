/* Ported from rac2-decomp's func_0029B658 (a twin of this function's code), names renamed from retail's
   relocations; 6 instruction(s) still differ under this file's flags. */
extern void func_003AC638(char *, unsigned int, unsigned int, float, float, float, float);
extern s32 D_L01_001D67C8 __attribute__((section(".data")));


void func_L01_00436020(s32 arg0, s32 arg1, float top, float bottom, float left, float right) {
    s32 a;
    s32 b;
    a = arg0;
    b = arg1;
    if (D_L01_001D67C8 != 0) {
        func_003AC638((char *)(D_L01_001D67C8 + 0x36F28), a, b, top, bottom, left, right);
    }
}