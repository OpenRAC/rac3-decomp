/* functional: high. US draft with one PAL fix: both 0xEEEE... words are the full 64-bit 0xEEEEEEEEEEEEEEEE (draft had 0x0000EEEE...); all 19 params (a8..a18 on stack 0x80..0xD0), shifts, quadword layout and the func_003D6AE0 arg shuffle verified. 27 diff words (scheduling). */
extern void func_003D6AE0(long **, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D7080(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17, s32 a18) {
    *(*pp)++ = (0x8000UL << 47) | 1UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a8 - 1) << 16) | ((long)(a9 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 8) | ((long)a4 << 14) | ((long)a5 << 26) | ((long)a6 << 30) | (0x8000UL << 19);
    *(*pp)++ = 7;
    *(*pp)++ = (a7 >> 13) | ((long)a10 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = (0x9000UL << 46) | 1UL;
    *(*pp)++ = 1;
    *(*pp)++ = (0x8080UL << 16) | 0x8080UL;
    *(*pp)++ = 0x316;
    func_003D6AE0(pp, a11, a12, a15, a16, a13, a14, a17, a18);
    *(*pp)++ = (0x8000UL << 45) | 0x8001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
