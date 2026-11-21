#include "common.h"

/* localdecomp:start func_L39_00511750 */
extern s32 func_L39_00511848(void *, u32, u32 *, u8 *);

s32 func_L39_00511750(void *arg0, u32 len, u32 size, u32 *outLen, u8 *buf) {
    u32 k;
    s32 i;

    if (len > size) {
        return 0x10C;
    }
    k = (func_L39_00511540(arg0) + 7) / 8;
    if (len < k) {
        return 0x10C;
    }
    if (k < len) {
        for (i = 0; i < (s32)(len - k); i++) {
            buf[i] = 0;
        }
        *outLen = len;
        return func_L39_00511848(arg0, size, &k, buf + i);
    }
    return func_L39_00511848(arg0, size, outLen, buf);
}
/* localdecomp:end func_L39_00511750 */
