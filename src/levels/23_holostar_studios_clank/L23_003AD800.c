#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_003AD800);

INCLUDE_ASM("asm/levels", func_L23_003AF6E8);

INCLUDE_ASM("asm/levels", func_L23_003AF9B8);

INCLUDE_ASM("asm/levels", func_L23_003AFAF0);

INCLUDE_ASM("asm/levels", func_L23_003AFC40);

INCLUDE_ASM("asm/levels", func_L23_003AFE10);

INCLUDE_ASM("asm/levels", func_L23_003B0010);

INCLUDE_ASM("asm/levels", func_L23_003B0110);

INCLUDE_ASM("asm/levels", func_L23_003B0200);

INCLUDE_ASM("asm/levels", func_L23_003B0480);

INCLUDE_ASM("asm/levels", func_L23_003B0708);

/* localdecomp:start func_L23_003B08E0 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B08E0(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    func_0038CAD0(temp_s1 + 0x214);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L23_003B08E0 */

INCLUDE_ASM("asm/levels", func_L23_003B0978);

INCLUDE_ASM("asm/levels", func_L23_003B0A20);

INCLUDE_ASM("asm/levels", func_L23_003B0CE0);

INCLUDE_ASM("asm/levels", func_L23_003B0EC0);

INCLUDE_ASM("asm/levels", func_L23_003B1230);

INCLUDE_ASM("asm/levels", func_L23_003B12C8);

INCLUDE_ASM("asm/levels", func_L23_003B1418);

INCLUDE_ASM("asm/levels", func_L23_003B1490);

INCLUDE_ASM("asm/levels", func_L23_003B34F8);

/* localdecomp:start func_L23_003B3908 */
void func_0038CAD0(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L23_001E1A40[];

void func_L23_003B3908(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L23_001E1A40, arg0 + 0x10) < 9216.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x5A;
    }
    *(u16 *)((u8 *)arg0 + 0x96) = (u16) ((*(u16 *)((u8 *)arg0 + 0x96)) + 1);
    *(s32 *)((u8 *)temp_s1 + 0x31C) = (s32) ((*(s32 *)((u8 *)temp_s1 + 0x31C)) + 1);
    func_0038CAD0(temp_s1 + 0x330);
}
/* localdecomp:end func_L23_003B3908 */

INCLUDE_ASM("asm/levels", func_L23_003B3998);
