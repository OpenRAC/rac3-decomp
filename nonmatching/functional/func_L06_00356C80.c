/* functional: high. Same calls, args, order and constants as retail; 441 instrs differ in scheduling/regalloc/layout only. */
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_0045A898(void *, void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_00476498(void *, void *, void *, void *, s32, f32);
extern s32 func_L06_00350FD0(u8 *, u8 *, u8 *);
extern s32 func_L06_00351220(u8 *, u8 *);
extern void func_L06_003517C0(u8 *, u8 *, s32);
extern void func_L06_00351930(u8 *, u8 *, s32, s32, s32);
extern void func_L06_00351A08(u8 *, u8 *, s32);
extern void func_L06_00351A68(u8 *, u8 *, s32);
extern s32 func_L06_00352E20(void *, s32, s32, void *);
extern void func_L06_00353210(u8 *, s32 *, s32);
extern void func_L06_0045B1F8(void *, void *, void *, void *);
extern f32 func_L06_0045B290(void *, s32, s32, f32, f32);

s32 func_L06_00356C80(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 oldpos;
    vu0_v4 d;
    vu0_v4 p;
    vu0_v4 o;
    vu0_v4 e;
    vu0_v4 w1;
    vu0_v4 w2;
    s32 idx;
    f32 frac;
    s32 r;
    s32 dir;
    s32 st;
    f32 yaw;
    f32 f;
    f32 g;
    f32 h;
    f32 step;

    oldpos = *(vu0_v4 *)(a0 + 0x10);
    if (func_L01_004561B8(a0)) {
        *(s32 *)(v + 0x394) = 0;
    }
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
    frac = *(f32 *)(v + 0x348);
    idx = *(s32 *)(v + 0x344);
    func_L01_00476498(*(void **)(v + 0x358), &p, &idx, &frac, *(s32 *)(v + 0x340), step);
    vec_sub_ab(&d, &p, a0 + 0x10);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
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
    if (a0[0x95] == 4) {
        func_L06_003517C0(a0, v, 0x14);
    } else if (*(s32 *)(v + 0x384) == 0) {
        if (a0[0x43] != 5) {
            func_L01_0045BD78(a0, 0.0059999995f, 0.2f, 0.010000001f, 0.25f);
            func_L06_00351A68(a0, v, 5);
        }
    } else {
        vec_sub_ab(&w1, &p, a0 + 0x10);
        func_0038CF68(&w1, &w1, 1.0f);
        vec_sub_ab(&w2, v + 0x220, a0 + 0x10);
        func_0038CF68(&w2, &w2, 1.0f);
        f = func_0038CE68(&w1, &w2);
        st = a0[0x43];
        if (st == 0x14) {
            if (f < -0.2f) {
                func_L06_003517C0(a0, v, 0x15);
            }
        } else if (st == 0x15) {
            if (0.1f < f) {
                func_L06_003517C0(a0, v, 0x14);
            }
        } else if (f < 0.2f) {
            func_L06_003517C0(a0, v, 0x15);
        } else {
            func_L06_003517C0(a0, v, 0x14);
        }
    }
    if (a0[0x43] == 0x15) {
        yaw = func_0038DAB8(func_0038D160(p.x - *(f32 *)(a0 + 0x10), p.y - *(f32 *)(a0 + 0x14)), 3.1415927f);
    } else {
        yaw = func_0038D160(p.x - *(f32 *)(a0 + 0x10), p.y - *(f32 *)(a0 + 0x14));
    }
    func_L01_0045A898(a0, &p, yaw);
    *(f32 *)(*(u8 **)(v + 0x260) + 0x48) = *(f32 *)(a0 + 0x48);
    if (*(s32 *)(v + 0x104) & 4) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 0.01f;
    }
    if (func_L01_0040E570(&oldpos, a0 + 0x10) < 0.00010000001f) {
        *(s32 *)(v + 0x394) = *(s32 *)(v + 0x394) + 1;
    } else {
        *(s32 *)(v + 0x394) = 0;
    }
    if ((*(s32 *)(v + 0x104) & 0xF) != 0 && (*(s32 *)(v + 0x108) & 0xF) != 0) {
        goto stuck;
    }
    if (*(s32 *)(v + 0x394) >= 0x2E) {
    stuck:
        if (*(f32 *)(v + 0x13C) < 1.0f) {
            if (0.0f < *(f32 *)(v + 0x34C)) {
                *(f32 *)(v + 0x34C) = 0.375f;
            } else {
                *(f32 *)(v + 0x34C) = -0.375f;
            }
            *(f32 *)(v + 0x13C) = 0.0f;
        } else {
            func_L01_004450F0(a0, 8, -1);
            return 1;
        }
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
    if (*(s32 *)(v + 0x384) != 0) {
        func_L06_00350FD0(a0, v, v + 0x220);
    } else {
        func_L06_00351220(a0, v);
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
    func_L01_004450F0(a0, 3, -1);
    if (*(s32 *)(v + 0x384) != 0) {
        func_L06_00351A08(a0, v, 0xA);
    } else {
        func_L06_00351930(a0, v, 2, 0, 0xA);
    }
    return 1;
}
