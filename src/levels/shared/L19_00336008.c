#include "common.h"

/* localdecomp:start func_L19_00336008 */
#include "vu0.h"

typedef int Q_00336008 __attribute__((mode(TI)));
typedef struct {
    vu0_v4 head;
    vu0_v4 pts[1];
} S_00336008;

extern Q_00336008 D_L19_001D66F0[];
extern void func_0038CE20(void *, void *, f32);

void func_L19_00336008(vu0_v4 *out, S_00336008 *s, s32 n) {
    vu0_v4 *p;
    f32 count;
    s32 i;

    *(Q_00336008 *)out = D_L19_001D66F0[0];
    if (s == 0 || n == 0) {
        return;
    }
    count = n;
    p = s->pts;
    for (i = 0; i < n; i++) {
        vec_add_ba(out, out, p);
        p++;
    }
    func_0038CE20(out, out, 1.0f / count);
}
/* localdecomp:end func_L19_00336008 */
