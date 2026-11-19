/* functional: high. Written from PAL asm; two random draws kept in retail order (first picks the sprite byte, second is stored raw). */
extern u8 *D_L01_00221180[];
extern void func_00382760(void *, f32, f32, f32);
u8 *func_L01_0046BD88(void *pos, u8 type, u8 b11, u8 b12, u8 b13, u8 b15, s32 i18, f32 f1c, f32 scale) {
    u8 *p = (u8 *)func_L01_004618E0(0x3A);
    u8 *q;
    f32 sx, sy, sz;
    s32 r;
    if (p == 0) {
        return 0;
    }
    p[9] = 0x70;
    *(vu0_q *)(p + 0x10) = *(vu0_q *)pos;
    p[1] = 0;
    p[3] = 0x44;
    q = p + 0x20;
    r = func_0013D3E0() & 7;
    *(f32 *)(p + 0xC) = 21000.0f;
    p[2] = D_L01_00221180[0][r];
    p[8] = func_0013D3E0();
    q[0x10] = type;
    q[0x12] = b12;
    q[0x13] = b13;
    *(s32 *)(q + 0x18) = i18;
    *(f32 *)(q + 0x1C) = f1c;
    q[0x11] = b11;
    q[0x15] = b15;
    if (type < 2) {
        *(s16 *)(p + 0xA) = b11;
        *(u32 *)(p + 4) = 0xFF808080;
        q[0x14] = 0;
    } else if (type == 2) {
        sx = func_003824E0(3.0f, 9.0f) * scale * 0.020000001f;
        sy = func_00382538();
        sz = func_003824E0(1.3439035f, 1.7976891f);
        func_00382760(q, sx, sy, sz);
        *(f32 *)(p + 0xC) = 42000.0f;
        q[0x16] = (func_0013D3E0() & 0x1F) + 0x10;
        *(s16 *)(p + 0xA) = b15;
        *(u32 *)(p + 4) = ((u32)q[0x16] << 24) | 0x808080;
        q[0x14] = type;
    }
    return p;
}
