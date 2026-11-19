/* functional: high. From asm; gp offsets verified equal in diff; literals 2pi in gp in mine vs lui in retail; 123 diff = scheduling */
#include "vu0.h"
extern f32 D_L30_001DD6B4;
__asm__(".extern D_L30_001DD6B4, 4");
extern f32 D_L30_001DD69C;
__asm__(".extern D_L30_001DD69C, 4");
extern f32 D_L30_001DD6A0;
__asm__(".extern D_L30_001DD6A0, 4");
extern f32 D_L30_001DD6AC;
__asm__(".extern D_L30_001DD6AC, 4");
extern f32 D_L30_001DD6B0;
__asm__(".extern D_L30_001DD6B0, 4");
extern s32 D_L30_001DD68C;
__asm__(".extern D_L30_001DD68C, 4");
extern s32 D_L30_001DD690;
__asm__(".extern D_L30_001DD690, 4");
extern u8 D_L30_001DD6B8;
__asm__(".extern D_L30_001DD6B8, 1");
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L30_0034DBA0(s32, s32);

void func_L30_0034FC30(u8 *out, u8 *in) {
    u8 *obj;
    f32 t;
    f32 r;
    f32 r2;
    s32 a;

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
        *(s32 *)(out + 4) = func_L30_0034DBA0(D_L30_001DD68C, D_L30_001DD690);
        *(s32 *)(out + 0xC) = func_L30_0034DBA0(D_L30_001DD68C, D_L30_001DD690);
        out[3] = D_L30_001DD6B8;
    }
    t = func_L03_0034B148(*(s16 *)(out + 0xA), in[8] << 2, D_L30_001DD6B4);
    r = func_003C4088(D_L30_001DD6A0, D_L30_001DD69C, (f32)in[0xA] * 0.00390625f);
    r2 = r * t;
    *(f32 *)(out + 0x10) = func_0038D098(*(f32 *)(in + 0xC)) * r2;
    *(f32 *)(out + 0x14) = 0.0f;
    *(f32 *)(out + 0x18) = func_0038D0B0(*(f32 *)(in + 0xC)) * r2;
    *(f32 *)(out + 0x10) += *(f32 *)(obj + 0x10);
    *(f32 *)(out + 0x14) += *(f32 *)(obj + 0x14);
    *(f32 *)(out + 0x18) += *(f32 *)(obj + 0x18);
    r2 = -r * t;
    *(f32 *)(out + 0x20) = func_0038D098(*(f32 *)(in + 0xC)) * r2;
    *(f32 *)(out + 0x24) = 0.0f;
    *(f32 *)(out + 0x28) = func_0038D0B0(*(f32 *)(in + 0xC)) * r2;
    *(f32 *)(out + 0x20) += *(f32 *)(obj + 0x10);
    *(f32 *)(out + 0x24) += *(f32 *)(obj + 0x14);
    *(f32 *)(out + 0x28) += *(f32 *)(obj + 0x18);
    *(f32 *)(out + 0x2C) = 1.0f;
    *(f32 *)(out + 0x1C) = D_L30_001DD6AC;
    a = (s32)((1.0f - func_L03_0034B148(*(s16 *)(out + 0xA), in[8] << 2, D_L30_001DD6B0)) * 128.0f) << 24;
    *(s32 *)(out + 0xC) = (*(s32 *)(out + 0xC) & 0xFFFFFF) + a;
    *(s32 *)(out + 4) = (*(s32 *)(out + 4) & 0xFFFFFF) + a;
}
