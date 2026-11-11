#include "common.h"

INCLUDE_ASM("asm/levels", func_L11_00350EE0);

INCLUDE_ASM("asm/levels", func_L11_003510D0);

/* localdecomp:start func_L11_003514D8 */
extern char D_001A4CC0[];
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003514D8(void) {
    func_003D9508(D_001A4CC0, 5, 0x3FFF2020, 1, 1.2f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003514D8 */

/* localdecomp:start func_L11_00351528 */
typedef int u128_351528 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
__asm__(".extern D_L11_001DD3A0, 4");
extern s32 D_L11_001DD3A0;

u8 *func_L11_00351528(u128_351528 *m, u128_351528 *a, u128_351528 *b)
{
    u128_351528 s[6];
    u8 *moby;
    u128_351528 *v;

    s[0] = m[0];
    s[1] = m[1];
    s[2] = m[2];
    s[3] = m[3];
    s[4] = *a;
    s[5] = *b;
    moby = func_003C24B0(0x1695, 0x80);
    if (moby != 0) {
        moby[0x30] = 0xFF;
        *(u16 *)(moby + 0x32) = 0x40;
        *(u16 *)(moby + 0x34) &= 0xFFBE;
        *(u128_351528 *)(moby + 0x10) = *(u128_351528 *)D_001A4CC0;
        v = *(u128_351528 **)(moby + 0x68);
        v[0] = s[0];
        v[4] = s[4];
        v[5] = s[5];
        D_L11_001DD3A0++;
    }
    return moby;
}
/* localdecomp:end func_L11_00351528 */

/* localdecomp:start func_L11_003515E0 */
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L11_0034F0F0(void *, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L11_003515E0(u8 *a0) {
    if (func_L01_00447490(a0, 0x10000, 0) != 0) {
        func_L11_0034F0F0(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 2.0f, 1, 1, 0x3FFF2020);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L11_003515E0 */
