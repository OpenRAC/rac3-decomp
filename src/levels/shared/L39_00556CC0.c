#include "common.h"

/* declared by functions of L39_00556C10.c, which this file was cut from */
extern s32 D_L39_0024D588_b;

/* localdecomp:start func_L39_00556CC0 */
extern s32 D_L39_0024D548_00556CC0[16] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024D548_00556CC0, 64");
extern s32 D_L39_0024D588_00556CC0[] __attribute__((section(".sdata")));
extern s32 func_L39_005B4398(s32);
extern void func_L39_00556638(s32, s32, s32);
extern s32 func_L39_00556C40(void);
extern void func_L39_00556C78(s32);

void func_L39_00556CC0(s32 arg0) {
    s32 i;
    s32 n;

    if (func_L39_00556C40() == 0) {
        for (i = 0; i < 16; i++) {
            if (D_L39_0024D548_00556CC0[i] == 0) {
                D_L39_0024D548_00556CC0[i] = arg0;
                return;
            }
        }
        n = D_L39_0024D588_b;
    } else {
        i = func_L39_005B4398(16);
        func_L39_00556638(D_L39_0024D548_00556CC0[i], 0, 0);
        func_L39_00556C78(D_L39_0024D548_00556CC0[i]);
        D_L39_0024D548_00556CC0[i] = arg0;
        n = D_L39_0024D588_00556CC0[0];
    }
    D_L39_0024D588_00556CC0[0] = n + 1;
}
/* localdecomp:end func_L39_00556CC0 */
