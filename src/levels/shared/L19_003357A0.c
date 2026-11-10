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

INCLUDE_ASM("asm/levels", func_L19_00336008);

/* localdecomp:start func_L19_00336088 */
extern void func_003D93B0(u8 *a0, s32 a1, s32 a2, s32 a3);

void func_L19_00336088(u8 *a0, s32 a1, s32 a2, s32 a3) {
    func_003D93B0(a0, a1, a2, 128);
    *(s32 *)(a0 + 76) = a3;
    *(s32 *)(a0 + 72) = a3;
    *(s32 *)(a0 + 68) = a3;
    *(s32 *)(a0 + 64) = a3;
    *(s32 *)(a0 + 80) = 0;
    *(s32 *)(a0 + 84) = 0;
    *(s32 *)(a0 + 88) = 0;
    *(f32 *)(a0 + 92) = 1.0f;
    *(f32 *)(a0 + 96) = 1.0f;
    *(s32 *)(a0 + 100) = 0;
    *(f32 *)(a0 + 104) = 1.0f;
    *(f32 *)(a0 + 108) = 1.0f;
    *(long *)(a0 + 112) = 5;
}
/* localdecomp:end func_L19_00336088 */

INCLUDE_ASM("asm/levels", func_L19_00336100);

INCLUDE_ASM("asm/levels", func_L19_003361E0);

LINKER_REMNANT("asm/levels", func_L19_003362F8);

INCLUDE_ASM("asm/levels", func_L19_00336330);
