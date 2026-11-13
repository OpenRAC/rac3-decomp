#include "common.h"

/* NTSC-U counterpart of func_L39_0067FD38 (src/levels/39_multiplayer_menu/L39_0067FAE8.c): 37 -> 45 */
s32 func_L01_00512AB0(s32, s32, s32);
s32 func_L01_005130C8(s32, s32);

/* localdecomp:start func_L39_0067D218 */
s32 func_L01_00512FE8(s32, void *);
s32 func_L01_00512AB0(s32, s32, s32);
s32 func_L01_005130C8(s32, s32);
u32 func_003825F8(u32, u32, s32, s32, s32, s32);
s32 func_L01_00512480(s32, f32, f32);

void func_L39_0067D218(void *arg0) {
    u8 *p = arg0;
    u32 color;
    f32 x, y;
    u32 base;
    s32 st;

    if (*(s32 *)(p + 0x64) == -1) {
        return;
    }
    color = 0x8066CCFF;
    func_L01_00512FE8(*(s32 *)(p + 0x64), p + 0x14);
    if (*(s32 *)(p + 0x4) == 0) {
        func_L01_00512AB0(*(s32 *)(p + 0x64), 1, 0);
        return;
    }
    func_L01_00512AB0(*(s32 *)(p + 0x64), 1, 1);
    base = *(u32 *)(p + 0x68);
    st = *(s32 *)(p + 0x4);
    if (base == 0) {
        if (st == 2) {
            color = 0x80808080;
        } else if (st == 3) {
            /* keeps the default colour */
        } else if (st == 4) {
            color = func_003825F8(0x8066CCFF, 0x66D6EEFA, 0x2D, 1, 0, 1);
        } else if (st == 5) {
            color = 0x66D6EEFA;
        }
    } else if (st == 4) {
        color = func_003825F8(base, 0x66D6EEFA, 0x2D, 1, 0, 1);
    } else {
        color = base;
    }
    func_L01_005130C8(*(s32 *)(p + 0x64), color);
    (*(void (**)(void *, f32 *, f32 *))(*(u8 **)(p + 0x60) + 0x30))(p, &x, &y);
    func_L01_00512480(*(s32 *)(p + 0x64), x, y);
}
/* localdecomp:end func_L39_0067D218 */
