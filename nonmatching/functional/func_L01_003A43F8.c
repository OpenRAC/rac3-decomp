/* functional: high. Dead constant tests dropped; same list walk, same return */
extern u16 *D_L01_0021DE20_003A4320[];
extern u8 *D_L01_001E001C_003A4320;
extern s32 D_L01_001E0058_003A4320;

u8 *func_L01_003A43F8(s32 idx) {
    u16 *p;
    u8 *e;
    u8 id = idx;
    p = D_L01_0021DE20_003A4320[idx];
    if (id == 0xFF) return 0;
    if (D_L01_001E0058_003A4320 < idx) return 0;
    if (p == 0) return 0;
    while (1) {
        e = D_L01_001E001C_003A4320 + ((*p & 0x7FFF) << 8);
        if (e == 0) return 0;
        if (*(s16 *)(e + 0xAA) == 0x18A2 && e[0x20] == 0x10) return e;
        p++;
        if (p == 0) return 0;
        if ((s16)p[-1] >= 0 || p == D_L01_0021DE20_003A4320[idx]) continue;
        return 0;
    }
}
