#include "common.h"

typedef struct {
    u8 pad0[0x80];
    u8 pad80[0x25C4 - 0x80];
    s32 f25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 f25E4;
    u8 pad25E5[0x284C - 0x25E5];
    f32 f284C;
} G_003E7528;

/* localdecomp:start func_L22_003E9550 */
/* PAL port of the NTSC-U match src/us/levels/func_L22_003E7528.c */


extern G_003E7528 D_001A4BE0_003E7528;
extern s32 func_L01_00456500(void *, s32);
extern void func_0038A238(s32);
extern void func_L01_004EDE10(void);
extern void func_L01_005003D0(s32, s32);

void func_L22_003E9550(u8 *obj)
{
    s32 *p = *(s32 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
        obj[0x30] = 0xFF;
        break;
    case 1:
        if (p[2] >= 0 && func_L01_00456500((u8 *)&D_001A4BE0_003E7528 + 0x80, p[2]) != 0) {
            break;
        }
        if (p[0] >= 0 && func_L01_00456500((u8 *)&D_001A4BE0_003E7528 + 0x80, p[0]) != 0) {
            if (p[4] != 0) {
                D_001A4BE0_003E7528.f284C = 0.25f;
            } else if (D_001A4BE0_003E7528.f25E4 != 0) {
                func_0038A238(8);
                func_L01_004EDE10();
            } else {
                if (D_001A4BE0_003E7528.f25C4 != 0x79) {
                    func_L01_005003D0(0x79, 1);
                }
            }
        }
        if (p[1] >= 0 && func_L01_00456500((u8 *)&D_001A4BE0_003E7528 + 0x80, p[1]) != 0) {
            func_0038A238(8);
            func_L01_004EDE10();
        }
        break;
    }
}
/* localdecomp:end func_L22_003E9550 */
