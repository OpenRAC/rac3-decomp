#include "common.h"

/* NTSC-U counterpart of func_L01_00468828 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(u8 *);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern s32 func_0037E1D8(s32);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern s32 func_003883C8(u8 *);
#include "structs/hero.h"

/* localdecomp:start func_L01_004651D0 */
#include "vu0.h"
extern f32 D_L01_001E2A58_004651D0[];
void func_L01_004651D0(u8 *self) {
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern s32 func_0037E1D8(s32);
    extern f32 func_003887A0(void *);
    extern void func_00388880(void *, void *, f32);
    extern void func_003BEBF8(f32 *, f32, f32);
    extern f32 func_00389380(f32, f32);
    extern f32 func_00388978(f32);
    extern f32 func_00388960(f32);
    u8 *vars = self + 0x20;
    f32 velocity[4] __attribute__((aligned(16)));
    f32 angle, radius;
    s32 alpha;
    if (func_003883C8(self + 0xA)) { func_003C7CE0(self); return; }
    if (*(f32 *)(self + 0x18) > *(f32 *)(vars + 0x10)) {
        *(s32 *)(vars + 8) = 0;
        if (*(s16 *)(self + 0xA) > 12) *(s16 *)(self + 0xA) = 12;
    }
    if (*(f32 *)(self + 0x18) + 0.8666666746139526f > *(f32 *)(vars + 0x10)) {
        if (func_0037E1D8(20) == 0 && *(s16 *)(self + 0xA) > 12) *(s16 *)(self + 0xA) = 12;
    }
    if (*(s16 *)(self + 0xA) < 14) {
        alpha = *(u32 *)(self + 4) >> 24;
        *(u32 *)(self + 4) = ((alpha * *(s16 *)(self + 0xA) / 14) << 24) | (*(u32 *)(self + 4) & 0xFFFFFF);
    }
    *(f32 *)(self + 0xC) += 840.0000610351562f;
    if (*(f32 *)(self + 0xC) > *(f32 *)(vars + 0xC)) *(f32 *)(self + 0xC) = *(f32 *)(vars + 0xC);
    velocity[0] = *(f32 *)(vars + 0);
    velocity[1] = *(f32 *)(vars + 4);
    velocity[2] = *(f32 *)(vars + 8);
    func_00388880(velocity, velocity, func_003887A0(velocity) * 0.9700000286102295f);
    vec_add_ba(self + 0x10, self + 0x10, velocity);
    func_003BEBF8(&velocity[2], 0.021666666492819786f, 0.0013888889225199819f);
    *(f32 *)(vars + 4) = velocity[1];
    *(f32 *)(vars + 0) = velocity[0];
    *(f32 *)(vars + 8) = velocity[2];
    *(f32 *)(vars + 0x14) = func_00389380(*(f32 *)(vars + 0x14), *(f32 *)(vars + 0x18));
    angle = func_00389380(D_L01_001E2A58_004651D0[0], 1.5707963705062866f);
    radius = func_00388978(*(f32 *)(vars + 0x14)) * *(f32 *)(vars + 0x1C);
    velocity[0] = func_00388960(angle) * radius;
    velocity[1] = func_00388978(angle) * radius;
    velocity[2] = 0.0f;
    vec_add_ab(self + 0x10, self + 0x10, velocity);
}
/* localdecomp:end func_L01_004651D0 */
