#include "common.h"

/* NTSC-U counterpart of func_L07_003B8C50 (src/levels/07_annihilation_nation/L07_003B7408.c) */
extern void func_L07_003B6DA0(void *, s32);
extern void func_L07_003B6DA0(void *, s32);

/* localdecomp:start func_L07_003B7360 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L07_001DF500_003B7360;
extern void func_L07_003A0BC0(s32, void *, s32, s32);
extern void func_L07_003B6DA0(void *, s32);

void func_L07_003B7360(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (s[0x296] == 1) {
        func_L07_003A0BC0(0xF, a0, 0, 0x78);
    }
    s[0x299] = 0;
    *(u128_t *)(s + 0x270) = *(u128_t *)(&D_L07_001DF500_003B7360[(*(s32 *)(s + 0x284) << 7) + 0x30]);
    s[0x298] = 2;
    s[0x297] = 0xE;
    *(s32 *)(s + 0x290) = 0;
    func_L07_003B6DA0(a0, 10);
}
/* localdecomp:end func_L07_003B7360 */
