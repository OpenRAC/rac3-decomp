#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00450F00);

LINKER_REMNANT("asm/levels", func_L01_00450F50);

INCLUDE_ASM("asm/levels", func_L01_00450F60);

INCLUDE_ASM("asm/levels", func_L01_00451020);

/* localdecomp:start func_L01_00451048 */
extern void func_003C5060(void *, void *, f32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);

void func_L01_00451048(u8 *a0, void *a1, f32 f) {
    func_003C5060(a0, a1, f);
    func_0038CFB8(a1, a1, f);
    func_0038D000(a1, a1, a0 + 192);
}
/* localdecomp:end func_L01_00451048 */

/* localdecomp:start func_L01_004510A8 */
extern void func_0038D000(void *, void *, void *);
extern void func_003C5060(void *, void *, f32);

void func_L01_004510A8(u8 *a0, u8 *a1, float f)
{
    ((void (*)(u8 *a, u8 *b))func_003C5060)(a0, a1);
    *(float *)(a1 + 8) = f;
    ((void (*)(u8 *a, u8 *b, u8 *c))func_0038D000)(a1, a1, a0 + 192);
}
/* localdecomp:end func_L01_004510A8 */

/* localdecomp:start func_L01_004510F8 */
extern void func_003C5060();
extern f32 func_0038CED8(f32 *);
f32 func_L01_004510F8(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003C5060(a, v, b, c);
    return func_0038CED8(v);
}
/* localdecomp:end func_L01_004510F8 */
