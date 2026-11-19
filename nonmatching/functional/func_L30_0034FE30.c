/* functional: high. From asm; gp globals by address; 125 diff = scheduling */
#include "vu0.h"
extern f32 D_L30_001DD6D4;
__asm__(".extern D_L30_001DD6D4, 4");
extern f32 D_L30_001DD6C8;
__asm__(".extern D_L30_001DD6C8, 4");
extern f32 D_L30_001DD6D8;
__asm__(".extern D_L30_001DD6D8, 4");
extern f32 D_L30_001DD6E4;
__asm__(".extern D_L30_001DD6E4, 4");
extern f32 D_L30_001DD6C4;
__asm__(".extern D_L30_001DD6C4, 4");
extern s32 D_L30_001DD6C0;
__asm__(".extern D_L30_001DD6C0, 4");
extern s32 D_L30_001DD6BC;
__asm__(".extern D_L30_001DD6BC, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L30_0034FE30(u8 *out, u8 *in) {
    u8 *obj;
    f32 hi;
    f32 lo;
    f32 off;
    f32 g;

    if (in == 0) {
        return;
    }
    obj = *(u8 **)in;
    if (obj == 0) {
        return;
    }
    if (*(u32 *)(obj + 0x68) == 0) {
        return;
    }
    if (in[9] & 1) {
        *(f32 *)(in + 0xC) = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    }
    g = D_L30_001DD6D4 + 1.0f;
    hi = g * (1.0f - (f32)*(s16 *)(out + 0xA) * 0.25f / (f32)in[8]);
    if (1.0f < hi) {
        hi = 1.0f;
    }
    lo = g * (1.0f - (f32)*(s16 *)(out + 0xA) * 0.25f / (f32)in[8]) - D_L30_001DD6D4;
    if (lo < 0.0f) {
        lo = 0.0f;
    }
    off = D_L30_001DD6C8 * (f32)in[0xA] * 0.00390625f;
    *(f32 *)(out + 0x10) = func_0038D098(*(f32 *)(in + 0xC)) * (D_L30_001DD6D8 * hi + off);
    *(f32 *)(out + 0x14) = 0.0f;
    *(f32 *)(out + 0x18) = func_0038D0B0(*(f32 *)(in + 0xC)) * (D_L30_001DD6D8 * hi + off);
    *(f32 *)(out + 0x10) += *(f32 *)(obj + 0x10);
    *(f32 *)(out + 0x14) += *(f32 *)(obj + 0x14);
    *(f32 *)(out + 0x18) += *(f32 *)(obj + 0x18);
    *(f32 *)(out + 0x20) = func_0038D098(*(f32 *)(in + 0xC)) * (D_L30_001DD6D8 * lo + off);
    *(f32 *)(out + 0x24) = 0.0f;
    *(f32 *)(out + 0x28) = func_0038D0B0(*(f32 *)(in + 0xC)) * (D_L30_001DD6D8 * lo + off);
    *(f32 *)(out + 0x20) += *(f32 *)(obj + 0x10);
    *(f32 *)(out + 0x24) += *(f32 *)(obj + 0x14);
    *(f32 *)(out + 0x28) += *(f32 *)(obj + 0x18);
    *(f32 *)(out + 0x1C) = D_L30_001DD6E4;
    *(f32 *)(out + 0x2C) = D_L30_001DD6C4;
    *(s32 *)(out + 4) = func_0038DBD8(D_L30_001DD6C0, D_L30_001DD6BC, hi);
    *(s32 *)(out + 0xC) = func_0038DBD8(D_L30_001DD6C0, D_L30_001DD6BC, lo);
}
