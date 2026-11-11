/* Historical draft; resolved as plain C in src/levels/04_marcadia/L04_00366800.c. */
#include "common.h"

/* localdecomp:start func_L04_00366AC8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_366AC8;
typedef int u128_t_366AC8 __attribute__((mode(TI)));

extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFE80;
__asm__(".extern D_L04_001DFE80, 16");
extern u8 D_001BBC40[];
extern s32 D_001DFDD8_sda;
__asm__(".extern D_001DFDD8_sda, 4");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_001DD7F4_sda;
__asm__(".extern D_001DD7F4_sda, 4");

extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044F450(void *, void *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00366E48(void *, void *, void *, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L04_00366AC8(u8 *a0, u8 *a1) {
    u16 *p;
    u8 *e;
    V4_366AC8 t;
    u128_t_366AC8 v;
    u8 *q;
    u8 *pos;
    s32 f;

    a0[0x30] = 0x20;
    *(u16 *)(a0 + 0x32) = 0x20;
    *(V4_366AC8 *)(a1 + 0x2C0) = *(V4_366AC8 *)(a0 + 0x10);
    p = D_L04_0021C9A0[*(s32 *)(a1 + 0x120)];

    for (;;) {
        f = *(s32 *)(a1 + 0x120);
        if ((u8)f == 0xFF) break;
        if (D_001DFDD8_sda < f) break;
        if (p == 0) break;
        if ((s16)p[-1] < 0 && p != D_L04_0021C9A0[f]) break;
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        *(u16 *)(e + 0x34) |= 0x41;
        if (*(s16 *)(e + 0xAA) == 0x1860) {
            *(u8 **)(a1 + 0x12C) = e;
            *(u8 **)(e + 0xB8) = a0;
            func_003C2F58(a0, 0, &t);
            *(V4_366AC8 *)(e + 0x10) = t;
        } else if (*(s16 *)(e + 0xAA) == 0x11C1) {
            *(u8 **)(e + 0xB8) = a0;
            func_003C2F58(a0, 1, &t);
            *(V4_366AC8 *)(e + 0x10) = t;
        }
        p++;
    }

    pos = a0 + 0xF0;
    func_L01_0044ED88(a0, a1 + 0x180, 4, *(s32 *)(a1 + 0x120), -1, -1, 7, 0);

    *(f32 *)(a1 + 0x30) = 0.2f;
    *(f32 *)(a1 + 0x3C) = 0.1f;
    *(f32 *)(a1 + 0x40) = 0.61086524f;
    *(f32 *)(a1 + 0x60) = 0.08726646f;
    *(f32 *)(a1 + 0x64) = 0.75f;
    *(f32 *)(a1 + 0x34) = 0.1f;
    *(f32 *)(a1 + 0x38) = 0.1f;
    *(s32 *)(a1 + 0x68) |= 4;
    *(s32 *)(a1 + 0x5C) = 0;
    *(u16 *)(a0 + 0x34) |= 0x100;
    func_L01_0045BD78(a0, 0.0032000002f, 0.020000001f * D_001DD7F4_sda, 0.0018849557f, 0.041887905f);
    *(s32 *)(a1 + 0x300) = 0;
    *(V4_366AC8 *)(a1 + 0x2E0) = *(V4_366AC8 *)(a0 + 0x10);
    *(V4_366AC8 *)(a1 + 0x2F0) = *(V4_366AC8 *)(a0 + 0xF0);
    func_L01_00366E48(a0, a1 + 0x134, a1 + 0x138, a1 + 0x140, 0);
    *(s32 *)(a1 + 0x130) = 0x5A;
    if (a0[0xB0] != 0xFF) {
        if ((D_001BBC40[a0[0xB0] + (D_001D545C_sda << 4)] & 0x80) != 0) {
            q = D_L04_001DFE80 + (*(s32 *)(a1 + 0x13C) << 7);
            v = *(u128_t_366AC8 *)(q + 0x30);
            *(u128_t_366AC8 *)(a0 + 0x10) = v;
            *(u128_t_366AC8 *)(a1 + 0x2C0) = v;
            *(V4_366AC8 *)(a0 + 0xF0) = *(V4_366AC8 *)(q + 0x70);
            func_0038D308(a0 + 0xC0, pos);
            func_L01_0044F450(a0, a1 + 0x180);
            *(V4_366AC8 *)(a1 + 0x2E0) = *(V4_366AC8 *)(a0 + 0x10);
            *(s32 *)(a1 + 0x300) = 1;
            *(V4_366AC8 *)(a1 + 0x2F0) = *(V4_366AC8 *)(a0 + 0xF0);
        }
    }
    func_L01_004450F0(a0, 1, -1);
    func_003C3A10(a0, 0, 0, 0);
}
/* localdecomp:end func_L04_00366AC8 */
