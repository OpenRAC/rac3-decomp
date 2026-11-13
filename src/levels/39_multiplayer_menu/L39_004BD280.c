#include "common.h"

/* declared by functions of L39_004BCDE0.c, which this file was cut from */
typedef struct S_004BCDE0 {
    u8 _00[0x88];
    long f88;
    long f90;
    u8 _98[8];
    s32 fA0;
} S_004BCDE0;
extern s32 **func_L39_004BD178(S_004BCDE0 *, s32, s32 *);

/* localdecomp:start func_L39_004BD280 */
/* ee29 near miss (needs @ee29 without -fopt-stack): only diff is $s0/$s1 swap (retail h in $s0, s in $s1; move s1,a0 before move s0,zero); tried h=0 after check, local copy of s (gives h in s0 but s copied late), for/while forms, char types */
extern long func_001306F8(long, long);

unsigned long func_L39_004BD280(s8 *s)
{
    unsigned long h = 0;
    long k;
    unsigned long v;
    s32 r;

    if (s == 0 || *s == 0) {
        return 0;
    }
    k = 0x100;
    do {
        v = k | *s++;
        r = (s32)((v >> 2) ^ v) & 0xF;
        k += 0x100;
        h = (h << r) | (h >> (32 - r));
        h = h & 0xFFFFFFFF;
        h = h ^ func_001306F8(v, v);
    } while (*s != 0);
    return (h >> 16) ^ h;
}
/* localdecomp:end func_L39_004BD280 */

INCLUDE_ASM("asm/levels", func_L39_004BD350);

INCLUDE_ASM("asm/levels", func_L39_004BD428);

INCLUDE_ASM("asm/levels", func_L39_004BD4E0);

INCLUDE_ASM("asm/levels", func_L39_004BDC08);
