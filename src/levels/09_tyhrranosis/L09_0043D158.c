#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L09_0043D158);

/* localdecomp:start func_L09_0043D590 */
extern f32 D_L09_001D6C3C;
extern f32 D_L09_001D6C2C;
extern f32 D_L09_001D6C30;
extern s32 D_001D6C24;
extern s32 D_001D6C28;
extern s32 D_L09_001D6C34;
extern s32 D_L09_001D6C38;
__asm__(".extern D_L09_001D6C3C, 4");
__asm__(".extern D_L09_001D6C2C, 4");
__asm__(".extern D_L09_001D6C30, 4");
__asm__(".extern D_001D6C24, 4");
__asm__(".extern D_001D6C28, 4");
__asm__(".extern D_L09_001D6C34, 4");
__asm__(".extern D_L09_001D6C38, 4");
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L09_0043D590(u8 *a0) {
    f32 v[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 n;
    a = func_00382538();
    b = func_003824E0(0.0f, D_L09_001D6C3C);
    c = func_003824E0(0.0f, D_L09_001D6C2C);
    d = func_003824E0(D_L09_001D6C2C, D_L09_001D6C30);
    n = func_00382498(D_L09_001D6C34, D_L09_001D6C38);
    v[0] = func_0038D098(a) * b;
    v[1] = func_0038D0B0(a) * b;
    v[2] = 0.0f;
    vec_add_ab(v, v, a0);
    v[2] = v[2] + 0.025f;
    func_L01_0046B288(c, d, v, D_001D6C24, D_001D6C28, n);
}
/* localdecomp:end func_L09_0043D590 */
