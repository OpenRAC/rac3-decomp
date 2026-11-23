/* functional: high. Spawner (sibling of func_L01_0046E5A8) for a 0x5C-byte sprite effect: header from the arguments (position, colour word, life, model byte from table by index t3, size factors f12/f13 scaled by 210000), model-byte mode (0 -> 0x40, 1 -> 0x5A, 2 -> random, other modes leave it untouched as retail), a record with the size ramp, velocity vec, bytes, h1E and an int; then nudges its position 0.9 of the way toward D_L01_001E29C0. */
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern u8 *D_L01_00221208[];
extern vu0_v4 D_L01_001E29C0;

u8 *func_L01_00470C78(s128 *pos, s32 life, s32 color, s32 mode, s32 t0, f32 *vec, s32 t2, s32 t3, s32 a8, s32 a9, f32 f12, f32 f13) {
    u8 *p = func_L01_004618E0(0x5C);
    u8 *q;
    vu0_v4 v;
    if (p != 0) {
        *(s128 *)(p + 0x10) = *pos;
        *(f32 *)(p + 0x1C) = (f32)a9;
        q = p + 0x20;
        p[3] = 0x48;
        p[9] = 0x20;
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        *(f32 *)(p + 0xC) = f12 * 210000.0f;
        p[2] = D_L01_00221208[0][t3];
        *(s16 *)(p + 0xA) = life;
        if (mode == 0) {
            p[8] = 0x40;
        } else if (mode == 1) {
            p[8] = 0x5A;
        } else if (mode == 2) {
            p[8] = func_00382468(0xFF);
        }
        *(f32 *)(q + 0) = *(f32 *)(p + 0xC);
        *(f32 *)(q + 4) = f13 * 210000.0f;
        *(s16 *)(q + 8) = life;
        q[0xA] = t0;
        q[0xB] = color >> 24;
        *(s32 *)(q + 0x18) = t2;
        *(s16 *)(q + 0x1E) = a8;
        *(f32 *)(q + 0xC) = vec[0];
        *(f32 *)(q + 0x10) = vec[1];
        *(f32 *)(q + 0x14) = vec[2];
        vec_sub_ba(&v, &D_L01_001E29C0, p + 0x10);
        func_0038CF68(&v, &v, 0.9f);
        vec_add_ab(p + 0x10, p + 0x10, &v);
    }
    return p;
}
