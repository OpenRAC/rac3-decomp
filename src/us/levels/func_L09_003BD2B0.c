#include "common.h"

/* NTSC-U counterpart of func_L09_003BEB30 (src/levels/09_tyhrranosis/L09_003BE910.c) */
#include "vu0.h"
extern u8 *D_L09_001E011C;

/* localdecomp:start func_L09_003BD2B0 */
extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern u8 D_L09_001E2C00[];
__asm__(".extern D_L09_001E2C00, 16");
extern void func_L09_003BABD8(u8 *, s32, s32, s32, s32);
extern s32 func_0037E208(s32, s32);

s32 func_L09_003BD2B0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    u8 *g;
    p[0xD42] &= ~1;
    func_L09_003BABD8(a0, a1, a2, a3, 0);
    *(s16 *)(p + 0xD38) = (f32)func_0037E208(5, 10) * 60.0f;
    *(s16 *)(p + 0xD30) = (f32)func_0037E208(15, 25) * 60.0f;
    *(s16 *)(p + 0xD34) = 0;
    p[0xD40] = 0;
    g = D_L09_001E2C00;
    if (*(u8 **)(g + 0x144) == e)
        *(u8 **)(g + 0x144) = 0;
    if (*(u8 **)(g + 0x144) == 0) {
        *(u8 **)(g + 0x144) = a0;
        *(s32 *)(g + 0x148) = 0;
    }
    return 1;
}
/* localdecomp:end func_L09_003BD2B0 */
