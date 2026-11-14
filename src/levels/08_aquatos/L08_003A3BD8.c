#include "common.h"

/* localdecomp:start func_L08_003A3BD8 */
extern s16 *D_L08_0021BEA0[];
extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF21C, 16");
extern s32 D_L08_001DF258;

void func_L08_003A3BD8(u8 *self) {
    s16 *p;
    u8 *o;

    if (self[0x21] == 0xFF) {
        return;
    }
    p = D_L08_0021BEA0[self[0x21]];
    while (self[0x21] != 0xFF && self[0x21] <= D_L08_001DF258 && p != 0 && (p[-1] >= 0 || p == D_L08_0021BEA0[self[0x21]])) {
        o = D_L08_001DF21C + ((*(u16 *)p & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        p++;
        if (*(s16 *)(o + 0xAA) == *(s16 *)(self + 0xAA)) {
            *(s32 *)(*(u8 **)(o + 0x68) + 0x314) = 1;
        }
    }
}
/* localdecomp:end func_L08_003A3BD8 */
