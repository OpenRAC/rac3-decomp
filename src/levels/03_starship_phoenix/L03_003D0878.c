#include "common.h"

/* localdecomp:start func_L03_003D0878 */
typedef struct { s32 f00; u8 pad04[0x20]; s32 f24; } S_003D0878a;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } S_003D0878b;
extern S_003D0878a D_L03_002E52F0;
extern u16 D_00143954[];
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern S_003D0878b *D_001D52FC;
extern s32 D_001DF4C0;
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
void func_L03_003D0878(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    s32 flag = 0;
    s32 i;
    for (i = 0xB0; i < 0xBF; i++) {
        if (D_001426E0[i] == 1) flag = 1;
    }
    if ((D_L03_002E52F0.f00 == 0 && D_L03_002E52F0.f24 == -1) || D_00143954[0] == 0) {
        if (func_00382380(D_001A4C60, *p, 0) != 0 && flag != 0) {
            func_L01_00452560(0, 9, 0xF06, 1, 0, 0, 0);
            if (D_001D52FC->f1A4 & 0x10) {
                func_003A0EC0(3, 1, 0x13, 0, 0);
            }
        }
    }
    if (D_001DF4C0 == 10) {
        s32 all = 1;
        for (i = 0xB0; i < 0xBE; i++) {
            if (D_001426E0[i] == 0) all = 0;
        }
        if (all) D_001426E0[0xBF] = 1;
    }
}
/* localdecomp:end func_L03_003D0878 */

/* localdecomp:start func_L03_003D09C0 */
extern s32 func_L01_00447490(s32, s32, s32);
extern void func_L03_003D02A0(f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, u32);

void func_L03_003D09C0(s32 a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_L03_003D02A0(0.0f, a0, 31, 0.0f, 0, 7837, 1, 1, 1, 1, 0xC050C020);
    }
}
/* localdecomp:end func_L03_003D09C0 */
