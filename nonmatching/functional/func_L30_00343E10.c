/* functional: high. Written from asm; gp floats named by address (gp=0x1DC8B0); vec_add_ab replaced by 4 float adds (VU asm pressure fails to compile in this function); 183 diff = regalloc/scheduling */
#include "vu0.h"
extern f32 D_L30_001DCE90;
extern f32 D_L30_001DCEE0;
extern f32 D_L30_001DCEE4;
extern f32 D_L30_001DCEE8;
extern f32 D_L30_001DCEEC;
extern f32 D_L30_001DCEF0;
extern f32 D_L30_001DCEF4;
extern f32 D_L30_001DCEF8;
extern f32 D_L30_001DCEFC;
extern u8 D_L30_001DCF00;
extern u8 D_L30_001DCF01;
extern f32 D_L30_001DCF04;
__asm__(".extern D_L30_001DCE90, 4");
__asm__(".extern D_L30_001DCEE0, 4");
__asm__(".extern D_L30_001DCEE4, 4");
__asm__(".extern D_L30_001DCEE8, 4");
__asm__(".extern D_L30_001DCEEC, 4");
__asm__(".extern D_L30_001DCEF0, 4");
__asm__(".extern D_L30_001DCEF4, 4");
__asm__(".extern D_L30_001DCEF8, 4");
__asm__(".extern D_L30_001DCEFC, 4");
__asm__(".extern D_L30_001DCF00, 1");
__asm__(".extern D_L30_001DCF01, 1");
__asm__(".extern D_L30_001DCF04, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L30_00343AC8(void *, void *, f32 *, f32 *);

void func_L30_00343E10(u8 *out, u8 *in) {
    u8 *obj;
    u8 *v;
    vu0_v4 off;
    vu0_v4 pos;
    f32 w;
    f32 h;
    f32 radius;
    f32 t;
    f32 ang;
    f32 c;
    f32 s;
    f32 sz;
    f32 a;
    s32 col;
    f32 r;

    if (in == 0) {
        return;
    }
    obj = *(u8 **)in;
    if (obj == 0) {
        return;
    }
    v = *(u8 **)(obj + 0x68);
    if (*(u32 *)(in + 4) == 0) {
        return;
    }
    func_L30_00343AC8(obj, &off, &w, &h);
    if (obj[0x20] == 1) {
        r = sqrt_asm(w * w + h * h);
        radius = D_L30_001DCE90 * *(f32 *)(v + 0x160) * r + r;
    } else if (obj[0x20] == 2) {
        r = sqrt_asm(w * w + h * h);
        radius = r * (D_L30_001DCE90 * (1.0f - *(f32 *)(v + 0x160)) + 1.0f);
    } else {
        radius = 0.0f;
    }
    if (*(u16 *)(in + 0xA) & 1) {
        *(f32 *)(in + 0x10) = func_003824E0(0.0f, 1.0f);
        *(f32 *)(in + 0x14) = func_003824E0(D_L30_001DCF04, 1.0f);
        *(f32 *)(in + 0x10) = 1.0f - *(f32 *)(in + 0x10) * *(f32 *)(in + 0x10);
    }
    t = func_L03_0034B148(*(s16 *)(out + 0xA), *(s16 *)(in + 8), 0.0f);
    s = func_0038D0B0(func_0038DB48(t * 3.1415927f));
    a = (f32)*(u8 *)(in + 0xC) * 3.1415927f * 0.0078125f;
    ang = func_0038DB48(func_003C4088(a, a + D_L30_001DCEE8 * 6.2831855f * *(f32 *)(in + 0x10), t));
    radius = *(f32 *)(in + 0x10) * radius;
    pos.x = func_0038D098(ang) * radius;
    pos.y = 0.0f;
    pos.z = func_0038D0B0(ang) * radius;
    *(f32 *)(out + 0x10) = *(f32 *)(v + 0x130) + pos.x;
    *(f32 *)(out + 0x14) = *(f32 *)(v + 0x134) + pos.y;
    *(f32 *)(out + 0x18) = *(f32 *)(v + 0x138) + pos.z;
    *(f32 *)(out + 0x1C) = *(f32 *)(v + 0x13C);
    *(f32 *)(out + 0x14) += D_L30_001DCEFC;
    if (*(f32 *)(in + 0x10) < *(f32 *)(in + 0x14)) {
        out[3] = D_L30_001DCF01;
        sz = s * D_L30_001DCEEC;
        sz *= func_003C4088(D_L30_001DCEF0, 1.0f,
                            (*(f32 *)(in + 0x14) - *(f32 *)(in + 0x10)) / *(f32 *)(in + 0x14));
        col = (s32)sz << 24;
    } else {
        out[3] = D_L30_001DCF00;
        sz = s * D_L30_001DCEF4;
        sz *= func_003C4088(D_L30_001DCEF8, 1.0f,
                            (*(f32 *)(in + 0x10) - *(f32 *)(in + 0x14)) / (1.0f - *(f32 *)(in + 0x14)));
        col = ((s32)sz << 24) | 0x808080;
    }
    *(s32 *)(out + 4) = col;
    {
        f32 lo = (f32)((*(s16 *)(in + 0xC) & 0xFF00) >> 8);
        f32 hi = (f32)((*(s16 *)(in + 0xE) & 0xFF00) >> 8);
        f32 sv = func_003C4088(lo, lo + D_L30_001DCEE0 * hi, t);
        out[8] = (s32)sv;
        *(f32 *)(out + 0xC) = D_L30_001DCEE4 * sqrt_asm(s);
    }
}
