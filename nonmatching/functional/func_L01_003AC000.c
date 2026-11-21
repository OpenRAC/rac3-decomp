/* functional: medium. compiles at level_01 (583 diff lines, regalloc/frame); plain-C vsub/vcopy helpers used because the VU0 inline asm exhausts vf regs here; retail uses VU0 vsub.xyz and quad copies; sp54/idx out-param of func_L01_003ABD60; mode selection reconstructed from the branch web, all 4 modes read; callee semantics (003ABD10/60/E88/F48, 00448890, 003C41A0) inferred from use */
extern f32 func_L01_003ABD10(void *, void *, f32);
extern f32 func_L01_003ABD60(void *, void *, s32 *, f32, f32);
extern void func_L01_003ABE88(void *, void *, s32, void *, f32);
extern void func_L01_003ABF48(void *, void *, void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32);
extern u8 *D_L01_0021F6C0[];
extern u8 *D_L01_001E0100;
extern f32 D_001DE3C4_sda;
extern f32 D_001DE3C8_sda;
extern f32 D_001DE3D0_sda;
extern f32 D_001DE3D4_sda;
extern f32 D_001DE3D8_sda;
extern f32 D_001DE3DC_sda;
extern f32 D_001DE3E0_sda;
extern f32 D_001DE3E4_sda;
extern f32 D_001DE3E8_sda;
extern f32 D_001DE3EC_sda;
extern f32 D_001DE3F0_sda;
extern f32 D_001DE3F4_sda;
extern f32 D_001DE3F8_sda;
extern f32 D_001DE3FC_sda;
extern f32 D_001DE400_sda;
extern f32 D_001DE404_sda;
extern f32 D_001DE408_sda;
extern f32 D_001DE40C_sda;
extern f32 D_001DE410_sda;

static void vsub3_3AC000(void *dv, void *av, void *bv) {
    f32 *d = dv;
    f32 *a = av;
    f32 *b = bv;
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
}

static void vcopy4_3AC000(void *dv, void *sv) {
    f32 *d = dv;
    f32 *s = sv;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
}

