#include "common.h"

/* localdecomp:start func_L01_00423A10 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L01_002E68E0;
extern f32 D_L01_001D6B94;
extern u8 D_L01_001D6B00;
extern u8 D_L01_001D6AF5;
extern S_L01_002E68E0 D_L01_002E68E0;
extern u8 D_L01_002E6930[];
extern u8 D_L01_002E6990[];
extern s32 D_L01_001E6DB0_00423A10[];
extern u32 D_001D545C_00423A10;
__asm__(".extern D_001D545C_00423A10, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
void func_L01_00423A10(void) {
    u8 *q;
    D_L01_001D6B94 = 1.0f;
    D_L01_002E68E0.f20 = &D_L01_001D6B00;
    D_L01_002E68E0.f30 = 1;
    q = 0;
    D_L01_001D6AF5 = 0;
    if (D_001D545C_00423A10 == 1) {
        switch (D_L01_001E6DB0_00423A10[0]) {
        case 3:
            q = D_L01_002E6930;
            break;
        case 4:
            q = D_L01_002E6990;
            break;
        }
    }
    if (q != 0) func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L01_00423A10 */
