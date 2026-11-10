#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FC318 */
void func_L39_004FC318(void *p) {
    BitSet_004FCA98 *s = p;
    s32 n = s->f4;
    if (n > 0) {
        unsigned long *e = &s->f0[n - 1];
        if (*e-- == 0) {
            while ((s->f4 = n - 1) > 0 && *e-- == 0) {
                n = s->f4;
            }
        }
    }
}
/* localdecomp:end func_L39_004FC318 */

INCLUDE_ASM("asm/levels", func_L39_004FC370);

/* localdecomp:start func_L39_004FC380 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} S_4FC380;

extern void *func_L39_004BEED8(s32);

/* from rac4-decomp's func_L00_00538190 */
S_4FC380 *func_L39_004FC380(void) {
    S_4FC380 *p = func_L39_004BEED8(0x14);
    S_4FC380 *r = 0;
    if (p != 0) {
        p->f4 = 0;
        p->f10 = 1;
        p->fC = 0;
        p->f8 = 0;
        p->f0 = 0;
        r = p;
    }
    return r;
}
/* localdecomp:end func_L39_004FC380 */
