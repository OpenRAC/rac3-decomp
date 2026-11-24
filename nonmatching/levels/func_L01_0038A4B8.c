/* PAL near miss (round 14, r14_b/z4.c): 92 words differ with the file's flags (haiku-w1's draft: 106).
 * What closed the gap: the 210000.0f written in place, with the lifetime computed twice (the first
 * one dead: retail calls func_003824E0(0.05f, 0.2f) and drops the result, and the second use keeps
 * the constant live long enough for loop.c to hoist it into $f30 after 0.2f, as retail has); the
 * prologue and every hoisted constant now agree. u8 *D_L01_00221098[] as the file declares it.
 * Still differs: the loop counter's decrement. sched1's interblock motion (-dS dump: "interblock
 * motions == 1") moves i-- from the join block to the top of the loop, into the first jal's delay
 * slot; retail keeps it at the end, in the beqz's delay slot. The loop is one region of 68 insns
 * (under MAX_RGN_INSNS 100). Same bytes: `for (i = 0; i < 15; i++)` (reversed by loop.c),
 * `for (i = 14; i >= 0; i--)`, `while (--i >= 0)`, i-- before or after the if, `continue`, and a
 * while loop. All the rest of the 92 words is that shift. */
#include "common.h"
#include "vu0.h"

extern vu0_v4 D_L01_001E29C0;
extern u8 *D_L01_00221098[];

void func_L01_0038A4B8(void *p) {
    vu0_v4 *origin = p;
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 delta, velocity, position;
    f32 angle, speed, tilt, yaw, lifetime;
    s32 type, i;
    u8 *particle;

    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    i = 14;
    do {
        speed = func_003824E0(0.5f, 1.0f);
        type = (s32)func_L01_00443A18(1.0f, 2.0f);
        lifetime = func_003824E0(0.05f, 0.2f) * 210000.0f;
        tilt = func_003824E0(0.0f, 1.39626336f);
        yaw = func_L01_00443A18(0.0f, 1.39626336f);
        yaw = func_0038DAB8(angle, yaw);
        func_00382760(&velocity, speed * 0.020000001415610313f, yaw, tilt);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        lifetime = func_003824E0(0.05f, 0.2f) * 210000.0f;
        particle = func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, type,
            lifetime, 500.0f, 1.0f, 0.0f, 2.0f);
        i--;
        if (particle != 0) particle[2] = D_L01_00221098[0x5B][1];
    } while (i >= 0);
}