s32 func_L01_003AC000(u8 *obj, u8 *m) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 ang[4] __attribute__((aligned(16)));   /* [0]=sp20 [1]=sp24 [2]=sp28 */
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    s32 v50;
    s32 idx;
    u8 *path;
    u8 *ent;
    u8 *A;
    u8 *B;
    f32 pos, f21, f1, d, f5, f3, k, frac, fnew, lim, t;
    s32 ret;
    s32 reached;
    s32 st;
    s32 mode;

    path = D_L01_0021F6C0[*(s32 *)(m + 0xD10)];
    ent = D_L01_001E0100 + (*(s32 *)(m + 0xC80 + *(s32 *)(m + 0xD0C) * 4) << 7);
    vcopy4_3AC000(v10, obj + 0x10);
    f21 = func_L01_003ABD10(obj, m, D_001DE3C8_sda * *(f32 *)(m + 0xC6C));
    pos = *(f32 *)(m + 0xD14);
    if (pos < 0.0f) {
        A = path + 0x10;
        B = m + 0xD60;
    } else {
        idx = (s32)pos;
        if (idx == *(s32 *)path - 1) {
            A = m + 0xD70;
            B = path + 0x10 + idx * 16;
        } else {
            B = path + 0x10 + idx * 16;
            A = path + 0x20 + idx * 16;
        }
    }
    vsub3_3AC000(v0, A, B);
    func_0038CF68((u8 *)v0, (Vec4 *)v0, 1.0f);
    d = func_0038CE68(v0, obj + 0xC0);
    if (d <= 0.0f) {
        f5 = D_001DE3D4_sda;
        f3 = D_001DE3DC_sda;
    } else {
        d = d * D_001DE3D0_sda;
        if (1.0f < d) {
            d = 1.0f;
        }
        f5 = D_001DE3D4_sda + (D_001DE3C8_sda - D_001DE3D4_sda) * d;
        f3 = D_001DE3DC_sda + (D_001DE3D8_sda - D_001DE3DC_sda) * d;
    }
    f1 = *(f32 *)(m + 0xC6C);
    k = ((f1 + 1.0f) + f1) * 0.33333334f;
    f5 = f5 * f1;
    f3 = f3 * k;
    v50 = 0;
    ret = 0;
    func_003C41A0(&v50, m + 0xD18, f21, f3 * 0.0004f, f3 * 0.0004f, f5 * 0.0200000014f);
    fnew = func_L01_003ABD60(m, path, &idx, *(f32 *)(m + 0xD14), *(f32 *)(m + 0xD18));
    *(f32 *)(m + 0xD14) = fnew;
    reached = 0;
    if (idx >= *(s32 *)path - 1) {
        idx = *(s32 *)path - 1;
        reached = 1;
    }
    frac = fnew - (f32)idx;
    if (reached != 0 && 1.0f <= frac) {
        if (obj[0x20] == 5 && *(s32 *)(m + 0xC54) != 0) {
            if (func_0038CF00(obj + 0x10, path + 0x10) < D_001DE3C4_sda) {
                *(f32 *)(m + 0xD14) = *(f32 *)(m + 0xD14) - (f32)(*(s32 *)path - 1);
                vcopy4_3AC000(m + 0xD60, path + 0x10);
                *(f32 *)(m + 0xD6C) = -1.0f;
            } else {
                *(f32 *)(m + 0xD14) = *(f32 *)(m + 0xD14) - (f32)*(s32 *)path;
                vcopy4_3AC000(m + 0xD60, obj + 0x10);
                *(f32 *)(m + 0xD6C) = func_0038CF00(obj + 0x10, path + 0x10);
            }
            t = *(f32 *)(m + 0xD14);
            idx = (s32)t;
            frac = t - (f32)idx;
        } else {
            ret = 2;
            frac = 1.0f;
            *(f32 *)(m + 0xD14) = fnew - *(f32 *)(m + 0xD18) / *(f32 *)(path + 0x10 + idx * 16 + 0xC);
        }
    }
    func_L01_003ABE88(m, path, idx, obj + 0x10, frac);

    st = obj[0x20];
    mode = 0;   /* 0: aim at the target point, 1: aim at the path end, 2: follow the path, 3: stopped at the path end */
    if (*(s32 *)(m + 0xC4C) != 0 && *(s16 *)(m + 0x44) == 1) {
        vsub3_3AC000(v0, m + 0x30, obj + 0x10);
        func_L01_003ABF48(obj, m, v10, &ang[0], &ang[1]);
        t = func_0038DAB8(ang[1], -func_0038D160(func_0038CED8(v0), v0[2]));
        ang[1] = t;
        lim = D_001DE3F0_sda * 0.0174532924f;
        if (lim < t) {
            ang[1] = lim;
        } else if (t < -lim) {
            ang[1] = -lim;
        }
        ang[2] = func_0038D160(v0[0], v0[1]);
    } else {
        if (st == 5) {
            mode = (*(s32 *)(m + 0xC58) != 0) ? 1 : 4;
        } else if (idx < *(s32 *)path - *(s32 *)(m + 0xCA0 + *(s32 *)(m + 0xD0C) * 4)) {
            mode = 4;
        } else {
            mode = 3;
        }
        if (mode == 4) {
            t = *(f32 *)(m + 0xD6C);
            mode = 2;
            if ((0.0f < t && idx == -1) || (t < 0.0f && idx == 0)) {
                if (!(st == 5 && *(s32 *)(m + 0xC70) == -1 && idx == -1)) {
                    mode = 1;
                }
            }
        }
        if (mode == 3) {
            func_L01_003ABF48(obj, m, v10, &ang[0], &ang[1]);
            ang[0] = -ang[0];
            ang[1] = -ang[1];
            ang[0] = func_0038DAB8(ang[0], *(f32 *)(ent + 0x70));
            lim = D_001DE3F0_sda * 0.0174532924f;
            if (lim < ang[1]) {
                ang[1] = lim;
            } else if (ang[1] < -lim) {
                ang[1] = -lim;
            }
            ang[1] = func_0038DAB8(ang[1], *(f32 *)(ent + 0x74));
            ang[2] = *(f32 *)(ent + 0x78);
        } else if (mode == 1) {
            func_L01_003ABF48(obj, m, v10, &ang[0], &ang[1]);
            ang[0] = func_0038DAB8(ang[0], *(f32 *)(ent + 0x70));
            lim = D_001DE3F0_sda * 0.0174532924f;
            if (lim < ang[1]) {
                ang[1] = lim;
            } else if (ang[1] < -lim) {
                ang[1] = -lim;
            }
            ang[1] = func_0038DAB8(ang[1], *(f32 *)(ent + 0x74));
            ang[2] = *(f32 *)(obj + 0xF8);
        } else {
            f1 = *(f32 *)(m + 0xD18) * D_001DE3E0_sda;
            if (D_001DE3E4_sda < f1) {
                f1 = D_001DE3E4_sda;
            } else if (f1 < D_001DE3E8_sda) {
                f1 = D_001DE3E8_sda;
            }
            t = func_L01_003ABD60(m, path, &idx, *(f32 *)(m + 0xD14), f1);
            idx = (s32)t;
            func_L01_003ABE88(m, path, idx, v30, t - (f32)idx);
            vsub3_3AC000(v40, v30, obj + 0x10);
            ang[0] = 0.0f;
            t = -func_0038D160(func_0038CED8(v40), v40[2]);
            ang[1] = t;
            lim = D_001DE3F0_sda * 0.0174532924f;
            if (lim < t) {
                ang[1] = lim;
            } else if (t < -lim) {
                ang[1] = -lim;
            }
            ang[2] = func_0038D160(v40[0], v40[1]);
        }
    }
    func_L01_00448890(obj + 0xF4, m + 0xD54, 0, ang[1],
                      D_001DE3F4_sda * 0.0174532924f * 0.0004f, D_001DE3F8_sda * 0.0174532924f * 0.0200000014f);
    func_L01_00448890(obj + 0xF8, m + 0xD58, 0, ang[2],
                      D_001DE3FC_sda * 0.0174532924f * 0.0004f, D_001DE400_sda * 0.0174532924f * 0.0200000014f);
    t = func_0038DAB8(ang[0], *(f32 *)(m + 0xD58) * *(f32 *)(m + 0xD18) * D_001DE410_sda);
    ang[0] = t;
    lim = D_001DE404_sda * 0.0174532924f;
    if (lim < t) {
        ang[0] = lim;
    } else if (t < -lim) {
        ang[0] = -lim;
    }
    func_L01_00448890(obj + 0xF0, m + 0xD50, 0, ang[0],
                      D_001DE40C_sda * 0.0174532924f * 0.0004f, D_001DE408_sda * 0.0174532924f * 0.0200000014f);
    vcopy4_3AC000(ang, ent + 0x70);
    if (ret == 2) {
        if (D_001DE3EC_sda < fabs_asm(func_0038DBA0(*(f32 *)(obj + 0xF0), ang[0])) ||
            D_001DE3EC_sda < fabs_asm(func_0038DBA0(*(f32 *)(obj + 0xF4), ang[1])) ||
            D_001DE3EC_sda < fabs_asm(func_0038DBA0(*(f32 *)(obj + 0xF8), ang[2]))) {
            ret = 1;
        }
    }
    return ret;
}
