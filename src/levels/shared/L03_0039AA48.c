#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039AA48);

INCLUDE_ASM("asm/levels", func_L03_0039AE90);

/* localdecomp:start func_L03_0039AFB0 */
typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003998B0;

extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);

s32 func_L03_0039AFB0(Moby_003998B0 *m) {
    s32 r;
    s32 id = *(s32 *)(m->w68 + 1272);
    if (id == -1) {
        r = 0;
    } else {
        r = func_00382380(D_001A4C60, id, 0) != 0;
    }
    return r;
}
/* localdecomp:end func_L03_0039AFB0 */

INCLUDE_ASM("asm/levels", func_L03_0039AFF0);

/* localdecomp:start func_L03_0039B248 */
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

void func_L03_0039B248(u8 *a) {
    if (a[32] == 0) {
        *(s32 *)(*(u8 **)(a + 104) + 8) = 0;
        func_L01_004450F0(a, 4, -1);
    }
}
/* localdecomp:end func_L03_0039B248 */

INCLUDE_ASM("asm/levels", func_L03_0039B280);
