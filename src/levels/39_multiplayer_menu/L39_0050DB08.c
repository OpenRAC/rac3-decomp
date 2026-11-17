#include "common.h"

/* declared by functions of L39_0050D5B0.c, which this file was cut from */
extern char *func_L39_004F7510(char *, char *, s32);
extern void func_L39_0050DB08(void *, void *);

/* localdecomp:start func_L39_0050DB08 */
extern void *D_L39_0046F410[];
typedef struct S_0050DB08 { void *buf; s32 len; } S_0050DB08;
typedef struct N_0050DB08 { void **vt; S_0050DB08 *s; } N_0050DB08;
void func_L39_0050DB08(void *a0, void *a1)
{
    N_0050DB08 *a = a0;
    S_0050DB08 *s = a1;
    a->s = s;
    s->buf = 0;
    s->len = 0;
    a->vt = D_L39_0046F410;
}
/* localdecomp:end func_L39_0050DB08 */

/* localdecomp:start func_L39_0050DB28 */
typedef struct S_0050DB28 { char *buf; s32 len; } S_0050DB28;
typedef struct T_0050DB28 { s32 pad0; S_0050DB28 *s; } T_0050DB28;
extern char *func_L39_004F7590(s32);
s32 func_L39_0050DB28(T_0050DB28 *a, char *b, s32 c)
{
    S_0050DB28 *s;
    char *m;
    if (a->s->buf != 0)
        return 0x804;
    m = func_L39_004F7590(c);
    a->s->buf = m;
    if (m == 0)
        return 0x803;
    s = a->s;
    s->len = c;
    func_L39_004F7510(s->buf, b, c);
    return 0;
}
/* localdecomp:end func_L39_0050DB28 */
