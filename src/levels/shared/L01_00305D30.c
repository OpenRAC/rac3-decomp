#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00305D30 */
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_35A8A0;
extern void func_L01_00305C50(S_35A8A0 *);
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_003D2DA0(S_35A8A0 *, f32 *, s32);
extern f32 D_L01_001E2880[];

void func_L01_00305D30(f32 scale, s32 unused, f32 *pos, s32 color) {
    S_35A8A0 s;
    vu0_v4 d;
    f32 dist;

    func_L01_00305C50(&s);
    s.x50 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.x54 = 0;
    s.x58 = 0;
    s.x64 = 0;
    s.x78 = func_00389598(0x2C);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.x70 = 0;
    s.rot[3] = 0.0f;
    s.rot[2] = func_0038D160(D_L01_001E2880[0x140 / 4] - pos[0], D_L01_001E2880[0x144 / 4] - pos[1]);
    dist = func_0038CF38(pos, &D_L01_001E2880[0x140 / 4]);
    s.rot[1] = -func_0038D160(dist, D_L01_001E2880[0x148 / 4] - pos[2]);
    s.rot[0] = func_00382538();
    func_0038D328(s.r[0], s.rot);
    vec_sub_ba(&d, &D_L01_001E2880[0x140 / 4], pos);
    func_0038CF68(&d, &d, 0.25f);
    s.r[3][0] = pos[0] + d.x;
    s.r[3][1] = pos[1] + d.y;
    s.r[3][2] = pos[2] + d.z;
    s.r[3][3] = 1.0f;
    func_0038CE20(s.m[0], s.m[0], scale);
    func_0038CE20(s.m[1], s.m[1], scale);
    func_0038CE20(s.m[2], s.m[2], scale);
    func_0038CE20(s.m[3], s.m[3], scale);
    func_003D2DA0(&s, s.r[0], 0);
}
/* localdecomp:end func_L01_00305D30 */

INCLUDE_ASM("asm/levels", func_L01_00305F00);

/* localdecomp:start func_L01_00306628 */
typedef int s128_00306628 __attribute__((mode(TI)));
typedef struct {
    s128_00306628 q0;
    s128_00306628 q10;
    s128_00306628 flame_pos[2];
    u8 pad40[0x4E0 - 0x40];
    s32 kind[2];
    u8 pad4E8[0x4F0 - 0x4E8];
    f32 u_speed[4];
    f32 u[4];
    f32 strength;
    s32 active;
    s32 phase;
    f32 rate;
    s32 hold;
    u8 pad524[0x530 - 0x524];
} Pool_00306628;

__asm__(".extern D_L01_001DC5C8, 4");
extern Pool_00306628 *D_L01_001DC5C8;
extern void func_L01_00305CB8(void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);

void func_L01_00306628(s32 unused, f32 *pos, s128_00306628 *a, s128_00306628 *b) {
    s32 i;
    s32 j;
    Pool_00306628 *pool;
    f32 *e;
    s32 o;
    u8 *base;
    f32 r, r2, r3, r4;

    for (i = 0; i < 10; i++) {
        pool = (Pool_00306628 *)(i * sizeof(Pool_00306628) + (u32)D_L01_001DC5C8);
        if (pool->active == 0) {
            base = (u8 *)pool;
            for (j = 0; j < 2; j++) {
                o = j * 0x90;
                e = (f32 *)(base + o);
                func_L01_00305CB8(base + (o + 0x2A0));
                func_L01_00305CB8(base + (o + 0x60));
                r = func_003824E0(0.3f, 0.5f);
                e[0x64 / 4] *= r;
                e[0x74 / 4] *= r;
                e[0x84 / 4] *= r;
                e[0x94 / 4] *= r;
                r2 = func_003824E0(0.9f, 1.0f);
                e[0x78 / 4] *= r2;
                e[0x98 / 4] *= r2;
                e[0x74 / 4] *= 0.4f;
                e[0x94 / 4] *= 0.4f;
                r3 = func_003824E0(-0.1f, 0.1f);
                ((f32 *)&pool->flame_pos[j])[0] = pos[0] + r3;
                r4 = func_003824E0(-0.1f, 0.1f);
                ((f32 *)&pool->flame_pos[j])[1] = pos[1] + r4;
                ((f32 *)&pool->flame_pos[j])[2] = pos[2];
                ((f32 *)&pool->flame_pos[j])[3] = 1.0f;
                pool->u_speed[j] = func_003824E0(-0.02f, -0.01f);
                pool->u[j] = func_003824E0(-7.99f, 0.0f);
                pool->kind[j] = func_0013D3E0() % 2;
            }
            pool->strength = 0.0f;
            pool->active = 1;
            pool->phase = 0;
            pool->rate = 0.0f;
            pool->q10 = *b;
            pool->q0 = *a;
            return;
        }
    }
}
/* localdecomp:end func_L01_00306628 */
