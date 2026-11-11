#include "common.h"

/* localdecomp:start func_L39_004C5F70 */
/* BEST: 22 diff. Retail uses 16-byte $s slots with a 0x40 frame (library-compiler layout) and different reg allocation; --flags=@ee29 untestable because the file's -fopt-stack is always passed. Body is otherwise structurally right. */
extern s32 func_L39_004C6098(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

typedef struct S_004C5F70 {
    s32 pad0[15];
    u8 **p3C;
    s32 f40;
} S_004C5F70;

s32 func_L39_004C5F70(S_004C5F70 *arg0, s64 arg1, s32 arg2) {
    if (arg0->f40 == 0 && arg2 >= 3) {
        u8 *p = arg0->p3C[1];
        if (p[0] == 0) {
            func_L39_004BC6C8(0x14, arg1, func_L39_004C6098((p[1] << 8) | p[2]), 0, 0);
        }
    }
    if (arg2 < 0) {
        return arg2;
    }
    arg0->f40 += arg2;
    return 0;
}
/* localdecomp:end func_L39_004C5F70 */

/* localdecomp:start func_L39_004C6020 */
typedef struct S_004C6020 {
    u8 pad0[0x3C];
    s32 *f3C;
    s32 f40;
    s32 f44;
} S_004C6020;
extern s32 func_L39_004C59D8(S_004C6020 *, s32, s32);

s32 func_L39_004C6020(S_004C6020 *a0)
{
    s32 r = func_L39_004C59D8(a0, a0->f3C[1] + a0->f44, a0->f40);

    if (r == a0->f40) {
        return 1;
    }
    if (r < 0) {
        return -1;
    }
    a0->f40 -= r;
    a0->f44 += r;
    return 0;
}
/* localdecomp:end func_L39_004C6020 */
