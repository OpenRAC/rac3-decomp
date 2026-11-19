/* functional: high. Per-frame handler of the effect spawned by func_L01_004713C8: frees itself at end of life; otherwise steps its alpha byte (top byte of the colour word) by the per-frame step at q+0x14, moves by the velocity record (then func_L01_004CAB30 on the position), and either applies gravity to z velocity (when the flag word D_L01_001D673C is 0) or pushes the position along the vector func_L01_004C7D98 gives, scaled by -q[0xC]; finally advances the model byte and the size. */
extern s32 D_L01_001D673C[];
extern void func_L01_004C7D98(void *, void *);

void func_L01_00471530(u8 *o) {
    u8 *q = o + 0x20;
    vu0_v4 v;
    vu0_v4 v10;
    s32 w4;
    s32 a;
    if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
        func_003CD250((Obj *)o);
        return;
    }
    w4 = *(s32 *)(o + 4);
    a = (w4 >> 24) + q[0x14];
    *(s32 *)(o + 4) = (w4 & 0xFFFFFF) | (a << 24);
    v.x = *(f32 *)(o + 0x20);
    v.y = *(f32 *)(q + 4);
    v.z = *(f32 *)(q + 8);
    v.w = 0.0f;
    vec_add_ab(o + 0x10, o + 0x10, &v);
    func_L01_004CAB30(o + 0x10, o + 0x10);
    if (D_L01_001D673C[0] == 0) {
        *(f32 *)(q + 8) = *(f32 *)(q + 8) - *(f32 *)(q + 0xC);
    } else {
        func_L01_004C7D98(o + 0x10, &v10);
        func_0038CF68(&v10, &v10, -*(f32 *)(q + 0xC));
        vec_add_ba(o + 0x10, o + 0x10, &v10);
    }
    o[8] = o[8] + q[0x15];
    *(f32 *)(o + 0xC) = *(f32 *)(o + 0xC) + *(f32 *)(q + 0x10);
}
