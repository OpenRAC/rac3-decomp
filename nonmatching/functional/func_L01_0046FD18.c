/* functional: high. Per-frame handler for the effect spawned by func_L01_0046FB40: advances the alpha ramp (q+0x18, 8-bit alpha in the top byte of the colour word), moves by the velocity record and lowers its z velocity by the gravity term, runs func_L01_004CAB30 on the position once when its w lane (a state flag) is 2.0 then keeps it at 2.0, advances the model byte and the size ramp, and frees itself when its life ends. */
void func_L01_0046FD18(u8 *o) {
    u8 *q = o + 0x20;
    vu0_v4 v;
    f32 f1;
    f32 w;
    if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
        func_003CD250((Obj *)o);
        return;
    }
    f1 = *(f32 *)(q + 0x18) + (f32)*(s16 *)(q + 0x16) * 0.00061037f;
    *(f32 *)(q + 0x18) = f1;
    *(s32 *)(o + 4) = (*(s32 *)(o + 4) & 0xFFFFFF) | ((s32)f1 << 24);
    v.x = *(f32 *)(q + 0);
    v.y = *(f32 *)(q + 4);
    v.z = *(f32 *)(q + 8);
    v.w = 0.0f;
    vec_add_ab(o + 0x10, o + 0x10, &v);
    *(f32 *)(q + 8) = *(f32 *)(q + 8) - *(f32 *)(q + 0xC);
    w = *(f32 *)(o + 0x1C);
    if (w != 0.0f) {
        if (w == 2.0f) {
            func_L01_004CAB30(o + 0x10, o + 0x10);
        }
        *(f32 *)(o + 0x1C) = 2.0f;
    }
    o[8] = o[8] + q[0x15];
    *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + *(f32 *)(q + 0x10);
}
