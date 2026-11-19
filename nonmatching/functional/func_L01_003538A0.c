/* functional: high. Compiles in context, not exact (registers only). Finds the object slot for a list id: walks a halfword list from the table, each entry 15-bit index<<8 into the object array, returns the first whose halfword at 0xAA is 0x16BD and type byte 0x20 is 0x12; else 0. Uses the level's own D_L01_ names. */
u8 *func_L01_003538A0(s32 idx) {
    u16 *tbl = D_L01_0021DE20[idx];
    u16 *p;
    u8 *base;
    u8 *m;
    s32 h;
    if ((idx & 0xFF) == 0xFF) return 0;
    if (D_L01_001E0058 < idx) return 0;
    if (tbl == 0) return 0;
    base = D_L01_001E001C;
    p = tbl;
    h = *p;
    for (;;) {
        m = base + ((h & 0x7FFF) << 8);
        if (m == 0) return 0;
        if (*(s16 *)(m + 0xAA) == 0x16BD && m[0x20] == 0x12) return m;
        if ((idx & 0xFF) == 0xFF) return 0;
        p++;
        if (p == 0) return 0;
        if ((s16)p[-1] >= 0 || p == D_L01_0021DE20[idx]) h = *p;
        else return 0;
    }
}
