#include "common.h"

/* localdecomp:start func_L07_003DBE28 */
void func_L01_00404808(void *, void *);
s32 func_L01_004561B8(void *);
void func_L07_003DC0C8(void *);
void func_L07_003DC6E8(void *);
extern s32 D_L07_001DE908;
extern s32 D_L07_001DE928;
extern u8 D_L07_003DC940[];

void func_L07_003DBE28(void *arg0) {
    u16 temp_v1_2;
    u8 temp_v1;
    void *temp_s1;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (func_L01_004561B8(arg0) != 0) {
            *(void **)((u8 *)temp_s1 + 0x114) = &D_L07_001DE908;
        }
        if ((u16) (*(u16 *)((u8 *)arg0 + 0x96)) >= 0x12U) {
            *(void **)((u8 *)temp_s1 + 0x110) = &D_L07_001DE908;
        }
        break;
    case 1:
        if (func_L01_004561B8(arg0) != 0) {
            *(void **)((u8 *)temp_s1 + 0x114) = &D_L07_001DE928;
        }
        if ((u16) (*(u16 *)((u8 *)arg0 + 0x96)) >= 0x12U) {
            *(void **)((u8 *)temp_s1 + 0x110) = &D_L07_001DE928;
        }
        func_L07_003DC6E8(arg0);
        break;
    }
    func_L07_003DC0C8(arg0);
    func_L01_00404808(D_L07_003DC940, arg0);
    temp_v1_2 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1_2 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1_2 + 1);
    }
}
/* localdecomp:end func_L07_003DBE28 */

INCLUDE_ASM("asm/levels", func_L07_003DBF10);

/* localdecomp:start func_L07_003DC020 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003DC020(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        func_L01_004450F0(arg0, arg1, -1);
    }
}
/* localdecomp:end func_L07_003DC020 */

INCLUDE_ASM("asm/levels", func_L07_003DC040);

INCLUDE_ASM("asm/levels", func_L07_003DC0C8);

INCLUDE_ASM("asm/levels", func_L07_003DC4C8);
