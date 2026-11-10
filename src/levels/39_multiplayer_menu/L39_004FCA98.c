#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

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

/* localdecomp:start func_L39_004FCD30 */
typedef struct Type1 Type1;
typedef struct Type2 {
    char _p0[0x14];
    void (*f14)(Type1 *arg0);
} Type2;
struct Type1 {
    Type2 *f0;
};

/* from rac4-decomp's func_L00_0051EE28 */
void func_L39_004FCD30(Type1 *arg0) {
    arg0->f0->f14(arg0);
}
/* localdecomp:end func_L39_004FCD30 */

INCLUDE_ASM("asm/levels", func_L39_004FCD58);
