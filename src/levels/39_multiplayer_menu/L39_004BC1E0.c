#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 D_L39_00443444[];
extern s32 D_L39_00443448[];
extern s32 D_L39_0044344C[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BC1E0 */
extern s32 D_L39_00443444[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BC1E0(void *a, void *b, void *c, void *d) {
    if (D_L39_00443444[0] != 0) {
        return ((s32 (*)(void *, void *, void *, void *))D_L39_00443444[0])(a, b, c, d);
    }
    func_L39_004BC6C8(26, 143, 14, 0, 0);
}
/* localdecomp:end func_L39_004BC1E0 */

/* localdecomp:start func_L39_004BC228 */
extern s32 D_L39_00443448[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC228(void *a) {
    if (D_L39_00443448[0] != 0) {
        ((void (*)(void *))D_L39_00443448[0])(a);
    } else {
        func_L39_004BC6C8(26, 152, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC228 */

/* localdecomp:start func_L39_004BC270 */
extern s32 D_L39_0044344C[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC270(void *a) {
    if (D_L39_0044344C[0] != 0) {
        ((void (*)(void *))D_L39_0044344C[0])(a);
    } else {
        func_L39_004BC6C8(26, 137, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC270 */
