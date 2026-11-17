/* PAL near miss (Codex wave 6): near miss: 36 words differ with the file's flags.
 * Worker's note: 36 diff; build/codex/w270/func_L01_00510F08.02.log; VU0 shared-tail scheduling; contract COMPILE ERROR: later owner extern void func_L01_00510F08(f32) conflicts with retail pointer/pointer/float signature (contract.log)
 */
#include "common.h"
/* localdecomp:start func_L01_00510F08 */
extern D_001A4BE0_t D_001A4BE0;
void func_L01_00510F08(Vec4 *out, Vec4 *in, f32 distance) {
    extern void func_0038CF68(Vec4 *, Vec4 *, f32);
    extern void func_L01_00511588(f32 *dst, f32 *src, f32 scale);
    extern void func_L01_00511508(Vec4 *out, Vec4 *in, f32 z);
    Vec4 axis, plane, copy1, copy2;
    u8 *hero = (u8 *)&D_001A4BE0;
    switch (hero[0x25F4]) {
    case 0:
        out->f[2] = in->f[2] - distance;
        break;
    case 1:
        func_0038CF68(&axis, (Vec4 *)(hero + 0x2C0), -distance);
        func_L01_00511588(plane.f, in->f, 0.0f);
        func_L01_00511508(out, out, 0.0f);
        __asm__(
            "lqc2 $vf1, %3\n\t"
            "lqc2 $vf2, %0\n\t"
            "vadd.xyz $vf2, $vf2, $vf1\n\t"
            "lqc2 $vf1, %2\n\t"
            "sqc2 $vf1, %1\n\t"
            "sqc2 $vf2, %0\n\t"
            "lqc2 $vf1, %0\n\t"
            "lqc2 $vf2, %1\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "+m"(*out), "=m"(copy1)
            : "m"(axis), "m"(plane) : "vf1", "vf2");
        break;
    case 2:
        func_0038CF68(&axis, (Vec4 *)(hero + 0x2E0), distance);
        func_L01_00511588(plane.f, in->f, 0.0f);
        func_L01_00511508(out, out, 0.0f);
        __asm__(
            "lqc2 $vf1, %3\n\t"
            "lqc2 $vf2, %0\n\t"
            "vadd.xyz $vf2, $vf2, $vf1\n\t"
            "lqc2 $vf1, %2\n\t"
            "sqc2 $vf1, %1\n\t"
            "sqc2 $vf2, %0\n\t"
            "lqc2 $vf1, %0\n\t"
            "lqc2 $vf2, %1\n\t"
            "vadd.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "+m"(*out), "=m"(copy2)
            : "m"(axis), "m"(plane) : "vf1", "vf2");
        break;
    }
}
/* localdecomp:end func_L01_00510F08 */
