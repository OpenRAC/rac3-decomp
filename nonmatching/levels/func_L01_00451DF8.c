/* Ported from rac2-decomp's func_002B0990 (a twin of this function's code), names renamed from retail's
   relocations; 4 instruction(s) still differ under this file's flags. */
extern u8 D_001D5473 __attribute__((section(".sdata")));
extern void func_L01_0044E850(void *a0, void *a1, int a2, float f12, float f13);

void func_L01_00451DF8(void *a0, float *a1, float f12, int a2, int a3)
{
    if (D_001D5473 != 0) {
        a1[28] = f12;
    } else {
        a1[28] = 1.0f;
    }
    if (a3 != 0) {
        if (a1[28] != a1[8]) {
            func_L01_0044E850(a0, a1, a2, 0.03f, 0.3f);
        }
    }
}