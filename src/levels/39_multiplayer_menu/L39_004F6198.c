#include "common.h"

/* declared by functions of L39_004F4E58.c, which this file was cut from */
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

/* declared by functions of L39_004F5DA0.c, which this file was cut from */
extern void func_L39_004F5F80(void *);
extern void func_L39_004F74E8(void *, s32, s32);

/* declared by functions of L39_004F5F38.c, which this file was cut from */
extern void func_L39_004F7620(void *);
extern void *func_L39_004F7590(void *n);
extern void func_L39_004F7510(void *dst, const void *src, u32 n);
extern s32 func_L39_004F6198(void *, void *, void *, s32);

/* localdecomp:start func_L39_004F6198 */
typedef struct E_004F6198 {
    s32 a;
    s32 b;
    s32 c;
} E_004F6198;
typedef struct V_004F6198 {
    u32 count;
    u32 cap;
    E_004F6198 *data;
} V_004F6198;
extern void *func_L39_004F7590(void *n);
extern void func_L39_004F7510(void *dst, const void *src, u32 n);
extern void func_L39_004F7620(void *);

s32 func_L39_004F6198(void *arg, void *a, void *b, s32 c)
{
    V_004F6198 *v = arg;
    E_004F6198 *nd;
    u32 ncap;
    u32 n;

    n = v->count;
    if (v->cap < n + 1) {
        ncap = n + 10;
        nd = func_L39_004F7590((void *)(ncap * sizeof(E_004F6198)));
        if (nd == 0) {
            return 0x206;
        }
        func_L39_004F7510(nd, v->data, v->count * sizeof(E_004F6198));
        func_L39_004F7620(v->data);
        v->data = nd;
        v->cap = ncap;
        n = v->count;
    }
    v->data[n].a = (s32)a;
    v->data[v->count].b = (s32)b;
    v->data[v->count++].c = c;
    return 0;
}
/* localdecomp:end func_L39_004F6198 */
