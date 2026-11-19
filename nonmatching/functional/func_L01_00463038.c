/* functional: high. 87 diff at default flags with vec_* helpers (the repo's inline-asm draft had 24); behaviour traced block by block against PAL asm, delay-slot ordering of the cvt reads kept (old position read before the add) */
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern vu0_v4 D_L01_001E02A0_00463038;
extern f32 D_L01_001E02B0_00463038;
__asm__(".extern D_L01_001E02B0_00463038, 16");
extern f32 D_L01_001E02A8_00463038;
__asm__(".extern D_L01_001E02A8_00463038, 16");
extern void func_003CD250(u8 *);
extern f32 func_L01_00451768(void *);

void func_L01_00463038(u8 *p) {
    u8 *vars = p + 0x30;
    vu0_v4 delta;
    vu0_v4 first;
    vu0_v4 second;
    s32 x, y;
    f32 floor = *(f32 *)(vars + 12);

    if (D_001D545C == 15) {
        if (*(f32 *)(p + 24) < floor) {
            func_003CD250(p);
            return;
        }
    } else if (*(f32 *)(p + 24) < floor || *(f32 *)(p + 16) < 0.0f || *(f32 *)(p + 20) < 0.0f ||
               *(f32 *)(p + 16) > 1024.0f || *(f32 *)(p + 20) > 1024.0f) {
        func_003CD250(p);
        return;
    }
    vec_add_ab(&delta, vars, &D_L01_001E02A0_00463038);
    x = (s32)*(f32 *)(p + 32);
    y = (s32)*(f32 *)(p + 36);
    vec_add_ba(p + 32, p + 32, &delta);
    vec_add_ab(p + 16, p + 16, &delta);
    if (*(s16 *)(p + 10) != 2 && (x != (s32)*(f32 *)(p + 32) || y != (s32)*(f32 *)(p + 36))) {
        first = *(vu0_v4 *)(p + 32);
        if (func_L01_00451768(&first) < D_L01_001E02B0_00463038) {
            floor = D_L01_001E02B0_00463038;
        } else {
            second = *(vu0_v4 *)(p + 32);
            floor = func_L01_00451768(&second);
        }
        if (*(f32 *)(p + 40) < floor) {
            func_003CD250(p);
            return;
        }
    }
    *(f32 *)(vars + 8) -= 0.003920000046491623f;
    *(f32 *)(vars + 12) = floor + D_L01_001E02A8_00463038;
}
