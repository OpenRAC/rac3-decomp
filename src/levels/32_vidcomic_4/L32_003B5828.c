#include "common.h"

/* localdecomp:start func_L32_003B5828 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_L32_003B6C88(void *);
extern void func_L32_003B6408(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L32_003B6DD0(void *);
extern void func_L32_003B70F8(void *);
extern void func_L32_003B7190(void *, void *);

void func_L32_003B5828(void *arg0) {
    u8 buf[16] __attribute__((aligned(16)));

    *(u128_t *)buf = *(u128_t *)((u8 *)arg0 + 0x10);
    switch (*(u8 *)((u8 *)arg0 + 0x20)) {
    case 1:
        func_L32_003B6C88(arg0);
        break;
    case 0:
        func_L32_003B6408(arg0);
        func_L01_004450F0(arg0, 5, -1);
        break;
    case 2:
    case 3:
    case 4:
        func_L32_003B6DD0(arg0);
        break;
    case 5:
        func_L32_003B70F8(arg0);
        break;
    }
    func_L32_003B7190(arg0, buf);
}
/* localdecomp:end func_L32_003B5828 */

INCLUDE_ASM("asm/levels", func_L32_003B58D0);

INCLUDE_ASM("asm/levels", func_L32_003B5C98);
