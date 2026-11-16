/* PAL near miss (Codex wave 8): near miss: 320 words differ with the file's flags.
 * Worker's note: Best 324 diff: w431/func_L01_003E99E8.02.log (divs 0,1,1 tested, no MATCH). Complete camera draft; VU scheduling, address allocation, float live ranges differ. Refined typed03/04/05 each identical334diff (divs0,2,2), correct C0 frame; retained separately.
 */
#include "common.h"
/* localdecomp:start func_L01_003E99E8 */
#include "vu0.h"
void func_L01_003E99E8(u8 *obj)
{
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038D0C8(f32);
    extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    u8 *follow = *(u8 **)(obj + 0x70);
    u8 *look = follow + 0x60;
    u8 *view = follow + 0x20;
    u8 *entry = D_L01_001E2AA0 + *(s32 *)(obj + 0x94) * 0x460;
    f32 *up;
    f32 *right;
    f32 *forward;
    f32 *axis = (f32 *)obj;
    u8 *springs;
    f32 length, angle, height, dot, pitch, target;
    if (look[0xE4] == 11) {
        __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
            : "=m"(*(vu0_v4 *)obj) : "m"(*(vu0_v4 *)(obj + 0x30)), "m"(*(vu0_v4 *)(entry + 0x150)) : "vf1", "vf2");
        func_0038CF68(axis, axis, 1.0f);
        up = (f32 *)(entry + 0x20);
        right = (f32 *)(obj + 0x10);
        forward = (f32 *)(obj + 0x20);
        func_0038CB00(view);
    } else {
        up = (f32 *)(entry + 0x20);
        func_0038CE20(a, up, func_0038CE68((f32 *)(follow + 0xA0), up));
        __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
            : "=m"(*(vu0_v4 *)b) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)(follow + 0xA0)) : "vf1", "vf2");
        springs = *(u8 **)(obj + 0x70) + 0x180;
        func_0038CE20(a, up, func_0038CE68((f32 *)(obj + 0x30), up));
        __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
            : "=m"(*(vu0_v4 *)c) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)(obj + 0x30)) : "vf1", "vf2");
        __asm__("lqc2 vf1,%1\n lqc2 vf2,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
            : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)b), "m"(*(vu0_v4 *)c) : "vf1", "vf2");
        if (*(f32 *)(view + 0x28) != 0.0f) func_0038D890(d, d, up, *(f32 *)(view + 0x28));
        length = func_0038CEA8(d);
        if (length >= 0.05f) {
            func_0038CE20(axis, d, 1.0f / length);
        } else {
            func_0038CE20(e, up, func_0038CE68(axis, up));
            __asm__("lqc2 vf1,%1\n lqc2 vf2,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
                : "=m"(*(vu0_v4 *)obj) : "m"(*(vu0_v4 *)obj), "m"(*(vu0_v4 *)e) : "vf1", "vf2");
        }
        right = (f32 *)(obj + 0x10);
        func_0038CE90(right, axis, up);
        func_0038CF68(right, right, 1.0f);
        forward = (f32 *)(obj + 0x20);
        *(f32 *)(view + 8) = func_00382BC8((f32 *)(view + 0x10), *(f32 *)(view + 8), *(f32 *)(springs + 0x30), 0.004f, 0.2f, 0.0f);
        *(f32 *)(view + 4) = func_00382BC8((f32 *)(view + 0xC), *(f32 *)(view + 4), *(f32 *)(look + 0xD0), 0.004f, 0.2f, 0.0f);
        height = *(f32 *)(view + 8) - *(f32 *)(view + 4);
        func_0038CE20(a, up, -func_0038CE68((f32 *)(springs + 0x10), up));
        __asm__("lqc2 vf2,%1\n lqc2 vf1,%2\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%0"
            : "=m"(*(vu0_v4 *)a) : "m"(*(vu0_v4 *)d), "m"(*(vu0_v4 *)a) : "vf1", "vf2");
        __asm__("lqc2 vf1,%1\n lqc2 vf2,%2\n vsub.xyz vf2,vf2,vf1\n sqc2 vf2,%0"
            : "=m"(*(vu0_v4 *)e) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)(obj + 0x30)) : "vf1", "vf2");
        func_0038CE20(a, up, -height);
        __asm__("lqc2 vf2,%2\n lqc2 vf1,%3\n vsub.xyz vf1,vf1,vf2\n lqc2 vf2,%4\n sqc2 vf1,%0\n lqc2 vf1,%0\n vsub.xyz vf1,vf1,vf2\n sqc2 vf1,%1"
            : "=m"(*(vu0_v4 *)e), "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)e), "m"(*(vu0_v4 *)(obj + 0x30)) : "vf1", "vf2");
        length = func_0038CEA8(d);
        if (length != 0.0f) {
            angle = 1.57079637f - func_0038D0C8(func_0038CE68(axis, d) / length);
            func_0038CE90(forward, right, axis);
            if (func_0038CE68(forward, d) < 0.0f) angle = -angle;
            dot = func_0038CE68((f32 *)springs, up);
            length = func_0038CEA8((f32 *)springs);
            target = 0.0f;
            if (*(s32 *)((u8 *)D_L01_001E2A40 + *(s32 *)(obj + 0x94) * 0x460 + 0x26C) != 0) {
                pitch = func_0038D160(length, dot) / 0.6981317f;
                if (pitch < -0.1f) {
                    pitch = -pitch;
                    if (pitch > 0.5f) pitch = 1.0f - pitch;
                    pitch += pitch;
                    target += pitch * 0.2617994f;
                }
            }
            *(f32 *)(view + 0x14) = func_00382C58((f32 *)(view + 0x18), *(f32 *)(view + 0x14), target, *(f32 *)(view + 0x1C), *(f32 *)(view + 0x20), 0.0f);
            angle = func_0038DB00(angle, *(f32 *)(view + 0x14));
            if (angle > 1.2217305f) angle = 1.2217305f;
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
/* localdecomp:end func_L01_003E99E8 */
