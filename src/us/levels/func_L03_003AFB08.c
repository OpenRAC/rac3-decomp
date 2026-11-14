#include "common.h"

/* NTSC-U counterpart of func_L03_003B8770 (src/levels/03_starship_phoenix/L03_003B8570.c) */
typedef struct { float x,y,z,w; } V87c;
extern s32 func_00388398(s32 *);
extern f32 func_0037E250(f32, f32);
extern void func_L03_003AFB08(u8 *);

/* localdecomp:start func_L03_003AFB08 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388770(void *);
extern s32 func_00388398(s32 *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L03_003AFB08(u8 *s) {
    u8 *t = *(u8 **)(s + 0x68);
    f32 k1 = 0.02f;
    f32 k2 = 0.3f;
    f32 dir[4];
    f32 tgt[4];
    f32 pos[4];
    u8 *h;
    f32 ang;
    f32 pitch;
    f32 yaw;
    f32 dyaw;
    f32 dpitch;
    if (s[0x42] == 1) {
        pitch = 0.0f;
        yaw = pitch;
        goto clamp;
    } else if (*(s32 *)(t + 0x124)) {
        __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1" : : "m"(*(V87c *)(s+0x10)), "m"(*(V87c *)(t+0x100)) : "vf1","vf2");
    } else {
        if (func_00388800(s + 0x10, D_001A4BE0 + 0x80) < 8.0f) {
            h = D_001A4BE0;
            ang = func_00388A28(*(f32 *)(h + 0xE0) - *(f32 *)(s + 0x10), *(f32 *)(h + 0xE4) - *(f32 *)(s + 0x14));
            if (func_00389468(*(f32 *)(s + 0xF8), ang) < 1.5707964f) {
                if (func_00388770(D_001A4BE0 + 0x110) > 0.01f) {
                    *(s32 *)(t + 0x114) = 120;
                } else {
                    func_00388398((s32 *)(t + 0x114));
                }
                goto timer;
            }
        }
        if (*(s32 *)(t + 0x114) != 0) {
            *(s32 *)(t + 0x114) = 0;
            *(u128_t *)(t + 0x100) = *(u128_t *)(D_001A4BE0 + 0xE0);
        }
    timer:
        if (func_00388398((s32 *)(t + 0x118))) {
            *(s32 *)(t + 0x118) = (s32)func_0037E250(180.0f, 300.0f);
            dyaw = func_00389380(*(f32 *)(s + 0xF8), func_0037E250(-90.0f, 90.0f) * 0.017453292f);
            dpitch = func_0037E250(0.0f, 30.0f) * 0.017453292f;
            func_0037E4B8(t + 0x100, 6.0f, dyaw, dpitch);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V87c *)(t + 0x100)) : "m"(*(V87c *)( t + 0x100)), "m"(*(V87c *)( s + 0x10)) : "vf1","vf2");
        }
        if (*(s32 *)(t + 0x114) != 0) {
            k1 = 0.04f;
            *(u128_t *)tgt = *(u128_t *)(D_001A4BE0 + 0xE0);
        } else {
            *(u128_t *)tgt = *(u128_t *)(t + 0x100);
        }

        *(u128_t *)pos = *(u128_t *)(s + 0x10);
        pos[2] += 2.0f;
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1" : : "m"(*(V87c *)tgt), "m"(*(V87c *)pos) : "vf1","vf2");
    }
    __asm__("vsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(V87c *)dir) : : "vf1","vf2");
        yaw = func_003893C8(func_00388A28(dir[0], dir[1]), *(f32 *)(s + 0xF8));
        pitch = -func_00388A28(func_003887A0(dir), dir[2]);
clamp:
        if (yaw > 1.2217305f) yaw = 1.2217305f;
        else if (yaw < -1.2217305f) yaw = -1.2217305f;
        if (pitch > 0.5235988f) pitch = 0.5235988f;
        else if (pitch < -0.5235988f) pitch = -0.5235988f;
        *(f32 *)(t + 0x68) = yaw * 0.8f;
        *(f32 *)(t + 0xE8) = yaw * 0.2f;
        *(f32 *)(t + 0x64) = pitch;
    func_L01_0044B5C8(s, t, 0, k1, k2);
    func_L01_0044B5C8(s, t + 0x80, 1, k1, k2);
}
/* localdecomp:end func_L03_003AFB08 */
