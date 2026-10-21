#include "common.h"

/* localdecomp:start func_L01_00517748 */
extern s32 func_L01_00517748();
extern s32 func_003E6DE8(void *);
extern void *func_003E6C08();
extern s32 func_003E6DE8();

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_3E2E60;
extern S_3E2E60 D_L01_001E15E0;
extern s32 func_003E62C8();
s32 func_L01_00517748(s32 a) {
    S_3E2E60 *q;
    s32 r = 0;
    s32 t;
    if (D_L01_001E15E0.x4) q = &D_L01_001E15E0;
    else q = func_003E6C08(&D_L01_001E15E0);
    t = func_003E6DE8(q);
    if (t) r = func_003E62C8(t, a);
    return r;
}
/* localdecomp:end func_L01_00517748 */

LINKER_REMNANT("asm/levels", func_L01_005177B8);
