#include "common.h"

/* localdecomp:start func_L20_003FB1F0 */
__asm__(".extern D_L20_001E029C, 16");
extern u8 *D_L20_001E029C;
__asm__(".extern D_L20_001E02D8, 4");
extern s32 D_L20_001E02D8;
extern u16 *D_L20_0021CFE0[];

void func_L20_003FB1F0(u8 *a0) {
    u16 *p;
    u8 *e;

    if (a0[0x21] == 0xFF) {
        return;
    }
    p = D_L20_0021CFE0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L20_001E02D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L20_0021CFE0[a0[0x21]])) {
        e = D_L20_001E029C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2E8) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L20_003FB1F0 */
