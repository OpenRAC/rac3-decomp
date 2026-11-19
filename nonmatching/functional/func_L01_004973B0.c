/* functional: high. Compiles at level_01 with --no-context (60 diff); the file context declares it extern void func_L01_004973B0(void) (src line 334), so that declaration must become (s32, f32 *) when landing. */
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;

extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00518110(s32, s32, s32, s32);

void func_L01_004973B0(s32 a, f32 *r) {
    f32 off = r[3] * 0.25f;

    func_003E8FE8(0x470019, 0, 0x8066CCFF, r[0], r[1] - off, 0.85f, 0.85f);
    func_L01_00516AA0(0x470019, 0x40, 1);
    func_003E8FE8(0x47001A, 0, 0x8066CCFF, r[0], r[1] + off, 0.85f, 0.85f);
    func_L01_00516AA0(0x47001A, 0x40, 1);
    func_003E9270(0x470018, 0x332299DE, r[0], r[1], r[2], r[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_L01_00518110(a, 0x470018, 0x470019, 0x47001A);
}
