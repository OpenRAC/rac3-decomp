#include "common.h"

/* declared by functions of L39_0051E200.c, which this file was cut from */
extern s32 D_L39_0024D490_b;

/* localdecomp:start func_L39_0051E2B0 */
extern s32 D_L39_0024D450_0051E2B0[16] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D450_0051E2B0, 64");
extern s32 D_L39_0024D490_0051E2B0[] __attribute__((section(".sdata")));
extern s32 func_L39_005B4398(s32);
extern void func_L39_0051DD30(s32, s32, s32);

void func_L39_0051E2B0(s32 arg0) {
    s32 i;
    s32 n;

    if (func_L39_0051E230() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_L39_0024D450_0051E2B0[i] == 0) {
                D_L39_0024D450_0051E2B0[i] = arg0;
                return;
            }
        }
        n = D_L39_0024D490_b;
    } else {
        i = func_L39_005B4398(16);
        func_L39_0051DD30(D_L39_0024D450_0051E2B0[i], 0, 0);
        func_L39_0051E268(D_L39_0024D450_0051E2B0[i]);
        D_L39_0024D450_0051E2B0[i] = arg0;
        n = D_L39_0024D490_0051E2B0[0];
    }
    D_L39_0024D490_0051E2B0[0] = n + 1;
}
/* localdecomp:end func_L39_0051E2B0 */
