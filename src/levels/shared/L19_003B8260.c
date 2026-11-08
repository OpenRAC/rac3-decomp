#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_003B8260 */
extern char *func_003C24B0(s32, s32);
extern s32 D_L19_001DF240;
__asm__(".extern D_L19_001DF240, 16");

char *func_L19_003B8260(s32 a0, void *a1, void *a2, s32 a3, s32 t0, s32 t1) {
    char *n = func_003C24B0(0x1AEA, 0x80);
    char *st;

    if (n != 0) {
        *(u8 *)(n + 0x20) = 0;
        *(u8 *)(n + 0x30) = 0xFF;
        st = *(char **)(n + 0x68);
        *(u128_t *)(n + 0x10) = *(u128_t *)a1;
        *(u128_t *)st = *(u128_t *)a1;
        *(u128_t *)(st + 0x10) = *(u128_t *)a2;
        *(s32 *)(st + 0x2C) = t1;
        *(s32 *)(st + 0x20) = a3;
        *(s32 *)(st + 0x24) = D_L19_001DF240 + 0x64;
        *(s32 *)(st + 0x28) = a0;
    }
    return n;
}
/* localdecomp:end func_L19_003B8260 */

INCLUDE_ASM("asm/levels", func_L19_003B8310);

INCLUDE_ASM("asm/levels", func_L19_003B86E8);
