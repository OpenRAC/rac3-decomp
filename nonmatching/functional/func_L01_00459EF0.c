/* functional: high. EXACT at levels 01, 02, 12, 36 (byte-identical). */
extern s32 D_L01_001D6690;
extern s32 D_001D545C;
extern s32 D_L01_001DFB90;
void func_L01_00459EF0(void) {
    extern void func_L01_00415DC8(s32);
    if ((u32)(D_L01_001D6690 - 3) < 2) {
        switch (D_001D545C) {
        case 11: break;
        case 18:
        case 20:
        case 26:
        case 29:
            D_L01_001DFB90 = 2;
            break;
        }
        func_L01_00415DC8(D_L01_001DFB90);
    }
}
