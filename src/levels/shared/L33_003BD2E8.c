#include "common.h"

/* localdecomp:start func_L33_003BD2E8 */
extern void func_L33_003BD798();
extern void func_L33_003BD828(u8 *);
extern void func_L33_003BD7C8(u8 *);
extern void func_L33_003BD5F8(u8 *);
extern void func_L33_003BD978(u8 *);
extern void func_L33_003BDA58(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BD2E8(u8 *a0) {
    switch (a0[0x20]) {
    case 1:
        func_L33_003BD798(a0);
        break;
    case 2:
        func_L33_003BD828(a0);
        break;
    case 3:
        func_L33_003BD7C8(a0);
        break;
    case 0:
        func_L33_003BD5F8(a0);
        func_L01_004450F0(a0, 5, -1);
        break;
    case 4:
        func_L33_003BD978(a0);
        break;
    case 5:
        func_L33_003BDA58(a0);
        break;
    }
}
/* localdecomp:end func_L33_003BD2E8 */

INCLUDE_ASM("asm/levels", func_L33_003BD398);

INCLUDE_ASM("asm/levels", func_L33_003BD5F8);

INCLUDE_ASM("asm/levels", func_L33_003BD6C8);

/* localdecomp:start func_L33_003BD798 */
extern u8 D_00142732[];
extern s32 func_L01_004561B8(void);

void func_L33_003BD798(void) {
    if (func_L01_004561B8()) {
        D_00142732[0] = 1;
    }
}
/* localdecomp:end func_L33_003BD798 */

/* localdecomp:start func_L33_003BD7C8 */
extern s32 func_L01_004561B8(void);
extern s32 D_L33_001DF17C;
extern void func_L30_0034DAC0(u8 *);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BD7C8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (((s32 (*)(u8 *))func_L01_004561B8)(a0)) {
        *(s32 *)(v + 20) = D_L33_001DF17C;
        func_L30_0034DAC0(v + 8);
    }
    if (func_0038CAD0(v + 20)) {
        func_L01_004450F0(a0, 1, -1);
    }
}
/* localdecomp:end func_L33_003BD7C8 */

INCLUDE_ASM("asm/levels", func_L33_003BD828);

INCLUDE_ASM("asm/levels", func_L33_003BD978);

INCLUDE_ASM("asm/levels", func_L33_003BDA58);
