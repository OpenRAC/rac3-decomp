/* PAL near miss (Codex wave 6): near miss: 105 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: 103 diff in build/codex/w323/3CE080-03.log; fixed GNU-as flags emit lit4 loads for 0.66/0.34 instead of retail immediate constants; VU0 block scheduling and saved registers differ
 */
#include "common.h"
/* localdecomp:start func_L07_003CE080 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003CE080;
typedef struct { u8 pad[24]; void *hit; } Hit_003CE080;
extern Hit_003CE080 D_L07_001E8C00;
extern u8 D_L07_001E8C18[];
typedef struct { u8 pad[0x25C0]; void *hero; } Hero_003CE080;
extern Hero_003CE080 D_001A4BE0;
extern int D_001A71A0[];
void func_L07_003CE080(u8 *moby) {
    extern void func_003C2F58(void *, s32, void *);
    extern void func_L01_0044C280(void *, void *, void *, f32, s32);
    extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
    Vec_003CE080 a, b, dir, trail, point;
    u8 *s = *(u8 **)(moby + 0x68);
    s32 flags = s[0x5F] ? 0x10001 : 1;
    s32 index;
    f32 t;
    func_003C2F58(moby, 0, &a);
    func_003C2F58(moby, 1, &b);
    if (s[0x407] && s[0x409]) {
        index = (s[0x408] + s[0x409] - 1) % 10;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(trail) : "m"(*(Vec_003CE080 *)(s + 0x2C0 + index * 16)), "m"(*(Vec_003CE080 *)(s + 0x360 + index * 16)) : "vf1", "vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(dir) : "m"(b), "m"(a) : "vf1", "vf2");
        for (t = 0.66f; t > 0.0f; t -= 0.34f) {
            func_L01_0044C280(&point, &trail, &dir, t, 0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(point) : "m"(a), "m"(point) : "vf1", "vf2");
            if (func_L03_00433C70(moby, &a, &point, flags, 0, 1, 0, (f32)s[0x46], 2.5f) &&
                D_L07_001E8C00.hit == D_001A4BE0.hero) {
                s[0x406]++;
                return;
            }
        }
    }
    if (func_L03_00433C70(moby, &a, &b, flags, 0, 1, 0, (f32)s[0x46], 2.5f) &&
        *(void **)D_L07_001E8C18 == (void *)D_001A71A0[0]) {
        s[0x406]++;
    }
}
/* localdecomp:end func_L07_003CE080 */
