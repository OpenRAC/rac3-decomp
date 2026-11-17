#include "common.h"

/* localdecomp:start func_L27_0039EF90 */
extern u16 *D_L27_0021B7E0[];
extern u8 *D_L27_001DED1C;
__asm__(".extern D_L27_001DED1C, 16");
extern s32 D_L27_001DED58;

void func_L27_0039EF90(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF)
        return;
    p = D_L27_0021B7E0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L27_001DED58 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L27_0021B7E0[object[0x21]])) {
        entity = D_L27_001DED1C + ((*p & 0x7FFF) << 8);
        if (entity == 0)
            break;
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x45C) = 1;
        p++;
    }
}
/* localdecomp:end func_L27_0039EF90 */
