#include "common.h"

/* NTSC-U counterpart of func_L24_00359E30 (src/levels/24_insomniac_museum/L24_00359248.c) */
#include "vu0.h"
extern void func_L24_00359A28(void *);

/* localdecomp:start func_L24_00358D68 */
typedef int u128_00359E30 __attribute__((mode(TI)));
__asm__(".extern D_L24_001DD670, 4");
__asm__(".extern D_L24_001DD674, 4");
extern f32 D_L24_001DD670;
extern f32 D_L24_001DD674;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    s16 x36;
    u8 pad38[0x1];
    u8 x39;
    u8 pad3A[0x6];
    f32 x40;
    u8 x44;
    u8 pad45[0x13];
    u8 x58;
    u8 pad59[0x1];
    u8 x5A;
    u8 pad5B[0x25];
    u8 x80;
    u8 pad81[0x5];
    u8 x86;
    u8 pad87[0x5];
    f32 x8C;
    f32 x90;
    f32 x94;
    f32 x98;
    f32 x9C;
    f32 xA0;
    f32 xA4;
    u8 padA8[0x4];
    f32 xAC;
    u8 padB0[0x8];
    u8 xB8;
    u8 padB9[0x29];
    u8 xE2;
    u8 xE3;
    u8 padE4[0x3];
    u8 xE7;
    u8 padE8[0x2];
    u8 xEA;
    u8 padEB[0x2D];
    f32 x118;
    u8 pad11C[0x34];
    u128_00359E30 x150;
    u8 pad160[0x34];
    s16 x194;
    u8 pad196[0x2];
    u8 x198;
    u8 pad199[0xF];
    f32 x1A8;
    u8 pad1AC[0x10];
    s32 x1BC;
    u8 pad1C0[0x1C];
    f32 x1DC;
    u8 pad1E0[0x10];
    f32 x1F0;
    f32 x1F4;
    f32 x1F8;
    f32 x1FC;
    f32 x200;
    f32 x204;
    u8 pad208[0xC];
    f32 x214;
} S_00359E30;
extern void func_L24_00359A28(void *);
extern void func_L24_00359228(u8 *);

void func_L24_00358D68(void *arg) {
    u8 *a0 = arg;
    S_00359E30 *p = *(S_00359E30 **)(a0 + 0x68);
    f32 f6;
    p->xB8 = 4;
    p->x86 = 7;
    p->x80 = 0xE;
    p->xE3 = 0xF;
    p->xE2 = 8;
    p->xA0 = 0.5f;
    p->xA4 = 0.5f;
    p->xAC = 0.15f;
    p->xE7 = 1;
    p->x8C = 0.25f;
    p->x90 = 0.016666668f;
    p->x94 = 0.0069444445f;
    p->x98 = 0.009722223f;
    p->x9C = 0.00055555557f;
    p->xEA = 3;
    p->x118 = 0.25f;
    p->x58 = 0x14;
    p->x5A = 0xE;
    if (p->x34 == 0) {
        p->x34 = 1;
        p->x30 = 1.1f;
    }
    p->x39 = 1;
    p->x44 = 1;
    f6 = p->x1A8;
    p->x40 = 0.5f;
    p->x36 = 0x19;
    p->x1DC = 0.0027222224f;
    p->x1F0 = D_L24_001DD670;
    p->x1F4 = D_L24_001DD674;
    p->x1FC = -(f6 + 0.15f);
    p->x204 = 0.2f;
    p->x200 = 0.2f;
    p->x214 = 0.00100000005f;
    p->x1F8 = f6;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.75f;
    p->x150 = *(u128_00359E30 *)(a0 + 0x10);
    p->x198 = 1;
    p->x1BC = 0;
    p->x194 = 0;
    func_L24_00359A28(a0);
    func_L24_00359228(a0);
}
/* localdecomp:end func_L24_00358D68 */
