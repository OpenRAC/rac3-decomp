#include "common.h"

/* NTSC-U counterpart of func_L21_003A3AA8 (src/levels/21_obani_draco/L21_003A3AA8.c) */
void func_L21_003A2150(void *arg0);
extern s32 D_L21_001E1040[];

/* localdecomp:start func_L21_003A2150 */
extern s32 func_00388398(void *);
extern s32 func_003894A0(s32, s32, f32);
__asm__(".extern D_L21_001DE0F8, 8");
extern s32 D_L21_001DE0F8[3] __attribute__((section(".sdata")));
__asm__(".extern D_L21_001DE104, 4");
extern s32 D_L21_001DE104;
__asm__(".extern D_L21_001DE108, 4");
extern s32 D_L21_001DE108;
__asm__(".extern D_L21_001DE10C, 4");
extern s32 D_L21_001DE10C;
extern s32 D_L21_001DE940;
extern s32 D_L21_001E1030_003A2150[];

void func_L21_003A2150(void *arg0) {
    s32 i;

    if (D_L21_001DE10C != D_L21_001DE940) {
        D_L21_001DE10C = D_L21_001DE940;
        if (func_00388398(&D_L21_001DE104)) {
            D_L21_001DE104 = 180;
            D_L21_001DE108++;
            for (i = 0; i < 3; i++) {
                D_L21_001E1030_003A2150[i] = D_L21_001DE0F8[(i + D_L21_001DE108) % 3];
            }
        }
        for (i = 0; i < 3; i++) {
            D_L21_001E1040[i] = func_003894A0(D_L21_001E1030_003A2150[i], D_L21_001E1040[i], 0.9f);
        }
    }
}
/* localdecomp:end func_L21_003A2150 */
