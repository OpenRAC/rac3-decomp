/* functional: high. Same calls, args, order and constants as retail; 273 instrs differ in scheduling/regalloc, frame size matches. abs/sqrt via fabs_asm/sqrt_asm. */
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_003C4BB0(float *, float);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L02_00431568(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_00476498(void *, void *, void *, void *, s32, f32);
extern s32 func_L06_00352E20(void *, s32, s32, void *);
extern void func_L06_00353210(u8 *, s32 *, s32);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern f32 func_L06_0045B290(void *, s32, s32, f32, f32);

s32 func_L06_003566B0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 p;
    vu0_v4 o;
    vu0_v4 e;
    vu0_v4 w;
    vu0_v4 acc;
    s32 idx;
    f32 frac;
    s32 r;
    s32 dir;
    f32 yaw;
    f32 f;
    f32 g;
    f32 h;
    f32 step;

    idx = *(s32 *)(v + 0x344);
    frac = *(f32 *)(v + 0x348);
    f = *(f32 *)(v + 0x34C);
    if (f < 0.0f) {
        step = -5.0f;
        if (-5.0f < f) {
            step = f;
        }
    } else {
        step = 5.0f;
        if (f < 5.0f) {
            step = f;
        }
    }
    func_L01_00476498(*(void **)(v + 0x358), &p, &idx, &frac, *(s32 *)(v + 0x340), step);
    vec_sub_ab(&d, &p, a0 + 0x10);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
    yaw = func_0038D160(d.x, d.y);
    dir = 0.0f <= *(f32 *)(v + 0x34C) ? 1 : 0;
    r = func_L06_00352E20(v, dir, idx, &o);
    if (r) {
        p = o;
    } else if (*(s32 *)(v + 0x36C) != 0) {
        f = fabs_asm(*(f32 *)(v + 0x34C));
        if (f < 20.0f) {
            if (f < 10.0f) {
                p = *(vu0_v4 *)(v + 0x4A0);
            } else {
                h = (f - 10.0f) / 10.0f;
                if (1.0f < h) {
                    h = 1.0f;
                } else if (h < 0.0f) {
                    h = 0.0f;
                }
                func_0038CDF8(&p, v + 0x4A0, &p, h);
                if (func_0038CF38(a0 + 0x10, &p) < 0.75f) {
                    p = *(vu0_v4 *)(v + 0x4A0);
                    func_L06_0045B1F8(*(void **)(v + 0x358), a0 + 0x10, v + 0x344, v + 0x348);
                    *(f32 *)(v + 0x34C) = func_L06_0045B290(*(void **)(v + 0x358), *(s32 *)(v + 0x344),
                                                            *(s32 *)(v + 0x364), *(f32 *)(v + 0x348),
                                                            *(f32 *)(v + 0x368));
                }
            }
        }
    }
    if (fabs_asm(step) < 5.0156f) {
        p.z = p.z + *(f32 *)(v + 0x354);
    }
    func_L01_00448890(a0 + 0xF8, v + 0x124, 0, yaw, *(f32 *)(v + 0x84), *(f32 *)(v + 0x88), *(f32 *)(v + 0x8C));
    if (p.z < *(f32 *)(a0 + 0x18)) {
        func_L02_00431568(a0, &p, 0x515, yaw, -1.0f, -1.0f, -1.0f);
    } else {
        f = func_0038CF00(a0 + 0x10, &p);
        *(f32 *)(v + 0x13C) = f;
        g = *(f32 *)(v + 0xA4);
        if (f <= g) {
            qzero(&w);
        } else {
            h = sqrt_asm((f - g) * 2.0f * *(f32 *)(v + 0x94));
            if (*(f32 *)(v + 0x98) < h) {
                h = *(f32 *)(v + 0x98);
            }
            vec_sub_ab(&w, &p, a0 + 0x10);
            func_0038CF68(&w, &w, h);
        }
        vec_sub_ab(&acc, &w, v + 0x110);
        if (0.0f < func_0038CE68(&w, v + 0x110)) {
            func_003C4BB0((float *)&acc, *(f32 *)(v + 0x90));
        } else {
            func_003C4BB0((float *)&acc, *(f32 *)(v + 0x94));
        }
        vec_add_ab(v + 0x110, v + 0x110, &acc);
        *(f32 *)(v + 0x120) = func_0038CEA8(v + 0x110);
        vec_add_ab(a0 + 0x10, a0 + 0x10, v + 0x110);
        *(f32 *)(v + 0x13C) = func_0038CF00(a0 + 0x10, &p);
    }
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
    if (r != 0 && 0.75f < fabs_asm(*(f32 *)(v + 0x34C))) {
        func_L01_004450F0(a0, 3, -1);
    } else {
        func_L01_004450F0(a0, 0xA, -1);
    }
    return 1;
}
