#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;


/* localdecomp:start func_L07_003BB2A8 */
extern f32 func_0038D098(f32 a);
extern f32 func_0038D0B0(f32 a);

void func_L07_003BB2A8(f32 *out, f32 *in, f32 angle, f32 radius) {
    out[0] = in[0] + radius * func_0038D098(angle);
    out[1] = in[1] + radius * func_0038D0B0(angle);
    out[2] = in[2];
    out[3] = 0.0f;
}
/* localdecomp:end func_L07_003BB2A8 */

/* localdecomp:start func_L07_003BB328 */
float func_L07_003BB328(float x) {
    if (x < 0.0f) return x + 6.2831855f;
    return x;
}
/* localdecomp:end func_L07_003BB328 */
