#include "common.h"

/* localdecomp:start func_L39_00516498 */
typedef struct Type1 S_00516498;
extern void func_0011D534(void *, s32, s32);
extern void func_L39_00517678(S_00516498 *, s32, s32, s32);

void func_L39_00516498(s32 *p, s32 v) {
    func_0011D534(p, 0, 0xE8);
    func_L39_00517678((S_00516498 *)(p + 2), 0, 0, 0);
    *p = v;
}
/* localdecomp:end func_L39_00516498 */

INCLUDE_ASM("asm/levels", func_L39_005164E8);

INCLUDE_ASM("asm/levels", func_L39_00516570);

/* localdecomp:start func_L39_005165D0 */
typedef struct {
    char pad0[8];
    s32 f8;
    char padC[0xC4];
    s32 fD0;
} S_005165D0;
extern s32 func_L39_00517888(void *);

/* from rac4-decomp's func_L00_005523E0 */
s32 func_L39_005165D0(S_005165D0 *p) {
    s32 old = p->f8;
    s32 r = func_L39_00517888(&p->f8);
    if (r == 0 && old != p->f8) {
        p->fD0 = old;
    }
    return r;
}
/* localdecomp:end func_L39_005165D0 */
