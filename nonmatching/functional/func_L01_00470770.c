/* functional: high. Per-frame update of a two-point streak (trail) effect: frees itself at end of life; otherwise picks a random model byte from a 2-entry table, moves by the velocity at o+0x30 (gravity lowers its z), writes the previous-position end point at o+0x20 (current position minus the damped step, w = 2.0) and, once the life is shorter than the model byte, fades both colour words' alpha by life/byte * 127. */

void func_L01_00470770(u8 *o) {
    u8 *q = o + 0x30;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    s32 h;
    s32 b;
    s32 s;
    if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
        func_003CD250((Obj *)o);
        return;
    }
    o[2] = D_L01_00221200[0][func_00382468(2)];
    v0 = *(vu0_v4 *)(o + 0x10);
    vec_copy(&v20, &v0);
    vec_add_ba(o + 0x10, o + 0x10, q);
    vec_sub_ab(&v10, o + 0x10, &v20);
    func_0038CF68(&v10, &v10, 0.9f);
    vec_sub_ab(o + 0x20, o + 0x10, &v10);
    *(f32 *)(o + 0x2C) = 2.0f;
    *(f32 *)(q + 8) = *(f32 *)(q + 8) - *(f32 *)(q + 0xC);
    h = *(s16 *)(o + 0xA);
    b = o[8];
    if (h < b) {
        s = (s32)((f32)h / (f32)b * 127.0f);
        *(s32 *)(o + 4) = (*(s32 *)(o + 4) & 0xFFFFFF) | (s << 24);
        *(s32 *)(o + 0xC) = (*(s32 *)(o + 0xC) & 0xFFFFFF) | (s << 24);
    }
}
