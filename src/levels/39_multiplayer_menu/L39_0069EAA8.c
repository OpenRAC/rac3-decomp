#include "common.h"

/* localdecomp:start func_L39_0069EAA8 */
typedef struct V_0069EAA8 V_0069EAA8;
typedef struct O_0069EAA8 {
    u8 pad[0x60];
    struct { u8 pad[0x24]; void (*fn)(struct O_0069EAA8 *, s32); } *vt;
} O_0069EAA8;

void func_L39_0069EAA8(u8 *self, s32 a, s32 b, s32 c)
{
    O_0069EAA8 *o;
    o = *(O_0069EAA8 **)(self + 0x110);
    o->vt->fn(o, a);
    o = *(O_0069EAA8 **)(self + 0x114);
    o->vt->fn(o, b);
    self[0x2AC] = c;
}
/* localdecomp:end func_L39_0069EAA8 */

LINKER_REMNANT("asm/levels", func_L39_0069EB08);
