/* functional: high. Returns x scaled by the level-wide factor D_001D5314; same FPU multiply. */
extern f32 D_001D5314;

f32 func_L01_0040DFA0(f32 x) {
    return D_001D5314 * x;
}
