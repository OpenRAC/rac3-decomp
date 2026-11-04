#include "common.h"

typedef struct {
    s16 h0;
    s16 h2;
    f32 f4;
    f32 f8;
    int wC;
} S_0034C8A8;

/* localdecomp:start func_L30_0034C8A8 */
extern int func_00382498(int, int);
extern void func_L03_00461E88(void *, S_0034C8A8 *, int, int);

void func_L30_0034C8A8(S_0034C8A8 *s, void *a1) {
    if (s == 0) {
        return;
    }
    s->f8 += s->f4;
    while (s->f8 > 1.0f) {
        s->f8 -= 1.0f;
        func_L03_00461E88(a1, s, func_00382498(s->h2, s->h0), s->wC);
    }
}
/* localdecomp:end func_L30_0034C8A8 */
