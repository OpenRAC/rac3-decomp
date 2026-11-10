#include "common.h"
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L23_002E7A20;

/* localdecomp:start func_L23_00406898 */
extern f32 D_L23_001D6B64;
extern u8 D_L23_001D6AD0;
extern u8 D_L23_001D6AC5;
extern S_L23_002E7A20 D_L23_002E7A20;
extern u8 D_L23_002E7A70[];
extern s32 D_L23_001E5DB0[];
extern u32 D_001D545C_00406898;
__asm__(".extern D_001D545C_00406898, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
void func_L23_00406898(void) {
    u8 *q;
    D_L23_001D6B64 = 1.0f;
    D_L23_002E7A20.f20 = &D_L23_001D6AD0;
    D_L23_002E7A20.f30 = 1;
    q = 0;
    D_L23_001D6AC5 = 0;
    if (D_001D545C_00406898 == 23 && D_L23_001E5DB0[0] == 0) {
        q = D_L23_002E7A70;
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L23_00406898 */
