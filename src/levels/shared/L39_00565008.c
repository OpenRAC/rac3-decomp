#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00565008);

INCLUDE_ASM("asm/levels", func_L39_005651F0);

/* localdecomp:start func_L39_00565750 */
typedef int u128_t __attribute__((mode(TI)));

extern char *func_003C24B0(s32, s32);

/* from rac2-decomp's func_L11_004349F8 */
char *func_L39_00565750(char *obj, void *a, void *b, s32 c, s32 d, f32 f12, f32 f13, f32 f14) {
    u128_t t[2];
    u128_t *saved = &t[1];
    char *n;
    char *st;

    t[0] = *(u128_t *)a;
    *saved = *(u128_t *)b;
    n = func_003C24B0(0x1B79, 0x80);
    if (n != 0) {
        *(u8 *)(n + 0x30) = 0xFF;
        *(u16 *)(n + 0x32) = 0xFF;
        *(u8 *)(n + 0x31) = 1;
        *(u8 *)(n + 0x20) = 0;
        *(char **)(n + 0xB8) = obj;
        st = *(char **)(n + 0x68);
        *(long *)(n + 0x38) = *(long *)(obj + 0x38);
        *(u128_t *)(n + 0x10) = *(u128_t *)st;
        *(u128_t *)st = t[0];
        *(u128_t *)(st + 0x20) = *saved;
        *(f32 *)(st + 0x4C) = f14;
        *(f32 *)(st + 0x3C) = f12;
        *(s32 *)(st + 0x44) = c;
        *(s32 *)(st + 0x48) = d;
        *(s32 *)(st + 0x38) = 0;
        *(s32 *)(st + 0x34) = 0;
        *(f32 *)(n + 0x2C) = f13;
    }
    return n;
}
/* localdecomp:end func_L39_00565750 */
