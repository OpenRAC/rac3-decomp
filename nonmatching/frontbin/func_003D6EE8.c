/* US draft of func_003D6EE8 (rac3-uya-decomp func_003D1978, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override). */


/* localdecomp:start func_003D6EE8 */
void func_003D6EE8(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12) {
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = ((long)(a2 - 1) << 16) | ((long)(a3 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = (a1 >> 13) | ((long)a4 << 16);
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x4400000000008001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x306;
    *(*pp)++ = a9 | ((long)a10 << 8) | ((long)a11 << 16) | ((long)a12 << 24);
    *(*pp)++ = a5 | ((long)a6 << 16);
    *(*pp)++ = a7 | ((long)a8 << 16);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D6EE8 */
