#include "common.h"

/* declared by functions of L39_005128F8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;
extern void func_L39_004F7510(void *, void *, s32);
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00512A40_Big;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00510FF0(void *, void *, void *);
extern s32 func_L39_00510EF0(void *, void *);
extern s32 func_L39_00511268(s32, s32, s32);

/* localdecomp:start func_L39_00514BE0 */
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_00511268(s32, s32, s32);
extern s32 func_L39_00510FF0(void *, void *, void *);

s32 func_L39_00514BE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5)
{
    if (func_L39_00510F60((void *)arg0, (void *)arg2) >= 0) {
        *arg5 = arg1;
        if (arg1 == arg3) {
            return func_L39_00511268(arg0, arg2, arg4);
        }
        return func_L39_00510FF0((void *)arg0, (void *)arg2, (void *)arg4);
    }
    *arg5 = -arg3;
    if (arg1 == arg3) {
        return func_L39_00511268(arg2, arg0, arg4);
    }
    return func_L39_00510FF0((void *)arg0, (void *)arg2, (void *)arg4);
}
/* localdecomp:end func_L39_00514BE0 */

INCLUDE_ASM("asm/levels", func_L39_00514CF8);
