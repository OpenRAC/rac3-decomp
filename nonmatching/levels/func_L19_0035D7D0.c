/* func_L19_0035D7D0: 43 diff with -mvu0-use-vf0-vf2 @ps2as on L19_0035D238.c (its flags have neither now; its other C block, func_L19_0035D238, still matches with them). Hero-side beam and a three-pass quad draw (func_003D2DA0) with the S_3CA0A8-style packet at sp+0x20. Left: retail keeps &s in $s0 and sets it after the first func_0038D328 call; sched1 hoists that set to the packet stores here, so $s0-$s2 rotate; plus the order of the packet stores (a single-move search went from 70 to 43). func_L01_0040A8C0 takes its floats before the colours. */
#include "vu0.h"
typedef int u128_t_35D7D0 __attribute__((mode(TI)));
typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[8];
    long x70, x78, x80, x88;
    vu0_v4 r[4];
} S_35D7D0;
__asm__(".extern D_L19_001DD8E8, 4");
__asm__(".extern D_L19_001DD8EC, 4");
extern s32 D_L19_001DD8E8;
extern s32 D_L19_001DD8EC;
extern s32 D_L19_001DF240;
extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);
extern long func_00389598(s32);
extern void func_0038D328(void *, void *);
extern void func_003D2DA0(S_35D7D0 *, vu0_v4 *, s32);
extern void func_0038D2A0(void *);

void func_L19_0035D7D0(u8 *obj) {
    vu0_v4 t;
    vu0_v4 u;
    S_35D7D0 s;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *h;
    s32 color;

    if (v == 0)
        return;
    *(f32 *)(v + 0x28) = *(f32 *)(v + 0x28) - 0.025f;
    if (*(f32 *)(v + 0x28) <= -8.0f)
        *(f32 *)(v + 0x28) = *(f32 *)(v + 0x28) + 8.0f;
    h = (u8 *)&D_001A4BE0 + 0x80;
    func_L01_004C7D98(h, &t);
    func_0038CE20(&t, &t, 2.0f);
    vec_add_ba(&t, h, &t);
    u = *(vu0_v4 *)h;
    func_L01_0040A8C0(&u, &t, 0x1A, 1, 0.4f, 1.0f, *(f32 *)(v + 0x28), 0x53FF7F40, 0x53FF7F40, 0xFF7F40, 0xFF7F40);
    if (D_L19_001DD8E8 != 2)
        return;
    s.x78 = func_00389598(0x55);
    color = (D_L19_001DD8EC << 26) | 0xFF4010;
    s.x80 = 0xFF9000000260L;
    s.x70 = 4;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.c40 = color;
    s.x88 = 0x8000000048L;
    s.uv[1] = 0.0f;
    s.uv[2] = 0.0f;
    s.uv[3] = 1.0f;
    s.uv[4] = 1.0f;
    s.uv[5] = 0.0f;
    s.uv[6] = 1.0f;
    s.uv[7] = 1.0f;
    s.m[0].x = -*(f32 *)(v + 0x2C);
    qzero(&s.m[0]);
    s.m[0].y = -*(f32 *)(v + 0x2C);
    s.m[0].w = 1.0f;
    qzero(&s.m[1]);
    s.m[1].x = *(f32 *)(v + 0x2C);
    s.m[1].y = -*(f32 *)(v + 0x2C);
    s.m[1].w = 1.0f;
    qzero(&s.m[2]);
    s.m[2].x = -*(f32 *)(v + 0x2C);
    s.m[2].y = *(f32 *)(v + 0x2C);
    s.m[2].w = 1.0f;
    qzero(&s.m[3]);
    s.m[3].x = *(f32 *)(v + 0x2C);
    s.m[3].y = *(f32 *)(v + 0x2C);
    s.m[3].w = 1.0f;
    qzero(&u);
    u.z = (f32)(D_L19_001DF240 % 240) / 120.0f * 3.14159274f - 3.14159274f;
    func_0038D328(s.r, &u);
    s.uv[0] = 0.0f;
    s.r[3] = *(vu0_v4 *)((u8 *)&D_001A4BE0 + 0xE0);
    func_003D2DA0(&s, s.r, 1);
    qzero(&u);
    u.z = -((f32)(D_L19_001DF240 % 240) / 120.0f * 3.14159274f - 3.14159274f);
    func_0038D328(s.r, &u);
    s.r[3] = *(vu0_v4 *)((u8 *)&D_001A4BE0 + 0xE0);
    func_003D2DA0(&s, s.r, 1);
    func_0038D2A0(s.r);
    s.r[3] = *(vu0_v4 *)((u8 *)&D_001A4BE0 + 0xE0);
    func_003D2DA0(&s, s.r, 1);
}
