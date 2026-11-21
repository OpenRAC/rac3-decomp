#include "common.h"

/* NTSC-U counterpart of func_L13_0044DB78 (src/levels/shared/L13_0044DB78.c): lifetime 0x37 frames for 60 Hz */
/* localdecomp:start func_L13_0044A168 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0044DB78;
extern u8 *func_L01_0045E438(s32);
extern f32 func_0037E250(f32, f32);
extern u8 *D_L13_0021F0B8[];

void func_L13_0044A168(u128_t *pos, s32 kind, V4_0044DB78 vec, f32 scale)
{
    u8 *p = func_L01_0045E438(0x49);
    f32 f;
    s32 c;

    if (p != 0) {
        f = 0.0f;
        c = 0;
        switch (kind) {
        case 0:
            f = 0.12f;
            func_0037E250(0.25f, 0.25f);
            c = 0x20;
            break;
        case 1:
            f = 0.5f;
            func_0037E250(1.0f, 1.0f);
            c = 0xD;
            break;
        }
        *(s16 *)(p + 0xA) = 0x37;
        *(u32 *)(p + 4) = (c << 24) | 0xFFFFFF;
        p[9] = 0x24;
        p[3] = 0x48;
        p[1] = 0;
        p[2] = D_L13_0021F0B8[1][kind];
        *(f32 *)(p + 0xC) = f * 210000.0f;
        p[8] = (s32)func_0037E250(0.0f, 360.0f);
        *(u128_t *)(p + 0x10) = *pos;
        *(V4_0044DB78 *)(p + 0x20) = vec;
        *(f32 *)(p + 0x2C) = scale;
    }
}
/* localdecomp:end func_L13_0044A168 */
