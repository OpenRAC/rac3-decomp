#include "common.h"

/* localdecomp:start func_L39_004D5B50 */
typedef struct S_004D5B50 {
    u8 pad0[0x106C8];
    s32 x106C8;
    u8 pad106CC[0x106D8 - 0x106CC];
    s32 x106D8;
    u8 pad106DC[0x106F8 - 0x106DC];
    s32 x106F8;
} S_004D5B50;
extern S_004D5B50 D_L39_00453FB0;
extern s32 func_00126150(void);
extern s32 func_L01_003EC898_004D5B50(s32);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern s32 func_L39_004B3E10(void);

s32 func_L39_004D5B50(void) {
    S_004D5B50 *g;

    if (func_L01_003EC898_004D5B50(func_00126150()) < 0) {
        return 0;
    }
    g = &D_L39_00453FB0;
    for (;;) {
        func_001262A0(g->x106D8);
        func_001262A0(g->x106C8);
        g->x106F8 = 1;
        func_00126280(g->x106C8);
        func_L39_004B3E10();
    }
}
/* localdecomp:end func_L39_004D5B50 */

INCLUDE_ASM("asm/levels", func_L39_004D5BE8);
