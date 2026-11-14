#include "common.h"

/* localdecomp:start func_L39_004EACC8 */
extern s32 D_L39_0046D3B0[];
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACC8_004EACC8(s32 a0) {
    D_L39_0046D3B0[0] = a0;
}
/* localdecomp:end func_L39_004EACC8 */

/* localdecomp:start func_L39_004EACD8 */
extern s32 D_L39_0046D3B4[];
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACD8_004EACD8(s32 a0) {
    D_L39_0046D3B4[0] = a0;
}
/* localdecomp:end func_L39_004EACD8 */

/* localdecomp:start func_L39_004EACE8 */
extern s32 D_L39_0046D3B8[];
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");
void func_L39_004EACE8_004EACE8(s32 a0) {
    D_L39_0046D3B8[0] = a0;
}
/* localdecomp:end func_L39_004EACE8 */

/* localdecomp:start func_L39_004EACF8 */
extern s32 D_L39_0046D3BC[];
void func_L39_004EACF8(void *a0) {
    D_L39_0046D3BC[0] = (s32)a0;
}
/* localdecomp:end func_L39_004EACF8 */

LINKER_REMNANT("asm/levels", func_L39_004EAD08);

INCLUDE_ASM("asm/levels", func_L39_004EAD18);

INCLUDE_ASM("asm/levels", func_L39_004EADC0);
