/* functional: high. Lays out widgets 0x2000A, 0x20009, 0x2000E, 0x2000D and 0x2000F of one multiplayer-menu screen: positions (func_L01_00516470) and sizes (func_L01_00517538) read from the level's float constants D_001D8044_sda..D_001D8070_sda, widget 0x20009's value set to 0.0 (func_L01_005169C8), and widget 0x2000F placed at fixed (0.9265, 0.689). Same call order as retail. */
/* localdecomp:start func_L39_005DB618 */
extern f32 D_001D8044_sda;
extern f32 D_001D8048_sda;
extern f32 D_001D804C_sda;
extern f32 D_001D8050_sda;
extern f32 D_001D8054_sda;
extern f32 D_001D8058_sda;
extern f32 D_001D805C_sda;
extern f32 D_001D8060_sda;
extern f32 D_001D8064_sda;
extern f32 D_001D8068_sda;
extern f32 D_001D806C_sda;
extern f32 D_001D8070_sda;
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L39_005DB618(void) {
    func_L01_00516470(0x2000A, D_001D8044_sda, D_001D8048_sda);
    func_L01_00517538(0x2000A, D_001D804C_sda, D_001D8050_sda);
    func_L01_00516470(0x20009, D_001D8054_sda, D_001D8058_sda);
    func_L01_00517538(0x20009, D_001D805C_sda, D_001D8060_sda);
    func_L01_005169C8(0x20009, 0.0f);
    func_L01_00516470(0x2000E, D_001D8064_sda, D_001D8068_sda);
    func_L01_00516470(0x2000D, D_001D8064_sda, D_001D8068_sda);
    func_L01_00517538(0x2000E, D_001D806C_sda, D_001D8070_sda);
    func_L01_00517538(0x2000D, D_001D806C_sda, D_001D8070_sda);
    func_L01_00516470(0x2000F, 0.9265f, 0.689f);
}
/* localdecomp:end func_L39_005DB618 */
