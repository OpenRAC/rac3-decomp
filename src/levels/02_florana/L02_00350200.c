#include "common.h"
/* localdecomp:start func_L02_00350200 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern u8 D_001A4CC0[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L02_00350200(u8 *a0, s32 a1)
{
    u8 *v;
    V4 a;
    V4 b;
    V4 d;
    f32 ang;
    f32 p;
    f32 rate;
    f32 rate2;

    v = *(u8 **)(a0 + 0x68);
    rate = 0.04f;
    rate2 = 0.3f;
    *(u128_t *)&a = *(u128_t *)D_001A4CC0;
    if (a1) {
        *(u128_t *)&b = *(u128_t *)(a0 + 0x10);
        b.z += 2.0f;
        vec_sub_ab(&d, &a, &b);
        ang = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(a0 + 0xF8));
        p = -func_0038D160(func_0038CED8(&d), d.z);
        if (ang > 1.5707964f) {
            ang = 1.5707964f;
        } else if (ang < -1.5707964f) {
            ang = -1.5707964f;
        }
        if (p > 0.5235988f) {
            p = 0.5235988f;
        } else if (p < -0.5235988f) {
            p = -0.5235988f;
        }
        *(f32 *)(v + 0x2A4) = p;
        *(f32 *)(v + 0x2A8) = ang * 0.6f;
        *(f32 *)(v + 0x9A8) = ang * 0.4f;
    }
    func_L01_0044E850(a0, v + 0x940, 3, rate * 1.44f, rate2 * 1.44f);
}
/* localdecomp:end func_L02_00350200 */
