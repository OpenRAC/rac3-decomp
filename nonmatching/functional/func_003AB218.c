/* functional: high. Plain C stores; retail reaches D_001DA074 via $gp, here via its name (same address); float constants 1.07692301f (0x3F89D89D; the gate found that 1.0769231f rounds to 0x3F89D89E) and 0.9f (0x3F666666) taken from the asm. */
/* fcheck: the blocks no state ran (mode 0: both 1.0f) read against retail: fcheck-read: 003AB22C-003AB230,003AB250-003AB254 */
extern s32 D_001DA070;
extern f32 D_001DA074;
extern f32 D_001DA078;
void func_003AB218(s32 mode) {
    D_001DA070 = mode;
    D_001DA074 = mode ? 1.07692301f : 1.0f;
    D_001DA078 = mode ? 0.9f : 1.0f;
}
