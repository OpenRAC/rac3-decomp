#include "common.h"

/* localdecomp:start func_L01_00412E30 */
extern void func_0038DED0_00412E30();
 
void func_L01_00412E30(void) {
    func_0038DED0_00412E30();
}
/* localdecomp:end func_L01_00412E30 */

/* localdecomp:start func_L01_00412E50 */
extern void func_00390BF8_00412E50();
 
void func_L01_00412E50(void) {
    func_00390BF8_00412E50();
}
/* localdecomp:end func_L01_00412E50 */

INCLUDE_ASM("asm/levels", func_L01_00412E70);

INCLUDE_ASM("asm/levels", func_L01_00412FE0);

/* localdecomp:start func_L01_004130C0 */
void func_L01_004130C0(u8 *a) {
    *(u16 *)(a + 0xE0) &= ~2;
}
/* localdecomp:end func_L01_004130C0 */

/* localdecomp:start func_L01_004130D0 */
extern f32 func_0038CED8(void *v);
extern f32 func_0038D160(f32 a, f32 b);

void func_L01_004130D0(u8 *a0)
{
    if (!(*(u16 *)(a0 + 224) & 2)) {
        *(u16 *)(a0 + 224) |= 2;
        *(f32 *)(a0 + 96) = -func_0038D160(func_0038CED8(a0 + 240), *(f32 *)(a0 + 248));
        *(f32 *)(a0 + 64) = func_0038D160(*(f32 *)(a0 + 240), *(f32 *)(a0 + 244));
    }
}
/* localdecomp:end func_L01_004130D0 */

INCLUDE_ASM("asm/levels", func_L01_00413138);

/* localdecomp:start func_L01_00413AE0 */
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038DB00(f32 a, f32 b);
s32 func_L01_00413AE0(u8 *a0, f32 s) {
    u8 *p;
    p = *(u8 **)(a0 + 140);
    if (p != 0) {
        return s * func_0038DB00(func_0038D160(*(f32 *)(p + 16) - *(f32 *)(a0 + 48), *(f32 *)(p + 20) - *(f32 *)(a0 + 52)), *(f32 *)(a0 + 64)) > 0.0f;
    }
    return 0;
}
/* localdecomp:end func_L01_00413AE0 */

INCLUDE_ASM("asm/levels", func_L01_00413B68);

INCLUDE_ASM("asm/levels", func_L01_00413F48);

LINKER_REMNANT("asm/levels", func_L01_00414360);
