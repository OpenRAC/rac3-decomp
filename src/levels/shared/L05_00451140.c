#include "common.h"
#include "vu0.h"

LINKER_REMNANT("asm/levels", func_L05_00451140);

/* localdecomp:start func_L05_00451150 */
extern void func_003C3938(void *, s32, s32);
extern void func_003C29B0(u8 *);
extern void func_003C7DD8(void *);
extern u8 D_L05_001FD890[];
extern u8 *D_L05_001FCE40[];

void func_L05_00451150(u8 *o, s32 id) {

    if (id != -1) {
        func_003C3938(o, 0, 0);
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        *(s16 *)(o + 0xAA) = id;
        o[0x22] = D_L05_001FD890[(s16)id];
        *(u8 **)(o + 0x24) = D_L05_001FCE40[o[0x22]];
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        o[0x61] = 0xFF;
        *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        func_003C3938(o, 0, 0);
        func_003C29B0(o);
        func_003C7DD8(o);
    }
}
/* localdecomp:end func_L05_00451150 */

/* localdecomp:start func_L05_00451228 */
extern void func_0038CE20(void *, void *, f32);
extern float func_L05_00441508(float a, float b, float c);

void func_L05_00451228(vu0_v4 *d, f32 *out, vu0_v4 *p, f32 *q, f32 t, vu0_v4 *r, f32 *s) {
    vu0_v4 tmp;
    vec_sub_ab(&tmp, r, p);
    func_0038CE20(&tmp, &tmp, t);
    vec_add_ba(d, p, &tmp);
    out[2] = func_L05_00441508(q[2], s[2], t);
    out[1] = func_L05_00441508(q[1], s[1], t);
    out[0] = func_L05_00441508(q[0], s[0], t);
}
/* localdecomp:end func_L05_00451228 */
