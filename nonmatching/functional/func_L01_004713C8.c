/* functional: high. Spawner for the effect handled by func_L01_00471530: allocates a 0x61-byte object, fills the header (position, colour word from t1 alpha and a3, life, random phase byte, model byte from table index t3), velocity from vec, size ramp (f13-f12)/life, per-frame alpha step (t2-t1)/life, and installs func_L01_00471530 as its handler. */
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern u8 *D_L01_0022121C[];
extern void func_L01_00471530(void);

u8 *func_L01_004713C8(s128 *pos, f32 *vec, s32 life, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13, f32 f14) {
    u8 *p = func_L01_004618E0(0x61);
    u8 *q;
    if (p != 0) {
        p[1] = 0;
        *(f32 *)(p + 0xC) = f12;
        *(s128 *)(p + 0x10) = *pos;
        p[9] = 0x44;
        p[3] = 0x48;
        *(s32 *)(p + 4) = (t1 << 24) | a3;
        p[8] = func_00382468(0xFF);
        q = p + 0x20;
        p[2] = D_L01_0022121C[0][t3];
        *(s16 *)(p + 0xA) = life;
        *(f32 *)(q + 0) = vec[0];
        *(f32 *)(q + 4) = vec[1];
        *(f32 *)(q + 8) = vec[2];
        *(s32 *)(q + 0x1C) = (s32)func_L01_00471530;
        *(f32 *)(q + 0xC) = f14;
        q[0x15] = t0;
        *(f32 *)(q + 0x10) = (f13 - f12) / (f32)life;
        q[0x14] = (t2 - t1) / life;
    }
    return p;
}
