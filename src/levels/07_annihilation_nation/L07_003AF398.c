#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003AF398);

/* localdecomp:start func_L07_003AF600 */
void func_0038CB78(s32, s32, s32);
void func_L01_0043A430(void *, s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L01_004AA760(s32, void *);

void func_L07_003AF600(void *arg0) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x90;
        func_0038CB78(temp_s0, 0, 0x40);
        func_L01_0043A430(arg0, 0, temp_s0);
        func_L01_004AA760(1, arg0);
        func_L01_004450F0(arg0, 1, -1);
    }
}
/* localdecomp:end func_L07_003AF600 */

INCLUDE_ASM("asm/levels", func_L07_003AF678);

INCLUDE_ASM("asm/levels", func_L07_003AF758);

INCLUDE_ASM("asm/levels", func_L07_003AF7B8);

INCLUDE_ASM("asm/levels", func_L07_003AF7F8);

INCLUDE_ASM("asm/levels", func_L07_003AF920);

INCLUDE_ASM("asm/levels", func_L07_003AFC10);

INCLUDE_ASM("asm/levels", func_L07_003AFD10);

INCLUDE_ASM("asm/levels", func_L07_003B0458);

INCLUDE_ASM("asm/levels", func_L07_003B04C8);

INCLUDE_ASM("asm/levels", func_L07_003B0530);

/* localdecomp:start func_L07_003B05A0 */
s32 func_L07_003B05A0(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x20)) - 7) < 2U;
}
/* localdecomp:end func_L07_003B05A0 */

INCLUDE_ASM("asm/levels", func_L07_003B05B0);

INCLUDE_ASM("asm/levels", func_L07_003B0660);

INCLUDE_ASM("asm/levels", func_L07_003B0738);

INCLUDE_ASM("asm/levels", func_L07_003B0970);

INCLUDE_ASM("asm/levels", func_L07_003B0B08);

INCLUDE_ASM("asm/levels", func_L07_003B0CF8);

INCLUDE_ASM("asm/levels", func_L07_003B0E08);

INCLUDE_ASM("asm/levels", func_L07_003B0F20);

/* localdecomp:start func_L07_003B0F78 */
void func_003C7C38(void *);
void func_L07_003B0E08(void *, s32);

void func_L07_003B0F78(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    *(s32 *)((u8 *)temp_v0 + 0x48) = 0;
    *(s32 *)((u8 *)((*(void **)((u8 *)temp_v0 + 0x44))) + 0xF0) = 0;
    func_003C7C38((*(void **)((u8 *)temp_v0 + 0x44)));
    func_L07_003B0E08(arg0, 1);
}
/* localdecomp:end func_L07_003B0F78 */

INCLUDE_ASM("asm/levels", func_L07_003B0FC0);

INCLUDE_ASM("asm/levels", func_L07_003B0FE0);

INCLUDE_ASM("asm/levels", func_L07_003B12D8);

INCLUDE_ASM("asm/levels", func_L07_003B13E8);

INCLUDE_ASM("asm/levels", func_L07_003B1578);

INCLUDE_ASM("asm/levels", func_L07_003B15A8);

INCLUDE_ASM("asm/levels", func_L07_003B1958);

INCLUDE_ASM("asm/levels", func_L07_003B1A30);

INCLUDE_ASM("asm/levels", func_L07_003B1C08);

INCLUDE_ASM("asm/levels", func_L07_003B24C8);

INCLUDE_ASM("asm/levels", func_L07_003B2738);

INCLUDE_ASM("asm/levels", func_L07_003B2870);

INCLUDE_ASM("asm/levels", func_L07_003B28B8);

INCLUDE_ASM("asm/levels", func_L07_003B28C8);

INCLUDE_ASM("asm/levels", func_L07_003B3028);

INCLUDE_ASM("asm/levels", func_L07_003B3160);

INCLUDE_ASM("asm/levels", func_L07_003B34A0);

INCLUDE_ASM("asm/levels", func_L07_003B3570);

INCLUDE_ASM("asm/levels", func_L07_003B3798);

INCLUDE_ASM("asm/levels", func_L07_003B37D0);

INCLUDE_ASM("asm/levels", func_L07_003B3A88);

INCLUDE_ASM("asm/levels", func_L07_003B3C78);

INCLUDE_ASM("asm/levels", func_L07_003B3DB0);

INCLUDE_ASM("asm/levels", func_L07_003B4250);

INCLUDE_ASM("asm/levels", func_L07_003B4308);

INCLUDE_ASM("asm/levels", func_L07_003B4370);

INCLUDE_ASM("asm/levels", func_L07_003B4470);

INCLUDE_ASM("asm/levels", func_L07_003B4688);

INCLUDE_ASM("asm/levels", func_L07_003B46E8);

INCLUDE_ASM("asm/levels", func_L07_003B48E8);

INCLUDE_ASM("asm/levels", func_L07_003B4978);

INCLUDE_ASM("asm/levels", func_L07_003B4B68);

INCLUDE_ASM("asm/levels", func_L07_003B4C30);

INCLUDE_ASM("asm/levels", func_L07_003B4DF8);

INCLUDE_ASM("asm/levels", func_L07_003B4FD0);

INCLUDE_ASM("asm/levels", func_L07_003B5CC8);

INCLUDE_ASM("asm/levels", func_L07_003B5E08);

INCLUDE_ASM("asm/levels", func_L07_003B62C8);

INCLUDE_ASM("asm/levels", func_L07_003B6320);

INCLUDE_ASM("asm/levels", func_L07_003B64D0);

INCLUDE_ASM("asm/levels", func_L07_003B6800);

INCLUDE_ASM("asm/levels", func_L07_003B6870);

INCLUDE_ASM("asm/levels", func_L07_003B68F0);

INCLUDE_ASM("asm/levels", func_L07_003B6998);

INCLUDE_ASM("asm/levels", func_L07_003B6AE8);

INCLUDE_ASM("asm/levels", func_L07_003B6B38);

INCLUDE_ASM("asm/levels", func_L07_003B6BD8);

INCLUDE_ASM("asm/levels", func_L07_003B6CD8);

INCLUDE_ASM("asm/levels", func_L07_003B6DC8);

INCLUDE_ASM("asm/levels", func_L07_003B6E98);

INCLUDE_ASM("asm/levels", func_L07_003B70F0);

INCLUDE_ASM("asm/levels", func_L07_003B7230);

INCLUDE_ASM("asm/levels", func_L07_003B7378);
