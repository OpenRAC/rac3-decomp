/* func_L01_003E99E8 (Claude wave 14 r51, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
/* func_L01_003E99E8: 227 diff with the file's flags (wave 14 r51; the Codex wave 8 draft had 326). Changes
 * against it: every VU0 block is a vu0.h helper (vec_sub_ab / vec_sub_ba, the file's line has
 * -mvu0-use-vf0-vf2) instead of raw asm with hard-coded vf registers, and the look[0xE4] == 11 branch reads
 * D_L01_001E2AA0 + 0x150 + idx * 0x460 directly (retail's addiu 0x150 / addu instead of entry + 0x150).
 * Remaining: the frame (0xD0: one length variable is reused for both lengths and the springs length, so it
 * needs a callee-saved $f register; splitting it into three locals gives retail's 0xC0 frame and $f20-$f23
 * but measures 235 here) and the $s register assignment (retail: entry/up-projection pointer/right in $s0,
 * follow then &d in $s2, view $s3, up $s4, look $s7; retail also computes entry + 0x20 in place in $s0 and
 * copies it to $s4 for the later uses: writing the two projections with (entry + 0x20) and `up = ...` after
 * them reproduces that copy but costs $fp, 293). */
#include "common.h"

/* localdecomp:start func_L01_003E99E8 */
#include "vu0.h"
void func_L01_003E99E8(u8 *obj)
{
    extern f32 func_00382C58(f32 *, f32, f32, f32, f32, f32);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
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
        vec_sub_ba(obj, D_L01_001E2AA0 + 0x150 + *(s32 *)(obj + 0x94) * 0x460, obj + 0x30);
        func_0038CF68(axis, axis, 1.0f);
        up = (f32 *)(entry + 0x20);
        right = (f32 *)(obj + 0x10);
        forward = (f32 *)(obj + 0x20);
        func_0038CB00(view);
    } else {
        up = (f32 *)(entry + 0x20);
        func_0038CE20((f32 *)&a, up, func_0038CE68((f32 *)(follow + 0xA0), up));
        vec_sub_ba(&b, follow + 0xA0, &a);
        springs = *(u8 **)(obj + 0x70) + 0x180;
        func_0038CE20((f32 *)&a, up, func_0038CE68((f32 *)(obj + 0x30), up));
        vec_sub_ba(&c, obj + 0x30, &a);
        vec_sub_ab(&d, &b, &c);
        if (*(f32 *)(view + 0x28) != 0.0f) {
            func_0038D890((f32 *)&d, (f32 *)&d, up, *(f32 *)(view + 0x28));
        }
        length = func_0038CEA8((f32 *)&d);
        if (length >= 0.05f) {
            func_0038CE20(axis, (f32 *)&d, 1.0f / length);
        } else {
            func_0038CE20((f32 *)&e, up, func_0038CE68(axis, up));
            vec_sub_ab(obj, obj, &e);
        }
        right = (f32 *)(obj + 0x10);
        func_0038CE90(right, axis, up);
        func_0038CF68(right, right, 1.0f);
        forward = (f32 *)(obj + 0x20);
        *(f32 *)(view + 8) = func_00382BC8((f32 *)(view + 0x10), *(f32 *)(view + 8), *(f32 *)(springs + 0x30), 0.004f, 0.2f, 0.0f);
        *(f32 *)(view + 4) = func_00382BC8((f32 *)(view + 0xC), *(f32 *)(view + 4), *(f32 *)(look + 0xD0), 0.004f, 0.2f, 0.0f);
        height = *(f32 *)(view + 8) - *(f32 *)(view + 4);
        func_0038CE20((f32 *)&a, up, -func_0038CE68((f32 *)(springs + 0x10), up));
        vec_sub_ba(&a, &a, &d);
        vec_sub_ba(&e, obj + 0x30, &a);
        func_0038CE20((f32 *)&a, up, -height);
        vec_sub_ba(&e, &e, &a);
        vec_sub_ba(&d, &e, obj + 0x30);
        length = func_0038CEA8((f32 *)&d);
        if (length != 0.0f) {
            angle = 1.5707964f - func_0038D0C8(func_0038CE68(axis, (f32 *)&d) / length);
            func_0038CE90(forward, right, axis);
            if (func_0038CE68(forward, (f32 *)&d) < 0.0f) {
                angle = -angle;
            }
            dot = func_0038CE68((f32 *)springs, up);
            length = func_0038CEA8((f32 *)springs);
            target = 0.0f;
            if (*(s32 *)((u8 *)D_L01_001E2A40 + *(s32 *)(obj + 0x94) * 0x460 + 0x26C) != 0) {
                pitch = func_0038D160(length, dot) / 0.6981317f;
                if (pitch < -0.1f) {
                    pitch = -pitch;
                    if (pitch > 0.5f) {
                        pitch = 1.0f - pitch;
                    }
                    pitch += pitch;
                    target += pitch * 0.2617994f;
                }
            }
            *(f32 *)(view + 0x14) = func_00382C58((f32 *)(view + 0x18), *(f32 *)(view + 0x14), target, *(f32 *)(view + 0x1C), *(f32 *)(view + 0x20), 0.0f);
            angle = func_0038DB00(angle, *(f32 *)(view + 0x14));
            if (angle > 1.2217305f) {
                angle = 1.2217305f;
            } else if (angle < -1.2217305f) {
                angle = -1.2217305f;
            }
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
