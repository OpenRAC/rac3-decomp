#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L01_0032FBA0 */
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032FF68(void *);

void func_L01_0032FBA0(u8 *a) {
    if (((s32 (*)(s32))func_0038CAD0)(*(s32 *)(a + 104) + 68) == 0) {
        func_L01_0032FF68(a);
    }
}
/* localdecomp:end func_L01_0032FBA0 */

/* localdecomp:start func_L01_0032FBE0 */
void func_L01_0032FBE0(char *p)
{
    *(long *)(p + 112) = 0L;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -2.0f;
    *(float *)(p + 24) = 2.0f;
    *(float *)(p + 40) = -2.0f;
    *(float *)(p + 56) = 2.0f;
    *(float *)(p + 4) = -2.0f;
    *(float *)(p + 36) = 2.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long *)(p + 128) = 0x0000FF9000000260L;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0032FBE0 */

/* localdecomp:start func_L01_0032FC70 */
typedef struct { f32 x, y, z, w; } V_32FC70;
typedef union { vu0_q q; V_32FC70 v; } Q_32FC70;
typedef struct { Q_32FC70 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_32FC70;
extern long func_00389598(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);
extern f32 D_L01_001E2880[];

void func_L01_0032FC70(void *a0, void *op) {
    f32 *o = op;
    S_32FC70 s;
    f32 m[16] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 sc;
    s32 c;
    f32 *dp;
    func_L01_0032FBE0((char *)&s);
    s.f78 = func_00389598(0x2C);
    s.f80 = 0xFF9000000260UL;
    s.f88 = 0x8000000048UL;
    s.f70 = 0;
    c = (func_00382498(0x30, 0x40) << 24) + 0x8183F;
    s.col[3] = c; s.col[2] = c; s.col[1] = c; s.col[0] = c;
    dp = D_L01_001E2880;
    dir[3] = 0;
    dir[2] = func_0038D160(dp[80] - o[0], dp[81] - o[1]);
    dir[1] = -func_0038D160(func_0038CF38(o, dp + 80), dp[82] - o[2]);
    dir[0] = func_00382538();
    func_0038D328(m, dir);
    vec_sub_ba(d, dp + 80, o);
    func_0038CF68(d, d, 0.25f);
    m[12] = o[0] + d[0];
    m[13] = o[1] + d[1];
    m[14] = o[2] + d[2];
    m[15] = 1.0f;
    sc = func_003824E0(0.3f, 0.4f);
    func_0038CE20(&s.v[0], &s.v[0], sc);
    func_0038CE20(&s.v[1], &s.v[1], sc);
    func_0038CE20(&s.v[2], &s.v[2], sc);
    func_0038CE20(&s.v[3], &s.v[3], sc);
    func_003D2DA0(&s, m, 0);
    func_0038CE20(&s.v[0], &s.v[0], 0.5f);
    func_0038CE20(&s.v[1], &s.v[1], 0.5f);
    func_0038CE20(&s.v[2], &s.v[2], 0.5f);
    func_0038CE20(&s.v[3], &s.v[3], 0.5f);
    c = (func_00382498(0x40, 0x7F) << 24) + 0x103080;
    s.col[3] = c; s.col[2] = c; s.col[1] = c; s.col[0] = c;
    func_003D2DA0(&s, m, 0);
    func_0038CE20(&s.v[0], &s.v[0], 0.5f);
    func_0038CE20(&s.v[1], &s.v[1], 0.5f);
    func_0038CE20(&s.v[2], &s.v[2], 0.5f);
    func_0038CE20(&s.v[3], &s.v[3], 0.5f);
    c = (func_00382498(0x40, 0x7F) << 24) + 0x7F7F7F;
    s.col[3] = c; s.col[2] = c; s.col[1] = c; s.col[0] = c;
    func_003D2DA0(&s, m, 0);
}
/* localdecomp:end func_L01_0032FC70 */

/* localdecomp:start func_L01_0032FF68 */
#include "vu0.h"
typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    f32 uv[8];
    long l70;
    long l78;
    long l80;
    long l88;
} A_0032FF68;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern vu0_v4 D_L01_001E29C0;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);

