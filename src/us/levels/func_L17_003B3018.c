#include "common.h"

/* NTSC-U counterpart of func_L17_003B4B88 (src/levels/17_crash_site/L17_003B4B88.c) */
/* localdecomp:start func_L17_003B3018 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B4B88;
typedef struct { u8 p0[0x20]; s32 owner; u8 p24[8]; f32 amount; } H_3B4B88;
extern s32 D_001A71A0[];
extern void func_L01_004367A0(u8 *, u16 *, s32 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_00388398(void *);
extern H_3B4B88 *func_L01_00444358(u8 *, s32, s32);
extern void func_L01_00452B20(u8 *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003BD360(u8 *);

void func_L17_003B3018(u8 *self) {
    u8 *d = *(u8 **)(self + 0x68);
    H_3B4B88 *h;
    f32 dmg;
    u8 *q;
    u8 *hp;
    V4_3B4B88 v;
    V4_3B4B88 *pv;

    if (self[0x20] == 0) {
        u16 a;
        s32 b;
        func_L01_004367A0(self, &a, &b);
        *(u16 *)(self + 0x7C) = a | 0x8000;
        if (*(f32 *)(d + 0x30) <= 0.0f) *(f32 *)(d + 0x30) = 30.0f;
        if (*(s16 *)(d + 0x34) <= 0) *(f32 *)(d + 0x30) = 30.0f;
        func_L01_00441FB8(self, 1, -1);
    }
    dmg = 0.0f;
    if (func_00388398(d + 0x158) == 0) return;
    h = func_L01_00444358(self, 0x10000, 0);
    if (h == 0) return;
    if (h->amount != dmg) {
        if (h->owner == D_001A71A0[0]) h->amount = h->amount * *(f32 *)(d + 0x154);
        dmg += h->amount;
    }
    self[0xA8] = 0xFF;
    if (0.0f < dmg) {
        *(f32 *)(d + 0x30) -= dmg;
        hp = d + 0x30;
        q = d + 0x130;
        *(s32 *)(d + 0x158) = *(s32 *)(d + 0x150);
        if (q != 0) func_L01_00452B20(self, q, hp);
    }
    if (*(f32 *)(d + 0x30) <= 0.0f) {
        pv = &v;
        *pv = *(V4_3B4B88 *)(self + 0xE0);
        func_00388830(pv, pv, 0.0333333351f);
        func_L01_0044ED60(self, *(u16 *)(self + 0x7C), pv, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                          3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003BD360(self);
    }
}
/* localdecomp:end func_L17_003B3018 */
