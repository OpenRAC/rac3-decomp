#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 8010A8.c's earlier functions (tools/port_from_us.py) */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);
extern int func_008014A0(int);

/* localdecomp:start func_00801510 */
/* Double (bits in a GPR, soft-float) to int, rounding the last two shifted-out bits; 9999 when too
   large. Called by func_008015A0. Retail ends with dsll32 / jr / dsra32: the sign extension was
   most likely the (int) conversion, a single two-word pattern that the assembler split into the
   delay slot (binutils 2.10 does, this project's assemblers don't). Here the shifts are two
   separate instructions, so gcc's own delay-slot pass puts the second one there; the empty asm
   stops combine from merging them back. The value is the same, sign-extended in $v0. */
long func_00801510(double d) {
    union { double d; unsigned long u; } x;
    long e;
    x.d = d;
    e = (x.u << 1) >> 53;
    e -= 1075;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    x.u = (x.u << 12) >> 12;
    x.u |= 1UL << 52;
    if (e < 0) {
        e = -e;
        x.u >>= (int)(e - 2);
        if ((x.u & 3) == 3) x.u = (x.u >> 2) + 1;
        else x.u >>= 2;
    } else {
        x.u <<= (int)e;
    }
    {
        long t = x.u << 32;
        __asm__("" : "+r"(t));
        return t >> 32;
    }
}
/* localdecomp:end func_00801510 */
