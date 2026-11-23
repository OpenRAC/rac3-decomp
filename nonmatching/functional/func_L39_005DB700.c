/* functional: high. Same layout as func_L39_005DB618 for the other multiplayer-menu screen variant: widget 0x20005 sized (0.5, 0.5) first, then widgets 0x2000A, 0x20009, 0x2000E, 0x2000D positioned and sized from D_001D8074_sda..D_001D80A0_sda, 0x20009's value set to 0.0, and widget 0x2000F placed at fixed (0.9265, 0.572). Same call order as retail. */
/* localdecomp:start func_L39_005DB700 */
extern f32 D_001D8074_sda;
extern f32 D_001D8078_sda;
extern f32 D_001D807C_sda;
extern f32 D_001D8080_sda;
extern f32 D_001D8084_sda;
extern f32 D_001D8088_sda;
extern f32 D_001D808C_sda;
extern f32 D_001D8090_sda;
extern f32 D_001D8094_sda;
extern f32 D_001D8098_sda;
extern f32 D_001D809C_sda;
extern f32 D_001D80A0_sda;
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L39_005DB700(void) {
    func_L01_00517538(0x20005, 0.5f, 0.5f);
    func_L01_00516470(0x2000A, D_001D8074_sda, D_001D8078_sda);
    func_L01_00517538(0x2000A, D_001D807C_sda, D_001D8080_sda);
    func_L01_00516470(0x20009, D_001D8084_sda, D_001D8088_sda);
    func_L01_00517538(0x20009, D_001D808C_sda, D_001D8090_sda);
    func_L01_005169C8(0x20009, 0.0f);
    func_L01_00516470(0x2000E, D_001D8094_sda, D_001D8098_sda);
    func_L01_00516470(0x2000D, D_001D8094_sda, D_001D8098_sda);
    func_L01_00517538(0x2000E, D_001D809C_sda, D_001D80A0_sda);
    func_L01_00517538(0x2000D, D_001D809C_sda, D_001D80A0_sda);
    func_L01_00516470(0x2000F, 0.9265f, 0.572f);
}
/* localdecomp:end func_L39_005DB700 */
