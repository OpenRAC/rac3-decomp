/* Historical draft; resolved as plain C in src/levels/04_marcadia/L04_003CD2C0.c. */
#include "common.h"

/* localdecomp:start func_L04_003CE348 */
typedef int u128_3CE348 __attribute__((mode(TI)));

extern void *func_003C24B0(s32 a0, s32 a1);
extern s32 func_L01_00456160(void *a0, u8 *a1);
extern void (**func_L01_0043B548(s32 a0, s32 a1))(u8 *);
extern void func_003C2880(u8 *a0);
extern void func_L04_003CE760(u8 *a0, s32 a1, s32 a2, s32 a3);
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

s32 func_L04_003CE348(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s16 h34;
    void *p;
    void (**t)(u8 *);

    h34 = *(s16 *)(s1 + 0x34);
    *(s16 *)(s1 + 0x198) = 0;
    *(u128_3CE348 *)(s1 + 0x2D0) = *(u128_3CE348 *)(a0 + 0x10);
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    *(f32 *)(s1 + 0x194) = 0.5f;
    *(u8 *)(s1 + 0x1D9) = 2;
    *(u8 *)(s1 + 0x172) = 255;
    *(u8 *)(s1 + 0x1A8) = 255;
    *(f32 *)(s1 + 0x190) = 0.5f;
    *(u8 *)(s1 + 0x1D8) = 2;
    *(u8 *)(s1 + 0x1DB) = 255;
    *(u8 *)(s1 + 0x176) = 255;
    *(u8 *)(s1 + 0x171) = 255;
    *(u8 *)(s1 + 0x170) = 12;
    *(f32 *)(s1 + 0x19C) = 0.15f;
    *(u8 *)(s1 + 0x1D7) = 1;
    *(f32 *)(s1 + 0x70) = 0.75f;
    *(f32 *)(s1 + 0x74) = 0.2f;
    *(f32 *)(s1 + 0x78) = 1.0f;
    *(f32 *)(s1 + 0x7C) = 1.75f;
    *(f32 *)(s1 + 0x80) = 1.3089969f;
    *(f32 *)(s1 + 0xA0) = 0.34906584f;
    *(f32 *)(s1 + 0x9C) = 0.00392f;
    *(u8 *)(s1 + 0x58) = 20;
    *(u8 *)(s1 + 0x5A) = 14;
    *(u8 *)(s1 + 0x1DA) = 0;

    if (h34 == 0 || *(f32 *)(s1 + 0x30) <= 0.0f) {
        *(s16 *)(s1 + 0x34) = 10;
        *(f32 *)(s1 + 0x30) = 10.0f;
    }
    if (*(u8 *)(s1 + 0x44) == 0) {
        *(u8 *)(s1 + 0x44) = 1;
    }
    *(f32 *)(s1 + 0x40) = 2.0f;
    *(u8 *)(s1 + 0x38) = 1;
    *(u8 *)(s1 + 0x39) = 1;
    if (*(s32 *)(s1 + 0x300) == 0) {
        p = func_003C24B0(0x19C1, 0x80);
        *(void **)(s1 + 0x300) = p;
        func_L01_00456160(p, a0);
    }

    *(s16 *)(s1 + 0x30C) = (*(s32 *)(s1 + 0x304) == -1);
    *(s16 *)(s1 + 0x30E) = (*(s32 *)(s1 + 0x308) == -1);
    *(s32 *)(s1 + 0x2F0) = 0;
    *(s32 *)(s1 + 0x2F4) = 0;
    *(s32 *)(s1 + 0x2F8) = 0;
    if (*(s32 *)(s1 + 0x240) > 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(s1 + 0x240) = -1;
        func_L04_003CE760(a0, 0, 0, 1);
        *(u8 *)(s1 + 0x24E) = 11;
        *(u8 *)(s1 + 0x24F) = 4;
        (*t)(a0);
        if (*(void **)(s1 + 0x300) != 0) {
            func_003C2880(*(u8 **)(s1 + 0x300));
            *(void **)(s1 + 0x300) = 0;
        }
    } else {
        func_L01_004450F0(a0, 3, 0);
        func_L04_003CE760(a0, 0, 0, 1);
    }
    return 0;
}
/* localdecomp:end func_L04_003CE348 */
