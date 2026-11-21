#include "common.h"

/* declared by functions of L39_0050DE78.c, which this file was cut from */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;

/* declared by functions of L39_0050DFA0.c, which this file was cut from */
extern s32 D_L39_0046F414[];
extern s32 func_L39_0050F1C0(void *);

/* localdecomp:start func_L39_0050F1C0 */
typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u8 pad[6];
    s16 extra;
} S_0050F1C0;

extern s32 D_L39_0046F414[];

s32 func_L39_0050F1C0(void *arg)
{
    S_0050F1C0 *s = arg;
    s32 year;
    s32 month;
    s32 day;
    s32 hour;
    s32 minute;
    s32 t;

    t = s->extra;
    if (t == 0)
        return 0;
    year = s->year;
    month = s->month;
    day = s->day;
    hour = s->hour;
    minute = s->minute;
    minute -= t % 60;
    hour -= t / 60;
    if (minute < 0) {
        minute += 60;
        hour -= 1;
    } else if (minute >= 60) {
        minute -= 60;
        hour += 1;
    }
    if (hour < 0) {
        hour += 24;
        day -= 1;
        if (day <= 0) {
            month -= 1;
            if (month <= 0) {
                month += 12;
                year -= 1;
            }
            if ((year & 3) == 0 && month == 2) {
                day += 29;
            } else {
                day += D_L39_0046F414[month];
            }
        }
    } else if (hour >= 24) {
        hour -= 24;
        day += 1;
        if (day > ((year & 3) == 0 && month == 2 ? 29 : D_L39_0046F414[month])) {
            day -= ((year & 3) == 0 && month == 2 ? 29 : D_L39_0046F414[month]);
            month += 1;
            if (month >= 13) {
                month -= 12;
                year += 1;
                if (year >= 10000) {
                    return 0x804;
                }
            }
        }
    }
    s->year = year;
    s->month = month;
    s->day = day;
    s->hour = hour;
    s->minute = minute;
    s->extra = 0;
    return 0;
}
/* localdecomp:end func_L39_0050F1C0 */

INCLUDE_ASM("asm/levels", func_L39_0050F358);
