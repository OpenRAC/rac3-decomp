#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005FFD10);

/* localdecomp:start func_L39_005FFD20 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);

s32 func_L39_005FFD20(f32 dt, f32 *a, s32 *cnt, s32 flag) {
    s32 r;
    u32 c, c0, c1;
    *cnt += 1;
    if (*cnt > 20) {
        *cnt = 20;
    }
    *a = func_0038DAB8(*a, dt * 0.017453292f * 0.0200000014f);
    c = (*cnt * 5) << 24;
    c0 = c | 0xFF0F;
    c1 = c | 0xFFFFFF;
    r = func_0038DBD8(func_0038D0B0(*a) * 0.5f + 0.5f, c0, c1);
    if (flag) {
        r = 0x600000FF;
    }
    return r;
}
/* localdecomp:end func_L39_005FFD20 */

/* localdecomp:start func_L39_005FFDF8 */
typedef struct S_005FFDF8_b { u8 pad00[0x10]; s32 f10; } S_005FFDF8_b;
typedef struct S_005FFDF8_a { u8 pad00[0x24]; S_005FFDF8_b *f24; u8 pad28[0x98 - 0x28]; s32 f98; } S_005FFDF8_a;
typedef struct S_005FFDF8_c { u8 pad00[0x2548]; s32 f2548; } S_005FFDF8_c;
extern S_005FFDF8_c *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern S_005FFDF8_a *D_L39_002C2840[8][4];

void func_L39_005FFDF8(s32 a0) {
    s32 i, j;
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CE20[i] != 0 && D_L39_0024CE20[i]->f2548 == a0) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            S_005FFDF8_a *p = D_L39_002C2840[i][j];
            if (p != 0) {
                p->f98 = p->f24->f10;
            }
        }
    }
}
/* localdecomp:end func_L39_005FFDF8 */
