/* functional: high. Same reads, writes, calls and clamps as retail; retail multiplies 1.44f by 0.04f/0.3f at run time, gcc folds to constants (same values within float rounding). The vsub.xyz is plain float math (the file's flags cannot take the vu0.h helpers); w lane kept from the target as vsub does. */
#include "vu0.h"
extern vu0_v4 D_001A4CC0;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L02_00350200(u8 *self, s32 track) {
    u8 *d;
    vu0_v4 tgt, me, dir;
    f32 yaw, pitch, k;

    tgt = D_001A4CC0;
    d = *(u8 **)(self + 0x68);
    if (track != 0) {
        me = *(vu0_v4 *)(self + 0x10);
        me.z += 2.0f;
        dir.x = tgt.x - me.x;
        dir.y = tgt.y - me.y;
        dir.z = tgt.z - me.z;
        dir.w = tgt.w;
        yaw = func_0038DB00(func_0038D160(dir.x, dir.y), *(f32 *)(self + 0xF8));
        pitch = -func_0038D160(func_0038CED8(&dir), dir.z);
        if (1.5707964f < yaw) yaw = 1.5707964f;
        else if (yaw < -1.5707964f) yaw = -1.5707964f;
        if (0.5235988f < pitch) pitch = 0.5235988f;
        else if (pitch < -0.5235988f) pitch = -0.5235988f;
        *(f32 *)(d + 0x2A4) = pitch;
        *(f32 *)(d + 0x2A8) = yaw * 0.6f;
        *(f32 *)(d + 0x9A8) = yaw * 0.4f;
    }
    k = 1.44f;
    func_L01_0044E850(self, d + 0x940, 3, 0.04f * k, 0.3f * k);
}
