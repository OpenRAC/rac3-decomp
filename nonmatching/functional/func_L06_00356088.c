/* functional: high. Same calls, args, order and constants as retail; 211 instrs differ only in scheduling/regalloc, frame size matches. */
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L02_00431568(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_00476498(void *, void *, void *, void *, s32, f32);
extern s32 func_L06_00351220(u8 *, u8 *);
extern s32 func_L06_00352FB0(void *, s32, s32, void *, s32 *);
extern void func_L06_00353210(u8 *, s32 *, s32);
extern f32 func_L06_0045B290(void *, s32, s32, f32, f32);

s32 func_L06_00356088(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 o;
    vu0_v4 e;
    s32 idx;
    f32 frac;
    s32 j;
    s32 r;
    s32 dir;
    f32 yaw;
    f32 f;
    f32 g;
    f32 h;
    f32 step;

    func_L06_00351220(a0, v);
    idx = *(s32 *)(v + 0x344);
    frac = *(f32 *)(v + 0x348);
    step = 5.0f;
    if (*(f32 *)(v + 0x34C) < 0.0f) {
        step = -5.0f;
    }
    r = func_L01_00476498(*(void **)(v + 0x358), &p, &idx, &frac, *(s32 *)(v + 0x340), step);
    vec_sub_ab(&d, &p, a0 + 0x10);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
    yaw = func_0038D160(d.x, d.y);
    dir = 0.0f <= *(f32 *)(v + 0x34C) ? 1 : 0;
    if (func_L06_00352FB0(v, dir, idx, &o, &j)) {
        f = *(f32 *)(v + 0x284 + j * 8);
        if (f < -2.0f) {
            g = func_L06_0045B290(*(void **)(v + 0x358), *(s32 *)(v + 0x344), *(s32 *)(v + 0x280 + j * 8),
                                  *(f32 *)(v + 0x348), 0.0f);
            *(f32 *)(v + 0x34C) = g;
            if (g < 0.0f) {
                f = g + *(f32 *)(v + 0x284 + j * 8);
            } else {
                f = g - *(f32 *)(v + 0x284 + j * 8);
            }
            *(f32 *)(v + 0x34C) = f;
            idx = *(s32 *)(v + 0x344);
            frac = *(f32 *)(v + 0x348);
            func_L01_00476498(*(void **)(v + 0x358), &p, &idx, &frac, *(s32 *)(v + 0x340), *(f32 *)(v + 0x34C));
            *(vu0_v4 *)(v + 0x4A0) = p;
            func_L01_004450F0(a0, 9, -1);
            return 2;
        }
        p = o;
        p.z = func_003C3D30(&o, 0, a0, 0.5f);
    } else {
        p.z = p.z + *(f32 *)(v + 0x354);
    }
    func_L01_00448890(a0 + 0xF8, v + 0x124, 0, yaw, *(f32 *)(v + 0x84), *(f32 *)(v + 0x88), *(f32 *)(v + 0x8C));
    func_L02_00431568(a0, &p, 0x515, yaw, -1.0f, -1.0f, -1.0f);
    func_L06_00353210((u8 *)&e, *(s32 **)(v + 0x358), *(s32 *)(v + 0x344));
    f = func_0038CE68(a0 + 0x10, &d);
    g = func_0038CE68(&e, &d);
    h = f - g;
    if (0.0f <= h) {
        f = *(f32 *)(v + 0x34C);
        if (0.0f < f) {
            f = f - h;
            if (f < 0.375f) {
                f = 0.375f;
            }
            *(f32 *)(v + 0x34C) = f;
        } else {
            f = f + h;
            if (-0.375f < f) {
                f = -0.375f;
            }
            *(f32 *)(v + 0x34C) = f;
            h = -h;
        }
        func_L01_00476498(*(void **)(v + 0x358), &p, v + 0x344, v + 0x348, *(s32 *)(v + 0x340), h);
    }
    if (!(*(f32 *)(v + 0x13C) < *(f32 *)(v + 0xA4))) {
        return 0;
    }
    if (0.0f < *(f32 *)(v + 0x34C)) {
        if (0.0f < *(f32 *)(v + 0x348)) {
            s32 k = *(s32 *)(v + 0x344) + 1;
            s32 last = **(s32 **)(v + 0x358) - 1;
            *(s32 *)(v + 0x344) = k;
            if (last < k) {
                *(s32 *)(v + 0x344) = last;
            }
            *(f32 *)(v + 0x348) = 0.0f;
        }
    } else if (0.0f < *(f32 *)(v + 0x348)) {
        s32 k = *(s32 *)(v + 0x344) - 1;
        *(s32 *)(v + 0x344) = k;
        if (k < 0) {
            *(s32 *)(v + 0x344) = 0;
        }
        *(f32 *)(v + 0x348) = 0.0f;
    }
    if (r != 0) {
        func_L01_004450F0(a0, 3, -1);
    } else {
        func_L01_004450F0(a0, 7, -1);
    }
    return 1;
}
