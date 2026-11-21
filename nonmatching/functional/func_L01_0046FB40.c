/* functional: high. Spawner for the effect handled by func_L01_0046FD18: allocates an 0x55-byte object, fills its header (position, colour/alpha word, model byte, random phase), its velocity record and its fade ramps, and installs func_L01_0046FD18 as its per-frame handler. */
extern u8 *D_L01_002211EC[];
extern void func_L01_0046FD18(void);

u8 *func_L01_0046FB40(s128 *pos, f32 *vec, s32 life, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13, f32 f14) {
    u8 *p = ((u8 * (*)(s32))func_L01_004618E0)(0x55);
    u8 *q;
    f32 fl;
    f32 f3;
    f32 span;
    if (p != 0) {
        *(s128 *)(p + 0x10) = *pos;
        p[1] = 0;
        *(f32 *)(p + 0xC) = f12;
        *(f32 *)(p + 0x1C) = (f32)t3;
        p[3] = 0x48;
        *(s32 *)(p + 4) = (t1 << 24) | a3;
        p[9] = 0x44;
        p[8] = func_00382468(0xFF);
        fl = (f32)life;
        span = (f32)(t2 - t1);
        p[2] = *D_L01_002211EC[0];
        q = p + 0x20;
        span = span / fl;
        *(f32 *)(q + 0) = vec[0];
        *(f32 *)(q + 4) = vec[1];
        *(f32 *)(q + 8) = vec[2];
        *(f32 *)(q + 0xC) = f14;
        q[0x15] = t0;
        f3 = span * 0.05f;
        if (1.0f < f3) {
            f3 = 1.0f;
        }
        *(f32 *)(q + 0x18) = (f32)t1;
        life = abs_asm(life);
        *(s16 *)(q + 0x16) = (s32)(f3 * 32767.0f);
        *(f32 *)(q + 0x10) = (f13 - f12) / fl;
        *(s16 *)(p + 0xA) = life;
        *(s32 *)(q + 0x1C) = (s32)func_L01_0046FD18;
    }
    return p;
}
