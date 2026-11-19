/* functional: high. 4 diff at default flags (a1/s1 move order of the o+0xA0 pointer only); passes o+0xB0 in f12 to func_L01_00451048 as retail does */
extern vu0_q D_L01_001E0240[] __attribute__((section(".sdata")));
extern s32 func_L01_0045DF48(u8 *, u8 *);
extern f32 func_L01_004510F8(void *, void *, s32);
extern void func_L01_00451048(void *, void *, void *, s32, f32);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern void func_L01_004510A8(void *, void *, void *, f32, s32);

void func_L01_0045DA60(u8 *a, u8 *o, void *v4, void *mpv) {
    f32 sv[4];
    s32 mp = (s32)mpv;
    s32 r = 0;
    s32 acc = 0;
    s32 i;
    u8 *p;
    f32 h;

    vec_add_ab(a + 0x10, a + 0x10, o + 0xA0);
    *(vu0_q *)sv = *(vu0_q *)(a + 0x10);
    *(s32 *)(o + 0x84) = 0;
    qzero(o + 0x60);
    for (i = 0; i < 8; i++) {
        r |= func_L01_0045DF48(a, o);
        acc |= r;
        if (r == 0) {
            break;
        }
    }
    if (acc != 0) {
        p = o + 0xA0;
        vec_sub_ab(p, a + 0x10, D_L01_001E0240);
        h = func_L01_004510F8(a, p, mp);
        if (*(f32 *)(o + 0xB0) < h) {
            func_L01_00451048(a, p, p, mp, *(f32 *)(o + 0xB0));
        } else {
            *(f32 *)(o + 0xB0) = h;
        }
        if (0.0f < *(f32 *)(o + 0x90)) {
            func_L01_00450E48(a, a + 0x10, 0.0f, 0.0f, *(f32 *)(o + 0x90));
            func_L01_004510A8(a, p, p, 0.0f, mp);
        }
        if (*(f32 *)(o + 0xB0) < *(f32 *)(o + 0x28) * 0.5f) {
            *(s32 *)(o + 0x80) = *(s32 *)(o + 0x80) + 1;
        } else {
            *(s32 *)(o + 0x80) = 0;
        }
    } else {
        *(s32 *)(o + 0x80) = 0;
    }
    vec_sub_ab(o + 0x70, a + 0x10, sv);
}
