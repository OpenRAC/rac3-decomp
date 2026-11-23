#include "common.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;

/* localdecomp:start func_L01_0033AC58 */
__asm__(".extern D_L01_001DCFB8, 4");
extern s32 D_L01_001DCFB8;
s32 *func_L01_0033AC58(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L01_001DCFB8;
    }
    return 0;
}
/* localdecomp:end func_L01_0033AC58 */

INCLUDE_ASM("asm/levels", func_L01_0033AC78);

INCLUDE_ASM("asm/levels", func_L01_0033B530);

INCLUDE_ASM("asm/levels", func_L01_0033B7C0);

INCLUDE_ASM("asm/levels", func_L01_0033C030);

/* localdecomp:start func_L01_0033C4B8 */
__asm__(".extern D_L01_001DCFB4, 4");

extern s32 D_001D545C[];
extern s32 D_L01_001DCFB4;
extern void func_L01_00459C50(s32 a0);

void func_L01_0033C4B8(S_33BDC8 *a0) {
    if (D_001D545C[0] == 8) {
        if (a0->f18 < 330.0f) {
            D_L01_001DCFB4++;
        }
        if (D_L01_001DCFB4 >= 46) {
            func_L01_00459C50(12);
        }
    }
}
/* localdecomp:end func_L01_0033C4B8 */

INCLUDE_ASM("asm/levels", func_L01_0033C520);

LINKER_REMNANT("asm/levels", func_L01_0033CBB8);