extern long func_00389598(s32);
extern void func_L01_0032FBE0(char *);
extern s32 func_0013D3E0();
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0032FF68(void *arg) {
    u8 *o = arg;
    u8 *s;
    A_0032FF68 a;
    A_0032FF68 b;
    vu0_v4 mat[4];
    vu0_v4 v160;
    vu0_v4 v170;
    vu0_v4 v180;
    vu0_v4 v190;
    vu0_v4 v1a0;
    f32 r;

    s = *(u8 **)(o + 0x68);
    if (D_L01_001DFB40 & 1) {
        func_003C2F58(o, 1, &v180);
    } else {
        func_003C2F58(o, 2, &v180);
    }
    v160 = v180;
    func_0038CF68(&v170, s + 0x30, func_003824E0(2.0f, 4.0f));
    func_0038D000(&v170, &v170, o + 0xC0);
    vec_add_ab(&v170, &v170, &v180);
    func_L01_0032FC70(o, &v160);
    a.l78 = func_00389598(0x17);
    a.l80 = 0x0000FF9000000260L;
    a.col[0] = a.col[1] = 0x7F103080;
    a.l70 = 0;
    a.l88 = 0x0000008000000048L;
    a.col[2] = a.col[3] = 0x103080;
    b.l78 = func_00389598(0x17);
    *(vu0_q *)&v190 = 0;
    *(vu0_q *)&v1a0 = 0;
    b.l80 = 0x0000FF9000000260L;
    b.l88 = 0x0000008000000048L;
    b.l70 = 0;
    b.col[2] = b.col[3] = 0x103080;
    b.col[0] = b.col[1] = 0x3F103080;
    v190.w = 1.0f;
    v1a0.w = 1.0f;
    r = func_003824E0(0.1f, 0.3f);
    v190.z = r;
    v1a0.z = r + r;
    func_L01_0032FBE0((char *)&a);
    func_L01_0032FBE0((char *)&b);
    if ((func_0013D3E0() & 1) == 0) {
        a.uv[0] = 0.0f;
        a.uv[1] = 0.0f;
        a.uv[2] = 0.0f;
        a.uv[3] = 1.0f;
        a.uv[4] = 1.0f;
        a.uv[5] = 0.0f;
        a.uv[6] = 1.0f;
        a.uv[7] = 1.0f;
        b.uv[0] = 0.0f;
        b.uv[1] = 0.0f;
        b.uv[2] = 0.0f;
        b.uv[3] = 1.0f;
        b.uv[4] = 1.0f;
        b.uv[5] = 0.0f;
        b.uv[6] = 1.0f;
        b.uv[7] = 1.0f;
    } else {
        a.uv[0] = 0.0f;
        a.uv[1] = 1.0f;
        a.uv[2] = 0.0f;
        a.uv[3] = 0.0f;
        a.uv[4] = 1.0f;
        a.uv[5] = 1.0f;
        a.uv[6] = 1.0f;
        a.uv[7] = 0.0f;
        b.uv[0] = 0.0f;
        b.uv[1] = 1.0f;
        b.uv[2] = 0.0f;
        b.uv[3] = 0.0f;
        b.uv[4] = 1.0f;
        b.uv[5] = 1.0f;
        b.uv[6] = 1.0f;
        b.uv[7] = 0.0f;
    }
    vec_sub_ab(&mat[0], &v170, &v160);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    vec_sub_ab(&mat[1], &D_L01_001E29C0, &v160);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    mat[3] = v160;
    a.m[0] = v190;
    b.m[0] = v1a0;
    func_0038CE20(&a.m[1], &a.m[0], -1.0f);
    func_0038CE20(&b.m[1], &b.m[0], -1.0f);
    func_0038D028(&a.m[0], &a.m[0], mat);
    func_0038D028(&a.m[1], &a.m[1], mat);
    func_0038D028(&b.m[0], &b.m[0], mat);
    func_0038D028(&b.m[1], &b.m[1], mat);
    v190.z = v190.z * 0.15f;
    v1a0.z = v190.z + v190.z;
    mat[3] = v170;
    a.m[2] = v190;
    b.m[2] = v1a0;
    func_0038CE20(&a.m[3], &a.m[2], -1.0f);
    func_0038CE20(&b.m[3], &b.m[2], -1.0f);
    func_0038D028(&a.m[2], &a.m[2], mat);
    func_0038D028(&a.m[3], &a.m[3], mat);
    func_0038D028(&b.m[2], &b.m[2], mat);
    func_0038D028(&b.m[3], &b.m[3], mat);
    func_003D2DA0(&a, 0, 0);
    func_003D2DA0(&b, 0, 0);
}
/* localdecomp:end func_L01_0032FF68 */

/* localdecomp:start func_L01_00330390 */
void func_L01_00330390(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_00330390 */

LINKER_REMNANT("asm/levels", func_L01_003303B0);
