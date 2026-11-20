#include "common.h"

/* localdecomp:start func_L39_005F0FA0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005F0FA0;
extern V4_005F0FA0 D_L39_0024DE00;
extern V4_005F0FA0 D_L39_0025F760;
extern s32 D_001FE020[];
extern void func_00382580(void *, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);

void func_L39_005F0FA0(void *v, void *d) {
    if (d == 0) {
        d = &D_L39_0024DE00;
    }
    func_00382580(v, 0.5f, 6.0f);
    vec_add_ab(v, v, d);
    if (func_003D3CB0(d, v, 0x82, D_001FE020[0x11], 0) != 0) {
        vec_sub_ba(v, &D_L39_0025F760, d);
        func_0038CE20(v, v, 0.75f);
        vec_add_ba(v, v, d);
    }
}
/* localdecomp:end func_L39_005F0FA0 */

/* localdecomp:start func_L39_005F1058 */
extern void func_L01_0040E6B8(void *, void *, f32);
extern f32 func_L01_0040E548(void *, void *);

s32 func_L39_005F1058(u8 *obj, void *a1, void *p) {
    vu0_v4 tmp;

    if (p == 0) {
        p = &D_L39_0024DE00;
    }
    vec_sub_ba(&tmp, obj + 0x20, p);
    func_0038CE20(&tmp, &tmp, 0.75f);
    func_L01_0040E6B8(&tmp, &tmp, 64.0f);
    vec_add_ba(&tmp, &tmp, p);
    if (900.0f < func_L01_0040E548(a1, &tmp)) {
        return 0;
    }
    return func_003D3CB0(a1, &tmp, 0x82, *(s32 *)(obj + 0x1C), 0);
}
/* localdecomp:end func_L39_005F1058 */
