/* functional: high. Compiles at level_01 (36 diff). Context declares it as (s32 a, s32 b); b is the f32[4] rect pointer. Level data named D_L01_001D91xx as the neighbours do. */
extern f32 D_L01_001D91E4;
extern f32 D_L01_001D91EC;
extern f32 D_L01_001D91E8;

extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_00496F78(s32 a, s32 b) {
    f32 *r = (f32 *)b;

    func_003E8FE8(0x47000F, 0, 0x8066CCFF, r[0], r[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x47000F, 0x40, 1);
    func_003E7F20(0x47000F, 1);
    func_L01_00518010(0x47000F, 1);
    func_003E8898(0x47000F, r[2] * 0.9f, 0.0f);
    func_003E9138(0x470010, 0x202299DE, 0, r[0], r[1] + r[3] + D_L01_001D91E4,
                  r[2] - D_L01_001D91EC * 0.001953125f, D_L01_001D91E8);
    func_003E8A08(a, 0x47000F, 0x470010);
}
