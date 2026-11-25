#include "common.h"

/* localdecomp:start func_L39_00595248 */
s32 func_L39_00595248(u8 *s, s32 *pos)
{
    s32 n;
    s16 c;
    u32 b;
    s32 r = 0;

    n = 0;
    b = s[*pos];
    if (b & 0x80) {
        c = b;
        do {
            n++;
        } while ((c << n) & 0x80);
    }
    switch (n) {
    case 0:
        r = s[*pos] & 0x7F;
        *pos += 1;
        break;
    case 2:
        r = ((s[*pos] & 0x1F) << 6) | (s[*pos + 1] & 0x3F);
        *pos += 2;
        break;
    case 3:
        r = ((s[*pos] & 0x0F) << 12) | ((s[*pos + 1] << 6) & 0x3F) | (s[*pos + 2] & 0x3F);
        *pos += 3;
        break;
    case 4:
        r = (((s[*pos] & 0x0F) << 18) | ((s[*pos + 1] << 12) & 0x3F) | ((s[*pos + 2] << 6) & 0x3F) | (s[*pos + 3] & 0x3F)) & 0x1FFFFF;
        *pos += 4;
        break;
    case 5:
        r = (((s[*pos] & 0x0F) << 24) | ((s[*pos + 1] << 18) & 0x3F) | ((s[*pos + 2] << 12) & 0x3F) | ((s[*pos + 3] << 6) & 0x3F) | (s[*pos + 4] & 0x3F)) & 0x3FFFFFF;
        *pos += 5;
        break;
    case 6:
        r = ((s[*pos] << 30) | ((s[*pos + 1] << 24) & 0x3F) | ((s[*pos + 2] << 18) & 0x3F) | ((s[*pos + 3] << 12) & 0x3F) | ((s[*pos + 4] << 6) & 0x3F) | (s[*pos + 5] & 0x3F)) & 0x7FFFFFFF;
        *pos += 6;
        break;
    case 1:
    case 7:
        r = '?';
        *pos += 1;
        break;
    }
    return (s16)r;
}
/* localdecomp:end func_L39_00595248 */
