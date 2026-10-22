#include "common.h"

/* localdecomp:start func_L26_003E5178 */
s32 func_L26_003E5218(s32, s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
s32 func_L26_003E5330(void *, s32);
extern u8 D_L26_001E2840[];

void func_L26_003E5178(void *arg0) {
    s32 temp_s1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if ((((*(u8 *)((u8 *)arg0 + 0x20)) != 0) || (func_L26_003E5218((s32) arg0, temp_s1) != 0)) && (func_L26_003E5330(arg0, temp_s1) != 0) && ((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L26_001E2840, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
}
/* localdecomp:end func_L26_003E5178 */

INCLUDE_ASM("asm/levels", func_L26_003E5218);

INCLUDE_ASM("asm/levels", func_L26_003E5330);

INCLUDE_ASM("asm/levels", func_L26_003E54F8);

/* localdecomp:start func_L26_003E5578 */
s32 func_00382498(s32, s32);
void func_003C3A10(s32, s32, s32, s32);

void func_L26_003E5578(s32 arg0) {
    func_003C3A10(arg0, 0, func_00382498(0, 6), 0);
}
/* localdecomp:end func_L26_003E5578 */
