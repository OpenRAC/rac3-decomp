#include "common.h"

typedef int u128_3B7390 __attribute__((mode(TI)));

/* localdecomp:start func_L30_003B91E0 */
#include "vu0.h"
extern s32 D_L30_001DED98;
extern f32 D_L30_001DED94;
extern f32 D_L30_001DED90;
extern s32 func_0038CAD0(void *);
extern void func_003C2880(u8 *);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034CB68_003B91E0(u8 *, f32, f32, s32, s32, s32, u128_3B7390 *, s32);

void func_L30_003B91E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_0038CAD0(s + 0x10) != 0) {
        func_003C2880(a0);
        return;
    }
    vec_add_ba(a0 + 0x10, a0 + 0x10, s);
    func_L30_0034CB68_003B91E0(a0, 1.0f,
        func_003C4088(D_L30_001DED94, D_L30_001DED90,
            func_L03_0034B440(1, 0, 0, (f32)*(s32 *)(s + 0x10), (f32)D_L30_001DED98, 1.0f)),
        (s32)s, 0, -1, (u128_3B7390 *)(a0 + 0x10), 0);
}
/* localdecomp:end func_L30_003B91E0 */
