#include "common.h"
#include "vu0.h"

/*
 * PAL reconstruction; first stock check.py compile: 324 positional differences
 * against 1644 retail bytes. Owning flags:
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stop signal: the default-state path can reach the final movement call with
 * incoming $f21/$f22. Do not reproduce that with uninitialized C locals.
 * This draft explicitly initializes speed/rate to zero for safety; that is
 * an inference for invalid/default states, not a claim of retail equivalence.
 * Other differences include prologue scheduling, abs.s/global-load order,
 * modulus/float temporaries and vector load order. Existing VU0 helpers only.
 * No source marker replaced. Full PAL/US build verification remains pending.
 */
extern f32 D_L36_001DEA4C;
__asm__(".extern D_L36_001DEA4C, 4");
extern f32 D_L36_001DEA50;
__asm__(".extern D_L36_001DEA50, 4");
extern s32 D_L36_001DEA54;
__asm__(".extern D_L36_001DEA54, 4");
extern f32 D_L36_001DEA58;
__asm__(".extern D_L36_001DEA58, 4");
extern f32 D_L36_001DEA5C;
__asm__(".extern D_L36_001DEA5C, 4");
extern f32 D_L36_001DEA60;
__asm__(".extern D_L36_001DEA60, 4");
extern f32 D_L36_001DEA64;
__asm__(".extern D_L36_001DEA64, 4");
extern s32 D_L36_001DEA68;
__asm__(".extern D_L36_001DEA68, 4");
extern s32 D_L36_001DEA6C;
__asm__(".extern D_L36_001DEA6C, 4");
extern f32 D_L36_001DEA70;
__asm__(".extern D_L36_001DEA70, 4");
extern s32 D_L36_001DEA74;
__asm__(".extern D_L36_001DEA74, 4");
extern f32 D_L36_001DEA78;
__asm__(".extern D_L36_001DEA78, 4");
extern f32 D_L36_001DEA7C;
__asm__(".extern D_L36_001DEA7C, 4");
extern f32 D_L36_001DEA80;
__asm__(".extern D_L36_001DEA80, 4");
extern f32 D_L36_001DEA84;
__asm__(".extern D_L36_001DEA84, 4");
extern s32 D_L36_001DEA88;
__asm__(".extern D_L36_001DEA88, 4");
extern f32 D_L36_001DEA8C;
__asm__(".extern D_L36_001DEA8C, 4");
extern f32 D_L36_001DEA90;
__asm__(".extern D_L36_001DEA90, 4");
extern f32 D_L36_001DEA94;
__asm__(".extern D_L36_001DEA94, 4");
extern s32 D_L36_001DEA9C;
__asm__(".extern D_L36_001DEA9C, 4");
extern s32 D_L36_001DEAA0;
__asm__(".extern D_L36_001DEAA0, 4");
extern s32 D_L36_001DEAA4;
__asm__(".extern D_L36_001DEAA4, 4");
extern f32 D_L36_001DEAA8;
__asm__(".extern D_L36_001DEAA8, 4");
extern f32 D_L36_001DEAAC;
__asm__(".extern D_L36_001DEAAC, 4");
extern f32 D_L36_001DEAB0;
__asm__(".extern D_L36_001DEAB0, 4");
extern u8 D_001A4C60[];
extern u8 D_L36_001E9560[];
extern s32 D_L36_001DF6C0;
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_00456250(u8 *);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L05_00441508(f32, f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern void func_L36_003A85A8(u8 *);

void func_L36_003A7F38(u8 *obj) {
    vu0_v4 p0, p1, temp, delta;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 angle, diff, ratio;
    f32 speed = 0.0f;
    f32 rate = 0.0f;
    s32 hit;
    func_003C2F58(obj, 0, &p0);
    func_003C2F58(obj, 1, &p1);
    switch (obj[0x20]) {
    case 1:
        if (func_L01_004561B8(obj)) *(s32 *)(s + 0x7C) = D_L36_001DEA9C;
        vec_sub_ba(&temp, D_001A4C60, obj + 0x10);
        func_0038CF68(&temp, &temp, 1.0f);
        angle = func_0038D160(temp.x, -temp.z);
        diff = __builtin_fabsf(func_0038DB00(angle, *(f32 *)(s + 0x70)));
        if (diff < D_L36_001DEA4C) *(f32 *)(s + 0x70) = angle;
        else *(f32 *)(s + 0x70) = func_L05_00441508(*(f32 *)(s + 0x70), angle, D_L36_001DEA4C / diff);
        *(f32 *)(s + 0x74) = D_L36_001DEA80;
        speed = func_003C4088(D_L36_001DEA50, D_L36_001DEA50, func_0038D098(func_0038DB48((f32)(D_L36_001DF6C0 % D_L36_001DEA54) / (f32)D_L36_001DEA54)) * 0.5f + 0.5f);
        rate = D_L36_001DEAA8;
        if (func_0038CAD0(s + 0x7C)) func_L01_004450F0(obj, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(obj)) {
            func_003A52A0(1, 0, obj);
            *(s32 *)(s + 0x7C) = 0;
            vec_sub_ab(&temp, D_001A4C60, obj + 0x10);
            ratio = func_0038CEA8(&temp);
            func_0038CF68(&temp, &temp, ratio + D_L36_001DEA64);
            vec_add_ab(s + 0x60, &temp, obj + 0x10);
        }
        *(f32 *)(s + 0x74) = D_L36_001DEA80;
        speed = D_L36_001DEA58;
        rate = D_L36_001DEAAC;
        if (func_003D3CB0(&p0, &p1, 2, obj, 0)) {
            if (*(s32 *)(s + 0x7C) == 0) {
                *(s32 *)(s + 0x7C) = 1;
                func_003A52A0(2, 0, obj);
            }
            ratio = func_0038CF00(D_L36_001E9560, &p1);
            ratio = ratio / func_0038CF00(&p0, &p1);
            if (D_L36_001DEA60 < ratio) {
                qzero(s + 0x50);
                func_L01_004450F0(obj, 3, -1);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(obj)) {
            *(s32 *)(s + 0x7C) = D_L36_001DEAA0;
            if (--*(s32 *)(s + 0x78) <= 0) func_L01_004450F0(obj, 4, -1);
        }
        rate = 0.0f;
        speed = rate;
        if (*(s32 *)(s + 0x7C) % D_L36_001DEA6C < D_L36_001DEA74) {
            *(f32 *)(s + 0x74) += D_L36_001DEA70;
            if (D_L36_001DEA78 < *(f32 *)(s + 0x74)) {
                *(f32 *)(s + 0x74) += D_L36_001DEA7C - D_L36_001DEA78;
            }
        } else *(f32 *)(s + 0x74) = D_L36_001DEA80;
        if (func_0038CAD0(s + 0x7C)) func_L01_004450F0(obj, 5, -1);
        break;
    case 0x42:
        func_L01_004561B8(obj);
        if (func_L01_00456250(obj)) {
            func_L01_00456230(obj, 0);
            func_L01_004450F0(obj, 5, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(obj)) *(s32 *)(s + 0x7C) = D_L36_001DEAA4;
        rate = 0.0f;
        speed = rate;
        if (func_0038CAD0(s + 0x7C)) func_L01_004450F0(obj, 0x42, -1);
        break;
    case 0:
        qzero(s + 0x50);
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(obj, 1);
        func_L01_004450F0(obj, 0x42, -1);
        break;
    case 5:
        if (func_L01_004561B8(obj)) {
            *(s32 *)(s + 0x7C) = 0;
            func_003A52A0(1, 0, obj);
            *(u16 *)(obj + 0x96) = 0;
        }
        speed = D_L36_001DEA5C;
        rate = D_L36_001DEAB0;
        func_0038CAD0(s + 0x90);
        hit = func_003D3CB0(&p0, &p1, 2, obj, 0);
        if (hit != 0 || *(s32 *)(s + 0x90) != 0) {
            vec_sub_ab(&delta, &p0, &p1);
            vec_add_ab(s + 0x60, &p0, &delta);
            ratio = func_0038CE68(&delta, s + 0x50);
            ratio = ratio / func_0038CE68(&delta, &delta);
            func_0038CE20(s + 0x50, &delta, ratio);
            *(s32 *)(s + 0x7C) = 0;
            if (hit) *(s32 *)(s + 0x90) = D_L36_001DEA68;
            *(f32 *)(s + 0x74) = D_L36_001DEA80;
        } else {
            if (*(s32 *)(s + 0x7C) == 0) {
                *(f32 *)(s + 0x60) = func_003824E0(*(f32 *)(s + 0x80), *(f32 *)(s + 0x84));
                *(f32 *)(s + 0x68) = *(f32 *)(s + 0x88);
                *(f32 *)(s + 0x64) = ((f32 *)D_001A4C60)[1];
                *(s32 *)(s + 0x7C) = 1;
            }
            if (func_0038D098(*(f32 *)(s + 0x70)) < 0.0f &&
                0.0f < func_0038D098(func_0038DB48(*(f32 *)(s + 0x70) + D_L36_001DEA94)) &&
                !(obj[0x34] & 1)) {
                func_003A52A0(0, 0, obj);
            }
            if (func_0038CF00(obj + 0x10, s + 0x60) < D_L36_001DEA90 || D_L36_001DEA88 < *(u16 *)(obj + 0x96)) {
                func_L01_004450F0(obj, 1, -1);
            }
            *(f32 *)(s + 0x70) = func_0038DB48(*(f32 *)(s + 0x70) + D_L36_001DEA94);
            *(f32 *)(s + 0x74) = D_L36_001DEA80;
        }
        *(u16 *)(obj + 0x96) += 1;
        break;
    }
    if (obj[0x20] != 0x42 && obj[0x20] != 4 &&
        (obj[0x94] != 0x42 || *(u16 *)(obj + 0x96) >= 2)) {
        vec_sub_ab(&temp, s + 0x60, obj + 0x10);
        func_0038CF68(&temp, &temp, speed);
        vec_add_ab(s + 0x60, &temp, s + 0x50);
        func_L31_003478E8(obj, obj + 0x10, s + 0x50, 0.0f, D_L36_001DEA84, rate, rate, rate, D_L36_001DEA8C, 0.0f, 0);
    }
    func_L36_003A85A8(obj);
}
