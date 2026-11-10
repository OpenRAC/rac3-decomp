/* Near miss, ported from rac4-decomp's func_L00_00516E40 (cross-game near pair). NEAR: SQ_RA 16-byte slots (frame 0x30, ra 0x20); callee is func_L39_004DAAB0 (jal masked); body otherwise equal */
s32 func_L00_005168B0(void *);

void func_L39_004DB040(void *arg0) {
    s32 temp_s0;
    void *temp_a0;
    while (arg0 != 0) {
        temp_a0 = arg0;
        temp_s0 = (*(s32 *)((u8 *)(arg0) + 0x2C));
        arg0 = (*(void **)((u8 *)(arg0) + 0x24));
        func_L00_005168B0(temp_a0);
        if (temp_s0 >= 2) {
            break;
        }
    }
}
