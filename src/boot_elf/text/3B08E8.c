#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B08E8 */
extern s32 func_003B0A60();
s32 func_003B08E8(void *ctx, s32 p, s32 a, s32 q, s32 d, s32 r, s32 b, s32 s, s32 c) {
    s32 over;
    s32 len;
    if (a + d < b + c) {
        over = b + c - (a + d);
        if (c <= over) {
            b -= over - c;
            c = 0;
        } else {
            c -= over;
        }
    }
    if (a <= b) {
        func_003B0A60(ctx, p, r, a);
        func_003B0A60(ctx, q, r + a, b - a);
        func_003B0A60(ctx, q + b - a, s, c);
    } else if ((len = a - b) <= c) {
        func_003B0A60(ctx, p, r, b);
        func_003B0A60(ctx, p + b, s, len);
        func_003B0A60(ctx, q, s + a - b, c - len);
    } else {
        func_003B0A60(ctx, p, r, b);
        func_003B0A60(ctx, p + b, s, c);
    }
    return b + c;
}
/* localdecomp:end func_003B08E8 */
