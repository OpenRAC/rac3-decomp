#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067BBE8 */
extern void *D_L39_00240504 __attribute__((section(".data")));
extern u8 *D_L39_00240508 __attribute__((section(".data")));
void func_0011D534(void *, s32, s32);
void func_0011D380(void *, void *, s32);

void func_L39_0067BBE8(u8 *arg0) {
    u8 *p = arg0 + 0x2D;
    func_0011D534(p, 0, 0x20);
    *(s32 *)(arg0 + 0x28) = 0;
    if (D_L39_00240504 != 0) {
        arg0[0x2C] = *D_L39_00240508;
        func_0011D380(p, D_L39_00240504, arg0[0x2C]);
    }
}
/* localdecomp:end func_L39_0067BBE8 */
