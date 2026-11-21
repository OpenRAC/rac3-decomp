/* functional: high. Integer n scaled by D_001D5310, rounded to nearest (retail adds 0.25*2 = 0.5 through ACC then truncates); same arithmetic order. */
extern f32 D_001D5310;

s32 func_L01_0040DF78(s32 n) {
    return (s32)((f32)n * D_001D5310 + 0.5f);
}
