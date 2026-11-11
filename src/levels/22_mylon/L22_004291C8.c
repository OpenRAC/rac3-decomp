#include "common.h"

/* localdecomp:start func_L22_004291C8 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L22_002E83A0;
extern f32 D_L22_001D6B44;
extern u8 D_L22_001D6AB0;
extern u8 D_L22_001D6AA5;
extern S_L22_002E83A0 D_L22_002E83A0;
extern u8 D_L22_002E83F0[];
extern s32 D_L22_001E6E70_004291C8[];
extern u32 D_001D545C_004291C8;
__asm__(".extern D_001D545C_004291C8, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
void func_L22_004291C8(void) {
    u8 *q;
    D_L22_001D6B44 = 1.0f;
    D_L22_002E83A0.f20 = &D_L22_001D6AB0;
    D_L22_002E83A0.f30 = 1;
    q = 0;
    D_L22_001D6AA5 = 0;
    if (D_001D545C_004291C8 == 0x16 && D_L22_001E6E70_004291C8[0] == 0) {
        q = D_L22_002E83F0;
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L22_004291C8 */
