#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00301F98 */
extern vu0_v4 D_L01_0026EC90[];
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
void func_L01_00301F98(u8 *m, u8 *out, s32 idx) {
    vu0_v4 v;
    u8 *pv;
    u8 *t;
    pv = *(u8 **)(m + 104);
    func_0038D890(&v, &D_L01_0026EC90[idx], pv + 32, *(f32 *)(pv + 44));
    t = *(u8 **)(pv + (idx << 2) + 48);

    if (t != 0 && m[32] == 2)
        func_0038CF68(&v, &v, *(f32 *)(t + 40));
    vec_add_ba(out, pv + 16, &v);
    *(f32 *)(out + 8) += *(f32 *)pv;
}
/* localdecomp:end func_L01_00301F98 */
