#include "common.h"

/* NTSC-U counterpart of func_L39_00647150 (src/levels/shared/L39_00646980.c) */
/* localdecomp:start func_L39_00644920 */
#include "vu0.h"

typedef struct { u8 pad[0xA4]; u8 flags[0x100]; } Tab_00647150;
extern Tab_00647150 D_001A5990;
extern void func_0038CF68_00644920(void *, s32, f32);

void func_L39_00644920(u8 *o, s32 mode) {
    if (mode == 0) {
        D_001A5990.flags[*(s32 *)(o + 0x2544)] = 0;
        qzero(o + 0x1260);
        qzero(o + 0x1270);
        *(f32 *)(o + 0x132C) = 1.15f;
        *(u16 *)(o + 0x1280) |= 1;
        *(f32 *)(o + 0x1254) = 1.5533431f;
        *(f32 *)(o + 0x1258) = -1.5533431f;
        *(s32 *)(o + 0x1310) = 0;
        *(u16 *)(o + 0x3E4) = 0;
    } else {
        func_0038CF68_00644920(o + 0x1190, *(s32 *)(o + 0x2530) + 0x380, 1.0f);
        qzero(o + 0x1260);
        qzero(o + 0x1270);
        *(u16 *)(o + 0x1280) &= 0xFFFE;
        switch (mode) {
        case 2: {
            f32 p = 1.5533431f;
            f32 n = -1.5533431f;
            f32 c = 1.15f;
            D_001A5990.flags[*(s32 *)(o + 0x2544)] = mode;
            *(s32 *)(o + 0x1310) = mode;
            *(f32 *)(o + 0x1254) = p;
            *(f32 *)(o + 0x1258) = n;
            *(f32 *)(o + 0x132C) = c;
            break;
        }
        case 1: {
            f32 a = -6.0f;
            f32 b = 6.0f;
            f32 c = 1.2217305f;
            f32 e = -1.2217305f;
            f32 g = 2.0f;
            D_001A5990.flags[*(s32 *)(o + 0x2544)] = mode;
            *(f32 *)(o + 0x132C) = g;
            *(s32 *)(o + 0x1310) = mode;
            *(f32 *)(o + 0x1260) = a;
            *(f32 *)(o + 0x12C4) = b;
            *(f32 *)(o + 0x1254) = c;
            *(f32 *)(o + 0x1258) = e;
            *(s32 *)(o + 0x1268) = 0;
            break;
        }
        }
    }
}
/* localdecomp:end func_L39_00644920 */
