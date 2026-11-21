/* functional: high. Rewritten from PAL asm; scheduling differences only expected. */
/* localdecomp:start func_L01_004BEA70 */
extern S_00244740 D_L01_002446C0[];
extern f32 D_001E0FD0_sda;
extern s32 D_001DAD60_sda;
extern s32 D_001DAD68_sda[];
extern s32 D_00143950[];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0011B868(s32);
extern s32 func_00382468(s32);
extern char *func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
extern void func_L01_004BE6B8(s32, s32, s32, f32, f32, f32);

void func_L01_004BEA70(void) {
    u8 *u = (u8 *)D_L01_002446C0;
    f32 scale;
    s32 base;
    s32 yi;
    s32 n;
    f32 y;

    if (*(s32 *)(u + 0x50) == 2) {
        base = 20;
        scale = 1.0f;
        func_003A9500(0x4B, 0x163, (s32)(D_001E0FD0_sda * 19.0f + 0.5f), (s32)(D_001E0FD0_sda * 36.0f + 0.5f));
    } else {
        base = 60;
        scale = 1.5f;
        func_003A9500(0x50, 0x1B0, (s32)(D_001E0FD0_sda * 56.0f + 0.5f), (s32)(D_001E0FD0_sda * 100.0f + 0.5f));
    }
    if (func_0011B868(*(s32 *)(u + 0x3C)) - *(s32 *)(u + 0x64) / 20 > 0) {
        *(s32 *)(u + 0x64) = *(s32 *)(u + 0x64) + 2;
    } else if (*(s32 *)(u + 0x744) == 0 && *(s32 *)(u + 0x50) != 2) {
        n = func_00382468(12);
        if (n < 6) func_L01_004BC0B8((s32)func_00381FF0(D_001DAD68_sda[n]));
        else func_L01_004BC0B8((s32)func_00381FF0(D_001DAD60_sda));
    }
    yi = (s32)((f32)base * D_001E0FD0_sda + 0.5f);
    y = (f32)yi;
    if (D_00143950[0] != 0) y = (f32)(yi - 2);
    func_L01_004BE6B8(0xF0C070, *(s32 *)(u + 0x3C), -1, (f32)(-*(s32 *)(u + 0x64)), y, scale);
}
/* localdecomp:end func_L01_004BEA70 */
