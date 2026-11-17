#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* declared by functions of L07_003BB360.c, which this file was cut from */
extern s32 func_L07_003A2380_003BB840(s32, s32, s32, s32) __asm__("func_L07_003A2380");

INCLUDE_ASM("asm/levels", func_L07_003BC4D8);

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
