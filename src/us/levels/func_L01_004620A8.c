#include "common.h"

/* NTSC-U counterpart of func_L01_00465650 (src/levels/shared/L01_00462978.c) */
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_004620A8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E2A40_004620A8;
void func_L01_004620A8(u8 *self) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern void func_00388830(void *, void *, f32);
    u8 *state = self + 0x20;
    vu0_v4 delta;
    self[8] += state[0];
    if (*(s32 *)(state + 4) == 0) {
        *(vu0_q *)(self + 0x10) = *(vu0_q *)(*(u8 **)(state + 8) + 0x10);
        vec_sub_ba(&delta, &D_L01_001E2A40_004620A8, self + 0x10);
        func_00388830(&delta, &delta, 0.01f);
        vec_add_ab(self + 0x10, self + 0x10, &delta);
    } else if (func_003883C8(self + 0xA)) {
        func_003C7CE0(self);
    } else {
        *(s32 *)(self + 4) = ((s32)(*(s16 *)(self + 0xA) * 21.166666f) << 24) | 0xFFFFFF;
    }
}
/* localdecomp:end func_L01_004620A8 */
