#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039E470);

INCLUDE_ASM("asm/levels", func_L03_0039E748);

INCLUDE_ASM("asm/levels", func_L03_0039E8F0);

/* localdecomp:start func_L03_0039EB90 */
void func_003C2880(s32);
void func_L03_0032FD50(void *);
void func_L03_0039ECA0(void *, s32);

void func_L03_0039EB90(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x300);
    *(s8 *)((u8 *)temp_s0 + 0x308) = 0;
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x300) = 0;
    }
    func_L03_0032FD50(arg0);
    func_L03_0039ECA0(arg0, 1);
}
/* localdecomp:end func_L03_0039EB90 */

/* localdecomp:start func_L03_0039EBE8 */
void *func_003C24B0(s32, s32);
void func_003C7C38(void *);
void func_L01_0044A7D0(u8 *);
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L03_0032FE10(void *);
void func_L03_0039ECA0(void *, s32);

void func_L03_0039EBE8(void *arg0) {
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v0 = func_003C24B0(0x18F9, 0x80);
    *(void **)((u8 *)temp_s0 + 0x300) = temp_v0;
    if (temp_v0 != 0) {
        *(u16 *)((u8 *)temp_v0 + 0x34) = (u16) ((*(u16 *)((u8 *)temp_v0 + 0x34)) | 0x100);
        *(u16 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x32) = (u16) (*(u16 *)((u8 *)arg0 + 0x32));
        *(u8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x31) = (u8) (*(u8 *)((u8 *)arg0 + 0x31));
        *(s8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x30) = 0;
        temp_v0_2 = *(void **)((u8 *)temp_s0 + 0x300);
        *(void **)((u8 *)temp_s0 + 0x240) = temp_v0_2;
        func_L01_0044A7D0(temp_v0_2);
        func_003C7C38((*(void **)((u8 *)temp_s0 + 0x300)));
    }
    *(s16 *)((u8 *)temp_s0 + 0x30A) = 0;
    func_L01_004AAC98(4, 4, arg0, 0x197A);
    func_L03_0032FE10(arg0);
    func_L03_0039ECA0(arg0, 2);
}
/* localdecomp:end func_L03_0039EBE8 */

INCLUDE_ASM("asm/levels", func_L03_0039ECA0);

INCLUDE_ASM("asm/levels", func_L03_0039EE10);

INCLUDE_ASM("asm/levels", func_L03_0039EEE8);

INCLUDE_ASM("asm/levels", func_L03_0039F028);

INCLUDE_ASM("asm/levels", func_L03_0039F2C8);

INCLUDE_ASM("asm/levels", func_L03_0039F3C0);

INCLUDE_ASM("asm/levels", func_L03_0039F960);

INCLUDE_ASM("asm/levels", func_L03_0039FB18);

/* localdecomp:start func_L03_0039FDE0 */
void func_003C2880(s32);
void func_L01_0044E740(void *);
void func_L03_0032FD50(void *);
void func_L03_0039FEF0(void *, s32);

void func_L03_0039FDE0(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x450);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x450) = 0;
    }
    func_L01_0044E740(temp_s0 + 0x2F0);
    func_L03_0032FD50(arg0);
    func_L03_0039FEF0(arg0, 1);
}
/* localdecomp:end func_L03_0039FDE0 */

INCLUDE_ASM("asm/levels", func_L03_0039FE40);

INCLUDE_ASM("asm/levels", func_L03_0039FEF0);

INCLUDE_ASM("asm/levels", func_L03_003A02B0);

INCLUDE_ASM("asm/levels", func_L03_003A0398);

INCLUDE_ASM("asm/levels", func_L03_003A04D0);

INCLUDE_ASM("asm/levels", func_L03_003A05D0);

INCLUDE_ASM("asm/levels", func_L03_003A0BF8);

INCLUDE_ASM("asm/levels", func_L03_003A0DA0);

/* localdecomp:start func_L03_003A1050 */
void func_003C2880(s32);
void func_L03_0032FD50(void *);
void func_L03_003A1158(void *, s32);

void func_L03_003A1050(void *arg0) {
    s32 temp_a0;
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s1 + 0x300);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s1 + 0x300) = 0;
    }
    func_L03_0032FD50(arg0);
    func_L03_003A1158(arg0, 1);
}
/* localdecomp:end func_L03_003A1050 */

INCLUDE_ASM("asm/levels", func_L03_003A10A8);

INCLUDE_ASM("asm/levels", func_L03_003A1158);

INCLUDE_ASM("asm/levels", func_L03_003A13E8);

INCLUDE_ASM("asm/levels", func_L03_003A14D0);

INCLUDE_ASM("asm/levels", func_L03_003A1600);

INCLUDE_ASM("asm/levels", func_L03_003A16D8);

INCLUDE_ASM("asm/levels", func_L03_003A17D8);

INCLUDE_ASM("asm/levels", func_L03_003A1A78);

INCLUDE_ASM("asm/levels", func_L03_003A1B70);

INCLUDE_ASM("asm/levels", func_L03_003A1C60);

INCLUDE_ASM("asm/levels", func_L03_003A1CD8);
