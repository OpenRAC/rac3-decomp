#include "common.h"

/* NTSC-U counterpart of func_L01_004E5C08 (src/levels/shared/L01_004E2988.c) */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L01_004E1E40 */
typedef struct {
    u8 pad0[0x80]; f32 pos[4];
    u8 pad90[0x110-0x90]; f32 velocity[4];
    u8 pad120[0x170-0x120]; f32 speed;
    u8 pad174[0x25C0-0x174]; u8 *moby; s32 state;
} Hero_004E5C08;
void func_L01_004E1E40(s32 count, s32 kind, s32 special)
{
    extern f32 func_0037E250(f32, f32);
    extern void func_003BDA38(u8 *, s32, u128_t *);
    extern void func_003886E8(f32 *, f32 *, f32);
    extern void func_L01_00464068(f32 *, void *, f32);
    extern void func_L01_00465020(f32 *, f32 *, f32, f32, s32);
    f32 pos[4];
    f32 vel[4];
    s32 i = 0;
    Hero_004E5C08 *hero;
    f32 *v;
    for (; i < count; i++) {
        hero = (Hero_004E5C08 *)&D_001A4BE0;
        if (kind == 0) {
            pos[0] = hero->pos[0] + func_0037E250(-0.1f, 0.1f);
            pos[1] = hero->pos[1] + func_0037E250(-0.1f, 0.1f);
            pos[2] = hero->pos[2] + func_0037E250(-0.5f, 0.1f);
        } else if (kind == 1) {
            if ((i & 1) == 0) func_003BDA38(hero->moby, 0, (u128_t *)pos);
            else func_003BDA38(hero->moby, 14, (u128_t *)pos);
        } else if (kind == 2) {
            if ((i & 1) == 0) func_003BDA38(hero->moby, 23, (u128_t *)pos);
            else func_003BDA38(hero->moby, 22, (u128_t *)pos);
        }
        *(u128_t *)vel = *(u128_t *)((u8 *)&D_001A4BE0 + 0x110);
        if (hero->state == 51) func_003886E8(vel, vel, 1.15f);
        else func_003886E8(vel, vel, 0.7f);
        v = vel;
        vel[0] += func_0037E250(-0.0066666673f, 0.0066666673f);
        vel[1] += func_0037E250(-0.0066666673f, 0.0066666673f);
        vel[2] += func_0037E250(-0.016666668f, 0.0f);
        if (special) {
            void *matrix = hero->moby + 0xC0;
            f32 r = func_0037E250(0.7f, 1.1f);
            func_L01_00464068(pos, matrix, hero->speed * r);
        } else {
            f32 r = func_0037E250(4200.0f, 7350.0f);
            func_L01_00465020(pos, v, r, -1.0f, 0x88A0A0A0);
        }
    }
}
/* localdecomp:end func_L01_004E1E40 */
