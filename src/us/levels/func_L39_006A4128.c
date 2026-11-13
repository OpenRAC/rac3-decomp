#include "common.h"

/* NTSC-U counterpart of func_L39_006A6938 (src/levels/39_multiplayer_menu/L39_006A61A0.c) */
/* localdecomp:start func_L39_006A4128 */
typedef struct { u8 pad0[0xE0]; s16 f_E0[8]; u8 pad1[0x150 - 0xF0]; s32 f_150[8]; } S_006A6938;
typedef struct { u8 pad0[0x34]; s32 f34; } G_006A6938;
extern S_006A6938 *D_L39_002417C0;
extern G_006A6938 D_001A5E50;

s32 func_L39_006A4128(s32 a0, s32 a1)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_L39_002417C0->f_E0[i] >= 0 && (D_L39_002417C0->f_150[i] == a1 || D_001A5E50.f34 == a1)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006A4128 */
