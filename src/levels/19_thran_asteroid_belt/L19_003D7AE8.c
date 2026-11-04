#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003D7AE8);

INCLUDE_ASM("asm/levels", func_L19_003D7C88);

INCLUDE_ASM("asm/levels", func_L19_003D7F80);

/* localdecomp:start func_L19_003D81D0 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L19_004044B0(void *, void *, void *);

void func_L19_003D81D0(u8 *a0) {
    f32 v[4];
    f32 ang;

    ang = *(f32 *)(a0 + 0xFC) * 0.5f * 0.017453292f;
    func_0038CE20(v, a0 + 0xE0, func_0038D0B0(ang));
    v[3] = func_0038D098(ang);
    func_L19_004044B0(a0 + 0xC0, a0 + 0xF0, v);
    func_0038CE90(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
    *(s32 *)(a0 + 0xCC) = 0;
    *(s32 *)(a0 + 0xDC) = 0;
}
/* localdecomp:end func_L19_003D81D0 */

INCLUDE_ASM("asm/levels", func_L19_003D8280);

INCLUDE_ASM("asm/levels", func_L19_003D8BC0);

INCLUDE_ASM("asm/levels", func_L19_003D8E30);
