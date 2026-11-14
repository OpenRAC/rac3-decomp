#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);
s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L32_001DFE1C;

INCLUDE_ASM("asm/levels", func_L32_003A44A8);

INCLUDE_ASM("asm/levels", func_L32_003A45D8);

INCLUDE_ASM("asm/levels", func_L32_003A4F18);

INCLUDE_ASM("asm/levels", func_L32_003A52A8);

INCLUDE_ASM("asm/levels", func_L32_003A5720);

INCLUDE_ASM("asm/levels", func_L32_003A5850);

/* localdecomp:start func_L32_003A5B20 */
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A5B20(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(s + 0x90) = 0;
    }
    *(s32 *)(s + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, s + 0x90, s + 0x140, D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (a0[0x60] & 2) {
        func_L32_003A52A8(a0, a1);
    }
}
/* localdecomp:end func_L32_003A5B20 */

INCLUDE_ASM("asm/levels", func_L32_003A5BC0);

/* localdecomp:start func_L32_003A5C78 */
extern f32 D_001DE9D4_sda, D_001DEA88_sda, D_001DEA50_sda;
__asm__(".extern D_001DE9D4_sda, 4");
__asm__(".extern D_001DEA88_sda, 4");
__asm__(".extern D_001DEA50_sda, 4");
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A5850(void *);

void func_L32_003A5C78(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    *(s32 *)(d + 0x110) = func_L30_0034D1E8(obj, obj + 0x10, d + 0x90, d + 0x140, D_001DE9D4_sda, D_001DE9D4_sda, D_001DEA88_sda, 0.0f, 0.0f, D_001DEA50_sda, 1, 1, 1, 0);
    if (obj[0x60] & 2) {
        func_L32_003A5850(obj);
    }
}
/* localdecomp:end func_L32_003A5C78 */

INCLUDE_ASM("asm/levels", func_L32_003A5CF8);

INCLUDE_ASM("asm/levels", func_L32_003A5E48);

INCLUDE_ASM("asm/levels", func_L32_003A6168);

INCLUDE_ASM("asm/levels", func_L32_003A6308);

INCLUDE_ASM("asm/levels", func_L32_003A63E0);

INCLUDE_ASM("asm/levels", func_L32_003A6608);

INCLUDE_ASM("asm/levels", func_L32_003A66B0);

INCLUDE_ASM("asm/levels", func_L32_003A6920);

INCLUDE_ASM("asm/levels", func_L32_003A6D70);

INCLUDE_ASM("asm/levels", func_L32_003A70A0);

INCLUDE_ASM("asm/levels", func_L32_003A7210);

INCLUDE_ASM("asm/levels", func_L32_003A77D8);

INCLUDE_ASM("asm/levels", func_L32_003A7948);

INCLUDE_ASM("asm/levels", func_L32_003A7C88);

INCLUDE_ASM("asm/levels", func_L32_003A7E18);

INCLUDE_ASM("asm/levels", func_L32_003A7F48);
