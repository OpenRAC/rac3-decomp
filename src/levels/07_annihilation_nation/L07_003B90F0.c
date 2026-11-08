#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003B90F0);

INCLUDE_ASM("asm/levels", func_L07_003B91C8);

/* localdecomp:start func_L07_003B94E0 */
void func_L07_003A71E8(s32);
void func_L07_003BA098(s32);
void func_L07_003A6EA8(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B94E0(void *arg0) {
    void *temp_s0;
    u8 kind;

    *(u16 *)((u8 *)arg0 + 0x34) = (u16)(*(u16 *)((u8 *)arg0 + 0x34) & 0xFFFD);
    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    kind = *(u8 *)((u8 *)temp_s0 + *(s32 *)((u8 *)temp_s0 + 0x7C));
    switch (kind) {
    case 1:
        func_L07_003A71E8(*(s32 *)((u8 *)temp_s0 + 0x80));
        break;
    case 2:
        func_L07_003BA098(*(s32 *)((u8 *)temp_s0 + 0x80));
        break;
    case 3:
        func_L07_003A6EA8(*(s32 *)((u8 *)temp_s0 + 0x80));
        break;
    case 0:
    default:
        break;
    }
    *(s32 *)((u8 *)temp_s0 + 0x7C) = 0;
    func_L01_004450F0(arg0, 0, -1);
}
/* localdecomp:end func_L07_003B94E0 */

INCLUDE_ASM("asm/levels", func_L07_003B9590);

INCLUDE_ASM("asm/levels", func_L07_003B96F8);

/* localdecomp:start func_L07_003B98E0 */
void func_L01_003F2AF8(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003B98E0(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_s0 + 0x30)) != 0) {
        func_L01_003F2AF8(0, (*(s32 *)((u8 *)temp_s0 + 0x40)));
        *(s32 *)((u8 *)temp_s0 + 0x30) = 0;
    }
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003B98E0 */

/* localdecomp:start func_L07_003B9948 */
extern void func_L01_004450F0(void *, int, int);

void func_L07_003B9948(char *arg0, unsigned char idx)
{
    if (*(unsigned char *)(*(char **)(arg0 + 0x68) + idx + 0x64) != 0) {
        *(unsigned short *)(arg0 + 0x34) &= 0xFFFD;
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L07_003B9948 */
