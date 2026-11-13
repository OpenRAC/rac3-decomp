#include "common.h"

/* NTSC-U counterpart of func_L28_0039B910 (src/levels/28_aquatos_sewers/L28_0039B910.c) */
/* localdecomp:start func_L28_00399D10 */
extern u8 D_001426E0[];
extern s16 D_001A4DC0[];
extern s32 D_L28_001DE840_00399D10;
extern s32 D_001A82AC[];
extern s32 D_001D545C_00399D10;
__asm__(".extern D_001D545C_00399D10, 16");
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00417F60(s32, s32);
void func_L28_00399D10(u8 *a0) {
    u8 *q = D_001426E0;
    f32 v[4];
    f32 w[4];
    s32 m, t;
    if (q[0x73] == 0) {
        if (a0[0x20] == 0) {
            a0[0x30] = 0xFF;
            v[0] = 474.54998779f;
            v[1] = 445.32998657f;
            v[2] = 972.21997070f;
            w[2] = -3.11999988f;
            func_L01_004F12C0(v, w, 0, 1);
            q[0x73] = 1;
            D_001A4DC0[0] = 240;
            func_L01_00441FB8(a0, 1, -1);
        }
    }
    if (a0[0x20] == 1) {
        if (D_L28_001DE840_00399D10 > 18000) {
            t = D_001A82AC[0];
            m = 1 << D_001D545C_00399D10;
            if ((t & m) == 0) {
                func_L01_00417F60(0xC9E, 0x61);
            }
        }
    }
}
/* localdecomp:end func_L28_00399D10 */
