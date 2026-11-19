/* functional: high. 69 words differ at default flags (register allocation and loop strength reduction); behaviour identical. The i==2 branch tests the address of an array so retail never takes it; kept for fidelity. */
extern s32 D_L01_001D9574;
__asm__(".extern D_L01_001D9574, 4");
extern s32 D_L01_001E0CD0[];
extern s32 D_L01_002ED730[];
extern s32 D_L01_00236AB8[];
void func_L01_004A04B8(void) {
    s32 i;
    for (i = 0; i < D_L01_001D9574; i++) {
        if (i == 2 && !D_L01_001E0CD0) {
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, 2), D_L01_001D9638,
                        D_L01_00236AB8[D_L01_002ED730[24] ? 6 : 7]);
        } else if (i != 3) {
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D9638,
                        D_L01_00236AB8[D_L01_002ED730[i * 12] + i * 3]);
        }
    }
}
