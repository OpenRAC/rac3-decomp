/* functional: high. Not necessarily byte-exact; calls and args follow PAL asm (n twice, count 5, widths from gp, shift 0.2). */
extern s16 D_L01_001E18D0[];
extern s16 D_L01_001E18D8[];
extern f32 D_L01_001E18F8[];
extern vu0_v4 D_L01_00278E20[];
extern f32 D_001DD140_sda;
extern f32 D_001DD144_sda;
__asm__(".extern D_001DD140_sda, 4");
__asm__(".extern D_001DD144_sda, 4");
extern void func_L01_00340670(vu0_v4 *, s32, s32, s32, f32, f32, f32);

void func_L01_003405B8(void) {
    s32 i;
    s32 n;

    for (i = 0; i < 4; i++) {
        if (D_L01_001E18D0[i] != 0) {
            n = (s32)((f32)D_L01_001E18D8[i] * D_L01_001E18F8[0]);
            func_L01_00340670(&D_L01_00278E20[i * 5], n, n, 5, D_001DD140_sda, D_001DD144_sda, 0.2f);
        }
    }
}
