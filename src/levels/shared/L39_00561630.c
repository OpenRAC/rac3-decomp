#include "common.h"

/* localdecomp:start func_L39_00561630 */
typedef struct {
    u8 pad0[0x18];
    s32 x18;
    u8 pad1C[0x10];
    f32 x2C;
} S_00561630;

typedef struct {
    u8 pad0[0x68];
    S_00561630 *p68;
} O_00561630;

extern f32 D_L39_0024B460;
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L39_00561630(O_00561630 *a0, u8 *a1) {
    S_00561630 *p = a0->p68;
    if (p->x2C > 0.0f) {
        func_L01_003303B8(a1, 0, 0, 20, 20, 10, 45, 0, D_L39_0024B460, 0.0f, (f32)p->x18, p->x2C,
                          0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    } else {
        func_L01_003303B8(a1, 0, 0, 20, 20, 10, 45, 0, D_L39_0024B460, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
}
/* localdecomp:end func_L39_00561630 */

INCLUDE_ASM("asm/levels", func_L39_005617D8);

INCLUDE_ASM("asm/levels", func_L39_00561D28);
