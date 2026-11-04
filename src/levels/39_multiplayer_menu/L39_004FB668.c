#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

INCLUDE_ASM("asm/levels", func_L39_004FB668);

INCLUDE_ASM("asm/levels", func_L39_004FB710);

INCLUDE_ASM("asm/levels", func_L39_004FB898);

INCLUDE_ASM("asm/levels", func_L39_004FB9A0);

INCLUDE_ASM("asm/levels", func_L39_004FBA78);

INCLUDE_ASM("asm/levels", func_L39_004FBBE8);

INCLUDE_ASM("asm/levels", func_L39_004FBDA0);

INCLUDE_ASM("asm/levels", func_L39_004FBED8);

INCLUDE_ASM("asm/levels", func_L39_004FBF10);

INCLUDE_ASM("asm/levels", func_L39_004FC158);

INCLUDE_ASM("asm/levels", func_L39_004FC1A0);

INCLUDE_ASM("asm/levels", func_L39_004FC228);

INCLUDE_ASM("asm/levels", func_L39_004FC288);

INCLUDE_ASM("asm/levels", func_L39_004FC318);

INCLUDE_ASM("asm/levels", func_L39_004FC370);

INCLUDE_ASM("asm/levels", func_L39_004FC380);

INCLUDE_ASM("asm/levels", func_L39_004FC3C8);

INCLUDE_ASM("asm/levels", func_L39_004FC410);

INCLUDE_ASM("asm/levels", func_L39_004FC448);

INCLUDE_ASM("asm/levels", func_L39_004FC4B8);

INCLUDE_ASM("asm/levels", func_L39_004FC580);

INCLUDE_ASM("asm/levels", func_L39_004FC5C0);

INCLUDE_ASM("asm/levels", func_L39_004FC668);

INCLUDE_ASM("asm/levels", func_L39_004FC6F8);

INCLUDE_ASM("asm/levels", func_L39_004FC780);

INCLUDE_ASM("asm/levels", func_L39_004FC8C0);

INCLUDE_ASM("asm/levels", func_L39_004FC960);

INCLUDE_ASM("asm/levels", func_L39_004FC9D0);

/* localdecomp:start func_L39_004FCA98 */
extern void func_L39_004FC318(void *p);

s32 func_L39_004FCA98(BitSet_004FCA98 *a0, s32 a1) {
    BitSet_004FCA98 *s = a0;
    s32 q = a1 / 64;
    s32 rem = a1 % 64;

    if (q >= s->f4) {
        return 0;
    }
    if (rem == 0) {
        s->f4 = q;
    } else {
        s->f4 = q + 1;
        *(s->f0 + q) &= ~((unsigned long)-1 << rem);
    }
    func_L39_004FC318(s);
    return 1;
}
/* localdecomp:end func_L39_004FCA98 */

INCLUDE_ASM("asm/levels", func_L39_004FCB28);

INCLUDE_ASM("asm/levels", func_L39_004FCCC8);

INCLUDE_ASM("asm/levels", func_L39_004FCD30);

INCLUDE_ASM("asm/levels", func_L39_004FCD58);

INCLUDE_ASM("asm/levels", func_L39_004FCE30);

INCLUDE_ASM("asm/levels", func_L39_004FCF40);

INCLUDE_ASM("asm/levels", func_L39_004FCF88);

INCLUDE_ASM("asm/levels", func_L39_004FCFD0);

INCLUDE_ASM("asm/levels", func_L39_004FD0F8);

INCLUDE_ASM("asm/levels", func_L39_004FD228);

INCLUDE_ASM("asm/levels", func_L39_004FD2D0);

INCLUDE_ASM("asm/levels", func_L39_004FD3B0);

INCLUDE_ASM("asm/levels", func_L39_004FD500);

INCLUDE_ASM("asm/levels", func_L39_004FD678);

INCLUDE_ASM("asm/levels", func_L39_004FD710);

INCLUDE_ASM("asm/levels", func_L39_004FDA88);

INCLUDE_ASM("asm/levels", func_L39_004FDDF0);

INCLUDE_ASM("asm/levels", func_L39_004FE020);

/* localdecomp:start func_L39_004FE100 */
/* 64-bit multi-precision subtract with borrow, 4x unrolled, returns final borrow */
unsigned long func_L39_004FE100(unsigned long *d, unsigned long *a, unsigned long *b, s32 n) {
    unsigned long borrow = 0;
    unsigned long x;
    unsigned long y;

    if (n <= 0) {
        return 0;
    }
    {
        for (;;) {
            x = a[0];
            y = b[0];
            d[0] = x - y - borrow;
            if (x != y) {
                borrow = x < y;
            }
            if (--n <= 0) break;

            x = a[1];
            y = b[1];
            d[1] = x - y - borrow;
            if (x != y) {
                borrow = x < y;
            }
            if (--n <= 0) break;

            x = a[2];
            y = b[2];
            d[2] = x - y - borrow;
            if (x != y) {
                borrow = x < y;
            }
            if (--n <= 0) break;

            x = a[3];
            y = b[3];
            d[3] = x - y - borrow;
            if (x != y) {
                borrow = x < y;
            }
            if (--n <= 0) break;

            a += 4;
            b += 4;
            d += 4;
        }
    }
    return borrow;
}
/* localdecomp:end func_L39_004FE100 */

INCLUDE_ASM("asm/levels", func_L39_004FE1BC);

INCLUDE_ASM("asm/levels", func_L39_004FE1C8);

INCLUDE_ASM("asm/levels", func_L39_004FE250);

LINKER_REMNANT("asm/levels", func_L39_004FE320);

INCLUDE_ASM("asm/levels", func_L39_004FE328);

INCLUDE_ASM("asm/levels", func_L39_004FE608);

INCLUDE_ASM("asm/levels", func_L39_004FE6B0);

INCLUDE_ASM("asm/levels", func_L39_004FE728);

INCLUDE_ASM("asm/levels", func_L39_004FECA0);

INCLUDE_ASM("asm/levels", func_L39_004FF3AC);

INCLUDE_ASM("asm/levels", func_L39_004FF3C0);

INCLUDE_ASM("asm/levels", func_L39_004FF440);

INCLUDE_ASM("asm/levels", func_L39_004FF4A0);

INCLUDE_ASM("asm/levels", func_L39_004FF5A0);

INCLUDE_ASM("asm/levels", func_L39_004FFAF0);

INCLUDE_ASM("asm/levels", func_L39_004FFBB0);

INCLUDE_ASM("asm/levels", func_L39_004FFD58);

INCLUDE_ASM("asm/levels", func_L39_004FFEE0);

INCLUDE_ASM("asm/levels", func_L39_005000BC);
