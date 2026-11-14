#include "common.h"

INCLUDE_ASM("asm/levels", func_L08_0039C930);

INCLUDE_ASM("asm/levels", func_L08_0039CB60);

/* localdecomp:start func_L08_0039CF78 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0046B288(f32, f32, void *, s32, s32, s32);

void func_L08_0039CF78(u8 *a0) {
    f32 v[4];
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 n;
    a = func_00382538();
    b = func_003824E0(0.0f, 1.0f);
    c = func_003824E0(0.0f, 1.5f);
    d = func_003824E0(1.5f, 7.0f);
    n = func_00382498(0x8C, 0xE6);
    v[0] = func_0038D098(a) * b;
    v[1] = func_0038D0B0(a) * b;
    v[2] = 0.0f;
    vec_add_ba(v, v, a0 + 0x10);
    v[2] = v[2] + 0.025f;
    func_L01_0046B288(c, d, v, 0x38007040, 0x4040, n);
}
/* localdecomp:end func_L08_0039CF78 */
