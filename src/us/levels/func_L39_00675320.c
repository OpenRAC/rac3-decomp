#include "common.h"

/* localdecomp:start func_L39_00675320 */
extern s32 D_L39_0024D128[];
extern s32 D_L39_0024D12C[];
extern s32 D_L39_0024D130[];
extern s32 D_L39_0024D134[];
extern s32 D_L39_0024D138[];
extern f32 D_L39_0024D13C[];
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_00608730(s32, s32);

s32 func_L39_00675320(s32 value) {
    D_L39_0024D130[0] = value;
    D_L39_0024D13C[0] = 1.0f;
    D_L39_0024D12C[0] = 0x5A;
    D_L39_0024D128[0] = 0;
    D_L39_0024D134[0] = 0;
    D_L39_0024D138[0] = func_L39_005B24C8(0x1A, 0x23);
    func_L39_00608730(0, 0);
    return 1;
}
/* localdecomp:end func_L39_00675320 */
