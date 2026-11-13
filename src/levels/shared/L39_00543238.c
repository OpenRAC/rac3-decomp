#include "common.h"

/* localdecomp:start func_L39_00543238 */
#include "vu0.h"

typedef struct {
    char pad0[0x270];
    u8 q270[0x10];
    char pad280[0x2D0 - 0x280];
    void *f2D0;
    char pad2D4[0x308 - 0x2D4];
    f32 f308;
    f32 f30C;
    s32 f310;
} In_00543238;

typedef struct {
    char pad0[0x384];
    In_00543238 *f384;
} Mid_00543238;

typedef struct {
    char pad0[0x68];
    Mid_00543238 *f68;
} Out_00543238;

extern void func_L39_00543818(void *);

void func_L39_00543238(Out_00543238 *o) {
    Mid_00543238 *m = o->f68;
    In_00543238 *p = (In_00543238 *)m->f384;
    qzero(p->q270);
    p->f308 = 60.0f;
    p->f30C = 60.0f;
    p->f310 = 0;
    func_L39_00543818(p->f2D0);
}
/* localdecomp:end func_L39_00543238 */

INCLUDE_ASM("asm/levels", func_L39_00543278);

INCLUDE_ASM("asm/levels", func_L39_00543410);
