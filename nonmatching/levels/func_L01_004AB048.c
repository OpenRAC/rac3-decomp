/* func_L01_004AB048: matches level 01 (check.py MATCH) but not every level: the field offset is 0xD4 in level 01 but 0xD8 in levels 04, 09, 18, 20, 23, 24, 26 and 29. */
extern u8 D_001A30B0[];

s32 func_L01_004AB048(u32 i, s32 v) {
    if (i < 0x34) {
        u8 *p = D_001A30B0;
        *(s32 *)(p + i * 128 + 0xd4) = v;
    }
    return 1;
}
