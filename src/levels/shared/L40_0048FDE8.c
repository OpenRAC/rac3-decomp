#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_0048FDE8);

INCLUDE_ASM("asm/levels", func_L40_0048FF90);

INCLUDE_ASM("asm/levels", func_L40_00490080);

/* localdecomp:start func_L40_004903C8 */
typedef struct {
    u8 pad0[0x20];
    s16 h20[8];
    f32 f30[8];
    u8 pad50[0x10];
} S_004903C8;

extern S_004903C8 D_L40_002926E0[];

void func_L40_004903C8(s32 a, s32 b, f32 v) {
    S_004903C8 *ea = &D_L40_002926E0[a];
    S_004903C8 *eb = &D_L40_002926E0[b];
    s32 ra = -1;
    s32 rb = -1;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (ea->h20[i] == -1) {
            ra = i;
            break;
        }
    }
    for (i = 0; i < 8; i++) {
        if (eb->h20[i] == -1) {
            rb = i;
            break;
        }
    }
    if (ra != -1 && rb != -1) {
        ea->h20[ra] = b;
        ea->f30[ra] = v;
        eb->h20[rb] = a;
        eb->f30[rb] = v;
    }
}
/* localdecomp:end func_L40_004903C8 */

INCLUDE_ASM("asm/levels", func_L40_004904B8);
