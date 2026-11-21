/* functional: high. Returns x scaled by the level-wide factor D_001D530C (frame-rate scale); same FPU multiply. */
extern f32 D_001D530C;

f32 func_L01_0040DF30(f32 x) {
    return D_001D530C * x;
}
