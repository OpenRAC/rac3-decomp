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

/* localdecomp:start func_L39_00514CF8 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00514CF8;
extern s32 func_L39_00512A40(s32, void *);
extern void func_L39_005128F8(void *);
extern s32 func_L39_004F7538(void *, void *, s32);

s32 func_L39_00514CF8(s32 n, S_00514CF8 *s) {
    S_00514CF8 tmp;
    s32 old;
    s32 len;
    s32 err;
    s32 bytes;
    s32 b2;
    unsigned long *p;
    unsigned long *q;

    if (n <= 0) {
        return 0;
    }
    old = s->n;
    len = old + n;
    if (s->cap < len) {
        bytes = n * 8;
        while (func_L39_005128E8((s32 *)&tmp), (err = func_L39_00510EF0(s, &tmp)) == 0 && (err = func_L39_00512A40(len + 1, s)) == 0) {
            func_L39_004F74E8(s->d, 0, bytes);
            func_L39_004F7510((u8 *)s->d + bytes, tmp.d, old * 8);
            p = &s->d[len - 1];
            if (*p == 0 && len > 1) {
                q = p;
                do {
                    q--;
                    len--;
                } while (*q == 0 && len > 1);
            }
            s->n = len;
            break;
        }
        func_L39_005128F8(&tmp);
        return err;
    }
    b2 = n * 8;
    func_L39_004F7538((u8 *)s->d + b2, s->d, old * 8);
    func_L39_004F74E8(s->d, 0, b2);
    p = &s->d[len - 1];
    if (*p == 0 && len > 1) {
        q = p;
        do {
            q--;
            len--;
        } while (*q == 0 && len > 1);
    }
    s->n = len;
    return 0;
}
/* localdecomp:end func_L39_00514CF8 */
