/* functional: high. Rewritten from PAL asm; behaviour identical, constant-load style differs. */
/* localdecomp:start func_L01_004C1D38 */
extern s32 func_L01_004C1CE0(s32, s32, s32, f32, f32);

s32 func_L01_004C1D38(s32 message) {
    if (message == 0x1B8 || message == 0x17F4) {
        return func_L01_004C1CE0(message, 0, 0, 0.65f, 0.25f);
    } else if (message == 0x17FD) {
        return func_L01_004C1CE0(0x17FD, 0x40, 1, 0.65f, 0.13f);
    } else if (message == 0x1804) {
        return func_L01_004C1CE0(0x1804, 0x40, 1, 0.65f, 0.16f);
    } else if (message == 0x1803) {
        return func_L01_004C1CE0(0x1803, 0x40, 1, 0.65f, 0.16f);
    } else if (message == 0x1802) {
        return func_L01_004C1CE0(0x1802, 0x40, 1, 0.65f, 0.16f);
    } else if (message == 0x17F7) {
        return func_L01_004C1CE0(0x17F7, 0x40, 1, 0.65f, 0.32f);
    } else {
        return func_L01_004C1CE0(message, 0x40, 1, 0.65f, 0.26f);
    }
}
/* localdecomp:end func_L01_004C1D38 */
