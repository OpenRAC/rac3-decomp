/* functional: medium. From asm; gp globals by address (gp=0x1DC8B0), types of the int ones guessed; func_L03_0034B440 result is dropped in retail too (kept as a call); the u32->float alpha conversion artefact (bltzl) is done as plain (f32)(u32); 186 diff = scheduling */
#include "vu0.h"
extern f32 D_L30_001DD630;
__asm__(".extern D_L30_001DD630, 4");
extern f32 D_L30_001DD660;
__asm__(".extern D_L30_001DD660, 4");
extern f32 D_L30_001DD65C;
__asm__(".extern D_L30_001DD65C, 4");
extern f32 D_L30_001DD648;
__asm__(".extern D_L30_001DD648, 4");
extern f32 D_L30_001DD644;
__asm__(".extern D_L30_001DD644, 4");
extern f32 D_L30_001DD628;
__asm__(".extern D_L30_001DD628, 4");
extern f32 D_L30_001DD62C;
__asm__(".extern D_L30_001DD62C, 4");
extern f32 D_L30_001DD640;
__asm__(".extern D_L30_001DD640, 4");
extern s32 D_L30_001DD63C;
__asm__(".extern D_L30_001DD63C, 4");
extern s32 D_L30_001DD620;
__asm__(".extern D_L30_001DD620, 4");
extern s32 D_L30_001DD624;
__asm__(".extern D_L30_001DD624, 4");
extern s32 D_L30_001DD658;
__asm__(".extern D_L30_001DD658, 4");
extern s32 D_L30_001DD654;
__asm__(".extern D_L30_001DD654, 4");
extern s32 D_L30_001DF2C0;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_L30_0034DBA0(s32, s32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

void func_L30_0034F5D8(u8 *out, u8 *in) {
    u8 *obj;
    f32 ang;
    f32 r;
    f32 alpha;
    f32 frac;
    s32 age;

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
    if (*(u32 *)(in + 4) == 0) {
        return;
    }
    if (*(u16 *)(in + 0xA) & 1) {
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        r = func_003824E0(0.0f, D_L30_001DD630);
        *(f32 *)(out + 0x10) = func_0038D098(ang) * r;
        *(f32 *)(out + 0x14) = 0.0f;
        *(f32 *)(out + 0x18) = func_0038D0B0(ang) * r;
        *(f32 *)(out + 0x10) += *(f32 *)(obj + 0x10);
        *(f32 *)(out + 0x14) += *(f32 *)(obj + 0x14);
        *(f32 *)(out + 0x18) += *(f32 *)(obj + 0x18);
        r = func_003824E0(D_L30_001DD660, D_L30_001DD65C);
        ang = func_003824E0(0.0f, 6.2831855f);
        *(f32 *)(in + 0x10) = r * func_0038D098(ang);
        *(f32 *)(in + 0x1C) = 0.0f;
        *(f32 *)(in + 0x14) = r * func_0038D0B0(ang);
        *(s32 *)(out + 4) = func_L30_0034DBA0(D_L30_001DD620, D_L30_001DD624);
        *(f32 *)(out + 0xC) = func_003824E0(D_L30_001DD648, D_L30_001DD644);
    }
    func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(out + 0xA), (f32)*(s16 *)(in + 8), 1.0f);
    *(f32 *)(out + 0x10) += *(f32 *)(in + 0x10);
    *(f32 *)(in + 0x14) += D_L30_001DD628;
    *(f32 *)(out + 0x18) += *(f32 *)(in + 0x14);
    if (*(f32 *)(in + 0x1C) <= 0.0f) {
        if ((D_L30_001DF2C0 & D_L30_001DD63C) == (((s32)out >> 8) & D_L30_001DD63C)) {
            if (func_L01_003FB640(out + 0x10, 0, obj, D_L30_001DD640) != 0) {
                *(f32 *)(in + 0x10) = *(f32 *)(in + 0x10) * D_L30_001DD62C;
                *(f32 *)(in + 0x1C) = 1.0f;
                *(f32 *)(in + 0x14) = *(f32 *)(in + 0x14) * D_L30_001DD62C;
            }
        }
    }
    if (0.0f < *(f32 *)(in + 0x1C)) {
        alpha = (f32)(*(u32 *)(out + 4) >> 24);
        age = *(s16 *)(out + 0xA);
        alpha = alpha * ((f32)age / (f32)(age + 1));
        frac = alpha - (f32)(s32)alpha;
        if (frac < func_003824E0(0.0f, 1.0f)) {
            *(s32 *)(out + 4) = (*(s32 *)(out + 4) & 0xFFFFFF) + ((s32)alpha << 24);
        } else {
            *(s32 *)(out + 4) = (*(s32 *)(out + 4) & 0xFFFFFF) + (((s32)alpha + 1) << 24);
        }
    } else {
        *(s32 *)(out + 4) = (*(s32 *)(out + 4) & 0xFFFFFF) + (func_00382498(D_L30_001DD658, D_L30_001DD654) << 24);
    }
    if (*(f32 *)(in + 0x1C) <= 0.0f) {
        out[8] = func_00382498(0, 0xFF);
        if (*(f32 *)(in + 0x1C) <= 0.0f) {
            age = *(s16 *)(out + 0xA);
            *(f32 *)(out + 0xC) = *(f32 *)(out + 0xC) * ((f32)age / (f32)(age + 1));
        }
    }
}
