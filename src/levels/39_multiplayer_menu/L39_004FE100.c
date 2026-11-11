#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

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
