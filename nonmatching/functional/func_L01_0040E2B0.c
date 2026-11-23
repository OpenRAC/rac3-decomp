/* functional: high. Handwritten backward quadword copy (memmove for overlapping dst > src): copies n bytes, 16 at a time from the end down, at least one block (do-while on n > 0). n is a multiple of 16 and pointers 16-byte aligned (lq/sq ignore the low bits). */
void func_L01_0040E2B0(u8 *dst, u8 *src, s32 n) {
    dst += n;
    src += n;
    do {
        s32 i;
        src -= 16;
        dst -= 16;
        n -= 16;
        for (i = 0; i < 16; i++) {
            dst[i] = src[i];
        }
    } while (n > 0);
}
