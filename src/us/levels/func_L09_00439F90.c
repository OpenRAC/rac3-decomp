#include "common.h"

/* localdecomp:start func_L09_00439F90 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_L09_002E7160;
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; } S_L09_001E6F40;
extern f32 D_001D6B44_sda_00439F90;
__asm__(".extern D_001D6B44_sda_00439F90, 4");
extern u8 D_001D6AB0_sda_00439F90;
__asm__(".extern D_001D6AB0_sda_00439F90, 1");
extern u8 D_001D6AA5_sda_00439F90;
__asm__(".extern D_001D6AA5_sda_00439F90, 1");
extern S_L09_002E7160 D_L09_002E7160;
extern S_L09_001E6F40 D_L09_001E6F40;
extern u8 D_L09_002E71B0[];
extern u8 D_L09_002E7210[];
extern u8 D_L09_002E7270[];
extern u32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_004203A8(void *, s32, s32, s32, s32, s32, s32);
void func_L09_00439F90(void) {
    u8 *q;
    D_001D6B44_sda_00439F90 = 1.0f;
    D_L09_002E7160.f20 = &D_001D6AB0_sda_00439F90;
    D_L09_002E7160.f30 = 1;
    q = 0;
    D_001D6AA5_sda_00439F90 = 0;
    if (D_001D545C == 9) {
        switch (D_L09_001E6F40.f30) {
        case 0:
            if (D_L09_001E6F40.f34 < 0xF5) q = D_L09_002E71B0;
            else q = D_L09_002E7210;
            break;
        case 1:
            q = D_L09_002E7270;
            break;
        }
    }
    if (q != 0) func_L01_004203A8(q, 0, 0, 0, 0, 1, 0);
}
/* localdecomp:end func_L09_00439F90 */
