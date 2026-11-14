#include "common.h"

/* NTSC-U counterpart of func_L04_00356318 (src/levels/04_marcadia/L04_00356318.c): 0.02 -> 0.0166667; 0.01 -> 0.00833333 */
#include "vu0.h"

/* localdecomp:start func_L04_00355400 */
typedef int u128_t_356318 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;

extern u8 *D_L04_001E9618[];
extern u8 D_L04_001D66B0_00355400[8];
__asm__(".extern D_L04_001D66B0_00355400, 16");
__asm__(".extern D_L04_001DD350, 4");
__asm__(".extern D_L04_001DD354, 4");
__asm__(".extern D_L04_001DD358, 4");
extern f32 D_L04_001DD350;
extern f32 D_L04_001DD354;
extern f32 D_L04_001DD358;
extern s32 func_L01_00448E90(void *);
extern f32 func_0037E2A8(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern void func_L01_004EA040(void);
extern f32 func_00388800(void *, void *);
extern void func_003BD360(void *);
extern void func_00388718(f32 *, void *, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L04_00355778(void *);
extern f32 func_003BEBF8(f32 *, f32, f32);

void func_L04_00355400(u8 *a0) {
    f32 *q = *(f32 **)(a0 + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    u8 c[0x30];
    vu0_v4 e;
    u8 *h;
    u8 *h2;
    f32 dt;
    s32 i;
    f32 k;
    f32 *p;

    if (func_L01_00448E90(a0 + 0x10) == 0)
        return;
    switch (a0[0x20]) {
    case 0:
        q[0] = 1.0f;
        q[8] = func_0037E2A8();
        q[2] = 0.5f;
        q[1] = 0.0f;
        q[0] = 1.0f;
        for (i = 0; i < 4; i++)
            q[4 + i] = 1.0f;
        a0[0x30] = 0xFF;
        func_L01_00441FB8(a0, 1, -1);
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        break;
    case 1:
        if (D_001D545C == 0x10) {
            *(u128_t_356318 *)&a = *(u128_t_356318 *)(D_001A4BE0 + 0x80);
            h = D_001A4BE0;
            func_00388830(&b, *(u8 **)(h + 0x25C0) + 0xE0, 0.75f);
            vec_add_ab(&a, &a, &b);
            if (func_L01_003F9498(&a, 0, *(u8 **)(h + 0x25C0), 0.5f) != 0 && D_L04_001E9618[0] != 0 && D_L04_001E9618[0] == a0) {
                func_L01_00443628(c, a0, 1, 100.0f, D_L04_001D66B0_00355400);
                *(u16 *)(c + 0x1A) = *(u16 *)(a0 + 0xAA);
                func_L01_004EA040();
            }
            h2 = D_001A4BE0;
            if (*(u8 **)(h2 + 0x35C) != 0 && *(u8 **)(h2 + 0x35C) == a0 && *(s32 *)(h2 + 0x360) != 0) {
                e.x = 0.0f;
                e.y = 1.0f;
                e.z = 0.0f;
                e.w = 1.0f;
                func_00388830(&e, &e, 10.0f);
                func_L01_00443628(c, a0, 1, 10.0f, &e);
                *(u16 *)(c + 0x1A) = *(u16 *)(a0 + 0xAA);
                func_L01_004EA040();
            }
        }
        break;
    case 2:
        break;
    }
    if (func_00388800(a0 + 0x10, D_001A4BE0 + 0x80) < 8.0f) {
        func_003BD360(a0);
        return;
    }
    if (q[0] == 0.0f)
        return;
    dt = 0.0166666675f;
    func_00388718(&a.x, a0, 0.0009765625f);
    q[8] = func_00389380(q[8], D_L04_001DD350 * 0.017453292f * dt);
    q[3] = q[3] + (D_L04_001DD354 + func_L01_00440918(0.25f, 0.5f)) * dt;
    if (1.0f < q[3])
        q[3] = q[3] - 1.0f;
    k = D_L04_001DD358 * dt;
    p = q + 1;
    for (i = 0; i < 2; i++) {
        *p = *p + k;
        if (1.0f < *p)
            *p = *p - 1.0f;
        p++;
    }
    func_L01_00402498(func_L04_00355778, a0);
    func_003BEBF8(q, 1.0f, 0.00833333377f);
}
/* localdecomp:end func_L04_00355400 */
