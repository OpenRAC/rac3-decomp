#include "common.h"

/* NTSC-U counterpart of func_L14_00361598 (src/levels/14_koros/L14_00361598.c) */
#include "vu0.h"

/* localdecomp:start func_L14_003604B8 */
__asm__(".extern D_L14_001DF71C_003604B8, 16");
extern u8 *D_L14_001DF71C_003604B8;
extern char D_001A4C60[];
extern s32 func_L01_00453210(void *, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003C26C8(void *);
extern s32 func_003883C8(void *);
void func_L14_003604B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *o;
    f32 t;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L01_00453210(D_001A4C60, *(s32 *)s) != 0) {
            a0[0x20] = 2;
            *(s16 *)(s + 0x12) = *(s16 *)(s + 0x10);
            *(f32 *)(s + 0x14) = *(f32 *)(a0 + 0xF0);
            *(f32 *)(s + 0x18) = *(f32 *)(a0 + 0xF4);
            *(f32 *)(s + 0x1C) = *(f32 *)(a0 + 0xF8);
        }
        break;
    case 2:
        o = D_L14_001DF71C_003604B8 + (*(s32 *)(s + 0x20) << 8);
        t = 1.0f - (f32)*(s16 *)(s + 0x12) / (f32)*(s16 *)(s + 0x10);
        if (*(f32 *)(s + 4) != 0.0f) {
            *(f32 *)(o + 0xF0) = *(f32 *)(s + 0x14) + func_003BE6A8(0.0f, *(f32 *)(s + 4) * 0.017453292f, t);
        }
        if (*(f32 *)(s + 8) != 0.0f) {
            *(f32 *)(o + 0xF4) = *(f32 *)(s + 0x18) + func_003BE6A8(0.0f, *(f32 *)(s + 8) * 0.017453292f, t);
        }
        if (*(f32 *)(s + 0xC) != 0.0f) {
            *(f32 *)(o + 0xF8) = *(f32 *)(s + 0x1C) + func_003BE6A8(0.0f, *(f32 *)(s + 0xC) * 0.017453292f, t);
        }
        func_003C26C8(o);
        if (func_003883C8(s + 0x12) != 0) {
            a0[0x20] = 3;
        }
        break;
    case 3:
        break;
    }
}
/* localdecomp:end func_L14_003604B8 */
