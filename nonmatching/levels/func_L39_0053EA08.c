/* Ported from rac2-decomp's func_L16_003E70E0 (a twin of this function's code), names renamed from retail's
   relocations; 4 instruction(s) still differ under this file's flags. */
extern int D_001DF728 __attribute__((section(".sdata")));
extern int D_001DF72C __attribute__((section(".sdata")));
extern int D_001DF730 __attribute__((section(".sdata")));
extern int D_001DF734 __attribute__((section(".sdata")));
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_L39_0053EB68(u8 *, int, f32, int, int, f32, f32, int, u8 *);

void func_L39_0053EA08(u8 *a0) {
    func_L39_0053EB68(a0 + 0x10, D_001DF730, *(f32 *)(a0 + 0x2C),
                      func_L39_005B43C8(0x5F, 0x6F), D_001DF728, func_L39_005B44C8(),
                      1.0f, 2, a0);
    {
        f32 half = *(f32 *)(a0 + 0x2C) * 0.5f;
        func_L39_0053EB68(a0 + 0x10, D_001DF734, half,
                          func_L39_005B43C8(0x6F, 0x7F), D_001DF72C,
                          func_L39_005B44C8(), 1.0f, 2, a0);
    }
}