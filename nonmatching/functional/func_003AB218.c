/* functional: high. Plain C stores; retail reaches D_001DA074 via $gp, here via its name (same address); float constants 1.0769231f (0x3F89D89D) and 0.9f (0x3F666666) taken from the asm. */
extern s32 D_001DA070;
extern f32 D_001DA074;
extern f32 D_001DA078;
void func_003AB218(s32 mode) {
    D_001DA070 = mode;
    D_001DA074 = mode ? 1.0769231f : 1.0f;
    D_001DA078 = mode ? 0.9f : 1.0f;
}
