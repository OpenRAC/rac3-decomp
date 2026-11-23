/* functional: high. From asm; callee prototypes from matched callers; 140 diff = scheduling and 2pi constant loaded via gp (retail uses lui); gp floats named by address (gp=0x1DC8B0) */
#include "vu0.h"
extern s32 D_L30_001DCF80;
__asm__(".extern D_L30_001DCF80, 4");
extern s32 D_L30_001DCF84;
__asm__(".extern D_L30_001DCF84, 4");
extern f32 D_L30_001DCF90;
__asm__(".extern D_L30_001DCF90, 4");
extern f32 D_L30_001DCF94;
__asm__(".extern D_L30_001DCF94, 4");
extern f32 D_L30_001DCF98;
__asm__(".extern D_L30_001DCF98, 4");
extern f32 D_L30_001DCF9C;
__asm__(".extern D_L30_001DCF9C, 4");
extern f32 D_L30_001DCFA0;
__asm__(".extern D_L30_001DCFA0, 4");
extern f32 D_L30_001DCFAC;
__asm__(".extern D_L30_001DCFAC, 4");
extern f32 D_L30_001DCFB0;
__asm__(".extern D_L30_001DCFB0, 4");
extern f32 D_L30_001DCFF4;
__asm__(".extern D_L30_001DCFF4, 4");
extern f32 D_L30_001DCFF8;
__asm__(".extern D_L30_001DCFF8, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_0034C958(vu0_v4 *, f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);

void func_L30_00347060(u8 *out, u8 *in) {
    u8 *obj;
    u8 *v;
    vu0_v4 heading;
    vu0_v4 dir;
    vu0_v4 a;
    vu0_v4 b;
    f32 ang;
    f32 r;
    f32 t;
    f32 lo;
    f32 hi;

    if (in == 0) {
        return;
    }
    obj = *(u8 **)in;
    v = *(u8 **)(obj + 0x68);
    if (*(u16 *)(in + 0xA) & 1) {
        if (obj == 0 || v == 0 || *(u32 *)(in + 4) == 0) {
            return;
        }
        *(vu0_q *)(out + 0x10) = *(vu0_q *)(obj + 0x10);
        func_L30_0034C958((vu0_v4 *)(out + 0x10), D_L30_001DCF90);
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        r = func_003824E0(D_L30_001DCFB0, D_L30_001DCFAC);
        heading.x = func_0038D098(*(f32 *)(v + 0xA0));
        heading.z = func_0038D0B0(*(f32 *)(v + 0xA0));
        heading.y = 0.0f;
        dir.x = func_0038D098(ang) * r;
        dir.y = 0.0f;
        dir.z = func_0038D0B0(ang) * r;
        func_L02_003BA9F8(&dir, &heading, &a, &b);
        func_0038CE20(&a, &a, 1.0f - D_L30_001DCFF4);
        func_0038CE20(&b, &b, D_L30_001DCFF4 + 1.0f);
        dir.x = a.x + b.x;
        dir.y = a.y + b.y;
        dir.z = a.z + b.z;
        *(f32 *)(in + 0x10) = dir.x;
        *(f32 *)(in + 0x14) = dir.z;
        *(f32 *)(in + 0x18) = func_003824E0(D_L30_001DCFA0, D_L30_001DCF9C);
        *(f32 *)(in + 0x1C) = func_003824E0(D_L30_001DCF98, D_L30_001DCF94);
    }
    t = func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(out + 0xA), (f32)*(s16 *)(in + 8), 1.0f);
    *(f32 *)(out + 0x10) += *(f32 *)(in + 0x10);
    *(f32 *)(out + 0x18) += *(f32 *)(in + 0x14);
    *(s32 *)(out + 4) = func_0038DBD8(D_L30_001DCF84, D_L30_001DCF80, t);
    *(f32 *)(out + 0xC) = func_003C4088(*(f32 *)(in + 0x18), *(f32 *)(in + 0x1C), t);
    lo = (f32)(*(u16 *)(in + 0xE) & 0xFF);
    hi = D_L30_001DCFF8 * (f32)*(s16 *)(in + 8) * (f32)(*(u16 *)(in + 0xE) >> 8) * 0.00390625f;
    out[8] = (s32)func_003C4088(lo, lo + hi, t);
}
