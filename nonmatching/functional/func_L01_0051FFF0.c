/* functional: high. Retail has nop and sp-adjust filler between the stores; behaviour identical. */
s32 func_L01_0051FFF0(u8 *p, f32 v) {
    *(f32 *)(p + 0x10) = v;
    *(f32 *)(p + 0x18) = v;
    return 3;
}
