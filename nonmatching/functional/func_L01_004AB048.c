/* functional: high. Exact match: slot pointer formed first, offset 0xD4 kept in the sw; unsigned idx < 0x34 bounds check, returns 1. */
extern u8 D_001A30B0[];
s32 func_L01_004AB048(u32 idx, s32 val) {
    u8 *slot;
    if (idx < 0x34) {
        slot = D_001A30B0 + idx * 128;
        *(s32 *)(slot + 0xD4) = val;
    }
    return 1;
}
