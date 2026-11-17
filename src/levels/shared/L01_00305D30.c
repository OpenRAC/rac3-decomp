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

INCLUDE_ASM("asm/levels", func_L01_00306628);
