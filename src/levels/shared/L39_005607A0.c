#include "common.h"

/* localdecomp:start func_L39_005607A0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 f[4];
} __attribute__((aligned(16))) V_005607A0;
extern void func_0038CE20(void *out, void *in, f32 s);
extern f32 func_0038CE68(void *a, void *b);
extern void func_0038CE90(void *out, void *a, void *b);
void func_L39_005607A0(void *m, void *n) {
    V_005607A0 x;
    V_005607A0 y;
    V_005607A0 d;
    f32 t;

    *(u128_t *)&x = 0;
    *(u128_t *)&y = 0;
    x.f[0] = 1.0f;
    y.f[1] = 1.0f;
    func_0038CE20(&d, n, -1.0f);
    t = func_0038CE68(&x, &d);
    if (fabs_asm(t) > 0.98f) {
        func_0038CE90(m, &d, &y);
    } else {
        func_0038CE90(m, &d, &x);
    }
    func_0038CE90((u8 *)m + 16, m, &d);
    *(u128_t *)((u8 *)m + 32) = *(u128_t *)&d;
}
/* localdecomp:end func_L39_005607A0 */

INCLUDE_ASM("asm/levels", func_L39_00560868);

INCLUDE_ASM("asm/levels", func_L39_00560FC0);
