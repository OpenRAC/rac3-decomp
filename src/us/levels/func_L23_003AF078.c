#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L23_003B0978, with a 180-frame lifetime. */
/* localdecomp:start func_L23_003AF078 */
extern u8 *func_003BCFB0(s32, s32);
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");

u8 *func_L23_003AF078(s32 a0, vu0_q *pos, vu0_q *target, s32 a3, s32 a4, s32 a5) {
    u8 *m = func_003BCFB0(0x1BC8, 0x80);
    u8 *v;

    if (m != 0) {
        m[0x20] = 0;
        m[0x30] = 0xFF;
        v = *(u8 **)(m + 0x68);
        *(vu0_q *)(m + 0x10) = *pos;
        *(vu0_q *)(v + 0x10) = *target;
        *(s32 *)(v + 0) = a3;
        *(s32 *)(v + 4) = a0;
        *(s32 *)(v + 8) = D_L23_001DECC0 + 180;
        *(s32 *)(v + 0xC) = a5;
    }
    return m;
}
/* localdecomp:end func_L23_003AF078 */
