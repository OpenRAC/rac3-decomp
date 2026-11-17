#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EC768 */
extern s32 func_L39_004BC2B8(void);
extern s32 D_L39_0046D42C __attribute__((section(".data")));
extern u8 D_L39_00477848[];

s32 func_L39_004EC768(void) {
    s32 r = D_L39_0046D42C;

    if (r < 0) {
        r = ((s32 (*)(s32, void *, s32, s32, s32))func_L39_004BC2B8)(0, D_L39_00477848, 0, 0, 0);
        D_L39_0046D42C = r;
    }
    return r;
}
/* localdecomp:end func_L39_004EC768 */
