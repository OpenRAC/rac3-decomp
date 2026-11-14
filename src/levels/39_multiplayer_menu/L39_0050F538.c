#include "common.h"

/* localdecomp:start func_L39_0050F538 */
extern s32 func_L39_0050F5B8(s32, s32, s32, s32, s32, void *, s32, void *);
extern void func_L39_004F7620(void *);
s32 func_L39_0050F538(s32 a, s32 b, s32 c, s32 d, s32 *out, s32 e) {
    s32 v;
    void *obj;
    s32 r;
    obj = 0;
    r = func_L39_0050F5B8(a, b, c, d, 0, &v, e, &obj);
    if (obj != 0) {
        func_L39_004F7620(obj);
    }
    if (r != 0) {
        return r;
    }
    if (out != 0) {
        *out = v;
    }
    return 0;
}
/* localdecomp:end func_L39_0050F538 */
