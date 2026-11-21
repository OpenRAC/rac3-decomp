/* functional: high. Constants 0.002f and 0.03846154f read from the PAL asm bit patterns. */
extern u8 *D_001D52FC;
extern f32 D_L01_001D8CA4;
extern f32 D_L01_001D8C98;
extern f32 D_L01_001D8CA8;
extern s32 D_L01_001D8C80;
extern s32 D_L01_001D8C7C;
extern s32 D_L01_001D8C78;
extern s32 D_L01_001E092C;
extern f32 D_L01_001E0928;
extern s32 D_L01_001E0934;
extern f32 D_L01_001E0930;
extern s32 D_L01_001E0954[];
extern s32 D_L01_001E0958[];
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_003BB590(s32);

void func_L01_0048EA10(void) {
    s32 buttons;

    if (D_L01_001E092C == 0) {
        D_L01_001E092C = 1;
        D_L01_001E0928 = (D_L01_001D8CA4 + D_L01_001D8C98) + 0.00200000009f;
    }
    if (D_L01_001E0934 == 0) {
        D_L01_001E0934 = 1;
        D_L01_001E0930 = D_L01_001D8C98 + 0.0384615399f;
    }
    buttons = *(s32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001E0954[0] = 0x11;
        D_L01_001D8C80 = D_L01_001D8C80 - 1;
        if (D_L01_001D8C80 < 0) {
            D_L01_001D8C80 = 0;
            if (D_L01_001D8C7C - 1 >= 0) {
                D_L01_001E0958[0] = 2;
            }
        }
    } else if (buttons & 0x4000) {
        if (D_L01_001D8C80 < D_L01_001D8C78 - 1) {
            func_003A5348(3, 0, 0);
            D_L01_001E0954[0] = 0x11;
            D_L01_001D8C80 = D_L01_001D8C80 + 1;
            if (D_L01_001D8C80 >= 3) {
                D_L01_001D8C80 = 2;
                if (D_L01_001D8C7C + 1 <= D_L01_001D8C78 - 3) {
                    D_L01_001E0958[0] = 1;
                }
            }
        }
    }
    func_L01_00516470(0x160008, D_L01_001D8CA8, D_L01_001E0928 + (f32)D_L01_001D8C80 * D_L01_001E0930);
    func_003BB590(0x160008);
}
