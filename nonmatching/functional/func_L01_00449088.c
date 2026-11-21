/* functional: high. 315 words differ at level_01 but only because SN cc1 pools the float constants (lwc1 from a literal pool) where retail materialises them with lui/ori/mtc1, plus loop-form branches; the 28 calls are identical in order and arguments, frame size matches (0x140). Rewritten from the PAL assembly: the NTSC-U draft differs (PAL adds the (rand*5+2)/6 scaling and uses 189000/420000/0.0004 constants). func_003C2B88 = reads scratchpad hit list count, func_00382580/98/E0/68 = random helpers. Reads scratchpad 0x70000000 entries (0x20 bytes: pos+radius, end+flag). */
#include "vu0.h"
extern s32 func_003C2B88(void *, s32);
extern void *func_00382348(void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern u8 D_L01_001D66B0[];
extern u8 *D_L01_00221098[];

void func_L01_00449088(u8 *obj, s32 unused, s32 mode) {
    vu0_v4 a, b, c, points[8];
    vu0_v4 *scratch;
    s32 n, i, j, r1, r2, boost;
    f32 w, h, f, d;
    u8 *particle;
    u8 *state;

    n = func_003C2B88(obj, 0);
    if (n != 0) {
        scratch = (vu0_v4 *)0x70000000;
        for (; n > 0; n--, scratch += 2) {
            if (scratch[1].w == 0.0f) {
                *(vu0_q *)&a = *(vu0_q *)&scratch[0];
                a.w = 1.0f;
                func_00382580(&b, 0.0f, scratch[0].w);
                vec_add_ab(&a, &a, &b);
                r1 = (func_00382498(10, 20) * 5 + 2) / 6;
                r2 = func_00382498(-10, 10);
                w = scratch[0].w * 189000.0f;
                h = scratch[0].w * 420000.0f;
                f = func_003824E0(-4.0f, -10.0f) * 0.0004000000189989805f;
                particle = func_L01_0046FB40(&a, D_L01_001D66B0, r1, 0x808080, r2, 0x40, 0, w, h, 0, f);
            } else {
                *(vu0_q *)&a = *(vu0_q *)&scratch[0];
                *(vu0_q *)&b = *(vu0_q *)&scratch[1];
                a.w = 1.0f;
                b.w = 1.0f;
                f = func_003824E0(0.0f, 1.0f);
                func_0038CDF8(&c, &a, &b, f);
                c.x += func_003824E0(-scratch[0].w * 0.4f, scratch[0].w * 0.4f);
                c.y += func_003824E0(-scratch[0].w * 0.4f, scratch[0].w * 0.4f);
                c.z += func_003824E0(-scratch[0].w * 0.4f, scratch[0].w * 0.4f);
                r1 = (func_00382498(10, 20) * 5 + 2) / 6;
                r2 = func_00382498(-10, 10);
                w = scratch[0].w * 189000.0f;
                h = scratch[0].w * 420000.0f;
                f = func_003824E0(-4.0f, -10.0f) * 0.0004000000189989805f;
                particle = func_L01_0046FB40(&c, D_L01_001D66B0, r1, 0x808080, r2, 0x40, 0, w, h, 0, f);
            }
            if (particle != 0) {
                if (func_00382468(3) != 0) {
                    particle[2] = D_L01_00221098[0x16C / 4][4];
                    particle[3] = func_00382468(4) != 0 ? 0x44 : 0x48;
                } else {
                    particle[2] = D_L01_00221098[0x16C / 4][0];
                    particle[3] = 0x48;
                }
            }
        }
    } else {
        state = func_00382348(obj);
        if (state != 0 && 5.0f < *(f32 *)(state + 0x10)) {
            return;
        }
        n = func_L01_00447938(obj, 8, points, mode, 6.0f);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            vec_sub_ba(&a, &points[i], obj + 0x10);
            func_0038CEA8(&a);
            func_0038CE20(&a, &a, 0.8f);
            vec_add_ba(&points[i], &a, obj + 0x10);
            func_0038CF68((f32 *)&b, (f32 *)&a, 1.0f);
            d = func_0038CE68(&b, obj + 0xE0);
            boost = (s32)(d * d * d * d * d * d * 20.0f);
            j = 0;
            do {
                r1 = ((func_00382498(10, 20) + boost) * 5 + 2) / 6;
                r2 = func_00382498(-10, 10);
                f = func_003824E0(-4.0f, -10.0f) * 0.0004000000189989805f;
                particle = func_L01_0046FB40(&points[i], D_L01_001D66B0, r1, 0x808080, r2, 0x40, 0, 63000.00390625f, 210000.0f, 0, f);
                if (particle != 0) {
                    if (func_00382468(3) != 0) {
                        particle[2] = D_L01_00221098[0x16C / 4][4];
                        particle[3] = func_00382468(4) != 0 ? 0x44 : 0x48;
                    } else {
                        particle[2] = D_L01_00221098[0x16C / 4][0];
                        particle[3] = 0x48;
                    }
                }
            } while (--j >= 0);
        }
    }
}
