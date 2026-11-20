/* functional: medium. Rewritten from PAL asm; the flag word at gp+0x46D0 is declared small-data so it is gp-relative as in retail. */
/* localdecomp:start func_L01_004C1460 */
extern s32 D_001E0F80_sda;
__asm__(".extern D_001E0F80_sda, 4");
extern s32 D_L01_001E0F7C[];
extern u8 D_L01_002F1D18[];
extern f32 func_0038D098(f32);
extern f32 func_L01_004451A8(f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_005170B8(s32, u32);
extern void func_L01_004C13B0(s32, Ent4BD808 *);

void func_L01_004C1460(s32 a0) {
    f32 t, sn, half, k, c1, c2, c3, c4;
    s32 alpha, i;

    D_001E0F80_sda = 1;
    if (a0 != 0) {
        t = 1.0f - (f32)D_L01_001E0F7C[0] / 12.0f;
    } else {
        t = (f32)D_L01_001E0F7C[0] / 15.0f;
    }
    if (1.0f < t) t = 1.0f;
    else if (t < 0.0f) t = 0.0f;

    sn = func_0038D098(t * 3.1415927f);
    k = (1.0f - sn) * 0.5f;
    alpha = (s32)(func_L01_004451A8(t) * 128.0f);
    c1 = func_003C4088(0.65f, 0.45f, k);
    for (i = 0; i < 2; i++) {
        func_L01_00516470(0x480005 + i, 0.5f, c1);
        func_L01_00516470(0x480009 + i, 0.5f, c1);
        func_L01_00516470(0x48000D + i, 0.5f, c1);
    }
    c2 = func_003C4088(0.25f, 0.45f, k) - 0.187f;
    for (i = 2; i < 4; i++) {
        func_L01_00516470(0x480005 + i, 0.5f, c2);
        func_L01_00516470(0x480009 + i, 0.5f, c2);
        func_L01_00516470(0x48000D + i, 0.5f, c2);
    }
    func_L01_005170B8(0x480012, (alpha << 24) | 0x1465B7);
    func_L01_00517538(0x480012, 0.84f, k * 0.56f);
    func_L01_004C13B0(alpha, (Ent4BD808 *)D_L01_002F1D18);
    func_L01_00516AA0(0x480026, 1, 0);
    func_L01_00518590(0x480004, 1, 1);
    c3 = (c1 + c2) * 0.5f;
    func_L01_00516470(0x480004, 0.5f, c3);
    func_L01_00517538(0x480004, 1.0f, func_003C4088(0.145f, 0.57f, k));
    func_L01_00518590(0x480003, 1, 1);
    func_L01_00516470(0x480003, 0.5f, c3);
    func_L01_00517538(0x480003, 1.0f, func_003C4088(0.13f, 0.57f, k));
}
/* localdecomp:end func_L01_004C1460 */
