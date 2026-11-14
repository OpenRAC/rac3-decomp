#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00334238);

/* localdecomp:start func_L07_00334318 */
typedef struct { u8 b[16]; } B16_00334318;

extern B16_00334318 D_L07_001DD118;
extern f32 func_L07_00334238(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L03_0032FB70(f32);

void func_L07_00334318(void *arg0, s32 *arg1, s32 *arg2) {
    B16_00334318 tmp;
    s32 *p;
    s32 n;
    s32 i;
    f32 a;

    a = func_L07_00334238(arg0);
    a = func_0038DAB8(a, 0.39269909f);
    a = func_L03_0032FB70(a);
    n = (s32)(a / 0.39269909f);
    tmp = D_L07_001DD118;
    p = (s32 *)tmp.b;
    for (i = 3; i >= 0; i--) {
        if (*p < n) {
            n--;
        }
        p++;
    }
    *arg1 = n >> 1;
    *arg2 = (n & 1) ? 1 : -1;
}
/* localdecomp:end func_L07_00334318 */

/* localdecomp:start func_L07_003343E8 */
s32 func_L07_003343E8(s32 arg0) {
    if (arg0 < 6) {
        return 0;
    }
    return arg0 < 7;
}
/* localdecomp:end func_L07_003343E8 */

INCLUDE_ASM("asm/levels", func_L07_00334408);
