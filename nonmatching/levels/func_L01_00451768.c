/* PAL near miss (b8-s3): 4 words differ. Needs `-mvu0-use-vf0-vf2 @ps2as` (S mode) for its file (the other two blocks of
 * L01_00451700.c were not rechecked under it) and the divs_nops row `func_L01_00451768 2 2`. With those, the only
 * difference is which of the two `lui` (hi of D_L01_001F3F40, hi of D_L01_001D6D00) comes first and the register of
 * the compare (retail: lui $v0 = 0x1f, lui $a0 = 0x1d, lw $a0, lw $v1, bne $a0, $v1; here the two are swapped).
 * Tried: operand order, [0] forms, pointers, locals.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00451768 */
extern u8 *D_L01_001DFF00;
extern f32 D_L01_001DFEC0;
extern f32 D_L01_001DFEF0;
extern s32 D_L01_001D6D00[];
extern s32 D_L01_001F3F40;

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
        || D_L01_001F3F40 != D_L01_001D6D00[0]) {
        return 1023.0f;
    }
    c = map[((s32)d.v[1] << 8) + (s32)d.v[0]];
    if (c == 0xFF) {
        return 1023.0f;
    }
    return (f32)c * (&D_L01_001DFEF0)[2] + (&D_L01_001DFEC0)[2];
}
