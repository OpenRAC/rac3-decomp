/* NTSC-U draft (Claude wave K): C of func_L13_003ABCE8, the NTSC-U twin of func_L13_003ADAD0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 85 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003ABCE8", whose code is not the PAL one).
 * Worker's note: Unchanged (85 diff with @ps2as, 150 of 203 equal; K/near/func_L13_003ABCE8.opus.c = the medium draft). Re-diffed: the store group after the prologue differs in WHICH registers carry the constants and the sub-struct pointer: retail A = s0 + 0x70 in a1 (addiu ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L13_003ADAD0 (src/levels/shared/L13_003ABD48.c) */
/* localdecomp:start func_L13_003ABCE8 */
typedef struct A_003ABCE8 {
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
} A_003ABCE8;

typedef struct B_003ABCE8 {
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
} B_003ABCE8;

typedef struct C_003ABCE8 {
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
} C_003ABCE8;

typedef struct S_003ABCE8 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0xE];
    u8 b44[2];
    u8 pad46[0x18];
    u8 b5E;
    u8 b5F;
    u8 pad60[0x10];
    A_003ABCE8 a;
    u8 padXX[1];
} S_003ABCE8;

extern s32 D_L13_001DF140;
extern s32 D_L13_001D67C4;
extern s32 D_001D545C;
extern f32 D_001DE680_sda;
extern u8 D_001DE684_sda;
extern f32 D_001DE6CC_sda;
extern f32 D_001DE6D0_sda;
__asm__(".extern D_L13_001DF140, 16");
__asm__(".extern D_L13_001D67C4, 16");
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_001DE680_sda, 4");
__asm__(".extern D_001DE684_sda, 4");
__asm__(".extern D_001DE6CC_sda, 4");
__asm__(".extern D_001DE6D0_sda, 4");
extern void (**func_L01_00438468(s32, s32))(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_004A6DF8(u8 *, s32);
extern void func_L13_003ABCB0(u8 *, u8 *);
extern void *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, u8 *);

s32 func_L13_003ABCE8(u8 *self) {
    u8 *s0;
    A_003ABCE8 *pa;
    B_003ABCE8 *pb;
    C_003ABCE8 *pc;
    u8 *p;
    void (**t)(u8 *);
    s32 v;

    if (D_L13_001DF140 == 0) {
        D_L13_001D67C4 = 0;
    }
    s0 = *(u8 **)(self + 0x68);
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    pa = (A_003ABCE8 *)(s0 + 0x70);
    pa->b48 = 0xFF;
    pa->b10 = 0x22;
    pa->b77 = 1;
    pa->f34 = 0.5f;
    pa->f3C = 0.15f;
    pa->fB0 = 1.0f;
    pa->f30 = 1.5f;
    s0[0xB9] = 1;
    if (D_001D545C != 0xD) {
        *(f32 *)(s0 + 0xB0) = *(f32 *)(self + 0x18) - 32.0f;
    }
    if (D_001D545C == 0xC) {
        pa->h4A = 0x280B;
    }
    pb = (B_003ABCE8 *)(s0 + 0x30);
    pb->b28 = 0x14;
    pb->b2A = 0xE;
    pb->f10 = 1.5f;
    pb->b9 = 1;
    pb->bE = 1;
    pb->bF = 0;
    pb->b8 = 1;
    if (pb->h4 == 0) {
        pb->h4 = (s16)D_001DE680_sda;
        *(f32 *)(s0 + 0x30) = (f32)*(s16 *)(s0 + 0x34);
    }
    pc = (C_003ABCE8 *)(s0 + 0x150);
    for (p = s0 + 0x44; p < s0 + 0x46; p++) {
        if (*p == 0) {
            *p = D_001DE684_sda;
        }
    }
    pc->f0 = 1.5f;
    pc->f30 = D_001DE6D0_sda * 0.017453292f;
    pc->fC = 0.5f;
    pc->f10 = 1.5707964f;
    pc->f2C = 0.00272222236f;
    pc->f34 = D_001DE6CC_sda;
    pc->f4 = 0.5f;
    pc->wEC = 0;
    pc->f8 = 0.5f;
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
        (*t)(self);
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
