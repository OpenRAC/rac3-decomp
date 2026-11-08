/* func_L01_0033D780: MATCH at level 01 (+1 other) with --as ps2as; file flags include -mno-split-addresses. Not delivered: gp slot differs per level (01: 0x760, 02: 0x320, ...), 33 of 35 places differ (false fold by data). Scalar for D_L01_001E18B0 (&X) avoids base hoisting; 0.19999999f gives 0x3E4CCCCC. */
extern f32 D_001DD010_sda;
__asm__(".extern D_001DD010_sda, 4");
extern u8 D_L01_001E18B0;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_0033DED0(void *);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0033D780(void *a0) {
    f32 t;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 c0;
    s32 c1;
    s32 c2;
    D_001DD010_sda = func_0038DAB8(D_001DD010_sda, 0.15f);
    t = func_0038D098(D_001DD010_sda);
    f20 = (t + 1.0f) * 0.5f;
    f23 = f20 * 0.0625f + 0.0625f;
    f22 = f20 * 0.19999999f + 0.15f;
    f21 = f20 * 0.125f + 0.125f;
    c0 = func_0038DBD8(f20, 0x2F007F00, 0x3F007F00);
    c1 = func_0038DBD8(f20, 0x2F7F7F7F, 0x5F7F7F7F);
    c2 = func_0038DBD8(f20, 0x10003F00, 0x10003F00);
    func_L01_0033DED0(a0);
    func_003D9508(&D_L01_001E18B0, 0x31, c0, 1, f21, 0.125f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0x31, c1, 1, f23, 0.124f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0xB, c2, 1, f22, 0.123f, 0.0f);
}
