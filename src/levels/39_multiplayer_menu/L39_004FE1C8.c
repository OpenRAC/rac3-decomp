#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FE1C8 */
typedef struct { u8 b[16]; } V16_4FE1C8;
extern s32 D_L39_0046EA54 __attribute__((section(".data")));
extern V16_4FE1C8 D_L39_00453B48[];
s32 func_L39_004FE1C8(s32 idx) {
    s32 n = D_L39_0046EA54;
    s32 i;
    if (idx < n) {
        for (i = idx; i + 1 < n; i++) {
            D_L39_00453B48[i] = (D_L39_00453B48 + 1)[i];
        }
        D_L39_0046EA54--;
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_004FE1C8 */

INCLUDE_ASM("asm/levels", func_L39_004FE250);

LINKER_REMNANT("asm/levels", func_L39_004FE320);

INCLUDE_ASM("asm/levels", func_L39_004FE328);

INCLUDE_ASM("asm/levels", func_L39_004FE608);

INCLUDE_ASM("asm/levels", func_L39_004FE6B0);

INCLUDE_ASM("asm/levels", func_L39_004FE728);

INCLUDE_ASM("asm/levels", func_L39_004FECA0);

INCLUDE_ASM("asm/levels", func_L39_004FF3AC);

/* localdecomp:start func_L39_004FF3C0 */
typedef struct { void *f0; u8 pad[0xC]; void *f10; s32 f14; s32 f18; s32 f1c; } S_004FF3C0;
extern void *func_L39_004BEED8(s32);
extern void func_11D534(void *, s32, s32);
extern void func_L39_004FCF88(void *);
s32 func_L39_004FF3C0(void *a0, s32 *a1) {
    S_004FF3C0 *p = func_L39_004BEED8(0x78);
    if (p == 0) {
        return 1;
    }
    func_11D534(p, 0, 0x20);
    p->f0 = a0;
    p->f10 = p + 1;
    func_L39_004FCF88(p + 1);
    p->f14 = 0;
    p->f18 = 0;
    *a1 = (s32)p;
    return 0;
}
/* localdecomp:end func_L39_004FF3C0 */
