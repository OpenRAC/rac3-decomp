#include "common.h"

/* NTSC-U counterpart of func_L24_003B64C8 (src/levels/24_insomniac_museum/L24_003B6050.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L24_003B48D0();

/* localdecomp:start func_L24_003B48D0 */
typedef int vu0_q_003B64C8 __attribute__((mode(TI)));

__asm__(".extern D_L24_001DE840, 4");
extern f32 D_L24_001DE840;
extern s32 D_L24_001DD5C4_003B48D0;
extern f32 D_L24_001DD5C0_003B48D0;
extern f32 D_L24_001DD5BC;

typedef struct {
    u8 pad0[0x10];
    vu0_q_003B64C8 x10;
    u8 pad20[0x4];
    u8 *x24;
    u8 pad28[0x4];
    f32 x2C;
    u8 pad30[0x4];
    u16 x34;
    u8 pad36[0x62];
    s32 x98;
} M_003B64C8;

typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    u8 pad36[0x3];
    u8 x39;
    u8 pad3A[0x6];
    f32 x40;
    u8 pad44[0x14];
    u8 x58;
    u8 pad59;
    u8 x5A;
    u8 pad5B[0x15];
    f32 x70;
    f32 x74;
    f32 x78;
    f32 x7C;
    f32 x80;
    u8 pad84[0x18];
    f32 x9C;
    f32 xA0;
    u8 padA4[0x8DC - 0xA4];
    M_003B64C8 *x8DC;
    u8 pad8E0[0x4];
    f32 x8E4;
    f32 x8E8;
    u8 pad8EC[0x4];
    s32 x8F0;
    s32 x8F4;
    u8 pad8F8[0x14];
    s32 x90C;
    u8 pad910[0x20];
    f32 x930;
    u8 pad934[0xC];
    vu0_q_003B64C8 x940;
} S_003B64C8;

extern M_003B64C8 *func_003BCFB0(s32, s32);
extern void func_L01_00452E70(void *, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);

s32 func_L24_003B48D0(u8 *arg) {
    M_003B64C8 *a0 = (M_003B64C8 *)arg;
    S_003B64C8 *p = *(S_003B64C8 **)(arg + 0x68);
    M_003B64C8 *e;
    p->x70 = 0.5f;
    p->x74 = 0.1f;
    p->x78 = 0.5f;
    p->x7C = 1.0f;
    p->x80 = 0.785398185f;
    p->xA0 = 0.34906584f;
    p->x9C = 0.0027222223579883575f;
    if (p->x34 == 0) {
        p->x34 = 100;
        p->x30 = 100.0f;
    }
    p->x39 = 1;
    p->x40 = 2.0f;
    p->x58 = 0x14;
    p->x5A = 0xE;
    func_L01_00452E70(p->x8DC = func_003BCFB0(0x1B5C, 0x80), a0);
    a0->x2C = *(f32 *)(a0->x24 + 0x24) * D_L24_001DE840;
    p->x8F0 = 0x4096006B;
    p->x8F4 = 0x450030;
    p->x8E4 = 2.0f;
    p->x8E8 = 2.0f;
    e = p->x8DC;
    e->x2C = *(f32 *)(e->x24 + 0x24) * 0.300000012f * D_L24_001DE840;
    a0->x34 &= 0xFFBE;
    a0->x34 |= *(u16 *)(a0->x24 + 0x44) & 0x1000;
    a0->x98 = *(s32 *)(a0->x24 + 0x10);
    p->x8DC->x34 &= 0xFFBE;
    p->x8DC->x34 |= *(u16 *)(p->x8DC->x24 + 0x44) & 0x1000;
    p->x8DC->x98 = *(s32 *)(p->x8DC->x24 + 0x10);
    p->x90C = D_L24_001DD5C4_003B48D0;
    p->x930 = D_L24_001DD5C0_003B48D0;
    func_L01_00458A70(a0, D_L24_001DD5BC, D_L24_001DD5BC, 0.41887906f, 0.41887906f);
    p->x940 = a0->x10;
    func_L01_00441FB8(a0, 1, -1);
    return 0;
}
/* localdecomp:end func_L24_003B48D0 */
