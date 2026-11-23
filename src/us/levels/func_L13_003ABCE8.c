#include "common.h"

/* NTSC-U counterpart of func_L13_003ADAD0 (src/levels/shared/L13_003ADAD0.c): 60 Hz values (0.0027222223f against 0.00392f, 60 frames against 50) */
/* localdecomp:start func_L13_003ABCE8 */
typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_003ABCE8;

typedef struct A_003ADAD0 {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[0x1F];
    f32 f30;
    f32 f34;
    u8 pad38[4];
    f32 f3C;
    u8 pad40[8];
    u8 b48;
    u8 pad49;
    s16 h4A;
    u8 pad4C[0x2B];
    u8 b77;
    u8 pad78[0x38];
    f32 fB0;
} A_003ADAD0;

typedef struct B_003ADAD0 {
    u8 pad0[4];
    s16 h4;
    u8 pad6[2];
    u8 b8;
    u8 b9;
    u8 padA[4];
    u8 bE;
    u8 bF;
    f32 f10;
    u8 pad14[0x14];
    u8 b28;
    u8 pad29;
    u8 b2A;
} B_003ADAD0;

typedef struct C_003ADAD0 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[0x18];
    f32 f2C;
    f32 f30;
    f32 f34;
    u8 pad38[0xB4];
    s32 wEC;
} C_003ADAD0;


extern s32 D_L13_001DF140;
extern s32 D_L13_001D67C4;
extern s32 D_001D545C;
extern f32 D_L13_001DE680;
extern u8 D_L13_001DE684;
extern f32 D_L13_001DE6CC;
extern f32 D_L13_001DE6D0;
__asm__(".extern D_L13_001DE680, 4");
__asm__(".extern D_L13_001DE684, 1");
__asm__(".extern D_L13_001DE6CC, 4");
__asm__(".extern D_L13_001DE6D0, 4");
extern S_003ABCE8 *func_L01_00438468(s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_004A6DF8(u8 *, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(u8 *, u8 *);
extern void func_L13_003ABCB0(u8 *a, u8 *b);

s32 func_L13_003ABCE8(u8 *self) {
    u8 *s0;
    A_003ADAD0 *pa;
    B_003ADAD0 *pb;
    C_003ADAD0 *pc;
    u8 *p;
    S_003ABCE8 *t;
    s32 v;

    s0 = *(u8 **)(self + 0x68);
    if (D_L13_001DF140 == 0) {
        D_L13_001D67C4 = 0;
    }
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    pa = (A_003ADAD0 *)(s0 + 0x70);
    pa->f30 = 1.5f;
    pa->b48 = 0xFF;
    pa->b10 = 0x22;
    pa->b77 = 1;
    pa->f34 = 0.5f;
    pa->f3C = 0.15f;
    pa->fB0 = 1.0f;
    s0[0xB9] = 1;
    if (D_001D545C != 0xD) {
        *(f32 *)(s0 + 0xB0) = *(f32 *)(self + 0x18) - 32.0f;
    }
    if (D_001D545C == 0xC) {
        pa->h4A = 0x280B;
    }
    pb = (B_003ADAD0 *)(s0 + 0x30);
    pb->b28 = 0x14;
    pb->b2A = 0xE;
    pb->f10 = 1.5f;
    pb->bE = 1;
    pb->bF = 0;
    pb->b8 = 1;
    pb->b9 = 1;
    if (pb->h4 == 0) {
        pb->h4 = (s16)D_L13_001DE680;
        *(f32 *)(s0 + 0x30) = (f32)*(s16 *)(s0 + 0x34);
    }
    p = s0 + 0x44;
    for (v = 0; v < 2; v++) {
        if (p[v] == 0) {
            p[v] = D_L13_001DE684;
        }
    }
    pc = (C_003ADAD0 *)(s0 + 0x150);
    pc->f0 = 1.5f;
    pc->f4 = 0.5f;
    pc->wEC = 0;
    pc->f8 = 0.5f;
    pc->fC = 0.5f;
    pc->f10 = 1.5707964f;
    pc->f2C = 0.0027222223f;
    pc->f34 = D_L13_001DE6CC;
    pc->f30 = D_L13_001DE6D0 * 0.017453292f;
    if (s0[0x3AC] != 0) {
        *(u16 *)(self + 0x34) = *(u16 *)(self + 0x34) | 0x8000;
    }
    s0[0x5E] = 0;
    s0[0x5F] = 0;
    if (*(s32 *)(s0 + 0x260) > 0) {
        t = func_L01_00438468(0x19E1, 0x6C);
        *(s32 *)(s0 + 0x260) = -1;
        if (self[0x43] != 0) {
            func_003BE4F0(self, 0, 0, 0);
        }
        s0[0x26E] = 0x24;
        s0[0x26F] = 4;
        t->f0(self);
        return 0;
    }
    if (*(s32 *)(s0 + 0x3D4) != 0) {
        func_L01_00441FB8(self, 0x25, 0x25);
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004A6DF8(self, 1);
    } else {
        func_L13_003ABCB0(self, s0);
        if (*(s32 *)(s0 + 0x3C0) != 0) {
            func_L01_00441FB8(self, 0x23, 3);
            if (self[0x43] != 0xB) {
                func_003BE4F0(self, 0xB, 0, 0x3C);
            }
        }
    }
    if (self[0x95] == 0) {
        p = func_003BCFB0(0x1C8E, 0x80);
        *(u8 **)(s0 + 0x3E0) = p;
        if (p != 0) {
            func_L01_00452E70(p, self);
            *(f32 *)(*(u8 **)(s0 + 0x3E0) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(s0 + 0x3E0) + 0x24) + 0x24) * 1.25f;
        }
    }
    *(s32 *)(s0 + 0x3E8) = 0;
    return 1;
}
/* localdecomp:end func_L13_003ABCE8 */
