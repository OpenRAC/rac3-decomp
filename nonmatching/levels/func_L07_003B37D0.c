/* PAL near miss (Codex wave 10): held at landing (5f54b6f2): the C matches on its own (tools/check.py, every place), but in the level build its .rodata lands at another address than retail's.
 */
#include "common.h"
/* localdecomp:start func_L07_003B37D0 */
void func_L07_003B37D0(u8 *obj, s32 state) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_00456230(void *, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: case 3: break;
    case 2:
        if (obj[0x43] != 1) func_003C3A10(obj, 1, 0, 0);
        break;
    case 4:
        *(f32 *)(p + 0xC8) = 0.20000001788139343f;
        *(u16 *)(obj + 0x34) |= 0x5000;
        break;
    case 5:
        *(s16 *)(p + 0x664) = ((func_00382468(10) + 20) * 5 + 2) / 6;
        if (obj[0x95] >= 2) {
            if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 2);
        } else {
            if (obj[0x43] != 1) func_003C3A10(obj, 1, 0, 2);
        }
        *(f32 *)(p + 0xC8) = 0.20000001788139343f;
        *(s32 *)(p + 0xD8) |= 0x10;
        break;
    case 6:
        *(s16 *)(p + 0x660) = ((func_00382468(30) + 60) * 5 + 2) / 6;
        break;
    case 7:
        func_L01_00456230(obj, 0);
        p[0x66A] = 0;
        *(f32 *)(p + 0xC8) = (func_003824E0(0.0f, 1.0f) + 3.0f) * 0.020000001415610313f;
        *(f32 *)(p + 0x658) = func_003824E0(0.0f, 2.0f);
        *(f32 *)(p + 0x65C) = func_003824E0(0.0f, 2.0f);
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 3);
        break;
    case 8:
        *(s16 *)(p + 0x660) = 42;
        break;
    case 9:
        p[0x667] = 1 << func_00382498(0, 1);
        *(s16 *)(p + 0x660) = ((func_00382468(30) + 60) * 5 + 2) / 6;
        break;
    case 10:
        func_L01_00456230(obj, 0);
        if (obj[0x43] != 4) func_003C3A10(obj, 4, 0, 0);
        break;
    case 11:
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 0);
        break;
    case 12:
        p[0x66A] = 0;
        p[0x667] = 3;
        if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 2);
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003B37D0 */
