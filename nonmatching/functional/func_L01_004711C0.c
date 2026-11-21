/* functional: high. Per-frame update of a short streak particle (sibling of func_L01_00470770 without the random model byte): frees itself at end of life; otherwise moves by the velocity at o+0x30, lowers its z velocity by the gravity term at +0x3C, writes the trailing end point at o+0x20 (position minus the velocity scaled by 0.4 * its length, w = 1.0) and, once life < model byte, fades both colour words to white with alpha life/byte * 127. (Retail also saves the old position to the stack; it is never read.) */
void func_L01_004711C0(u8 *o) {
    u8 *q = o + 0x30;
    vu0_v4 v10;
    f32 len;
    s32 h;
    s32 b;
    s32 s;
    if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
        func_003CD250((Obj *)o);
        return;
    }
    vec_add_ba(o + 0x10, o + 0x10, q);
    *(f32 *)(q + 8) = *(f32 *)(q + 8) - *(f32 *)(q + 0xC);
    len = func_0038CEA8(q);
    func_0038CF68(&v10, q, len * 0.4f);
    vec_sub_ab(o + 0x20, o + 0x10, &v10);
    *(f32 *)(o + 0x2C) = 1.0f;
    h = *(s16 *)(o + 0xA);
    b = o[8];
    if (h < b) {
        s = (s32)((f32)h / (f32)b * 127.0f);
        *(s32 *)(o + 4) = (s << 24) | 0xFFFFFF;
        *(s32 *)(o + 0xC) = (s << 24) | 0xFFFFFF;
    }
}
