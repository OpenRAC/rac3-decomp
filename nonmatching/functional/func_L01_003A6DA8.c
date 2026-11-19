/* functional: high. Same walk; only register allocation expected to differ */
extern u16 *D_L01_0021DE20_003A4320[];
extern u8 *D_L01_001E001C_003A4320;
extern s32 D_L01_001E0058_003A4320;

void func_L01_003A6DA8(u8 *obj, u8 *parent, s32 group) {
    u8 *v = *(u8 **)(obj + 0x68);
    u16 *p;
    u8 *m;
    s32 i;
    s32 j;
    *(s32 *)(v + 0x318) = parent != 0 ? ((s32)parent - (s32)D_L01_001E001C_003A4320) >> 8 : -1;
    if (group != 255) {
        p = D_L01_0021DE20_003A4320[group];
        i = 0;
        while ((group & 255) != 255 && group <= D_L01_001E0058_003A4320 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L01_0021DE20_003A4320[group])) {
            m = D_L01_001E001C_003A4320 + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            *(s32 *)(v + 0x360 + i * 4) = ((s32)m - (s32)D_L01_001E001C_003A4320) >> 8;
            i++;
            *(u16 *)(m + 0x34) |= 2;
            p++;
        }
    } else {
        for (j = 9; j >= 0; j--) {
            *(s32 *)(v + 0x360 + j * 4) = -1;
        }
    }
}
