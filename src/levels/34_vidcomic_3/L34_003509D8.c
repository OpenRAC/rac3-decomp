#include "common.h"

/* localdecomp:start func_L34_003509D8 */
extern u16 *D_L34_0021C5A0[];
extern u8 *D_L34_001DF79C;
__asm__(".extern D_L34_001DF79C, 16");
extern s32 D_001DF7D8_sda;

void func_L34_003509D8(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF)
        return;
    p = D_L34_0021C5A0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_001DF7D8_sda && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L34_0021C5A0[object[0x21]])) {
        entity = D_L34_001DF79C + ((*p & 0x7FFF) << 8);
        if (entity == 0)
            break;
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x270) = 1;
        p++;
    }
}
/* localdecomp:end func_L34_003509D8 */
