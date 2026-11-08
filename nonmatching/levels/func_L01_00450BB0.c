/* near miss: gun_target (open-rac-engine symbols.toml; weapons.md "Gun aim assist"). Blocked by
 * the file's flags: retail builds the hero's address split (%hi kept in $s4, %lo added at each
 * use), which needs split addresses, and L01_0044E130.c is -mno-split-addresses (its blocks
 * func_L01_0044F8D8, 0044F9F8 and 0044FBC8 need that). With --mode S this C is 4 words off:
 * from and kind swap $s2/$s3. Probably a source file boundary between 0x44FE98 and 0x450BB0. */
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
u8 *func_L01_00450BB0(void *from, void *aim, s32 kind, f32 far_yaw, f32 far_pitch, f32 range, f32 near_pitch, f32 near_yaw) {
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
