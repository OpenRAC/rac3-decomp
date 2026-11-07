#include "common.h"

/* localdecomp:start func_L13_004050E0 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L13_002E5220;
extern f32 D_L13_001D6B44;
extern u8 D_L13_001D6AB0;
extern u8 D_L13_001D6AA5;
extern S_L13_002E5220 D_L13_002E5220;
extern u8 D_L13_002E5270[];
extern s32 D_L13_001E64B0_004050E0[];
extern u32 D_001D545C_004050E0;
__asm__(".extern D_001D545C_004050E0, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
void func_L13_004050E0(void) {
    u8 *q;
    D_L13_001D6B44 = 1.0f;
    D_L13_002E5220.f20 = &D_L13_001D6AB0;
    D_L13_002E5220.f30 = 1;
    q = 0;
    D_L13_001D6AA5 = 0;
    if (D_001D545C_004050E0 == 13 && D_L13_001E64B0_004050E0[0] == 2) {
        D_L13_001D6B44 = -1.0f;
        q = D_L13_002E5270;
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L13_004050E0 */
