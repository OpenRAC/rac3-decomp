/* functional: high. Written from PAL asm, every block read against it. Needs file flag -mvu0-use-vf0-vf2; not byte-identical (same frame size). func_L01_00464EC8 (effect spawn) prototype is mine: (void*, void*, s32, f32) returns the new effect pointer. */
#include "common.h"
#include "vu0.h"

extern void func_L34_00352090(u8 *, void *);
extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_00464EC8(void *, void *, s32, f32);
extern f32 D_L34_001DD788;
extern f32 D_L34_001DD750;
extern f32 D_L34_001DD754;

void func_L34_00352430(u8 *obj, f32 p1, f32 p2) {
    u8 *st;
    u8 *fx;
    s32 i;
    f32 sign, big, scale, ratio, mag;
    f32 pos[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 jit[4] __attribute__((aligned(16)));

    st = *(u8 **)(obj + 0x68);
    sign = -1.0f;
    if (1.5707964f < func_0038DBA0(*(f32 *)(obj + 0xF4), 0.0f)) {
        sign = 1.0f;
    }
    if (obj[0x31] != 0) {
        for (i = 0; i < 5; i++) {
            *(vu0_q *)pos = *(vu0_q *)(obj + 0x10);
            pos[2] += (((f32)i * 1.5f) * p2 + 0.7f) * sign;
            func_L01_00446780(obj, pos, 0x30001, 0, 1, 0, (f32)i * 0.13f + 0.2f, 20.0f, 1.0f);
        }
    }
    if (!(0.0f < p1)) {
        return;
    }
    pos[0] = 0.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    pos[3] = 0.0f;
    vec_add_ba(pos, pos, obj + 0x10);
    pos[0] = pos[0] - sign * 0.2f;
    func_L34_00352090(obj, pos);
    *(f32 *)(st + 0x24) += D_L34_001DD788;
    if (1.0f <= *(f32 *)(st + 0x24)) {
        big = p1 * 17.0f;
        scale = big * 0.02f;
        ratio = big / 17.0f;
        sign = scale * sign;
        do {
            *(f32 *)(st + 0x24) -= 1.0f;
            jit[0] = 0.0f;
            jit[1] = 0.0f;
            jit[2] = 0.0f;
            jit[3] = 0.0f;
            jit[2] = sign;
            func_L01_00443B88(vel, 0.0f, (((D_L34_001DD750 - D_L34_001DD754) * ratio + D_L34_001DD754) * 0.02f) * p1);
            vec_add_ba(vel, jit, vel);
            fx = func_L01_00464EC8(pos, vel, func_00382498(0, 1) & 0xFF, big);
            if (fx != 0) {
                if (func_00382468(3) == 0) {
                    fx[2] = D_L34_0021F218.f16C[4];
                    fx[3] = (func_00382468(2) == 0) ? 0x48 : 0x44;
                }
            }
        } while (1.0f <= *(f32 *)(st + 0x24));
    }
}
