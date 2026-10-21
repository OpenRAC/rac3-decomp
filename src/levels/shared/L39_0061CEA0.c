#include "common.h"

/* localdecomp:start func_L39_0061CEA0 */
typedef struct {
    u8 pad[4];
    s32 (*f4)(void *);
    u8 pad8[24];
    s32 (*f32)(void *);
} V61A728;

typedef struct O61A728 {
    u8 pad[184];
    struct O61A728 *parent;
} O61A728;

extern V61A728 *func_L39_005C1018(O61A728 *);

s32 func_L39_0061CEA0(O61A728 *o) {
    s32 r = 0;
    V61A728 *v;

    if (func_L39_005C1018(o) != 0) {
        r = func_L39_005C1018(o)->f32(o);
        if (r != 0) {
            return r;
        }
    }
    while (o->parent != 0) {
        o = o->parent;
    }
    v = func_L39_005C1018(o);
    if (v != 0) {
        r = v->f4(o);
    }
    return r;
}
/* localdecomp:end func_L39_0061CEA0 */

/* localdecomp:start func_L39_0061CF40 */
extern s32 func_L39_0061CEA0(O61A728 *o);

u8 *func_L39_0061CF40(void) {
    u8 *p = ((u8 * (*)())func_L39_0061CEA0)();
    if (p != 0 && (p[3] & 0xF) == 0) {
        return p;
    }
    return 0;
}
/* localdecomp:end func_L39_0061CF40 */

INCLUDE_ASM("asm/levels", func_L39_0061CF78);
