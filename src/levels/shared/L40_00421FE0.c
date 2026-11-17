#include "common.h"

/* declared by functions of L40_00420998.c, which this file was cut from */
extern s32 func_L39_005F33E0(s32, s32, u8 *);

/* declared by functions of L40_00421920.c, which this file was cut from */
extern void *func_L40_00421FE0(void *, void *, void *, void *, void *, void *, s32, s32, s32);

/* localdecomp:start func_L40_00421FE0 */
typedef int u128_00421FE0 __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);

void *func_L40_00421FE0(void *p0, void *p1, void *p2, void *p3, void *p4, void *p5, s32 n, s32 x7, s32 x8) {
    u8 *a0 = p0;
    u8 *o = func_003C24B0(0x1C5E, 0x80);
    u8 *v;
    s32 r, g, b;

    if (o != 0) {
        *(u8 **)(o + 0xB8) = a0;
        o[0x30] = 0xFF;
        v = *(u8 **)(o + 0x68);
        *(u128_00421FE0 *)(o + 0x10) = *(u128_00421FE0 *)(a0 + 0x10);
        *(u8 **)(v + 0x48) = a0;
        *(u128_00421FE0 *)(v + 0x00) = *(u128_00421FE0 *)p1;
        *(u128_00421FE0 *)(v + 0x20) = *(u128_00421FE0 *)p3;
        *(u128_00421FE0 *)(v + 0x10) = *(u128_00421FE0 *)p2;
        *(u128_00421FE0 *)(v + 0x30) = *(u128_00421FE0 *)p4;
        *(u8 **)(v + 0x40) = a0;
        *(f32 *)(v + 0x5C) = 1.0f / (f32)n;
        func_003C6FB0(a0, &r, &g, &b);
        *(s32 *)(v + 0x54) = 0x80000000 + (b << 16) + (g << 8) + r;
    }
    return o;
}
/* localdecomp:end func_L40_00421FE0 */
