#include "common.h"

/* declared by functions of L21_003A3A20.c, which this file was cut from */
void func_L21_003A3AA8(void *arg0);
extern s32 D_L21_001E0FC0[];

/* localdecomp:start func_L21_003A3AA8 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038DBD8(s32, s32, f32);
__asm__(".extern D_L21_001DE0C8, 8");
extern s32 D_L21_001DE0C8[3] __attribute__((section(".sdata")));
__asm__(".extern D_L21_001DE0D4, 4");
extern s32 D_L21_001DE0D4;
__asm__(".extern D_L21_001DE0D8, 4");
extern s32 D_L21_001DE0D8;
__asm__(".extern D_L21_001DE0DC, 4");
extern s32 D_L21_001DE0DC;
extern s32 D_L21_001DE8C0;
extern s32 D_L21_001E0FB0[];

void func_L21_003A3AA8(void *arg0) {
    s32 i;

    if (D_L21_001DE0DC != D_L21_001DE8C0) {
        D_L21_001DE0DC = D_L21_001DE8C0;
        if (func_0038CAD0(&D_L21_001DE0D4)) {
            D_L21_001DE0D4 = 150;
            D_L21_001DE0D8++;
            for (i = 0; i < 3; i++) {
                D_L21_001E0FB0[i] = D_L21_001DE0C8[(i + D_L21_001DE0D8) % 3];
            }
        }
        for (i = 0; i < 3; i++) {
            D_L21_001E0FC0[i] = func_0038DBD8(D_L21_001E0FB0[i], D_L21_001E0FC0[i], 0.88f);
        }
    }
}
/* localdecomp:end func_L21_003A3AA8 */
