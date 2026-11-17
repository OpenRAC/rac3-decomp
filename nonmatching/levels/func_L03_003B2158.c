/* NTSC-U draft (Claude wave K): C of func_L03_003B06A0, the NTSC-U twin of func_L03_003B2158, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 46 words differ on NTSC-U with "-mvu0-use-vf0-vf2 @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L03_003B06A0", whose code is not the PAL one).
 * Worker's note: 46 aligned diff (188 vs 187 words) from twin func_L03_003B6B20; remaining: float reg split (k1 f22 vs f21, yaw f21 vs f20), vf2/vf1 load order in the t+0x100-s+0x10 arm (ba there breaks tail merge)
 */
#include "common.h"

/* NTSC-U counterpart of func_L03_003B2158 (src/levels/shared/L03_003B1E38.c) */
#include "vu0.h"

/* localdecomp:start func_L03_003B06A0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern u8 D_001A4CC0[];
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388770(void *);
extern s32 func_00388398(s32 *);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L03_003B06A0(u8 *s) {
    u8 *t = *(u8 **)(s + 0x68);
    f32 k1 = 0.02f;
    f32 tgt[4];
    f32 pos[4];
    f32 dir[4];
    u8 *h;
    f32 ang;
    f32 yaw;
    f32 pitch;
    if (s[0x42] == 2) {
        pitch = 0.0f;
        yaw = 0.0f;
    } else {
        if (*(s32 *)(t + 0x128) != 0) {
            vec_sub_ab(dir, t + 0x100, s + 0x10);
        } else {
            if (func_00388800(s + 0x10, D_001A4C60) < 8.0f) {
                h = D_001A4C60 - 0x80;
                ang = func_00388A28(*(f32 *)(h + 0xE0) - *(f32 *)(s + 0x10), *(f32 *)(h + 0xE4) - *(f32 *)(s + 0x14));
                if (func_00389468(*(f32 *)(s + 0xF8), ang) < 1.5707964f) {
                    if (func_00388770(D_001A4C60 + 0x90) > 0.01f) {
                        *(s32 *)(t + 0x114) = 120;
                    } else {
                        func_00388398((s32 *)(t + 0x114));
                    }
                    goto timer;
                }
            }
            if (*(s32 *)(t + 0x114) != 0) {
                *(s32 *)(t + 0x114) = 0;
                *(u128_t *)(t + 0x100) = *(u128_t *)D_001A4CC0;
            }
        timer:
            if (func_00388398((s32 *)(t + 0x118))) {
                vec_add_ab(t + 0x100, s + 0x10, s + 0xC0);
            }
            if (*(s32 *)(t + 0x114) != 0) {
                k1 = 0.04f;
                *(u128_t *)tgt = *(u128_t *)D_001A4CC0;
            } else {
                *(u128_t *)tgt = *(u128_t *)(t + 0x100);
            }
            *(u128_t *)pos = *(u128_t *)(s + 0x10);
            pos[2] += 2.0f;
            vec_sub_ab(dir, tgt, pos);
        }
        yaw = func_003893C8(func_00388A28(dir[0], dir[1]), *(f32 *)(s + 0xF8));
        pitch = -func_00388A28(func_003887A0(dir), dir[2]);
    }
    if (yaw > 1.5707964f) yaw = 1.5707964f;
    else if (yaw < -1.5707964f) yaw = -1.5707964f;
    if (pitch > 0.5235988f) pitch = 0.5235988f;
    else if (pitch < -0.5235988f) pitch = -0.5235988f;
    *(f32 *)(t + 0x64) = pitch;
    *(f32 *)(t + 0x68) = yaw * 0.8f;
    *(f32 *)(t + 0xE8) = yaw * 0.2f;
    func_L01_0044B5C8(s, t, 0, k1, 0.3f);
    func_L01_0044B5C8(s, t + 0x80, 1, k1, 0.3f);
}
/* localdecomp:end func_L03_003B06A0 */
