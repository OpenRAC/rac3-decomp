#include "common.h"

/* localdecomp:start func_L01_00450BB0 */
typedef struct {
    u8 pad_0[0x1430];
    u8 *lockon_target;             /* 0x1430: the moby locked on to, or 0 */
    u8 pad_1434[0x16B0 - 0x1434];
    s32 camera_mode;               /* 0x16B0: 0 follow, 1 lock-strafe, 2 first person */
} Hero_450BB0;
typedef struct {
    u8 b[16];
} Skip_450BB0;
typedef struct {
    f32 x, y, z, w;
} Vec_450BB0;

extern Hero_450BB0 D_001A4BE0_00450BB0;
extern Skip_450BB0 D_L01_001D7C30;
extern f32 *func_L01_00443828(u8 *moby);
extern u8 *func_L01_004501E8(void *from, void *aim, f32 far_yaw, f32 far_pitch, f32 range, f32 near_pitch,
                             f32 near_yaw, Vec_450BB0 *at, s32 a3, s32 t0, s32 t1, s32 kind,
                             Skip_450BB0 *skip, s32 s0, s32 s8, s32 s10);

/* gun_target: the gun's target: the live lock-on target, else none in the lock-strafe camera,
 * else gun_aim_target's pick (never the classes listed at 0x1D7C30). */
/* gun_target: the gun's target: the live lock-on target, else none in the lock-strafe camera,
 * else gun_aim_target's pick (never the classes listed at 0x1D7C30). `kind` comes after the
 * cone's floats (it is still the third integer argument). */
u8 *func_L01_00450BB0(void *from, void *aim, f32 far_yaw, f32 far_pitch, f32 range, f32 near_pitch, f32 near_yaw, s32 kind) {
    Hero_450BB0 *hero = &D_001A4BE0_00450BB0;
    u8 *target = hero->lockon_target;
    Skip_450BB0 skip;
    Vec_450BB0 at;

    if (target != 0 && target[0x20] != 0xFE && target[0x20] != 0xFD) {
        f32 *health = func_L01_00443828(target);
        if (health != 0 && 0.0f < *health) return hero->lockon_target;
    }
    skip = D_L01_001D7C30;
    if (D_001A4BE0_00450BB0.camera_mode == 1) return 0;
    return func_L01_004501E8(from, aim, far_yaw, far_pitch, range, near_pitch, near_yaw, &at, 0, 0, 0, kind, &skip, 1, -1, 0);
}
/* localdecomp:end func_L01_00450BB0 */

INCLUDE_ASM("asm/levels", func_L01_00450D20);

INCLUDE_ASM("asm/levels", func_L01_00450DE8);

LINKER_REMNANT("asm/levels", func_L01_00450E40);

INCLUDE_ASM("asm/levels", func_L01_00450E48);
