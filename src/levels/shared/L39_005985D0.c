#include "common.h"

/* localdecomp:start func_L39_005985D0 */
extern s32 D_001FC458[];
__asm__(".extern D_L39_00240300, 16");
extern s32 D_L39_00240300;
extern s32 func_0013A088(void *, s16, s16, s32, s16, s16, s16, s16);
extern void func_001264E0(s32);
extern void func_0013A348(void *, s32);

void func_L39_005985D0(s16 a0, s16 a1, s16 a2, s16 a3, s32 a4) {
    s32 h = D_L39_00240300;
    s32 buf[28];
    s32 w = D_001FC458[0];
    func_0013A088(buf, w >> 8, h >> 6, 0x30, a0, a1, a2, a3);
    func_001264E0(0);
    func_0013A348(buf, a4);
}
/* localdecomp:end func_L39_005985D0 */
