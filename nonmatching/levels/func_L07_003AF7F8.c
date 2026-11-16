/*
 * P03 PAL retail reconstruction, wave 2, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock checker: 2 positional differences; preserves checked iteration 04.
 * Attempts: 2, 2, 70, 2 differences. Three formulations (01/02/04) have
 * identical checker output. Remaining: second call's pitch move and speed
 * pointer setup are swapped. No full build or US carry; marker retained.
 */
#include "common.h"
#include "vu0.h"
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
typedef struct { u8 pad[0xF0]; f32 pitch; } Aim_003AF7F8;
typedef struct { u8 pad[0xD8]; f32 pitch; } Speed_003AF7F8;
void func_L07_003AF7F8(u8 *self) {
    vu0_v4 target;
    u8 *p = *(u8 **)(self + 0x68);
    f32 yaw, pitch;
    *(vu0_q *)&target = *(vu0_q *)(p + 0x30);
    target.z += -0.75f;
    yaw = func_0038DB00(func_0038D160(target.x - *(f32 *)(self + 0x10),
                                   target.y - *(f32 *)(self + 0x14)), 1.5707964f);
    pitch = func_0038D160(func_0038CF38(self + 0x10, &target),
                         target.z - *(f32 *)(self + 0x18));
    func_L01_00448728(self + 0xF8, p + 0xDC, 0, yaw, 0.00072000007f, 0.014400001f, 0.0f);
    func_L01_00448728(&((Aim_003AF7F8 *)self)->pitch, &((Speed_003AF7F8 *)p)->pitch,
                     0, pitch, 0.00072000007f, 0.014400001f, 0.0f);
}
