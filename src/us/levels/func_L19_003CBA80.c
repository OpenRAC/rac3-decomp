#include "common.h"

/* NTSC-U counterpart of func_L19_003CDB98 (src/levels/19_thran_asteroid_belt/L19_003CDB98.c): 0.04 -> 0.0333333 */
/* localdecomp:start func_L19_003CBA80 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3CDB98;
typedef int u128_t_3CDB98 __attribute__((mode(TI)));
extern void func_L01_004367A0(u8 *, u16 *, s32 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L01_0044FC98(u8 *, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(u8 *);
extern void func_003BD360(u8 *);

void func_L19_003CBA80(u8 *self) {
    u8 *d = *(u8 **)(self + 0x68);
    u8 *n;
    V4_3CDB98 v;
    V4_3CDB98 *pv;

    if (self[0x20] == 0) {
        u16 a;
        s32 b;
        func_L01_004367A0(self, &a, &b);
        *(u16 *)(self + 0x7C) = a;
        if (*(f32 *)(d + 0x30) <= 0.0f) *(f32 *)(d + 0x30) = 30.0f;
        if (*(s16 *)(d + 0x34) <= 0) *(f32 *)(d + 0x30) = 30.0f;
        func_L01_00441FB8(self, 1, -1);
    }
    if (func_L01_0044FC98(self, 0, 0, 0) != 0) {
        *(u16 *)(d + 0x36) = *(u16 *)(d + 0x150);
    }
    if (*(f32 *)(d + 0x30) <= 0.0f) {
        pv = &v;
        *pv = *(V4_3CDB98 *)(self + 0xE0);
        func_00388830(pv, pv, 0.0333333351f);
        func_L01_0044ED60(self, *(u16 *)(self + 0x7C), pv, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                          3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        n = func_003BCFB0(0x1DF4, 0x80);
        *(u128_t_3CDB98 *)(n + 0x10) = *(u128_t_3CDB98 *)(self + 0x10);
        *(u128_t_3CDB98 *)(n + 0xF0) = *(u128_t_3CDB98 *)(self + 0xF0);
        *(u128_t_3CDB98 *)(n + 0xC0) = *(u128_t_3CDB98 *)(self + 0xC0);
        *(u128_t_3CDB98 *)(n + 0xD0) = *(u128_t_3CDB98 *)(self + 0xD0);
        *(u128_t_3CDB98 *)(n + 0xE0) = *(u128_t_3CDB98 *)(self + 0xE0);
        n[0x30] = self[0x30];
        *(u16 *)(n + 0x32) = *(u16 *)(self + 0x32);
        *(u16 *)(n + 0x34) &= 0xFFFE;
        n[0x31] = 1;
        *(s32 *)(n + 0x98) = *(s32 *)(*(u8 **)(n + 0x24) + 0x10);
        func_003C26C8(n);
        func_003BD360(self);
    }
}
/* localdecomp:end func_L19_003CBA80 */
