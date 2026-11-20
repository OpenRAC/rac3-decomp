/* functional: high. D_L01_* names (and their types) come from the file context; the two not in it carry the function address as suffix. Level data is named D_L01_ (its address differs per level; plain D_ names stood for the same address in every level). 73 diff at level 01 (loop shape/regalloc); same ring-buffer probe, stores and return. */
extern u8 *D_L01_001E001C_0043B618;
extern u8 D_L01_0021E260_0043B618[];

s32 func_L01_0043B618(u8 *obj) {
    s32 n = 0;
    s32 r;
    s32 slot;
    u8 *entry;

    while (D_L01_0021DE20[D_L01_001E005C + (D_L01_001E00C8 + n) % 32] != 0) {
        n++;
        if (n >= 32) {
            break;
        }
    }
    if (n == 32) {
        return 0xFF;
    }
    r = (D_L01_001E00C8 + n) % 32;
    slot = D_L01_001E005C + (D_L01_001E00C8 + n) % 32;
    entry = D_L01_0021E260_0043B618 + r * 48;
    D_L01_001E00C8 = (r + 1) % 32;
    *(u16 *)entry = (((s32)obj - (s32)D_L01_001E001C_0043B618) >> 8) | 0x8000;
    D_L01_0021DE20[slot] = (s32)entry;
    obj[0x21] = slot;
    return slot;
}
