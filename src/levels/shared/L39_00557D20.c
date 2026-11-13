#include "common.h"

/* localdecomp:start func_L39_00557D20 */
extern s32 D_L39_0024D590_00557D20[16] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D590_00557D20, 64");
extern s32 func_L39_00557CB0(void);
extern s32 func_L39_005B4398(s32);
extern void func_L39_00557890(s32);

void func_L39_00557D20(s32 arg0) {
    s32 i;
    s32 n;

    if (func_L39_00557CB0() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_L39_0024D590_00557D20[i] == 0) {
                D_L39_0024D590_00557D20[i] = arg0;
                return;
            }
        }
    } else {
        n = func_L39_005B4398(16);
        func_L39_00557890(D_L39_0024D590_00557D20[n]);
        func_L39_00557CE8(D_L39_0024D590_00557D20[n]);
        D_L39_0024D590_00557D20[n] = arg0;
    }
}
/* localdecomp:end func_L39_00557D20 */
