#include "common.h"

/* NTSC-U counterpart of func_L18_0033F208 (src/levels/shared/L18_0033F208.c) */
#include "vu0.h"

/* localdecomp:start func_L18_0033E9A8 */
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
extern u8 *D_L18_002211F4[];
extern s32 D_001A71A0[];
extern Hit_0033F208 D_L18_001EAB00;
extern u8 D_L18_001D6700_0033E9A8;
__asm__(".extern D_L18_001D6700_0033E9A8, 64");
void func_L18_0033E9A8(Moby_0033F208 *moby) {
    extern void func_003BEBF8(f32 *, f32, f32);
    extern void func_00388830(void *, void *, f32);
    extern Target_0033F208 *func_0037E0B8(void *);
    extern f32 func_00388A28(f32, f32);
    extern f32 func_00388800(void *, void *);
    extern void func_L01_00445758(f32 *, f32 *, f32, f32, f32, f32, s32);
    extern f32 func_0037E250(f32, f32);
    extern u8 *func_L01_00466F98(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    extern void func_003888C8(void *, void *, void *);
    extern f32 func_0037E2A8(void);
    extern void func_00389158(void *, void *, void *, f32);
    extern s32 func_L01_00462FD0(void *, void *, u32, u32, s32, s32, f32);
    extern s32 func_003CE740(void *, void *, s32, s32, s32);
    extern s32 func_00388398(void *);
    extern void func_003BD360(void *);
    extern void func_L01_00447D00(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
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
    func_003BEBF8(&vars->speed, 1.1666667461395264f, 0.02777777798473835f);
    func_00388830(&velocity, &moby->direction, vars->speed);
    if (vars->target) {
        target = func_0037E0B8(vars->target);
        if (target) {
            *(vu0_q *)&v = *(vu0_q *)&vars->target->pos;
            v.z += target->height;
            yaw = func_00388A28(v.x - moby->pos.x, v.y - moby->pos.y);
            scale = func_00388800(&v, &moby->pos);
            pitch = func_00388A28(scale, moby->pos.z - v.z);
            func_L01_00445758(&moby->yaw, &vars->yaw_rate, yaw, 0.0053329505026340485f, 0.0053329505026340485f, 0.0581776462495327f, 0);
            func_L01_00445758(&moby->pitch, &vars->pitch_rate, pitch, 0.0053329505026340485f, 0.0053329505026340485f, 0.0581776462495327f, 0);
        }
    }
    pos = &moby->pos;
    *(vu0_q *)&temp = 0;
    temp.x = func_0037E250(-1.0f, 1.0f);
    temp.y = func_0037E250(-1.0f, 1.0f);
    temp.z = func_0037E250(-1.0f, 1.0f);
    *(vu0_q *)&v = *(vu0_q *)&temp;
    scale = func_0037E250(0.1f, 0.2f) * 0.01666666753590107f;
    func_00388830(&v, &v, scale);
    temp_ptr = &temp;
    scale = -func_0037E250(0.0016666668234393f, 0.01666666753590107f);
    func_00388830(temp_ptr, &velocity, scale);
    vec_add_ab(&v, &v, &temp);
    scale = func_0037E250(0.0f, 1.0f) * vars->speed;
    func_00388830(temp_ptr, &velocity, scale);
    vec_add_ab(&temp, &temp, &moby->pos);
    particle = func_L01_00466F98(temp_ptr, &v, 60, 127, 0x606060, 3, 40000.0f, 1000.0f, 1.0f, -0.00019999999494757503f, 0.0f);
    if (particle) {
        particle[2] = D_L18_002211F4[0][0];
        particle[3] = 0x44;
    }
    func_L01_00466F98(pos, &v, 6, 127, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.00039999998989515007f, 0.0f);
    *(vu0_q *)&rotation = 0;
    rotation.z = 0.02f;
    func_003888C8(&rotation, &rotation, &moby->direction);
    scale = func_0037E2A8();
    func_00389158(&rotation, &rotation, &moby->direction, scale);
    func_L01_00462FD0(temp_ptr, &rotation, 0x4F007FFF, 0x1FFFFFFF, 5, 1, 20000.0f);
    *(vu0_q *)&v = *(vu0_q *)&moby->pos;
    vec_add_ab(&moby->pos, &moby->pos, &velocity);
    if (moby->pos.x < 0.0f || moby->pos.y < 0.0f || moby->pos.z < 0.0f) {
        func_003BD360(moby);
        return;
    }
    if (func_003CE740(&v, &moby->pos, 0, D_001A71A0[0], 0)) {
        if (D_L18_001EAB00.moby) {
            if (D_L18_001EAB00.moby != moby->owner) {
                moby->hit = 2;
                *(vu0_q *)&moby->pos = *(vu0_q *)&D_L18_001EAB00.pos;
            }
        } else if (D_L18_001EAB00.count > 0) {
            moby->hit = 1;
            *(vu0_q *)&moby->pos = *(vu0_q *)&D_L18_001EAB00.pos;
        }
    } else if (func_00388398(&vars->timer)) {
        func_003BD360(moby);
        return;
    }
    if (moby->hit) {
        func_L01_00447D00(moby, &D_L18_001D6700_0033E9A8, 0, 0, 3, 16, -1, 0, 0, -1, 0, 0x1010000,
            2.0f, 6.0f, 1.0f, 0.5f, 9.0f, 1.0f, 15.0f);
        func_003BD360(moby);
    }
}
/* localdecomp:end func_L18_0033E9A8 */
