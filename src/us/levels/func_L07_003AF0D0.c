#include "common.h"

/* localdecomp:start func_L07_003AF0D0 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3AF0D0;
extern s32 D_L07_001DEF40_003AF0D0;
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_004632D8(V4_3AF0D0 *, V4_3AF0D0 *, s32, s32, f32, s32);

void func_L07_003AF0D0(u8 *a0) {
    V4_3AF0D0 pos;
    V4_3AF0D0 vel;
    V4_3AF0D0 tmp;
    f32 ang;
    f32 r;
    f32 sa;
    f32 sb;
    f32 life;
    s32 c;
    s32 color;
    V4_3AF0D0 *pv;

    if (D_L07_001DEF40_003AF0D0 & 3) {
        pos = *(V4_3AF0D0 *)(a0 + 0x10);
        pos.z += 0.5f;
        ang = func_0037E2A8();
        r = func_0037E250(0.0f, 0.5f);
        pos.x += func_00388960(ang) * r;
        pos.y += func_00388978(ang) * r;
        sa = func_0037E250(0.0083333338f, 0.033333335f);
        sb = func_0037E250(0.033333335f, 0.066666670f);
        tmp = (V4_3AF0D0){0.0f, 0.0f, 0.0f, 0.0f};
        tmp.x = sa * func_00388960(ang);
        tmp.y = sa * func_00388978(ang);
        tmp.z = sb;
        vel = tmp;
        c = func_0037E208(8, 16) & 0xFF;
        color = 0x80000000 | (c << 16) | (c << 8) | c;
        pv = &vel;
        life = func_0037E250(315000.0f, 630000.0f);
        func_L01_004632D8(&pos, pv, color, 0x101010, life, func_0037E208(0x3C, 0x50));
    }
}
/* localdecomp:end func_L07_003AF0D0 */
