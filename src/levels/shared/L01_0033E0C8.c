#include "common.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);


INCLUDE_ASM("asm/levels", func_L01_0033E0C8);

INCLUDE_ASM("asm/levels", func_L01_0033E290);

INCLUDE_ASM("asm/levels", func_L01_0033E2D0);

LINKER_REMNANT("asm/levels", func_L01_0033E758);

INCLUDE_ASM("asm/levels", func_L01_0033E760);

LINKER_REMNANT("asm/levels", func_L01_0033ED28);

INCLUDE_ASM("asm/levels", func_L01_0033ED30);

INCLUDE_ASM("asm/levels", func_L01_0033EE50);

INCLUDE_ASM("asm/levels", func_L01_0033EF90);

INCLUDE_ASM("asm/levels", func_L01_0033F1F0);

INCLUDE_ASM("asm/levels", func_L01_0033F388);

INCLUDE_ASM("asm/levels", func_L01_0033F530);

INCLUDE_ASM("asm/levels", func_L01_0033F920);

/* localdecomp:start func_L01_00340248 */
extern s16 D_L01_001E18D0[];
extern s16 D_L01_001E18E0[];
extern s16 D_L01_001E18E8[];
extern f32 D_L01_001E18F8[];
extern s32 D_L01_001E18F0[];
extern s32 D_L01_001DD158;
extern s32 D_L01_001DD15C;
extern s32 D_L01_001E18F4;

void func_L01_00340248(void) {
    s32 i;
    s32 two = 2;
    s32 one = 1;
    s16 *r = D_L01_001E18E8;
    s16 *q = D_L01_001E18E0;
    s16 *p = D_L01_001E18D0;

    for (i = 3; i >= 0; i--) {
        *p++ = two;
        *q++ = two;
        *r++ = one;
    }
    D_L01_001E18F8[0] = 1.0f;
    D_L01_001E18F0[0] = (D_L01_001DD158 * 5 + 2) / 6;
    D_L01_001E18F4 = (D_L01_001DD15C * 5 + 2) / 6;
}
/* localdecomp:end func_L01_00340248 */

INCLUDE_ASM("asm/levels", func_L01_003402E8);

INCLUDE_ASM("asm/levels", func_L01_003405B8);
