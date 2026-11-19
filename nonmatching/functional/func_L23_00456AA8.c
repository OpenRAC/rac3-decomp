/* functional: high. Same stores and calls as retail. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L23_0021EF44;
extern s32 D_001D7F50;
extern f32 D_001D7F5C;
extern u8 *func_L01_004618E0(s32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);

u8 *func_L23_00456AA8(u128_t *a0, u128_t *a1, s32 a2, s32 a3, s32 a4, f32 f12) {
    u8 *p;

    p = func_L01_004618E0(0x7B);
    if (p != 0) {
        *(u128_t *)(p + 0x20) = *a1;
        p[0x35] = a2;
        p[0x36] = a3;
        p[0x37] = a4;
        *(s16 *)(p + 0x32) = a2 & 0xFF;
        *(s16 *)(p + 0x30) = a2 & 0xFF;
        *(f32 *)(p + 0x38) = f12 * 210000.0f;
        p[0x34] = 0;
        *(u128_t *)(p + 0x10) = *a0;
        p[1] = 0;
        *(s32 *)(p + 4) = D_001D7F50;
        p[3] = 0x48;
        p[9] = 0x44;
        p[8] = (s32)(func_00382538() * 256.0f);
        p[2] = D_L23_0021EF44[func_00382468(2)];
        *(s16 *)(p + 0xA) = a2 + a3 + a4 + 4;
        *(f32 *)(p + 0xC) = D_001D7F5C;
    }
    return p;
}
