/* functional: high. compiles; 150 diff lines at level_01 (stack layout/regalloc); semantics read block by block; unknown callees named by address only */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_00445170(void *, s32);
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_L01_003ACFA8(void *, void *, void *, void *);

void func_L01_003AD010(u8 *obj, u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    f32 dir[4] __attribute__((aligned(16)));
    f32 p10[4] __attribute__((aligned(16)));
    f32 d20[4] __attribute__((aligned(16)));
    f32 a30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    f32 m70[16] __attribute__((aligned(16)));
    f32 mA0[16] __attribute__((aligned(16)));
    f32 mD0[16] __attribute__((aligned(16)));
    f32 s100[4] __attribute__((aligned(16)));
    f32 ang;
    f32 f4;
    f32 d;
    f32 lo;
    s32 n;
    s32 i;
    s32 st;
    s32 active;
    u8 *e;
    u8 *o;

    if (*(s32 *)(pv + 8) == 0) {
        return;
    }
    ang = func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(pv + 0x1C));
    dir[0] = func_0038D098(ang);
    dir[1] = func_0038D0B0(ang);
    dir[2] = 0.0f;
    func_0038D000(p10, m + 0xD90, obj + 0xC0);
    vec_add_ab(p10, p10, obj + 0x10);
    vec_sub_ab(v40, m + 0x70, p10);
    vec_copy(v50, v40);
    v50[2] = 0.0f;
    func_0038CF68(v50, v50, 1.0f);

    active = 0;
    if (obj[0x20] >= 2 && *(s32 *)(m + 0xCE0) != 0) {
        if (*(s32 *)(m + 0xCEC) > 0) {
            active = 1;
        } else if (obj[0x95] != 3 && *(s16 *)(m + 0x44) == 1) {
            if (!(v50[0] * dir[0] + v50[1] * dir[1] < *(f32 *)(pv + 0x20))) {
                active = 1;
            }
        }
    }
    if (!active) {
        func_0038CAD0(m + 0xC60);
        if (*(s32 *)(m + 0xC60) < *(s32 *)(pv + 0x24)) {
            *(s32 *)(m + 0xC60) = *(s32 *)(pv + 0x24);
        }
        n = *(s32 *)(pv + 8);
        e = *(u8 **)(pv + 0xC);
        for (i = 0; i < n; i++) {
            o = m + 0xA0 + (*(s32 *)(e + 4) << 7);
            qzero(o + 0x60);
            func_L01_0044E850(*(void **)(m + 0x64), o, *(s32 *)e, 0.0432f, 0.43200004f);
            e += 0x18;
            n = *(s32 *)(pv + 8);
        }
        return;
    }
    st = obj[0x95];
    if (st == 3) {
        func_0038CAD0(m + 0xC60);
        if (*(s32 *)(m + 0xC60) < *(s32 *)(pv + 0x24)) {
            *(s32 *)(m + 0xC60) = *(s32 *)(pv + 0x24);
        }
    } else {
        if (func_0038CAD0(m + 0xC60) != 0 && obj[0x95] != 2) {
            func_L01_00445170(obj, 2);
        }
    }
    d = func_0038CED8(v40);
    lo = *(f32 *)(pv + 0x28) * 0.5f + *(f32 *)(pv + 0x2C);
    if (d < lo) {
        f4 = *(f32 *)(pv + 0x2C) - d;
    } else {
        f4 = *(f32 *)(pv + 0x28) * -0.5f;
    }
    if (*(s32 *)(m + 0xCEC) > 0) {
        f4 = f4 + *(f32 *)(pv + 0x28) * (1.0f - (f32)*(s32 *)(m + 0xCEC) / (f32)*(s32 *)(m + 0xCE0));
    }
    func_0038CE20(s100, v50, f4);
    vec_add_ab(v60, s100, m + 0x70);
    func_L01_0040EE50(mD0, obj + 0xC0);
    qzero(a30);
    n = *(s32 *)(pv + 8);
    e = *(u8 **)(pv + 0xC);
    for (i = 0; i < n; i++) {
        o = m + 0xA0 + (*(s32 *)(e + 4) << 7);
        func_003C2F58(*(void **)(m + 0x64), *(s32 *)e, p10);
        vec_sub_ab(d20, v60, p10);
        a30[1] = -func_0038D160(func_0038CED8(d20), d20[2]);
        a30[2] = func_0038D160(d20[0], d20[1]);
        func_0038D308(m70, a30);
        func_0038D5F0(mA0, mD0, m70);
        func_003C48A8(mA0, o + 0x60);
        func_L01_003ACFA8(obj, m, e, o + 0x60);
        func_L01_0044E850(*(void **)(m + 0x64), o, *(s32 *)e, 0.0432f, 0.43200004f);
        e += 0x18;
        n = *(s32 *)(pv + 8);
    }
}
