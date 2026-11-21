/* functional: high. Per-frame update of a fading drifting sparkle (sibling of func_L01_0046E720 without the homing): advances the model byte, and on each tick of its timer (func_0038CAD0 on o+0x38) ramps the size and alpha over the last frames of its life, moves by the velocity at q+0xC, frees itself if it leaves the 2..1021 box or its life ends, and keeps the w lane at 2.0 (running func_L01_004CAB30 on the position once when it was 2.0). */
extern s32 func_0038CAD0(void *);

void func_L01_00470E48(u8 *o) {
    u8 *q = o + 0x20;
    vu0_v4 v;
    f32 a;
    f32 b;
    f32 r;
    f32 w;
    s32 t;
    s32 h8;
    s32 hA;
    s32 c;
    s32 v3;

    o[8] = o[8] + q[0xA];
    if (func_0038CAD0(o + 0x38) != 0) {
        h8 = *(s16 *)(q + 8);
        hA = *(s16 *)(o + 0xA);
        t = h8 - hA;
        a = *(f32 *)(o + 0x20);
        b = *(f32 *)(q + 4);
        c = q[0xB];
        if (t < *(s16 *)(q + 0x1E)) {
            r = (f32)t / 5.0f;
            *(f32 *)(o + 0xC) = b + ((a + b) * 0.5f - b) * r;
            v3 = (s32)((f32)c + (f32)((c >> 1) - c) * r);
        } else {
            r = (f32)hA / (f32)(h8 - 6);
            *(f32 *)(o + 0xC) = a + ((a + b) * 0.5f - a) * r;
            v3 = (s32)((f32)(c >> 1) * r + 0.0f);
        }
        *(s32 *)(o + 4) = (*(s32 *)(o + 4) & 0xFFFFFF) | (v3 << 24);
        v.x = *(f32 *)(q + 0xC);
        v.y = *(f32 *)(q + 0x10);
        v.z = *(f32 *)(q + 0x14);
        v.w = 0.0f;
        vec_add_ab(o + 0x10, o + 0x10, &v);
        if (*(f32 *)(o + 0x10) < 2.0f || *(f32 *)(o + 0x10) > 1021.0f ||
            *(f32 *)(o + 0x14) < 2.0f || *(f32 *)(o + 0x14) > 1021.0f ||
            *(f32 *)(o + 0x18) < 2.0f || *(f32 *)(o + 0x18) > 1021.0f ||
            func_0038CB00((s16 *)(o + 0xA)) != 0) {
            func_003CD250((Obj *)o);
            return;
        }
    }
    w = *(f32 *)(o + 0x1C);
    if (w != 0.0f) {
        if (w == 2.0f) {
            func_L01_004CAB30(o + 0x10, o + 0x10);
        }
        *(f32 *)(o + 0x1C) = 2.0f;
    }
}
