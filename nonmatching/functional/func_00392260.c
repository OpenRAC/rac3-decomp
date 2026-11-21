/* functional: high. Matches the asm op for op (dsll 8, dsll 16, or with 0x80000000); differs only by file flags in the check. */
extern unsigned long D_001D07E8[];
void func_00392260(s32 arg0, long arg1, long arg2) {
    D_001D07E8[0] = arg0 | (arg1 << 8) | (arg2 << 0x10) | (unsigned long)0x80000000;
}
