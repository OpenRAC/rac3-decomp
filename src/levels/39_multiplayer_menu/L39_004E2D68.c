#include "common.h"

/* localdecomp:start func_L39_004E2D68 */
typedef struct {
    void *f0;
    void (*f4)(void *);
} M_004E2D68;
typedef struct {
    M_004E2D68 *f0;
    void *f4;
    s32 f8;
    s32 fC;
} S_004E2D68;
extern void func_L39_004E47F8(void *);
extern void func_L39_004BEF28(void *);

void func_L39_004E2D68(S_004E2D68 *a) {
    if (a->f0 != 0) {
        a->f0->f4(a);
    }
    if (a->f4 != 0) {
        func_L39_004E47F8(a->f4);
    }
    if (a->fC & 1) {
        func_L39_004BEF28(a);
    }
}
/* localdecomp:end func_L39_004E2D68 */
