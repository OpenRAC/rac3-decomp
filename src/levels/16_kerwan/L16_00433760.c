#include "common.h"

typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L16_002F2360;
typedef struct { u8 p0[0x44]; s32 f44; } S_L16_00433760_b;
typedef struct { u8 p0[0x30]; s32 f30; u8 p34[0x1C]; S_L16_00433760_b *f50; } S_L16_001E6EC0;

/* localdecomp:start func_L16_00433760 */
extern f32 D_L16_001D6B94;
extern u8 D_L16_001D6B00;
extern u8 D_L16_001D6AF5;
extern S_L16_002F2360 D_L16_002F2360;
extern u8 D_L16_002F23B0[];
extern s32 D_L16_001E6EF0[];
extern S_L16_001E6EC0 D_L16_001E6EC0;
extern u32 D_001D545C_00433760;
__asm__(".extern D_001D545C_00433760, 16");
extern s32 D_001A5E80[];
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
void func_L16_00433760(void) {
    u8 *q;
    D_L16_001D6B94 = 1.0f;
    D_L16_002F2360.f20 = &D_L16_001D6B00;
    D_L16_002F2360.f30 = 1;
    q = 0;
    D_L16_001D6AF5 = 0;
    if (D_001D545C_00433760 == 16 && D_L16_001E6EF0[0] == 0) {
        q = D_L16_002F23B0;
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
    if (D_001D545C_00433760 == 16 && D_L16_001E6EC0.f30 == 0 && D_L16_001E6EC0.f50 != 0) {
        if (D_001A5E80[0] != 0) D_L16_001E6EC0.f50->f44 = D_001A5E80[0];
    }
}
/* localdecomp:end func_L16_00433760 */
