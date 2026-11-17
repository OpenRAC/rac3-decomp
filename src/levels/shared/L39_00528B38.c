#include "common.h"

/* declared by functions of L39_00528A88.c, which this file was cut from */
extern s32 D_L39_0024D4E0_b;

/* localdecomp:start func_L39_00528B38 */
extern s32 D_L39_0024D4A0_00528B38[16] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D4A0_00528B38, 64");
extern s32 D_L39_0024D4E0_b;
extern s32 func_L39_00528AB8(void);
extern void func_L39_00528AF0(s32 a0);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005287B0(s32);

void func_L39_00528B38(s32 a0) {
    s32 i;

    if (func_L39_00528AB8() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_L39_0024D4A0_00528B38[i] == 0) {
                D_L39_0024D4A0_00528B38[i] = a0;
                return;
            }
        }
    } else {
        i = func_L39_005B4398(16);
        func_L39_005287B0(D_L39_0024D4A0_00528B38[i]);
        func_L39_00528AF0(D_L39_0024D4A0_00528B38[i]);
        D_L39_0024D4A0_00528B38[i] = a0;
    }
    D_L39_0024D4E0_b++;
}
/* localdecomp:end func_L39_00528B38 */
