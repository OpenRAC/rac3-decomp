#include "common.h"

/* declared by functions of L39_0050DE78.c, which this file was cut from */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;

/* localdecomp:start func_L39_0050DFA0 */
extern s32 func_L39_0050CC00(void *, u32, u32, u8 *, u32);
extern u8 D_L39_0046F448[];

s32 func_L39_0050DFA0(void *a0, u32 a1, u32 a2, const Cursor *in)
{
    Cursor c;
    s32 r;

    c = *in;
    while (c.remaining && *c.data == 0) {
        c.remaining--;
        c.data++;
    }
    if (!c.remaining || (*c.data & 0x80)) {
        r = func_L39_0050CC00(a0, a1 | 0x800, a2, D_L39_0046F448, 1);
        if (r)
            return r;
    }
    return func_L39_0050CC00(a0, a1, a2, c.data, c.remaining);
}
/* localdecomp:end func_L39_0050DFA0 */

LINKER_REMNANT("asm/levels", func_L39_0050E080);

/* localdecomp:start func_L39_0050E0C8 */
extern s32 D_L39_0046F418[];

s32 func_L39_0050E0C8(u8 *out, s32 *outlen, u32 t) {
    s32 year;
    s8 leap;
    u32 cur;
    s32 month;
    s32 *tab;
    u32 mon;
    s32 day;
    s32 hour;
    s32 min;

    year = 70;
    for (;;) {
        cur = (year & 3) ? 31536000 : 31622400;
        if (t < cur)
            break;
        t -= cur;
        year++;
    }
    if (year >= 170) {
        return 0x804;
    }
    leap = year & 3;
    tab = D_L39_0046F418;
    month = 1;
    for (;;) {
        mon = (leap == 0 && month == 2) ? 29 * 86400 : *tab * 86400;
        if (t < mon) {
            break;
        }
        t -= mon;
        tab++;
        month++;
    }
    if (year >= 100) {
        year -= 100;
    }
    day = t / 86400 + 1;
    t -= (day - 1) * 86400;
    hour = t / 3600;
    t -= hour * 3600;
    min = t / 60;
    t -= min * 60;
    out[0] = year / 10 + '0';
    out[1] = year % 10 + '0';
    out[2] = month / 10 + '0';
    out[3] = month % 10 + '0';
    out[4] = day / 10 + '0';
    out[5] = day % 10 + '0';
    out[6] = hour / 10 + '0';
    out[7] = hour % 10 + '0';
    out[8] = min / 10 + '0';
    out[9] = min % 10 + '0';
    out[10] = (s32)t / 10 + '0';
    out[11] = (s32)t % 10 + '0';
    out[12] = 'Z';
    *outlen = 13;
    return 0;
}
/* localdecomp:end func_L39_0050E0C8 */

/* localdecomp:start func_L39_0050E330 */
extern s32 D_L39_0046F414[];

