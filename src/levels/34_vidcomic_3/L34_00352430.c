#include "common.h"

/* declared by functions of L34_003515A0.c, which this file was cut from */
extern f32 func_0038DBA0(f32, f32);
extern s32 func_00382498(s32, s32);
typedef struct {
    u8 pad0[0x10];
    u8 *f10;
    u8 pad14[0x16C - 0x14];
    u8 *f16C;
} T_00352090;
extern T_00352090 D_L34_0021F218;
extern s32 func_00382468(s32);

/* localdecomp:start func_L34_00352430 */
#include "vu0.h"
extern void func_L34_00352090(u8 *, void *);
extern s32 func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_00464EC8(void *, void *, s32, f32);
extern f32 D_L34_001DD788;
__asm__(".extern D_L34_001DD788, 4");
extern f32 D_L34_001DD750;
__asm__(".extern D_L34_001DD750, 4");
extern f32 D_L34_001DD754;
__asm__(".extern D_L34_001DD754, 4");

void func_L34_00352430(u8 *obj, f32 p1, f32 p2) {
    u8 *st;
    u8 *fx;
    s32 i;
    f32 sign, big, mag;
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
    qzero(pos);
    vec_add_ba(pos, pos, obj + 0x10);
    pos[0] = pos[0] - sign * 0.2f;
    func_L34_00352090(obj, pos);
    *(f32 *)(st + 0x24) += D_L34_001DD788;
    while (1.0f <= *(f32 *)(st + 0x24)) {
        big = p1 * 17.0f;
        mag = (((D_L34_001DD750 - D_L34_001DD754) * (big / 17.0f) + D_L34_001DD754) * 0.020000001f) * p1;
        *(f32 *)(st + 0x24) -= 1.0f;
        *(vu0_q *)jit = 0;
        jit[2] = big * 0.020000001f * sign;
        func_L01_00443B88(vel, 0.0f, mag);
        vec_add_ab(vel, vel, jit);
        fx = func_L01_00464EC8(pos, vel, func_00382498(0, 1) & 0xFF, big);
        if (fx != 0) {
            if (func_00382468(3) == 0) {
                fx[2] = D_L34_0021F218.f16C[4];
                fx[3] = (func_00382468(2) != 0) ? 0x44 : 0x48;
            }
        }
    }
}
/* localdecomp:end func_L34_00352430 */
