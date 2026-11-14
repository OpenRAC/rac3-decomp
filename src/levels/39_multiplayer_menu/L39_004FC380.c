#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

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
