#include "common.h"

/* localdecomp:start func_L14_00355FE0 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L06_00351930(void *, void *, s32, s32, s32);

void func_L14_00355FE0(u8 *a0) {
    u8 *m;
    u16 v;

    m = *(u8 **)(a0 + 0x68);
    {
        u8 *z = *(u8 **)(a0 + 0x24);
        v = *(u16 *)(a0 + 0x34) & 0xFFBE;
        *(u16 *)(a0 + 0x34) = v;
        v |= *(u16 *)(z + 0x44) & 0x1000;
        *(u16 *)(a0 + 0x34) = v;
        *(s32 *)(a0 + 0x98) = *(s32 *)(z + 0x10);
    }

    {
        u8 *y = *(u8 **)(m + 0x260);
        *(u16 *)(y + 0x34) = *(u16 *)(y + 0x34) & 0xFFBE;
    }

    {
        u8 *y = *(u8 **)(m + 0x260);
        u8 *z = *(u8 **)(y + 0x24);
        v = *(u16 *)(y + 0x34);
        v |= *(u16 *)(z + 0x44) & 0x1000;
        *(u16 *)(y + 0x34) = v;
    }

    {
        u8 *y = *(u8 **)(m + 0x260);
        *(s32 *)(y + 0x98) = *(s32 *)(*(u8 **)(y + 0x24) + 0x10);
    }

    func_L01_004450F0(a0, 1, 7);
    func_L06_00351930(a0, m, 0, 0, 0);
}
/* localdecomp:end func_L14_00355FE0 */

/* localdecomp:start func_L14_00356098 */
void func_L14_00356098(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x26C) = 2;
}
/* localdecomp:end func_L14_00356098 */
