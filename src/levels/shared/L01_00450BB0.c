#include "common.h"
#include "vu0.h"

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
extern f32 *func_00382348(u8 *moby);
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
        f32 *health = func_00382348(target);
        if (health != 0 && 0.0f < *health) return hero->lockon_target;
    }
    skip = D_L01_001D7C30;
    if (D_001A4BE0_00450BB0.camera_mode == 1) return 0;
    return func_L01_004501E8(from, aim, far_yaw, far_pitch, range, near_pitch, near_yaw, &at, 0, 0, 0, kind, &skip, 1, -1, 0);
}
/* localdecomp:end func_L01_00450BB0 */

/* localdecomp:start func_L01_00450D20 */
extern u8 D_001A4BE0[];
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_00450BB0(void *, void *, f32, f32, f32, f32, f32, s32);

u8 *func_L01_00450D20(void *obj, s32 kind, f32 a, f32 b, f32 c, f32 d, f32 e) {
    vu0_v4 v;
    u8 *g = D_001A4BE0;
    func_0038CE20(&v, *(u8 **)(g + 0x25C0) + 0xE0, 0.75f);
    vec_add_ab(&v, g + 0x80, &v);
    return func_L01_00450BB0(&v, obj, a, b, c, d, e, kind);
}
/* localdecomp:end func_L01_00450D20 */

/* localdecomp:start func_L01_00450DE8 */
extern void func_0038D000(f32 *, f32 *, u8 *);

void func_L01_00450DE8(u8 *obj, f32 *out, f32 x, f32 y, f32 z) {
    out[0] = x;
    out[1] = y;
    out[2] = z;
    func_0038D000(out, out, obj + 0xC0);
    vec_add_ba(out, out, obj + 0x10);
}
/* localdecomp:end func_L01_00450DE8 */

LINKER_REMNANT("asm/levels", func_L01_00450E40);

/* localdecomp:start func_L01_00450E48 */
extern void func_0038D000(f32 *, f32 *, u8 *);

void func_L01_00450E48(u8 *obj, f32 *out, f32 x, f32 y, f32 z) {
    vu0_v4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    func_0038D000(&v.x, &v.x, obj + 0xC0);
    vec_add_ab(out, out, &v);
}
/* localdecomp:end func_L01_00450E48 */
