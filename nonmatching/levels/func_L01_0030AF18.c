/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Draft reconstructed from PAL; compile blocked by exact func_0038CF68 signature using S_0030CD20, defined later in owner at func_L01_0030CFC0. Needs moving existing type/declaration earlier; no incompatible prototype or typedef redefinition attempted. Logs ...
 */
#include "common.h"
/* localdecomp:start func_L01_0030AF18 */
#include "vu0.h"
typedef struct {
    vu0_v4 point[4];
    u32 color[4];
    f32 uv[8];
    long tag70, texture, tag80, mode;
} Strip_0030AF18;
extern vu0_v4 D_L01_001E29C0;
void func_L01_0030AF18(s32 unused, s32 alpha, vu0_v4 *points, s32 count) {
    extern void func_L01_0030AED8(vu0_v4 *, s32);
    extern void func_L01_0030AB70(u8 *);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern u32 func_0038DBD8(u32, u32, f32);
    Strip_0030AF18 a, b;
    vu0_v4 matrix[4];
    vu0_v4 small, large;
    s32 i;
    f32 t, u;
    a.texture = func_00389598(43);
    a.tag80 = 0xFF9000000260L;
    a.mode = ((long)alpha << 32) | 0x68;
    a.color[0] = a.color[1] = 0x7F0072FF;
    a.tag70 = 0;
    b.texture = func_00389598(43);
    b.tag80 = 0xFF9000000260L;
    b.mode = ((long)(alpha / 3) << 32) | 0x68;
    b.color[0] = b.color[1] = 0x400072FF;
    b.tag70 = 0;
    *(vu0_q *)&small = 0;
    *(vu0_q *)&large = 0;
    small.w = large.w = 1.0f;
    small.z = func_003824E0(0.005f, 0.085f) * 2.0f;
    large.z = func_003824E0(0.1f, 0.25f) * 2.0f;
    func_L01_0030AED8(points, count);
    func_L01_0030AB70((u8 *)&a);
    func_L01_0030AB70((u8 *)&b);
    a.uv[0]=0; a.uv[1]=0; a.uv[2]=0; a.uv[3]=1;
    a.uv[4]=1; a.uv[5]=0; a.uv[6]=1; a.uv[7]=1;
    b.uv[0]=0; b.uv[1]=0; b.uv[2]=0; b.uv[3]=1;
    b.uv[4]=0.33f; b.uv[5]=0; b.uv[6]=0.33f; b.uv[7]=1;
    vec_sub_ba(&matrix[0], &points[1], &points[0]);
    func_0038CF68((S_0030CD20 *)&matrix[0], (S_0030CD20 *)&matrix[0], 1.0f);
    vec_sub_ab(&matrix[1], &D_L01_001E29C0, &points[0]);
    func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
    func_0038CF68((S_0030CD20 *)&matrix[2], (S_0030CD20 *)&matrix[2], 1.0f);
    func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
    *(vu0_q *)&matrix[3] = *(vu0_q *)&points[0];
    *(vu0_q *)&a.point[0] = *(vu0_q *)&small;
    func_0038CE20((f32 *)&a.point[1], (f32 *)&a.point[0], -1.0f);
    func_0038D028(&a.point[0], &a.point[0], matrix);
    func_0038D028(&a.point[1], &a.point[1], matrix);
    *(vu0_q *)&b.point[0] = *(vu0_q *)&large;
    func_0038CE20((f32 *)&b.point[1], (f32 *)&b.point[0], -1.0f);
    func_0038D028(&b.point[0], &b.point[0], matrix);
    func_0038D028(&b.point[1], &b.point[1], matrix);
    for (i=1; i<count-1; i++) {
        *(vu0_q *)&a.point[2] = *(vu0_q *)&small;
        func_0038CE20((f32 *)&a.point[3], (f32 *)&a.point[2], -1.0f);
        *(vu0_q *)&b.point[2] = *(vu0_q *)&large;
        func_0038CE20((f32 *)&b.point[3], (f32 *)&b.point[2], -1.0f);
        vec_sub_ba(&matrix[0], &points[i+1], &points[i]);
        func_0038CF68((S_0030CD20 *)&matrix[0], (S_0030CD20 *)&matrix[0], 1.0f);
        vec_sub_ba(&matrix[1], &D_L01_001E29C0, &points[i]);
        func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
        func_0038CF68((S_0030CD20 *)&matrix[2], (S_0030CD20 *)&matrix[2], 1.0f);
        func_0038CE90(&matrix[1], &matrix[0], &matrix[2]);
        *(vu0_q *)&matrix[3] = *(vu0_q *)&points[i];
        func_0038D028(&a.point[2], &a.point[2], matrix);
        func_0038D028(&a.point[3], &a.point[3], matrix);
        func_0038D028(&b.point[2], &b.point[2], matrix);
        func_0038D028(&b.point[3], &b.point[3], matrix);
        t=(f32)i/((f32)count-2.0f);
        a.color[2]=a.color[3]=func_0038DBD8(0x7F0072FF, 0x7FDDB973, t);
        b.color[2]=b.color[3]=func_0038DBD8(0x7F0072FF, 0x40FF0000, t);
        func_003D2DA0((S_35A8A0 *)&a, 0, 0);
        func_003D2DA0((S_35A8A0 *)&b, 0, 0);
        u=(f32)i*0.33f;
        if (u>=1.0f) u-=1.0f;
        *(vu0_q *)&a.point[0]=*(vu0_q *)&a.point[2];
        *(vu0_q *)&a.point[1]=*(vu0_q *)&a.point[3];
        *(vu0_q *)&b.point[0]=*(vu0_q *)&b.point[2];
        *(vu0_q *)&b.point[1]=*(vu0_q *)&b.point[3];
        a.color[0]=a.color[1]=a.color[2];
        b.color[0]=b.color[1]=b.color[2];
        b.uv[0]=b.uv[2]=u;
        b.uv[4]=b.uv[6]=u+0.33f;
    }
}
/* localdecomp:end func_L01_0030AF18 */
