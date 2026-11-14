#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EC830 */
extern s32 func_11D2EC(void *, void *, s32);

s32 func_L39_004EC830(u8 *a, u8 *b) {
    if (*(s32 *)a != *(s32 *)b || *(s32 *)(a + 0x44) != *(s32 *)(b + 0x44)) {
        return 1;
    }
    return func_11D2EC(a + 0x48, b + 0x48, *(s32 *)(a + 0x44));
}
/* localdecomp:end func_L39_004EC830 */

INCLUDE_ASM("asm/levels", func_L39_004EC870);

/* localdecomp:start func_L39_004ECA10 */
extern s32 func_139328(u8 *);
extern s32 func_L39_004ECAB8(u8 *);
extern s32 func_L39_004ECAD8(s32, s32, s32);
extern s32 func_L39_004ECB48(s32 *);

s32 func_L39_004ECA10(void) {
    u8 buf[8];
    s32 v[7];

    if (func_139328(buf) == 0 || buf[0] != 0) {
        return -1;
    }
    do {
        v[5] = func_L39_004ECAB8(buf + 7) + 100;
        v[4] = func_L39_004ECAB8(buf + 6) - 1;
        v[3] = func_L39_004ECAB8(buf + 5);
    } while (0);
    do { v[2] = func_L39_004ECAB8(buf + 3); } while (0);
    do { v[1] = func_L39_004ECAB8(buf + 2); } while (0);
    v[0] = func_L39_004ECAB8(buf + 1);
    v[6] = func_L39_004ECAD8(v[5] + 0x76C, v[4], v[3]);
    return func_L39_004ECB48(v);
}
/* localdecomp:end func_L39_004ECA10 */

/* localdecomp:start func_L39_004ECAB8 */
s32 func_L39_004ECAB8(u8 *arg0) {
    u8 temp_v1;

    temp_v1 = *arg0;
    return ((temp_v1 >> 4) * 0xA) + (temp_v1 & 0xF);
}
/* localdecomp:end func_L39_004ECAB8 */
