#include "common.h"

/* localdecomp:start func_L31_00347868 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003C2880(u8 *a0);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

s32 func_L31_00347868(u8 *moby, u8 *info) {
    s32 flags = *(s32 *)(info + 32);
    *(s32 *)(info + 32) = flags & ~4;
    if ((flags & 2) || (info[32] ^ 1) & 1) {
        func_003C2880(moby);
        return 1;
    }
    *(u128_t *)(moby + 16) = *(u128_t *)info;
    *(u16 *)(moby + 52) = (*(u16 *)(moby + 52) | 0x41) & 0xEFFF;
    *(s32 *)(moby + 152) = 0;
    func_L01_004AA7E8(moby, 1);
    return 0;
}
/* localdecomp:end func_L31_00347868 */

INCLUDE_ASM("asm/levels", func_L31_003478E8);

INCLUDE_ASM("asm/levels", func_L31_00347938);

/* localdecomp:start func_L31_00347CB8 */
extern s32 D_L31_001DF340[];
s32 func_L31_00347CB8(s32 a0, s32 a1, s32 a2, s32 *a3) {
    s32 t = D_L31_001DF340[0];
    s32 v = t + a0 - a1;
    s32 w;
    if (a0 <= 0 || a2 <= 0) {
        return 0;
    }
    w = -a0;
    if (a3 != 0) {
        w = *a3;
    }
    if (v % a0 < a2 && w + a2 < t) {
        if (a3 != 0) {
            *a3 = t;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L31_00347CB8 */
