/* functional: high. Retail's binary-search tree of type ids rewritten as a switch (same mapping, traced by hand); returns 0xFF for null/not found. Table names D_001425C0/D_002C5600/D_00142637 and hero base D_001A4BE0 offsets 0x1200 (hero moby) and 0x1228 (state) as raw offsets */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_00142637;
extern u8 D_002C5600[];

s32 func_L01_0044CE88(u8 *a0) {
    s32 state;
    s32 g;
    s32 op;
    u8 *b8;
    s32 i;
    s32 t;

    if (a0 == 0) {
        return 0xFF;
    }
    state = *(s32 *)(D_001A4BE0 + 0x1228);
    op = *(s16 *)(a0 + 0xAA);
    if (state == 0x87 && op == 0x1893) return 0x87;
    if (state == 0x57 && op == 0x1893) return 0x57;
    if (state == 0x77 && D_002C5600[D_00142637 * 0xF0 + 1] >= 4 && op == 0x1855) return 0x77;
    if (state == 0x11 && (op == 0xC59 || op == 0x5C9)) return 0x11;
    if (state == 0x7F && op == 0x47) return 0x7F;
    if (state == 0x47 && op == 0x1195) return 0x47;

    switch (op) {
    case 0x1893: case 0x188F: case 0x1AEC: case 0x1ADA:
    case 0x1852: case 0x1853: case 0x1854: case 0x1855:
        return 0x57;
    case 0x185B: case 0x1892: case 0x1872:
        return 0x87;
    case 0x1858: case 0x185A: case 0x1865: case 0x1888: case 0x1885: case 0x1898:
        return 0x77;
    case 0x5C9: case 0xC59: case 0xB2E:
        return 0x11;
    case 0x1843: case 0x1890: case 0x1CB8:
        return 0x7F;
    case 0x1195:
        return 0x16;
    case 0x1869: case 0x186D:
        return 0x67;
    case 0x1870: case 0x189B: case 0x1C59:
        return 0x8F;
    case 0x1871: case 0x1873:
        return 0x97;
    case 0x1866: case 0x1867:
        return 0x4F;
    case 0x186A: case 0x186B:
        return 0x5F;
    case 0xA82: case 0xC5A: case 0xA65: case 0xA66: case 0x1366:
        return 0x15;
    case 0xECE: case 0xE64:
        return 0x13;
    case 0x1864: case 0x1887: case 0x1894:
        return 0x3F;
    case 0x9A9: case 0xA9B:
        return 0x10;
    default:
        break;
    }

    g = *(s32 *)(D_001A4BE0 + 0x1200);
    b8 = *(u8 **)(a0 + 0xB8);
    if ((s32)a0 == g || (b8 != 0 && (s32)b8 == g)) {
        return state;
    }
    for (i = 0; i < 0x9C; i++) {
        t = *(s32 *)(D_002C5600 + D_001425C0[i] * 0xF0 + 0x10);
        if (op == t) {
            return i;
        }
        if (b8 != 0 && *(s16 *)(b8 + 0xAA) == t) {
            return i;
        }
    }
    return 0xFF;
}
