#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EC800 */
unsigned long func_L39_004EC800(u8 *p) {
    return (unsigned long)p[0x48] | (u32)(p[0x49] << 8) | ((unsigned long)p[0x4A] << 16) | ((unsigned long)p[0x4B] << 24);
}
/* localdecomp:end func_L39_004EC800 */
