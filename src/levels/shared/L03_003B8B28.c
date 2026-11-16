#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003B8B28);

/* localdecomp:start func_L03_003B8DF8 */
typedef int u128_3B8DF8 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L03_003B9130(u8 *, void *);
__asm__(".extern D_L03_001DEA88, 4");
extern s32 D_L03_001DEA88;
extern u8 D_L03_001E1E08[8];

u8 *func_L03_003B8DF8(u8 *a0, s32 a1, f32 a2) {
    u8 *m = func_003C24B0(0x1C16, 0x80);
    u8 *mv;
    u8 *pv;
    if (m != 0) {
        mv = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(mv + 0x20) = a2 * 0.020000001f;
        *(s32 *)(mv + 0x24) = 0;
        *(s32 *)(mv + 0x2C) = a1;
        pv = *(u8 **)(a0 + 0x68);
        func_003C2F58(*(void **)pv, a1, mv + 0x10);
        func_003C2F58(*(void **)pv, a1 - 0x20, mv);
        *(s32 *)(mv + 0x28) = *(s32 *)pv;
        *(u128_3B8DF8 *)(m + 0x10) = *(u128_3B8DF8 *)(mv + 0x10);
    }
    if (D_L03_001DEA88 == 0) {
        D_L03_001DEA88 = 1;
        func_L03_0034B218(D_L03_001E1E08, 0x19, 0x11, 2.1f, 2, func_L03_003B9130);
    }
    return m;
}
/* localdecomp:end func_L03_003B8DF8 */
