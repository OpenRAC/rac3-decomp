/* Near miss, ported from rac4-decomp's func_L00_00516F68 (cross-game near pair). NEAR: SIBCALL (tail j func_L00_004BEF28) + SQ_RA */
s32 func_0011D534();
s32 func_L00_004BEF28(void *);

void func_L39_004DB168(void *arg0) {
    void *temp_a0;
    if (arg0 != 0) {
        temp_a0 = (*(void **)((u8 *)(arg0) + 4));
        if (temp_a0 != 0) {
            func_0011D534(temp_a0, 0, (*(s32 *)((u8 *)(arg0) + 8)));
            func_L00_004BEF28((*(void **)((u8 *)(arg0) + 4)));
        }
        func_L00_004BEF28(arg0);
    }
}
