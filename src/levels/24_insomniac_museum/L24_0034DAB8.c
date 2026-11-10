#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0034DAB8);

INCLUDE_ASM("asm/levels", func_L24_0034E250);

INCLUDE_ASM("asm/levels", func_L24_0034E370);

/* localdecomp:start func_L24_0034E6B0 */
extern void func_L01_004C70A8(char *, char *, unsigned int *, float, int);
void func_L24_0034E6B0(char *a0)
{
    char *s = *(char **)(a0 + 0x68);
    unsigned int c;
    if (((unsigned char *)s)[0x1A4] != 0) {
        c = 0x80008000;
        func_L01_004C70A8(s + 0x170, s + 0x180, &c, 1.0f, 1);
    }
}
/* localdecomp:end func_L24_0034E6B0 */

INCLUDE_ASM("asm/levels", func_L24_0034E6F8);

/* localdecomp:start func_L24_0034EBF8 */
void func_L01_003EB5E0(s32, s32);
void func_L01_003F2AF8(s32, s32);

void func_L24_0034EBF8(void *arg0) {
    s32 temp_a1;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a1 = *(s32 *)((u8 *)temp_s0 + 0x158);
    if (temp_a1 != 0) {
        func_L01_003F2AF8(0, temp_a1);
        *(s32 *)((u8 *)temp_s0 + 0x158) = 0;
        return;
    }
    func_L01_003EB5E0(0, 3);
}
/* localdecomp:end func_L24_0034EBF8 */

INCLUDE_ASM("asm/levels", func_L24_0034EC40);

INCLUDE_ASM("asm/levels", func_L24_0034ED28);
