#include "common.h"
#include "vu0.h"

/* declared by functions of L01_00450F00.c, which this file was cut from */
extern void func_0038D000(void *, void *, void *);

/* localdecomp:start func_L01_00450F60 */
#include "vu0.h"
extern s32 D_L01_001D673C;
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);

f32 func_L01_00450F60(u8 *a0, u8 *a1, s32 a2) {
    f32 v[4];
    f32 m[4];
    f32 d;

    if (D_L01_001D673C == 0) {
        return func_0038D160(*(f32 *)(a1 + 8), func_0038CED8((f32 *)a1));
    } else if (a2 != 0) {
        func_0038D000(v, a1, (void *)a2);
        return func_0038D160(v[2], func_0038CED8(v));
    } else {
        func_003C5180(a0 + 0x10, m, 1);
        func_0038CF68(v, a1, 1.0f);
        d = func_0038CE68(v, m);
        return func_0038D160(d, sqrt_asm(1.0f - d));
    }
}
/* localdecomp:end func_L01_00450F60 */
