#include "common.h"

/* localdecomp:start func_L21_003FCAA8 */
typedef struct { char p0[0x20]; u8 *f20; char p24[0xC]; s32 f30; } S_003FCAA8;
extern S_003FCAA8 D_L21_002EF460;
__asm__(".extern D_L21_002EF460, 16");
extern u8 D_L21_002EF4B0[];
__asm__(".extern D_L21_002EF4B0, 16");
extern s32 D_L21_001E5A70[];
__asm__(".extern D_L21_001E5A70, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D6B00_sda;
__asm__(".extern D_001D6B00_sda, 4");
extern u8 D_001D6AF5_sda;
__asm__(".extern D_001D6AF5_sda, 4");
extern f32 D_001D6B94_sda;
__asm__(".extern D_001D6B94_sda, 4");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);

void func_L21_003FCAA8(void)
{
    S_003FCAA8 *a = &D_L21_002EF460;
    u8 *b = 0;
    D_001D6B94_sda = 1.0f;
    a->f20 = &D_001D6B00_sda;
    a->f30 = 1;
    D_001D6AF5_sda = 0;
    if (D_001D545C == 0x15 && D_L21_001E5A70[0] == 2) {
        b = D_L21_002EF4B0;
    }
    if (b != 0) {
        func_L01_00423068(b, 0, 0, 0, 0, 1, 0);
    }
}
/* localdecomp:end func_L21_003FCAA8 */
