/* func_L03_0040F9E8: near miss (p2 w2): 3 diff, only the order of the two lui/addiu address setups (retail computes D_001D4C80 first).
   Tried pointer forms, swapped tests, sized arrays. */
extern int D_001D4C60[];
extern int D_001D4C80[];
void func_L03_0040F9E8(int a0) {
    int i;
    for (i = 0; i < 8; i++) {
        if (D_001D4C60[i] == a0) D_001D4C60[i] = 0;
        if (D_001D4C80[i] == a0) D_001D4C80[i] = 0;
    }
}
