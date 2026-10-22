#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A9DB0);

INCLUDE_ASM("asm/levels", func_L07_003AA228);

INCLUDE_ASM("asm/levels", func_L07_003AA458);

INCLUDE_ASM("asm/levels", func_L07_003AA9C0);

/* localdecomp:start func_L07_003AAA08 */
void func_L07_00334800();
void func_L07_003AAA50(void *, s32);

void func_L07_003AAA08(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003AAA50(arg0, 2);
}
/* localdecomp:end func_L07_003AAA08 */

INCLUDE_ASM("asm/levels", func_L07_003AAA50);

INCLUDE_ASM("asm/levels", func_L07_003AADB0);

INCLUDE_ASM("asm/levels", func_L07_003AAF98);

INCLUDE_ASM("asm/levels", func_L07_003AB200);

INCLUDE_ASM("asm/levels", func_L07_003AB2B0);

INCLUDE_ASM("asm/levels", func_L07_003AB4B8);

INCLUDE_ASM("asm/levels", func_L07_003AB678);

INCLUDE_ASM("asm/levels", func_L07_003AB918);

INCLUDE_ASM("asm/levels", func_L07_003ABD18);

INCLUDE_ASM("asm/levels", func_L07_003AC2D0);

INCLUDE_ASM("asm/levels", func_L07_003AC500);

INCLUDE_ASM("asm/levels", func_L07_003ACA00);

/* localdecomp:start func_L07_003ACA48 */
void func_L07_00334800();
void func_L07_003ACA90(void *, s32);

void func_L07_003ACA48(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003ACA90(arg0, 2);
}
/* localdecomp:end func_L07_003ACA48 */

INCLUDE_ASM("asm/levels", func_L07_003ACA90);

INCLUDE_ASM("asm/levels", func_L07_003ACD58);

INCLUDE_ASM("asm/levels", func_L07_003ACF40);

/* localdecomp:start func_L07_003AD058 */
void func_L07_003AD058(void *arg0) {
    s32 var_v1;
    void *var_v0;

    var_v1 = 1;
    var_v0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x560;
    do {
        *(s8 *)((u8 *)var_v0 + 2) = 0;
        var_v1 -= 1;
        (*(s8 *)var_v0) = 0;
        var_v0 += 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_L07_003AD058 */

INCLUDE_ASM("asm/levels", func_L07_003AD088);

INCLUDE_ASM("asm/levels", func_L07_003AD180);

INCLUDE_ASM("asm/levels", func_L07_003AD210);
