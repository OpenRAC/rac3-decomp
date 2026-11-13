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
