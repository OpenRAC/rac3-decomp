/* Ported from rac2-decomp's func_L04_003C70C8 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */
extern u32 D_L16_001DB03C __attribute__((section(".sdata")));

u32 func_L16_004DCA98(u32 value) {
    u32 old = D_L16_001DB03C;
    D_L16_001DB03C = old + value;
    return old;
}