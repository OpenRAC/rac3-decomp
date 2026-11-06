#include "common.h"

/* localdecomp:start func_L12_004254A8 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L12_002E6920;
extern f32 D_L12_001D6B94;
extern u8 D_L12_001D6B00;
extern u8 D_L12_001D6AF5;
extern S_L12_002E6920 D_L12_002E6920;
extern u8 D_L12_002E6970[];
extern s32 D_L12_001E6AF0_004254A8[];
extern u32 D_001D545C_004254A8;
__asm__(".extern D_001D545C_004254A8, 16");
extern void func_L12_00424B00(void *, s32, s32, s32, s32, s32, s32);
void func_L12_004254A8(void) {
    u8 *q;
    D_L12_001D6B94 = 1.0f;
    D_L12_002E6920.f20 = &D_L12_001D6B00;
    D_L12_002E6920.f30 = 1;
    q = 0;
    D_L12_001D6AF5 = 0;
    if (D_001D545C_004254A8 == 12 && D_L12_001E6AF0_004254A8[0] == 1) {
        D_L12_001D6B94 = -1.0f;
        q = D_L12_002E6970;
    }
    if (q != 0) func_L12_00424B00(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L12_004254A8 */
