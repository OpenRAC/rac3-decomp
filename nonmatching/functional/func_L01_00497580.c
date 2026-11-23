/* functional: high. Compiles at level_01 with --no-context (49 diff); context declares it extern void func_L01_00497580(void) (src line 349), so that declaration must become (s32, f32 *). */
extern s32 D_L01_001D9210;
extern s32 D_L01_001D9214;
extern s32 D_L01_001D9218;
extern s32 D_L01_001D921C;
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;

extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_00497580(s32 a, f32 *r) {
    func_003E9138(0x47001C, 0x80808080, 0, r[0] + (f32)D_L01_001D9210 * 0.001953125f, r[1] + (f32)D_L01_001D9214 / 416.0f,
                  r[2] + (f32)D_L01_001D9218 * 0.001953125f, r[3] + (f32)D_L01_001D921C / 416.0f);
    func_003E9270(0x47001B, 0x332299DE, r[0], r[1], r[2], r[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8A08(a, 0x47001B, 0x47001C);
}
