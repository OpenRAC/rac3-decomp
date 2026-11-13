#include "common.h"

/* NTSC-U counterpart of func_L39_00684230 (src/levels/39_multiplayer_menu/L39_00684230.c): 37 -> 45 */
extern s32 func_L01_00512AB0(s32, s32, s32);
s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L39_0060EF10(s32);

/* localdecomp:start func_L39_00681710 */
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512FE8(s32, s32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00514020(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003825F8(u32, u32, s32, s32, s32, s32);

void func_L39_00681710(void *arg0) {
    f32 buf[4];
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    s32 color;

    if (*(s32 *)((u8 *)arg0 + 0xB4) == -1) {
        return;
    }
    func_L01_00512AB0(*(s32 *)((u8 *)arg0 + 0xB4), 1, 0);
    func_L01_00512AB0(*(s32 *)((u8 *)arg0 + 0xB8), 1, 0);
    if (*(s32 *)((u8 *)arg0 + 0x4) == 0) {
        func_L01_00512AB0(*(s32 *)((u8 *)arg0 + 0xBC), 1, 0);
        return;
    }
    func_L01_00512AB0(*(s32 *)((u8 *)arg0 + 0xBC), 1, 1);
    if (*(s32 *)((u8 *)arg0 + 0x4) == 2) {
        color = 0x80808080;
    } else if (*(s32 *)((u8 *)arg0 + 0x4) == 3) {
        color = *(s32 *)((u8 *)arg0 + 0xC8);
    } else if (*(s32 *)((u8 *)arg0 + 0x4) == 4) {
        color = func_003825F8(0x8066CCFF, 0x66D6EEFA, 0x2D, 1, 0, 1);
    } else if (*(s32 *)((u8 *)arg0 + 0x4) == 5) {
        color = 0x66D6EEFA;
    } else {
        color = *(s32 *)((u8 *)arg0 + 0xC8);
    }
    (*(void (**)(void *, f32 *, f32 *))(*(u8 **)((u8 *)arg0 + 0x60) + 0x30))(arg0, &x, &y);
    if (*((u8 *)arg0 + 0x14) != 0) {
        func_L01_00512FE8(*(s32 *)((u8 *)arg0 + 0xB4), (s32)((u8 *)arg0 + 0x14));
        func_L01_00512480(*(s32 *)((u8 *)arg0 + 0xB4), x, y);
        func_L01_005130C8(*(s32 *)((u8 *)arg0 + 0xB4), color);
        ((s32 (*)(s32, f32 *))func_L39_0060EF10)(*(s32 *)((u8 *)arg0 + 0xB4), buf);
        x = buf[2] + 0.005f;
        func_L01_00512480(*(s32 *)((u8 *)arg0 + 0xB8), x, y);
        func_L01_005130C8(*(s32 *)((u8 *)arg0 + 0xB8), color);
        ((s32 (*)(s32, f32 *))func_L39_0060EF10)(*(s32 *)((u8 *)arg0 + 0xB8), buf);
        x = buf[2] + 0.005f;
        func_L01_00512AB0(*(s32 *)((u8 *)arg0 + 0xB4), 1, 1);
        func_L01_00512AB0(*(s32 *)((u8 *)arg0 + 0xB8), 1, 1);
    }
    if (*(s32 *)((u8 *)arg0 + 0xC0) != 0) {
        (*(void (**)(void *, f32 *, f32 *))(*(u8 **)((u8 *)arg0 + 0x60) + 0x30))(arg0, &x2, &y2);
        if (*((u8 *)arg0 + 0xCC) != 0) {
            if (func_L01_00514020(*(s32 *)((u8 *)arg0 + 0xBC), 1) != 0) {
                func_003E8898(*(s32 *)((u8 *)arg0 + 0xBC), x2 + *(f32 *)((u8 *)arg0 + 0x58) - x, 0.0f);
            }
        }
        func_L01_00512480(*(s32 *)((u8 *)arg0 + 0xBC), x2 + *(f32 *)((u8 *)arg0 + 0x58), y2);
    } else {
        func_L01_00512480(*(s32 *)((u8 *)arg0 + 0xBC), x, y);
    }
    func_L01_00512FE8(*(s32 *)((u8 *)arg0 + 0xBC), (s32)((u8 *)arg0 + 0x64));
    func_L01_005130C8(*(s32 *)((u8 *)arg0 + 0xBC), color);
}
/* localdecomp:end func_L39_00681710 */
