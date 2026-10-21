#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00443AC0);

INCLUDE_ASM("asm/levels", func_L01_00443B18);

/* localdecomp:start func_L01_00443B88 */
extern f32 func_003824E0(void);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_00443B88(f32 *out) {
    f32 r;
    f32 a;
    f32 b;

    r = func_003824E0();
    a = func_00382538();
    b = func_00382538();
    out[0] = func_0038D098(a) * func_0038D0B0(b) * r;
    out[1] = func_0038D0B0(a) * func_0038D0B0(b) * r;
    out[2] = func_0038D098(b) * r;
}
/* localdecomp:end func_L01_00443B88 */
