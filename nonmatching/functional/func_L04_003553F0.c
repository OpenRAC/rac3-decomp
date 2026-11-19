/* functional: high. Ported from the NTSC-U twin draft with PAL callee names and PAL asm checked (constants 0.15, 0.8, 0.0725, 1.5, 3.0, 0.3, 0.04, 0.4 identical); spawns a streak effect object (type 0xEA7) with velocity, size, two glow particles. */
#include "common.h"
#include "vu0.h"

extern s32 D_001DD308_sda, D_001DD30C_sda;
__asm__(".extern D_001DD308_sda, 4");
__asm__(".extern D_001DD30C_sda, 4");
extern u8 D_L04_001D66B0;
extern u8 *func_003C24B0(s32, s32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_0038D308(void *, void *);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern void func_003A52A0(s32, s32, void *);

u8 *func_L04_003553F0(u8 *source, vu0_v4 *velocity, vu0_v4 *position, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 size) {
    u8 *m = func_003C24B0(0xEA7, 0x80);
    u8 *d;
    f32 radius, speed;
    if (m) {
        m[0x31] = 1;
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0xFF;
        m[0x20] = 0;
        d = *(u8 **)(m + 0x68);
        *(unsigned long *)(m + 0x38) = *(unsigned long *)(source + 0x38);
        *(vu0_v4 *)(m + 0x10) = *position;
        *(f32 *)(d + 0x14) = size;
        *(vu0_v4 *)d = *velocity;
        *(u8 **)(d + 0x10) = source;
        *(f32 *)(d + 0x20) = 0.15f;
        *(u16 *)(m + 0x34) |= 0x208;
        *(s32 *)(d + 0x2C) = arg3;
        *(s32 *)(d + 0x30) = arg4;
        d[0x34] = arg5;
        speed = func_0038CEA8(velocity) * 0.8f;
        *(f32 *)(d + 0x3C) = speed;
        *(f32 *)(d + 0x38) = -speed;
        *(f32 *)(m + 0xF8) = func_0038DAB8(func_0038D160(velocity->x, velocity->y), 1.5707963705062866f);
        *(f32 *)(m + 0xF0) = -func_0038D160(func_0038CED8(velocity), velocity->z);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(u16 *)(m + 0x34) |= 0x100;
        m[0x23] = 0x80;
        *(f32 *)(m + 0x2C) = 0.0725f;
        *(s32 *)(d + 0x24) = 0;
        radius = func_003824E0(1.5f, 3.0f);
        *(s32 *)(d + 0x4C) = arg6;
        *(s32 *)(d + 0x40) = D_001DD308_sda;
        *(s32 *)(d + 0x44) = D_001DD30C_sda;
        *(s32 *)(d + 0x48) = 0x80803010;
        func_L01_0046B458(m + 0x10, 15, 0x80803010, 0, 10, &D_L04_001D66B0, 0, radius * 0.3f, radius, 0.0f);
        func_L01_0046B458(m + 0x10, 15, -1, 1, -10, &D_L04_001D66B0, 0, radius * 0.04f, radius * 0.4f, 0.0f);
        func_003A52A0(0, 0, m);
    }
    return m;
}
