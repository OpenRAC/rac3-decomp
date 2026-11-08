#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L16_003E8580 */
extern float D_001DF618;
__asm__(".extern D_001DF618, 4");
extern char *func_003C24B0(s32, s32);
extern void func_L01_00456160(char *, char *);
extern float func_00382538(void);

char *func_L16_003E8580(char *object, char *a1, char *a2, char *a3, float f12, float f13) {
    char *s1 = func_003C24B0(0x1D29, 0x80);
    char *s0;

    if (s1 != 0) {
        *(u8 *)(s1 + 0x30) = 0xFF;
        *(u16 *)(s1 + 0x32) = 0xFF;
        *(u8 *)(s1 + 0x31) = 1;
        *(char **)(s1 + 0xB8) = object;
        s0 = *(char **)(s1 + 0x68);
        *(long *)(s1 + 0x38) = *(long *)(object + 0x38);
        func_L01_00456160(s1, object);
        *(float *)(s1 + 0x2C) = *(float *)(s1 + 0x2C) * D_001DF618;
        *(u128_t *)(s1 + 0xC0) = *(u128_t *)(object + 0xC0);
        *(u128_t *)(s1 + 0xD0) = *(u128_t *)(object + 0xD0);
        *(u128_t *)(s1 + 0xE0) = *(u128_t *)(object + 0xE0);
        *(u128_t *)(s1 + 0x10) = *(u128_t *)a1;
        *(char **)(s0 + 0x20) = object;
        *(float *)(s0 + 0x28) = f12;
        *(float *)(s0 + 0x30) = f13;
        *(s32 *)(s0 + 0x24) = 0;
        *(u128_t *)(s0 + 0x10) = *(u128_t *)a3;
        *(u128_t *)s0 = *(u128_t *)a2;
        *(float *)(s0 + 0x2C) = func_00382538();
    }
    return s1;
}
/* localdecomp:end func_L16_003E8580 */

INCLUDE_ASM("asm/levels", func_L16_003E8690);
