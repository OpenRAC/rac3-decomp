#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");
extern s32 func_L39_004ECAD8(s32, s32, s32);

/* localdecomp:start func_L39_004ECAD8 */
extern const u16 D_L39_00477878[][13];

s32 func_L39_004ECAD8(s32 year, s32 month, s32 day) {
    return D_L39_00477878[(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))][month] + day;
}
/* localdecomp:end func_L39_004ECAD8 */

INCLUDE_ASM("asm/levels", func_L39_004ECB48);

/* localdecomp:start func_L39_004ECC60 */
/* from glibc's mktime.c ydhms_tm_diff */
typedef struct {
    s32 sec, min, hour, mday, mon, year, yday;
} S_004ECC60;

long func_L39_004ECC60(s32 year, s32 yday, s32 hour, s32 min, s32 sec, void *arg) {
    S_004ECC60 *tp = arg;

    if (!tp) {
        return 1;
    } else {
        s32 a4 = (year >> 2) + (1900 >> 2) - !(year & 3);
        s32 b4 = (tp->year >> 2) + (1900 >> 2) - !(tp->year & 3);
        s32 a100 = a4 / 25 - (a4 % 25 < 0);
        s32 b100 = b4 / 25 - (b4 % 25 < 0);
        s32 a400 = a100 >> 2;
        s32 b400 = b100 >> 2;
        s32 intervening_leap_days = (a4 - b4) - (a100 - b100) + (a400 - b400);
        long years = year - (long)tp->year;
        long days = 365 * years + intervening_leap_days + (yday - tp->yday);
        return 60 * (60 * (24 * days + (hour - tp->hour)) + (min - tp->min)) + (sec - tp->sec);
    }
}
/* localdecomp:end func_L39_004ECC60 */

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
