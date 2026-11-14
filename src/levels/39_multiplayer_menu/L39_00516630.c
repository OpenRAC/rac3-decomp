#include "common.h"

/* localdecomp:start func_L39_00516630 */
typedef struct {
    u8 pad[0x48];
    long regs[16];
} S_00516630;

s32 func_L39_00516630(S_00516630 *ctx, s32 unused, s32 v) {
    return (v & 0x80) ? *(ctx->regs + (v & 0xF)) : v;
}
/* localdecomp:end func_L39_00516630 */
