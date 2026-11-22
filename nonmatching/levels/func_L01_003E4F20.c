/* PAL near miss (sol-round3-c): 261 words differ with the file's flags; the camera axis and hero pointer lifetimes, switch control flow and VU0 scheduling differ. Based on the functional draft. */
#include "vu0.h"
extern s32 D_L01_001DF658, D_L01_001DF660;
__asm__(".extern D_L01_001DF658, 4");
__asm__(".extern D_L01_001DF660, 4");
static __inline__ void sub_3E4F20(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
extern s32 D_L01_001D673C;
extern Entry_3E6C58 D_L01_001E2A40[];
/* camera vertical follow step: per-frame update of the follow point's vertical motion
   (cam->follow + 0x60, mode byte +0xE4) from the hero's state; writes the follow point to *out */
void func_L01_003E4F20(u8 *cam, u128_t *out) {
    extern s32 func_L01_003E4198(u8 *, void *, s32);
    extern void func_L01_003E4028(u8 *, u128_t *);
    extern f32 func_L01_003E4428(u8 *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    vu0_v4 target, scratch;
    u8 *entry = (u8 *)&D_L01_001E2A40[*(s32 *)(cam + 0x94)];
    u8 *v = *(u8 **)(cam + 0x70) + 0x60;
    u8 *hero = entry + 0x150;
    u8 *motion = entry + 0x60;
    u8 *axis;
    s32 mode, flag, lim, n;
    f32 dot, a, b;

    if (func_0038CE68(entry + 0x80, entry + 0x90) < 0.99900001f || D_L01_001D673C != 0) {
        v[0x10E] = 1;
        if (D_L01_001D673C != 0) {
            v[0x10F] = (D_L01_001DF660 * 5 + 2) / 6;
        } else if ((s8)v[0x10F] <= 0) {
            v[0x10F] = (D_L01_001DF658 * 5 + 2) / 6;
        } else {
            n = v[0x10F] + 2;
            v[0x10F] = n;
            lim = (D_L01_001DF658 * 5 + 2) / 6;
            if (lim < (s8)n) v[0x10F] = lim;
        }
    }
    axis = motion + 0x30;
    if (*(s16 *)(hero + 0x124) != 0 || D_L01_001D673C != 0 ||
        (v[0x10E] != 0 && *(s16 *)(hero + 0x122) != 0)) {
        dot = func_0038CE68(v, axis);
        func_0038CE20(v + 0x10, axis, dot);
        *(u128_t *)(v + 0x20) = *(u128_t *)(v + 0x10);
        *out = *(u128_t *)(v + 0x10);
        mode = v[0xE4];
        if ((u32)(mode - 5) < 3 || mode == 3)
            func_L01_003E4828((Entry_3E6C58 *)entry, (void *)(v + 0x30), 1.5f, 1);
    }
    func_L01_003E4028(cam, (u128_t *)&target);

    if (*(s32 *)(hero + 0x100) == 0x79) {
        dot = func_0038CE68(v, axis);
        func_0038CE20(out, axis, dot);
        sub_3E4F20(v, v, out);
        dot = func_0038CE68(axis, v + 0x60);
        func_0038CE20(out, axis, dot);
        *(u128_t *)(v + 0x10) = *out;
        if (v[0xE4] != 0xB) {
            u8 *follow;
            v[0xE4] = 0xB;
            *(u128_t *)(cam + 0x40) = *(u128_t *)cam;
            follow = *(u8 **)(cam + 0x70);
            *(f32 *)(follow + 0x44) = 0.013333334f;
            *(s16 *)(follow + 0x20) = 0x4B;
        }
        return;
    }
    switch (v[0xE4]) {
    case 2:
        flag = 0;
        if (*(s32 *)(hero + 0x100) == 17) {
            flag = 1;
        } else if (hero[0x12A] != 0 && 0.2f < *(f32 *)(hero + 0x114)) {
            a = func_L01_003E4428(cam, *(f32 *)(v + 0xD0));
            if (a < -0.01f || 1.57079637f < a) flag = 1;
        }
        if (flag) {
            v[0xE4] = 1;
            *(s16 *)(v + 0xE6) = 10;
            *(f32 *)(v + 0xE8) = 0.1f;
        }
        flag = 0;
        if (*(s16 *)(hero + 0x120) != 0 && (hero[0x12A] == 0 || *(s16 *)(hero + 0x128) >= 16)) {
            flag = 1;
        } else {
            if (func_L01_003E4198(entry, &scratch, 1) != 1) {
                flag = 1;
            } else {
                a = func_0038CE68(&scratch, axis);
                b = func_0038CEA8(v + 0x10);
                if (a < b) flag = 1;
            }
        }
        if (flag) {
            *out = *(u128_t *)(v + 0x10);
            dot = func_0038CE68(&target, axis);
            func_0038CE20(&scratch, axis, dot);
            sub_3E4F20(v, &target, &scratch);
        } else {
            func_L01_003E4198(entry, &scratch, 1);
            dot = func_0038CE68(&scratch, axis);
            func_0038CE20(out, axis, dot);
            sub_3E4F20(v, &scratch, out);
        }
        break;
    case 3: case 5: case 6: case 7:
        func_0038CDF8(v + 0x10, v + 0x30, v + 0x20, (f32)*(s16 *)(v + 0xF4) * *(f32 *)(v + 0xEC));
        if (v[0xF7] == 0) {
            if (func_L01_003FB640(cam + 0x30, 18, 0, 0.2f)) {
                v[0xF7] = 1;
                *(u128_t *)(v + 0x30) = *(u128_t *)(v + 0x10);
            }
        }
        *out = *(u128_t *)(v + 0x10);
        dot = func_0038CE68(&target, axis);
        func_0038CE20(&scratch, axis, dot);
        sub_3E4F20(v, &target, &scratch);
        if (func_0038CB00(v + 0xF4)) {
            mode = v[0xE4];
            if (mode == 9) {
                u128_t q = *(u128_t *)(v + 0x10);
                *(s16 *)(v + 0xF4) = 0x19;
                v[0xE4] = 10;
                *(u128_t *)(v + 0x20) = q;
                func_0038CE20(&scratch, axis, *(f32 *)(v + 0xF0));
                sub_3E4F20(v + 0x30, v + 0x20, &scratch);
            } else if (mode == 6) {
                u128_t old20 = *(u128_t *)(v + 0x20);
                u128_t cur10 = *(u128_t *)(v + 0x10);
                v[0xE4] = 7;
                *(u128_t *)(v + 0x20) = cur10;
                *(s16 *)(v + 0xF4) = 0x1D;
                *(u128_t *)(v + 0x30) = old20;
            } else {
                v[0xE4] = 4;
                *(f32 *)(v + 0xE8) = 0.05f;
                *(s16 *)(v + 0xE6) = 20;
            }
        }
        break;
    case 8:
        *out = *(u128_t *)(v + 0x10);
        dot = func_0038CE68(&target, axis);
        func_0038CE20(&scratch, axis, dot);
        sub_3E4F20(v, &target, &scratch);
        break;
    case 9: case 10:
        dot = func_0038CE68(&target, axis);
        func_0038CE20(out, axis, dot);
        sub_3E4F20(v, &target, out);
        func_0038CDF8(out, out, v + 0x20, 0.5f);
        break;
    default:
        dot = func_0038CE68(&target, axis);
        func_0038CE20(out, axis, dot);
        sub_3E4F20(v, &target, out);
        break;
    }
}
