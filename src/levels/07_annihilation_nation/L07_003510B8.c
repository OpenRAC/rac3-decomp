#include "common.h"

/* localdecomp:start func_L07_003510B8 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003510B8(u8 *a0, s32 a1) {
    u8 *a24;
    u8 *base;
    s32 f34;
    s32 t;
    s32 v;
    u8 b43;

    base = *(u8 **)(a0 + 0x68);
    base = base + a1;
    if (base[0x280] != 0) {
        f34 = *(u16 *)(a0 + 0x34);
        a24 = *(u8 **)(a0 + 0x24);
        t = f34 & 0xFFBE;
        b43 = *(u8 *)(a0 + 0x43);
        *(u16 *)(a0 + 0x34) = t;
        t = t | (*(u16 *)(a24 + 0x44) & 0x1000);
        *(u16 *)(a0 + 0x34) = t;
        t = t & 0xFFFD;
        v = *(s32 *)(a24 + 0x10);
        *(u16 *)(a0 + 0x34) = t;
        *(s32 *)(a0 + 0x98) = v;
        if (b43 != 0) {
            func_003C3A10(a0, 0, 0, 0);
        }
        func_L01_004450F0(a0, 1, 0);
    }
}
/* localdecomp:end func_L07_003510B8 */
