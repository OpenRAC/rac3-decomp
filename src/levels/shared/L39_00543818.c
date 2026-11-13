#include "common.h"

/* localdecomp:start func_L39_00543818 */
#include "vu0.h"
extern s32 D_L39_002412DC;
extern s32 D_L39_00243F20[2];
extern void func_L01_0043A430(u8 *, s32, u8 *);
extern void func_0038D278(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L39_00543818(u8 *a0) {
    u8 *s;
    s32 i;
    s32 m;

    s = *(u8 **)(a0 + 0x68);
    qzero(s + 0x290);
    qzero(s + 0x2A0);
    qzero(s + 0x2B0);
    qzero(s + 0x3F0);
    m = D_L39_002412DC;
    *(s32 *)(s + 0x350) = 0;
    *(s32 *)(s + 0x354) = 0;
    if (m == 0x12) {
        *(s16 *)(s + 0x34) = 0x190;
        *(f32 *)(s + 0x30) = 400.0f;
    } else if (m == 0x14) {
        *(s16 *)(s + 0x34) = 0x190;
        *(f32 *)(s + 0x30) = 400.0f;
    } else if (m == 0x1A) {
        *(s16 *)(s + 0x34) = 0x12C;
        *(f32 *)(s + 0x30) = 300.0f;
    } else if (m == 0x1D) {
        *(s16 *)(s + 0x34) = 0x64;
        *(f32 *)(s + 0x30) = 100.0f;
    } else {
        *(s16 *)(s + 0x34) = 0x96;
        *(f32 *)(s + 0x30) = 150.0f;
    }
    s[0x3E] = 3;
    s[0x58] = 0x1E;
    s[0x5A] = 0x20;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.8f;
    *(f32 *)(s + 0x368) = *(f32 *)(a0 + 0x18);
    qzero(s + 0x2C0);
    *(f32 *)(s + 0x390) = 0.05235988f;
    *(s32 *)(s + 0x3AC) = -1;
    *(s32 *)(s + 0x3D4) = 8;
    *(s32 *)(s + 0x3D8) = 0x15;
    *(s32 *)(s + 0x3DC) = 5;
    *(s32 *)(s + 0x3E0) = 0x32;
    *(s32 *)(s + 0x388) = 0;
    *(s32 *)(s + 0x38C) = 0;
    *(s32 *)(s + 0x394) = 0;
    *(s32 *)(s + 0x39C) = 0;
    *(s32 *)(s + 0x398) = 0;
    *(s32 *)(s + 0x3A0) = 0;
    *(s32 *)(s + 0x360) = 0;
    *(s32 *)(s + 0x364) = 0;
    *(s32 *)(s + 0x3A4) = 0;
    *(s32 *)(s + 0x3A8) = 0;
    s[0x380] = 0;
    s[0x381] = 0;
    *(s32 *)(s + 0x3B8) = 0;
    *(s16 *)(s + 0x37E) = 0;
    *(s32 *)(s + 0x374) = 0;
    *(s32 *)(s + 0x378) = 0;
    *(s16 *)(s + 0x37C) = 0;
    *(s32 *)(s + 0x3E4) = 0;
    *(s32 *)(s + 0x3E8) = 0;
    for (i = 0; i < 2; i++) {
        u8 *e = s + i * 0x40;
        if (e[0x91] == 0) {
            func_L01_0043A430(a0, i + 4, s + 0x90 + i * 0x40);
        }
        if (e[0x111] == 0) {
            func_L01_0043A430(a0, i + 2, s + 0x110 + i * 0x40);
        }
        if (e[0x191] == 0) {
            func_L01_0043A430(a0, i + 9, s + 0x190 + i * 0x40);
        }
    }
    func_0038D278(s + 0x2D0);
    *(vu0_q *)(s + 0x3C0) = *(vu0_q *)D_L39_00243F20;
    *(s32 *)(s + 0x3BC) = 1;
    func_L01_004450F0(a0, 0, 2);
    *(vu0_q *)(s + 0x420) = *(vu0_q *)(a0 + 0x10);
    *(vu0_q *)(s + 0x2D0) = *(vu0_q *)(a0 + 0xC0);
    *(vu0_q *)(s + 0x2E0) = *(vu0_q *)(a0 + 0xD0);
    *(vu0_q *)(s + 0x2F0) = *(vu0_q *)(a0 + 0xE0);
}
/* localdecomp:end func_L39_00543818 */

INCLUDE_ASM("asm/levels", func_L39_00543AA8);
