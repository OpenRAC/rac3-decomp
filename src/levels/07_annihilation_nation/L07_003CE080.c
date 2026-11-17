#include "common.h"

/* localdecomp:start func_L07_003CE080 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003CE080;
typedef struct { u8 pad[0x18]; void *hit; } Hit_003CE080;
extern Hit_003CE080 D_L07_001E8C00;
typedef struct { u8 pad[0x25C0]; void *hero; } Hero_003CE080;
extern Hero_003CE080 D_001A4BE0;
extern int D_001A71A0[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0044C280_003CE080(void *, void *, void *, f32, s32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);

void func_L07_003CE080(u8 *moby) {
    Vec_003CE080 a, b, dir, trail, point;
    u8 *s = *(u8 **)(moby + 0x68);
    s32 flags = s[0x5F] ? 0x10001 : 1;
    s32 index;
    f32 t;

    func_003C2F58(moby, 0, &a);
    func_003C2F58(moby, 1, &b);
    if (s[0x407] && s[0x409]) {
        index = (s[0x408] + s[0x409] - 1) % 10;
        vec_sub_ba(&trail, s + 0x360 + index * 16, s + 0x2C0 + index * 16);
        vec_sub_ab(&dir, &b, &a);
        t = 1.0f;
        while ((t -= 0.34f) > 0.0f) {
            func_L01_0044C280_003CE080(&point, &trail, &dir, t, 0);
            vec_add_ab(&point, &a, &point);
            if (func_L03_00433C70(moby, &a, &point, flags, 0, 1, 0, (f32)s[0x46], 2.5f) &&
                D_L07_001E8C00.hit == D_001A4BE0.hero) {
                s[0x406]++;
                return;
            }
        }
    }
    if (func_L03_00433C70(moby, &a, &b, flags, 0, 1, 0, (f32)s[0x46], 2.5f) &&
        D_L07_001E8C00.hit == (void *)D_001A71A0[0]) {
        s[0x406]++;
    }
}
/* localdecomp:end func_L07_003CE080 */
