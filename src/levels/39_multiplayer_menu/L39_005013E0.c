#include "common.h"

typedef struct S_00504410 {
    u8 pad[0x20];
    u8 *f20;
    void (*f24)(void);
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} S_00504410;

INCLUDE_ASM("asm/levels", func_L39_005013E0);

INCLUDE_ASM("asm/levels", func_L39_00501658);

INCLUDE_ASM("asm/levels", func_L39_005017A0);

INCLUDE_ASM("asm/levels", func_L39_00501B08);

INCLUDE_ASM("asm/levels", func_L39_00502618);

INCLUDE_ASM("asm/levels", func_L39_00502FF8);

INCLUDE_ASM("asm/levels", func_L39_005031A8);

INCLUDE_ASM("asm/levels", func_L39_00503360);

INCLUDE_ASM("asm/levels", func_L39_00503B20);

INCLUDE_ASM("asm/levels", func_L39_005042F8);

/* localdecomp:start func_L39_00504410 */
extern u8 D_L39_0050C0B8[];
extern void func_L39_0050C110(void);
extern S_00504410 *func_L39_004DBA08(void);

s32 func_L39_00504410(void) {
    S_00504410 *p = func_L39_004DBA08();

    p->f20 = D_L39_0050C0B8;
    p->f24 = func_L39_0050C110;
    p->f28 = 0;
    p->f2C = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f38 = 0;
    return 1;
}
/* localdecomp:end func_L39_00504410 */

INCLUDE_ASM("asm/levels", func_L39_00504460);

INCLUDE_ASM("asm/levels", func_L39_00504488);

INCLUDE_ASM("asm/levels", func_L39_005044B0);

INCLUDE_ASM("asm/levels", func_L39_005044D8);

INCLUDE_ASM("asm/levels", func_L39_00504500);

INCLUDE_ASM("asm/levels", func_L39_00504528);

INCLUDE_ASM("asm/levels", func_L39_00504588);

INCLUDE_ASM("asm/levels", func_L39_005045A8);

INCLUDE_ASM("asm/levels", func_L39_005045C0);

INCLUDE_ASM("asm/levels", func_L39_005047E8);

INCLUDE_ASM("asm/levels", func_L39_00504970);

INCLUDE_ASM("asm/levels", func_L39_005049D8);

INCLUDE_ASM("asm/levels", func_L39_00504A30);

INCLUDE_ASM("asm/levels", func_L39_00504A58);

INCLUDE_ASM("asm/levels", func_L39_00504B50);

INCLUDE_ASM("asm/levels", func_L39_00504B90);

INCLUDE_ASM("asm/levels", func_L39_00504C80);

/* localdecomp:start func_L39_00504DF8 */
s32 func_L39_00504DF8(s32 arg0) {
    return arg0 + 0x2C;
}
/* localdecomp:end func_L39_00504DF8 */

INCLUDE_ASM("asm/levels", func_L39_00504E00);
