/* functional: high. Unpacks four bytes of a packed word into four floats (byte 0 -> x ... byte 3 -> w), each 0..255 (pextlb/pextlh zero-extend, vitof0 converts). */
void func_L01_0040E858(f32 *dst, u32 packed) {
    dst[0] = (f32)(s32)(packed & 0xFF);
    dst[1] = (f32)(s32)((packed >> 8) & 0xFF);
    dst[2] = (f32)(s32)((packed >> 16) & 0xFF);
    dst[3] = (f32)(s32)((packed >> 24) & 0xFF);
}
