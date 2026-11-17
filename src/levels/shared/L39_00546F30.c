#include "common.h"

/* localdecomp:start func_L39_00546F30 */
typedef struct {
    char pad0[0x3];
    u8 flags;
} Ent;

extern Ent *func_L39_0061D7B0(s32);

void func_L39_00546F30(s32 id, f32 *a, f32 *b) {
    Ent *e = func_L39_0061D7B0(id);
    Ent *r;

    r = 0;
    if (e != 0) {
        if (e->flags & 0xF) {
            r = 0;
        } else {
            r = e;
        }
    }

    if (r != 0) {
        if (a != 0) {
            *a = 4.0f;
        }
        if (b != 0) {
            *b = 7.0f;
        }
    } else {
        if (a != 0) {
            *a = 7.0f;
        }
        if (b != 0) {
            *b = 15.0f;
        }
    }
}
/* localdecomp:end func_L39_00546F30 */

INCLUDE_ASM("asm/levels", func_L39_00546FE0);

INCLUDE_ASM("asm/levels", func_L39_00547E10);
