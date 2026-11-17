#include "common.h"

/* localdecomp:start func_L02_0034FD58 */
extern u16 *D_L02_0021B460[];
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 16");
extern s32 D_L02_001DE9D8;

void func_L02_0034FD58(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF)
        return;
    p = D_L02_0021B460[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L02_001DE9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L02_0021B460[object[0x21]])) {
        entity = D_L02_001DE99C + ((*p & 0x7FFF) << 8);
        if (entity == 0)
            break;
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2D8) = 1;
        p++;
    }
}
/* localdecomp:end func_L02_0034FD58 */

/* localdecomp:start func_L04_003CE6A8 */
extern s16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern s32 D_L04_001DFDD8;

void func_L04_003CE6A8(u8 *self) {
    s16 *p;
    u8 *o;

    if (self[0x21] == 0xFF) {
        return;
    }
    p = D_L04_0021C9A0[self[0x21]];
    while (self[0x21] != 0xFF && self[0x21] <= D_L04_001DFDD8 && p != 0 && (p[-1] >= 0 || p == D_L04_0021C9A0[self[0x21]])) {
        o = D_L04_001DFD9C + ((*(u16 *)p & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        p++;
        if (*(s16 *)(o + 0xAA) == *(s16 *)(self + 0xAA)) {
            *(s32 *)(*(u8 **)(o + 0x68) + 0x2F8) = 1;
        }
    }
}
/* localdecomp:end func_L04_003CE6A8 */
