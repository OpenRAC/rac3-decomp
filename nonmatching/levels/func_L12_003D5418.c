/* Near miss (b10-u6): 2 of 86 words differ: in the last call to func_L01_00448690 retail sets $f13 (the scale) before $f12 (the
 * angle, a copy of func_0038D160's result in $f0); here $f12 comes first. Everything else is retail's.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L12_003D5418 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D5418;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L01_00448690(void *, s32, f32, f32);

void func_L12_003D5418(u8 *o, u8 *p, V4_003D5418 *at, f32 s) {
    V4_003D5418 pos;
    V4_003D5418 d;
    f32 h;
    f32 r;
    u8 *m;

    pos = *at;
    h = s * 1.3f;
    vec_sub_ba(&d, &pos, o + 0x10);
    if (o[0x20] == 3) {
        h *= 1.5f;
        r = 1.5707964f;
    } else {
        r = -func_0038D160(func_0038CED8(&d), d.z);
        if (o[0x20] == 2) {
            h *= 0.75f;
        }
    }
    func_L01_00448690(o + 0xF4, 0, r, h);
    if (o[0x20] == 3) {
        s *= 0.25f;
    } else if (o[0x20] == 2) {
        s *= 0.5f;
    }
    m = o + 0xC0;
    r = func_0038D160(d.x, d.y);
    func_L01_00448690(o + 0xF8, 0, r, s);
    func_0038D308(m, o + 0xF0);
    func_0038CE20(p, m, *(f32 *)(p + 0x38));
}
/* localdecomp:end func_L12_003D5418 */
