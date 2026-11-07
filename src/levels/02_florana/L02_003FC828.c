#include "common.h"

/* localdecomp:start func_L02_003FC828 */
typedef struct { char p0[0x20]; u8 *f20; char p24[0xC]; s32 f30; } S_3FC828;
extern S_3FC828 D_L02_002E44A0;
__asm__(".extern D_L02_002E44A0, 16");
extern u8 D_L02_002E44F0[];
__asm__(".extern D_L02_002E44F0, 16");
extern s32 D_L02_001E5670[];
__asm__(".extern D_L02_001E5670, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D6AB0_sda;
__asm__(".extern D_001D6AB0_sda, 4");
extern u8 D_001D6AA5_sda;
__asm__(".extern D_001D6AA5_sda, 4");
extern f32 D_001D6B44_sda;
__asm__(".extern D_001D6B44_sda, 4");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);

void func_L02_003FC828(void)
{
    S_3FC828 *a = &D_L02_002E44A0;
    u8 *b = 0;
    D_001D6B44_sda = 1.0f;
    a->f20 = &D_001D6AB0_sda;
    a->f30 = 1;
    D_001D6AA5_sda = 0;
    if (D_001D545C == 2 && D_L02_001E5670[0] == 3) {
        b = D_L02_002E44F0;
        D_001D6B44_sda = -1.0f;
    }
    if (b != 0) {
        func_L01_00423068(b, 0, 0, 0, 0, 1, 0);
    }
}
/* localdecomp:end func_L02_003FC828 */
