/* near miss (level 4, Marcadia): 7 differences: scheduling: the store of the 10th argument (sw $v0,8($sp)) and sw $zero,0($sp) come earlier than retail; tested against src/levels/04_marcadia/L04_003ECC40.c with tools/check.py */
#include "common.h"

/* localdecomp:start func_L04_003ECE58 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3ECE58;

extern u8 D_L04_001D66B0[8];
__asm__(".extern D_L04_001D66B0, 16");
extern f32 D_001DF400_sda;
__asm__(".extern D_001DF400_sda, 4");
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00452460(void *, s32, s32);
extern void func_L04_003ECC40(void *, void *, void *);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L04_003ECE58(u8 *self) {
    V4_3ECE58 tmp;
    V4_3ECE58 src;
    if (func_L01_00447490(self, -1, 0) != 0) {
        func_003A52A0(0, 0, self);
        func_L01_00451FE0(self, 0x1F, D_L04_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 2.0f, 4.0f, 2.0f, 5.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00452460(self, 0x1F22, 0);
        *(u128_t *)&src = 0;
        src.z = D_001DF400_sda;
        tmp = src;
        func_L04_003ECC40(self, self + 0x10, &tmp);
        func_L01_00451E78(self, 1, 0.0f);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L04_003ECE58 */
