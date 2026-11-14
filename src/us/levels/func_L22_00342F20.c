#include "common.h"

/* NTSC-U counterpart of func_L22_00343800 (src/levels/22_mylon/L22_00343800.c) */
#include "vu0.h"

/* localdecomp:start func_L22_00342F20 */
extern vu0_v4 D_L22_001E2A80_00342F20;
extern u8 D_L22_001D66B0_00342F20[8];
extern u8 *D_L22_0021FFAC_00342F20[];
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003BFC18(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_0037E1D8(s32);

void func_L22_00342F20(vu0_v4 *pos, s32 a1, s32 big) {
    vu0_v4 d;
    vu0_v4 vel;
    vu0_v4 at;
    vu0_v4 pt;
    f32 heading;
    f32 speed;
    f32 size;
    f32 tilt;
    f32 yaw;
    s32 n;
    s32 i;
    u8 *q;
    u8 *data;

    vec_sub_ab(&d, &D_L22_001E2A80_00342F20, pos);
    heading = func_00388A28(d.x, d.y);
    for (i = 0; i < 20; i++) {
        speed = func_0037E250(0.2f, 3.0f);
        func_003BFC18(pos, &at, 1);
        func_003886E8(&vel, &at, -(speed * 0.016666668f));
        n = func_L01_00440918(1.0f, 2.0f);
        size = func_0037E250(0.3f, 0.75f) * 210000.0f;
        pt.x = pos->x + func_L01_00440918(0.0f, 0.2f);
        pt.y = pos->y + func_L01_00440918(0.0f, 0.2f);
        pt.z = pos->z + func_L01_00440918(0.0f, 0.2f);
        q = func_L01_004633E8(&pt, 0.0f, 1.0f, 1.01f, size, n, &vel, 0x7F202020, 1);
        if (q != 0) {
            q[3] = 0x44;
            *(s16 *)(q + 0xA) = 0x5A;
            q[9] = 0x44;
            data = q + 0x20;
            *(f32 *)(data + 0x1C) = 5.0f;
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x30;
            data[0xB] = q[0xA];
        }
        speed = func_0037E250(1.0f, 2.0f);
        tilt = func_0037E250(0.0f, 1.3962634f);
        yaw = func_00389380(heading, func_L01_00440918(0.0f, 1.3962634f));
        func_0037E4B8(&vel, speed * 0.016666668f, yaw, tilt);
        pt.x = pos->x + func_L01_00440918(0.0f, 0.1f);
        pt.y = pos->y + func_L01_00440918(0.0f, 0.1f);
        pt.z = pos->z + func_L01_00440918(0.0f, 0.1f);
        func_L01_00466F98(&pt, &vel, 0x1E, 0x7F, 0x7F7F7F, n, func_0037E250(0.1f, 0.5f) * 210000.0f, 500.0f, 1.0f, 0.0f, 1.0f);
    }
    if (big == 1) {
        n = func_0037E1D8(0xFF);
        q = func_L01_00466F98(pos, D_L22_001D66B0_00342F20, 5, 0x7F, 0x207080, n, 525000.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        if (q != 0) {
            q[2] = *D_L22_0021FFAC_00342F20[0];
        }
        q = func_L01_00466F98(pos, D_L22_001D66B0_00342F20, 5, 0x7F, 0x207080, (n + 0x80) & 0xFF, 525000.0f, 0.0f, 1.0f, 0.0f, 1.0f);
        if (q != 0) {
            q[2] = *D_L22_0021FFAC_00342F20[0];
        }
    }
}
/* localdecomp:end func_L22_00342F20 */
