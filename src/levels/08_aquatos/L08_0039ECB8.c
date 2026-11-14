#include "common.h"

/* localdecomp:start func_L08_0039ECB8 */
extern u16 *D_L08_0021BEA0[];
extern u8 *D_L08_001DF21C;
__asm__(".extern D_L08_001DF21C, 16");
extern s32 D_L08_001DF258;

void func_L08_0039ECB8(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L08_0021BEA0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L08_001DF258 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L08_0021BEA0[a0[0x21]])) {
        e = D_L08_001DF21C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x198) = 1;
        }
    }
}
/* localdecomp:end func_L08_0039ECB8 */
