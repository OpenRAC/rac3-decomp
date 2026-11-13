#include "common.h"

/* localdecomp:start func_L39_0066E010 */
typedef struct S_0066E010q {
    u8 pad0[0x38];
    s32 w38;
} S_0066E010q;

typedef struct S_0066E010p {
    u8 pad0[4];
    S_0066E010q *w4;
} S_0066E010p;

typedef struct S_0066E010 {
    u8 pad0[0x2558];
    S_0066E010p *w2558;
} S_0066E010;

typedef struct S_0066E010d {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x170 - 0xC];
    s32 w170;
} S_0066E010d;

extern S_0066E010d D_001A5CD0;
extern S_0066E010 *func_L39_0061C488(s32);
extern s32 *func_L39_00668620(s32);
extern s32 *func_L39_0066C238(s32);
extern s32 func_L39_0066E100(s32, s32, s32, s32, s32, s32, s32, void *);

s32 func_L39_0066E010(void *a0, s32 a1, void *a2, s32 a3, void *a4) {
    S_0066E010 *pl;
    s32 *e;
    s32 id;
    S_0066E010d *d = &D_001A5CD0;
    if (d->w8 < 0 || d->w170 != 0) {
        return -1;
    }
    id = 0;
    pl = func_L39_0061C488(a3);
    if (pl != 0) {
        id = pl->w2558->w4->w38;
    } else {
        e = func_L39_00668620(a3);
        if (e != 0) {
            id = *e;
        } else {
            e = func_L39_0066C238(a3);
            if (e != 0) {
                id = *e;
            }
        }
    }
    return func_L39_0066E100(((S_0066E010 *)a0)->w2558->w4->w38, id, a1, 1, 0, 0, (s32)a2, a4);
}
/* localdecomp:end func_L39_0066E010 */

INCLUDE_ASM("asm/levels", func_L39_0066E100);
