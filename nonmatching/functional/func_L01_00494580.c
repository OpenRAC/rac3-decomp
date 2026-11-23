/* functional: high. Stores 0 into word 2 of its argument and returns 0; retail has one extra nop before the jr (not representable), behaviour identical */
s32 func_L01_00494580(s32 *a0) {
    a0[2] = 0;
    return 0;
}
