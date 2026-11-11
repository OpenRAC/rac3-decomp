#include "common.h"
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L23_00406D00 */
extern f32 func_003824E0(f32, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                              f32 f0, f32 f1, f32 f2);
extern u128_t D_L23_001DEF80;
extern u128_t D_L23_001DEF70;

void func_L23_00406D00(void) {
    f32 r;

    r = func_003824E0(0.01f, 0.03f);
    func_L01_0040A8C0(&D_L23_001DEF80, &D_L23_001DEF70, 0x15, 1, 0x80403080, 0x80403080, 0x80403080, 0x80403080,
                      r, 1.0f, 0.0f);
}
/* localdecomp:end func_L23_00406D00 */
