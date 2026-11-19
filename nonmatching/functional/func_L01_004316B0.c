/* functional: high. Rewritten from the PAL asm. Matches retail logic and call order; checker diff is scheduling only. */
extern s32 D_001D545C;
extern s32 func_L01_00431608(s32, f32 *, s32);

void func_L01_004316B0(f32 x, f32 y, f32 *outX, f32 *outY, s32 level, s32 arg) {
    f32 m[4];
    s32 lv;
    lv = (level != -1) ? level : D_001D545C;
    if (lv < 0) lv = 0;
    func_L01_00431608(lv < 61 ? lv : 0, m, arg);
    *outX = (m[0] + m[1] * x) * 0.001953125f;
    *outY = (m[2] + m[3] * y) * 0.001953125f;
}
