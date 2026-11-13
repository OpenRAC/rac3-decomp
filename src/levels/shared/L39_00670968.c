#include "common.h"

/* localdecomp:start func_L39_00670968 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} E_00670968;

typedef struct {
    u8 pad0[0x1A8];
    s32 f1A8;
    E_00670968 e[3];
} G_00670968;

typedef struct {
    u8 pad0[0x2544];
    s32 f2544;
} R_00670968;

extern G_00670968 D_L39_00352940;
extern s32 *D_L39_00241120;
extern R_00670968 *func_L39_0061BF38(s32);

void func_L39_00670968(s32 arg0, s32 arg1, s32 arg2) {
    s32 best = 0;
    s32 min;
    s32 i;
    s32 id;
    R_00670968 *r;

    D_L39_00352940.f1A8++;
    min = D_L39_00352940.e[0].fC;
    if (*D_L39_00241120 < 3) {
        if (D_L39_00352940.f1A8 >= 4) {
            D_L39_00352940.f1A8 = 3;
        }
    } else {
        if (D_L39_00352940.f1A8 >= 3) {
            D_L39_00352940.f1A8 = 2;
        }
    }
    if (min > 0) {
        for (i = 0; i < (*D_L39_00241120 < 3 ? 3 : 2); i++) {
            if (D_L39_00352940.e[i].fC < min) {
                min = D_L39_00352940.e[i].fC;
                best = i;
            }
        }
    }
    id = -1;
    r = func_L39_0061BF38(0);
    if (r != 0) {
        id = r->f2544;
    }
    if (arg0 == id) {
        D_L39_00352940.e[best].f10 = 0x2D;
        D_L39_00352940.e[best].fC = 0xB4;
    } else {
        D_L39_00352940.e[best].f10 = 0xF;
        D_L39_00352940.e[best].fC = 0x78;
    }
    D_L39_00352940.e[best].f0 = arg0;
    D_L39_00352940.e[best].f4 = arg1;
    D_L39_00352940.e[best].f8 = arg2;
}
/* localdecomp:end func_L39_00670968 */

INCLUDE_ASM("asm/levels", func_L39_00670AE0);

INCLUDE_ASM("asm/levels", func_L39_00670C50);

INCLUDE_ASM("asm/levels", func_L39_00670D90);

INCLUDE_ASM("asm/levels", func_L39_00671448);
