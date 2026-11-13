#include "common.h"

/* NTSC-U counterpart of func_L39_005C8990 (src/levels/shared/L39_005C8990.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005C6678 */
extern void *func_003CD108_005C6678(int);
extern int func_0019D650(void);
extern unsigned char *D_L39_0029696C[];

void *func_L39_005C6678(void *a0, void *a1, int a2, int a3, int a4, int a5, float f)
{
    char *p;
    char *q;

    if (a4 == 0)
        return 0;
    p = func_003CD108_005C6678(0x15);
    if (p != 0) {
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
        *(int *)(p + 4) = a2;
        *(unsigned char *)(p + 1) = 0;
        *(float *)(p + 0xC) = f;
        *(unsigned char *)(p + 9) = 0xA4;
        *(unsigned char *)(p + 3) = 0x48;
        *(unsigned char *)(p + 8) = func_0019D650();
        q = p + 0x20;
        *(unsigned char *)(p + 2) = **D_L39_0029696C;
        *(short *)(p + 0xA) = a4;
        *(short *)(q + 0x18) = a4;
        *(float *)(q + 0x1C) = f;
        *(int *)(q + 0x10) = a2;
        *(int *)(q + 0x14) = a3;
        *(short *)(q + 0x1A) = a5;
        *(u128_t *)q = *(u128_t *)a1;
    }
    return p;
}
/* localdecomp:end func_L39_005C6678 */
