#include "common.h"

/* localdecomp:start func_L07_003B90F0 */
void func_L01_004450F0(void *, s32, s32);
void func_L01_004AA7E8(void *, s32);

void func_L07_003B90F0(u8 *arg0) {
    u8 *a24;
    s32 t;

    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        *(u8 *)(arg0 + 0x30) = 0xFF;
        t = *(u16 *)(arg0 + 0x34);
        a24 = *(u8 **)(arg0 + 0x24);
        t = t & 0xFFBE;
        *(u16 *)(arg0 + 0x34) = t;
        t = t | (*(u16 *)(a24 + 0x44) & 0x1000);
        *(u16 *)(arg0 + 0x34) = t;
        t = t | 2;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(a24 + 0x10);
        *(s32 *)(arg0 + 0x98) = *(s32 *)(a24 + 0x10);
        *(u16 *)(arg0 + 0x34) = t;
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        break;
    case 2:
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(arg0, 1);
        *(s32 *)(arg0 + 0x98) = 0;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) | 2;
        break;
    }
}
/* localdecomp:end func_L07_003B90F0 */

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
