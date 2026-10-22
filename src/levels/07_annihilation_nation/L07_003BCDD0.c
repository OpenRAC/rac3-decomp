#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003BCDD0);

/* localdecomp:start func_L07_003BCE50 */
void func_L07_003BCE50(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x18) = (f32) ((*(f32 *)((u8 *)arg0 + 0x18)) - (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2AC)));
}
/* localdecomp:end func_L07_003BCE50 */

INCLUDE_ASM("asm/levels", func_L07_003BCE68);

INCLUDE_ASM("asm/levels", func_L07_003BCEE8);

INCLUDE_ASM("asm/levels", func_L07_003BD078);

INCLUDE_ASM("asm/levels", func_L07_003BD118);

INCLUDE_ASM("asm/levels", func_L07_003BD1E8);

INCLUDE_ASM("asm/levels", func_L07_003BD9D0);

INCLUDE_ASM("asm/levels", func_L07_003BDC08);

INCLUDE_ASM("asm/levels", func_L07_003BDFB8);

INCLUDE_ASM("asm/levels", func_L07_003BE2A0);

INCLUDE_ASM("asm/levels", func_L07_003BE368);

INCLUDE_ASM("asm/levels", func_L07_003BE3A8);

INCLUDE_ASM("asm/levels", func_L07_003BE570);

INCLUDE_ASM("asm/levels", func_L07_003BE5F8);

INCLUDE_ASM("asm/levels", func_L07_003BE678);

INCLUDE_ASM("asm/levels", func_L07_003BE6C0);

/* localdecomp:start func_L07_003BE708 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE708(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x39C)) != -1) {
        func_L07_003BE3A8(arg0, 0xB);
        return;
    }
    func_L07_003BE3A8(arg0, 0xC);
}
/* localdecomp:end func_L07_003BE708 */

INCLUDE_ASM("asm/levels", func_L07_003BE750);

/* localdecomp:start func_L07_003BE7C8 */
void func_L07_003BE3A8(void *, s32);

void func_L07_003BE7C8(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    *(s16 *)((u8 *)temp_v1 + 0x4F8) = 0x32;
    if ((*(u8 *)((u8 *)temp_v1 + 0x4FA)) != 0) {
        func_L07_003BE3A8(arg0, 0xF);
        return;
    }
    func_L07_003BE3A8(arg0, 0xC);
}
/* localdecomp:end func_L07_003BE7C8 */

INCLUDE_ASM("asm/levels", func_L07_003BE818);

INCLUDE_ASM("asm/levels", func_L07_003BE870);

INCLUDE_ASM("asm/levels", func_L07_003BE988);

INCLUDE_ASM("asm/levels", func_L07_003BE9B8);
