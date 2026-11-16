/* PAL near miss (Codex wave 7): near miss: 12 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003BFF08; did not compile with its file's flags under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 12).
 * Worker's note: 12 instruction diffs; build/codex/w361/func_003C0010.final.log; two parent versus subobject address selections and opacity address/register scheduling differ. Subobject member address and grouped state declarations repeat the baseline 12-diff output; scalar ...
 */
#include "common.h"
/* localdecomp:start func_003C0010 */
#include "vu0.h"
extern f32 D_001DA340_003C0010[];
void func_003C0010(P_3BA748 *p) {
    Q_3BA748 matrix[4];
    B_3BA748 *b = (B_3BA748 *)((u8 *)p + 0x20);
    if ((p->h0A >= 0 && func_0038CEE0(&p->h0A)) || (b->obj && b->obj->b20 < 0)) {
        func_003CD608((s32)p);
        return;
    }
    if (b->obj) {
        func_003C3278((u8 *)b->obj, b->f4, (u8 *)matrix);
        func_0038D3E0(&p->v10, &b->v10, matrix);
        vec_add_ab(&p->v10, &p->v10, &matrix[3]);
        p->v10.w = 0.0f;
    } else {
        *(Q_3BA748 *)&p->v10 = *(Q_3BA748 *)&b->v10;
    }
    if (D_001DA33C) {
        p->f4 = (p->f4 & 0xFFFFFF) | ((s32)(D_001DA340_003C0010[0] * 128.0f) << 24);
    }
    p->fC *= *(f32 *)((u8 *)b + 0x1C);
    p->b8 += b->b0D;
}
/* localdecomp:end func_003C0010 */
