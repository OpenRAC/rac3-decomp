#include "common.h"

/* localdecomp:start func_L32_003C4E00 */
void func_L01_00404A10(void *, void *);
void func_L01_004450F0(void *, s32, s32);
void func_L32_003C4F08(void *);
void func_L32_003C4FC0(void *);
void func_L32_003C50B0(void *);
void func_L32_003C5280(void *);
extern u8 D_L32_003C4EC8[];

void func_L32_003C4E00(void *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    switch (temp_v1) {                              /* irregular */
    case 1:
        func_L32_003C4FC0(arg0);
        return;
    case 2:
        func_L32_003C50B0(arg0);
        func_L01_00404A10(D_L32_003C4EC8, arg0);
        return;
    case 0:
        func_L32_003C4F08(arg0);
        func_L01_004450F0(arg0, 3, -1);
        return;
    case 3:
        func_L32_003C5280(arg0);
        func_L01_00404A10(D_L32_003C4EC8, arg0);
        return;
    }
}
/* localdecomp:end func_L32_003C4E00 */

/* localdecomp:start func_L32_003C4EC8 */
void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 D_L32_001DF424;
extern s32 D_L32_001DF42C;
extern f32 D_L32_001DF430;
extern f32 D_L32_001DF434;

void func_L32_003C4EC8(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    func_003D9508(arg0 + 0x10, D_L32_001DF42C, D_L32_001DF424, 0, D_L32_001DF430 * (*(f32 *)((u8 *)temp_v0 + 0x10)), D_L32_001DF434, (*(f32 *)((u8 *)temp_v0 + 0x1C)));
}
/* localdecomp:end func_L32_003C4EC8 */

INCLUDE_ASM("asm/levels", func_L32_003C4F08);

INCLUDE_ASM("asm/levels", func_L32_003C4F70);

INCLUDE_ASM("asm/levels", func_L32_003C4FC0);

INCLUDE_ASM("asm/levels", func_L32_003C50B0);

INCLUDE_ASM("asm/levels", func_L32_003C5280);

INCLUDE_ASM("asm/levels", func_L32_003C53A0);
