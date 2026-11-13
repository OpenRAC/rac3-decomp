#include "common.h"

/* localdecomp:start func_L39_004FA538 */
extern char D_L39_00478E58[];
extern char D_L39_00478E60[];
extern char D_L39_00478E68[];
extern char D_L39_00478E78[];
extern void func_00120048(char *, char *, ...);
extern void func_L39_004DE348(int, char *, char *, char *, char *);

void func_L39_004FA538(int a0, int a1)
{
    char buf0[16];
    char buf1[16];
    func_00120048(buf0, D_L39_00478E58, a0);
    func_00120048(buf1, D_L39_00478E60, a1);
    func_L39_004DE348(4, D_L39_00478E68, buf0, D_L39_00478E78, buf1);
}
/* localdecomp:end func_L39_004FA538 */

/* localdecomp:start func_L39_004FA5B0 */
typedef struct { s32 len; void *data; } S_004FA5B0b;
typedef struct { s32 pad0; s32 pad4; s32 flag; S_004FA5B0b *buf; } S_004FA5B0;
s32 func_L39_004FA638(S_004FA5B0 *);
extern void *func_0011D380(void *, const void *, unsigned int);
s32 func_L39_004FA5B0(S_004FA5B0 *p, u8 **out) {
    s32 r;
    S_004FA5B0b *b;
    if (p == 0) {
        return 0;
    }
    if (p->flag != 0) {
        r = func_L39_004FA638(p);
        if (r < 0) {
            return r;
        }
    }
    b = p->buf;
    r = b->len;
    if (out != 0) {
        func_0011D380(*out, b->data, r);
        *out += r;
    }
    return r;
}
/* localdecomp:end func_L39_004FA5B0 */
