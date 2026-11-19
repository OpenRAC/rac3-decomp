/* functional: high. 73 diff at level 01 (loop shape/regalloc); same ring-buffer probe, stores and return. */
extern s32 D_001E00C8;
extern s32 D_001E005C;
extern s32 D_001E001C;
extern u32 D_0021DE20[];
extern u8 D_0021E260[];

s32 func_L01_0043B618(u8 *obj) {
    s32 n = 0;
    s32 r;
    s32 slot;
    u8 *entry;

    while (D_0021DE20[D_001E005C + (D_001E00C8 + n) % 32] != 0) {
        n++;
        if (n >= 32) {
            break;
        }
    }
    if (n == 32) {
        return 0xFF;
    }
    r = (D_001E00C8 + n) % 32;
    slot = D_001E005C + (D_001E00C8 + n) % 32;
    entry = D_0021E260 + r * 48;
    D_001E00C8 = (r + 1) % 32;
    *(u16 *)entry = (((s32)obj - D_001E001C) >> 8) | 0x8000;
    D_0021DE20[slot] = (u32)entry;
    obj[0x21] = slot;
    return slot;
}
