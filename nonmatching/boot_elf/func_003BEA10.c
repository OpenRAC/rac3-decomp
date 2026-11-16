/* PAL near miss (Codex wave 7): near miss: 39 words differ with the file's flags.
 * Replaces the earlier draft (US draft of func_003BE920; did not compile with its file's flags under tools/check.py with the file's flags, measured
 * 2026-11-16; this one: 39).
 * Worker's note: 8 instruction differences with --divs 2 in build/codex/w373/func_003BEA10.03.log (three forms same wrong copy scheduling/allocation). Exact later S_3B9160/Sub_3B9160 declarations copied for standalone; move existing declarations before function for ...
 */
#include "common.h"
/* localdecomp:start func_003BEA10 */
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; u8 pad16[6]; void *f1C; } Sub_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3B9160 q10;
    Sub_3B9160 s20;
} S_3B9160;
S_3B9160 *func_003BEA10(Q_3B9160 *pos, f32 *velocity, s32 duration,
    s32 color, s32 delta, s32 alpha0, s32 alpha1, f32 scale0, f32 scale1, f32 gravity) {
    extern void func_003BE948(S_3B9098 *);
    P_3B9160 *p;
    Q_3B9160 *q;
    p = func_003CD4C0(0x61);
    if (p) {
        u128_3B9160 position = *(u128_3B9160 *)pos;
        p->b1 = 0;
        p->fC = scale0;
        p->v10 = position;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->x4 = (alpha0 << 24) | color;
        p->b8 = func_00382848(255);
        p->b2 = D_002FCF20[0][0];
        p->hA = duration;
        q = &p->q;
        q->x = velocity[0];
        q->y = velocity[1];
        q->z = velocity[2];
        q->fC = gravity;
        q->b15 = delta;
        q->f10 = (scale1 - scale0) / duration;
        q->b14 = (alpha1 - alpha0) / duration;
        q->f1C = func_003BE948;
    }
    return (S_3B9160 *)p;
}
/* localdecomp:end func_003BEA10 */
