#include "common.h"

/* localdecomp:start func_L39_004DEA00 */
extern void *func_L39_00505058(void *);
extern void *func_L39_004E0B10(void *);
extern void *func_L39_004E0BC8(void *);
extern s32 func_L39_004E0490(void *, s32, void *);
s32 func_L39_004DEA00(void *a0)
{
    void *r = func_L39_00505058(a0);
    if (func_L39_004E0490(func_L39_004E0B10(r), 2, a0) == 0) {
        return 0;
    }
    return func_L39_004E0490(func_L39_004E0BC8(r), 2, a0);
}
/* localdecomp:end func_L39_004DEA00 */

/* localdecomp:start func_L39_004DEA68 */
extern void *func_L01_00516000(void *);
extern void *func_L01_004CC750(void *);
extern void *func_L39_004E0B10(void *);
extern void *func_L39_004E0BC8(void *);
extern s32 func_L39_004E0490(void *, s32, void *);

s32 func_L39_004DEA68(void *arg0) {
    void *a;
    void *b;
    void *c;
    s32 ret;

    a = func_L01_00516000(arg0);
    b = func_L39_004E0B10(a);
    if (func_L39_004E0490(b, 1, arg0) == 0) {
        return 0;
    }
    ret = func_L39_004E0490(func_L39_004E0BC8(a), 1, arg0);
    if (ret == 0) {
        return 0;
    }
    c = func_L01_004CC750(arg0);
    if (a != c && c != 0) {
        if (func_L39_004E0490(func_L39_004E0B10(c), 0x8001, b) == 0) {
            return 0;
        }
        ret = func_L39_004E0490(func_L39_004E0BC8(c), 0x8001, b);
    }
    return ret;
}
/* localdecomp:end func_L39_004DEA68 */
