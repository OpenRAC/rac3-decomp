#include "common.h"

/* localdecomp:start func_L33_003A4920 */
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L33_003A4920(u8 *o) {
    switch (o[0x20]) {
    case 0:
        if (func_L01_00456250(o) != 0) {
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            func_L01_003303B8(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                              1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
        }
        break;
    }
}
/* localdecomp:end func_L33_003A4920 */
