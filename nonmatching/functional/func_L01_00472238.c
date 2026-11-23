/* functional: high. Differs from retail by register order/scheduling only; all offsets, constants and call args verified against the .s. */
/* localdecomp:start func_L01_00472238 */
extern u8 *D_L01_00221240[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);

u8 *func_L01_00472238(u128_t *pos, f32 *vel, s32 id, s32 life, f32 scale) {
    u8 *p;
    u8 *s;
    s32 r;

    p = func_L01_004618E0(0x6A);
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *pos;
        p[3] = id;
        p[1] = 0;
        s = p + 0x20;
        p[9] = 0x44;
        p[8] = func_00382468(0xFF);
        *(s16 *)(p + 0xA) = life;
        p[2] = *D_L01_00221240[0];
        *(f32 *)(s + 0) = vel[0];
        *(f32 *)(s + 4) = vel[1];
        *(f32 *)(s + 8) = vel[2];
        r = func_00382498(0xF, 0x1F);
        *(s32 *)(s + 0xC) = (r << 16) + (r << 8) + r;
        s[0x11] = life;
        s[0x13] = 0;
        s[0x10] = func_00382498(1, 4);
        s[0x12] = func_00382498(0x5F, 0x7F);
        *(f32 *)(s + 0x14) = func_003824E0(0.0625f, 0.125f) * 210000.0f;
        *(f32 *)(s + 0x18) = func_003824E0(0.5f, 0.6f) * 210000.0f;
        *(f32 *)(s + 0x1C) = scale;
        *(s32 *)(p + 4) = (s[0x12] << 24) | 0x103080;
    }
    return p;
}
/* localdecomp:end func_L01_00472238 */
