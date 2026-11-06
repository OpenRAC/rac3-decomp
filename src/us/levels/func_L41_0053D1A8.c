#include "common.h"

/* localdecomp:start func_L41_0053D1A8 */
extern void *func_L41_0053EB80(void);
extern s32 func_L41_0053EB48(s32, s32, s32, s32, void *);
extern s32 D_001A5F78[];

s32 func_L41_0053D1A8(s32 arg0, s32 count, s32 *source) {
    u8 *buffer;
    s32 *dest;
    s32 *src;
    s32 remaining;
    s32 offset;

    if (count < 0) {
        return -1;
    }
    buffer = func_L41_0053EB80();
    if (buffer == 0) {
        return -1;
    }
    offset = func_L41_0053EB48(3, arg0, D_001A5F78[0], count, buffer);
    dest = (s32 *)(buffer + offset);
    if (count > 0) {
        src = source;
        remaining = count;
        do {
            *dest++ = *src++;
        } while (--remaining != 0);
    }
    *(s32 *)buffer = (s32)dest - (s32)buffer;
    return arg0;
}
/* localdecomp:end func_L41_0053D1A8 */
