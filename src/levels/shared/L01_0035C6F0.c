#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

typedef struct {
    s32 a[12];
} S_0035E418;

/* localdecomp:start func_L01_0035C6F0 */
#include "vu0.h"

typedef struct {
    vu0_v4 q[4];
    s32 k[4];
    f32 e0[4];
    f32 f0[4];
    u8 pad[0x20];
} Quad_0035C6F0;

extern vu0_v4 D_L01_001E29C0;
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);

/* n60_tracer: the N60 Storm bullet's tracer, a quad from the bullet back along its velocity */
void func_L01_0035C6F0(u8 *bullet)
{
    u8 *vars = *(u8 **)(bullet + 0x68);
    vu0_v4 mat[4];
    Quad_0035C6F0 quad;
    vu0_v4 t;
    f32 width;
    f32 length;
    s32 i;

    width = func_003824E0(0.45f, 0.7f);
    length = func_003824E0(4.0f, 4.5f);
    func_0038CF68(&mat[0], vars, 1.0f);
    vec_sub_ba(&mat[1], &D_L01_001E29C0, bullet + 0x10);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], width);
    func_0038CF68(&mat[0], &mat[0], length);
    mat[0].w = 0.0f;
    mat[1].w = 0.0f;
    mat[2].w = 0.0f;
    func_003D93B0(&quad, 0x3F, 0, 0x80);
    quad.e0[0] = 0.0f;
    quad.e0[1] = 0.0f;
    quad.e0[2] = 0.0f;
    quad.e0[3] = 1.0f;
    quad.f0[0] = 1.0f;
    quad.f0[1] = 0.0f;
    quad.f0[2] = 1.0f;
    quad.f0[3] = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&quad.q[i]);
        quad.q[i].x = (i < 2) ? 0.0f : 1.0f;
        quad.q[i].y = 0.0f;
        quad.q[i].z = (i & 1) ? 1.0f : -1.0f;
        quad.q[i].w = 1.0f;
        quad.k[i] = 0x7FFFFFFF;
    }
    func_0038CF68(&t, vars, -3.7f);
    vec_add_ba(&mat[3], &t, bullet + 0x10);
    mat[3].w = 1.0f;
    func_003D2DA0(&quad, mat, 0);
}
/* localdecomp:end func_L01_0035C6F0 */
