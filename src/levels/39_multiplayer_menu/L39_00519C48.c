#include "common.h"

/* localdecomp:start func_L39_00519C48 */
extern s32 func_0011D534(void *, s32, s32);
extern s32 func_001487E8(void *, s32, void *);
extern s32 func_00148860(void *, s32, s32, s32);
extern s32 func_L39_00519468(s32);

typedef struct {
    u8 pad0[0x14];
    u8 f14[0x40];
    s32 f54;
} A_00519C48;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[4];
    s32 f14;
    s32 f18;
    u8 f1C[0x10];
    s32 f2C;
} B_00519C48;

s32 func_L39_00519C48(A_00519C48 *a, B_00519C48 *b) {
    s32 r;
    s32 k;

    if (b->fC != 0) {
        return 0;
    }
    if (b->f14 != 0 && b->f14 != 3) {
        return 0x80;
    }
    func_0011D534(b->f1C, 0, 0x10);
    b->f2C = 0;
    if (b->f18 == 0) {
        b->f18 = -1;
    }
    r = func_001487E8(a->f14, a->f54, &b->f14);
    if (r <= 0) {
        return func_L39_00519468(r);
    }
    k = a->f54;
    b->fC = r;
    r = func_00148860(a->f14, k, r, -1);
    if (r < 0) {
        return func_L39_00519468(r);
    }
    return 0;
}
/* localdecomp:end func_L39_00519C48 */

INCLUDE_ASM("asm/levels", func_L39_00519D08);

INCLUDE_ASM("asm/levels", func_L39_00519EB8);
