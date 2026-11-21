/* functional: high. Draft verified vector-op by vector-op against asm (sub/add operand order, length-zero guards, i==1/2/count-2 colour rules). Inline asm only lqc2/vsub/vadd/sqc2 (VU0). */
#include "common.h"
/* localdecomp:start func_L01_00380CE0 */
typedef int Q_00380CE0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00380CE0;
typedef struct {
    V4_00380CE0 position[4];
    s32 color[4];
    V4_00380CE0 uv[2];
    unsigned long texture[4];
} Packet_00380CE0;
extern s32 D_001DDC6C_sda;
extern s32 D_001DDC70_sda;
extern s32 D_001DDC50_sda;
extern f32 D_001DDC54_sda;
extern f32 D_001DDC44_sda;
extern V4_00380CE0 D_L01_001E29C0_00380CE0;
void func_L01_00380CE0(V4_00380CE0 *points, s32 alpha, s32 glow_alpha, s32 count, s32 glow_color, f32 unused, f32 width, f32 inset)
{
    extern long func_00389598(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE20(Q_00380CE0 *, Q_00380CE0 *, f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_003A9440(s32, long);
    Packet_00380CE0 core, glow;
    V4_00380CE0 normal, wide;
    V4_00380CE0 radial, edge;
    V4_00380CE0 start, end;
    V4_00380CE0 radial_start, radial_end;
    V4_00380CE0 camera_to_start, edge_inset;
    V4_00380CE0 initial_radial, copy_point, copy_camera, other_camera;
    V4_00380CE0 copy;
    s32 i, last;
    s32 core_color, outer_color;
    unsigned long texture;
    f32 zero;
    V4_00380CE0 *point;
    texture = func_00389598(D_001DDC6C_sda);
    core_color = D_001DDC50_sda | (alpha << 24);
    core.texture[0] = 0;
    core.texture[1] = texture;
    core.texture[2] = 0xFF9000000260UL;
    core.texture[3] = 0x8000000048UL;
    core.color[0] = core.color[1] = core.color[2] = core.color[3] = core_color;
    glow.texture[1] = func_00389598(D_001DDC70_sda);
    glow.texture[0] = core.texture[0];
    glow.texture[2] = core.texture[2];
    glow.texture[3] = core.texture[3];
    glow.uv[0].x = 0.0f;
    zero = glow.uv[0].x;
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&copy)) : "m"(*(V4_00380CE0 *)(points)) : "vf1");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&initial_radial)) : "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)), "m"(*(V4_00380CE0 *)(&copy)) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&edge)) : "m"(*(V4_00380CE0 *)(points + 1)), "m"(*(V4_00380CE0 *)(points)) : "vf1", "vf2");
    outer_color = glow_color | (glow_alpha << 24);
    glow.color[0] = glow.color[1] = glow.color[2] = glow.color[3] = outer_color;
    glow.uv[0].y = 0.0f;
    glow.uv[0].z = 0.0f;
    glow.uv[0].w = 1.0f;
    glow.uv[1].x = 1.0f;
    glow.uv[1].y = 0.0f;
    glow.uv[1].z = 1.0f;
    glow.uv[1].w = 1.0f;
    core.uv[0].x = D_001DDC54_sda + glow.uv[0].x;
    core.uv[0].y = zero;
    core.uv[0].z = core.uv[0].x;
    core.uv[0].w = 1.0f;
    core.uv[1].x = D_001DDC54_sda + 1.0f;
    core.uv[1].y = zero;
    core.uv[1].z = core.uv[1].x;
    core.uv[1].w = 1.0f;
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&radial)) : "m"(*(V4_00380CE0 *)(&initial_radial)) : "vf1");
    func_0038CE90(&normal, &edge, &radial);
    { f32 length = func_0038CEA8(&normal);
    if (length != zero) length = 1.0f / length;
    func_0038CE20((Q_00380CE0 *)&normal, (Q_00380CE0 *)&normal, D_001DDC44_sda * length); }
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&core.position[0])) : "m"(*(V4_00380CE0 *)(&normal)), "m"(*(V4_00380CE0 *)(points)) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&core.position[1])) : "m"(*(V4_00380CE0 *)(points)), "m"(*(V4_00380CE0 *)(&normal)) : "vf1", "vf2");
    last = count - 1;
    for (i = 1, point = points + 1; i < last; i++, point++) {
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&copy)) : "m"(*(V4_00380CE0 *)(point)) : "vf1");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&copy)) : "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)), "m"(*(V4_00380CE0 *)(&copy)) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&copy_point)) : "m"(*(V4_00380CE0 *)(point)) : "vf1");
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&radial)) : "m"(*(V4_00380CE0 *)(&copy)) : "vf1");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&edge)) : "m"(*(V4_00380CE0 *)(point + 1)), "m"(*(V4_00380CE0 *)(&copy_point)) : "vf1", "vf2");
        func_0038CE90(&normal, &edge, &radial);
        { f32 length = func_0038CEA8(&normal);
        if (length != zero) length = 1.0f / length;
        func_0038CE20((Q_00380CE0 *)&normal, (Q_00380CE0 *)&normal, D_001DDC44_sda * length); }
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&core.position[2])) : "m"(*(V4_00380CE0 *)(&normal)), "m"(*(V4_00380CE0 *)(point)) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&core.position[3])) : "m"(*(V4_00380CE0 *)(point)), "m"(*(V4_00380CE0 *)(&normal)) : "vf1", "vf2");
        if (i == 1) core.color[0] = core.color[1] = D_001DDC50_sda;
        else if (i == count - 2) core.color[2] = core.color[3] = D_001DDC50_sda;
        else if (i == 2) core.color[1] = core.color[0] = core_color;
        func_003D2DA0(&core, 0, 0);
        core.position[0] = core.position[2];
        core.position[1] = core.position[3];
    }
    for (i = 0, point = points; i < last; i++, point++) {
        f32 length, length_end;
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&copy)) : "m"(*(V4_00380CE0 *)(point)) : "vf1");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&copy)) : "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)), "m"(*(V4_00380CE0 *)(&copy)) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&copy_camera)) : "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)) : "vf1");
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&radial_start)) : "m"(*(V4_00380CE0 *)(&copy)) : "vf1");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&radial_end)) : "m"(*(V4_00380CE0 *)(point + 1)), "m"(*(V4_00380CE0 *)(&copy_camera)) : "vf1", "vf2");
        length = func_0038CEA8(&radial_start);
        length_end = func_0038CEA8(&radial_end);
        if (length_end < length) {
            if (length_end == 0.0f) radial_end = radial_start;
            else func_0038CE20((Q_00380CE0 *)&radial_end, (Q_00380CE0 *)&radial_end, length / length_end);
        } else {
            if (length == 0.0f) radial_start = radial_end;
            else func_0038CE20((Q_00380CE0 *)&radial_start, (Q_00380CE0 *)&radial_start, length_end / length);
        }
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&start)) : "m"(*(V4_00380CE0 *)(&radial_start)), "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&end)) : "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)), "m"(*(V4_00380CE0 *)(&radial_end)) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&edge)) : "m"(*(V4_00380CE0 *)(&start)), "m"(*(V4_00380CE0 *)(&end)) : "vf1", "vf2");
        func_0038CE20((Q_00380CE0 *)&edge_inset, (Q_00380CE0 *)&edge, inset);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&start)) : "m"(*(V4_00380CE0 *)(&edge_inset)), "m"(*(V4_00380CE0 *)(&start)) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*(V4_00380CE0 *)(&other_camera)) : "m"(*(V4_00380CE0 *)(&D_L01_001E29C0_00380CE0)) : "vf1");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&end)) : "m"(*(V4_00380CE0 *)(&edge_inset)), "m"(*(V4_00380CE0 *)(&end)) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&camera_to_start)) : "m"(*(V4_00380CE0 *)(&other_camera)), "m"(*(V4_00380CE0 *)(&start)) : "vf1", "vf2");
        func_0038CE90(&normal, &camera_to_start, &edge);
        length = func_0038CEA8(&normal);
        if (length != 0.0f) length = 1.0f / length;
        func_0038CE20((Q_00380CE0 *)&wide, (Q_00380CE0 *)&normal, width * length);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&glow.position[0])) : "m"(*(V4_00380CE0 *)(&wide)), "m"(*(V4_00380CE0 *)(&start)) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&glow.position[1])) : "m"(*(V4_00380CE0 *)(&wide)), "m"(*(V4_00380CE0 *)(&start)) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&glow.position[2])) : "m"(*(V4_00380CE0 *)(&wide)), "m"(*(V4_00380CE0 *)(&end)) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(V4_00380CE0 *)(&glow.position[3])) : "m"(*(V4_00380CE0 *)(&end)), "m"(*(V4_00380CE0 *)(&wide)) : "vf1", "vf2");
        if (i == 0) glow.color[1] = glow.color[0] = glow_color;
        else if (i == count - 2) glow.color[3] = glow.color[2] = glow_color;
        else if (i == 1) glow.color[1] = glow.color[0] = outer_color;
        func_003D2DA0(&glow, 0, 0);
    }
    func_003A9440(0x47, 0x5360b);
}
/* localdecomp:end func_L01_00380CE0 */
