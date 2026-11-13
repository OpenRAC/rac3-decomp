#include "common.h"

/* NTSC-U counterpart of func_L30_0034C300 (src/levels/shared/L30_0034BE60.c): 200 -> 240 */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_0034B420 */
extern char *func_003C24B0(s32, s32);
extern float func_0038D160(float, float);
extern float func_0038CED8(char *);

char *func_L30_0034B420(char *object, char *a1, char *a2, s32 a3, s32 a4, float f12) {
    char *s1 = func_003C24B0(0x1614, 0x80);
    char *s0;
    float d;

    if (s1 != 0) {
        *(u8 *)(s1 + 0x30) = 0xFF;
        *(u16 *)(s1 + 0x32) = 0xFF;
        *(u8 *)(s1 + 0x31) = 1;
        *(u8 *)(s1 + 0x20) = 0;
        s0 = *(char **)(s1 + 0x68);
        *(long *)(s1 + 0x38) = *(long *)(object + 0x38);
        *(u128_t *)(s1 + 0x10) = *(u128_t *)a2;
        *(u128_t *)s0 = *(u128_t *)a1;
        *(s32 *)(s0 + 0x10) = 240;
        *(s32 *)(s0 + 0x1C) = -1;
        *(char **)(s0 + 0x14) = object;
        *(float *)(s0 + 0x18) = f12;
        *(s32 *)(s0 + 0x20) = a3;
        *(s32 *)(s0 + 0x24) = a4;
        *(s32 *)(s0 + 0x28) = -1;
        *(s32 *)(s0 + 0x2C) = 0;
        *(float *)(s1 + 0xF8) = func_0038D160(*(float *)a1, *(float *)(a1 + 4));
        d = func_0038CED8(a1);
        *(float *)(s1 + 0xF4) = -func_0038D160(d, *(float *)(a1 + 8));
    }
    return s1;
}
/* localdecomp:end func_L30_0034B420 */
