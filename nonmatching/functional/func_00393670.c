/* functional: high. 4 words differ (scheduling of lui/lw). Logic equals asm. */
extern s32 D_00227600[];
extern s32 D_001D9E98[];
extern s32 D_001D9E9C[];
void func_00393670(void) {
    s32 a = D_00227600[0];
    D_001D9E98[0] = a;
    D_001D9E9C[0] = a + 0x64000;
}
