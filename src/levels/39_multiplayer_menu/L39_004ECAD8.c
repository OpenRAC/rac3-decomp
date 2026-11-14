#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");
extern s32 func_L39_004ECAD8(s32, s32, s32);

/* localdecomp:start func_L39_004ECAD8 */
extern u16 D_L39_00477878[][13];

s32 func_L39_004ECAD8(s32 year, s32 month, s32 day) {
    return D_L39_00477878[(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))][month] + day;
}
/* localdecomp:end func_L39_004ECAD8 */

INCLUDE_ASM("asm/levels", func_L39_004ECB48);

INCLUDE_ASM("asm/levels", func_L39_004ECC60);

/* localdecomp:start func_L39_004ECD80 */
extern u8 D_L39_004788B0[];

s32 func_L39_004ECD80(u8 *a0) {
    u32 i;
    for (i = 0; i < 8; i++) {
        if (a0[i] != D_L39_004788B0[a0[i]]) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004ECD80 */

/* localdecomp:start func_L39_004ECDC8 */
extern s32 func_0011D2EC(void *, void *, s32);
extern u8 D_L39_0046D430[];

/* OpenSSL's des_is_weak_key: memcmp against the 16 weak keys */
s32 func_L39_004ECDC8(void *a0) {
    s32 i;
    u8 *p = D_L39_0046D430;
    for (i = 0; i < 16; i++, p += 8) {
        if (func_0011D2EC(p, a0, 8) == 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004ECDC8 */
