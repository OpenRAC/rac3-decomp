#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* declared by functions of L39_004FB668.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

INCLUDE_ASM("asm/levels", func_L39_004FC3C8);

INCLUDE_ASM("asm/levels", func_L39_004FC410);

INCLUDE_ASM("asm/levels", func_L39_004FC448);

INCLUDE_ASM("asm/levels", func_L39_004FC4B8);

/* localdecomp:start func_L39_004FC580 */
/* from rac4-decomp's func_L00_00538390 */
s32 func_L39_004FC380();
s32 func_L39_004FC5C0(s32, s32);

s32 func_L39_004FC580(s32 arg0) {
    s32 v = func_L39_004FC380();
    if (v == 0) return 0;
    return func_L39_004FC5C0(v, arg0);
}
/* localdecomp:end func_L39_004FC580 */

INCLUDE_ASM("asm/levels", func_L39_004FC5C0);

INCLUDE_ASM("asm/levels", func_L39_004FC668);

INCLUDE_ASM("asm/levels", func_L39_004FC6F8);

/* localdecomp:start func_L39_004FC780 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BigNum_004FC780;

extern void *func_L39_004FC4B8(void *, s32);

void *func_L39_004FC780(const u8 *s, s32 len, BigNum_004FC780 *ret) {
    u32 i;
    u32 m;
    u32 n;
    unsigned long l;

    if (ret == 0) {
        ret = (BigNum_004FC780 *) func_L39_004FC380();
    }
    if (ret == 0) {
        return 0;
    }
    l = 0;
    n = len;
    if (n == 0) {
        ret->top = 0;
        return ret;
    }
    if (((((s32) (n + 2) * 8 + 63) / 64 <= ret->dmax) ? ret : func_L39_004FC4B8(ret, (s32) (n + 2) * 8 / 64 + 1)) == 0) {
        return 0;
    }
    i = ((n - 1) / 8) + 1;
    m = (n - 1) % 8;
    ret->top = i;
    while (n-- > 0) {
        l = (l << 8) | *(s++);
        if (m-- == 0) {
            unsigned long *d = ret->d;

            d[--i] = l;
            l = 0;
            m = 7;
        }
    }
    func_L39_004FC318(ret);
    return ret;
}
/* localdecomp:end func_L39_004FC780 */

INCLUDE_ASM("asm/levels", func_L39_004FC8C0);

INCLUDE_ASM("asm/levels", func_L39_004FC960);

INCLUDE_ASM("asm/levels", func_L39_004FC9D0);
