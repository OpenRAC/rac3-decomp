#include "common.h"

typedef char *va_list_00428400;

/* localdecomp:start func_L28_00428400 */
extern s32 func_00381FF0(s32);
extern void func_L03_0044DC88(s32, s32, va_list_00428400);
extern void func_L01_0041D0F8(void *);

void func_L28_00428400(s32 a0, ...) {
    char buf[0x200];
    s32 r;

    r = func_00381FF0(a0);
    if (r != 0) {
        func_L03_0044DC88((s32)buf, r, (char *)__builtin_next_arg(a0) - 0x38);
        func_L01_0041D0F8(buf);
    }
}
/* localdecomp:end func_L28_00428400 */
