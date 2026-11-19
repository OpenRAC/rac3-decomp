/* functional: high. functional: same results for every input; byte differences are branch layout only */
extern s32 D_L01_002EAB28[];
extern s32 D_L01_001D88F0[2];

s32 func_L01_00487F78(s32 a0, s32 a1, s32 a2) {
    if (a0 == 0) {
        return D_L01_002EAB28[a1 * 4 + a2];
    }
    if (a0 == 1) {
        return D_L01_001D88F0[a1 * 2 + a2];
    }
    return 0;
}
