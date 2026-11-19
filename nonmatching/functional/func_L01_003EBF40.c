/* functional: high. Initialises a mover object's data block (limits, speeds, pose copy from the player's target at e+0x54, heading from either the stored angle or the vector to the target), marks the player slot active; stores/calls in retail order */
#include "vu0.h"
extern u8 D_L01_001E2A40[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
void func_L01_003EBF40(u8 *a0) {
    u8 *e = D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460;
    u8 *e150 = e + 0x150;
    u8 *data = *(u8 **)(a0 + 0x70);
    u8 *s = data + 0x40;
    u8 *p, *d18, *s20;
    u8 *tgt;

    *(f32 *)(s + 0x4C) = 1.5f;
    *(f32 *)(s + 0x48) = 0.20943951f;
    *(f32 *)(s + 0x58) = 0.0017453292f;
    *(f32 *)(s + 0x5C) = -0.0043633231f;
    *(s32 *)(s + 0x40) = 0;
    *(s32 *)(s + 0x44) = *(s32 *)(e150 + 0xF0);
    p = *(u8 **)(a0 + 0x70);
    *(f32 *)(p + 0xA0) = 4.64f;
    p += 0xA0;
    *(f32 *)(p + 0x14) = 0.05f;
    *(f32 *)(p + 4) = 0.5f;
    *(f32 *)(p + 0x10) = 2.0f;
    p = *(u8 **)(a0 + 0x70);
    qzero(p);
    *(f32 *)(p + 0x10) = 0.01f;
    *(f32 *)(p + 0x14) = 0.3f;
    *(s16 *)(p + 0x1E) = 100;
    *(s32 *)(p + 0x18) = 0;
    *(s16 *)(p + 0x1C) = 0;
    p = *(u8 **)(a0 + 0x70);
    *(f32 *)(p + 0x30 + 4) = 0.02f;
    *(f32 *)(p + 0x30 + 8) = 0.2f;
    *(s32 *)(p + 0x30 + 0xC) = 0;
    *(s32 *)(p + 0x30) = 0;
    d18 = *(u8 **)(a0 + 0x70);
    s20 = d18 + 0xB8;
    *(s32 *)(s20 + 4) = 0;
    tgt = *(u8 **)(e + 0x54);
    *(vu0_q *)(a0 + 0x30) = *(vu0_q *)(tgt + 0x30);
    tgt = *(u8 **)(e + 0x54);
    *(vu0_q *)(a0 + 0x00) = *(vu0_q *)(tgt + 0x00);
    tgt = *(u8 **)(e + 0x54);
    *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(tgt + 0x10);
    tgt = *(u8 **)(e + 0x54);
    *(vu0_q *)(a0 + 0x40) = *(vu0_q *)(tgt + 0x00);
    *(vu0_q *)(a0 + 0x20) = *(vu0_q *)(tgt + 0x20);
    *(s16 *)(a0 + 0x7E) = 0;
    if ((u32)(*(s32 *)(e150 + 0x100) - 0x2B) < 2) {
        *(f32 *)(d18 + 0xB8) = *(f32 *)(e150 + 0x13C);
        *(s32 *)(s20 + 8) = *(s32 *)(e150 + 0x138);
        *(f32 *)(s + 0x30) = func_0038D098(*(f32 *)(d18 + 0xB8));
        *(f32 *)(s + 0x34) = func_0038D0B0(*(f32 *)(d18 + 0xB8));
        *(s32 *)(s + 0x38) = 0;
    } else {
        tgt = *(u8 **)(e150 + 0x138);
        vec_sub_ba(data + 0x70, tgt + 0x10, a0 + 0x30);
        *(s32 *)(s + 0x38) = 0;
        *(s32 *)(s + 0x3C) = 0;
        func_0038CF68((f32 *)(data + 0x70), (f32 *)(data + 0x70), 1.0f);
        *(f32 *)(d18 + 0xB8) = func_0038D160(*(f32 *)(s + 0x30), *(f32 *)(s + 0x34));
        *(s32 *)(s20 + 8) = *(s32 *)(e150 + 0x138);
    }
    e[0x2A3] = 2;
    *(s16 *)(e + 0x2A0) = 1;
    *(s32 *)(D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460 + 0x324) = 0x32;
}
