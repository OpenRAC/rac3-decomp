/* functional: high. Retail bytes differ only in how the address of the slot is folded (offset 0xD4 kept in the sw vs folded into the %lo); same store, same bounds check (unsigned idx < 0x34), same return 1. */
extern u8 D_001A30B0[];

s32 func_L01_004AB048(u32 idx, s32 val) {
    if (idx < 0x34) {
        *(s32 *)(D_001A30B0 + idx * 128 + 0xD4) = val;
    }
    return 1;
}
