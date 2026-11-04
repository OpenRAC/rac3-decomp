#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_006121B0;

/* localdecomp:start func_L39_006121B0 */
extern S_006121B0 D_L39_0024CD50;
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_L39_0060F298(void *, s32);

s32 func_L39_006121B0(s32 a) {
    s32 r;
    void *p;
    s32 x;

    r = 0;
    if (D_L39_0024CD50.f4 != 0) {
        p = &D_L39_0024CD50;
    } else {
        p = func_003E6C08(&D_L39_0024CD50);
    }
    x = func_003E6DE8(p);
    if (x != 0) {
        func_L39_0060F298(x, a);
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_006121B0 */
