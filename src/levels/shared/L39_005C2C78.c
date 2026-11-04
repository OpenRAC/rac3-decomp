#include "common.h"

typedef struct Rec_005C2C78 {
    void *f0;
    u8 pad4[0xA - 4];
    s16 h0A;
    u8 pad0C[0x20 - 0xC];
    s32 f20;
} Rec_005C2C78;
typedef struct Glob_005C2C78 {
    u8 pad0[0x94];
    u8 f94[4];
    s16 h98;
    s16 h9A;
    s16 h9C;
    u8 pad9E[0xB0 - 0x9E];
    s32 fB0;
} Glob_005C2C78;
typedef struct Slot_005C2C78 {
    u8 pad0[0xC0];
    void *fC0;
} Slot_005C2C78;

/* localdecomp:start func_L39_005C2C78 */
extern u8 D_1FE020[];
extern u8 D_225660[];
extern void func_L39_005C1700(s32 a0, s32 a1, s32 a2, void *a3, s32 a4);

void func_L39_005C2C78(void *a0, long a1)
{
    Rec_005C2C78 *n = (Rec_005C2C78 *)a1;
    Glob_005C2C78 *g;
    s32 i;

    if (n == 0)
        return;
    n->f0 = a0;
    i = n->f20;
    if (i >= 0) {
        Slot_005C2C78 *s = (Slot_005C2C78 *)(D_1FE020 + (i << 7));
        s->fC0 = a0;
    }
    if (a0 != 0) {
        if (n->h0A == 1)
            n->h0A = 2;
    } else {
        g = (Glob_005C2C78 *)D_225660;
        func_L39_005C1700(g->h98, g->h9C, g->fB0, g->f94, g->h9A);
    }
}
/* localdecomp:end func_L39_005C2C78 */
