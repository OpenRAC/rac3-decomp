#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L04_003553F0 (src/levels/shared/L04_003553F0.c) */
/* localdecomp:start func_L04_003544D0 */
extern s32 D_L04_001DD348, D_L04_001DD34C;
__asm__(".extern D_L04_001DD348, 4");
__asm__(".extern D_L04_001DD34C, 4");
extern u8 D_L04_001D66B0[] __attribute__((section(".sdata")));
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_00388770(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003887A0(void *);
extern void func_00388BD0(void *, void *);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_0039FE80(s32, s32, void *);

u8 *func_L04_003544D0(u8 *source, vu0_v4 *velocity, vu0_v4 *position, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 size) {
    u8 *m = func_003BCFB0(0xEA7, 0x80);
    u8 *d;
    f32 radius, speed;
    s32 w0, w1;
    if (m) {
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        d = *(u8 **)(m + 0x68);
        *(unsigned long *)(m + 0x38) = *(unsigned long *)(source + 0x38);
        *(vu0_v4 *)(m + 0x10) = *position;
        *(vu0_v4 *)d = *velocity;
        *(f32 *)(d + 0x14) = size;
        *(u8 **)(d + 0x10) = source;
        *(f32 *)(d + 0x20) = 0.15f;
        *(u16 *)(m + 0x34) |= 0x208;
        *(s32 *)(d + 0x2C) = arg3;
        *(s32 *)(d + 0x30) = arg4;
        d[0x34] = arg5;
        speed = func_00388770(velocity) * 0.8f;
        *(f32 *)(d + 0x3C) = speed;
        *(f32 *)(d + 0x38) = -speed;
        *(f32 *)(m + 0xF8) = func_00389380(func_00388A28(velocity->x, velocity->y), 1.5707963705062866f);
        *(f32 *)(m + 0xF0) = -func_00388A28(func_003887A0(velocity), velocity->z);
        func_00388BD0(m + 0xC0, m + 0xF0);
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x23] = 0x80;
        *(f32 *)(m + 0x2C) = 0.0725f;
        *(s32 *)(d + 0x24) = 0;
        radius = func_0037E250(1.5f, 3.0f);
        w0 = D_L04_001DD348;
        w1 = D_L04_001DD34C;
        *(s32 *)(d + 0x4C) = arg6;
        *(s32 *)(d + 0x40) = w0;
        *(s32 *)(d + 0x48) = 0x80803010;
        *(s32 *)(d + 0x44) = w1;
        func_L01_00467DA8(m + 0x10, 15, radius * 0.3f, radius, 0x80803010, 0, 10, D_L04_001D66B0, 0.0f, 0);
        func_L01_00467DA8(m + 0x10, 15, radius * 0.04f, radius * 0.4f, -1, 1, -10, D_L04_001D66B0, 0.0f, 0);
        func_0039FE80(0, 0, m);
    }
    return m;
}
/* localdecomp:end func_L04_003544D0 */
