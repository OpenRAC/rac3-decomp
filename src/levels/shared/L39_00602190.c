#include "common.h"

typedef struct {
    u8 *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    s32 f10;
    u32 f14;
} Pool_00602190;

/* localdecomp:start func_L39_00602190 */
extern u8 D_L39_00245348[];
extern u8 D_L39_00245390[];
extern void func_118E98(u8 *a0, s32 a1, u8 *a2);

void *func_L39_00602190(Pool_00602190 *p)
{
    u32 off, size;
    u32 *x;
    u8 *r;

    if (p->f14 != 0)
    {
        x = (u32 *)p->f14;
        p->f14 = x[0];
        p->f10 = p->f10 + 1;
        return x;
    }
    off = p->fC;
    size = p->f8;
    if (p->f4 < off + size)
    {
        func_118E98(D_L39_00245348, 84, D_L39_00245390);
        return 0;
    }
    r = p->f0 + off;
    p->fC = off + size;
    p->f10 = p->f10 + 1;
    return r;
}
/* localdecomp:end func_L39_00602190 */
