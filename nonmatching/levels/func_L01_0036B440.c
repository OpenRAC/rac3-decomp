/* PAL near miss (Codex wave 10): near miss: 132 words differ with the file's flags.
 * Worker's note: 134 word diffs: build/codex/w537/func_L01_0036B440.try3.log; opaque VU sequence cannot reproduce retail interleaving; fixed flags lack vf0-vf2; constant hoisting also differs
 */
#include "common.h"
/* localdecomp:start func_L01_0036B440 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
void func_L01_0036B440(vu0_v4 *origin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 delta, velocity, position;
    f32 angle, speed, tilt, yaw, lifetime;
    s32 type, i;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(D_L01_001E29C0), "m"(*origin) : "vf1", "vf2");
    angle = func_0038D160(delta.x, delta.y);
    for (i = 14; i >= 0; i--) {
        speed = func_003824E0(0.5f, 1.0f);
        type = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        tilt = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, speed * 0.020000001415610313f, yaw, tilt);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        lifetime = 210000.0f * func_003824E0(0.05f, 0.2f);
        func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, type,
            lifetime, 500.0f, 1.0f, 0.0f, 2.0f);
    }
}
/* localdecomp:end func_L01_0036B440 */
