/* func_L19_003D2BF8: 13 diff, one instruction's place; needs @ps2as (L19_003D26C0.c has it now) */
typedef int u128_t __attribute__((mode(TI)));

extern f32 func_0038CEA8(void *);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_0040A4A0(void *, void *, s32, u32, s32, s32, f32, f32, f32);
__asm__(".extern D_L19_001DEBE8, 4");
extern u32 D_L19_001DEBE8;
extern u32 D_L19_001DEBEC;
extern u32 D_L19_001DEBF0;
__asm__(".extern D_L19_001DEBD8, 4");
extern f32 D_L19_001DEBD8;
extern f32 D_L19_001DEBDC;
extern f32 D_L19_001DEBE0;
__asm__(".extern D_L19_001DEC18, 4");
extern u32 D_L19_001DEC18;
extern u32 D_L19_001DEC1C;
extern u32 D_L19_001DEC20;
__asm__(".extern D_L19_001DEC28, 4");
extern u32 D_L19_001DEC28;
extern u32 D_L19_001DEC2C;
extern u32 D_L19_001DEC30;
__asm__(".extern D_L19_001DEBF8, 4");
extern f32 D_L19_001DEBF8;
extern f32 D_L19_001DEBFC;
extern f32 D_L19_001DEC00;
__asm__(".extern D_L19_001DEC08, 4");
extern f32 D_L19_001DEC08;
extern f32 D_L19_001DEC0C;
extern f32 D_L19_001DEC10;

void func_L19_003D2BF8(u8 *a) {
    u128_t vec = 0;
    u8 *s;
    u8 *pos;
    f32 z;
    ((f32 *)&vec)[3] = 1.0f;
    s = *(u8 **)(a + 0x68);
    *(f32 *)(s + 0x14) = *(f32 *)(s + 0x14) - 0.1f;
    if (*(f32 *)(s + 0x14) <= -8.0f) {
        *(f32 *)(s + 0x14) = *(f32 *)(s + 0x14) + 8.0f;
    }
    z = 0.0f;
    pos = a + 0x10;
    *(f32 *)(s + 0x18) = *(f32 *)(s + 0x18) + func_0038CEA8(s);
    func_003D9508(pos, 0x31, D_L19_001DEBE8, 1, D_L19_001DEBD8, z, func_00382538());
    func_003D9508(pos, 0x31, D_L19_001DEBEC, 0, D_L19_001DEBDC, z, func_00382538());
    func_003D9508(pos, 0x2F, D_L19_001DEBF0, 1, D_L19_001DEBE0, z, func_00382538());
    if (1.0f < *(f32 *)(s + 0x18)) {
        func_L01_0040A4A0(a, &vec, 1, D_L19_001DEC18, D_L19_001DEC28, 0x17, D_L19_001DEBF8, D_L19_001DEC08, *(f32 *)(s + 0x14));
        func_L01_0040A4A0(a, &vec, 1, D_L19_001DEC1C, D_L19_001DEC2C, 0x17, D_L19_001DEBFC, D_L19_001DEC0C, *(f32 *)(s + 0x14));
        func_L01_0040A4A0(a, &vec, 1, D_L19_001DEC20, D_L19_001DEC30, 0x17, D_L19_001DEC00, D_L19_001DEC10, *(f32 *)(s + 0x14));
    }
}
