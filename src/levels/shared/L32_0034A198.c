#include "common.h"

/* localdecomp:start func_L32_0034A198 */
extern f32 D_L32_001DD03C;
extern void func_L32_0034A428(void *);
extern s32 func_L32_0034A460(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003E4008(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_003B2DC8(void);
extern s32 func_L01_004561B8(void *);
extern void func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);
extern void func_L01_0038B988(void *);
void func_L32_0034A198(u8 *a0) {
    switch (a0[0x20]) {
    case 0:
        func_L32_0034A428(a0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L32_0034A460(a0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        func_L01_003E4008(a0);
        func_L01_00404808(func_L01_003B2DC8, a0);
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            func_L04_00325460(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, D_L32_001DD03C, 20.0f, 1, 1, 0, 0);
        }
        func_L01_0038B988(a0);
        break;
    }
}
/* localdecomp:end func_L32_0034A198 */
