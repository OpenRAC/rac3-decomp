#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B8570 */
typedef struct S_003B8570 {
    char p0[0x20]; u8 mode; char p1[0x10]; u8 f31; char p2[2]; u16 flags; char p3[0xD]; u8 f43;
    char p4[0x1C]; u8 f60; char p5[7]; struct T_003B8570 *t;
} S_003B8570;
typedef struct T_003B8570 { char p[0x11C]; s32 a; char b[1]; } T_003B8570;
extern s32 D_00142C5C[];
extern s32 D_L03_001D6694;
__asm__(".extern D_L03_001D6694, 16");
__asm__(".extern D_00142C5C, 16");
extern s32 D_001D6694_sda;
__asm__(".extern D_001D6694_sda, 4");
extern void func_003C3A10(S_003B8570 *, s32, s32, s32);
extern void func_L01_004450F0(S_003B8570 *, s32, s32);
extern void func_003C2880(S_003B8570 *);
extern s32 func_L01_004BA800();
extern s32 func_0038CAD0(s32 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L03_003B8770(u8 *);
extern void func_L01_00451DB8(f32, S_003B8570 *, char *, s32, s32);

void func_L03_003B8570(S_003B8570 *s) {
    T_003B8570 *t = s->t;
    s32 v;
    if (s->mode == 0) {
        if (D_00142C5C[0] & 0x40000000) {
            if (s->f43 != 1) func_003C3A10(s, 1, 0, 8);
            func_L01_004450F0(s, 1, -1);
            v = D_001D6694_sda;
        } else {
            func_003C2880(s);
            return;
        }
    } else {
        v = D_L03_001D6694;
    }
    if (v == 2) {
        s->f31 = 0;
        s->flags |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        s->f31 = 1;
        s->flags &= 0xFFFE;
    }
    switch (s->mode) {
    case 1:
        if (func_0038CAD0(&t->a)) {
            s32 k;
            t->a = (s32)((func_003824E0(600.0f, 1200.0f) * 5.0f + 2.0f) / 6.0f);
            k = func_00382468(3) ? 2 : 3;
            if (s->f43 != k) func_003C3A10(s, k, 0, 8);
            func_L01_004450F0(s, 2, -1);
        }
        break;
    case 2:
        if (s->f60 & 2) {
            if (s->f43 != 1) func_003C3A10(s, 1, 0, 8);
            func_L01_004450F0(s, 1, -1);
        }
        break;
    }
    func_L03_003B8770((u8 *)s);
    func_L01_00451DB8(0.06283186f, s, t->b, 0x80A0A0A0, 0x80404040);
}
/* localdecomp:end func_L03_003B8570 */

/* localdecomp:start func_L03_003B8770 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(s32 *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L03_003B8770(u8 *s) {
    u8 *t = *(u8 **)(s + 0x68);
    s32 aim = 0;
    f32 k1 = 0.02f;
    f32 k2 = 0.3f;
    f32 tgt[4];
    f32 pos[4];
    f32 dir[4];
    u8 *h;
    f32 ang;
    f32 yaw;
    f32 pitch;
    f32 dyaw;
    f32 dpitch;
    if (s[0x20] == 1) {
        aim = 1;
        if (func_0038CF38(s + 0x10, D_001A4BE0 + 0x80) < 8.0f) {
            h = D_001A4BE0;
            ang = func_0038D160(*(f32 *)(h + 0xE0) - *(f32 *)(s + 0x10), *(f32 *)(h + 0xE4) - *(f32 *)(s + 0x14));
            if (func_0038DBA0(*(f32 *)(s + 0xF8), ang) < 1.5707964f) {
                if (func_0038CEA8(D_001A4BE0 + 0x110) > 0.01f) {
                    *(s32 *)(t + 0x114) = 100;
                } else {
                    func_0038CAD0((s32 *)(t + 0x114));
                }
                goto timer;
            }
        }
        if (*(s32 *)(t + 0x114) != 0) {
            *(s32 *)(t + 0x114) = 0;
            *(u128_t *)(t + 0x100) = *(u128_t *)(D_001A4BE0 + 0xE0);
        }
    timer:
        if (func_0038CAD0((s32 *)(t + 0x118))) {
            *(s32 *)(t + 0x118) = (s32)((func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / 6.0f);
            dyaw = func_0038DAB8(*(f32 *)(s + 0xF8), func_003824E0(-90.0f, 90.0f) * 0.017453292f);
            dpitch = func_003824E0(0.0f, 30.0f) * 0.017453292f;
            func_00382760(t + 0x100, 6.0f, dyaw, dpitch);
            vec_add_ab(t + 0x100, t + 0x100, s + 0x10);
        }
        if (*(s32 *)(t + 0x114) != 0) {
            k1 = 0.04f;
            k2 = 0.3f;
            *(u128_t *)tgt = *(u128_t *)(D_001A4BE0 + 0xE0);
        } else {
            *(u128_t *)tgt = *(u128_t *)(t + 0x100);
        }
    }
    if (aim) {
        *(u128_t *)pos = *(u128_t *)(s + 0x10);
        pos[2] += 2.0f;
        vec_sub_ab(dir, tgt, pos);
        yaw = func_0038DB00(func_0038D160(dir[0], dir[1]), *(f32 *)(s + 0xF8));
        pitch = -func_0038D160(func_0038CED8(dir), dir[2]);
        if (yaw > 1.5707964f) yaw = 1.5707964f;
        else if (yaw < -1.5707964f) yaw = -1.5707964f;
        if (pitch > 0.5235988f) pitch = 0.5235988f;
        else if (pitch < -0.5235988f) pitch = -0.5235988f;
        *(f32 *)(t + 0x64) = pitch;
        *(f32 *)(t + 0x68) = yaw * 0.6f;
        *(f32 *)(t + 0xE8) = yaw * 0.4f;
    }
    func_L01_0044E850(s, t, 0, k1 * 1.44f, k2 * 1.44f);
    func_L01_0044E850(s, t + 0x80, 1, k1 * 1.44f, k2 * 1.44f);
}
/* localdecomp:end func_L03_003B8770 */
