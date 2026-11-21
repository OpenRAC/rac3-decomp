/* Near miss: 15 diffs, all in the dispatch. Retail keeps the constant 1 in $a2 (shared with the case-1 store of 1) and the switch value in $v1, and fills the first beq delay slot with lui $v0,0x35; ours uses $v0 for 1, $a2 for the value, slti in the delay slot. The three case bodies match exactly. */
#include "common.h"
typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, bA;
    u8 pad[0x6A8 - 0xB];
    s32 f6A8;
} T_006787B0;
typedef struct {
    u8 pad0[0x180];
    s32 f180;
    s8 s184[4];
    s8 s188;
    u8 pad189[6];
    s8 s18F;
    u8 pad190[4];
    s8 s194;
    u8 pad195[5];
    s8 s19A;
    s8 s19B;
    s8 s19C;
    u8 pad19D[2];
    u8 u19F;
} O_006787B0;
extern O_006787B0 *D_L39_00241640_006787B0;
__asm__(".extern D_L39_00241640_006787B0, 16");

void func_L39_006787B0(void) {
    O_006787B0 *o = D_L39_00241640_006787B0;
    switch (o->f180) {
    case 1: {
        T_006787B0 *t;
        *(u8 *)&D_L39_00352CE0 = 0;
        t = (T_006787B0 *)&D_L39_00352CE0;
        t->b1 = 0;
        t->b2 = 1;
        t->b3 = t->f6A8 == 0;
        t->b4 = o->u19F != 0;
        t->b5 = o->s188 != 0;
        t->b6 = o->s18F != 0;
        t->b7 = o->s194 != 0;
        t->b8 = o->s19B == 0;
        t->b9 = o->s19A == 0;
        t->bA = o->s19C == 0;
        break;
    }
    case 0: {
        T_006787B0 *t;
        *(u8 *)&D_L39_00352CE0 = 0;
        t = (T_006787B0 *)&D_L39_00352CE0;
        t->b1 = 0;
        t->b2 = 0;
        t->b3 = t->f6A8 == 0;
        t->b4 = o->u19F != 0;
        t->b5 = o->s188 != 0;
        t->b6 = o->s18F != 0;
        t->b7 = o->s194 == 0;
        t->b8 = o->s19B == 0;
        t->b9 = o->s19A == 0;
        t->bA = o->s19C == 0;
        break;
    }
    case 2: {
        T_006787B0 *t;
        *(u8 *)&D_L39_00352CE0 = 0;
        t = (T_006787B0 *)&D_L39_00352CE0;
        t->b1 = 0;
        t->b2 = 0;
        t->b3 = t->f6A8 == 0;
        t->b4 = o->u19F != 0;
        t->b5 = o->s188 != 0;
        t->b6 = o->s18F == 0;
        t->b7 = o->s194 == 0;
        t->b8 = o->s19B == 0;
        t->b9 = o->s19A == 0;
        t->bA = o->s19C == 0;
        break;
    }
    }
}
