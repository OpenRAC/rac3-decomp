#include "common.h"

/* declared by functions of L39_0050DE78.c, which this file was cut from */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor;

/* declared by functions of L39_0050DFA0.c, which this file was cut from */
extern s32 D_L39_0046F414[];
extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_0050F1C0(void *);

/* localdecomp:start func_L39_0050EC58 */
typedef struct {
    u16 year;
    u16 month;
    u16 day;
    u16 hour;
    u16 minute;
    u16 second;
    u32 fraction;
    s16 offset;
    s16 pad;
} S_0050EC58;

extern s32 func_L39_0050F358(void *, const u8 *, u32, u32 *, u32);

s32 func_L39_0050EC58(S_0050EC58 *out, const u8 *s, u32 len)
{
    u32 pos;
    s32 state;
    s32 end;
    s32 rc;

    end = 0;
    ((s32 (*)(void *, s32, s32))func_L39_004F74E8)(out, 0, 0x14);
    rc = 0;
    state = 1;
    if (!((u8)(s[0] - '0') < 10 && (u8)(s[1] - '0') < 10 && (u8)(s[2] - '0') < 10 && (u8)(s[3] - '0') < 10 &&
          (u8)(s[4] - '0') < 10 && (u8)(s[5] - '0') < 10 && (u8)(s[6] - '0') < 10 && (u8)(s[7] - '0') < 10 &&
          (u8)(s[8] - '0') < 10 && (u8)(s[9] - '0') < 10))
        return 0x804;
    out->year = (s[0] - '0') * 1000;
    out->year += (s[1] - '0') * 100;
    out->year += (s[2] - '0') * 10;
    out->year += s[3] - '0';
    out->month = (s[4] - '0') * 10;
    out->month += s[5] - '0';
    out->day = (s[6] - '0') * 10;
    out->day += s[7] - '0';
    out->hour = (s[8] - '0') * 10;
    out->hour += s[9] - '0';
    if (out->year >= 10000 || out->month == 0 || out->month > 12 || out->day == 0 ||
        out->day > ((out->year % 4 == 0 && out->month == 2) ? 29 : (u32)D_L39_0046F414[out->month]) ||
        out->hour >= 24)
        return 0x804;
    pos = 10;
    while (pos < len) {
        if (end) {
            rc = 0x804;
            break;
        }
        switch (s[pos]) {
        case ',':
        case '.':
            pos++;
            rc = func_L39_0050F358(out, s, len, &pos, state);
            if (rc)
                return 0x804;
            state = 3;
            break;
        case 'Z':
            pos++;
            end = 1;
            break;
        case '+':
        case '-':
            pos++;
            if ((u8)(s[pos] - '0') >= 10 || (u8)(s[pos + 1] - '0') >= 10 || (u8)(s[pos + 2] - '0') >= 10 ||
                (u8)(s[pos + 3] - '0') >= 10) {
                rc = 0x804;
                break;
            }
            {
                u32 h = (s[pos] - '0') * 10 + (s[pos + 1] - '0');
                u32 m = (s[pos + 2] - '0') * 10 + (s[pos + 3] - '0');
                if (h < 24 && m < 60) {
                    s32 off;
                    out->offset = m + h * 60;
                    off = out->offset;
                    if (s[pos - 1] == '-')
                        off = -off;
                    out->offset = off;
                    pos += 4;
                    end = 1;
                } else {
                    rc = 0x804;
                }
            }
            break;
        default:
            if ((u8)(s[pos] - '0') >= 10 || (u8)(s[pos + 1] - '0') >= 10) {
                rc = 0x804;
                break;
            }
            switch (state) {
            case 1:
                out->minute = (s[pos] - '0') * 10;
                out->minute += s[pos + 1] - '0';
                if (out->minute >= 60) {
                    rc = 0x804;
                    break;
                }
                pos += 2;
                state = 2;
                break;
            case 2:
                out->second = (s[pos] - '0') * 10;
                out->second += s[pos + 1] - '0';
                if (out->second >= 60) {
                    rc = 0x804;
                    break;
                }
                pos += 2;
                state = 3;
                break;
            default:
                rc = 0x804;
                break;
            }
            break;
        }
        if (rc)
            return rc;
    }
    if (rc)
        return rc;
    return func_L39_0050F1C0(out);
}
/* localdecomp:end func_L39_0050EC58 */
