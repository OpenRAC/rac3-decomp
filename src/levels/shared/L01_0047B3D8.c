#include "common.h"

/* localdecomp:start func_L01_0047B3D8 */
extern u8 D_L01_001D80A4;
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_0047B638(s32);
extern s32 func_L01_00516010(s32);
s32 func_L01_0047B3D8(void) {
    if (D_L01_001D80A4 != 0) {
        func_L01_00516AA0(0x90000, 1, 0);
        return func_L01_00516010(func_L01_0047B638(0));
    }
    return 0;
}
/* localdecomp:end func_L01_0047B3D8 */

/* localdecomp:start func_L01_0047B420 */
extern s32 D_L01_001D80A0;
extern s32 func_L01_0047B638(s32 a0);
extern s32 func_L01_00516050(s32 a0);
extern void func_L01_00516AA0(s32 a0, s32 a1, s32 a2);
s32 func_L01_0047B420(void) {
    if (func_L01_00516050(func_L01_0047B638(0)) != 0) {
        if (D_L01_001D80A0 != 0) func_L01_00516AA0(0x90000, 1, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0047B420 */

INCLUDE_ASM("asm/levels", func_L01_0047B470);
