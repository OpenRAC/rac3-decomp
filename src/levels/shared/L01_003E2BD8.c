#include "common.h"

/* localdecomp:start func_L01_003E2BD8 */
#include "vu0.h"
extern f32 D_L01_001DF5AC;
__asm__(".extern D_L01_001DF5AC, 4");
extern f32 D_L01_001DF5B0;
__asm__(".extern D_L01_001DF5B0, 4");
extern f32 D_L01_001DF5B4;
__asm__(".extern D_L01_001DF5B4, 4");
extern f32 D_L01_001DF5B8;
__asm__(".extern D_L01_001DF5B8, 4");
extern f32 D_L01_001DF5BC;
__asm__(".extern D_L01_001DF5BC, 4");
extern s32 D_L01_001DF5C0;
__asm__(".extern D_L01_001DF5C0, 4");
extern s32 D_L01_001DF5C4;
__asm__(".extern D_L01_001DF5C4, 4");
extern s32 D_L01_001DF5C8;
__asm__(".extern D_L01_001DF5C8, 4");
extern s32 D_L01_001DF5CC;
__asm__(".extern D_L01_001DF5CC, 4");
void func_L01_003E2BD8(u8 *moby, u8 *vars)
{
    extern s32 func_0038DBD8(s32, s32, f32);
    extern s32 func_L01_003E25B8(u8 *, u8 *, vu0_q *, s32, s32);
    s32 a, b, i;
    vu0_q position;
    switch (moby[0x20]) {
    case 2:
        if (*(f32 *)(vars + 8) < D_L01_001DF5AC || D_L01_001DF5B4 < *(f32 *)(vars + 8)) {
            a = 0;
        } else {
            if (*(f32 *)(vars + 8) < D_L01_001DF5B0)
                a = func_0038DBD8(D_L01_001DF5C4, D_L01_001DF5C0,
                    (*(f32 *)(vars + 8) - D_L01_001DF5AC) / (D_L01_001DF5B0 - D_L01_001DF5AC));
            else
                a = func_0038DBD8(D_L01_001DF5C0, D_L01_001DF5C4,
                    (*(f32 *)(vars + 8) - D_L01_001DF5B0) / (D_L01_001DF5B4 - D_L01_001DF5B0));
        }
        if (*(f32 *)(vars + 8) < D_L01_001DF5B8 || D_L01_001DF5BC < *(f32 *)(vars + 8)) {
            b = 0;
        } else {
            b = func_0038DBD8(D_L01_001DF5CC, D_L01_001DF5C8,
                (*(f32 *)(vars + 8) - D_L01_001DF5B8) / (D_L01_001DF5BC - D_L01_001DF5B8));
        }
        break;
    case 3:
        a = 0;
        b = func_0038DBD8(D_L01_001DF5C8, D_L01_001DF5CC, *(f32 *)(vars + 8));
        break;
    default:
        return;
    }
    if (a == 0 && b == 0) return;
    if ((*(u16 *)(*(u8 **)(moby + 0xB8) + 0x34) & 0x20) &&
        *(u8 **)(*(u8 **)(moby + 0x68) + 0x1C)) {
        position = *(vu0_q *)(*(u8 **)(*(u8 **)(moby + 0x68) + 0x1C) + 0xA0);
    } else {
        qzero(&position);
    }
    func_L01_003E25B8(*(u8 **)(moby + 0xB8), vars, &position, a, b);
    for (i = 0; i < *(s32 *)(vars + 0xC); i++) {
        func_L01_003E25B8(*(u8 **)(vars + 0x20 + i * 4), vars, &position, a, b);
    }
}
/* localdecomp:end func_L01_003E2BD8 */
