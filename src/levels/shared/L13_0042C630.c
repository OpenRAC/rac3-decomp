#include "common.h"

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

/* localdecomp:start func_L13_0042C630 */
#include "vu0.h"

extern BurstPalette D_L13_001D7AB8[], D_L13_001D7AD0[];
extern BurstFlashTemplate D_L13_002E85C0[] __attribute__((aligned(16)));
extern void func_00282C88(void *);
extern float func_003824E0(float, float);
extern int func_00382468(int);
extern int func_L01_00448D88(unsigned int, int);
extern int func_00382498(int, int);
extern char *func_L01_00464690(void *, void *, int, int, float, int, int, int, int, float);
extern void func_L01_00448D28(int *, int *, int *, int);
extern char *func_L01_002F9578(char *, char *, char *, float, int,
                          unsigned char, unsigned char, unsigned char, unsigned char);
extern char *func_L01_003006C0(char *, void *, int, void *);

void func_L13_0042C630(char *parent, char *position, float scale, float flash)
{
    BurstVector zero;
    BurstPalette first, second;
    int rgb[3];
    int i;
    float speed, size, glow;
    qzero(&zero);
    for (i = 2; i >= 0; i--) {
        int firstColor, secondColor, life, fadeLife;
        speed = func_003824E0(8.0f, 10.0f) * 0.020000001f;
        size = scale * 500000.0f;
        first = D_L13_001D7AB8[0];
        second = D_L13_001D7AD0[0];
        firstColor = func_L01_00448D88(first.values[func_00382468(6)], 1);
        secondColor = func_L01_00448D88(second.values[func_00382468(6)], 1);
        life = func_00382498(12, 17);
        fadeLife = func_00382498(21, 25);
        func_L01_00464690(position, &zero, firstColor, secondColor,
                      size, life, fadeLife, 0, 0, speed * scale);
    }
    if (parent) {
        rgb[0] = 127; rgb[1] = 64; rgb[2] = 0;
        func_L01_00448D28(rgb, rgb + 1, rgb + 2, 1);
        glow = scale * 4.0f;
        func_L01_002F9578(parent, position, (char *)&zero, glow, 17,
                      *(unsigned char *)&rgb[0], *(unsigned char *)&rgb[1],
                      *(unsigned char *)&rgb[2], 48);
        rgb[0] = 96; rgb[1] = 32; rgb[2] = 0;
        func_L01_00448D28(rgb, rgb + 1, rgb + 2, 1);
        glow = scale * 3.0f;
        func_L01_002F9578(parent, position, (char *)&zero, glow, 24,
                      *(unsigned char *)&rgb[0], *(unsigned char *)&rgb[1],
                      *(unsigned char *)&rgb[2], 32);
    }
    if (flash != 0.0f) {
        if (flash > 0.0f) {
            D_L13_002E85C0[0].radius[1] = flash;
            D_L13_002E85C0[0].radius[2] = flash;
            D_L13_002E85C0[0].radius[0] = flash;
        } else {
            D_L13_002E85C0[0].radius[1] = 13.0f;
            D_L13_002E85C0[0].radius[2] = 13.0f;
            D_L13_002E85C0[0].radius[0] = 13.0f;
        }
        func_L01_003006C0((char *)D_L13_002E85C0, position, 0, 0);
    }
}
/* localdecomp:end func_L13_0042C630 */
