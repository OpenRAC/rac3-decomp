/* functional: high. Plain C float math for the VU0 xyz adds (w lanes untouched, as retail's vadd.xyz); behaviour traced block by block against PAL asm; the old x/y cvt reads happen before the position add as in retail */
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_L01_001E02A0[];
__asm__(".extern D_L01_001E02A0, 16");
extern f32 D_L01_001E02B0;
__asm__(".extern D_L01_001E02B0, 16");
extern void func_003CD250(u8 *);
extern f32 func_L01_00451768(void *);

void func_L01_00463038(u8 *p) {
    u8 *vars = p + 0x30;
    f32 delta[4] __attribute__((aligned(16)));
    f32 first[4] __attribute__((aligned(16)));
    f32 second[4] __attribute__((aligned(16)));
    f32 *pos = (f32 *)(p + 0x20);
    f32 *vel = (f32 *)(p + 0x10);
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
    delta[0] = *(f32 *)(vars + 0) + D_L01_001E02A0[0];
    delta[1] = *(f32 *)(vars + 4) + D_L01_001E02A0[1];
    delta[2] = *(f32 *)(vars + 8) + D_L01_001E02A0[2];
    delta[3] = *(f32 *)(vars + 12);
    x = (s32)pos[0];
    y = (s32)pos[1];
    pos[0] += delta[0];
    pos[1] += delta[1];
    pos[2] += delta[2];
    vel[0] += delta[0];
    vel[1] += delta[1];
    vel[2] += delta[2];
    if (*(s16 *)(p + 10) != 2 && (x != (s32)pos[0] || y != (s32)pos[1])) {
        first[0] = pos[0]; first[1] = pos[1]; first[2] = pos[2]; first[3] = pos[3];
        if (func_L01_00451768(first) < D_L01_001E02B0) {
            floor = D_L01_001E02B0;
        } else {
            second[0] = pos[0]; second[1] = pos[1]; second[2] = pos[2]; second[3] = pos[3];
            floor = func_L01_00451768(second);
        }
        if (*(f32 *)(p + 40) < floor) {
            func_003CD250(p);
            return;
        }
    }
    *(f32 *)(vars + 8) -= 0.003920000046491623f;
    *(f32 *)(vars + 12) = floor + D_L01_001E02A0[2];
}
