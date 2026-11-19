/* functional: high. Compiles at level_01 with --no-context (12 diff, only s2/s3 callee-saved register swap of the loop index vs the second handle; tried 4 declaration/loop variants). Context declares it (s32 a, s32 b); b is the f32[4] rect pointer, so the signature here (s32, f32 *) needs the declaration at src line 240 adjusted or a cast. */
extern f32 D_L01_001D9238;
extern f32 D_L01_001D923C;
extern f32 D_L01_001D9240;
extern f32 D_L01_001D9244;
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern f32 D_L01_001D9248;
extern f32 D_L01_001D9234;
extern f32 D_L01_001D9230;

extern void func_003E8630(s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L01_004978A8(s32 a, f32 *r) {
    s32 i;
    s32 h;
    s32 h2;
    f32 step;
    f32 fi;

    func_003E9138(0x470023, 0x332299DE, 0, D_L01_001D9238, D_L01_001D923C, D_L01_001D9240, D_L01_001D9244);
    func_003E8630(a, 0x470023);
    func_003E9270(0x470022, 0x332299DE, r[0], r[1], r[2], r[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8630(a, 0x470022);
    step = r[3] / 5.0f - D_L01_001D9248;
    i = 0;
    do {
        fi = (f32)i;
        h = 0x470024 + i;
        h2 = 0x47002A + i;
        func_003E8FE8(h, 0, 0x8066CCFF, r[0], r[1] + step * (fi - 2.0f), 1.0f, 1.0f);
        func_L01_00516AA0(h, 0x40, 1);
        if (i > 0) {
            func_003E9138(h2, 0x202299DE, 0, r[0], r[1] + step * (fi - 2.5f), r[2] - D_L01_001D9234 * 0.001953125f, D_L01_001D9230);
            func_003E8A08(a, h, h2);
        } else {
            func_003E8630(a, h);
        }
        i++;
    } while (i < 5);
}
