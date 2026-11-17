#include "common.h"

/* localdecomp:start func_L16_003D6BA0 */
#include "vu0.h"
extern f32 D_L16_001DEC98;
extern f32 D_L16_001DEC9C;
extern f32 D_L16_001DECA0;
__asm__(".extern D_L16_001DEC98, 4");
__asm__(".extern D_L16_001DEC9C, 4");
__asm__(".extern D_L16_001DECA0, 4");
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

void func_L16_003D6BA0(u8 *self, s32 unused, vu0_v4 *pos, f32 *outA, f32 *outB) {
    vu0_v4 p = *pos;
    vu0_v4 d;
    vec_sub_ab(&d, self + 0x10, &p);
    if (D_L16_001DEC98 < func_0038CEA8(&d)) {
        func_0038CF68(&d, &d, D_L16_001DEC98);
    }
    *outA = func_0038CE68(&d, self + 0xD0) * D_L16_001DEC9C;
    *outB = func_0038CE68(&d, self + 0xC0) * D_L16_001DECA0;
}
/* localdecomp:end func_L16_003D6BA0 */
