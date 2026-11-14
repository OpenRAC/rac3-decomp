#include "common.h"

/* NTSC-U counterpart of func_L30_004E5DD8 (src/levels/shared/L30_004E5370.c): 75 -> 90; 8 -> 10 */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
#include "vu0.h"
extern f32 func_00388A28(f32, f32);
#include "vu0.h"

/* localdecomp:start func_L30_004E1ED8 */
typedef struct {
    u8 pad0[0x98];
    f32 f98;
    u8 pad1[0x33C - 0x9C];
    f32 f33C;
    u8 pad2[0x25C4 - 0x340];
    s32 w25C4;
} S_004E5DD8;

typedef struct {
    u8 pad0[0x40];
    f32 f40;
    f32 f44;
} S2_004E5DD8;

extern S2_004E5DD8 D_L30_001E9000_004E1ED8;
extern s32 func_L01_004E2628(f32 *out, f32 scale, f32 amount);
extern s32 func_L01_004FC388(s32, s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);

s32 func_L30_004E1ED8(void) {
    f32 buf[4];
    f32 s;

    if (((S_004E5DD8 *)&D_001A4BE0)->f33C < 0.5f) {
        return 0;
    }
    if (!func_L01_004E2628(buf, 0.3f, 2.0f)) {
        return 0;
    }
    s = 4.0f;
    if (((S_004E5DD8 *)&D_001A4BE0)->w25C4 == 0xA7 || func_L01_004FC388(0xA7, 0x5A)) {
        s = 2.0f;
    }
    if (func_L01_004FC388(0xA9, 10)) {
        s = 2.0f;
    }
    if (!func_L01_004E2628(buf, s, 2.0f)) {
        return 0;
    }
    if (0.1f < buf[0]) {
        return 0;
    }
    if (func_00389468(func_00388A28(D_L30_001E9000_004E1ED8.f40, D_L30_001E9000_004E1ED8.f44), ((S_004E5DD8 *)&D_001A4BE0)->f98) < 1.5707964f) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L30_004E1ED8 */
