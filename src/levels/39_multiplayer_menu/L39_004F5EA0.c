#include "common.h"

/* declared by functions of L39_004F4E58.c, which this file was cut from */
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

/* localdecomp:start func_L39_004F5EA0 */
typedef struct E_004F5EA0 { s32 a; s32 b; } E_004F5EA0;
typedef struct S_004F5EA0 { u8 pad[0xC]; s32 n; E_004F5EA0 *data; } S_004F5EA0;
s32 func_L39_004F62B0(void *, void *, s32);

s32 func_L39_004F5EA0(S_004F5EA0 *p, s32 a, s32 b) {
    s32 r;

    r = func_L39_004F62B0(p, &p->data, p->n * 8 + 8);
    if (r != 0) {
        return r;
    }
    p->data[p->n].a = a;
    p->data[p->n].b = b;
    p->n++;
    return 0;
}
/* localdecomp:end func_L39_004F5EA0 */
