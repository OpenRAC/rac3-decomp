/* Near miss of func_003D7080 with its file's own flags: tools/check.py reports 131 diff
   (the version it replaces: 136).
   What differs: body matches retail word for word; still differ: the callee-saved frame
   (retail 0x80 with 16-byte `sq` slots, ours 0x50 with 8-byte `sd` slots - a `-fopt-stack`
   effect) and 3 of the 64-bit constant materialisations (`lui`+`dsll32` vs retail's
   `ori`+`dsll32` - the retail compiler evaluates the shift expressions at run time, ours folds
   them into constants)
*/

/* US draft of func_003D7080 (rac3-uya-decomp func_003D1B10, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override).

   PAL retail builds the 64-bit packet words with run-time shifts (ori $r,$zero,imm ; dsll/dsll32 ; ori),
   i.e. the source expressions are evaluated, not folded into a constant, so they are written here in
   shift form.  The 32-bit words (0x400000000, 0x80808080) are written the same way. */


/* localdecomp:start func_003D7080 */
extern void func_003D6AE0(long **, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D7080(long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17, s32 a18) {
    *(*pp)++ = (0x8000UL << 47) | 1UL;
    *(*pp)++ = 0x0000EEEEEEEEEEEEUL;
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
    *(*pp)++ = 0x0000EEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D7080 */
