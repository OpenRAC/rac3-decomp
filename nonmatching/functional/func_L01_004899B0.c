/* functional: high. functional: layout only */
extern u8 *D_001D52FC;
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_005170B8(s32, u32);

void func_L01_004899B0(void) {
    s32 b = *(s32 *)(D_001D52FC + 0x1C4);

    if (b & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001D883C = D_L01_001D883C - 1;
        if (D_L01_001D883C < 0) {
            D_L01_001D883C = 3;
        }
    } else if (b & 0x4000) {
        func_003A5348(3, 0, 0);
        D_L01_001D883C = D_L01_001D883C + 1;
        if (D_L01_001D883C >= 4) {
            D_L01_001D883C = 0;
        }
    } else if (b & 0x8000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8838 = D_L01_001D8838 - 1;
        if (D_L01_001D8838 < 0) {
            if (D_L01_001D883C < 2) {
                D_L01_001D8838 = 4;
            } else {
                D_L01_001D883C = D_L01_001D883C - 2;
                D_L01_001D8838 = 3;
                D_L01_001D8848 = 1;
            }
        }
    } else if (b & 0x2000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8838 = D_L01_001D8838 + 1;
        if (D_L01_001D8838 >= 5) {
            D_L01_001D8838 = 0;
            if (D_L01_001D883C >= 2) {
                D_L01_001D883C = D_L01_001D883C - 2;
                D_L01_001D8848 = 1;
            }
        }
    } else {
        return;
    }
    func_L01_005170B8(0x19000E, 0x402299DE);
    func_L01_005170B8(0x19000F, 0x402299DE);
}
