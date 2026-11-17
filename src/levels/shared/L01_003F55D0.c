#include "common.h"

/* localdecomp:start func_L01_003F55D0 */
typedef struct {
    u8 pad[0xD4];
    f32 fD4;
    f32 fD8;
    f32 fDC;
    s32 iE0;
    u8 pad2[0x460 - 0xE4];
} T_1120;
extern T_1120 D_L01_001E2AA0[];

void func_L01_003F55D0(s32 a0, s32 a1, f32 f12, f32 f13) {
    T_1120 *p = &D_L01_001E2AA0[a0];
    if (p->fDC == 0.0f) {
        p->iE0 = a1;
        p->fDC = 1.0f;
        p->fD4 = 1.0f / f12;
        p->fD8 = 1.0f / f13;
    }
}
/* localdecomp:end func_L01_003F55D0 */
