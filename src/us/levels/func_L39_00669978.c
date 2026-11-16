#include "common.h"

extern s32 D_001A5E58[];

/* localdecomp:start func_L39_00669978 */
/* Writes a 0x18-byte record into out (a stamp from D_001A5E58 plus four values) and returns 0x18,
 * or returns -1 when out is null. */
s32 func_L39_00669978(s32 first, s32 second, s32 third, s32 fourth, s32 *out) {
    s32 *payload;
    if (out == 0) {
        return -1;
    }
    payload = &out[2];
    out[1] = D_001A5E58[0];
    out[2] = first;
    payload[1] = second;
    payload[3] = fourth;
    payload[2] = third;
    return 0x18;
}
/* localdecomp:end func_L39_00669978 */