s32 func_L39_0050E330(u32 *out, u8 *str, s32 len)
{
    s32 tzMin = 0;
    s32 tzHour = 0;
    s32 year;
    s32 month;
    s32 day;
    s32 hour;
    s32 minute;
    s32 second;
    s32 idx;
    s32 sign;

    if ((u8)(str[0] - '0') >= 10 || (u8)(str[1] - '0') >= 10 || (u8)(str[2] - '0') >= 10 ||
        (u8)(str[3] - '0') >= 10 || (u8)(str[4] - '0') >= 10 || (u8)(str[5] - '0') >= 10 ||
        (u8)(str[6] - '0') >= 10 || (u8)(str[7] - '0') >= 10 || (u8)(str[8] - '0') >= 10 ||
        (u8)(str[9] - '0') >= 10) {
        return 0x801;
    }

    year = str[0] * 10 + str[1] - 528;
    month = str[2] * 10 + str[3] - 528;
    day = str[4] * 10 + str[5] - 528;
    hour = str[6] * 10 + str[7] - 528;
    minute = str[8] * 10 + str[9] - 528;
    if ((u8)(str[10] - '0') < 10) {
        if ((u8)(str[11] - '0') >= 10) return 0x801;
        second = str[10] * 10 + str[11] - 528;
        idx = 12;
    } else {
        second = 0;
        idx = 10;
    }

    if (year < 0 || year >= 100 || month <= 0 || month >= 13 || day <= 0 ||
        day > (((year & 3) != 0 || month != 2) ? D_L39_0046F414[month] : 29) ||
        hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60) {
        return 0x801;
    }

    sign = (s8)str[idx++];
    if (sign == '+' || sign == '-') {
        if ((u8)(str[idx] - '0') >= 10 || (u8)(str[idx + 1] - '0') >= 10 ||
            (u8)(str[idx + 2] - '0') >= 10 || (u8)(str[idx + 3] - '0') >= 10) {
            return 0x801;
        }
        tzHour = (str[idx++] - '0') * 10;
        tzHour = tzHour + (str[idx++] - '0');
        tzMin = (str[idx++] - '0') * 10;
        tzMin = tzMin + (str[idx++] - '0');
        if (tzHour < 0 || tzHour >= 24 || tzMin < 0 || tzMin >= 60) return 0x801;
    } else if (sign != 'Z') {
        return 0x801;
    }
    if (idx != len) return 0x801;

    if (sign == '+') {
        hour -= tzHour;
        minute -= tzMin;
    } else if (sign == '-') {
        hour += tzHour;
        minute += tzMin;
    }
    if (year < 70) year += 100;
    if (minute < 0) {
        minute += 60;
        hour--;
    } else if (minute >= 60) {
        minute -= 60;
        hour++;
    }
    if (hour < 0) {
        hour += 24;
        day--;
        if (day <= 0) {
            month--;
            if (month <= 0) {
                month += 12;
                year--;
            }
            day += (((year & 3) != 0 || month != 2) ? D_L39_0046F414[month] : 29);
        }
    } else if (hour >= 24) {
        hour -= 24;
        day++;
        if (day > (((year & 3) != 0 || month != 2) ? D_L39_0046F414[month] : 29)) {
            day -= (((year & 3) != 0 || month != 2) ? D_L39_0046F414[month] : 29);
            month++;
            if (month >= 13) {
                year++;
                month -= 12;
                if (year >= 170) return 0x801;
            }
        }
    }

    *out = (u32)second + minute * 60 + hour * 3600 + (day - 1) * 86400;
    for (; month >= 2; month--) {
        *out += (((year & 3) != 0 || month - 1 != 2) ? D_L39_0046F414[month - 1] : 29) * 86400;
    }
    while (year > 70) {
        *out += (((year - 1) & 3) != 0 ? 365 : 366) * 86400;
        year--;
    }
    return 0;
}
/* localdecomp:end func_L39_0050E330 */

/* localdecomp:start func_L39_0050E948 */
extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_0050F1C0(void *);

typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u32 micro;
    s16 zone;
} S_0050E948;

s32 func_L39_0050E948(u8 *out, s32 *outLen, S_0050E948 *in)
{
    s32 status;
    s32 len;

    func_L39_004F74E8(out, 0, 26);
    status = func_L39_0050F1C0(in);
    if (status != 0) return status;

    out[0] = in->year / 1000 + '0';
    out[1] = in->year % 1000 / 100 + '0';
    out[2] = in->year % 100 / 10 + '0';
    out[3] = in->year % 10 + '0';
    out[4] = in->month / 10 + '0';
    out[5] = in->month % 10 + '0';
    out[6] = in->day / 10 + '0';
    out[7] = in->day % 10 + '0';
    out[8] = in->hour / 10 + '0';
    out[9] = in->hour % 10 + '0';
    out[10] = in->minute / 10 + '0';
    out[11] = in->minute % 10 + '0';
    out[12] = in->second / 10 + '0';
    out[13] = in->second % 10 + '0';
    len = 14;
    if (in->micro != 0) {
        out[14] = '.';
        out[15] = in->micro / 100000 + '0';
        out[16] = in->micro % 100000 / 10000 + '0';
        out[17] = in->micro % 10000 / 1000 + '0';
        out[18] = in->micro % 1000 / 100 + '0';
        out[19] = in->micro % 100 / 10 + '0';
        out[20] = in->micro % 10 + '0';
        len = 21;
        while (out[len - 1] == '0') {
            len--;
        }
    }
    out[len++] = 'Z';
    *outLen = len;
    return 0;
}
/* localdecomp:end func_L39_0050E948 */

INCLUDE_ASM("asm/levels", func_L39_0050EC58);

INCLUDE_ASM("asm/levels", func_L39_0050F1C0);

INCLUDE_ASM("asm/levels", func_L39_0050F358);
