/* functional: high. Returns x scaled by the level-wide factor D_001D5318; same FPU multiply. */
extern f32 D_001D5318;

f32 func_L01_0040DFB0(f32 x) {
    return D_001D5318 * x;
}
