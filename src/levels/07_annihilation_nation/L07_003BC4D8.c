#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* declared by functions of L07_003BB360.c, which this file was cut from */
extern s32 func_L07_003A2380_003BB840(s32, s32, s32, s32) __asm__("func_L07_003A2380");

/* localdecomp:start func_L07_003BC4D8 */
typedef int Q_003BC4D8 __attribute__((mode(TI)));
extern void func_L01_00445F40(void *, s32);
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L07_003BCD80(void *);
/* localdecomp:start func_L07_003BC4D8 */
void func_L07_003BC4D8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *sub;
    u8 *g;
    u8 *other;
    s32 mode;
    f32 scale;
    func_L01_00445F40(obj, 0x19D2);
    sub = p + 0x120;
    mode = func_L07_003C1AF8();
    scale = func_L07_003C1B40(mode);
    *(s16 *)(sub + 4) = (s16)(*(s16 *)(p + 0x124) * scale);
    *(f32 *)(p + 0x120) = *(s16 *)(sub + 4);
    sub[0x14] = (u8)(p[0x134] * scale);
    sub[0x15] = (u8)(p[0x135] * scale);
    sub[0x16] = (u8)(p[0x136] * scale);
    if (mode == 1 || mode == 3) func_L01_00446058(obj, 0x1D88, 0x19D2);
    sub[0x28] = 20;
    sub[0x2A] = 14;
    *(f32 *)(sub + 0x10) = 0.25f;
    sub[9] = 0;
    *(Q_003BC4D8 *)(p + 0x240) = *(Q_003BC4D8 *)(obj + 0x10);
    *(Q_003BC4D8 *)(p + 0x250) = *(Q_003BC4D8 *)(obj + 0xF0);
    other = p + 0x160;
    other[0x10] = 7;
    other[0x48] = 255;
    other[0x11] = 255;
    other[0x12] = 255;
    g = p + 0x30;
    *(f32 *)(p + 0x30) = 0.8f;
    *(u32 *)(g + 0x38) |= 0x404;
    *(f32 *)(g + 4) = -0.3f;
    *(f32 *)(g + 0x34) = 0.3f;
    *(f32 *)(g + 0x2C) = 0.003920000046491623f;
    *(f32 *)(g + 0xB4) = 0.1256637126f;
    *(f32 *)(g + 0x14) = 0.005026548635214567f;
    *(f32 *)(g + 0x18) = 0.005026548635214567f;
    *(s32 *)(g + 0xEC) = 0;
    obj[0x62] = 0;
    func_L07_003BCD80(obj);
}
/* localdecomp:end func_L07_003BC4D8 */
/* localdecomp:end func_L07_003BC4D8 */

INCLUDE_ASM("asm/levels", func_L07_003BC6C0);

/* localdecomp:start func_L07_003BCB10 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003BCB10(void *arg0, s32 arg1) {
    switch (arg1) {
    case 1: case 2: case 3: case 4: case 5:
    case 6: case 7: case 8: case 9: case 10:
        if (((u8 *)arg0)[0x43] != 0) func_003C3A10(arg0, 0, 0, 7);
        break;
    case 11:
        if (((u8 *)arg0)[0x43] != 1) func_003C3A10(arg0, 1, 0, 7);
        break;
    case 12:
        if (((u8 *)arg0)[0x43] != 3) func_003C3A10(arg0, 3, 0, 7);
        break;
    case 13: case 14:
        if (((u8 *)arg0)[0x43] != 3) func_003C3A10(arg0, 3, 0, 7);
        break;
    }
    func_L01_004450F0(arg0, arg1, -1);
}
/* localdecomp:end func_L07_003BCB10 */
