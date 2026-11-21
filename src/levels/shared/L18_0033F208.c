#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_0033F208 */
typedef struct Moby_0033F208 Moby_0033F208;
typedef struct {
    u8 pad0[4];
    f32 pitch_rate, yaw_rate;
    u8 padC[0x18];
    s32 timer;
    Moby_0033F208 *target;
    f32 speed;
} Vars_0033F208;
struct Moby_0033F208 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x48];
    Vars_0033F208 *vars;
    u8 pad6C[0x4C];
    Moby_0033F208 *owner;
    u8 hit;
    u8 padBD[3];
    vu0_v4 direction;
    u8 padD0[0x24];
    f32 pitch, yaw;
};
typedef struct { u8 pad0[0x10]; f32 height; } Target_0033F208;
typedef struct {
    u8 pad0[0x18];
    Moby_0033F208 *moby;
    s32 count;
    vu0_v4 pos;
} Hit_0033F208;
extern u8 *D_L18_00221174[];
extern s32 D_001A71A0[];
extern Hit_0033F208 D_L18_001EAA80;
extern u8 D_L18_001D6700;
__asm__(".extern D_L18_001D6700, 64");
void func_L18_0033F208(Moby_0033F208 *moby) {
    extern void func_003C4138(f32 *, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern Target_0033F208 *func_00382348(void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00448890(f32 *, f32 *, f32, f32, f32, f32, s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_00382538(void);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_L01_00466588(void *, void *, u32, u32, s32, s32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(void *);
    extern void func_L01_0044AF78(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32, f32, f32, f32);
    vu0_v4 velocity;
    vu0_v4 v;
    vu0_v4 temp;
    vu0_v4 rotation;
    vu0_v4 *temp_ptr;
    vu0_v4 *pos;
    Vars_0033F208 *vars;
    Target_0033F208 *target;
    f32 yaw, pitch;
    f32 scale;
    u8 *particle;
    vars = moby->vars;
    func_003C4138(&vars->speed, 1.4000000953674316f, 0.04000000283122063f);
    func_0038CF68(&velocity, &moby->direction, vars->speed);
    if (vars->target) {
        target = func_00382348(vars->target);
        if (target) {
            *(vu0_q *)&v = *(vu0_q *)&vars->target->pos;
            v.z += target->height;
            yaw = func_0038D160(v.x - moby->pos.x, v.y - moby->pos.y);
            scale = func_0038CF38(&v, &moby->pos);
            pitch = func_0038D160(scale, moby->pos.z - v.z);
            func_L01_00448890(&moby->yaw, &vars->yaw_rate, yaw, 0.007679448928683996f, 0.007679448928683996f, 0.06981317698955536f, 0);
            func_L01_00448890(&moby->pitch, &vars->pitch_rate, pitch, 0.007679448928683996f, 0.007679448928683996f, 0.06981317698955536f, 0);
        }
    }
    pos = &moby->pos;
    *(vu0_q *)&temp = 0;
    temp.x = func_003824E0(-1.0f, 1.0f);
    temp.y = func_003824E0(-1.0f, 1.0f);
    temp.z = func_003824E0(-1.0f, 1.0f);
    *(vu0_q *)&v = *(vu0_q *)&temp;
    scale = func_003824E0(0.1f, 0.2f) * 0.020000001415610313f;
    func_0038CF68(&v, &v, scale);
    temp_ptr = &temp;
    scale = -func_003824E0(0.0020000000949949026f, 0.020000001415610313f);
    func_0038CF68(temp_ptr, &velocity, scale);
    vec_add_ab(&v, &v, &temp);
    scale = func_003824E0(0.0f, 1.0f) * vars->speed;
    func_0038CF68(temp_ptr, &velocity, scale);
    vec_add_ab(&temp, &temp, &moby->pos);
    particle = func_L01_0046A610(temp_ptr, &v, 50, 127, 0x606060, 3, 40000.0f, 1000.0f, 1.0f, -0.00019999999494757503f, 0.0f);
    if (particle) {
        particle[2] = D_L18_00221174[0][0];
        particle[3] = 0x44;
    }
    func_L01_0046A610(pos, &v, 5, 127, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.00039999998989515007f, 0.0f);
    *(vu0_q *)&rotation = 0;
    rotation.z = 0.02f;
    func_0038D000(&rotation, &rotation, &moby->direction);
    scale = func_00382538();
    func_0038D890(&rotation, &rotation, &moby->direction, scale);
    func_L01_00466588(temp_ptr, &rotation, 0x4F007FFF, 0x1FFFFFFF, 4, 1, 20000.0f);
    *(vu0_q *)&v = *(vu0_q *)&moby->pos;
    vec_add_ab(&moby->pos, &moby->pos, &velocity);
    if (moby->pos.x < 0.0f || moby->pos.y < 0.0f || moby->pos.z < 0.0f) {
        func_003C2880(moby);
        return;
    }
    if (func_003D3CB0(&v, &moby->pos, 0, D_001A71A0[0], 0)) {
        if (D_L18_001EAA80.moby) {
            if (D_L18_001EAA80.moby != moby->owner) {
                moby->hit = 2;
                *(vu0_q *)&moby->pos = *(vu0_q *)&D_L18_001EAA80.pos;
            }
        } else if (D_L18_001EAA80.count > 0) {
            moby->hit = 1;
            *(vu0_q *)&moby->pos = *(vu0_q *)&D_L18_001EAA80.pos;
        }
    } else if (func_0038CAD0(&vars->timer)) {
        func_003C2880(moby);
        return;
    }
    if (moby->hit) {
        func_L01_0044AF78(moby, &D_L18_001D6700, 0, 0, 3, 16, -1, 0, 0, -1, 0, 0x1010000,
            2.0f, 6.0f, 1.0f, 0.5f, 9.0f, 1.0f, 15.0f);
        func_003C2880(moby);
    }
}
/* localdecomp:end func_L18_0033F208 */
