#include "common.h"

/* localdecomp:start func_L07_003CDE48 */
extern s32 func_L01_004468C8(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);
extern int func_L07_003CE2B8(int n);

void func_L07_003CDE48(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);
    s32 mode = h[0x5F] ? 0x10001 : 1;

    if (func_L07_003CE2B8(func_L01_004468C8(arg0, 4, 0.3f, mode, (f32)h[0x44], 2.0f, 0, 1, 0)) != 0) {
        h[0x406]++;
    } else if (func_L07_003CE2B8(func_L01_004468C8(arg0, 5, 0.5f, mode, (f32)h[0x44], 2.0f, 0, 1, 0)) != 0) {
        h[0x406]++;
    }
}
/* localdecomp:end func_L07_003CDE48 */

/* localdecomp:start func_L07_003CDF40 */
extern s32 func_L01_004468C8_003CDF40(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);
extern int func_L07_003CE2B8(int n);

void func_L07_003CDF40(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);
    s32 mode = h[0x5F] ? 0x10001 : 1;

    if (func_L07_003CE2B8(func_L01_004468C8_003CDF40(arg0, 8, 0.75f, mode, (f32)h[0x44], 2.5f, 0, 1, 0)) != 0 ||
        func_L07_003CE2B8(func_L01_004468C8_003CDF40(arg0, 7, 0.45f, mode, (f32)h[0x44], 2.5f, 0, 1, 0)) != 0 ||
        func_L07_003CE2B8(func_L01_004468C8_003CDF40(arg0, 6, 0.25f, mode, (f32)h[0x44], 2.5f, 0, 1, 0)) != 0) {
        h[0x406]++;
    }
}
/* localdecomp:end func_L07_003CDF40 */
