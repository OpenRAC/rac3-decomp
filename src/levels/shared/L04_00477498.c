#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L04_00477498 */
extern char *func_L01_004618E0(int);
extern int func_13D3E0(void);
extern unsigned char *D_L04_0021FC84[];

void *func_L04_00477498(void *pos, void *dir, int color, int a3, float f)
{
    char *e;
    char *p;

    e = func_L01_004618E0(0x1B);
    if (e != 0) {
        *(u128_t *)(e + 0x10) = *(u128_t *)pos;
        p = e + 0x20;
        *(unsigned char *)(e + 8) = func_13D3E0();
        *(unsigned char *)(e + 9) = 0x74;
        *(unsigned char *)(e + 3) = 0x48;
        *(float *)(e + 0xC) = f;
        *(int *)(e + 4) = color;
        *(unsigned char *)(e + 1) = 0;
        *(unsigned char *)(e + 2) = **D_L04_0021FC84;
        *(int *)(p + 0x18) = color >> 24;
        *(u128_t *)p = *(u128_t *)dir;
        *(int *)(p + 0x10) = a3;
        *(int *)(p + 0x14) = a3;
    }
    return e;
}
/* localdecomp:end func_L04_00477498 */
