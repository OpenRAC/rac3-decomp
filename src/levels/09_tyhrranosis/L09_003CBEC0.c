#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003CBEC0);

INCLUDE_ASM("asm/levels", func_L09_003CC1F0);

INCLUDE_ASM("asm/levels", func_L09_003CC3A0);

/* localdecomp:start func_L09_003CCB28 */
void func_L01_00445130(s32, s32, s32);
void func_L09_003CCB28(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x20) = arg1;
    func_L01_00445130((s32) arg0, 2, -1);
}
/* localdecomp:end func_L09_003CCB28 */

/* localdecomp:start func_L09_003CCB50 */
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L09_003CCC00(void *, s32, f32, f32, f32, f32);
extern void func_003C2880(void *);
void func_L09_003CCB50(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        break;
    case 1:
        if (func_L01_00447490(a0, 0x8010000, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        a0[0xA8] = 0xFF;
        break;
    case 2:
        func_L09_003CCC00(a0, 0x3C, 0.4f, 10.0f, 10.0f, 0.100000009f);
        func_003C2880(a0);
        break;
    }
}
/* localdecomp:end func_L09_003CCB50 */

INCLUDE_ASM("asm/levels", func_L09_003CCC00);
