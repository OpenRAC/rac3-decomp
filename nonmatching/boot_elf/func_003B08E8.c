/* US draft of func_003B08E8 (rac3-uya-decomp func_003B0748, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-fopt-stack` (a single-function override). */


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
