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
