#include "common.h"

/* NTSC-U counterpart of func_L39_005CEC38 (src/levels/shared/L39_005CEC38.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005CC828 */
extern char *func_003CD108_005CC828(int);
extern int func_L39_005B2498(int);
extern float func_L39_005B25C8_005CC828(void);
extern float func_L39_005B2510(float, float);
extern float func_0038D098_005CC828(float);
extern float func_0038D0B0_005CC828(float);
extern int func_0019D650(void);
extern unsigned char *D_L39_00296A20[];

void *func_L39_005CC828(void *pos, int color, float size, float f)
{
    char *e;
    char *p;
    float ang;
    float mag;
    int c;

    e = func_003CD108_005CC828(0x42);
    if (e != 0) {
        *(u128_t *)(e + 0x10) = *(u128_t *)pos;
        if (color == -1)
            c = ((func_L39_005B2498(6) + 0x14) << 24) | 0x808080;
        else
            c = color;
        *(int *)(e + 4) = c;
        *(unsigned char *)(e + 9) = 0x21;
        *(unsigned char *)(e + 3) = 0x48;
        *(unsigned char *)(e + 1) = 1;
        if (func_L39_005B2498(0x100) & 1)
            *(unsigned char *)(e + 2) = (*D_L39_00296A20)[0];
        else
            *(unsigned char *)(e + 2) = (*D_L39_00296A20)[1];
        *(unsigned char *)(e + 8) = func_0019D650();
        p = e + 0x20;
        *(float *)(e + 0xC) = size * 210000.0f;
        *(short *)(e + 0xA) = 4;
        ang = func_L39_005B25C8_005CC828();
        mag = func_L39_005B2510(0.0015f, 0.0025f);
        *(float *)p = func_0038D098_005CC828(ang) * mag;
        *(float *)(p + 4) = func_0038D0B0_005CC828(ang) * mag;
        *(float *)(p + 0x10) = f;
        *(int *)(p + 8) = 0;
    }
    return e;
}
/* localdecomp:end func_L39_005CC828 */
