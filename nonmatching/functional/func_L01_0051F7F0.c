/* functional: high. Retail has inlined-macro remnants (nops and sp adjustments that cancel); stores and return value are identical. */
s32 func_L01_0051F7F0(u8 *p, f32 v) {
    *(f32 *)(p + 0x10) = v;
    *(f32 *)(p + 0x18) = v;
    return 2;
}
