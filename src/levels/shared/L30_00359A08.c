#include "common.h"

typedef struct Ent_00359D78 {
    u8 pad[0x20];
    u8 type;
    u8 pad2[0xDF];
} Ent_00359D78;
typedef struct Obj_00359D78 {
    u8 pad[4];
    s32 i4;
    s32 i8;
    u8 pad2[0x94];
    s32 fA0[3];
} Obj_00359D78;

INCLUDE_ASM("asm/levels", func_L30_00359A08);

/* localdecomp:start func_L30_00359D78 */
extern Ent_00359D78 *D_L30_001DF71C;
extern u8 D_L30_001E2240[];
extern void func_L30_00358180(u8 *m, u8 *p, s32 n);

void func_L30_00359D78(u8 *m) {
    Obj_00359D78 *v = *(Obj_00359D78 **)(m + 0x68);
    s32 r = -1;

    if (v->fA0[1] == 0) {
        if (D_L30_001DF71C[v->i4].type == 0x42) {
            r = 0;
        }
    }
    if (v->fA0[2] == 0) {
        if (D_L30_001DF71C[v->i8].type == 0x42) {
            r = 1;
        }
    }
    if (r != -1) {
        v->fA0[r + 1] = 1;
        func_L30_00358180(m, D_L30_001E2240, 500);
    }
}
/* localdecomp:end func_L30_00359D78 */

/* localdecomp:start func_L30_00359E20 */
typedef struct Obj_00359E20 {
    u8 pad[4];
    s32 i4;
    s32 i8;
    s32 iC;
    s32 i10;
    u8 pad2[0x90];
    s32 fA4[3];
} Obj_00359E20;
extern u8 D_00142660[];
extern void func_L01_00456230(void *, s32);

void func_L30_00359E20(u8 *m) {
    Obj_00359E20 *v = *(Obj_00359E20 **)(m + 0x68);

    v->fA4[0] = 0;
    v->fA4[1] = 0;
    v->fA4[2] = 0;
    if (D_00142660[0x77] & 2) {
        v->fA4[0] = 3;
        func_L01_00456230(&D_L30_001DF71C[v->iC], 1);
        D_L30_001DF71C[v->i4].type = 0x42;
    }
    if (D_00142660[0x77] & 4) {
        v->fA4[1] = 3;
        func_L01_00456230(&D_L30_001DF71C[v->i10], 1);
        D_L30_001DF71C[v->i8].type = 0x42;
    }
}
/* localdecomp:end func_L30_00359E20 */
