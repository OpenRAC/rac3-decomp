#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005CEC38 */
extern char *func_003CD108(int);
extern int func_L39_005B4398(int);
extern float func_L39_005B44C8(void);
extern float func_L39_005B4410(float, float);
extern float func_0038D098(float);
extern float func_0038D0B0(float);
extern int func_19D510(void);
extern unsigned char *D_L39_00296920[];

void *func_L39_005CEC38(void *pos, int color, float size, float f)
{
    char *e;
    char *p;
    float ang;
    float mag;
    int c;

    e = func_003CD108(0x42);
    if (e != 0) {
        *(u128_t *)(e + 0x10) = *(u128_t *)pos;
        if (color == -1)
            c = ((func_L39_005B4398(6) + 0x14) << 24) | 0x808080;
        else
            c = color;
        *(int *)(e + 4) = c;
        *(unsigned char *)(e + 9) = 0x21;
        *(unsigned char *)(e + 3) = 0x48;
        *(unsigned char *)(e + 1) = 1;
        if (func_L39_005B4398(0x100) & 1)
            *(unsigned char *)(e + 2) = (*D_L39_00296920)[0];
        else
            *(unsigned char *)(e + 2) = (*D_L39_00296920)[1];
        *(unsigned char *)(e + 8) = func_19D510();
        p = e + 0x20;
        *(float *)(e + 0xC) = size * 210000.0f;
        *(short *)(e + 0xA) = 4;
        ang = func_L39_005B44C8();
        mag = func_L39_005B4410(0.0015f, 0.0025f);
        *(float *)p = func_0038D098(ang) * mag;
        *(float *)(p + 4) = func_0038D0B0(ang) * mag;
        *(float *)(p + 0x10) = f;
        *(int *)(p + 8) = 0;
    }
    return e;
}
/* localdecomp:end func_L39_005CEC38 */
