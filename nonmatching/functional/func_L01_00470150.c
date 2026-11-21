/* functional: high. Spawner for an effect attached to a target object (updated by func_L01_00470000): allocates a 0x59-byte object, fills header (colour word, life, model byte from a table, random phase), the attach record (target, word, float, bytes, spawn position copy), and places it at the target's position plus the spawn offset rotated by the target's matrix, with its size byte from t3 (or the target's h32 field when t3 <= 0); without a target it sits at the given position. */
extern u8 *D_L01_002211FC;

u8 *func_L01_00470150(s128 *pos, u8 *target, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, u8 a8, s32 a9, f32 f12, f32 f13, f32 f14) {
    u8 *p = ((u8 * (*)(s32))func_L01_004618E0)(0x59);
    u8 *q;
    vu0_v4 out;
    s32 v;
    if (p != 0) {
        *(s32 *)(p + 4) = a2;
        *(f32 *)(p + 0xC) = f12;
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x48;
        p[8] = func_00382468(0xFF);
        q = p + 0x20;
        p[2] = D_L01_002211FC[t0];
        *(s16 *)(p + 0xA) = t1;
        *(u8 **)q = target;
        *(s32 *)(q + 4) = a3;
        *(f32 *)(q + 8) = f13;
        q[0xC] = t2;
        q[0xD] = a8;
        *(s128 *)(p + 0x30) = *pos;
        *(f32 *)(q + 0x1C) = f14;
        if (t0 == 0) {
            q[0xE] = 1;
        }
        q[0xF] = a9;
        if (target != 0) {
            *(s128 *)(p + 0x10) = *(s128 *)(target + 0x10);
            func_0038D000(&out, p + 0x30, target + 0xC0);
            vec_add_ab(p + 0x10, p + 0x10, &out);
            if (t3 > 0) {
                v = t3 >> 5;
            } else {
                v = (s16)*(u16 *)(target + 0x32) >> 5;
            }
            p[9] = (v << 4) + 4;
        } else {
            *(s128 *)(p + 0x10) = *pos;
        }
    }
    return p;
}
