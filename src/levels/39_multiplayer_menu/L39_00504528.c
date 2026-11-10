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

/* localdecomp:start func_L39_00504528 */
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);

void *func_L39_00504528(void) {
    void *p = func_L39_004BEED8(0x60);
    if (p == 0) {
        func_L39_004BC6C8(6, 0x72, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x60);
    return p;
}
/* localdecomp:end func_L39_00504528 */

INCLUDE_ASM("asm/levels", func_L39_00504588);
