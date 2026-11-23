/* functional: high. Per-frame camera basis update (obj = camera: axis +0x00, right +0x10, forward +0x20, pos +0x30, prev axis +0x40; follow block at obj+0x70): in follow mode 11 aims the axis from the position to the player table entry (+0x150); otherwise projects the follow/spring vectors onto the player's up plane, aims the axis at the projected target (tilting it about up by view+0x28 first), springs the view heights view+0x04/+0x08 (func_00382BC8) and the pitch view+0x14 (func_00382C58, driven by the spring pitch when the per-player flag +0x26C is set), then pitches the axis about right by the clamped angle (+-70 deg). Finally optionally blends toward the previous axis by view[0]*view+0x24 and rebuilds right/forward orthonormally. Branches, constants and callee args checked against PAL asm (VU0 vsub.xyz kept as COP2 asm); the combined asm blocks of retail are split into separate vsubs, same values */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
extern Entry_3E6C58 D_L01_001E2A40[];
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern f32 func_0038CEA8(f32 *);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
static __inline__ void vsub_003E99E8(void *d, void *x, void *y) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)x), "m"(*(vu0_v4 *)y) : "vf1", "vf2");
}
void func_L01_003E99E8(u8 *obj) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    u8 *follow = *(u8 **)(obj + 0x70);
    u8 *look = follow + 0x60;
    u8 *view = follow + 0x20;
    u8 *entry = D_L01_001E2AA0 + *(s32 *)(obj + 0x94) * 0x460;
    f32 *up = (f32 *)(entry + 0x20);
    f32 *axis = (f32 *)obj;
    f32 *right = (f32 *)(obj + 0x10);
    f32 *forward = (f32 *)(obj + 0x20);
    u8 *springs;
    f32 length, angle, height, dot, pitch, target;
    if (look[0xE4] == 11) {
        vsub_003E99E8(axis, entry + 0x150, obj + 0x30);
        func_0038CF68(axis, axis, 1.0f);
        func_0038CB00(view);
    } else {
        func_0038CE20(a, up, func_0038CE68((f32 *)(follow + 0xA0), up));
        vsub_003E99E8(b, follow + 0xA0, a);
        springs = *(u8 **)(obj + 0x70) + 0x180;
        func_0038CE20(a, up, func_0038CE68((f32 *)(obj + 0x30), up));
        vsub_003E99E8(c, obj + 0x30, a);
        vsub_003E99E8(d, b, c);
        if (*(f32 *)(view + 0x28) != 0.0f) func_0038D890(d, d, up, *(f32 *)(view + 0x28));
        length = func_0038CEA8(d);
        if (0.05f <= length) {
            func_0038CE20(axis, d, 1.0f / length);
        } else {
            func_0038CE20(e, up, func_0038CE68(axis, up));
            vsub_003E99E8(axis, axis, e);
        }
        func_0038CE90(right, axis, up);
        func_0038CF68(right, right, 1.0f);
        *(f32 *)(view + 8) = func_00382BC8((f32 *)(view + 0x10), *(f32 *)(view + 8), *(f32 *)(springs + 0x30), 0.004f, 0.2f, 0.0f);
        *(f32 *)(view + 4) = func_00382BC8((f32 *)(view + 0xC), *(f32 *)(view + 4), *(f32 *)(look + 0xD0), 0.004f, 0.2f, 0.0f);
        height = *(f32 *)(view + 8) - *(f32 *)(view + 4);
        func_0038CE20(a, up, -func_0038CE68((f32 *)(springs + 0x10), up));
        vsub_003E99E8(a, a, d);
        vsub_003E99E8(e, obj + 0x30, a);
        func_0038CE20(a, up, -height);
        vsub_003E99E8(e, e, a);
        vsub_003E99E8(d, e, obj + 0x30);
        length = func_0038CEA8(d);
        if (length != 0.0f) {
            angle = 1.5707964f - func_0038D0C8(func_0038CE68(axis, d) / length);
            func_0038CE90(forward, right, axis);
            if (func_0038CE68(forward, d) < 0.0f) angle = -angle;
            dot = func_0038CE68((f32 *)springs, up);
            length = func_0038CEA8((f32 *)springs);
            target = 0.0f;
            if (*(s32 *)((u8 *)D_L01_001E2A40 + *(s32 *)(obj + 0x94) * 0x460 + 0x26C) != 0) {
                pitch = func_0038D160(length, dot) / 0.6981317f;
                if (pitch < -0.1f) {
                    pitch = -pitch;
                    if (0.5f < pitch) pitch = 1.0f - pitch;
                    pitch = pitch + pitch;
                    target = pitch * 0.2617994f + target;
                }
            }
            *(f32 *)(view + 0x14) = func_00382C58((f32 *)(view + 0x18), *(f32 *)(view + 0x14), target, *(f32 *)(view + 0x1C), *(f32 *)(view + 0x20), 0.0f);
            angle = func_0038DB00(angle, *(f32 *)(view + 0x14));
            if (1.2217305f < angle) angle = 1.2217305f;
            else if (angle < -1.2217305f) angle = -1.2217305f;
            func_0038D890(axis, axis, right, angle);
            func_0038CF68(axis, axis, 1.0f);
        }
    }
    if (*(s16 *)view != 0) {
        func_0038CB00(view);
        func_0038CDF8(axis, axis, (f32 *)(obj + 0x40), (f32)*(s16 *)view * *(f32 *)(view + 0x24));
        func_0038CF68(axis, axis, 1.0f);
    }
    func_0038CE90(right, axis, up);
    func_0038CF68(right, right, 1.0f);
    func_0038CE90(forward, right, axis);
}
