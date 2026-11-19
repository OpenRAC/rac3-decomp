/* functional: medium. Per-frame update of a drifting wisp that the hero attracts. Damps its velocity (x0.9), applies gravity to z, moves, and when it is within 1.05 of the hero position (D_001A4C60): if the hero field at +0x170 (of D_001A4BE0) is non-zero, pulls toward the hero by a random amount scaled with that field and bumps the model byte by h16*field*0.5. Every 10th tick of the global counter it re-rolls its phase float (q+0x1C) and adds a small random kick along D_001E2880. Then sets colour/alpha from life vs h14 (two ranges: >= 160 white-ish 0x353535 alpha up to 128 or flat 0x9F; < 160 grey 0x909090 alpha up to 64 or flat 0x40), advances the model byte by q[0x16] and frees itself at end of life. The kick vector reuses the pull vector's stack slot, as retail does. */
extern s32 D_L01_001DFB40_00470A28;
extern vu0_v4 D_001A4C60;
extern vu0_v4 D_001E2880;
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);

void func_L01_00471748(u8 *o) {
    u8 *q = o + 0x20;
    u8 *h;
    vu0_v4 v0;
    vu0_v4 v10;
    f32 f;
    f32 g;
    s32 cnt;
    s32 h14;
    s32 hA;
    s32 w4;

    func_L01_004CAB30(o + 0x10, o + 0x10);
    func_0038CE20(q, q, 0.9f);
    *(f32 *)(q + 8) = *(f32 *)(q + 8) - *(f32 *)(q + 0xC);
    vec_add_ab(o + 0x10, o + 0x10, q);
    cnt = D_L01_001DFB40_00470A28;
    if (func_0038CF00(o + 0x10, &D_001A4C60) < 1.05f) {
        h = (u8 *)&D_001A4C60 - 0x80;
        if (*(f32 *)(h + 0x170) != 0.0f) {
            v10 = D_001A4C60;
            vec_sub_ab(&v0, o + 0x10, &v10);
            f = func_003824E0(0.1f, 2.0f);
            func_0038CF68(&v0, &v0, *(f32 *)(h + 0x170) * 0.2f + f * 0.020000001f * 0.15f);
            o[8] = o[8] + (s32)((f32)*(s16 *)(q + 0x16) * *(f32 *)(h + 0x170) * 0.5f);
            vec_add_ab(o + 0x10, o + 0x10, &v0);
        }
        cnt = D_L01_001DFB40_00470A28;
    }
    if (cnt % 10 == 0) {
        f = func_0038DAB8(*(f32 *)(q + 0x1C), 1.0f);
        *(f32 *)(q + 0x1C) = f;
        g = func_0038D0B0(f);
        func_0038CF68(&v0, &D_001E2880, g * 0.0075f);
        vec_add_ab(q, q, &v0);
    }
    h14 = *(s16 *)(q + 0x14);
    hA = *(s16 *)(o + 0xA);
    if (h14 >= 0xA0) {
        if (hA < h14) {
            w4 = ((s32)((f32)hA / (f32)h14 * 128.0f) << 24) | 0x353535;
        } else {
            w4 = 0x9F353535;
        }
    } else {
        if (hA < h14) {
            w4 = ((s32)((f32)hA / (f32)h14 * 64.0f) << 24) | 0x909090;
        } else {
            w4 = 0x40909090;
        }
    }
    *(s32 *)(o + 4) = w4;
    o[8] = o[8] + q[0x16];
    if (func_0038CB00((s16 *)(o + 0xA)) != 0) {
        func_003CD250((Obj *)o);
    }
}
