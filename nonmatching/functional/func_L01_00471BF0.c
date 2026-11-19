/* functional: high. EXACT (byte-identical via check.py at level 01). Declarations beyond the file context: none needed besides externs. */
/* localdecomp:start func_L01_00471BF0 */
extern u8 *D_L01_00221230[];
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_003C3D30(void *, s32, s32, f32);

u8 *func_L01_00471BF0(u128_t *pos, u128_t *vel, s32 life) {
    u8 *p;
    u8 *s;
    u8 *q;

    p = func_L01_004618E0(0x66);
    if (p != 0) {
        p[9] = 0x42;
        p[3] = 0x44;
        p[1] = 0;
        s = p + 0x20;
        q = p + 0x10;
        p[2] = *D_L01_00221230[0];
        *(f32 *)(p + 0xC) = func_003824E0(0.03f, 0.175f) * 210000.0f;
        p[8] = func_00382468(0xFF);
        *(s16 *)(p + 0xA) = (life * 5 + 2) / 6;
        *(u128_t *)(p + 0x10) = *pos;
        *(u128_t *)(p + 0x20) = *vel;
        *(f32 *)(s + 0xC) = func_003824E0(4.6f, 8.6f) * 0.0004000000189989805f;
        *(f32 *)(s + 0x18) = *(f32 *)(p + 0xC) + *(f32 *)(p + 0xC);
        *(s16 *)(s + 0x16) = func_00382498(0, 3);
        *(s16 *)(s + 0x14) = ((life / 2) * 5 + 2) / 6;
        *(f32 *)(s + 0x1C) = func_00382538();
        *(f32 *)(s + 0x10) = func_003C3D30(q, 0, 0, 0.5f);
    }
    return p;
}
/* localdecomp:end func_L01_00471BF0 */
