#include "common.h"

/* NTSC-U counterpart of func_L13_0042C630 (src/levels/shared/L13_0042C630.c) */
typedef struct { float f[4]; } BurstVector __attribute__((aligned(16)));
typedef struct { int values[6]; } BurstPalette;
typedef struct {
    float offset[4];
    unsigned char colors[16];
    float radius[3], intensity, falloff;
    int value34, value38;
    unsigned char options[4];
    unsigned short timers[4];
    unsigned char flags48, flags49;
} BurstFlashTemplate;

/* localdecomp:start func_L13_00429058 */
#include "vu0.h"

extern BurstPalette D_L13_001D7AB8_00429058[], D_L13_001D7AD0_00429058[];
extern BurstFlashTemplate D_L13_002E8600[] __attribute__((aligned(16)));
extern float func_0037E250(float, float);
extern int func_0037E1D8(int);
extern int func_L01_00445C50(unsigned int, int);
extern int func_0037E208(int, int);
extern char *func_L01_00461128(void *, void *, int, int, float, int, int, int, int, float);
extern void func_L01_00445BF0(int *, int *, int *, int);
extern char *func_L01_002F95A0(char *, char *, char *, float, int,
                          unsigned char, unsigned char, unsigned char, unsigned char);
extern char *func_L01_00300650(char *, void *, int, void *);

void func_L13_00429058(char *parent, char *position, float scale, float flash)
{
    BurstVector zero;
    BurstPalette first, second;
    int rgb[3];
    int i;
    float speed, size, glow;
    qzero(&zero);
    for (i = 2; i >= 0; i--) {
        int firstColor, secondColor, life, fadeLife;
        speed = func_0037E250(8.0f, 10.0f) * 0.0166666675f;
        size = scale * 500000.0f;
        first = D_L13_001D7AB8_00429058[0];
        second = D_L13_001D7AD0_00429058[0];
        firstColor = func_L01_00445C50(first.values[func_0037E1D8(6)], 1);
        secondColor = func_L01_00445C50(second.values[func_0037E1D8(6)], 1);
        life = func_0037E208(15, 20);
        fadeLife = func_0037E208(25, 30);
        func_L01_00461128(position, &zero, firstColor, secondColor,
                      size, life, fadeLife, 0, 0, speed * scale);
    }
    if (parent) {
        rgb[0] = 127; rgb[1] = 64; rgb[2] = 0;
        func_L01_00445BF0(rgb, rgb + 1, rgb + 2, 1);
        glow = scale * 4.0f;
        func_L01_002F95A0(parent, position, (char *)&zero, glow, 20,
                      *(unsigned char *)&rgb[0], *(unsigned char *)&rgb[1],
                      *(unsigned char *)&rgb[2], 48);
        rgb[0] = 96; rgb[1] = 32; rgb[2] = 0;
        func_L01_00445BF0(rgb, rgb + 1, rgb + 2, 1);
        glow = scale * 3.0f;
        func_L01_002F95A0(parent, position, (char *)&zero, glow, 29,
                      *(unsigned char *)&rgb[0], *(unsigned char *)&rgb[1],
                      *(unsigned char *)&rgb[2], 32);
    }
    if (flash != 0.0f) {
        if (flash > 0.0f) {
            D_L13_002E8600[0].radius[1] = flash;
            D_L13_002E8600[0].radius[2] = flash;
            D_L13_002E8600[0].radius[0] = flash;
        } else {
            D_L13_002E8600[0].radius[1] = 13.0f;
            D_L13_002E8600[0].radius[2] = 13.0f;
            D_L13_002E8600[0].radius[0] = 13.0f;
        }
        func_L01_00300650((char *)D_L13_002E8600, position, 0, 0);
    }
}
/* localdecomp:end func_L13_00429058 */
