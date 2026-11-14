#include "common.h"

/* NTSC-U counterpart of func_L07_00330748 (src/levels/07_annihilation_nation/L07_0032F598.c) */
/* localdecomp:start func_L07_00330018 */
extern u8 D_001A4BE0[];
extern s32 D_00142668[];
extern void func_L07_00331150(void *);
extern u8 func_L07_00333180(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_00330018(u8 *a0, s32 a1) {
    u8 *d;
    u8 *p;

    d = *(u8 **)(a0 + 0x68);
    d[0x9F] = 0;
    d[0x9E] = a1;
    func_L07_00331150(a0);
    d[0xA8] = 4;
    d[0xAA] = func_L07_00333180(d[0x9E], d[0x9F]);
    p = D_001A4BE0;
    *(s32 *)(p + 0x2850) = D_00142668[0];
    d[0xDE] = p[0x2850];
    d[0xDF] = p[0x2850];
    *(s32 *)(d + 0xC0) = 0;
    *(s32 *)(d + 0xC4) = 0;
    *(s32 *)(d + 0xC8) = 0;
    *(s32 *)(d + 0xCC) = 0;
    *(s16 *)(d + 0xD4) = 0;
    *(s16 *)(d + 0xD2) = 0;
    *(s16 *)(d + 0xD0) = 0;
    *(s16 *)(d + 0xD6) = 0;
    *(s16 *)(d + 0xD8) = func_0037E1D8(0x4B0) + 0x960;
    if (*(s32 *)(d + 0xE0) & 1) {
        *(s32 *)(d + 0xE0) = 3;
    } else {
        *(s32 *)(d + 0xE0) = 0;
    }
    func_L01_00452F40(a0, 0);
    func_L01_00441FB8(a0, 2, -1);
}
/* localdecomp:end func_L07_00330018 */
