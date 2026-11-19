/* functional: high. 170 diff at default flags (register allocation, one more saved reg in retail); callee arg 3 passed as pointer c; all branches traced */
extern void func_L01_0045E010(u8 *, u8 *, s32, u8 *);
extern f32 func_L01_00451738(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00451020(void *, void *, f32);
extern void func_0038CF68(f32, void *, void *);
extern void func_L01_004510A8(void *, void *, void *, f32, s32);
extern f32 func_0038CE68(void *, void *);
extern void func_003C4BB0(void *, f32);
extern f32 func_L01_004510F8(void *, void *, s32);
extern void func_L01_00451388(void *, void *, void *, f32);
extern f32 func_003C50E8(u8 *, u8 *, void *);
extern void func_003C4360(void *, f32, f32, f32, f32);

void func_L01_0045D788(u8 *a, u8 *o, u8 *b, s32 c, void *v3, void *v4, void *mpv) {
    f32 v0[4];
    f32 v1[4];
    f32 t;
    f32 g;
    f32 lim;
    u8 *mp = (u8 *)mpv;
    u8 *pos;

    if ((*(s32 *)(o + 0x38) & 0x10) == 0) {
        func_L01_0045E010(a, o, c, mp);
    }
    g = 0.0f;
    if ((*(s32 *)(o + 0x38) & 0x10) == 0) {
        g = func_L01_00451738(a, c, (s32)mp);
    }
    if (*(f32 *)(o + 0x30) < g) {
        qzero(v0);
        *(s32 *)(o + 0x9C) |= 2;
    } else {
        *(s32 *)(o + 0x9C) &= -3;
        g = func_0038CF00(a + 0x10, b);
        *(f32 *)(o + 0xCC) = g;
        if (g <= *(f32 *)(o + 0x34)) {
            qzero(v0);
        } else {
            lim = sqrt_asm((g - *(f32 *)(o + 0x34)) * 2.0f * *(f32 *)(o + 0x24));
            if (*(f32 *)(o + 0x28) < lim) {
                lim = *(f32 *)(o + 0x28);
            }
            func_L01_00451020(a, v0, lim);
        }
    }
    if (*(s32 *)(o + 0x38) & 0x10) {
        lim = sqrt_asm((*(f32 *)(o + 0xCC) - *(f32 *)(o + 0x34)) * 2.0f * *(f32 *)(o + 0x24));
        func_0038CF68(lim, v0, (void *)c);
    }
    vec_sub_ab(v1, v0, o + 0xA0);
    func_L01_004510A8(a, v1, v1, 0.0f, (s32)mp);
    pos = o + 0xA0;
    if (0.0f < func_0038CE68(v0, pos)) {
        func_003C4BB0(v1, *(f32 *)(o + 0x20));
    } else {
        func_003C4BB0(v1, *(f32 *)(o + 0x24));
    }
    vec_add_ab(o + 0xA0, o + 0xA0, v1);
    *(f32 *)(o + 0xB0) = func_L01_004510F8(a, pos, (s32)mp);
    if (*(s32 *)(o + 0x38) & 4) {
        return;
    }
    if (*(f32 *)(o + 0x90) < 0.0f) {
        func_L01_00451388(a, pos, pos, *(f32 *)(o + 0x2C));
        if (*(s16 *)(o + 0xC0) == 0) {
            *(s32 *)(o + 0x94) |= 0x20;
        }
    } else {
        g = func_003C50E8(a, pos, mp);
        if (*(f32 *)(o + 0x90) < g) {
            t = *(f32 *)(o + 0x90);
        } else {
            t = g;
            if (g < 0.0f) {
                t = 0.0f;
            }
        }
        func_003C4360(&t, *(f32 *)(o + 0x90), 0.016f, 0.016f, 1.0f);
        func_L01_004510A8(a, pos, pos, t, (s32)mp);
    }
}
