/* PAL near miss (Codex wave 7): near miss: 14 words differ with the file's flags.
 * Worker's note: 14 diff; build/codex/w344/func_L01_0035C6F0-best.log; full VU sequence blocks cannot interleave retail EE scheduling; existing vu0.h j helpers fail with fixed file flags (a2.log)
 */
#include "common.h"
/* localdecomp:start func_L01_0035C6F0 */
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colors[4];
    f32 uv[8];
    u8 pad70[0x20];
} Draw_0035C6F0;
extern vu0_v4 D_L01_001E29C0[];
void func_L01_0035C6F0(u8 *bullet) {
    extern f32 func_003824E0(f32 low, f32 high);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, void *, s32);
    vu0_v4 velocity, delta, side, start;
    Draw_0035C6F0 draw;
    vu0_v4 offset;
    s32 i;
    u8 *vars = *(u8 **)(bullet + 0x68);
    f32 width = func_003824E0(0.45f, 0.7f);
    f32 length = func_003824E0(4.0f, 4.5f);
    func_0038CF68(&velocity, vars, 1.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(D_L01_001E29C0[0]), "m"(*(vu0_v4 *)(bullet + 0x10)) : "vf1", "vf2");
    func_0038CE90(&side, &delta, &velocity);
    func_0038CF68(&side, &side, width);
    func_0038CF68(&velocity, &velocity, length);
    velocity.w = 0.0f; delta.w = 0.0f; side.w = 0.0f;
    func_003D93B0(&draw, 0x3F, 0, 0x80);
    draw.uv[0] = 0.0f; draw.uv[1] = 0.0f; draw.uv[2] = 0.0f; draw.uv[3] = 1.0f;
    draw.uv[4] = 1.0f; draw.uv[5] = 0.0f; draw.uv[6] = 1.0f; draw.uv[7] = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&draw.vertices[i]);
        draw.vertices[i].x = i < 2 ? 0.0f : 1.0f;
        draw.vertices[i].y = 0.0f;
        draw.vertices[i].z = i & 1 ? 1.0f : -1.0f;
        draw.vertices[i].w = 1.0f;
        draw.colors[i] = 0x7FFFFFFF;
    }
    func_0038CF68(&offset, vars, -3.7f);
    __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(start) : "m"(offset), "m"(*(vu0_v4 *)(bullet + 0x10)) : "vf1", "vf2");
    start.w = 1.0f;
    func_003D2DA0(&draw, &velocity, 0);
}
/* localdecomp:end func_L01_0035C6F0 */
