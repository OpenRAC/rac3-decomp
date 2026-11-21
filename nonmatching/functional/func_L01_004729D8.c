/* functional: high. Snippet needs typedef u128_t, func_00382498, func_003824E0 declared (this file has no such context). 11 args: 8 in regs, a8 and kind on stack, scale in f12. */
/* localdecomp:start func_L01_004729D8 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *D_L01_00221248[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);

u8 *func_L01_004729D8(u128_t *pos, f32 *velocity, f32 *acceleration, s32 render, s32 life, u8 a5, u8 a6, u8 a7, u8 a8, u8 kind, f32 scale) {
    u8 *p;
    u8 *s;
    s32 low;
    s32 k;

    p = func_L01_004618E0(0x6C);
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *pos;
        p[3] = render;
        p[1] = 0;
        s = p + 0x20;
        p[9] = 0x44;
        p[8] = func_00382468(0xFF);
        *(s16 *)(p + 0xA) = life;
        p[2] = *D_L01_00221248[0];
        *(f32 *)(s + 0) = velocity[0];
        *(f32 *)(s + 4) = velocity[1];
        *(f32 *)(s + 8) = velocity[2];
        *(f32 *)(p + 0x30) = acceleration[0];
        *(f32 *)(p + 0x34) = acceleration[1];
        *(f32 *)(p + 0x38) = acceleration[2];
        low = func_00382498(0, 0xB);
        k = kind;
        if ((u32)(kind - 1) >= 0xE) {
            k = func_00382498(0, 0xF);
        }
        s[0xC] = low | (k << 4);
        low = func_00382498(1, 4);
        s[0xE] = life;
        s[0xD] = low << 4;
        if (a5 == 0) {
            s[0x1E] = (s32)(func_003824E0(0.3f, 0.5f) * 128.0f);
        } else {
            s[0x1E] = a5;
        }
        if (a6 == 0) {
            s[0x1F] = (s32)(func_003824E0(1.0f, 2.0f) * 128.0f);
        } else {
            s[0x1F] = a6;
        }
        if (a7 == 0) {
            s[0x1C] = (s32)(func_003824E0(0.9f, 1.1f) * 0.10000001f * 128.0f);
        } else {
            s[0x1C] = a7;
        }
        if (a8 == 0) {
            s[0x1D] = (s32)(func_003824E0(0.0f, 0.0125f) * 128.0f);
        } else {
            s[0x1D] = a8;
        }
        s[0xF] = (s32)(scale * 128.0f);
        *(s32 *)(p + 4) = ((k + 0x70) << 24) | 0x103080;
    }
    return p;
}
/* localdecomp:end func_L01_004729D8 */
