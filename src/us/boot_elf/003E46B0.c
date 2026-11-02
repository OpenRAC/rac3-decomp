#include "common.h"

/* Adapted from nonmatching/boot_elf/func_003E47F8.c for the native NTSC-U program. */
/* localdecomp:start func_U_003E46B0 */
typedef struct {
    u8 padding[0x28B4];
    s32 first;
    s32 second;
} State_003E46B0;

extern State_003E46B0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_U_00381C68(s32 *, s32 *, s32 *);
extern s32 func_U_003E8448(s32, f32, f32);

s32 func_U_003E46B0(void) {
    s32 bounds[3];
    s32 position;
    f32 denominator;
    f32 numerator;
    f32 fraction;
    position = D_00142694[0] >> 5;
    bounds[0] = D_001A4BE0.second;
    bounds[1] = D_001A4BE0.first;
    if (bounds[0] == 0) {
        bounds[2] = 0;
        func_U_00381C68(bounds, bounds + 1, bounds + 2);
    }
    numerator = (f32)(position - bounds[0]);
    denominator = (f32)(bounds[1] - bounds[0]);
    fraction = denominator <= 0.0f ? 0.0f : numerator / denominator;
    return func_U_003E8448(0x90007, fraction * 0.1285f, 0.008f);
}
/* localdecomp:end func_U_003E46B0 */
