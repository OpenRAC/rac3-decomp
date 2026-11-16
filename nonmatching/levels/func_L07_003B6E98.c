/*
 * P03 PAL retail reconstruction, wave 2, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock checker: 126 positional differences; preserves checked iteration 02.
 * Attempts: 135, 126 differences. Both divisions have one extra nop under
 * the existing padding row "func_L07_003B6E98 1 1"; retail shows only the
 * assembler's one producer-to-div nop. A 0 0 row is an untested lead, not a
 * validated fix. No metadata edits, alternate flags, full build or US carry.
 * Other call/scheduling differences may remain; marker retained.
 */
#include "common.h"
#include "vu0.h"
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L07_003B6DC8(u8 *, u8 *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L07_00473C80(void *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_L07_003B6E98(u8 *self, u8 joint) {
    extern u8 *func_L07_003B1958(void *, vu0_q *, u8, f32, f32);
    vu0_v4 origin, target;
    u8 *p = *(u8 **)(self + 0x68);
    f32 fraction, pitch, offset, speed;
    joint += 2;
    func_003C2F58(self, joint, &origin);
    fraction = func_0038DBA0(func_L07_003B6DC8(self, p + 0x80), *(f32 *)(self + 0xF8)) / 0.5235988f;
    if (fraction > 1.0f) fraction = 1.0f;
    offset = -0.5f;
    fraction = func_003C3BE8(offset, -2.0f, fraction);
    *(vu0_q *)&target = *(vu0_q *)(p + 0x80);
    target.z += fraction;
    pitch = func_0038D160(func_0038CF38(&origin, &target), target.z - origin.z);
    if (*(s16 *)(p + 0x31A)) pitch *= (f32)*(s16 *)(p + 0x31A) / 90.0f + 1.0f;
    func_L07_003B1958(self, (vu0_q *)&origin, p[0x44], *(f32 *)(self + 0xF8), -pitch);
    if ((u32)(p[0x31D] - 1) < 2) offset = 0.5f;
    speed = 21000.0f;
    func_L07_00473C80(self, joint, 0xBF804020, 0, 7, 0, 1, 0x35, 0, 735000.0f, speed, offset);
    func_L07_00473C80(self, joint, 0xBFA04020, 0, 7, 0, 1, 0x35, 0, 525000.0f, speed, offset);
    func_L07_00473C80(self, joint, 0xC0FFFFFF, 0, 7, 0, 1, 0x35, 0, 367500.0f, speed, offset);
    func_L07_00473C80(self, joint, 0xB0FFFFFF, 0, 7, 0, 1, 0x35, 0, 262500.0f, speed, offset);
}
