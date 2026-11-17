#include "common.h"

/* localdecomp:start func_L39_0068D6D8 */
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad1[0x169 - 0xC];
    u8 b169;
    u8 pad2[0x2EC - 0x16A];
    s32 w2EC;
} S_0068D6D8_g;

typedef struct {
    u8 pad[0xE0];
    s16 eE0[8];
    s16 eF0[8];
} S_0068D6D8_p;

extern S_0068D6D8_g D_001A5CD0;
__asm__(".extern D_L39_00241640, 16");
extern S_0068D6D8_p *D_L39_00241640;
extern u8 *D_001DC204_sda;
__asm__(".extern D_L39_00247914, 16");
extern u8 *D_L39_00247914;
extern s32 func_L39_0068AEF8(void *, s32);

s32 func_L39_0068D6D8(void *a0, s32 a1)
{
    s32 idx = -1;
    s32 i;
    u8 *slot;

    for (i = 0; i < 8; i++) {
        if (D_L39_00241640->eE0[i] == D_001A5CD0.w8) {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        return 0;
    }
    if ((D_L39_00241640 == 0 || D_L39_00241640->eF0[idx] != 5) && D_001A5CD0.b169 == 0 && D_001A5CD0.w2EC == 0) {
        if ((D_L39_00241640 == 0 || D_L39_00241640->eF0[0] < 7) && a1 != 7) {
            return func_L39_0068AEF8(a0, a1) != 0;
        }
        slot = D_L39_00247914;
    } else {
        slot = D_001DC204_sda;
    }
    *(s32 *)(slot + 0x284) = 0x2C;
    return 1;
}
/* localdecomp:end func_L39_0068D6D8 */
