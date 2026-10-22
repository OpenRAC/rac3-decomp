#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003C0910);

INCLUDE_ASM("asm/levels", func_L19_003C0938);

INCLUDE_ASM("asm/levels", func_L19_003C0960);

INCLUDE_ASM("asm/levels", func_L19_003C1F18);

INCLUDE_ASM("asm/levels", func_L19_003C2388);

INCLUDE_ASM("asm/levels", func_L19_003C2628);

INCLUDE_ASM("asm/levels", func_L19_003C27A8);

/* localdecomp:start func_L19_003C2930 */
void func_0038CAD0(s32);
void func_0038CB00(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L19_001E2100[];

void func_L19_003C2930(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L19_001E2100, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CB00(temp_s1 + 0x414);
    func_0038CB00(temp_s1 + 0x416);
    func_0038CAD0(temp_s1 + 0x458);
}
/* localdecomp:end func_L19_003C2930 */

INCLUDE_ASM("asm/levels", func_L19_003C29D0);

/* localdecomp:start func_L19_003C2A20 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(void *, s32, void *);
extern u8 D_L19_003C29D0[];

void func_L19_003C2A20(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    if ((*(s32 *)((u8 *)temp_s0 + 0x444)) != 0) {
        *(s8 *)((u8 *)arg0 + 0x7F) = 0;
        *(u16 *)((u8 *)arg0 + 0xB6) = (u16) ((u16) (*(u16 *)((u8 *)arg0 + 0xB6)) >> 1);
        *(u16 *)((u8 *)arg0 + 0xB4) = (u16) ((s32) ((*(u16 *)((u8 *)arg0 + 0xB4)) << 0x10) >> 0x11);
    }
    func_L01_00315900(arg0, 0, D_L19_003C29D0);
}
/* localdecomp:end func_L19_003C2A20 */

INCLUDE_ASM("asm/levels", func_L19_003C2A98);

/* localdecomp:start func_L19_003C2BC0 */
s32 func_L19_003C2BC0(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((arg0 != 0) && ((*(s16 *)((u8 *)arg0 + 0xAA)) == 0x1C13)) {
        var_a1 = (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
    }
    return var_a1;
}
/* localdecomp:end func_L19_003C2BC0 */

INCLUDE_ASM("asm/levels", func_L19_003C2BF0);

INCLUDE_ASM("asm/levels", func_L19_003C2CC8);

INCLUDE_ASM("asm/levels", func_L19_003C3788);

INCLUDE_ASM("asm/levels", func_L19_003C3898);

INCLUDE_ASM("asm/levels", func_L19_003C3998);

INCLUDE_ASM("asm/levels", func_L19_003C3A78);

INCLUDE_ASM("asm/levels", func_L19_003C3B60);
