#include "common.h"

/* localdecomp:start func_L17_003FF1F0 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L17_002EE260;
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; } S_L17_001E5CC0;
typedef struct { u8 p0[0x38]; s32 f38; } S_L17_002EE310;
extern f32 D_L17_001D6B44;
extern u8 D_L17_001D6AB0;
extern u8 D_L17_001D6AA5;
extern S_L17_002EE260 D_L17_002EE260;
extern S_L17_001E5CC0 D_L17_001E5CC0;
extern S_L17_002EE310 D_L17_002EE310;
extern u8 D_L17_002EE2B0[];
extern u32 D_001D545C_003FF1F0;
__asm__(".extern D_001D545C_003FF1F0, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
void func_L17_003FF1F0(void) {
    void *q;
    D_L17_001D6B44 = 1.0f;
    D_L17_002EE260.f20 = &D_L17_001D6AB0;
    D_L17_002EE260.f30 = 1;
    q = 0;
    D_L17_001D6AA5 = 0;
    if (D_001D545C_003FF1F0 == 17 && D_L17_001E5CC0.f30 == 2) {
        q = &D_L17_002EE310;
        if (D_L17_001E5CC0.f34 < (D_L17_002EE310.f38 * 5 + 2) / 6) q = D_L17_002EE2B0;
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L17_003FF1F0 */
