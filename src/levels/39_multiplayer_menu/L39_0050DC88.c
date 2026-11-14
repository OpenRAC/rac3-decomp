#include "common.h"

/* localdecomp:start func_L39_0050DC88 */
typedef struct { unsigned char *data; unsigned int len; unsigned char unused; } S_0050DC88;
extern int func_L39_0050CC00(void *, int, int, unsigned char *, int);

int func_L39_0050DC88(void *ctx, int flags, int a2, S_0050DC88 *p)
{
    unsigned char c;
    unsigned char last;
    int t;
    int fl;
    int r;

    t = p->unused;
    c = t;
    if (t != 0 && (c >= 8 || p->len == 0)) return 0x804;
    fl = flags | 0x800;
    r = func_L39_0050CC00(ctx, fl, a2, &c, 1);
    if (r != 0) return r;
    if (c != 0) {
        if (p->len >= 2) {
            r = func_L39_0050CC00(ctx, fl, a2, p->data, p->len - 1);
            if (r != 0) return r;
        }
        last = p->data[p->len - 1] & (-1 << c);
        r = func_L39_0050CC00(ctx, flags, a2, &last, 1);
    } else {
        r = func_L39_0050CC00(ctx, flags, a2, p->data, p->len);
    }
    return r;
}
/* localdecomp:end func_L39_0050DC88 */

/* localdecomp:start func_L39_0050DDC8 */
typedef struct { unsigned char *data; int len; } S_0050DDC8;
extern int func_L39_0050DEC0(void *, S_0050DDC8 *);

int func_L39_0050DDC8(void *a0, unsigned short *out)
{
    S_0050DDC8 b;
    unsigned char tmp[2];
    int r;
    b.data = tmp;
    b.len = 2;
    r = func_L39_0050DEC0(a0, &b);
    if (r == 0) {
        *out = (tmp[0] << 8) | tmp[1];
    }
    return r;
}
/* localdecomp:end func_L39_0050DDC8 */

/* localdecomp:start func_L39_0050DE20 */
typedef struct { unsigned char *data; int len; } S_0050DE20;
extern int func_L39_0050DFA0(int, int, int, S_0050DE20 *);

int func_L39_0050DE20(int a0, int a1, int a2, unsigned short *p)
{
    S_0050DE20 b;
    unsigned char tmp[2];
    int r = 0;
    if (p != 0) {
        tmp[1] = *(unsigned char *)p;
        tmp[0] = *p >> 8;
        b.data = tmp;
        b.len = 2;
        r = func_L39_0050DFA0(a0, a1, a2, &b);
    }
    return r;
}
/* localdecomp:end func_L39_0050DE20 */
