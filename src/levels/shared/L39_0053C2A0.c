#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern u8 *D_L39_0024BF5C;
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_0053C2A0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L39_0053C1E8(void *, void *, f32);

void func_L39_0053C2A0(u8 *a0) {
    f32 v[4];
    u8 *p = *(u8 **)(a0 + 104);
    func_0038CF68(v, p + 32, 1.0f);
    func_L39_0053C1E8(a0, p, -func_0038CE68(p, v));
}
/* localdecomp:end func_L39_0053C2A0 */
