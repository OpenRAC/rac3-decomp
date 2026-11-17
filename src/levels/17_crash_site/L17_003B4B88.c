#include "common.h"

/* localdecomp:start func_L17_003B4B88 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B4B88;
typedef struct { u8 p0[0x20]; s32 owner; u8 p24[8]; f32 amount; } H_3B4B88;
extern s32 D_001A71A0[];
extern void func_L01_00439880(u8 *, u16 *, s32 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_0038CAD0(void *);
extern H_3B4B88 *func_L01_00447490(u8 *, s32, s32);
extern void func_L01_00455E18(u8 *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2880(u8 *);

void func_L17_003B4B88(u8 *self) {
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
        func_L01_00439880(self, &a, &b);
        *(u16 *)(self + 0x7C) = a | 0x8000;
        if (*(f32 *)(d + 0x30) <= 0.0f) *(f32 *)(d + 0x30) = 30.0f;
        if (*(s16 *)(d + 0x34) <= 0) *(f32 *)(d + 0x30) = 30.0f;
        func_L01_004450F0(self, 1, -1);
    }
    dmg = 0.0f;
    if (func_0038CAD0(d + 0x158) == 0) return;
    h = func_L01_00447490(self, 0x10000, 0);
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
        *(s32 *)(d + 0x158) = (*(s32 *)(d + 0x150) * 5 + 2) / 6;
        if (q != 0) func_L01_00455E18(self, q, hp);
    }
    if (*(f32 *)(d + 0x30) <= 0.0f) {
        pv = &v;
        *pv = *(V4_3B4B88 *)(self + 0xE0);
        func_0038CF68(pv, pv, 0.040000003f);
        func_L01_00451FE0(self, *(u16 *)(self + 0x7C), pv, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                          3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L17_003B4B88 */
