#include "common.h"

typedef struct S_003B4630_1 { u8 p0[0x1C]; s32 f1C; } S_003B4630_1;
typedef struct S_003B4630_0 { u8 p0[0x20]; u8 f20; u8 p21[0x47]; S_003B4630_1 *f68; } S_003B4630_0;
typedef struct S_1CCFD0_003B4630 { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[0x24]; s32 f94; } S_1CCFD0_003B4630;

/* localdecomp:start func_L31_003B4630 */
extern S_1CCFD0_003B4630 D_001CCFD0;
extern void func_L31_003B46C8(void);
extern void func_L01_004450F0(S_003B4630_0 *, s32, s32);
extern void func_L31_003B4768(S_003B4630_0 *);
extern void func_L31_003B46E0(S_003B4630_0 *);

void func_L31_003B4630(S_003B4630_0 *p) {
    S_003B4630_1 *q = p->f68;
    S_1CCFD0_003B4630 *g;

    if (p->f20 == 0) {
        func_L31_003B46C8();
        func_L01_004450F0(p, 1, -1);
    }
    g = &D_001CCFD0;
    if (g->f6C == 0 && g->f24 == -1 && g->f94 == 0 && q->f1C == 0) {
        func_L31_003B4768(p);
    }
    func_L31_003B46E0(p);
}
/* localdecomp:end func_L31_003B4630 */

INCLUDE_ASM("asm/levels", func_L31_003B46C8);

INCLUDE_ASM("asm/levels", func_L31_003B46E0);

INCLUDE_ASM("asm/levels", func_L31_003B4768);
