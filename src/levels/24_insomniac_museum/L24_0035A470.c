#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0035A470);

/* localdecomp:start func_L24_0035A550 */
void func_L24_0035A550(void *arg0, f32 fparg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    *(f32 *)((u8 *)temp_v0 + 0x1BC) = (f32) ((*(f32 *)((u8 *)temp_v0 + 0x1BC)) + fparg0);
    *(f32 *)((u8 *)temp_v0 + 0x1F4) = (f32) ((*(f32 *)((u8 *)temp_v0 + 0x1F4)) - fparg0);
    *(f32 *)((u8 *)temp_v0 + 0x1FC) = (f32) ((*(f32 *)((u8 *)temp_v0 + 0x1FC)) - fparg0);
}
/* localdecomp:end func_L24_0035A550 */

INCLUDE_ASM("asm/levels", func_L24_0035A580);

INCLUDE_ASM("asm/levels", func_L24_0035A908);

INCLUDE_ASM("asm/levels", func_L24_0035A970);

INCLUDE_ASM("asm/levels", func_L24_0035AA18);

INCLUDE_ASM("asm/levels", func_L24_0035AA48);

/* localdecomp:start func_L24_0035AB58 */
s32 func_0038CB00(void *);
void func_L24_0035A908(void *, s32);
s32 func_L24_0035AA48(void *);
void func_L24_0035ABD0(void *, u8);

void func_L24_0035AB58(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x95)) != (*(u8 *)((u8 *)temp_s1 + 0x198))) && (func_0038CB00(temp_s1 + 0x194) != 0) && (func_L24_0035AA48(arg0) != 0)) {
        func_L24_0035A908(arg0, 0);
        func_L24_0035ABD0(arg0, (*(u8 *)((u8 *)temp_s1 + 0x198)));
    }
}
/* localdecomp:end func_L24_0035AB58 */

INCLUDE_ASM("asm/levels", func_L24_0035ABD0);

INCLUDE_ASM("asm/levels", func_L24_0035ACB0);

INCLUDE_ASM("asm/levels", func_L24_0035B0D0);

INCLUDE_ASM("asm/levels", func_L24_0035B1F8);
