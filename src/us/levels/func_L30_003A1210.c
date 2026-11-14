#include "common.h"

/* NTSC-U counterpart of func_L30_003A2C68 (src/levels/shared/L30_003A2C68.c) */
typedef struct { u8 pad[0x30]; u8 x30[0x20]; s32 x50; u8 pad54[0x6C - 0x54]; f32 x6C; u8 pad70[8]; f32 x78; } V_3A1500;
typedef struct { u8 pad[0x68]; V_3A1500 *x68; u8 pad6C[0xF0 - 0x6C]; f32 xF0; } O_3A1500;

/* localdecomp:start func_L30_003A1210 */
extern s32 D_L30_001DE9B8;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L30_003A1210(O_3A1500 *a0, s32 a1) {
    u8 *o = (u8 *)a0;

    func_L01_00441FB8(a0, a1, -1);
    switch (o[0x20]) {
    case 1:
        if (o[0x43] == 1) {
            return;
        }
        func_003BE4F0(a0, 1, 0, D_L30_001DE9B8);
        return;
    case 66:
        if (o[0x43] != 5) {
            func_003BE4F0(a0, 5, 0, D_L30_001DE9B8);
        }
        *(f32 *)(o + 0x48) = 1.0f;
        return;
    case 2:
    case 3:
        if (o[0x43] == 3) {
            return;
        }
        func_003BE4F0(a0, 3, 0, D_L30_001DE9B8);
        return;
    case 4:
        if (o[0x43] != 0) {
            func_003BE4F0(a0, 0, 0, 0);
        }
        *(f32 *)(o + 0x48) = 1.0f;
        return;
    case 5:
        if (o[0x43] != 4) {
            func_003BE4F0(a0, 4, 0, D_L30_001DE9B8);
        }
        *(f32 *)(o + 0x48) = 1.0f;
        return;
    case 6:
        if (o[0x43] == 5) {
            return;
        }
        func_003BE4F0(a0, 5, 0, 2);
        return;
    case 7:
        if (o[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, D_L30_001DE9B8);
        }
        *(f32 *)(o + 0x48) = 1.0f;
        return;
    case 0:
        break;
    }
}
/* localdecomp:end func_L30_003A1210 */
