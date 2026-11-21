/* functional: high. Draft used register/asm tricks and NTSC address 0x22760C; rewritten as plain C from the PAL asm (D_0022758C hi/lo, D_001DA058, gp-relative D_001D5BDC/D_001D5C90). 14 words differ in layout only. */
extern u8 D_001D5BDC;
extern s32 D_001D5C90;
extern s32 D_0022758C[];
extern s32 D_001DA058[];
s32 func_003932E8(u32 value, s32 *result) {
    if (value > 0x40000) {
        *result = 0;
        return -1;
    }
    if (D_001D5BDC == 0 && D_001D5C90 != 0) {
        *result = D_001D5C90;
        return 0;
    }
    *result = D_0022758C[0] + D_001DA058[0] - value;
    return 0;
}
