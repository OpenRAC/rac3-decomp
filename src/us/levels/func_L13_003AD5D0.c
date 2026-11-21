#include "common.h"

/* NTSC-U counterpart of func_L13_003AF3B8 (src/levels/shared/L13_003AF2F8.c): 60 Hz step (1/60.0f against 0.02f) */
/* localdecomp:start func_L13_003AD5D0 */
#include "vu0.h"

__asm__(".extern D_L13_001DE7F8, 4");
__asm__(".extern D_L13_001DE7F4, 4");
extern f32 D_L13_001DE7F8;
extern f32 D_L13_001DE7F4;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L13_003B2720(void *, void *, void *, s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);

void func_L13_003AD5D0(u8 *self) {
    vu0_v4 m[4];
    vu0_v4 d;
    vu0_v4 e;
    u8 *t;
    f32 pitch;
    f32 yaw;
    f32 base;
    f32 lim;
    s32 flags;

    t = *(u8 **)(self + 0x68);
    func_003BD9A0(self, 2, m);
    vec_sub_ba(&d, t + 0x130, &m[3]);
    base = func_00388A28(func_003887A0(&m[0]), m[0].z);
    pitch = func_003893C8(func_00388A28(func_003887A0(&d), d.z), base);
    lim = D_L13_001DE7F8 * 0.017453292f;
    if (lim < pitch) {
        pitch = lim;
    } else if (pitch < -lim) {
        pitch = -lim;
    }
    pitch = func_00389380(pitch, base);
    base = func_00388A28(m[0].x, m[0].y);
    yaw = func_003893C8(func_00388A28(d.x, d.y), base);
    lim = D_L13_001DE7F8 * 0.017453292f;
    if (lim < yaw) {
        yaw = lim;
    } else if (yaw < -lim) {
        yaw = -lim;
    }
    yaw = func_00389380(yaw, base);
    func_0037E4B8(&d, D_L13_001DE7F4 * 0.016666668f, yaw, pitch);
    flags = 0x08000001;
    if (t[0x5F]) {
        flags = 0x08010001;
    }
    func_00388830(&e, m, -1.0f);
    vec_add_ab(&e, &e, &m[3]);
    if (func_003CE740(&e, &m[3], 0x12, self, 0) == 0 || D_001D545C != 0x10) {
        func_L13_003B2720(self, &m[3], &d, t[0x44], flags);
    }
}
/* localdecomp:end func_L13_003AD5D0 */
