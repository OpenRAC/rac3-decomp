#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0032EF80);

/* localdecomp:start func_L02_0032F1C8 */
typedef struct {
    s32 f0;
    s32 f4;
} S_B_0032F1C8;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x0F];
    u8 f30;
    u8 pad31[0x37];
    S_B_0032F1C8 *f68;
} S_A_0032F1C8;

void func_L02_0032F1C8(S_A_0032F1C8 *p) {
    if (p->f20 == 0) {
        p->f68->f4 = -1;
        p->f30 = 0xFF;
        p->f20 = 1;
    }
}
/* localdecomp:end func_L02_0032F1C8 */
