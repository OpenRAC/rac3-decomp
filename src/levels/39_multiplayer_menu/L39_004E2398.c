#include "common.h"

/* localdecomp:start func_L39_004E2398 */
s32 func_L39_004E2398(s32 key, s32 count, s32 *list) {
    s32 i = 0;
    if (count > 0) {
        do {
            if (key == *list++) return 0;
        } while (++i < count);
    }
    return 1;
}
/* localdecomp:end func_L39_004E2398 */

/* localdecomp:start func_L39_004E23D8 */
s32 func_L39_004E23D8(s32 arg0) {
    s32 i;
    s32 tag;
    s32 sum = 0;
    s32 n = (arg0 >> 28) & 0xF;

    if (n & 7) {
        tag = n % 8;
    } else {
        tag = 5;
    }
    for (i = 0; i < 7; i++) {
        sum |= ((arg0 >> (i * 4)) & 7) << (i * 4);
    }
    return (sum & 0x0FFFFFFF) | (tag << 28);
}
/* localdecomp:end func_L39_004E23D8 */
