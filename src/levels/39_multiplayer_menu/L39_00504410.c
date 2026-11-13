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
