#include "common.h"

/* localdecomp:start func_L01_002FD0A0 */
/* Ported from rac2-decomp/src/game/0030F7B0-g8.c. */
extern float D_001DC474_sda_002FD0A0 __attribute__((sda));
__asm__(".extern D_001DC474_sda_002FD0A0, 4");
extern char D_L01_001E1740_002FD0A0[] __attribute__((section(".sdata")));

void func_L01_002FD0A0(void *object)
{
    extern float func_00389380(float, float);
    extern float func_00388960(float);
    extern int func_003894A0(int, int, float);
    extern void func_L01_002FD7E8(void *);
    extern void func_003D3FA0(char *, int, unsigned int, int, float, float, float);
    float angle = func_00389380(D_001DC474_sda_002FD0A0, 0.125f);
    float scale;
    float size_a;
    float size_b;
    float size_c;
    int colour_a;
    int colour_b;
    int colour_c;

    D_001DC474_sda_002FD0A0 = angle;
    scale = func_00388960(angle);
    scale = (scale + 1.0f) * 0.5f;
    size_b = scale * 0.0625f + 0.0625f;
    size_c = scale * 0.19999999f + 0.15f;
    size_a = scale * 0.125f + 0.125f;

    colour_a = func_003894A0(0x2F007F00, 0x3F007F00, scale);
    colour_b = func_003894A0(0x2F7F7F7F, 0x5F7F7F7F, scale);
    colour_c = func_003894A0(0x10208040, 0x10208040, scale);

    func_L01_002FD7E8(object);
    func_003D3FA0(D_L01_001E1740_002FD0A0, 0x31, colour_a, 1, size_a, 0.125f, 0.0f);
    func_003D3FA0(D_L01_001E1740_002FD0A0, 0x31, colour_b, 1, size_b, 0.124f, 0.0f);
    func_003D3FA0(D_L01_001E1740_002FD0A0, 0x0B, colour_c, 1, size_c, 0.123f, 0.0f);
}

/* localdecomp:end func_L01_002FD0A0 */
