/* functional: medium. 169 instructions differ (scheduling and register use); same calls and arguments as retail, including stack arguments. */
#include "vu0.h"
extern s32 D_L01_001DEFA0[];
extern f32 D_L01_001DEF90_003CCC20;
extern f32 D_L01_001DEF94_003CCC20;
extern f32 D_L01_001DEF98_003CCC20;
extern f32 D_L01_001DEF9C_003CCC20;
__asm__(".extern D_L01_001DEF90_003CCC20, 4");
__asm__(".extern D_L01_001DEF94_003CCC20, 4");
__asm__(".extern D_L01_001DEF98_003CCC20, 4");
__asm__(".extern D_L01_001DEF9C_003CCC20, 4");
extern f32 D_L01_001DEFC0[];
extern f32 D_L01_001DEFE0[];
extern s32 D_L01_001DF000[];
extern u8 D_L01_001D66B0[];
extern void func_003C5180(void *, void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L01_0046B458(void *, s32, s32, s32, f32, f32, f32, s32, void *, s32);
extern void func_L01_00470C78(void *, s32, s32, s32, f32, f32, s32, void *, s32, s32, s32, s32);

u8 *func_L01_003CCC20(s32 w20, u8 *pos, u8 *dir, s32 w24, f32 val) {
    vu0_v4 axis, nd, rnd;
    u8 *n, *st;
    s32 i;
    func_003C5180(pos, &axis, 1);
    n = func_003C24B0(0x1B33, 0x80);
    if (n == 0) return n;
    st = *(u8 **)(n + 0x68);
    *(s32 *)(st + 0x10) = 0x43;
    n[0x30] = 0xFF;
    *(s16 *)(n + 0x32) = 0xFF;
    n[0x20] = 0;
    *(vu0_q *)(n + 0x10) = *(vu0_q *)pos;
    *(f32 *)(st + 0x1C) = val;
    *(s32 *)(st + 0x18) = 0;
    *(s32 *)(st + 0x14) = 0;
    *(vu0_q *)st = *(vu0_q *)dir;
    func_0038CF68(&nd, dir, 1.0f);
    *(vu0_q *)(n + 0xC0) = *(vu0_q *)&nd;
    func_0038CE90(n + 0xD0, n + 0xC0, &axis);
    func_0038CF68(n + 0xD0, n + 0xD0, 1.0f);
    func_0038CE90(n + 0xE0, n + 0xD0, n + 0xC0);
    *(f32 *)(n + 0xCC) = 0.0f;
    *(f32 *)(n + 0xEC) = 0.0f;
    *(f32 *)(n + 0xDC) = 0.0f;
    *(s32 *)(st + 0x24) = w24;
    *(s32 *)(st + 0x20) = w20;
    for (i = 9; i >= 0; i--) {
        s32 r;
        func_00382580(&rnd, 0.10000000894069672f, 0.20000001788139343f);
        r = func_00382498(10, 0x19);
        func_L01_00474078(pos, &rnd, (r * 5 + 2) / 6, D_L01_001DEF90_003CCC20, D_L01_001DEF94_003CCC20,
                          D_L01_001DEF98_003CCC20, D_L01_001DEF9C_003CCC20, D_L01_001DEFA0[0],
                          D_L01_001DEFA0[1], 0, 0);
    }
    for (i = 0; i < 4; i++) {
        func_L01_0046B458(pos, 0xC, D_L01_001DEFA0[i], 2, D_L01_001DEFC0[i], D_L01_001DEFE0[i], 0.0f, 1,
                          D_L01_001D66B0, 1);
    }
    for (i = 4; i < 7; i++) {
        func_L01_00470C78(pos, 0x11, D_L01_001DEFA0[i], 2, D_L01_001DEFC0[i], D_L01_001DEFE0[i], 2,
                          D_L01_001D66B0, 0, D_L01_001DF000[i - 4], 6, 1);
    }
    return n;
}
