/* functional: medium. Rewritten from PAL asm; no draft existed. */
/* localdecomp:start func_L01_004C0888 */
extern S_00244740 D_L01_002446C0[];
extern u8 D_001E7580[];
extern u32 D_001E29D0[];
extern u32 D_001E0FA0[];
extern s32 D_001DF944_sda;
extern s32 D_001DF948_sda;
extern s32 D_001E1070_sda;
extern f32 D_001DAC50_sda;
extern f32 D_001E0FD0_sda;
extern s32 D_001D4BC0_sda;
extern s32 D_L01_001D4BC4;
__asm__(".extern D_L01_001D4BC4, 16");
extern s32 D_001A1ED4[];
extern s32 D_001E0F80_sda;
extern void func_00392350(s32);
extern void func_00388AF8(s32);
extern void func_003A92F0(s32);
extern void func_0012C908(s32);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_L01_00404F00(s32);
extern void func_003861F0(void);
extern void func_0038CBA0(s32, s32);
extern void func_L01_004BF980(void);
extern void func_003873C0(void);
extern void func_L01_004C6030(s32, s32, s32);
extern void func_00389240(s32);
extern void func_00387F68(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003A9440(s32, long);
extern void func_L01_004CB540(s32);
extern void func_L01_00478AA0(void);
extern void func_003B3158(s32);
extern void func_L01_00478AD8(void);
extern void func_L01_004BF518(void);
extern void func_L01_004C3448(void);
extern void func_L01_004BED50(void);
extern void func_L01_004BF948(void);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_L01_004BF538(void);
extern void func_L01_004BF5A0(void);
extern void func_L01_004BF5B8(void);
extern void func_L01_004BF4D0(void);
extern void func_L01_00512BE0(s32, s32, s32, s32);
extern void func_003C3780(s32, s32);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_L01_004BF5B0(void);
extern void func_L01_004BF5F8(void);
extern void func_L01_004BF4F8(void);
extern void func_L01_004BEA70(void);
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
extern void func_003C6F90(s32, s32, s32, s32, s32);
extern void func_L01_004BF578(void);
extern void func_L01_004BF558(void);
extern void func_L01_004BF5A8(void);
extern void func_L01_004BF5D8(void);
extern void func_L01_004BF4F0(void);
extern void func_00389370(void);
extern void func_003C31B0(void);

void func_L01_004C0888(void) {
    u8 *u = (u8 *)D_L01_002446C0;
    s32 mode, m, h, w;
    s32 i;
    f32 f;

    func_00392350(0);
    *(f32 *)(D_001E7580 + 0xB0) = 0.62f;
    mode = *(s32 *)(u + 8);
    if (mode == 0) {
        if (*(s32 *)(u + 0xC) != 0) {
            *(u16 *)(*(u8 **)(u + 0x28) + 0x34) |= 1;
        }
        D_001DF944_sda = 0x100FF;
        if (*(s32 *)(u + 0xC) != 0) D_001DF944_sda = 0x7F;
        func_00388AF8(0);
        *(u16 *)(*(u8 **)(u + 0x28) + 0x34) &= 0xFFFE;
        if (*(s32 *)(u + 0xC) == 0) return;
        *(s32 *)(u + 8) = 1;
        *(s32 *)(u + 0xC) = 0;
        func_003A92F0(1);
        func_0012C908(0);
        D_001DF948_sda = D_001DF948_sda + 1;
        func_003A91D0();
        func_003A9150();
        D_001E1070_sda = 0x60000;
        func_L01_00404F00(*(s32 *)(u + 0x10));
        if (*(s32 *)(u + 0x60) != 0) {
            /* save quads 0..3 of the matrix at D_001E29D0: 0 -> u+0xE0, 1..3 -> D_001E0FA0[0..2], then clear 1..3 and set the diagonal */
            for (i = 0; i < 4; i++) *(u32 *)(u + 0xE0 + i * 4) = D_001E29D0[i];
            for (i = 0; i < 12; i++) D_001E0FA0[i] = D_001E29D0[4 + i];
            for (i = 4; i < 16; i++) D_001E29D0[i] = 0;
            ((f32 *)D_001E29D0)[4] = 1.0f;
            ((f32 *)D_001E29D0)[9] = 1.0f;
            ((f32 *)D_001E29D0)[14] = 1.0f;
            ((f32 *)D_001E29D0)[15] = 1.0f;
            func_003861F0();
        }
        {
            s32 base = *(s32 *)(u + 0x14);
            *(s32 *)(u + 0x2C) = base + 0x1000;
            *(s32 *)(u + 0x20) = base;
            *(s32 *)(u + 0x24) = base + 0x800;
            *(s32 *)(u + 0x3C) = base + 0x2400;
            func_0038CBA0(base + 0x2400, 0x400);
            *(s32 *)(u + 0x90) = 0;
            *(s32 *)(u + 0x8C) = 0;
            *(s32 *)(u + 0x18) = *(s32 *)(u + 0x3C) + 0x400;
            func_L01_004BF980();
        }
    } else if (mode != 1) {
        return;
    }
    /* mode 1 */
    *(f32 *)(D_001E7580 + 0x238) = 255.0f;
    *(f32 *)(D_001E7580 + 0x23C) = 254.0f;
    func_003873C0();
    func_L01_004C6030(*(s32 *)(u + 0x10), D_001A1ED4[0], D_L01_001D4BC4 << 11);
    func_00389240(0);
    func_003861F0();
    func_00387F68();
    if (1.0f <= D_001DAC50_sda && *(u8 *)(u + 0x88) != 0) {
        func_003C36C0();
        func_003C3638();
        func_003C3660();
    }
    func_003A9440(0x42, 0x8000000044L);
    func_L01_004CB540(0);
    func_L01_00478AA0();
    func_003B3158(0);
    func_L01_00478AD8();
    if (1.0f <= D_001DAC50_sda) {
        m = *(s32 *)(u + 0x50);
        if (m == 0) {
            func_L01_004BF518();
            func_L01_004C3448();
            if (D_001E0F80_sda == 0) func_L01_004BED50();
            if (*(s32 *)(u + 0x744) != 0) func_L01_004BF948();
            if (*(u8 *)(u + 0x88) != 0) func_003A9500(0x9E, 0x168, 0x73, 0xCE);
        } else if (m == 3) {
            func_L01_004BF538();
            func_L01_004BF5A0();
            func_L01_004BF5B8();
            if (D_001E0F80_sda == 0) func_L01_004BF4D0();
            if (*(u8 *)(u + 0x88) != 0) {
                func_003A9500(0, D_001D4BC0_sda - 1, 0, D_L01_001D4BC4 - 1);
                func_L01_00512BE0(*(s32 *)(u + 0x2C), *(s32 *)(u + 0x2C) + 0x100, *(s32 *)(u + 0x2C) + 0x200, *(s32 *)(u + 0x2C) + 0x300);
                func_003C3780(*(s32 *)(u + 0x2C), *(s32 *)(u + 0x34));
                func_003C3690();
                func_003C3800();
            }
        } else if (m == 2) {
            func_L01_004BF5B0();
            func_L01_004BF5F8();
            if (D_001E0F80_sda == 0) func_L01_004BF4F8();
            func_L01_004BEA70();
            if (*(u8 *)(u + 0x88) != 0) {
                f = D_001E0FD0_sda;
                func_003A9500(0x38, 0x1C3, (s32)(f * 68.0f + 0.5f), (s32)(f * 245.0f + 0.5f));
                h = func_003825F8(0xFFFFFF, 0x606060, 0x1E, 1, 0, 0);
                if (*(s32 *)(u + 0x54) != -1) func_003C6F90(*(s32 *)(u + 0x2C) + (*(s32 *)(u + 0x54) << 8), h, 0xE, 0xE, 0);
                if (*(s32 *)(u + 0x58) != -1) func_003C6F90(*(s32 *)(u + 0x2C) + (*(s32 *)(u + 0x58) << 8), h, 0xE, 0xE, 0);
                func_003C3780(*(s32 *)(u + 0x2C), *(s32 *)(u + 0x34));
                func_003C3690();
                func_003C3800();
                func_003A9500(0, D_001D4BC0_sda - 1, 0, D_L01_001D4BC4 - 1);
                func_L01_004BF578();
            }
        } else if (m == 5) {
            func_L01_004BF558();
            func_L01_004BF5A8();
            func_L01_004BF5D8();
            if (D_001E0F80_sda == 0) func_L01_004BF4F0();
            if (*(u8 *)(u + 0x88) != 0) {
                func_003A9500(0, D_001D4BC0_sda - 1, 0, D_L01_001D4BC4 - 1);
                func_L01_00512BE0(*(s32 *)(u + 0x2C), *(s32 *)(u + 0x2C) + 0x100, *(s32 *)(u + 0x2C) + 0x200, *(s32 *)(u + 0x2C) + 0x300);
                func_003C3780(*(s32 *)(u + 0x2C), *(s32 *)(u + 0x34));
                func_003C3690();
                func_003C3800();
            }
        }
        func_003A9500(0, D_001D4BC0_sda - 1, 0, D_L01_001D4BC4 - 1);
    }
    func_00389370();
    func_003A92F0(0x10);
    func_003C31B0();
}
/* localdecomp:end func_L01_004C0888 */
