/* PAL near miss (Codex wave 6): near miss: 48 words differ with the file's flags.
 * Worker's note: 27 diff with --divs 2,2 in w311/func_L01_00475C60.04.log; division ordering, float/integer allocation and store scheduling; three equivalent wordings unchanged; existing callee types preserved; out/func_L01_00475C60.near.c.
 */
#include "common.h"
/* localdecomp:start func_L01_00475C60 */
typedef struct {
    f32 x, y, z, inv;
    f32 delta;
    u8 mode;
    u8 pad15;
    s16 scale;
    s32 first;
    s32 second;
} Sub_00475C60;
extern u8 *D_L01_00221294;
Part_00470258 *func_L01_00475C60(s128_00470258 *pos, s128_00470258 *vec,
    s32 life, s32 mode, s32 first, s32 second, s32 texture,
    f32 start, f32 end, f32 scale) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern s32 func_00382468(s32);
    Part_00470258 *p = func_L01_004618E0(127);
    Sub_00475C60 *q;
    if (p != 0) {
        p->f10 = *pos;
        p->f9 = 68;
        p->f3 = 72;
        p->f1 = 0;
        p->fC = start;
        p->f8 = func_00382468(255);
        p->f2 = D_L01_00221294[texture];
        q = (Sub_00475C60 *)&p->sub;
        p->fA = life;
        *(s128_00470258 *)q = *vec;
        q->mode = mode;
        q->inv = 1.0f / (f32)(s16)life;
        q->delta = (end - start) / life;
        q->first = first;
        q->second = second;
        q->scale = scale * 128.0f;
    }
    return p;
}
/* localdecomp:end func_L01_00475C60 */
