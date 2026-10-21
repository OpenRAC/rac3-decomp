#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

INCLUDE_ASM("asm/levels", func_L30_003A10B8);

INCLUDE_ASM("asm/levels", func_L30_003A1150);

INCLUDE_ASM("asm/levels", func_L30_003A14F8);

/* localdecomp:start func_L30_003A1A68 */
extern f32 D_L30_001DE9C4;
extern f32 D_L30_001DE9C8;
extern f32 D_L30_001DE9CC;
extern f32 D_L30_001DE9D0;
extern void func_0038CE20(Vec4 *, void *, f32);
extern void func_L01_00451FE0(f32, f32, f32, f32, u8 *, s32, Vec4 *, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
void func_L30_003A1A68(u8 *a0) {
    Vec4 v;
    func_0038CE20(&v, *(void **)(a0 + 104), 0.75f);
    func_L01_00451FE0(D_L30_001DE9C4, D_L30_001DE9C8, D_L30_001DE9CC, D_L30_001DE9D0, a0, 7, &v, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
}
/* localdecomp:end func_L30_003A1A68 */

INCLUDE_ASM("asm/levels", func_L30_003A1AF8);

INCLUDE_ASM("asm/levels", func_L30_003A1D08);

INCLUDE_ASM("asm/levels", func_L30_003A20D0);

INCLUDE_ASM("asm/levels", func_L30_003A22F0);

INCLUDE_ASM("asm/levels", func_L30_003A2608);

INCLUDE_ASM("asm/levels", func_L30_003A2808);

INCLUDE_ASM("asm/levels", func_L30_003A2AF8);
