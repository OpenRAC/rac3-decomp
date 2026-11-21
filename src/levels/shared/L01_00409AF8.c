#include "common.h"
#include "vu0.h"

LINKER_REMNANT("asm/levels", func_L01_00409AF8);

/* localdecomp:start func_L01_00409B08 */
typedef struct {
    vu0_v4 v[4];
    u32 c[4];
    f32 w[8];
    u8 pad70[0x20];
    vu0_v4 mat[3];
    vu0_v4 pp;
    f32 r[4];
    vu0_v4 d;
} L409B08;

typedef struct {
    u8 pad0[0x140];
    vu0_v4 p;
    f32 z;
} G409B08;

extern G409B08 D_L01_001E2880_00409B08;
extern void func_003D93B0(void *, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_00409B08(f32 *pos, s32 col, s32 dbl) {
    L409B08 l;
    f32 sc;
    u32 c;

    l.v[0].z = -2.0f;
    l.v[1].z = 2.0f;
    l.v[2].z = -2.0f;
    l.v[3].z = 2.0f;
    l.v[0].y = -2.0f;
    l.v[2].y = 2.0f;
    l.v[1].y = -2.0f;
    l.v[3].y = 2.0f;
    l.v[0].x = 0.0f;
    l.v[1].x = 0.0f;
    l.v[2].x = 0.0f;
    l.v[3].x = 0.0f;
    l.v[0].w = 1.0f;
    l.v[1].w = 1.0f;
    l.v[2].w = 1.0f;
    l.v[3].w = 1.0f;
    func_003D93B0(&l, 0x2C, 1, 0x80);
    c = (func_00382498(0x30, 0x40) << 24) | ((col >> 17) << 16) | ((col >> 9) & 0xFF00) | ((col >> 1) & 0xFF);
    l.c[3] = c;
    l.c[2] = c;
    l.c[1] = c;
    l.c[0] = c;
    l.w[0] = 0.0f;
    l.w[1] = 0.0f;
    l.w[2] = 0.0f;
    l.w[3] = 1.0f;
    l.w[4] = 1.0f;
    l.w[5] = 0.0f;
    l.w[6] = 1.0f;
    l.w[7] = 1.0f;
    l.r[3] = 0.0f;
    l.r[2] = func_0038D160(D_L01_001E2880_00409B08.p.x - pos[0], D_L01_001E2880_00409B08.p.y - pos[1]);
    l.r[1] = -func_0038D160(func_0038CF38(pos, &D_L01_001E2880_00409B08.p), D_L01_001E2880_00409B08.p.z - pos[2]);
    l.r[0] = func_00382538();
    func_0038D328(l.mat, l.r);
    vec_sub_ab(&l.d, &D_L01_001E2880_00409B08.p, pos);
    func_0038CF68(&l.d, &l.d, 0.25f);
    l.pp.x = pos[0] + l.d.x;
    l.pp.y = pos[1] + l.d.y;
    l.pp.z = pos[2] + l.d.z;
    l.pp.w = 1.0f;
    sc = func_003824E0(0.3f, 0.4f);
    if (dbl != 0) {
        sc += sc;
    }
    func_0038CE20(&l.v[0], &l.v[0], sc);
    func_0038CE20(&l.v[1], &l.v[1], sc);
    func_0038CE20(&l.v[2], &l.v[2], sc);
    func_0038CE20(&l.v[3], &l.v[3], sc);
    func_003D2DA0(&l, l.mat, 0);
    func_0038CE20(&l.v[0], &l.v[0], 0.5f);
    func_0038CE20(&l.v[1], &l.v[1], 0.5f);
    func_0038CE20(&l.v[2], &l.v[2], 0.5f);
    func_0038CE20(&l.v[3], &l.v[3], 0.5f);
    c = col + (func_00382498(0x40, 0x7F) << 24);
    l.c[3] = c;
    l.c[2] = c;
    l.c[1] = c;
    l.c[0] = c;
    func_003D2DA0(&l, l.mat, 0);
    func_0038CE20(&l.v[0], &l.v[0], 0.5f);
    func_0038CE20(&l.v[1], &l.v[1], 0.5f);
    func_0038CE20(&l.v[2], &l.v[2], 0.5f);
    func_0038CE20(&l.v[3], &l.v[3], 0.5f);
    c = (func_00382498(0x40, 0x7F) << 24) + 0x7F7F7F;
    l.c[3] = c;
    l.c[2] = c;
    l.c[1] = c;
    l.c[0] = c;
    func_003D2DA0(&l, l.mat, 0);
}
/* localdecomp:end func_L01_00409B08 */

INCLUDE_ASM("asm/levels", func_L01_00409E70);

INCLUDE_ASM("asm/levels", func_L01_0040A4A0);
