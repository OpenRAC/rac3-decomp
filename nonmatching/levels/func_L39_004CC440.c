/* Near miss, ported from rac4-decomp's func_L00_00508240 (cross-game near pair). NEAR: SQ_RA: retail 0x20 frame, ra at 0x10 restored before s0; body otherwise identical (callee is func_0011D534) */
s32 func_0011D534();

void func_L39_004CC440(void *arg0) {
    s32 temp_a2;
    if (arg0 != 0) {
        temp_a2 = (*(s32 *)((u8 *)(arg0) + 0));
        if (temp_a2 > 0) {
            func_0011D534((*(s32 *)((u8 *)(arg0) + 4)), 0, temp_a2 * 4);
            (*(s32 *)((u8 *)(arg0) + 0)) = 0;
        }
    }
}
