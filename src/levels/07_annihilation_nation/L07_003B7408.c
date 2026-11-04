#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003B7408);

INCLUDE_ASM("asm/levels", func_L07_003B7548);

INCLUDE_ASM("asm/levels", func_L07_003B7E40);

INCLUDE_ASM("asm/levels", func_L07_003B7F80);

/* localdecomp:start func_L07_003B8448 */
extern void func_003C2880(s32 p);
extern void func_L07_00334740(void *);
extern void func_L07_003B8690(void *, s32);
extern u8 D_L07_001E1EC0[];

void func_L07_003B8448(void *arg0) {
    u8 *temp_s0;
    s32 temp_a0;
    u8 *g;

    temp_s0 = *(u8 **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x288);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x288) = 0;
    }
    *(u8 *)(temp_s0 + 0x187) = 0;
    *(u8 *)(temp_s0 + 0x188) = 0;
    *(u8 *)(temp_s0 + 0x189) = 0;
    g = D_L07_001E1EC0;
    if (*(void **)(g + 0x144) == arg0) {
        *(void **)(g + 0x144) = 0;
    }
    func_L07_00334740(arg0);
    func_L07_003B8690(arg0, 1);
}
/* localdecomp:end func_L07_003B8448 */

INCLUDE_ASM("asm/levels", func_L07_003B84C0);

INCLUDE_ASM("asm/levels", func_L07_003B8690);

INCLUDE_ASM("asm/levels", func_L07_003B8870);

INCLUDE_ASM("asm/levels", func_L07_003B88F0);

INCLUDE_ASM("asm/levels", func_L07_003B89C0);

INCLUDE_ASM("asm/levels", func_L07_003B89E0);

INCLUDE_ASM("asm/levels", func_L07_003B8AE0);

INCLUDE_ASM("asm/levels", func_L07_003B8BA0);

INCLUDE_ASM("asm/levels", func_L07_003B8C50);

INCLUDE_ASM("asm/levels", func_L07_003B8CE0);

INCLUDE_ASM("asm/levels", func_L07_003B8D80);

/* localdecomp:start func_L07_003B8F88 */
void func_L07_003B8FC0(void *, s32);

void func_L07_003B8F88(void *arg0) {
    func_L07_003B8FC0(arg0, 2);
    func_L07_003B8FC0(arg0, 3);
}
/* localdecomp:end func_L07_003B8F88 */

INCLUDE_ASM("asm/levels", func_L07_003B8FC0);
