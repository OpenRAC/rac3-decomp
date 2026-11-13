#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

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
