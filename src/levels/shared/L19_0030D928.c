#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_0030D928 */
#include "vu0.h"

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 D_L19_001DC610;
__asm__(".extern D_L19_001DC610, 4");

void func_L19_0030D928(u8 *a0, void *front, void *back) {
    vu0_v4 dir;
    vu0_v4 rev;

    func_0038CF68(&dir, a0 + 0xC0, D_L19_001DC610);
    func_0038CE20(&rev, &dir, -1.0f);
    vec_add_ba(front, &dir, a0 + 0x10);
    vec_add_ab(back, &rev, a0 + 0x10);
}
/* localdecomp:end func_L19_0030D928 */
