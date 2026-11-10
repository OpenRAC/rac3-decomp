#include "common.h"

/* localdecomp:start func_L39_004E5008 */
extern void func_L39_004BEF28(void *);

typedef struct S_004E5008 {
    s32 f0;
    s32 f4;
    void (*f8)(void *, s32, void *);
    s32 fC;
    s32 f10;
} S_004E5008;

void func_L39_004E5008(S_004E5008 *arg0) {
    if (arg0 == 0) {
        return;
    }
    if (arg0->f8 != 0) {
        arg0->f8(arg0, 2, arg0);
    }
    if (arg0->f10 & 1) {
        func_L39_004BEF28(arg0);
    }
}
/* localdecomp:end func_L39_004E5008 */
