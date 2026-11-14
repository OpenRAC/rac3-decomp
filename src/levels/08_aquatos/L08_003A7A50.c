#include "common.h"

/* localdecomp:start func_L08_003A7A50 */
extern u16 *D_L08_0021BEA0[];
extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF258, 4");
extern s32 D_L08_001DF258;
extern void func_L01_00445BE0(s32, s32);

void func_L08_003A7A50(u8 *object)
{
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF)
        return;
    func_L01_00445BE0(object[0x21], 0);
    p = D_L08_0021BEA0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L08_001DF258 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L08_0021BEA0[object[0x21]])) {
        entity = D_L08_001DF21C + ((*p & 0x7FFF) << 8);
        if (entity == 0)
            break;
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2D8) = 1;
        p++;
    }
}
/* localdecomp:end func_L08_003A7A50 */
