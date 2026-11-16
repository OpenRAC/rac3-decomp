/* PAL near miss (Codex wave 7): near miss: 11 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003BF568; did not compile with its file's flags under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 11).
 * Worker's note: 11 diff; build/codex/w374/func_003BF658.01.log; equivalent approved-helper wordings 06/07 repeat the same bytes; VU load order and gravity-constant scheduling remain; no flag changes.
 */
#include "common.h"
/* localdecomp:start func_003BF658 */
#include "vu0.h"
void func_003BF658(S_3B9DA8 *p)
{
    V4_3B9DA8 velocity, delta, old;
    V4_3B9DA8 *v = &p->v30;
    f32 height = v->w;
    if (p->v10.z > height || p->v10.x < 0.0f || p->v10.y < 0.0f ||
        p->v10.x > 1024.0f || p->v10.y > 1024.0f) {
        func_003CD608((s32)p);
    } else {
        *(Q_3B9DA8 *)&velocity = *(Q_3B9DA8 *)&p->v30;
        vec_copy(&old, &p->v20);
        velocity.w = 0.0f;
        vec_add_ab(&p->v20, &velocity, &old);
        vec_copy(&delta, &velocity);
        vec_add_ab(&p->v10, &p->v10, &delta);
        v->z -= 0.003920000046491623f;
        v->w = height;
    }
}
/* localdecomp:end func_003BF658 */
