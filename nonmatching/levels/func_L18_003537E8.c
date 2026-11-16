/* PAL near miss (Claude wave S/pal): near miss: 10 words differ with the file's flags.
 * Worker's note: needs @ps2as (0.2f/0.02f lui/ori/mtc1; file line L18_00350FB0.c lacks it) and even then 10 diff: retail has the struct address in v1 (lui v1 hoisted before the float loads) and the 0x19 constant in v0, mine the reverse (statement orders, local struct pointer, ...
 */
#include "common.h"

/* localdecomp:start func_L18_003537E8 */
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    f32 f30;
    s32 f34;
    s32 f38;
    u8 pad3C[4];
    f32 f40;
    s32 f44;
    s32 f48;
} Q_003537E8;

extern Q_003537E8 D_L18_001E2AC0_003537E8;
__asm__(".extern D_L18_001E2AC0_003537E8, 0x50");
extern void func_L01_003F1F20(s32, s32);
extern void func_003A52A0(s32, s32, void *);

void func_L18_003537E8(void *obj) {
    func_L01_003F1F20(0x12, 0);
    D_L18_001E2AC0_003537E8.f20 = 0.5f;
    D_L18_001E2AC0_003537E8.f30 = 0.2f;
    D_L18_001E2AC0_003537E8.f40 = 0.02f;
    D_L18_001E2AC0_003537E8.f48 = 0x19;
    D_L18_001E2AC0_003537E8.f2C = 0;
    D_L18_001E2AC0_003537E8.f28 = 0x19;
    D_L18_001E2AC0_003537E8.f38 = 0x19;
    func_003A52A0(6, 0, obj);
}
/* localdecomp:end func_L18_003537E8 */
