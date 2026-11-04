#include "common.h"

typedef struct Bar_003CF388 {
    u8 pad_000[0x300];
    s32 f300;
    f32 f304;
    f32 f308;
    f32 f30C;
    f32 f310;
    f32 f314;
    f32 f318;
    f32 f31C;
    f32 f320;
    f32 f324;
    f32 f328;
    f32 f32C;
    f32 f330;
    s32 f334;
    s32 f338;
} Bar_003CF388;
typedef struct Foo_003CF388 {
    u8 pad_000[0x68];
    Bar_003CF388 *f68;
} Foo_003CF388;

/* localdecomp:start func_L19_003CDD90 */
f32 func_L19_003CDD90(f32 t, f32 b, f32 c, f32 d, f32 e) {
    f32 t2, t3;
    t2 = t * t;
    t3 = t2 * t;
    return 0.5f * (2.0f * c + (-b + d) * t + (2.0f * b - c * 5.0f + d * 4.0f - e) * t2 + (-b + c * 3.0f - d * 3.0f + e) * t3);
}
/* localdecomp:end func_L19_003CDD90 */

/* localdecomp:start func_L19_003CDE10 */
extern f32 func_L19_003CDD90(f32, f32, f32, f32, f32);

void func_L19_003CDE10(f32 *out, f32 *a, f32 *b, f32 *c, f32 *d, f32 t) {
    out[0] = func_L19_003CDD90(t, a[0], b[0], c[0], d[0]);
    out[1] = func_L19_003CDD90(t, a[1], b[1], c[1], d[1]);
    out[2] = func_L19_003CDD90(t, a[2], b[2], c[2], d[2]);
}
/* localdecomp:end func_L19_003CDE10 */

INCLUDE_ASM("asm/levels", func_L19_003CDEC0);

INCLUDE_ASM("asm/levels", func_L19_003CE990);

INCLUDE_ASM("asm/levels", func_L19_003CEEF8);

INCLUDE_ASM("asm/levels", func_L19_003CF090);

INCLUDE_ASM("asm/levels", func_L19_003CF280);

/* localdecomp:start func_L19_003CF388 */
void func_L19_003CF388(Foo_003CF388 *a0) {
    Bar_003CF388 *p = a0->f68;

    p->f300 = 4;
    p->f304 = 0.33f;
    p->f308 = 1200.0f;
    p->f30C = 1500.0f;
    p->f314 = 5.5f;
    p->f318 = 0.1f;
    p->f31C = 0.02f;
    p->f320 = 0.05f;
    p->f310 = 3.0f;
    p->f324 = 3.0f;
    p->f328 = 5.0f;
    p->f32C = 0.2f;
    p->f330 = 1.0f;
    p->f334 = 0;
    p->f338 = 0;
}
/* localdecomp:end func_L19_003CF388 */

INCLUDE_ASM("asm/levels", func_L19_003CF440);

INCLUDE_ASM("asm/levels", func_L19_003CF7B8);

INCLUDE_ASM("asm/levels", func_L19_003CF930);

INCLUDE_ASM("asm/levels", func_L19_003CFB20);
