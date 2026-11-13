/* Level 02 (Florana), PAL. 28 diff with check.py --flags=-mvu0-use-vf0-vf2 (L02_0034FE10.c is @ps2as; it needs the VU0 flag too). A Florana creature turning its head toward the hero (yaw and pitch clamped to 90 and 30 degrees) before func_L01_0044E850.
   What differs: the last call. Retail loads 1.44f into $f12 and multiplies at run time
   (`$f13 = 0.3f * $f12`, `$f12 = 0.04f * $f12`); gcc folds both products to constants whatever the
   wording (literal products, a local assigned before the call, before the `if`, or in both arms:
   28, 102, 35 diff), and that also flips which of self/d gets $s0/$s1 (retail: self $s1, d $s0).
   Everything before the call (the VU0 subtraction, the atan2/angle-difference calls, both clamps) matches. */
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
        vec_sub_ab(&dir, &tgt, &me);
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
