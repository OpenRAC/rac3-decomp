/* functional: high. From asm; gp floats named by address; 166 diff = scheduling/regalloc */
#include "vu0.h"
extern f32 D_L30_001DD048;
__asm__(".extern D_L30_001DD048, 4");
extern f32 D_L30_001DD078;
__asm__(".extern D_L30_001DD078, 4");
extern f32 D_L30_001DD074;
__asm__(".extern D_L30_001DD074, 4");
extern f32 D_L30_001DD054;
__asm__(".extern D_L30_001DD054, 4");
extern f32 D_L30_001DD058;
__asm__(".extern D_L30_001DD058, 4");
extern f32 D_L30_001DD044;
__asm__(".extern D_L30_001DD044, 4");
extern f32 D_L30_001DD040;
__asm__(".extern D_L30_001DD040, 4");
extern f32 D_L30_001DD064;
__asm__(".extern D_L30_001DD064, 4");
extern f32 D_L30_001DD060;
__asm__(".extern D_L30_001DD060, 4");
extern f32 D_L30_001DD03C;
__asm__(".extern D_L30_001DD03C, 4");
extern f32 D_L30_001DD05C;
__asm__(".extern D_L30_001DD05C, 4");
extern f32 D_L30_001DD068;
__asm__(".extern D_L30_001DD068, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C958(vu0_v4 *, f32);

void func_L30_00347C20(u8 *out, u8 *in) {
    u8 *obj;
    u8 *v;
    f32 speed;
    f32 ang;
    f32 w;
    f32 sx;
    f32 sz;
    f32 t;
    f32 lo;
    f32 hi;

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
    if (*(u32 *)(in + 4) == 0) {
        return;
    }
    if (*(u16 *)(in + 0xA) & 1) {
        *(vu0_q *)(out + 0x10) = *(vu0_q *)(obj + 0x10);
        func_L30_0034C958((vu0_v4 *)(out + 0x10), D_L30_001DD048);
        speed = func_003824E0(D_L30_001DD078, D_L30_001DD074) * *(f32 *)(v + 0x50);
        ang = *(f32 *)(v + 0x48) + (*(s32 *)(v + 0x4C) != 0 ? 1.5707964f : -1.5707964f);
        sx = func_0038D098(func_0038DB48(ang)) * speed;
        ang = *(f32 *)(v + 0x48) + (*(s32 *)(v + 0x4C) != 0 ? 1.5707964f : -1.5707964f);
        sz = func_0038D0B0(func_0038DB48(ang)) * speed;
        w = func_003824E0(D_L30_001DD058, D_L30_001DD054);
        sx += func_0038D098(*(f32 *)(v + 0x48)) * w;
        sz += func_0038D0B0(*(f32 *)(v + 0x48)) * w;
        *(f32 *)(in + 0x10) = sx;
        *(f32 *)(in + 0x14) = sz;
        *(f32 *)(in + 0x18) = func_003824E0(D_L30_001DD044, D_L30_001DD040);
        out[3] = 0x49;
        *(s32 *)(out + 4) = 0x80000000;
        *(f32 *)(in + 0x1C) = func_003824E0(D_L30_001DD064, D_L30_001DD060);
    }
    t = func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(out + 0xA), (f32)*(s16 *)(in + 8), 1.0f);
    *(f32 *)(in + 0x14) += *(f32 *)(in + 0x18);
    *(f32 *)(out + 0x10) += *(f32 *)(in + 0x10);
    *(s32 *)(out + 4) = (s32)(D_L30_001DD03C * (1.0f - t)) << 24;
    *(f32 *)(out + 0x18) += *(f32 *)(in + 0x14);
    lo = (f32)(*(u16 *)(in + 0xE) & 0xFF);
    hi = D_L30_001DD05C * (f32)*(s16 *)(in + 8) * (f32)(*(u16 *)(in + 0xE) >> 8) * 0.00390625f;
    hi = lo + (lo + hi);
    out[8] = (s32)func_003C4088(lo, hi, func_L03_0034B148(*(s16 *)(out + 0xA), *(s16 *)(in + 8), 0.0f));
    *(f32 *)(out + 0xC) = *(f32 *)(in + 0x1C) * func_003C4088(1.0f, D_L30_001DD068, t);
}
