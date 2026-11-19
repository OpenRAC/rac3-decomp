/* functional: medium. From asm; func_0038DAB8 (angle step helper) usage inferred from callers; gp float/int globals named by address; 163 diff = scheduling */
#include "vu0.h"
extern f32 D_L30_001DD678;
__asm__(".extern D_L30_001DD678, 4");
extern f32 D_L30_001DD67C;
__asm__(".extern D_L30_001DD67C, 4");
extern f32 D_L30_001DD688;
__asm__(".extern D_L30_001DD688, 4");
extern s32 D_L30_001DD664;
__asm__(".extern D_L30_001DD664, 4");
extern s32 D_L30_001DD668;
__asm__(".extern D_L30_001DD668, 4");
extern s32 D_L30_001DD66C;
__asm__(".extern D_L30_001DD66C, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L30_0034F998(u8 *out, u8 *in) {
    u8 *obj;
    u8 *v;
    vu0_v4 c;
    f32 t;
    f32 lo;
    f32 hi;
    f32 ang;
    f32 a1;
    f32 a2;
    f32 f;
    s32 first;
    s32 col;

    if (in == 0) {
        return;
    }
    obj = *(u8 **)in;
    if (obj == 0) {
        return;
    }
    v = *(u8 **)(obj + 0x68);
    if (v == 0) {
        return;
    }
    t = (f32)*(s16 *)(out + 0xA) * 0.25f / (f32)in[8];
    lo = (D_L30_001DD678 + 1.0f) * (1.0f - t);
    if (1.0f < lo) {
        lo = 1.0f;
    }
    hi = (D_L30_001DD678 + 1.0f) * (1.0f - t) - D_L30_001DD678;
    if (hi < 0.0f) {
        hi = 0.0f;
    }
    first = *(u16 *)(in + 0xA) & 1;
    c.x = func_0038D098(*(f32 *)(v + 0x1C)) * D_L30_001DD67C;
    c.y = 0.0f;
    c.z = func_0038D0B0(*(f32 *)(v + 0x1C)) * D_L30_001DD67C;
    if (first) {
        c.x = *(f32 *)(obj + 0x10) + c.x;
        c.y = *(f32 *)(obj + 0x14) + c.y;
        c.z = *(f32 *)(obj + 0x18) + c.z;
    } else {
        c.x = *(f32 *)(obj + 0x10) - c.x;
        c.y = *(f32 *)(obj + 0x14) - c.y;
        c.z = *(f32 *)(obj + 0x18) - c.z;
    }
    ang = func_0038DAB8(func_0038DAB8(*(f32 *)(v + 0x1C), 3.1415927f), lo * 6.2831855f);
    a1 = ang;
    a2 = func_0038DAB8(func_0038DAB8(*(f32 *)(v + 0x1C), 3.1415927f), hi * 6.2831855f);
    *(f32 *)(out + 0x10) = func_0038D098(a1) * D_L30_001DD67C;
    *(f32 *)(out + 0x14) = 0.0f;
    *(f32 *)(out + 0x18) = func_0038D0B0(a1) * D_L30_001DD67C;
    *(f32 *)(out + 0x10) += c.x;
    *(f32 *)(out + 0x14) += c.y;
    *(f32 *)(out + 0x18) += c.z;
    *(f32 *)(out + 0x20) = func_0038D098(a2) * D_L30_001DD67C;
    *(f32 *)(out + 0x24) = 0.0f;
    *(f32 *)(out + 0x28) = func_0038D0B0(a2) * D_L30_001DD67C;
    *(f32 *)(out + 0x20) += c.x;
    *(f32 *)(out + 0x24) += c.y;
    *(f32 *)(out + 0x28) += c.z;
    *(f32 *)(out + 0x2C) = 1.0f;
    *(f32 *)(out + 0x1C) = D_L30_001DD688;
    f = 1.0f - (f32)*(s32 *)(v + 0x18) / (f32)D_L30_001DD608;
    if (0.5f < f) {
        col = func_0038DBD8(D_L30_001DD668, D_L30_001DD664, (f - 0.5f) * 2.0f);
    } else {
        col = func_0038DBD8(D_L30_001DD66C, D_L30_001DD668, f + f);
    }
    *(s32 *)(out + 4) = col;
    *(s32 *)(out + 0xC) = col;
}
