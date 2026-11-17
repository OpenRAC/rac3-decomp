#include "common.h"

/* declared by functions of L21_003A3BA0.c, which this file was cut from */
extern s32 func_0038CAD0(void *);
extern s32 func_00382468(s32 a0);

/* localdecomp:start func_L21_003A43E8 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_003A2A78.c */
extern s32 D_L21_001DE0E4;
__asm__(".extern D_L21_001DE0E4, 4");
extern s32 D_L21_001DE8C0;
extern s32 D_L21_001DE0E8[2];
__asm__(".extern D_L21_001DE0E8, 16");
extern s32 D_L21_001E0FD0[2];
__asm__(".extern D_L21_001E0FD0, 16");
extern s32 D_L21_001E0FE0[2];
__asm__(".extern D_L21_001E0FE0, 16");
extern s32 D_L21_001E0FF0[2];
__asm__(".extern D_L21_001E0FF0, 16");
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 func_0038DBD8(f32, s32, s32);

void func_L21_003A43E8(u8 *a0, u8 *a1) {
    s32 i;

    if (D_L21_001DE0E4 != D_L21_001DE8C0) {
        for (i = 0; i < 3; i++) {
            if (func_0038CAD0(&D_L21_001E0FD0[i]) != 0) {
                D_L21_001E0FD0[i] = func_00382498(83, 167);
                D_L21_001E0FE0[i] = D_L21_001DE0E8[func_00382468(4)];
            }
            D_L21_001E0FF0[i] = func_0038DBD8(0.020400047f, D_L21_001E0FF0[i], D_L21_001E0FE0[i]);
        }
        D_L21_001DE0E4 = D_L21_001DE8C0;
    }
    *(s32 *)(a0 + 0x78) = D_L21_001E0FF0[*(s32 *)(a1 + 0x50)];
}
/* localdecomp:end func_L21_003A43E8 */
