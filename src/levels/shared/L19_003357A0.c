#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003357A0);

INCLUDE_ASM("asm/levels", func_L19_00335898);

/* localdecomp:start func_L19_00335F58 */
__asm__(".extern D_L19_001DF240, 16");
extern int D_L19_001DF240;
extern int D_L19_001DCD20 __attribute__((section(".sdata")));
extern float D_L19_00276E40[] __attribute__((section(".data")));
extern float func_L01_00443A18(float, float);

/* from rac2-decomp's func_L03_0038B238 */
void func_L19_00335F58(void) {
    float *p;
    int i;
    if (D_L19_001DCD20 >= D_L19_001DF240)
        return;
    p = D_L19_00276E40;
    for (i = 15; i >= 0; i--) {
        p[0] = func_L01_00443A18(0.0f, 1.0f);
        p[1] = func_L01_00443A18(0.0f, 1.0f);
        p[2] = func_L01_00443A18(0.0f, 1.0f);
        p[3] = 1.0f;
        p += 4;
    }
    D_L19_001DCD20 = D_L19_001DF240;
}
/* localdecomp:end func_L19_00335F58 */
