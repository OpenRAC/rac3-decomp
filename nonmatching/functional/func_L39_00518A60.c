/* functional: high. Byte-swaps a 16-bit value (swap the two low bytes, upper bits cleared). */
u32 func_L39_00518A60(u32 x) {
    return ((x << 8) & 0xFF00) | ((x >> 8) & 0xFF);
}
