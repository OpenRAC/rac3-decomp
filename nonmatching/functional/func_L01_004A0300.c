/* functional: medium. Written from asm; companion of func_L01_0049FBC8; meaning of the tables unknown */
extern u8 D_002ED730[];
extern s32 D_001E0CD0[];
extern u8 D_00143950[];
extern s32 D_001D9570_sda;
__asm__(".extern D_001D9570_sda, 4");

void func_L01_004A0300(void) {
    s32 i = 0;
    s32 m = D_001E0CD0[0];
    u8 *base = D_00143950 + m * 16;
    s32 v = *(s32 *)(base + 0x74);
    s32 b6, b7;

    *(s32 *)(D_002ED730 + 0x60) = *(s32 *)(base + 0x44);
    *(s32 *)(D_002ED730 + 0x30) = *(s32 *)(base + 0x14);
    D_001D9570_sda = 0;
    if (v < 0x32) {
        *(s32 *)(D_002ED730 + 0x90) = 0;
    } else {
        *(s32 *)(D_002ED730 + 0x90) = (v < 0x58) ? 1 : 2;
    }
    b7 = D_00143950[0xB6];
    b6 = D_00143950[D_001D9570_sda + 0xAE];
    *(s32 *)(D_002ED730 + i * 12 + 0xC0) = b6;
    *(s32 *)(D_002ED730 + i * 12 + 0xF0) = b7;
}
