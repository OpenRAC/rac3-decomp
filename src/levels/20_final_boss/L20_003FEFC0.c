#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L20_003FEFC0 */
extern void func_0038CF68(void *, void *, f32);
extern u8 *D_L05_001EA6D8[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *D_L05_001EA6D8[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);

s32 func_L20_003FEFC0(u8 *arg0, f32 h)
{
    vu0_v4 p;
    vu0_v4 d;
    u8 *v;
    u8 *o;
    s32 r;
    *(vu0_q *)&p = *(vu0_q *)(arg0 + 0x10);
    v = *(u8 **)(arg0 + 0x68);
    p.z += h;
    vec_sub_ba(&d, v + 0x220, &p);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 3.0f);
    vec_add_ab(&d, &d, &p);
    if (func_003D3CB0(&p, &d, 0x10, arg0, 0) == 0) {
        return 1;
    }
    o = D_L05_001EA6D8[0];
    r = 0;
    if (o != 0 && (*(s16 *)(o + 0xAA) == 7682 || o == *(u8 **)(v + 0x230))) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L20_003FEFC0 */
