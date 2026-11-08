/* Near miss, ported from rac4-decomp's func_L00_00516ED8 (cross-game near pair). NEAR: FILL-ONLY: all code words equal; array externs D_..[] used as [0], no hint */
s32 func_L39_004FE6B0(void *);

extern s32 D_L39_0046A354[]; extern s32 D_L39_004761B8[];

s32 func_L39_004DB0D8(void) {
    if (D_L39_0046A354[0] != 0) {
        D_L39_0046A354[0] = 0;
        func_L39_004FE6B0(D_L39_004761B8);
    }
    return 0;
}
