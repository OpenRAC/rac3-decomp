/* func_L01_0031BCA0 (Claude wave 14 r66, 2026-11-28). Replaces the earlier draft of this function (Codex wave 6 near miss). */
/* PAL near miss (wave 14 r66, 2026-11-28): 71 instruction diffs at level 01 under the file's own line. Against the
 * Codex wave 6 draft: func_0038CF68 and func_003D2DA0 now use the file's own prototypes (f32 *, f32 *, f32) and
 * (S_003190A8 *, f32 *, s32), as func_L01_0031A820 does; with the draft's (void *) prototypes the block conflicts
 * with the file's declarations and does not compile there. Same code as the draft otherwise (its 71 rows).
 * Left: the first VU0 section stores q (sqc2 vf1, 0xE0) after the camera1 copy in retail, here before it, with
 * the &direction copies (a2, s5) placed earlier in retail; the second half loads the camera for left (vf2) before
 * the camera3 copy (vf1); both UV loops' registers (retail loop 1: counter v0, D_L01_001DC838 v1, D_L01_001DC83C
 * a1, uv[i][0] a0, uv[i][1] a3; loop 2: counter v1, a2/a3 sources, v0/a1 destinations) and their setup order.
 * Tried without effect or worse: copies before vec_add (71/257), left before camera3 (163), [][2] arrays, swapped
 * UV statements, float temps, pointer and flat UV forms, count-down/while loops, a second loop index (73),
 * header store orders (71-98). */
#include "common.h"

/* localdecomp:start func_L01_0031BCA0 */
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colours[4];
    f32 uv[4][2];
    unsigned long zero;
    unsigned long texture;
    unsigned long clamp;
    unsigned long primitive;
} Quad_0031BCA0;
extern vu0_v4 D_L01_001E29C0;
extern s32 D_L01_001DC828;
extern u32 D_L01_001DC830;
extern f32 D_L01_001DC838[];
extern f32 D_L01_001DC83C[];
__asm__(".extern D_L01_001DC828, 4");
__asm__(".extern D_L01_001DC830, 4");
void func_L01_0031BCA0(u8 *moby, u128_t *position) {
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(S_003190A8 *, f32 *, s32);
    vu0_v4 input;
    Quad_0031BCA0 quad;
    vu0_v4 left, right, direction, p, q;
    vu0_v4 tmp, sum;
    vu0_v4 camera1, camera2, camera3;
    u8 *vars;
    s32 i;
    *(u128_t *)&input = *position;
    vars = *(u8 **)(moby + 0x68);
    p = *(vu0_v4 *)(vars + 0x10);
    func_0038CF68((f32 *)&q, (f32 *)(vars + 0x20), -8.0f);
    vec_add_ba(&q, &q, &p);
    vec_copy(&camera1, &D_L01_001E29C0);
    vec_copy(&camera2, &D_L01_001E29C0);
    vec_sub_ba(&direction, &q, &p);
    vec_sub_ba(&left, &q, &camera1);
    vec_sub_ab(&right, &p, &camera2);
    func_0038CE90(&left, &left, &direction);
    func_0038CF68((f32 *)&left, (f32 *)&left, func_L01_00443A18(0.1f, 0.2f) + 0.5f);
    func_0038CE90(&right, &right, &direction);
    func_0038CF68((f32 *)&right, (f32 *)&right, func_L01_00443A18(0.1f, 0.2f) + 0.5f);
    quad.texture = func_00389598(62);
    quad.clamp = 0xFF9000000260;
    quad.primitive = ((unsigned long)D_L01_001DC828 << 32) | 0x48;
    quad.zero = 0;
    quad.colours[0] = quad.colours[1] = quad.colours[2] = quad.colours[3] = D_L01_001DC830;
    for (i = 0; i < 4; i++) {
        quad.uv[i][0] = D_L01_001DC838[i*2];
        quad.uv[i][1] = D_L01_001DC83C[i*2];
    }
    vec_sub_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[0] = tmp;
    vec_add_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[1] = tmp;
    vec_sub_ba(&sum, &p, &right);
    tmp = sum;
    quad.vertices[2] = tmp;
    vec_add_ba(&sum, &p, &right);
    tmp = sum;
    quad.vertices[3] = tmp;
    func_003D2DA0((S_003190A8 *)&quad, 0, 0);
    vec_sub_ba(&direction, &q, &p);
    vec_copy(&camera3, &D_L01_001E29C0);
    vec_sub_ba(&left, &q, &D_L01_001E29C0);
    vec_sub_ab(&right, &p, &camera3);
    func_0038CE90(&left, &left, &direction);
    func_0038CF68((f32 *)&left, (f32 *)&left, func_L01_00443A18(0.05f, 0.15f) + 0.25f);
    func_0038CE90(&right, &right, &direction);
    func_0038CF68((f32 *)&right, (f32 *)&right, func_L01_00443A18(0.05f, 0.15f) + 0.25f);
    quad.texture = func_00389598(63);
    quad.clamp = 0xFF9000000260;
    quad.primitive = ((unsigned long)D_L01_001DC828 << 32) | 0x48;
    quad.zero = 0;
    quad.colours[0] = quad.colours[1] = quad.colours[2] = quad.colours[3] = 0x60DDDDDD;
    for (i = 0; i < 4; i++) {
        quad.uv[i][0] = D_L01_001DC838[i*2];
        quad.uv[i][1] = D_L01_001DC83C[i*2];
    }
    vec_sub_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[0] = tmp;
    vec_add_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[1] = tmp;
    vec_sub_ba(&sum, &p, &right);
    tmp = sum;
    quad.vertices[2] = tmp;
    vec_add_ab(&sum, &p, &right);
    tmp = sum;
    quad.vertices[3] = tmp;
    func_003D2DA0((S_003190A8 *)&quad, 0, 0);
}
/* localdecomp:end func_L01_0031BCA0 */
