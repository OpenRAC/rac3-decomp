#include "common.h"

/* NTSC-U counterpart of func_L01_003F7CE0 (src/levels/shared/L01_003F79D8.c): 0.0004 -> 0.000277778; 0.04 -> 0.0333333; 0.015708 -> 0.01309; 0.00251327 -> 0.00174533 */
#include "vu0.h"
typedef struct {
    f32 x, y, z, w;
} V_003F6ED8;

/* localdecomp:start func_L01_003F5B38 */
extern s32 func_L01_004369B8_003F5B38(u8 *self, void *a, void *buf, s32 b);
extern void func_L01_004367E8(void *, s32, void *);
extern void func_003BFAF8(void *, void *, void *, s32);
extern void func_003886E8(V_003F6ED8 *, V_003F6ED8 *, f32);

void func_L01_003F5B38(u8 *m, s32 mode, s32 index, vu0_q *a, vu0_q *b, s32 byte, s32 half, f32 f) {
    u8 *d = *(u8 **)(m + 0x68);
    vu0_v4 tmp;
    f *= 0.000277777785f;
    *(s32 *)(m + 0x98) = 0;
    *(u16 *)(m + 0x34) |= 0x100;
    *(vu0_q *)d = *a;
    *(vu0_q *)(d + 0x10) = *b;
    *(f32 *)(d + 0x38) = 0.45f;
    *(f32 *)(d + 0x3C) = 0.0333333351f;
    *(f32 *)(d + 0x40) = 0.5f;
    *(f32 *)(d + 0x44) = 0.0130899707f;
    *(f32 *)(d + 0x48) = f;
    *(f32 *)(d + 0x4C) = 0.00174532935f;
    *(s16 *)(d + 0x34) = half;
    d[0x5E] = byte;
    d[0x5D] = mode;
    d[0x58] = 0;
    d[0x5C] = 0;
    *(s32 *)(d + 0x30) = 0;
    switch (mode) {
    case 2:
        *(s16 *)(d + 0x36) = index;
        *(u16 *)(m + 0x7C) = (1 << index) | 0x8000;
        d[0x58] = func_L01_004369B8_003F5B38(m, d + 0x20, *(void **)(d + 0x30), index);
        vec_sub_ab(d + 0x20, d + 0x20, m + 0x10);
        func_003BFAF8(m, d + 0x20, d + 0x20, 0);
        break;
    case 0:
    case 3:
        func_003886E8((V_003F6ED8 *)(d + 0x20), (V_003F6ED8 *)m, 0.0009765625f);
        *(f32 *)(d + 0x2C) = *(f32 *)(m + 0xC) * 0.0009765625f;
        vec_sub_ab(d + 0x20, d + 0x20, m + 0x10);
        func_003BFAF8(m, d + 0x20, d + 0x20, 0);
        break;
    case 1:
        *(s16 *)(d + 0x36) = index;
        *(u16 *)(m + 0x7C) = (1 << index) | 0x8000;
        func_L01_004367E8(m, index, &tmp);
        vec_sub_ab(d + 0x20, &tmp, m + 0x10);
        func_003BFAF8(m, d + 0x20, d + 0x20, 0);
        break;
    }
}
/* localdecomp:end func_L01_003F5B38 */
