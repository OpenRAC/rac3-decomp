#include "common.h"

/* declared by functions of L39_00688400.c, which this file was cut from */
extern s32 D_L39_003D2880[];
extern void func_L01_00516AA0();
extern u8 D_001DC30A_sda;
extern void func_L01_00516470(int);
void func_L01_00516AA0(s32);

/* localdecomp:start func_L39_00689D28 */
extern s32 D_L39_003D2880[];
extern u8 D_L39_0024D830[8];
extern f32 D_001DC330_sda;
__asm__(".extern D_001DC330_sda, 4");
__asm__(".extern D_001DC30A_sda, 1");
extern void func_00120D28();
extern void func_L01_00516FD8();
extern void func_L01_00518010();
extern void func_003E8898(s32, f32, f32);
void func_L39_00689D28(s32 a0, s32 a1) {
    if (D_001DC30A_sda) {
        func_00120D28(D_L39_0024D830, a1, 0x1F);
        D_L39_0024D830[0x1F] = 0;
        func_L01_00516FD8(D_L39_003D2880[0x34 / 4], D_L39_0024D830);
        ((void (*)(s32, f32, f32))func_L01_00516470)(D_L39_003D2880[0x34 / 4], D_001DC330_sda, 0.93f);
        func_L01_00518010(D_L39_003D2880[0x34 / 4], 1);
        func_003E8898(D_L39_003D2880[0x34 / 4], 0.24f, 0.0f);
    }
}
/* localdecomp:end func_L39_00689D28 */

INCLUDE_ASM("asm/levels", func_L39_00689DB8);

INCLUDE_ASM("asm/levels", func_L39_00689E58);
