#include "common.h"

/* localdecomp:start func_L17_003FC5C8 */
typedef struct { char p0[0x20]; u8 *f20; char p24[0xC]; s32 f30; } S_L17_002EE220;
typedef struct { char p0[0x38]; s32 f38; } S_L17_002EE2D0;
extern S_L17_002EE220 D_L17_002EE220;
__asm__(".extern D_L17_002EE220, 16");
extern S_L17_002EE2D0 D_L17_002EE2D0;
__asm__(".extern D_L17_002EE2D0, 16");
extern u8 D_L17_002EE270[];
__asm__(".extern D_L17_002EE270, 16");
extern s32 D_L17_001E5CC0_003FC5C8[];
__asm__(".extern D_L17_001E5CC0_003FC5C8, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D6AB0_sda_003FC5C8;
__asm__(".extern D_001D6AB0_sda_003FC5C8, 4");
extern u8 D_001D6AA5_sda_003FC5C8;
__asm__(".extern D_001D6AA5_sda_003FC5C8, 4");
extern f32 D_001D6B44_sda_003FC5C8;
__asm__(".extern D_001D6B44_sda_003FC5C8, 4");
extern void func_L01_004203A8(void *, s32, s32, s32, s32, s32, s32);

void func_L17_003FC5C8(void)
{
    S_L17_002EE220 *a = &D_L17_002EE220;
    u8 *b = 0;
    D_001D6B44_sda_003FC5C8 = 1.0f;
    a->f20 = &D_001D6AB0_sda_003FC5C8;
    a->f30 = 1;
    D_001D6AA5_sda_003FC5C8 = 0;
    if (D_001D545C == 0x11 && D_L17_001E5CC0_003FC5C8[12] == 2) {
        if (D_L17_001E5CC0_003FC5C8[13] < D_L17_002EE2D0.f38) {
            b = D_L17_002EE270;
        } else {
            b = (u8 *)&D_L17_002EE2D0;
        }
    }
    if (b != 0) {
        func_L01_004203A8(b, 0, 0, 0, 0, 1, 0);
    }
}
/* localdecomp:end func_L17_003FC5C8 */
