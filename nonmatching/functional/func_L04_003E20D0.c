/* functional: high. Checked at L04: jump table and all calls/operands match; only scheduling of loads and a few branch targets differ (96 diff lines, no operand differences). Switch is states 1..6 with 1 and 5 empty. */
/* localdecomp:start func_L04_003E20D0 */
__asm__(".extern D_001DF030_sda, 4");
extern s32 D_001DF030_sda;
__asm__(".extern D_001DF034_sda, 4");
extern s32 D_001DF034_sda;
__asm__(".extern D_001DF038_sda, 4");
extern s32 D_001DF038_sda;
__asm__(".extern D_001DF03C_sda, 4");
extern s32 D_001DF03C_sda;
__asm__(".extern D_001DF044_sda, 4");
extern s32 D_001DF044_sda;
__asm__(".extern D_001DF048_sda, 4");
extern s32 D_001DF048_sda;
__asm__(".extern D_001DF05C_sda, 4");
extern f32 D_001DF05C_sda;
__asm__(".extern D_001DF060_sda, 4");
extern f32 D_001DF060_sda;
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_L04_003E2550(void *, u8 *, s32);
extern void func_L04_003E25F8(void *, u8 *);
extern void func_L04_003E26C8(void *, u8 *);
extern void func_L04_003E2818(void *, u8 *);
extern s32 func_L01_0044E1B8(void *, f32);

void func_L04_003E20D0(u8 *self) {
    u8 *m = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(self)) {
            *(s32 *)(m + 0x60) = D_001DF038_sda;
        }
        if (func_0038CAD0(m + 0x60)) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(self)) {
            *(s32 *)(m + 0x60) = D_001DF03C_sda;
            func_003C3A10(self, 1, 0, 0);
            *(f32 *)(self + 0x48) = 0.25f;
        }
        if (self[0x43] == 1 && (self[0x60] & 2)) {
            func_003C3A10(self, 2, 0, 0);
        }
        if (func_0038CAD0(m + 0x60) && self[0x43] != 1) {
            *(s32 *)(self + 0x78) = D_001DF034_sda;
            *(f32 *)(m + 0x68) = D_001DF060_sda * 0.017453292f;
            func_L01_004450F0(self, 4, -1);
        } else {
            f32 t = 1.0f - (f32)*(s32 *)(m + 0x60) / (f32)D_001DF03C_sda;
            *(s32 *)(self + 0x78) = func_0038DBD8(t, D_001DF030_sda, D_001DF034_sda);
            *(f32 *)(m + 0x68) = t * (D_001DF060_sda * 0.017453292f);
        }
        break;
    case 4:
        if (func_L01_004561B8(self)) {
            func_003C3A10(self, 2, 0, 5);
            *(s32 *)(m + 0x60) = D_001DF044_sda;
        }
        if (func_L04_003E2550(self, m, 0)) {
            func_L01_004450F0(self, 6, -1);
        } else if (func_0038CAD0(m + 0x60)) {
            *(f32 *)(m + 0x64) = func_00382538();
            *(f32 *)(m + 0x68) = func_003824E0(D_001DF05C_sda * 0.017453292f, D_001DF060_sda * 0.017453292f);
            *(s32 *)(m + 0x60) = func_00382498(D_001DF044_sda, D_001DF048_sda);
        }
        break;
    case 5:
        break;
    case 6:
        if (func_L01_004561B8(self)) {
            func_003C3A10(self, 3, 5, 5);
        }
        if (func_L04_003E2550(self, m, 1) == 0) {
            func_L01_004450F0(self, 4, -1);
        } else {
            func_L04_003E26C8(self, m);
            if (func_L01_0044E1B8(self, 0.5f)) {
                func_L04_003E2818(self, m);
            }
        }
        break;
    }
    func_L04_003E25F8(self, m);
}
/* localdecomp:end func_L04_003E20D0 */
