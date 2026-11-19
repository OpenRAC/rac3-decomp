#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00513808(void *, void *, void *);
extern s32 func_L39_00510F60(void *, void *);
extern unsigned long func_001306F8(unsigned long, unsigned long);

/* localdecomp:start func_L39_00514750 */
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00514868(void *, void *, s32 *, void *);
extern s32 func_L39_00510FF0(void *, void *, void *);
extern s32 func_L39_00510EF0(void *, void *);

s32 func_L39_00514750(void *arg0, void *arg1, void *arg2, s32 *arg3, s32 *arg4, void *arg5, void *arg6) {
    s32 old;
    s32 ret;
    s32 m;

    old = *arg3;
    *arg3 = *arg4;
    do {
        ret = func_L39_00513350(arg2, arg6, arg1);
        if (ret != 0) {
            break;
        }
        if (*arg4 != old) {
            ret = func_L39_00510FF0(arg5, arg1, arg0);
            if (ret != 0) {
                break;
            }
            *arg4 = -*arg4;
        } else {
            if (func_L39_00514868(arg5, arg1, &m, arg0) != ret) {
                break;
            }
            *arg4 = *arg4 * m;
        }
        ret = func_L39_00510EF0(arg6, arg5);
        if (ret == 0) {
            ret = func_L39_00510EF0(arg0, arg6);
        }
    } while (0);
    return ret;
}
/* localdecomp:end func_L39_00514750 */

/* localdecomp:start func_L39_00514868 */
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00511268(s32, s32, s32);

s32 func_L39_00514868(void *arg0, void *arg1, s32 *arg2, void *arg3)
{
    if (func_L39_00510F60(arg0, arg1) >= 0) {
        *arg2 = 1;
        return func_L39_00511268((s32)arg0, (s32)arg1, (s32)arg3);
    }
    *arg2 = -1;
    return func_L39_00511268((s32)arg1, (s32)arg0, (s32)arg3);
}
/* localdecomp:end func_L39_00514868 */
