/* PAL near miss (Codex wave 10): near miss: 169 words differ with the file's flags.
 * Worker's note: 134/193 positional word diff with experimental --divs 2,2,2 (check-04.log); register allocation and scheduling remain, sqrt_asm f1 versus retail f12 and atomic VU add/sub cannot interleave ordinary EE argument setup. No metadata row established as matching.
 */
#include "common.h"
/* localdecomp:start func_L01_003693F8 */
#include "vu0.h"
void func_L01_003693F8(void *ptr) {
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_003A9440(s32, s32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern void func_003D9508(s128 *, s32, u32, s32, f32, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    f32 point[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    Moby_003691D8 *m = ptr;
    s128 *position;
    f32 distance, fade, scale, size;
    s32 count, life;
    u32 color, c1, c2, c3;
    distance = func_L01_0040E548(D_L01_001E2A40, &m->pos);
    if (distance > 1600.0f) return;
    if (distance > 1024.0f) {
        distance = sqrt_asm(distance);
        fade = (distance - 32.0f) * 0.125f;
    }
    else fade = 0.0f;
    func_003A9440(71, 0x53001);
    scale = m->scale / m->cls->scale / 1.5f * 1.4f;
    c1 = func_0038DBD8(0x7FFF2020, 0x7F000000, fade);
    size = scale * 1.25f;
    position = &m->pos;
    func_003D9508(position, 0x39, c1, 1, size, 0.05f, func_00382538());
    c2 = func_0038DBD8(0x4FFF2020, 0x7F000000, fade);
    func_003D9508(position, 0x39, c2, 1, size, 0.05f, func_00382538());
    c3 = func_0038DBD8(0x7F503040, 0x7F000000, fade);
    func_003D9508(position, 0x31, c3, 1, size, 0.05f, func_00382538());
    count = (s32)func_L01_00443A18(2.0f, 5.0f);
    func_00382580(point, scale * 0.8f, scale);
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tlqc2 $vf2, %2\n\tsqc2 $vf1, %0\n\tlqc2 $vf1, %0\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %1"
        : "+m"(*(s128 *)point), "=m"(*(s128 *)velocity)
        : "m"(m->pos) : "vf1", "vf2");
    m = (Moby_003691D8 *)velocity;
    func_0038CF68(m, m, 0.0150000006f);
    color = func_0038DBD8(0x00FF2020, 0xFF000000, fade);
    life = (func_00382498(55, 70) * 5 + 2) / 6;
    func_L01_004713C8(point, m, life, color, count, 0, 95, 6,
        func_003824E0(0.025f, 0.04f) * 210000.0f, 25200.0f, 0.0f);
}
/* localdecomp:end func_L01_003693F8 */
