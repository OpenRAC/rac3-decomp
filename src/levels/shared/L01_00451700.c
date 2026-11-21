#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00451700 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
extern void func_003C5060(s32, Vec4 *, Vec4 *, s32);
extern f32 func_0038D160(f32, f32);
f32 func_L01_00451700(s32 a0, Vec4 *a1, s32 a2) {
    Vec4 t;
    t = *a1;
    func_003C5060(a0, &t, &t, a2);
    return func_0038D160(t.v[0], t.v[1]);
}
/* localdecomp:end func_L01_00451700 */

/* localdecomp:start func_L01_00451738 */
/* func_L01_00451738: from the staged near miss. Retail's abs.s comes after the ld $ra, where
   __builtin_fabsf put it before; include/vu0.h's fabs_asm, the game's fabs, is scheduled as
   retail's. */
f32 func_L01_00451738(s32 a0, Vec4 *a1, s32 a2) {
    Vec4 t;
    f32 r;

    t = *a1;
    r = func_L01_00451700(a0, &t, a2);
    return fabs_asm(r);
}
/* localdecomp:end func_L01_00451738 */

LINKER_REMNANT("asm/levels", func_L01_00451760);

/* localdecomp:start func_L01_00451768 */
extern u8 *D_L01_001DFF00;
extern f32 D_L01_001DFEC0;
extern f32 D_L01_001DFEF0;
extern s32 D_L01_001D6D00;
extern s32 D_L01_001F3F40[];

f32 func_L01_00451768(Vec4 *a0) {
    Vec4 t;
    Vec4 d;
    u8 *map;
    s32 c;

    t = *a0;
    map = D_L01_001DFF00;
    if (map == 0) {
        return 0.0f;
    }
    vec_sub_ab(&d, &t, &D_L01_001DFEC0);
    d.v[0] = d.v[0] / D_L01_001DFEF0;
    d.v[1] = d.v[1] / (&D_L01_001DFEF0)[1];
    if (d.v[0] < 0.0f || d.v[0] > 256.0f || d.v[1] < 0.0f || d.v[1] > 256.0f
        || D_L01_001D6D00 != D_L01_001F3F40[0]) {
        return 1023.0f;
    }
    c = map[((s32)d.v[1] << 8) + (s32)d.v[0]];
    if (c == 0xFF) {
        return 1023.0f;
    }
    return (f32)c * (&D_L01_001DFEF0)[2] + (&D_L01_001DFEC0)[2];
}
/* localdecomp:end func_L01_00451768 */
