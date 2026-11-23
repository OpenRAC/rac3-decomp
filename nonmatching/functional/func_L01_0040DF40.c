/* functional: high. Integer n scaled by D_001D530C, rounded to nearest (retail adds 0.25*2 = 0.5 through ACC then truncates); same arithmetic order. */
extern f32 D_001D530C;

s32 func_L01_0040DF40(s32 n) {
    return (s32)((f32)n * D_001D530C + 0.5f);
}
